--
--	@(#) dbcreate/cfsec/db2luw/crsp_read_tsecgrp.sql
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
create or replace procedure sp_read_tsecgrp(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argTenantId bigint,	\
	in argTSecGroupId integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare isSystemUser integer;	\
	declare syscurs cursor with return to client for	\
		select	\
				a016.createdby as createdby,	\
				to_char( a016.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a016.updatedby as updatedby,	\
				to_char( a016.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a016.tenantid as tenantid,	\
			a016.tsecgroupid as tsecgroupid,	\
			a016.safe_name as safe_name,	\
			a016.isvisible as isvisible,	\
			a016.revision as revision	\
		from cfsec213.TSecGrp as a016	\
		where	\
			a016.tenantid = argTenantId	\
		and a016.tsecgroupid = argTSecGroupId;	\
	declare usercurs cursor with return to client for	\
		select	\
				a016.createdby as createdby,	\
				to_char( a016.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a016.updatedby as updatedby,	\
				to_char( a016.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a016.tenantid as tenantid,	\
			a016.tsecgroupid as tsecgroupid,	\
			a016.safe_name as safe_name,	\
			a016.isvisible as isvisible,	\
			a016.revision as revision	\
		from cfsec213.TSecGrp as a016	\
		where	\
			a016.tenantid = argTenantId	\
		and a016.tsecgroupid = argTSecGroupId	\
			and ( a016.TenantId = secTenantId );	\
	begin	\
		set( permissionFlag ) = ( sp_is_tenant_user( secTenantId,	\
				'ReadTSecGroup',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20003, 'Permission denied -- User not found in tenant TSecGroup for ReadTSecGroup' );	\
		end if;	\
		set( isSystemUser ) = ( sp_is_system_user( argAuditUserId ) );	\
		if( isSystemUser = 1 )	\
		then	\
			open syscurs;	\
		else	\
			open usercurs;	\
		end if;	\
	end;	\
end
