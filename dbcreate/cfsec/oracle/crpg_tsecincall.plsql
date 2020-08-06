--
--	@(#) dbcreate/cfsec/oracle/crpg_tsecincall.plsql
--
--	org.msscf.msscf.CFSec
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	MSS Code Factory CFSec 2.13 Security Essentials
--	
--	Copyright 2020 Mark Stephen Sobkow
--	
--		This file is part of MSS Code Factory.
--	
--		MSS Code Factory is available under dual commercial license from Mark Stephen
--		Sobkow, or under the terms of the GNU General Public License, Version 3
--		or later.
--	
--	    MSS Code Factory is free software: you can redistribute it and/or modify
--	    it under the terms of the GNU General Public License as published by
--	    the Free Software Foundation, either version 3 of the License, or
--	    (at your option) any later version.
--	
--	    MSS Code Factory is distributed in the hope that it will be useful,
--	    but WITHOUT ANY WARRANTY; without even the implied warranty of
--	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--	    GNU General Public License for more details.
--	
--	    You should have received a copy of the GNU General Public License
--	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
--	
--	Donations to support MSS Code Factory can be made at
--	https://www.paypal.com/paypalme2/MarkSobkow
--	
--	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
--
--	Manufactured by MSS Code Factory 2.12
--
alter session set plsql_warnings = 'ENABLE:ALL';
/

create or replace procedure cfsec213.pg_tsecincall(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
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
			where ( ( ( a017.TenantId = priorTenantId )
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
			a017.TenantId = secTenantId
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
			a017.TenantId = secTenantId
		order by TenantId desc,
			TSecGrpIncId desc
			) where ROWNUM <= 25;
	end if;
end pg_tsecincall;
/

show errors procedure cfsec213.pg_tsecincall;
