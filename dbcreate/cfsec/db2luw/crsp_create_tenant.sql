--
--	@(#) dbcreate/cfsec/db2luw/crsp_create_tenant.sql
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
create or replace procedure sp_create_tenant(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argClusterId bigint,	\
	in argTenantName varchar(192) )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
		declare argId bigint;	\
	declare retcursor cursor with return to client for	\
		select	\
				a015.createdby as createdby,	\
				to_char( a015.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a015.updatedby as updatedby,	\
				to_char( a015.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a015.clusterid as clusterid,	\
			a015.id as id,	\
			a015.tenantname as tenantname,	\
			a015.revision as revision	\
		from cfsec213.tenant as a015	\
		where	\
			a015.id = argId;	\
	begin	\
		if( argClassCode = 'a015' )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20001, 'Permission denied -- only system user can create Tenant records' );	\
			end if;	\
		end if;	\
		call sp_next_tenantidgen( argId );	\
		insert into cfsec213.tenant(	\
			createdby,	\
			createdat,	\
			updatedby,	\
			updatedat,	\
			clusterid,	\
			id,	\
			tenantname,	\
			revision )	\
		values (	\
			argAuditUserId,	\
			current timestamp,	\
			argAuditUserId,	\
			current timestamp,	\
			argClusterId,	\
			argId,	\
			argTenantName,	\
			1 );	\
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
				a015.revision,	\
				0	\
		from cfsec213.tenant as a015	\
		where	\
				a015.id = argId;	\
	\
		open retcursor;	\
	end;	\
end
