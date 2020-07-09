--
--	@(#) dbcreate/cfsec/oracle/crpg_secdevall.plsql
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

create or replace procedure cfsec213.pg_secdevall(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	priorSecUserId varchar2,
	priorDevName varchar2 ) authid definer
is
begin
	if( ( priorSecUserId is not null )and ( priorDevName is not null ) )
	then
		open retCursor for
			select * from (
				select
			a00a.createdby,
			to_char( a00a.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00a.updatedby,
			to_char( a00a.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00a.SecUserId as SecUserId,
			a00a.DevName as DevName,
			a00a.PubKey as PubKey,
					a00a.revision as revision
				from cfsec213.SecDev a00a
			where ( ( ( a00a.SecUserId = priorSecUserId )
					and ( a00a.DevName < priorDevName ) )
				or ( ( a00a.SecUserId < priorSecUserId ) ) )
		order by SecUserId desc,
			DevName desc
			) where ROWNUM <= 25;
	end if;
	if( not ( ( priorSecUserId is not null )and ( priorDevName is not null ) ) )
	then
		open retCursor for
			select * from (
				select
			a00a.createdby,
			to_char( a00a.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00a.updatedby,
			to_char( a00a.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00a.SecUserId as SecUserId,
			a00a.DevName as DevName,
			a00a.PubKey as PubKey,
					a00a.revision as revision
				from cfsec213.SecDev a00a
		order by SecUserId desc,
			DevName desc
			) where ROWNUM <= 25;
	end if;
end pg_secdevall;
/

show errors procedure cfsec213.pg_secdevall;
