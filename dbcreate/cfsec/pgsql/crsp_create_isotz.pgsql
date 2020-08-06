--
--	@(#) dbcreate/cfsec/pgsql/crsp_create_isotz.pgsql
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
create or replace function cfsec213.sp_create_isotz(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argIso8601 varchar(6),
	argTZName varchar(64),
	argTZHourOffset smallint,
	argTZMinOffset smallint,
	argDescription varchar(128),
	argVisible boolean )
returns setof cfsec213.type_isotz_rec as $$
declare
	permissionFlag boolean;
	argISOTZoneId smallint;
begin
	if( argClassCode = 'a008' )
	then
		select cfsec213.sp_is_system_user( argAuditUserId ) into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- only system user can create ISOTZone records';
		end if;
	end if;

	select cfsec213.sp_next_isotzoneidgen()
	into argISOTZoneId;

	insert into cfsec213.isotz(
		createdby,
		createdat,
		updatedby,
		updatedat,
		isotzoneid,
		iso8601,
		tzname,
		tzhouroffset,
		tzminoffset,
		description,
		visible,
		revision )
	values (
		argAuditUserId,
		now(),
		argAuditUserId,
		now(),
		argISOTZoneId,
		argIso8601,
		argTZName,
		argTZHourOffset,
		argTZMinOffset,
		argDescription,
		argVisible,
		1 );
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
			a008.revision,
			0
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
