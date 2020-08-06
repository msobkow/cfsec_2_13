--
--	@(#) dbcreate/cfsec/oracle/crrd_secappbyujeemountidx.plsql
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

create or replace procedure cfsec213.rd_secappbyujeemountidx(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClusterId numeric,
	argJEEMountName varchar2 ) authid definer
is
	permissionFlag integer;
	isSystemUser integer;
	permissionDenied exception;
begin
	permissionFlag := cfsec213.sp_is_cluster_user( secClusterId,
			'ReadSecApp',
			argAuditUserId );
	isSystemUser := cfsec213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;
	if( isSystemUser = 1 )
	then
		open retCursor for select
			a009.createdby,
			to_char( a009.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a009.updatedby,
			to_char( a009.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a009.ClusterId as ClusterId,
			a009.SecAppId as SecAppId,
			a009.JEEMountName as JEEMountName,
			a009.revision as revision
		from cfsec213.SecApp a009
		where
			a009.ClusterId = argClusterId
			and a009.JEEMountName = argJEEMountName;
	else
		open retCursor for select
			a009.createdby,
			to_char( a009.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a009.updatedby,
			to_char( a009.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a009.ClusterId as ClusterId,
			a009.SecAppId as SecAppId,
			a009.JEEMountName as JEEMountName,
			a009.revision as revision
		from cfsec213.SecApp a009
		where
			a009.ClusterId = argClusterId
			and a009.JEEMountName = argJEEMountName
			and a009.ClusterId = secClusterId;
	end if;
end rd_secappbyujeemountidx;
/

show errors procedure cfsec213.rd_secappbyujeemountidx;
