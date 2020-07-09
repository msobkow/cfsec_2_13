--
--	@(#) dbcreate/cfsec/pgsql/crsp_page_tsecmemb_by_useridx.pgsql
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
create or replace function cfsec213.sp_page_tsecmemb_by_useridx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argSecUserId varchar(36),
	priorTenantId bigint,
	priorTSecGrpMembId bigint )
returns setof cfsec213.type_tsecmemb_rec as $$
declare
	permissionFlag boolean;
	isSystemUser boolean;
begin
	select cfsec213.sp_is_tenant_user( secTenantId,
			'ReadTSecGrpMemb',
			argAuditUserId ),
		cfsec213.sp_is_system_user( argAuditUserId )
	into permissionFlag, isSystemUser;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in tenant TSecGroup for ReadTSecGrpMemb';
	end if;
	if( isSystemUser )
	then
		if( ( priorTenantId is not null )and ( priorTSecGrpMembId is not null ) )
		then
			return query select
			a018.createdby,
			to_char( a018.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a018.updatedby,
			to_char( a018.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a018.tenantid as tenantid,
			a018.tsecgrpmembid as tsecgrpmembid,
			a018.tsecgroupid as tsecgroupid,
			a018.secuserid as secuserid,
				a018.revision as revision
			from cfsec213.TSecMemb as a018
			where
				a018.secuserid = argSecUserId
			and ( ( ( a018.TenantId = priorTenantId )
					and ( a018.TSecGrpMembId < priorTSecGrpMembId ) )
				or ( ( a018.TenantId < priorTenantId ) ) )
				order by TenantId desc,
					TSecGrpMembId desc
			limit 25;
		else
			return query select
			a018.createdby,
			to_char( a018.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a018.updatedby,
			to_char( a018.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a018.tenantid as tenantid,
			a018.tsecgrpmembid as tsecgrpmembid,
			a018.tsecgroupid as tsecgroupid,
			a018.secuserid as secuserid,
				a018.revision as revision
			from cfsec213.TSecMemb as a018
			where
				a018.secuserid = argSecUserId
				order by TenantId desc,
					TSecGrpMembId desc
			limit 25;
		end if;
	else
		if( ( priorTenantId is not null )and ( priorTSecGrpMembId is not null ) )
		then
			return query select
			a018.createdby,
			to_char( a018.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a018.updatedby,
			to_char( a018.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a018.tenantid as tenantid,
			a018.tsecgrpmembid as tsecgrpmembid,
			a018.tsecgroupid as tsecgroupid,
			a018.secuserid as secuserid,
				a018.revision as revision
			from cfsec213.TSecMemb as a018
			where
				a018.secuserid = argSecUserId
				and a018.TenantId = secTenantId
			and ( ( ( a018.TenantId = priorTenantId )
					and ( a018.TSecGrpMembId < priorTSecGrpMembId ) )
				or ( ( a018.TenantId < priorTenantId ) ) )
				order by TenantId desc,
					TSecGrpMembId desc
			limit 25;
		else
			return query select
			a018.createdby,
			to_char( a018.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a018.updatedby,
			to_char( a018.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a018.tenantid as tenantid,
			a018.tsecgrpmembid as tsecgrpmembid,
			a018.tsecgroupid as tsecgroupid,
			a018.secuserid as secuserid,
				a018.revision as revision
			from cfsec213.TSecMemb as a018
			where
				a018.secuserid = argSecUserId
				and a018.TenantId = secTenantId
				order by TenantId desc,
					TSecGrpMembId desc
			limit 25;
		end if;
	end if;
	return;
end
$$ language plpgsql;
