--
--	@(#) dbcreate/cfsec/pgsql/crsp_update_hostsvc.pgsql
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

create or replace function cfsec213.sp_update_hostsvc(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argClusterId bigint,
	argServiceId bigint,
	argHostNodeId bigint,
	argServiceTypeId integer,
	argHostPort smallint,
	argRevision integer )
returns setof cfsec213.type_hostsvc_rec as $$
declare
	RowsAffected integer;
	oldClusterId bigint;
	oldServiceId bigint;
	oldHostNodeId bigint;
	oldServiceTypeId integer;
	oldHostPort smallint;
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a012' )
	then
		select cfsec213.sp_is_cluster_user( argClusterId,
			'UpdateService',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in cluster SecGroup for UpdateService';
		end if;
	end if;

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


	if argRevision != oldRevision
	then
		raise exception 'sp_update_hostsvc() Data collision detected';
	end if;


	update cfsec213.HostSvc
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		hostnodeid = argHostNodeId,
		servicetypeid = argServiceTypeId,
		hostport = argHostPort
	where
		ClusterId = argClusterId
			and ServiceId = argServiceId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_hostsvc() Expected to affect one HostSvc row, not %', RowsAffected;
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
			1
		from cfsec213.HostSvc as a012
		where
			a012.clusterid = argClusterId
			and a012.serviceid = argServiceId;
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
			and a012.serviceid = argServiceId;

	return;
end;
$$ language plpgsql;
