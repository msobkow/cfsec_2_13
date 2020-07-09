--
--	@(#) dbcreate/cfsec/oracle/crupd_hostsvc.plsql
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
alter session set plsql_warnings = 'ENABLE:ALL';
/


create or replace procedure cfsec213.upd_hostsvc(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argClusterId numeric,
	argServiceId numeric,
	argHostNodeId numeric,
	argServiceTypeId integer,
	argHostPort smallint,
	argRevision integer ) authid definer
is
	use_stamp cfsec213.HostSvc_h.auditstamp%type;
	oldClusterId numeric(22,0);
	oldServiceId numeric(22,0);
	oldHostNodeId numeric(22,0);
	oldServiceTypeId integer;
	oldHostPort smallint;
	oldRevision integer;
	dataCollision exception;
	dataUpdateFailed exception;
	permissionDenied exception;
	permissionFlag integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a012' )
	then
		permissionFlag := cfsec213.sp_is_cluster_user( argClusterId,
			'UpdateService',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
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
		raise dataCollision;
	end if;

	update cfsec213.HostSvc
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = use_stamp,
		HostNodeId = argHostNodeId,
		ServiceTypeId = argServiceTypeId,
		HostPort = argHostPort
	where
		ClusterId = argClusterId
		and ServiceId = argServiceId
		and revision = argRevision;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;


	insert into cfsec213.HostSvc_h (
			ClusterId,
			ServiceId,
			revision,
			auditclusterid,
			auditsessionid,
			HostNodeId,
			ServiceTypeId,
			HostPort,
			auditaction,
			auditstamp )
		select
			a012.ClusterId as ClusterId,
			a012.ServiceId as ServiceId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a012.HostNodeId as HostNodeId,
			a012.ServiceTypeId as ServiceTypeId,
			a012.HostPort as HostPort,
			1,
			use_stamp
		from cfsec213.HostSvc a012
		where
			a012.ClusterId = argClusterId
			and a012.ServiceId = argServiceId;

	open retCursor for select
			a012.createdby,
			to_char( a012.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a012.updatedby,
			to_char( a012.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a012.ClusterId as ClusterId,
			a012.ServiceId as ServiceId,
			a012.HostNodeId as HostNodeId,
			a012.ServiceTypeId as ServiceTypeId,
			a012.HostPort as HostPort,
		a012.revision as revision
	from cfsec213.HostSvc a012
	where
		a012.ClusterId = argClusterId
			and a012.ServiceId = argServiceId;
end upd_hostsvc;

/

show errors procedure cfsec213.upd_hostsvc;
