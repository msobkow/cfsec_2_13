--
--	@(#) dbcreate/cfsec/oracle/crpg_secmemball.plsql
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

create or replace procedure cfsec213.pg_secmemball(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	priorClusterId numeric,
	priorSecGrpMembId numeric ) authid definer
is
	permissionFlag integer;
	isSystemUser integer;
	permissionDenied exception;
begin
	permissionFlag := cfsec213.sp_is_cluster_user( secClusterId,
			'ReadSecGrpMemb',
			argAuditUserId );
	isSystemUser := cfsec213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;
	if( ( isSystemUser = 1 ) and ( ( priorClusterId is not null )and ( priorSecGrpMembId is not null ) ) )
	then
		open retCursor for
			select * from (
				select
			a00f.createdby,
			to_char( a00f.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00f.updatedby,
			to_char( a00f.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00f.ClusterId as ClusterId,
			a00f.SecGrpMembId as SecGrpMembId,
			a00f.SecGroupId as SecGroupId,
			a00f.SecUserId as SecUserId,
					a00f.revision as revision
				from cfsec213.SecMemb a00f
			where ( ( ( a00f.ClusterId = priorClusterId )
					and ( a00f.SecGrpMembId < priorSecGrpMembId ) )
				or ( ( a00f.ClusterId < priorClusterId ) ) )
		order by ClusterId desc,
			SecGrpMembId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 1 ) and ( not ( ( priorClusterId is not null )and ( priorSecGrpMembId is not null ) ) ) )
	then
		open retCursor for
			select * from (
				select
			a00f.createdby,
			to_char( a00f.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00f.updatedby,
			to_char( a00f.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00f.ClusterId as ClusterId,
			a00f.SecGrpMembId as SecGrpMembId,
			a00f.SecGroupId as SecGroupId,
			a00f.SecUserId as SecUserId,
					a00f.revision as revision
				from cfsec213.SecMemb a00f
		order by ClusterId desc,
			SecGrpMembId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 0 ) and ( ( priorClusterId is not null )and ( priorSecGrpMembId is not null ) ) )
	then
		open retCursor for
			select * from (
				select
			a00f.createdby,
			to_char( a00f.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00f.updatedby,
			to_char( a00f.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00f.ClusterId as ClusterId,
			a00f.SecGrpMembId as SecGrpMembId,
			a00f.SecGroupId as SecGroupId,
			a00f.SecUserId as SecUserId,
					a00f.revision as revision
				from cfsec213.SecMemb a00f
		where
			a00f.ClusterId = secClusterId
			and ( ( ( a00f.ClusterId = priorClusterId )
					and ( a00f.SecGrpMembId < priorSecGrpMembId ) )
				or ( ( a00f.ClusterId < priorClusterId ) ) )
		order by ClusterId desc,
			SecGrpMembId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 0 ) and ( not ( ( priorClusterId is not null )and ( priorSecGrpMembId is not null ) ) ) )
	then
		open retCursor for
			select * from (
				select
			a00f.createdby,
			to_char( a00f.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00f.updatedby,
			to_char( a00f.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00f.ClusterId as ClusterId,
			a00f.SecGrpMembId as SecGrpMembId,
			a00f.SecGroupId as SecGroupId,
			a00f.SecUserId as SecUserId,
					a00f.revision as revision
				from cfsec213.SecMemb a00f
		where
			a00f.ClusterId = secClusterId
		order by ClusterId desc,
			SecGrpMembId desc
			) where ROWNUM <= 25;
	end if;
end pg_secmemball;
/

show errors procedure cfsec213.pg_secmemball;
