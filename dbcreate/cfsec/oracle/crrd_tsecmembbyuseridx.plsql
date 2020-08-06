--
--	@(#) dbcreate/cfsec/oracle/crrd_tsecmembbyuseridx.plsql
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

create or replace procedure cfsec213.rd_tsecmembbyuseridx(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argSecUserId varchar2 ) authid definer
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
	if( isSystemUser = 1 )
	then
		open retCursor for select
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
			a018.SecUserId = argSecUserId
		order by TenantId desc,
			TSecGrpMembId desc;
	else
		open retCursor for select
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
			a018.SecUserId = argSecUserId
			and a018.TenantId = secTenantId
		order by TenantId desc,
			TSecGrpMembId desc;
	end if;
end rd_tsecmembbyuseridx;
/

show errors procedure cfsec213.rd_tsecmembbyuseridx;