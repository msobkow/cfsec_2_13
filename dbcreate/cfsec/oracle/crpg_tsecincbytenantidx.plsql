--
--	@(#) dbcreate/cfsec/oracle/crpg_tsecincbytenantidx.plsql
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
alter session set plsql_warnings = 'ENABLE:ALL';
/

create or replace procedure cfsec213.pg_tsecincbytenantidx(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argTenantId numeric,
	priorTenantId numeric,
	priorTSecGrpIncId numeric ) authid definer
is
	permissionFlag integer;
	isSystemUser integer;
	permissionDenied exception;
begin
	permissionFlag := cfsec213.sp_is_tenant_user( secTenantId,
			'ReadTSecGrpInc',
			argAuditUserId );
	isSystemUser := cfsec213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;
	if( ( isSystemUser = 1 ) and ( ( priorTenantId is not null )and ( priorTSecGrpIncId is not null ) ) )
	then
		open retCursor for
			select * from (
				select
			a017.createdby,
			to_char( a017.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a017.updatedby,
			to_char( a017.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a017.TenantId as TenantId,
			a017.TSecGrpIncId as TSecGrpIncId,
			a017.TSecGrpId as TSecGrpId,
			a017.IncGrpId as IncGrpId,
					a017.revision as revision
				from cfsec213.TSecInc a017
				where
					a017.TenantId = argTenantId
			and ( ( ( a017.TenantId = priorTenantId )
					and ( a017.TSecGrpIncId < priorTSecGrpIncId ) )
				or ( ( a017.TenantId < priorTenantId ) ) )
		order by TenantId desc,
			TSecGrpIncId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 1 ) and ( not ( ( priorTenantId is not null )and ( priorTSecGrpIncId is not null ) ) ) )
	then
		open retCursor for
			select * from (
				select
			a017.createdby,
			to_char( a017.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a017.updatedby,
			to_char( a017.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a017.TenantId as TenantId,
			a017.TSecGrpIncId as TSecGrpIncId,
			a017.TSecGrpId as TSecGrpId,
			a017.IncGrpId as IncGrpId,
					a017.revision as revision
				from cfsec213.TSecInc a017
				where
					a017.TenantId = argTenantId
		order by TenantId desc,
			TSecGrpIncId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 0 ) and ( ( priorTenantId is not null )and ( priorTSecGrpIncId is not null ) ) )
	then
		open retCursor for
			select * from (
				select
			a017.createdby,
			to_char( a017.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a017.updatedby,
			to_char( a017.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a017.TenantId as TenantId,
			a017.TSecGrpIncId as TSecGrpIncId,
			a017.TSecGrpId as TSecGrpId,
			a017.IncGrpId as IncGrpId,
					a017.revision as revision
				from cfsec213.TSecInc a017
				where
					a017.TenantId = argTenantId
					and a017.TenantId = secTenantId
			and ( ( ( a017.TenantId = priorTenantId )
					and ( a017.TSecGrpIncId < priorTSecGrpIncId ) )
				or ( ( a017.TenantId < priorTenantId ) ) )
		order by TenantId desc,
			TSecGrpIncId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 0 ) and ( not ( ( priorTenantId is not null )and ( priorTSecGrpIncId is not null ) ) ) )
	then
		open retCursor for
			select * from (
				select
			a017.createdby,
			to_char( a017.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a017.updatedby,
			to_char( a017.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a017.TenantId as TenantId,
			a017.TSecGrpIncId as TSecGrpIncId,
			a017.TSecGrpId as TSecGrpId,
			a017.IncGrpId as IncGrpId,
					a017.revision as revision
				from cfsec213.TSecInc a017
				where
					a017.TenantId = argTenantId
					and a017.TenantId = secTenantId
		order by TenantId desc,
			TSecGrpIncId desc
			) where ROWNUM <= 25;
	end if;
end pg_tsecincbytenantidx;
/

show errors procedure cfsec213.pg_tsecincbytenantidx;