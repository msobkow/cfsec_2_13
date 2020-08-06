--
--	@(#) dbcreate/cfsec/pgsql/crsp_update_tenant.pgsql
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

create or replace function cfsec213.sp_update_tenant(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argClusterId bigint,
	argId bigint,
	argTenantName varchar(192),
	argRevision integer )
returns setof cfsec213.type_tenant_rec as $$
declare
	RowsAffected integer;
	oldClusterId bigint;
	oldId bigint;
	oldTenantName varchar(192);
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a015' )
	then
		select cfsec213.sp_is_system_user( argAuditUserId ) into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- only system user can update Tenant records';
		end if;
	end if;

		select
			ClusterId,
			Id,
			TenantName,
			revision
		into
			oldClusterId,
			oldId,
			oldTenantName,
			oldRevision
		from cfsec213.tenant
		where
			Id = argId
		for update;


	if argRevision != oldRevision
	then
		raise exception 'sp_update_tenant() Data collision detected';
	end if;


	update cfsec213.tenant
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		clusterid = argClusterId,
		tenantname = argTenantName
	where
		Id = argId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_tenant() Expected to affect one tenant row, not %', RowsAffected;
	end if;


	insert into cfsec213.tenant_h (
			Id,
			auditclusterid,
			auditsessionid,
			auditstamp,
			ClusterId,
			TenantName,
			revision,
			auditaction )
		select
			a015.Id,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a015.ClusterId,
			a015.TenantName,
			argRevision + 1,
			1
		from cfsec213.tenant as a015
		where
			a015.id = argId;
	return query select
			a015.createdby,
			to_char( a015.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a015.updatedby,
			to_char( a015.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a015.clusterid as clusterid,
			a015.id as id,
			a015.tenantname as tenantname,
		a015.revision as revision
	from cfsec213.tenant as a015
	where
		a015.id = argId;

	return;
end;
$$ language plpgsql;
