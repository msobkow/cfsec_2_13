--
--	@(#) dbcreate/cfsec/pgsql/crsp_page_secmemb_all.pgsql
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
create or replace function cfsec213.sp_page_secmemb_all(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	priorClusterId bigint,
	priorSecGrpMembId bigint )
returns setof cfsec213.type_secmemb_rec as $$
declare
	permissionFlag boolean;
	isSystemUser boolean;
begin
	select cfsec213.sp_is_cluster_user( secClusterId,
			'ReadSecGrpMemb',
			argAuditUserId ),
		cfsec213.sp_is_system_user( argAuditUserId )
	into permissionFlag, isSystemUser;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in cluster SecGroup for ReadSecGrpMemb';
	end if;
	if( isSystemUser )
	then
		if( ( priorClusterId is not null )and ( priorSecGrpMembId is not null ) )
		then
			return query select
			a00f.createdby,
			to_char( a00f.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00f.updatedby,
			to_char( a00f.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00f.clusterid as clusterid,
			a00f.secgrpmembid as secgrpmembid,
			a00f.secgroupid as secgroupid,
			a00f.secuserid as secuserid,
				a00f.revision as revision
			from cfsec213.SecMemb as a00f
			where 
			( ( ( a00f.ClusterId = priorClusterId )
					and ( a00f.SecGrpMembId < priorSecGrpMembId ) )
				or ( ( a00f.ClusterId < priorClusterId ) ) )
				order by ClusterId desc,
					SecGrpMembId desc
			limit 25;
		else
			return query select
			a00f.createdby,
			to_char( a00f.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00f.updatedby,
			to_char( a00f.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00f.clusterid as clusterid,
			a00f.secgrpmembid as secgrpmembid,
			a00f.secgroupid as secgroupid,
			a00f.secuserid as secuserid,
				a00f.revision as revision
			from cfsec213.SecMemb as a00f
				order by ClusterId desc,
					SecGrpMembId desc
			limit 25;
		end if;
	else
		if( ( priorClusterId is not null )and ( priorSecGrpMembId is not null ) )
		then
			return query select
			a00f.createdby,
			to_char( a00f.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00f.updatedby,
			to_char( a00f.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00f.clusterid as clusterid,
			a00f.secgrpmembid as secgrpmembid,
			a00f.secgroupid as secgroupid,
			a00f.secuserid as secuserid,
				a00f.revision as revision
			from cfsec213.SecMemb as a00f
		where
			a00f.ClusterId = secClusterId
			and ( ( ( a00f.ClusterId = priorClusterId )
					and ( a00f.SecGrpMembId < priorSecGrpMembId ) )
				or ( ( a00f.ClusterId < priorClusterId ) ) )
				order by ClusterId desc,
					SecGrpMembId desc
			limit 25;
		else
			return query select
			a00f.createdby,
			to_char( a00f.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00f.updatedby,
			to_char( a00f.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00f.clusterid as clusterid,
			a00f.secgrpmembid as secgrpmembid,
			a00f.secgroupid as secgroupid,
			a00f.secuserid as secuserid,
				a00f.revision as revision
			from cfsec213.SecMemb as a00f
		where
			a00f.ClusterId = secClusterId
				order by ClusterId desc,
					SecGrpMembId desc
			limit 25;
		end if;
	end if;
	return;
end;
$$ language plpgsql;
