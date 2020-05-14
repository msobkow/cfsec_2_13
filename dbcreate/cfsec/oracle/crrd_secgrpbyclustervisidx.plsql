--
--	@(#) dbcreate/cfsec/oracle/crrd_secgrpbyclustervisidx.plsql
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

create or replace procedure cfsec213.rd_secgrpbyclustervisidx(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClusterId numeric,
	argIsVisible char ) authid definer
is
	permissionFlag integer;
	isSystemUser integer;
	permissionDenied exception;
begin
	permissionFlag := cfsec213.sp_is_cluster_user( secClusterId,
			'ReadSecGroup',
			argAuditUserId );
	isSystemUser := cfsec213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;
	if( isSystemUser = 1 )
	then
		open retCursor for select
			a00c.createdby,
			to_char( a00c.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00c.updatedby,
			to_char( a00c.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00c.ClusterId as ClusterId,
			a00c.SecGroupId as SecGroupId,
			a00c.safe_name as safe_name,
			a00c.IsVisible as IsVisible,
			a00c.revision as revision
		from cfsec213.SecGrp a00c
		where
			a00c.ClusterId = argClusterId
			and a00c.IsVisible = argIsVisible
		order by ClusterId desc,
			SecGroupId desc;
	else
		open retCursor for select
			a00c.createdby,
			to_char( a00c.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00c.updatedby,
			to_char( a00c.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00c.ClusterId as ClusterId,
			a00c.SecGroupId as SecGroupId,
			a00c.safe_name as safe_name,
			a00c.IsVisible as IsVisible,
			a00c.revision as revision
		from cfsec213.SecGrp a00c
		where
			a00c.ClusterId = argClusterId
			and a00c.IsVisible = argIsVisible
			and a00c.ClusterId = secClusterId
		order by ClusterId desc,
			SecGroupId desc;
	end if;
end rd_secgrpbyclustervisidx;
/

show errors procedure cfsec213.rd_secgrpbyclustervisidx;
