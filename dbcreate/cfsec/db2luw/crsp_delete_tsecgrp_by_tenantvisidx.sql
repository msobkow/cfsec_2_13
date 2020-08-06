--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_tsecgrp_by_tenantvisidx.sql
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
create or replace procedure sp_delete_tsecgrp_by_tenantvisidx(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argTenantId bigint,	\
	in argIsVisible char(1) )	\
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
					a016.tenantid as tenantid,	\
					a016.tsecgroupid as tsecgroupid,	\
					a016.revision as revision	\
			from cfsec213.TSecGrp as a016	\
			where	\
					a016.tenantid = argTenantId	\
		and a016.isvisible = argIsVisible	\
		do	\
			call sp_delete_tsecgrp( argAuditClusterId,	\
							argAuditUserId,	\
							argAuditSessionId,	\
							secClusterId,	\
							secTenantId,	\
							tenantid,	\
							tsecgroupid,	\
							revision );	\
		end for;	\
	else	\
		for cur as	\
			select	\
					a016.tenantid as tenantid,	\
					a016.tsecgroupid as tsecgroupid,	\
					a016.revision as revision	\
			from cfsec213.TSecGrp as a016	\
			where	\
					a016.tenantid = argTenantId	\
		and a016.isvisible = argIsVisible	\
					and a016.TenantId = secTenantId	\
		do	\
			call sp_delete_tsecgrp( argAuditClusterId,	\
							argAuditUserId,	\
							argAuditSessionId,	\
							secClusterId,	\
							secTenantId,	\
							tenantid,	\
							tsecgroupid,	\
							revision );	\
		end for;	\
	end if;	\
		open retcursor;	\
	end;	\
end
