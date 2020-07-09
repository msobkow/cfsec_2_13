--
--	@(#) dbcreate/cfsec/pgsql/crsp_create_hostnode.pgsql
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
create or replace function cfsec213.sp_create_hostnode(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argClusterId bigint,
	argDescription varchar(255),
	argHostName varchar(192) )
returns setof cfsec213.type_hostnode_rec as $$
declare
	permissionFlag boolean;
	argHostNodeId bigint;
begin
	if( argClassCode = 'a002' )
	then
		select cfsec213.sp_is_cluster_user( argClusterId,
			'CreateHostNode',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in cluster SecGroup for CreateHostNode';
		end if;
	end if;

	select cfsec213.sp_next_hostnodeidgen( argClusterId )
	into argHostNodeId;

	insert into cfsec213.hostnode(
		createdby,
		createdat,
		updatedby,
		updatedat,
		clusterid,
		hostnodeid,
		description,
		hostname,
		revision )
	values (
		argAuditUserId,
		now(),
		argAuditUserId,
		now(),
		argClusterId,
		argHostNodeId,
		argDescription,
		argHostName,
		1 );
	insert into cfsec213.HostNode_h (
			ClusterId,
			HostNodeId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			Description,
			HostName,
			revision,
			auditaction )
		select
			a002.ClusterId,
			a002.HostNodeId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a002.Description,
			a002.HostName,
			a002.revision,
			0
		from cfsec213.HostNode as a002
		where
			a002.clusterid = argClusterId
			and a002.hostnodeid = argHostNodeId;

	return query select
			a002.createdby,
			to_char( a002.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a002.updatedby,
			to_char( a002.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a002.clusterid as clusterid,
			a002.hostnodeid as hostnodeid,
			a002.description as description,
			a002.hostname as hostname,
			a002.revision as revision
	from cfsec213.HostNode as a002
	where
			a002.clusterid = argClusterId
			and a002.hostnodeid = argHostNodeId;

	return;
end;
$$ language plpgsql;
