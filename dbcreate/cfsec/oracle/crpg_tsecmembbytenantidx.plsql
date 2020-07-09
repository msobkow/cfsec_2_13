--
--	@(#) dbcreate/cfsec/oracle/crpg_tsecmembbytenantidx.plsql
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

create or replace procedure cfsec213.pg_tsecmembbytenantidx(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argTenantId numeric,
	priorTenantId numeric,
	priorTSecGrpMembId numeric ) authid definer
is
	permissionFlag integer;
	isSystemUser integer;
	permissionDenied exception;
begin
	permissionFlag := cfsec213.sp_is_tenant_user( secTenantId,
			'ReadTSecGrpMemb',
			argAuditUserId );
	isSystemUser := cfsec213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;
	if( ( isSystemUser = 1 ) and ( ( priorTenantId is not null )and ( priorTSecGrpMembId is not null ) ) )
	then
		open retCursor for
			select * from (
				select
			a018.createdby,
			to_char( a018.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a018.updatedby,
			to_char( a018.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a018.TenantId as TenantId,
			a018.TSecGrpMembId as TSecGrpMembId,
			a018.TSecGroupId as TSecGroupId,
			a018.SecUserId as SecUserId,
					a018.revision as revision
				from cfsec213.TSecMemb a018
				where
					a018.TenantId = argTenantId
			and ( ( ( a018.TenantId = priorTenantId )
					and ( a018.TSecGrpMembId < priorTSecGrpMembId ) )
				or ( ( a018.TenantId < priorTenantId ) ) )
		order by TenantId desc,
			TSecGrpMembId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 1 ) and ( not ( ( priorTenantId is not null )and ( priorTSecGrpMembId is not null ) ) ) )
	then
		open retCursor for
			select * from (
				select
			a018.createdby,
			to_char( a018.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a018.updatedby,
			to_char( a018.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a018.TenantId as TenantId,
			a018.TSecGrpMembId as TSecGrpMembId,
			a018.TSecGroupId as TSecGroupId,
			a018.SecUserId as SecUserId,
					a018.revision as revision
				from cfsec213.TSecMemb a018
				where
					a018.TenantId = argTenantId
		order by TenantId desc,
			TSecGrpMembId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 0 ) and ( ( priorTenantId is not null )and ( priorTSecGrpMembId is not null ) ) )
	then
		open retCursor for
			select * from (
				select
			a018.createdby,
			to_char( a018.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a018.updatedby,
			to_char( a018.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a018.TenantId as TenantId,
			a018.TSecGrpMembId as TSecGrpMembId,
			a018.TSecGroupId as TSecGroupId,
			a018.SecUserId as SecUserId,
					a018.revision as revision
				from cfsec213.TSecMemb a018
				where
					a018.TenantId = argTenantId
					and a018.TenantId = secTenantId
			and ( ( ( a018.TenantId = priorTenantId )
					and ( a018.TSecGrpMembId < priorTSecGrpMembId ) )
				or ( ( a018.TenantId < priorTenantId ) ) )
		order by TenantId desc,
			TSecGrpMembId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 0 ) and ( not ( ( priorTenantId is not null )and ( priorTSecGrpMembId is not null ) ) ) )
	then
		open retCursor for
			select * from (
				select
			a018.createdby,
			to_char( a018.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a018.updatedby,
			to_char( a018.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a018.TenantId as TenantId,
			a018.TSecGrpMembId as TSecGrpMembId,
			a018.TSecGroupId as TSecGroupId,
			a018.SecUserId as SecUserId,
					a018.revision as revision
				from cfsec213.TSecMemb a018
				where
					a018.TenantId = argTenantId
					and a018.TenantId = secTenantId
		order by TenantId desc,
			TSecGrpMembId desc
			) where ROWNUM <= 25;
	end if;
end pg_tsecmembbytenantidx;
/

show errors procedure cfsec213.pg_tsecmembbytenantidx;
