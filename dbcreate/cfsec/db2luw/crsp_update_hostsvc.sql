--
--	@(#) dbcreate/cfsec/db2luw/crsp_update_hostsvc.sql
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

create or replace procedure sp_update_hostsvc(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argClusterId bigint,	\
	in argServiceId bigint,	\
	in argHostNodeId bigint,	\
	in argServiceTypeId integer,	\
	in argHostPort smallint,	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldClusterId bigint;	\
	declare oldServiceId bigint;	\
	declare oldHostNodeId bigint;	\
	declare oldServiceTypeId integer;	\
	declare oldHostPort smallint;	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select	\
				a012.createdby as createdby,	\
				to_char( a012.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a012.updatedby as updatedby,	\
				to_char( a012.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a012.clusterid as clusterid,	\
			a012.serviceid as serviceid,	\
			a012.hostnodeid as hostnodeid,	\
			a012.servicetypeid as servicetypeid,	\
			a012.hostport as hostport,	\
			a012.revision as revision	\
		from cfsec213.HostSvc as a012	\
		where	\
			a012.clusterid = argClusterId	\
		and a012.serviceid = argServiceId;	\
	begin	\
		if( argClassCode = 'a012' )	\
		then	\
			set( permissionFlag ) = ( sp_is_cluster_user( argClusterId,	\
					'UpdateService',	\
					argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for UpdateService' );	\
			end if;	\
		end if;	\
	\
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
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_hostsvc() Data collision detected' );	\
		end if;	\
	\
		update cfsec213.HostSvc	\
		set	\
			revision = argRevision + 1,	\
			updatedby = argAuditUserId,	\
			updatedat = current timestamp,	\
			hostnodeid = argHostNodeId,	\
			servicetypeid = argServiceTypeId,	\
			hostport = argHostPort	\
		where	\
			clusterid = argClusterId	\
		and serviceid = argServiceId	\
		and revision = argRevision;	\
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
			a012.revision,	\
			2	\
		from cfsec213.HostSvc as a012	\
		where	\
			a012.clusterid = argClusterId	\
		and a012.serviceid = argServiceId;	\
	\
		open retcursor;	\
	end;	\
end