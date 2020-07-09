--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_hostnode.sql
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
create or replace procedure sp_delete_hostnode(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClusterId bigint,	\
	in argHostNodeId bigint,	\
	in argRevision int )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldClusterId bigint;	\
	declare oldHostNodeId bigint;	\
	declare oldDescription varchar(255);	\
	declare oldHostName varchar(192);	\
	declare oldRevision int;	\
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
		select	\
			ClusterId,	\
			HostNodeId,	\
			Description,	\
			HostName,	\
			revision	\
		into	\
			oldClusterId,	\
			oldHostNodeId,	\
			oldDescription,	\
			oldHostName,	\
			oldRevision	\
		from cfsec213.HostNode	\
		where	\
			ClusterId = argClusterId	\
			and HostNodeId = argHostNodeId	\
		for update;	\
	\
		if( oldClusterId != secClusterId )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20002, 'Permission denied -- Data is not owned by logged in cluster' );	\
			end if;	\
		end if;	\
	\
		set( permissionFlag ) = ( sp_is_cluster_user( oldClusterId,	\
				'DeleteHostNode',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for DeleteHostNode' );	\
		end if;	\
	\
	\
		for cur as	\
			select	\
				a012.clusterid as clusterid,	\
				a012.serviceid as serviceid	\
			from cfsec213.HostNode as a002	\
				inner join cfsec213.hostsvc a012 on 	\
					a002.clusterid = a012.clusterid	\
					and a002.hostnodeid = a012.hostnodeid	\
			where	\
				a002.clusterid = argClusterId	\
				and a002.hostnodeid = argHostNodeId	\
		do	\
			call sp_delete_hostsvc_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					clusterid,	\
					serviceid );	\
		end for;	\
	\
		insert into cfsec213.HostNode_h (	\
				clusterid,	\
				hostnodeid,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				description,	\
				hostname,	\
			revision,	\
			auditaction )	\
		select	\
				a002.clusterid,	\
				a002.hostnodeid,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a002.description,	\
				a002.hostname,	\
			a002.revision + 1,	\
			2	\
		from cfsec213.HostNode as a002	\
		where	\
			a002.clusterid = argClusterId	\
		and a002.hostnodeid = argHostNodeId;	\
	\
		delete from cfsec213.HostNode	\
		where	\
			clusterid = argClusterId	\
			and hostnodeid = argHostNodeId;	\
	\
		open retcursor;	\
	end;	\
end
