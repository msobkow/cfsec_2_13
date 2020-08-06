--
--	@(#) dbcreate/cfsec/pgsql/crsp_update_iso_cntrylng.pgsql
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

create or replace function cfsec213.sp_update_iso_cntrylng(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argISOCtryId smallint,
	argISOLangId smallint,
	argRevision integer )
returns setof cfsec213.type_iso_cntrylng_rec as $$
declare
	RowsAffected integer;
	oldISOCtryId smallint;
	oldISOLangId smallint;
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a006' )
	then
		select cfsec213.sp_is_system_user( argAuditUserId ) into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- only system user can update ISOCtryLang records';
		end if;
	end if;

		select
			ISOCtryId,
			ISOLangId,
			revision
		into
			oldISOCtryId,
			oldISOLangId,
			oldRevision
		from cfsec213.iso_cntrylng
		where
			ISOCtryId = argISOCtryId
			and ISOLangId = argISOLangId
		for update;


	if argRevision != oldRevision
	then
		raise exception 'sp_update_iso_cntrylng() Data collision detected';
	end if;


	update cfsec213.iso_cntrylng
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now()
	where
		ISOCtryId = argISOCtryId
			and ISOLangId = argISOLangId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_iso_cntrylng() Expected to affect one iso_cntrylng row, not %', RowsAffected;
	end if;


	insert into cfsec213.iso_cntrylng_h (
			ISOCtryId,
			ISOLangId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			revision,
			auditaction )
		select
			a006.ISOCtryId,
			a006.ISOLangId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			argRevision + 1,
			1
		from cfsec213.iso_cntrylng as a006
		where
			a006.isoctryid = argISOCtryId
			and a006.isolangid = argISOLangId;
	return query select
			a006.createdby,
			to_char( a006.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a006.updatedby,
			to_char( a006.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a006.isoctryid as isoctryid,
			a006.isolangid as isolangid,
		a006.revision as revision
	from cfsec213.iso_cntrylng as a006
	where
		a006.isoctryid = argISOCtryId
			and a006.isolangid = argISOLangId;

	return;
end;
$$ language plpgsql;
