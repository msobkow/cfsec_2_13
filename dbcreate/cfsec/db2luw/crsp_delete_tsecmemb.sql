--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_tsecmemb.sql
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
