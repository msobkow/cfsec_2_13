--
--	@(#) dbcreate/cfsec/oracle/crpg_secgrpfrmbyappidx.plsql
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

create or replace procedure cfsec213.pg_secgrpfrmbyappidx(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClusId numeric,
	argSecAppId integer,
	priorClusterId numeric,
	priorSecGroupFormId numeric ) authid definer
is
	permissionFlag integer;
	isSystemUser integer;
	permissionDenied exception;
begin
	permissionFlag := cfsec213.sp_is_cluster_user( secClusterId,
			'ReadSecGroupForm',
			argAuditUserId );
	isSystemUser := cfsec213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;
	if( ( isSystemUser = 1 ) and ( ( priorClusterId is not null )and ( priorSecGroupFormId is not null ) ) )
	then
		open retCursor for
			select * from (
				select
			a00d.createdby,
			to_char( a00d.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00d.updatedby,
			to_char( a00d.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00d.ClusId as ClusId,
			a00d.SecGrpFrmId as SecGrpFrmId,
			a00d.SecGrpId as SecGrpId,
			a00d.SecAppId as SecAppId,
			a00d.SecFrmId as SecFrmId,
					a00d.revision as revision
				from cfsec213.SecGrpFrm a00d
				where
					a00d.ClusId = argClusId
			and a00d.SecAppId = argSecAppId
			and ( ( ( a00d.ClusId = priorClusterId )
					and ( a00d.SecGrpFrmId < priorSecGroupFormId ) )
				or ( ( a00d.ClusId < priorClusterId ) ) )
		order by ClusId desc,
			SecGrpFrmId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 1 ) and ( not ( ( priorClusterId is not null )and ( priorSecGroupFormId is not null ) ) ) )
	then
		open retCursor for
			select * from (
				select
			a00d.createdby,
			to_char( a00d.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00d.updatedby,
			to_char( a00d.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00d.ClusId as ClusId,
			a00d.SecGrpFrmId as SecGrpFrmId,
			a00d.SecGrpId as SecGrpId,
			a00d.SecAppId as SecAppId,
			a00d.SecFrmId as SecFrmId,
					a00d.revision as revision
				from cfsec213.SecGrpFrm a00d
				where
					a00d.ClusId = argClusId
			and a00d.SecAppId = argSecAppId
		order by ClusId desc,
			SecGrpFrmId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 0 ) and ( ( priorClusterId is not null )and ( priorSecGroupFormId is not null ) ) )
	then
		open retCursor for
			select * from (
				select
			a00d.createdby,
			to_char( a00d.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00d.updatedby,
			to_char( a00d.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00d.ClusId as ClusId,
			a00d.SecGrpFrmId as SecGrpFrmId,
			a00d.SecGrpId as SecGrpId,
			a00d.SecAppId as SecAppId,
			a00d.SecFrmId as SecFrmId,
					a00d.revision as revision
				from cfsec213.SecGrpFrm a00d
				where
					a00d.ClusId = argClusId
			and a00d.SecAppId = argSecAppId
					and a00d.ClusId = secClusterId
			and ( ( ( a00d.ClusId = priorClusterId )
					and ( a00d.SecGrpFrmId < priorSecGroupFormId ) )
				or ( ( a00d.ClusId < priorClusterId ) ) )
		order by ClusId desc,
			SecGrpFrmId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 0 ) and ( not ( ( priorClusterId is not null )and ( priorSecGroupFormId is not null ) ) ) )
	then
		open retCursor for
			select * from (
				select
			a00d.createdby,
			to_char( a00d.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00d.updatedby,
			to_char( a00d.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00d.ClusId as ClusId,
			a00d.SecGrpFrmId as SecGrpFrmId,
			a00d.SecGrpId as SecGrpId,
			a00d.SecAppId as SecAppId,
			a00d.SecFrmId as SecFrmId,
					a00d.revision as revision
				from cfsec213.SecGrpFrm a00d
				where
					a00d.ClusId = argClusId
			and a00d.SecAppId = argSecAppId
					and a00d.ClusId = secClusterId
		order by ClusId desc,
			SecGrpFrmId desc
			) where ROWNUM <= 25;
	end if;
end pg_secgrpfrmbyappidx;
/

show errors procedure cfsec213.pg_secgrpfrmbyappidx;