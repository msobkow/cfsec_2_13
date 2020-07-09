--
--	@(#) dbcreate/cfsec/pgsql/crsp_page_secgrpfrm_by_appidx.pgsql
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
create or replace function cfsec213.sp_page_secgrpfrm_by_appidx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClusterId bigint,
	argSecAppId integer,
	priorClusterId bigint,
	priorSecGroupFormId bigint )
returns setof cfsec213.type_secgrpfrm_rec as $$
declare
	permissionFlag boolean;
	isSystemUser boolean;
begin
	select cfsec213.sp_is_cluster_user( secClusterId,
			'ReadSecGroupForm',
			argAuditUserId ),
		cfsec213.sp_is_system_user( argAuditUserId )
	into permissionFlag, isSystemUser;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in cluster SecGroup for ReadSecGroupForm';
	end if;
	if( isSystemUser )
	then
		if( ( priorClusterId is not null )and ( priorSecGroupFormId is not null ) )
		then
			return query select
			a00d.createdby,
			to_char( a00d.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00d.updatedby,
			to_char( a00d.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00d.clusid as clusid,
			a00d.secgrpfrmid as secgrpfrmid,
			a00d.secgrpid as secgrpid,
			a00d.secappid as secappid,
			a00d.secfrmid as secfrmid,
				a00d.revision as revision
			from cfsec213.SecGrpFrm as a00d
			where
				a00d.clusid = argClusterId
			and a00d.secappid = argSecAppId
			and ( ( ( a00d.ClusId = priorClusterId )
					and ( a00d.SecGrpFrmId < priorSecGroupFormId ) )
				or ( ( a00d.ClusId < priorClusterId ) ) )
				order by ClusId desc,
					SecGrpFrmId desc
			limit 25;
		else
			return query select
			a00d.createdby,
			to_char( a00d.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00d.updatedby,
			to_char( a00d.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00d.clusid as clusid,
			a00d.secgrpfrmid as secgrpfrmid,
			a00d.secgrpid as secgrpid,
			a00d.secappid as secappid,
			a00d.secfrmid as secfrmid,
				a00d.revision as revision
			from cfsec213.SecGrpFrm as a00d
			where
				a00d.clusid = argClusterId
			and a00d.secappid = argSecAppId
				order by ClusId desc,
					SecGrpFrmId desc
			limit 25;
		end if;
	else
		if( ( priorClusterId is not null )and ( priorSecGroupFormId is not null ) )
		then
			return query select
			a00d.createdby,
			to_char( a00d.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00d.updatedby,
			to_char( a00d.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00d.clusid as clusid,
			a00d.secgrpfrmid as secgrpfrmid,
			a00d.secgrpid as secgrpid,
			a00d.secappid as secappid,
			a00d.secfrmid as secfrmid,
				a00d.revision as revision
			from cfsec213.SecGrpFrm as a00d
			where
				a00d.clusid = argClusterId
			and a00d.secappid = argSecAppId
				and a00d.ClusId = secClusterId
			and ( ( ( a00d.ClusId = priorClusterId )
					and ( a00d.SecGrpFrmId < priorSecGroupFormId ) )
				or ( ( a00d.ClusId < priorClusterId ) ) )
				order by ClusId desc,
					SecGrpFrmId desc
			limit 25;
		else
			return query select
			a00d.createdby,
			to_char( a00d.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00d.updatedby,
			to_char( a00d.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00d.clusid as clusid,
			a00d.secgrpfrmid as secgrpfrmid,
			a00d.secgrpid as secgrpid,
			a00d.secappid as secappid,
			a00d.secfrmid as secfrmid,
				a00d.revision as revision
			from cfsec213.SecGrpFrm as a00d
			where
				a00d.clusid = argClusterId
			and a00d.secappid = argSecAppId
				and a00d.ClusId = secClusterId
				order by ClusId desc,
					SecGrpFrmId desc
			limit 25;
		end if;
	end if;
	return;
end
$$ language plpgsql;
