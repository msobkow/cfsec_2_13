--
--	@(#) dbcreate/cfsec/oracle/crrd_sysclusbyclusteridx.plsql
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
alter session set plsql_warnings = 'ENABLE:ALL';
/

create or replace procedure cfsec213.rd_sysclusbyclusteridx(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argsys_clus_id numeric ) authid definer
is
begin
	open retCursor for select
			a014.sgltn_id as sgltn_id,
			a014.sys_clus_id as sys_clus_id,
			a014.revision as revision
	from cfsec213.sysclus a014
	where
			a014.sys_clus_id = argsys_clus_id
		order by sgltn_id desc;
end rd_sysclusbyclusteridx;
/

show errors procedure cfsec213.rd_sysclusbyclusteridx;
