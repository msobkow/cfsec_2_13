--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_tsecinc_by_includeidx.sql
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
create or replace procedure sp_delete_tsecinc_by_includeidx(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argTenantId bigint,	\
	in argIncludeGroupId integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
begin 	\
	set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
	if( permissionFlag = 1 )	\
	then	\
		for cur as 	\
			select	\
					a017.tenantid as tenantid,	\
					a017.tsecgrpincid as tsecgrpincid,	\
					a017.revision as revision	\
			from cfsec213.TSecInc as a017	\
			where	\
					a017.tenantid = argTenantId	\
		and a017.incgrpid = argIncludeGroupId	\
		do	\
			call sp_delete_tsecinc( argAuditClusterId,	\
							argAuditUserId,	\
							argAuditSessionId,	\
							secClusterId,	\
							secTenantId,	\
							tenantid,	\
							tsecgrpincid,	\
							revision );	\
		end for;	\
	else	\
		for cur as	\
			select	\
					a017.tenantid as tenantid,	\
					a017.tsecgrpincid as tsecgrpincid,	\
					a017.revision as revision	\
			from cfsec213.TSecInc as a017	\
			where	\
					a017.tenantid = argTenantId	\
		and a017.incgrpid = argIncludeGroupId	\
					and a017.TenantId = secTenantId	\
		do	\
			call sp_delete_tsecinc( argAuditClusterId,	\
							argAuditUserId,	\
							argAuditSessionId,	\
							secClusterId,	\
							secTenantId,	\
							tenantid,	\
							tsecgrpincid,	\
							revision );	\
		end for;	\
	end if;	\
		open retcursor;	\
	end;	\
end