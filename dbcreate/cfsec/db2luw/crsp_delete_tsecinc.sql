--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_tsecinc.sql
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
create or replace procedure sp_delete_tsecinc(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argTenantId bigint,	\
	in argTSecGrpIncId bigint,	\
	in argRevision int )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldTenantId bigint;	\
	declare oldTSecGrpIncId bigint;	\
	declare oldTSecGroupId integer;	\
	declare oldIncludeGroupId integer;	\
	declare oldRevision int;	\
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
		select	\
			TenantId,	\
			TSecGrpIncId,	\
			TSecGrpId,	\
			IncGrpId,	\
			revision	\
		into	\
			oldTenantId,	\
			oldTSecGrpIncId,	\
			oldTSecGroupId,	\
			oldIncludeGroupId,	\
			oldRevision	\
		from cfsec213.TSecInc	\
		where	\
			TenantId = argTenantId	\
			and TSecGrpIncId = argTSecGrpIncId	\
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
				'DeleteTSecGrpInc',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20003, 'Permission denied -- User not found in tenant TSecGroup for DeleteTSecGrpInc' );	\
		end if;	\
	\
	\
		insert into cfsec213.TSecInc_h (	\
				tenantid,	\
				tsecgrpincid,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				tsecgrpid,	\
				incgrpid,	\
			revision,	\
			auditaction )	\
		select	\
				a017.tenantid,	\
				a017.tsecgrpincid,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a017.tsecgrpid,	\
				a017.incgrpid,	\
			a017.revision + 1,	\
			2	\
		from cfsec213.TSecInc as a017	\
		where	\
			a017.tenantid = argTenantId	\
		and a017.tsecgrpincid = argTSecGrpIncId;	\
	\
		delete from cfsec213.TSecInc	\
		where	\
			tenantid = argTenantId	\
			and tsecgrpincid = argTSecGrpIncId;	\
	\
		open retcursor;	\
	end;	\
end