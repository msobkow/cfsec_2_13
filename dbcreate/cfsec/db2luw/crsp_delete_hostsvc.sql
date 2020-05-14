--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_hostsvc.sql
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
create or replace procedure sp_delete_hostsvc(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClusterId bigint,	\
	in argServiceId bigint,	\
	in argRevision int )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldClusterId bigint;	\
	declare oldServiceId bigint;	\
	declare oldHostNodeId bigint;	\
	declare oldServiceTypeId integer;	\
	declare oldHostPort smallint;	\
	declare oldRevision int;	\
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
		select	\
			ClusterId,	\
			ServiceId,	\
			HostNodeId,	\
			ServiceTypeId,	\
			HostPort,	\
			revision	\
		into	\
			oldClusterId,	\
			oldServiceId,	\
			oldHostNodeId,	\
			oldServiceTypeId,	\
			oldHostPort,	\
			oldRevision	\
		from cfsec213.HostSvc	\
		where	\
			ClusterId = argClusterId	\
			and ServiceId = argServiceId	\
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
				'DeleteService',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for DeleteService' );	\
		end if;	\
	\
	\
		insert into cfsec213.HostSvc_h (	\
				clusterid,	\
				serviceid,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				hostnodeid,	\
				servicetypeid,	\
				hostport,	\
			revision,	\
			auditaction )	\
		select	\
				a012.clusterid,	\
				a012.serviceid,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a012.hostnodeid,	\
				a012.servicetypeid,	\
				a012.hostport,	\
			a012.revision + 1,	\
			2	\
		from cfsec213.HostSvc as a012	\
		where	\
			a012.clusterid = argClusterId	\
		and a012.serviceid = argServiceId;	\
	\
		delete from cfsec213.HostSvc	\
		where	\
			clusterid = argClusterId	\
			and serviceid = argServiceId;	\
	\
		open retcursor;	\
	end;	\
end
