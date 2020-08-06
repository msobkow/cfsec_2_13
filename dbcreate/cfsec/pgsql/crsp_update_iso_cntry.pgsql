--
--	@(#) dbcreate/cfsec/pgsql/crsp_update_iso_cntry.pgsql
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

create or replace function cfsec213.sp_update_iso_cntry(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argISOCtryId smallint,
	argISOCode varchar(2),
	argName varchar(64),
	argRevision integer )
returns setof cfsec213.type_iso_cntry_rec as $$
declare
	RowsAffected integer;
	oldISOCtryId smallint;
	oldISOCode varchar(2);
	oldName varchar(64);
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a004' )
	then
		select cfsec213.sp_is_system_user( argAuditUserId ) into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- only system user can update ISOCtry records';
		end if;
	end if;

		select
			ISOCtryId,
			iso_code,
			country_name,
			revision
		into
			oldISOCtryId,
			oldISOCode,
			oldName,
			oldRevision
		from cfsec213.iso_cntry
		where
			ISOCtryId = argISOCtryId
		for update;


	if argRevision != oldRevision
	then
		raise exception 'sp_update_iso_cntry() Data collision detected';
	end if;


	update cfsec213.iso_cntry
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		iso_code = argISOCode,
		country_name = argName
	where
		ISOCtryId = argISOCtryId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_iso_cntry() Expected to affect one iso_cntry row, not %', RowsAffected;
	end if;


	insert into cfsec213.iso_cntry_h (
			ISOCtryId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			iso_code,
			country_name,
			revision,
			auditaction )
		select
			a004.ISOCtryId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a004.iso_code,
			a004.country_name,
			argRevision + 1,
			1
		from cfsec213.iso_cntry as a004
		where
			a004.isoctryid = argISOCtryId;
	return query select
			a004.createdby,
			to_char( a004.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a004.updatedby,
			to_char( a004.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a004.isoctryid as isoctryid,
			a004.iso_code as iso_code,
			a004.country_name as country_name,
		a004.revision as revision
	from cfsec213.iso_cntry as a004
	where
		a004.isoctryid = argISOCtryId;

	return;
end;
$$ language plpgsql;
