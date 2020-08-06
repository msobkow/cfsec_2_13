--
--	@(#) dbcreate/cfsec/db2luw/crsp_page_tsecmemb_by_useridx.sql
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
create or replace procedure sp_page_tsecmemb_by_useridx(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argSecUserId varchar(36),	\
	in priorTenantId bigint,	\
	in priorTSecGrpMembId bigint )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare isSystemUser integer;	\
	declare syscurs cursor with return to client for	\
		select	\
				a018.createdby as createdby,	\
				to_char( a018.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a018.updatedby as updatedby,	\
				to_char( a018.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a018.tenantid as tenantid,	\
			a018.tsecgrpmembid as tsecgrpmembid,	\
			a018.tsecgroupid as tsecgroupid,	\
			a018.secuserid as secuserid,	\
			a018.revision as revision	\
		from cfsec213.TSecMemb as a018	\
		where	\
			a018.secuserid = argSecUserId	\
		order by TenantId desc,	\
			TSecGrpMembId desc	\
		fetch first 25 rows only;	\
	declare syspage cursor with return to client for	\
		select	\
				a018.createdby as createdby,	\
				to_char( a018.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a018.updatedby as updatedby,	\
				to_char( a018.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a018.tenantid as tenantid,	\
			a018.tsecgrpmembid as tsecgrpmembid,	\
			a018.tsecgroupid as tsecgroupid,	\
			a018.secuserid as secuserid,	\
			a018.revision as revision	\
		from cfsec213.TSecMemb as a018	\
		where	\
			a018.secuserid = argSecUserId	\
			and ( ( ( a018.TenantId = priorTenantId )	\
					and ( a018.TSecGrpMembId < priorTSecGrpMembId ) )	\
				or ( ( a018.TenantId < priorTenantId ) ) )	\
		order by TenantId desc,	\
			TSecGrpMembId desc	\
		fetch first 25 rows only;	\
	declare usercurs cursor with return to client for	\
		select	\
				a018.createdby as createdby,	\
				to_char( a018.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a018.updatedby as updatedby,	\
				to_char( a018.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a018.tenantid as tenantid,	\
			a018.tsecgrpmembid as tsecgrpmembid,	\
			a018.tsecgroupid as tsecgroupid,	\
			a018.secuserid as secuserid,	\
			a018.revision as revision	\
		from cfsec213.TSecMemb as a018	\
		where	\
			a018.secuserid = argSecUserId	\
			and ( a018.TenantId = secTenantId )	\
		order by TenantId desc,	\
			TSecGrpMembId desc	\
		fetch first 25 rows only;	\
	declare userpage cursor with return to client for	\
		select	\
				a018.createdby as createdby,	\
				to_char( a018.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a018.updatedby as updatedby,	\
				to_char( a018.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a018.tenantid as tenantid,	\
			a018.tsecgrpmembid as tsecgrpmembid,	\
			a018.tsecgroupid as tsecgroupid,	\
			a018.secuserid as secuserid,	\
			a018.revision as revision	\
		from cfsec213.TSecMemb as a018	\
		where	\
			a018.secuserid = argSecUserId	\
			and ( a018.TenantId = secTenantId )	\
			and ( ( ( a018.TenantId = priorTenantId )	\
					and ( a018.TSecGrpMembId < priorTSecGrpMembId ) )	\
				or ( ( a018.TenantId < priorTenantId ) ) )	\
		order by TenantId desc,	\
			TSecGrpMembId desc	\
		fetch first 25 rows only;	\
	begin	\
		set( permissionFlag ) = ( sp_is_tenant_user( secTenantId,	\
				'ReadTSecGrpMemb',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20003, 'Permission denied -- User not found in tenant TSecGroup for ReadTSecGrpMemb' );	\
		end if;	\
		set( isSystemUser ) = ( sp_is_system_user( argAuditUserId ) );	\
		if( ( isSystemUser = 1 ) and ( ( priorTenantId is not null ) and ( priorTSecGrpMembId is not null ) ) )	\
		then	\
			open syspage;	\
		end if;	\
		if( ( isSystemUser = 1 ) and ( not ( ( priorTenantId is not null ) and ( priorTSecGrpMembId is not null ) ) ) )	\
		then	\
			open syscurs;	\
		end if;	\
		if( ( isSystemUser = 0 ) and ( ( priorTenantId is not null ) and ( priorTSecGrpMembId is not null ) ) )	\
		then	\
			open userpage;	\
		end if;	\
		if( ( isSystemUser = 0 ) and ( not ( ( priorTenantId is not null ) and ( priorTSecGrpMembId is not null ) ) ) )	\
		then	\
			open usercurs;	\
		end if;	\
	end;	\
end
