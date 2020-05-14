--
--	@(#) dbcreate/cfsec/db2luw/crsp_create_hostnode.sql
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
create or replace procedure sp_create_hostnode(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argClusterId bigint,	\
	in argDescription varchar(255),	\
	in argHostName varchar(192) )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
		declare argHostNodeId bigint;	\
	declare retcursor cursor with return to client for	\
		select	\
				a002.createdby as createdby,	\
				to_char( a002.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a002.updatedby as updatedby,	\
				to_char( a002.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a002.clusterid as clusterid,	\
			a002.hostnodeid as hostnodeid,	\
			a002.description as description,	\
			a002.hostname as hostname,	\
			a002.revision as revision	\
		from cfsec213.HostNode as a002	\
		where	\
			a002.clusterid = argClusterId	\
		and a002.hostnodeid = argHostNodeId;	\
	begin	\
		if( argClassCode = 'a002' )	\
		then	\
			set( permissionFlag ) = ( sp_is_cluster_user( argClusterId,	\
					'CreateHostNode',	\
					argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for CreateHostNode' );	\
			end if;	\
		end if;	\
	\
		call sp_next_hostnodeidgen( argClusterId,	\
			argHostNodeId );	\
		insert into cfsec213.hostnode(	\
			createdby,	\
			createdat,	\
			updatedby,	\
			updatedat,	\
			clusterid,	\
			hostnodeid,	\
			description,	\
			hostname,	\
			revision )	\
		values (	\
			argAuditUserId,	\
			current timestamp,	\
			argAuditUserId,	\
			current timestamp,	\
			argClusterId,	\
			argHostNodeId,	\
			argDescription,	\
			argHostName,	\
			1 );	\
	\
		insert into cfsec213.hostnode_h (	\
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
				a002.revision,	\
				0	\
		from cfsec213.HostNode as a002	\
		where	\
				a002.clusterid = argClusterId	\
		and a002.hostnodeid = argHostNodeId;	\
	\
		open retcursor;	\
	end;	\
end
