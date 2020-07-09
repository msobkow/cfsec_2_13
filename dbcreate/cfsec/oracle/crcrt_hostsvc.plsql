--
--	@(#) dbcreate/cfsec/oracle/crcrt_hostsvc.plsql
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

create or replace procedure cfsec213.crt_hostsvc(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argClusterId numeric,
	argHostNodeId numeric,
	argServiceTypeId integer,
	argHostPort smallint ) authid definer
is
	permissionDenied exception;
	use_stamp cfsec213.HostSvc_h.auditstamp%type;
	permissionFlag integer;
	argServiceId numeric;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a012' )
	then
		permissionFlag := cfsec213.sp_is_cluster_user( argClusterId,
			'CreateService',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	argServiceId := cfsec213.nxt_serviceidgen( argClusterId );
	insert into cfsec213.hostsvc(
		createdby,
		createdat,
		updatedby,
		updatedat,
		ClusterId,
		ServiceId,
		HostNodeId,
		ServiceTypeId,
		HostPort,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argClusterId,
		argServiceId,
		argHostNodeId,
		argServiceTypeId,
		argHostPort,
		1 );
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
			a012.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a012.HostNodeId as HostNodeId,
			a012.ServiceTypeId as ServiceTypeId,
			a012.HostPort as HostPort,
			0,
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
end crt_hostsvc;
/

show errors procedure cfsec213.crt_hostsvc;
