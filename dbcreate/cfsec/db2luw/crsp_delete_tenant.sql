--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_tenant.sql
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
