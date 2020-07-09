--
--	@(#) dbcreate/cfsec/oracle/crpg_tenantall.plsql
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
alter session set plsql_warnings = 'ENABLE:ALL';
/

create or replace procedure cfsec213.pg_tenantall(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	priorId numeric ) authid definer
is
begin
	if( ( priorId is not null ) )
	then
		open retCursor for
			select * from (
				select
			a015.createdby,
			to_char( a015.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a015.updatedby,
			to_char( a015.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a015.ClusterId as ClusterId,
			a015.Id as Id,
			a015.TenantName as TenantName,
					a015.revision as revision
				from cfsec213.tenant a015
			where ( ( ( a015.Id < priorId ) ) )
		order by Id desc
			) where ROWNUM <= 25;
	end if;
	if( not ( ( priorId is not null ) ) )
	then
		open retCursor for
			select * from (
				select
			a015.createdby,
			to_char( a015.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a015.updatedby,
			to_char( a015.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a015.ClusterId as ClusterId,
			a015.Id as Id,
			a015.TenantName as TenantName,
					a015.revision as revision
				from cfsec213.tenant a015
		order by Id desc
			) where ROWNUM <= 25;
	end if;
end pg_tenantall;
/

show errors procedure cfsec213.pg_tenantall;
