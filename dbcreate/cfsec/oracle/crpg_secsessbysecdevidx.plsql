--
--	@(#) dbcreate/cfsec/oracle/crpg_secsessbysecdevidx.plsql
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

create or replace procedure cfsec213.pg_secsessbysecdevidx(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argSecUserId varchar2,
	argSecDevName varchar2,
	priorSecSessionId varchar2 ) authid definer
is
begin
	if( ( priorSecSessionId is not null ) )
	then
		open retCursor for
			select * from (
				select
			a010.SecSessionId as SecSessionId,
			a010.SecUserId as SecUserId,
			a010.SecDevName as SecDevName,
			to_char( a010.start_ts, 'YYYY-MM-DD HH24:MI:SS' ) as start_ts,
			to_char( a010.finish_ts, 'YYYY-MM-DD HH24:MI:SS' ) as finish_ts,
			a010.SecProxyId as SecProxyId,
					a010.revision as revision
				from cfsec213.SecSess a010
				where
					a010.SecUserId = argSecUserId
			and ( ( ( argSecDevName is null ) and ( a010.SecDevName is null ) )
				or ( ( argSecDevName is not null ) and ( a010.SecDevName = argSecDevName ) ) )
			and ( ( ( a010.SecSessionId < priorSecSessionId ) ) )
		order by SecSessionId desc
			) where ROWNUM <= 25;
	end if;
	if( not ( ( priorSecSessionId is not null ) ) )
	then
		open retCursor for
			select * from (
				select
			a010.SecSessionId as SecSessionId,
			a010.SecUserId as SecUserId,
			a010.SecDevName as SecDevName,
			to_char( a010.start_ts, 'YYYY-MM-DD HH24:MI:SS' ) as start_ts,
			to_char( a010.finish_ts, 'YYYY-MM-DD HH24:MI:SS' ) as finish_ts,
			a010.SecProxyId as SecProxyId,
					a010.revision as revision
				from cfsec213.SecSess a010
				where
					a010.SecUserId = argSecUserId
			and ( ( ( argSecDevName is null ) and ( a010.SecDevName is null ) )
				or ( ( argSecDevName is not null ) and ( a010.SecDevName = argSecDevName ) ) )
		order by SecSessionId desc
			) where ROWNUM <= 25;
	end if;
end pg_secsessbysecdevidx;
/

show errors procedure cfsec213.pg_secsessbysecdevidx;
