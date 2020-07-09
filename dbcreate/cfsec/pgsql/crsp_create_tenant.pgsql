--
--	@(#) dbcreate/cfsec/pgsql/crsp_create_tenant.pgsql
--
--	org.msscf.msscf.CFSec
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	This file is part of MSS Code Factory.
--	
--	Licensed under the Apache License, Version 2.0 (the "License");
--	you may not use this file except in compliance with the License.
--	You may obtain a copy of the License at
--	
--	    http://www.apache.org/licenses/LICENSE-2.0
--	
--	Unless required by applicable law or agreed to in writing, software
--	distributed under the License is distributed on an "AS IS" BASIS,
--	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
--	See the License for the specific language governing permissions and
--	limitations under the License.
--	
--	Donations to support MSS Code Factory can be made at
--	https://www.paypal.com/paypalme2/MarkSobkow
--
--	Manufactured by MSS Code Factory 2.12
--
create or replace function cfsec213.sp_create_tenant(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argClusterId bigint,
	argTenantName varchar(192) )
returns setof cfsec213.type_tenant_rec as $$
declare
	permissionFlag boolean;
	argId bigint;
begin
	if( argClassCode = 'a015' )
	then
		select cfsec213.sp_is_system_user( argAuditUserId ) into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- only system user can create Tenant records';
		end if;
	end if;

	select cfsec213.sp_next_tenantidgen()
	into argId;

	insert into cfsec213.tenant(
		createdby,
		createdat,
		updatedby,
		updatedat,
		clusterid,
		id,
		tenantname,
		revision )
	values (
		argAuditUserId,
		now(),
		argAuditUserId,
		now(),
		argClusterId,
		argId,
		argTenantName,
		1 );
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
			a015.revision,
			0
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
