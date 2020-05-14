--
--	@(#) dbcreate/cfsec/pgsql/crsp_page_hostsvc_by_clusteridx.pgsql
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
create or replace function cfsec213.sp_page_hostsvc_by_clusteridx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClusterId bigint,
	priorClusterId bigint,
	priorServiceId bigint )
returns setof cfsec213.type_hostsvc_rec as $$
declare
	permissionFlag boolean;
	isSystemUser boolean;
begin
	select cfsec213.sp_is_cluster_user( secClusterId,
			'ReadService',
			argAuditUserId ),
		cfsec213.sp_is_system_user( argAuditUserId )
	into permissionFlag, isSystemUser;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in cluster SecGroup for ReadService';
	end if;
	if( isSystemUser )
	then
		if( ( priorClusterId is not null )and ( priorServiceId is not null ) )
		then
			return query select
			a012.createdby,
			to_char( a012.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a012.updatedby,
			to_char( a012.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a012.clusterid as clusterid,
			a012.serviceid as serviceid,
			a012.hostnodeid as hostnodeid,
			a012.servicetypeid as servicetypeid,
			a012.hostport as hostport,
				a012.revision as revision
			from cfsec213.HostSvc as a012
			where
				a012.clusterid = argClusterId
			and ( ( ( a012.ClusterId = priorClusterId )
					and ( a012.ServiceId < priorServiceId ) )
				or ( ( a012.ClusterId < priorClusterId ) ) )
				order by ClusterId desc,
					ServiceId desc
			limit 25;
		else
			return query select
			a012.createdby,
			to_char( a012.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a012.updatedby,
			to_char( a012.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a012.clusterid as clusterid,
			a012.serviceid as serviceid,
			a012.hostnodeid as hostnodeid,
			a012.servicetypeid as servicetypeid,
			a012.hostport as hostport,
				a012.revision as revision
			from cfsec213.HostSvc as a012
			where
				a012.clusterid = argClusterId
				order by ClusterId desc,
					ServiceId desc
			limit 25;
		end if;
	else
		if( ( priorClusterId is not null )and ( priorServiceId is not null ) )
		then
			return query select
			a012.createdby,
			to_char( a012.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a012.updatedby,
			to_char( a012.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a012.clusterid as clusterid,
			a012.serviceid as serviceid,
			a012.hostnodeid as hostnodeid,
			a012.servicetypeid as servicetypeid,
			a012.hostport as hostport,
				a012.revision as revision
			from cfsec213.HostSvc as a012
			where
				a012.clusterid = argClusterId
				and a012.ClusterId = secClusterId
			and ( ( ( a012.ClusterId = priorClusterId )
					and ( a012.ServiceId < priorServiceId ) )
				or ( ( a012.ClusterId < priorClusterId ) ) )
				order by ClusterId desc,
					ServiceId desc
			limit 25;
		else
			return query select
			a012.createdby,
			to_char( a012.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a012.updatedby,
			to_char( a012.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a012.clusterid as clusterid,
			a012.serviceid as serviceid,
			a012.hostnodeid as hostnodeid,
			a012.servicetypeid as servicetypeid,
			a012.hostport as hostport,
				a012.revision as revision
			from cfsec213.HostSvc as a012
			where
				a012.clusterid = argClusterId
				and a012.ClusterId = secClusterId
				order by ClusterId desc,
					ServiceId desc
			limit 25;
		end if;
	end if;
	return;
end
$$ language plpgsql;
