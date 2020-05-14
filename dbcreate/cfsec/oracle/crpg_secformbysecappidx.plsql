--
--	@(#) dbcreate/cfsec/oracle/crpg_secformbysecappidx.plsql
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

create or replace procedure cfsec213.pg_secformbysecappidx(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClusterId numeric,
	argSecAppId integer,
	priorClusterId numeric,
	priorSecFormId integer ) authid definer
is
	permissionFlag integer;
	isSystemUser integer;
	permissionDenied exception;
begin
	permissionFlag := cfsec213.sp_is_cluster_user( secClusterId,
			'ReadSecForm',
			argAuditUserId );
	isSystemUser := cfsec213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;
	if( ( isSystemUser = 1 ) and ( ( priorClusterId is not null )and ( priorSecFormId is not null ) ) )
	then
		open retCursor for
			select * from (
				select
			a00b.createdby,
			to_char( a00b.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00b.updatedby,
			to_char( a00b.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00b.ClusterId as ClusterId,
			a00b.SecFormId as SecFormId,
			a00b.SecAppId as SecAppId,
			a00b.JEEServletMapName as JEEServletMapName,
					a00b.revision as revision
				from cfsec213.SecForm a00b
				where
					a00b.ClusterId = argClusterId
			and a00b.SecAppId = argSecAppId
			and ( ( ( a00b.ClusterId = priorClusterId )
					and ( a00b.SecFormId < priorSecFormId ) )
				or ( ( a00b.ClusterId < priorClusterId ) ) )
		order by ClusterId desc,
			SecFormId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 1 ) and ( not ( ( priorClusterId is not null )and ( priorSecFormId is not null ) ) ) )
	then
		open retCursor for
			select * from (
				select
			a00b.createdby,
			to_char( a00b.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00b.updatedby,
			to_char( a00b.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00b.ClusterId as ClusterId,
			a00b.SecFormId as SecFormId,
			a00b.SecAppId as SecAppId,
			a00b.JEEServletMapName as JEEServletMapName,
					a00b.revision as revision
				from cfsec213.SecForm a00b
				where
					a00b.ClusterId = argClusterId
			and a00b.SecAppId = argSecAppId
		order by ClusterId desc,
			SecFormId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 0 ) and ( ( priorClusterId is not null )and ( priorSecFormId is not null ) ) )
	then
		open retCursor for
			select * from (
				select
			a00b.createdby,
			to_char( a00b.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00b.updatedby,
			to_char( a00b.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00b.ClusterId as ClusterId,
			a00b.SecFormId as SecFormId,
			a00b.SecAppId as SecAppId,
			a00b.JEEServletMapName as JEEServletMapName,
					a00b.revision as revision
				from cfsec213.SecForm a00b
				where
					a00b.ClusterId = argClusterId
			and a00b.SecAppId = argSecAppId
					and a00b.ClusterId = secClusterId
			and ( ( ( a00b.ClusterId = priorClusterId )
					and ( a00b.SecFormId < priorSecFormId ) )
				or ( ( a00b.ClusterId < priorClusterId ) ) )
		order by ClusterId desc,
			SecFormId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 0 ) and ( not ( ( priorClusterId is not null )and ( priorSecFormId is not null ) ) ) )
	then
		open retCursor for
			select * from (
				select
			a00b.createdby,
			to_char( a00b.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00b.updatedby,
			to_char( a00b.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00b.ClusterId as ClusterId,
			a00b.SecFormId as SecFormId,
			a00b.SecAppId as SecAppId,
			a00b.JEEServletMapName as JEEServletMapName,
					a00b.revision as revision
				from cfsec213.SecForm a00b
				where
					a00b.ClusterId = argClusterId
			and a00b.SecAppId = argSecAppId
					and a00b.ClusterId = secClusterId
		order by ClusterId desc,
			SecFormId desc
			) where ROWNUM <= 25;
	end if;
end pg_secformbysecappidx;
/

show errors procedure cfsec213.pg_secformbysecappidx;
