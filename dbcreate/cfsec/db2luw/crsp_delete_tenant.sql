--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_tenant.sql
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
create or replace procedure sp_delete_tenant(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argId bigint,	\
	in argRevision int )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldClusterId bigint;	\
	declare oldId bigint;	\
	declare oldTenantName varchar(192);	\
	declare oldRevision int;	\
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
		select	\
			ClusterId,	\
			Id,	\
			TenantName,	\
			revision	\
		into	\
			oldClusterId,	\
			oldId,	\
			oldTenantName,	\
			oldRevision	\
		from cfsec213.tenant	\
		where	\
			Id = argId	\
		for update;	\
	\
		set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20001, 'Permission denied -- only system user can delete Tenant records' );	\
		end if;	\
	\
	\
		for cur as	\
			select	\
				a017.tenantid as tenantid,	\
				a017.tsecgrpincid as tsecgrpincid	\
			from cfsec213.tenant as a015	\
				inner join cfsec213.tsecgrp a016 on 	\
					a015.id = a016.tenantid	\
				inner join cfsec213.tsecinc a017 on 	\
					a016.tenantid = a017.tenantid	\
					and a016.tsecgroupid = a017.incgrpid	\
			where	\
				a015.id = argId	\
		do	\
			call sp_delete_tsecinc_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					tenantid,	\
					tsecgrpincid );	\
		end for;	\
	\
		for cur as	\
			select	\
				a018.tenantid as tenantid,	\
				a018.tsecgrpmembid as tsecgrpmembid	\
			from cfsec213.tenant as a015	\
				inner join cfsec213.tsecgrp a016 on 	\
					a015.id = a016.tenantid	\
				inner join cfsec213.tsecmemb a018 on 	\
					a016.tenantid = a018.tenantid	\
					and a016.tsecgroupid = a018.tsecgroupid	\
			where	\
				a015.id = argId	\
		do	\
			call sp_delete_tsecmemb_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					tenantid,	\
					tsecgrpmembid );	\
		end for;	\
	\
		for cur as	\
			select	\
				a017.tenantid as tenantid,	\
				a017.tsecgrpincid as tsecgrpincid	\
			from cfsec213.tenant as a015	\
				inner join cfsec213.tsecgrp a016 on 	\
					a015.id = a016.tenantid	\
				inner join cfsec213.tsecinc a017 on 	\
					a016.tenantid = a017.tenantid	\
					and a016.tsecgroupid = a017.tsecgrpid	\
			where	\
				a015.id = argId	\
		do	\
			call sp_delete_tsecinc_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					tenantid,	\
					tsecgrpincid );	\
		end for;	\
	\
		for cur as	\
			select	\
				a016.tenantid as tenantid,	\
				a016.tsecgroupid as tsecgroupid	\
			from cfsec213.tenant as a015	\
				inner join cfsec213.tsecgrp a016 on 	\
					a015.id = a016.tenantid	\
			where	\
				a015.id = argId	\
		do	\
			call sp_delete_tsecgrp_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					tenantid,	\
					tsecgroupid );	\
		end for;	\
	\
		insert into cfsec213.tenant_h (	\
				id,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				clusterid,	\
				tenantname,	\
			revision,	\
			auditaction )	\
		select	\
				a015.id,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a015.clusterid,	\
				a015.tenantname,	\
			a015.revision + 1,	\
			2	\
		from cfsec213.tenant as a015	\
		where	\
			a015.id = argId;	\
	\
		delete from cfsec213.tenant	\
		where	\
			id = argId;	\
	\
		open retcursor;	\
	end;	\
end
