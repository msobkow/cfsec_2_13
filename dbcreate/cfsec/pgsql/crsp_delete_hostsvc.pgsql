--
--	@(#) dbcreate/cfsec/pgsql/crsp_delete_hostsvc.pgsql
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
create or replace function cfsec213.sp_delete_hostsvc(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClusterId bigint,
	argServiceId bigint,
	argRevision int )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
	oldClusterId bigint;
	oldServiceId bigint;
	oldHostNodeId bigint;
	oldServiceTypeId integer;
	oldHostPort smallint;
	oldRevision int;
	permissionFlag boolean;
begin
		select
			ClusterId,
			ServiceId,
			HostNodeId,
			ServiceTypeId,
			HostPort,
			revision
		into
			oldClusterId,
			oldServiceId,
			oldHostNodeId,
			oldServiceTypeId,
			oldHostPort,
			oldRevision
		from cfsec213.HostSvc
		where
			ClusterId = argClusterId
			and ServiceId = argServiceId
		for update;

	if( oldClusterId != secClusterId )
	then
		select cfsec213.sp_is_system_user( argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- Data is not owned by logged in cluster';
		end if;
	end if;

	select cfsec213.sp_is_cluster_user( oldClusterId,
		'DeleteService',
		argAuditUserId )
	into permissionFlag;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in cluster SecGroup for DeleteService';
	end if;

	insert into cfsec213.HostSvc_h (
			ClusterId,
			ServiceId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			HostNodeId,
			ServiceTypeId,
			HostPort,
			revision,
			auditaction )
		select
			a012.ClusterId,
			a012.ServiceId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a012.HostNodeId,
			a012.ServiceTypeId,
			a012.HostPort,
			argRevision + 1,
			2
		from cfsec213.HostSvc as a012
		where
			a012.clusterid = argClusterId
			and a012.serviceid = argServiceId;


	delete from cfsec213.HostSvc
	where
		clusterid = argClusterId
		and serviceid = argServiceId;

	get diagnostics RowsAffected = row_count;
	if RowsAffected != 1 and RowsAffected != 0
	then
		raise exception 'sp_delete_hostsvc() Expected to affect 1 HostSvc, not %', RowsAffected;
	end if;

	return true;
end;
$$ language plpgsql;
