--
--	@(#) dbcreate/cfsec/pgsql/crsp_page_tsecinc_all.pgsql
--
--	com.github.msobkow.CFSec
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
create or replace function cfsec213.sp_page_tsecinc_all(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	priorTenantId bigint,
	priorTSecGrpIncId bigint )
returns setof cfsec213.type_tsecinc_rec as $$
declare
	permissionFlag boolean;
	isSystemUser boolean;
begin
	select cfsec213.sp_is_tenant_user( secTenantId,
			'ReadTSecGrpInc',
			argAuditUserId ),
		cfsec213.sp_is_system_user( argAuditUserId )
	into permissionFlag, isSystemUser;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in tenant TSecGroup for ReadTSecGrpInc';
	end if;
	if( isSystemUser )
	then
		if( ( priorTenantId is not null )and ( priorTSecGrpIncId is not null ) )
		then
			return query select
			a017.createdby,
			to_char( a017.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a017.updatedby,
			to_char( a017.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a017.tenantid as tenantid,
			a017.tsecgrpincid as tsecgrpincid,
			a017.tsecgrpid as tsecgrpid,
			a017.incgrpid as incgrpid,
				a017.revision as revision
			from cfsec213.TSecInc as a017
			where 
			( ( ( a017.TenantId = priorTenantId )
					and ( a017.TSecGrpIncId < priorTSecGrpIncId ) )
				or ( ( a017.TenantId < priorTenantId ) ) )
				order by TenantId desc,
					TSecGrpIncId desc
			limit 25;
		else
			return query select
			a017.createdby,
			to_char( a017.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a017.updatedby,
			to_char( a017.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a017.tenantid as tenantid,
			a017.tsecgrpincid as tsecgrpincid,
			a017.tsecgrpid as tsecgrpid,
			a017.incgrpid as incgrpid,
				a017.revision as revision
			from cfsec213.TSecInc as a017
				order by TenantId desc,
					TSecGrpIncId desc
			limit 25;
		end if;
	else
		if( ( priorTenantId is not null )and ( priorTSecGrpIncId is not null ) )
		then
			return query select
			a017.createdby,
			to_char( a017.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a017.updatedby,
			to_char( a017.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a017.tenantid as tenantid,
			a017.tsecgrpincid as tsecgrpincid,
			a017.tsecgrpid as tsecgrpid,
			a017.incgrpid as incgrpid,
				a017.revision as revision
			from cfsec213.TSecInc as a017
			where 
			( ( ( a017.TenantId = priorTenantId )
					and ( a017.TSecGrpIncId < priorTSecGrpIncId ) )
				or ( ( a017.TenantId < priorTenantId ) ) )
				order by TenantId desc,
					TSecGrpIncId desc
			limit 25;
		else
			return query select
			a017.createdby,
			to_char( a017.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a017.updatedby,
			to_char( a017.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a017.tenantid as tenantid,
			a017.tsecgrpincid as tsecgrpincid,
			a017.tsecgrpid as tsecgrpid,
			a017.incgrpid as incgrpid,
				a017.revision as revision
			from cfsec213.TSecInc as a017
				order by TenantId desc,
					TSecGrpIncId desc
			limit 25;
		end if;
	end if;
	return;
end;
$$ language plpgsql;