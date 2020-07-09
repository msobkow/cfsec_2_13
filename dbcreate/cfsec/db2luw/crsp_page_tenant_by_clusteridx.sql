--
--	@(#) dbcreate/cfsec/db2luw/crsp_page_tenant_by_clusteridx.sql
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
create or replace procedure sp_page_tenant_by_clusteridx(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClusterId bigint,	\
	in priorId bigint )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare isSystemUser integer;	\
	declare syscurs cursor with return to client for	\
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
			a015.clusterid = argClusterId	\
		order by Id desc	\
		fetch first 25 rows only;	\
	declare syspage cursor with return to client for	\
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
			a015.clusterid = argClusterId	\
			and ( ( ( a015.Id < priorId ) ) )	\
		order by Id desc	\
		fetch first 25 rows only;	\
	declare usercurs cursor with return to client for	\
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
			a015.clusterid = argClusterId	\
		order by Id desc	\
		fetch first 25 rows only;	\
	declare userpage cursor with return to client for	\
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
			a015.clusterid = argClusterId	\
			and ( ( ( a015.Id < priorId ) ) )	\
		order by Id desc	\
		fetch first 25 rows only;	\
	begin	\
		if( ( priorId is not null ) )	\
		then	\
			open syspage;	\
		end if;	\
		if( not ( ( priorId is not null ) ) )	\
		then	\
			open syscurs;	\
		end if;	\
	end;	\
end
