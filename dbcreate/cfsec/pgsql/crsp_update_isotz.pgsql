--
--	@(#) dbcreate/cfsec/pgsql/crsp_update_isotz.pgsql
--
--	org.msscf.msscf.CFSec
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	MSS Code Factory CFSec 2.13 Security Essentials
--	
--	Copyright 2020 Mark Stephen Sobkow
--	
--		This file is part of MSS Code Factory.
--	
--		MSS Code Factory is available under dual commercial license from Mark Stephen
--		Sobkow, or under the terms of the GNU General Public License, Version 3
--		or later.
--	
--	    MSS Code Factory is free software: you can redistribute it and/or modify
--	    it under the terms of the GNU General Public License as published by
--	    the Free Software Foundation, either version 3 of the License, or
--	    (at your option) any later version.
--	
--	    MSS Code Factory is distributed in the hope that it will be useful,
--	    but WITHOUT ANY WARRANTY; without even the implied warranty of
--	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--	    GNU General Public License for more details.
--	
--	    You should have received a copy of the GNU General Public License
--	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
--	
--	Donations to support MSS Code Factory can be made at
--	https://www.paypal.com/paypalme2/MarkSobkow
--	
--	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
--
--	Manufactured by MSS Code Factory 2.12
--

create or replace function cfsec213.sp_update_isotz(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argISOTZoneId smallint,
	argIso8601 varchar(6),
	argTZName varchar(64),
	argTZHourOffset smallint,
	argTZMinOffset smallint,
	argDescription varchar(128),
	argVisible boolean,
	argRevision integer )
returns setof cfsec213.type_isotz_rec as $$
declare
	RowsAffected integer;
	oldISOTZoneId smallint;
	oldIso8601 varchar(6);
	oldTZName varchar(64);
	oldTZHourOffset smallint;
	oldTZMinOffset smallint;
	oldDescription varchar(128);
	oldVisible boolean;
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a008' )
	then
		select cfsec213.sp_is_system_user( argAuditUserId ) into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- only system user can update ISOTZone records';
		end if;
	end if;

		select
			ISOTZoneId,
			Iso8601,
			TZName,
			TZHourOffset,
			TZMinOffset,
			Description,
			Visible,
			revision
		into
			oldISOTZoneId,
			oldIso8601,
			oldTZName,
			oldTZHourOffset,
			oldTZMinOffset,
			oldDescription,
			oldVisible,
			oldRevision
		from cfsec213.ISOTz
		where
			ISOTZoneId = argISOTZoneId
		for update;


	if argRevision != oldRevision
	then
		raise exception 'sp_update_isotz() Data collision detected';
	end if;


	update cfsec213.ISOTz
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		iso8601 = argIso8601,
		tzname = argTZName,
		tzhouroffset = argTZHourOffset,
		tzminoffset = argTZMinOffset,
		description = argDescription,
		visible = argVisible
	where
		ISOTZoneId = argISOTZoneId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_isotz() Expected to affect one ISOTz row, not %', RowsAffected;
	end if;


	insert into cfsec213.ISOTz_h (
			ISOTZoneId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			Iso8601,
			TZName,
			TZHourOffset,
			TZMinOffset,
			Description,
			Visible,
			revision,
			auditaction )
		select
			a008.ISOTZoneId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a008.Iso8601,
			a008.TZName,
			a008.TZHourOffset,
			a008.TZMinOffset,
			a008.Description,
			a008.Visible,
			argRevision + 1,
			1
		from cfsec213.ISOTz as a008
		where
			a008.isotzoneid = argISOTZoneId;
	return query select
			a008.createdby,
			to_char( a008.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a008.updatedby,
			to_char( a008.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a008.isotzoneid as isotzoneid,
			a008.iso8601 as iso8601,
			a008.tzname as tzname,
			a008.tzhouroffset as tzhouroffset,
			a008.tzminoffset as tzminoffset,
			a008.description as description,
			a008.visible as visible,
		a008.revision as revision
	from cfsec213.ISOTz as a008
	where
		a008.isotzoneid = argISOTZoneId;

	return;
end;
$$ language plpgsql;
