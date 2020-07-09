--
--	@(#) dbcreate/cfsec/oracle/crpg_hostsvcbytypeidx.plsql
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

create or replace procedure cfsec213.pg_hostsvcbytypeidx(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argServiceTypeId integer,
	priorClusterId numeric,
	priorServiceId numeric ) authid definer
is
	permissionFlag integer;
	isSystemUser integer;
	permissionDenied exception;
begin
	permissionFlag := cfsec213.sp_is_cluster_user( secClusterId,
			'ReadService',
			argAuditUserId );
	isSystemUser := cfsec213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;
	if( ( isSystemUser = 1 ) and ( ( priorClusterId is not null )and ( priorServiceId is not null ) ) )
	then
		open retCursor for
			select * from (
				select
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
					a012.ServiceTypeId = argServiceTypeId
			and ( ( ( a012.ClusterId = priorClusterId )
					and ( a012.ServiceId < priorServiceId ) )
				or ( ( a012.ClusterId < priorClusterId ) ) )
		order by ClusterId desc,
			ServiceId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 1 ) and ( not ( ( priorClusterId is not null )and ( priorServiceId is not null ) ) ) )
	then
		open retCursor for
			select * from (
				select
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
					a012.ServiceTypeId = argServiceTypeId
		order by ClusterId desc,
			ServiceId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 0 ) and ( ( priorClusterId is not null )and ( priorServiceId is not null ) ) )
	then
		open retCursor for
			select * from (
				select
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
					a012.ServiceTypeId = argServiceTypeId
					and a012.ClusterId = secClusterId
			and ( ( ( a012.ClusterId = priorClusterId )
					and ( a012.ServiceId < priorServiceId ) )
				or ( ( a012.ClusterId < priorClusterId ) ) )
		order by ClusterId desc,
			ServiceId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 0 ) and ( not ( ( priorClusterId is not null )and ( priorServiceId is not null ) ) ) )
	then
		open retCursor for
			select * from (
				select
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
					a012.ServiceTypeId = argServiceTypeId
					and a012.ClusterId = secClusterId
		order by ClusterId desc,
			ServiceId desc
			) where ROWNUM <= 25;
	end if;
end pg_hostsvcbytypeidx;
/

show errors procedure cfsec213.pg_hostsvcbytypeidx;
