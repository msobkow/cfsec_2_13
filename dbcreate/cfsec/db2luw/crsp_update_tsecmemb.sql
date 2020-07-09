--
--	@(#) dbcreate/cfsec/db2luw/crsp_update_tsecmemb.sql
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

create or replace procedure sp_update_tsecmemb(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argTenantId bigint,	\
	in argTSecGrpMembId bigint,	\
	in argTSecGroupId integer,	\
	in argSecUserId varchar(36),	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldTenantId bigint;	\
	declare oldTSecGrpMembId bigint;	\
	declare oldTSecGroupId integer;	\
	declare oldSecUserId varchar(36);	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
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
			a018.tenantid = argTenantId	\
		and a018.tsecgrpmembid = argTSecGrpMembId;	\
	begin	\
		if( argClassCode = 'a018' )	\
		then	\
			set( permissionFlag ) = ( sp_is_tenant_user( argTenantId,	\
					'UpdateTSecGrpMemb',	\
					argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20003, 'Permission denied -- User not found in tenant TSecGroup for UpdateTSecGrpMemb' );	\
			end if;	\
		end if;	\
	\
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
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_tsecmemb() Data collision detected' );	\
		end if;	\
	\
		update cfsec213.TSecMemb	\
		set	\
			revision = argRevision + 1,	\
			updatedby = argAuditUserId,	\
			updatedat = current timestamp,	\
			tsecgroupid = argTSecGroupId,	\
			secuserid = argSecUserId	\
		where	\
			tenantid = argTenantId	\
		and tsecgrpmembid = argTSecGrpMembId	\
		and revision = argRevision;	\
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
			a018.revision,	\
			2	\
		from cfsec213.TSecMemb as a018	\
		where	\
			a018.tenantid = argTenantId	\
		and a018.tsecgrpmembid = argTSecGrpMembId;	\
	\
		open retcursor;	\
	end;	\
end
