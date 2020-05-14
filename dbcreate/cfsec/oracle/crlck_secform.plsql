--
--	@(#) dbcreate/cfsec/oracle/crlck_secform.plsql
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


create or replace procedure cfsec213.lck_secform(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClusterId numeric,
	argSecFormId integer ) authid definer
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
	if( isSystemUser = 1 )
	then
		open retCursor for select
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
			and a00b.SecFormId = argSecFormId
		for update;
	else
		open retCursor for select
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
			and a00b.SecFormId = argSecFormId
			and a00b.ClusterId = secClusterId
		for update;
	end if;
end lck_secform;
/

show errors procedure cfsec213.lck_secform;