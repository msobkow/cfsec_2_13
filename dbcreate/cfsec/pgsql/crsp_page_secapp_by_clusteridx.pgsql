--
--	@(#) dbcreate/cfsec/pgsql/crsp_page_secapp_by_clusteridx.pgsql
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
create or replace function cfsec213.sp_page_secapp_by_clusteridx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClusterId bigint,
	priorClusterId bigint,
	priorSecAppId integer )
returns setof cfsec213.type_secapp_rec as $$
declare
	permissionFlag boolean;
	isSystemUser boolean;
begin
	select cfsec213.sp_is_cluster_user( secClusterId,
			'ReadSecApp',
			argAuditUserId ),
		cfsec213.sp_is_system_user( argAuditUserId )
	into permissionFlag, isSystemUser;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in cluster SecGroup for ReadSecApp';
	end if;
	if( isSystemUser )
	then
		if( ( priorClusterId is not null )and ( priorSecAppId is not null ) )
		then
			return query select
			a009.createdby,
			to_char( a009.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a009.updatedby,
			to_char( a009.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a009.clusterid as clusterid,
			a009.secappid as secappid,
			a009.jeemountname as jeemountname,
				a009.revision as revision
			from cfsec213.SecApp as a009
			where
				a009.clusterid = argClusterId
			and ( ( ( a009.ClusterId = priorClusterId )
					and ( a009.SecAppId < priorSecAppId ) )
				or ( ( a009.ClusterId < priorClusterId ) ) )
				order by ClusterId desc,
					SecAppId desc
			limit 25;
		else
			return query select
			a009.createdby,
			to_char( a009.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a009.updatedby,
			to_char( a009.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a009.clusterid as clusterid,
			a009.secappid as secappid,
			a009.jeemountname as jeemountname,
				a009.revision as revision
			from cfsec213.SecApp as a009
			where
				a009.clusterid = argClusterId
				order by ClusterId desc,
					SecAppId desc
			limit 25;
		end if;
	else
		if( ( priorClusterId is not null )and ( priorSecAppId is not null ) )
		then
			return query select
			a009.createdby,
			to_char( a009.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a009.updatedby,
			to_char( a009.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a009.clusterid as clusterid,
			a009.secappid as secappid,
			a009.jeemountname as jeemountname,
				a009.revision as revision
			from cfsec213.SecApp as a009
			where
				a009.clusterid = argClusterId
				and a009.ClusterId = secClusterId
			and ( ( ( a009.ClusterId = priorClusterId )
					and ( a009.SecAppId < priorSecAppId ) )
				or ( ( a009.ClusterId < priorClusterId ) ) )
				order by ClusterId desc,
					SecAppId desc
			limit 25;
		else
			return query select
			a009.createdby,
			to_char( a009.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a009.updatedby,
			to_char( a009.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a009.clusterid as clusterid,
			a009.secappid as secappid,
			a009.jeemountname as jeemountname,
				a009.revision as revision
			from cfsec213.SecApp as a009
			where
				a009.clusterid = argClusterId
				and a009.ClusterId = secClusterId
				order by ClusterId desc,
					SecAppId desc
			limit 25;
		end if;
	end if;
	return;
end
$$ language plpgsql;
