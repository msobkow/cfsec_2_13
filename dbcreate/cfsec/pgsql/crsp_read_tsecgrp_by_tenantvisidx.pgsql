--
--	@(#) dbcreate/cfsec/pgsql/crsp_read_tsecgrp_by_tenantvisidx.pgsql
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
create or replace function cfsec213.sp_read_tsecgrp_by_tenantvisidx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argTenantId bigint,
	argIsVisible boolean )
returns setof cfsec213.type_tsecgrp_rec as $$
declare
	permissionFlag boolean;
	isSystemUser boolean;
begin
	select cfsec213.sp_is_tenant_user( secTenantId,
			'ReadTSecGroup',
			argAuditUserId ),
		cfsec213.sp_is_system_user( argAuditUserId )
	into permissionFlag, isSystemUser;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in tenant TSecGroup for ReadTSecGroup';
	end if;
	if( isSystemUser )
	then
		return query select
			a016.createdby,
			to_char( a016.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a016.updatedby,
			to_char( a016.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a016.tenantid as tenantid,
			a016.tsecgroupid as tsecgroupid,
			a016.safe_name as safe_name,
			a016.isvisible as isvisible,
			a016.revision as revision
		from cfsec213.TSecGrp as a016
		where
			a016.tenantid = argTenantId
			and a016.isvisible = argIsVisible
				order by TenantId desc,
					TSecGroupId desc;
	else
		return query select
			a016.createdby,
			to_char( a016.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a016.updatedby,
			to_char( a016.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a016.tenantid as tenantid,
			a016.tsecgroupid as tsecgroupid,
			a016.safe_name as safe_name,
			a016.isvisible as isvisible,
			a016.revision as revision
		from cfsec213.TSecGrp as a016
		where
			a016.tenantid = argTenantId
			and a016.isvisible = argIsVisible
			and a016.TenantId = secTenantId
				order by TenantId desc,
					TSecGroupId desc;
	end if;
	return;
end
$$ language plpgsql;
