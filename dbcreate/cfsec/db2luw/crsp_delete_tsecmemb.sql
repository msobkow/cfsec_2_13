--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_tsecmemb.sql
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
create or replace procedure sp_delete_tsecmemb(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argTenantId bigint,	\
	in argTSecGrpMembId bigint,	\
	in argRevision int )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldTenantId bigint;	\
	declare oldTSecGrpMembId bigint;	\
	declare oldTSecGroupId integer;	\
	declare oldSecUserId varchar(36);	\
	declare oldRevision int;	\
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
		select	\
			TenantId,	\
			TSecGrpMembId,	\
			TSecGroupId,	\
			SecUserId,	\
			revision	\
		into	\
			oldTenantId,	\
			oldTSecGrpMembId,	\
			oldTSecGroupId,	\
			oldSecUserId,	\
			oldRevision	\
		from cfsec213.TSecMemb	\
		where	\
			TenantId = argTenantId	\
			and TSecGrpMembId = argTSecGrpMembId	\
		for update;	\
	\
		if( oldTenantId != secTenantId )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20003, 'Permission denied -- Data is not owned by logged in tenant' );	\
			end if;	\
		end if;	\
	\
		set( permissionFlag ) = ( sp_is_tenant_user( oldTenantId,	\
				'DeleteTSecGrpMemb',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20003, 'Permission denied -- User not found in tenant TSecGroup for DeleteTSecGrpMemb' );	\
		end if;	\
	\
	\
		insert into cfsec213.TSecMemb_h (	\
				tenantid,	\
				tsecgrpmembid,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				tsecgroupid,	\
				secuserid,	\
			revision,	\
			auditaction )	\
		select	\
				a018.tenantid,	\
				a018.tsecgrpmembid,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a018.tsecgroupid,	\
				a018.secuserid,	\
			a018.revision + 1,	\
			2	\
		from cfsec213.TSecMemb as a018	\
		where	\
			a018.tenantid = argTenantId	\
		and a018.tsecgrpmembid = argTSecGrpMembId;	\
	\
		delete from cfsec213.TSecMemb	\
		where	\
			tenantid = argTenantId	\
			and tsecgrpmembid = argTSecGrpMembId;	\
	\
		open retcursor;	\
	end;	\
end
