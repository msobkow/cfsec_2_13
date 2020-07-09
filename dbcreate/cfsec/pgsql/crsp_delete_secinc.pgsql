--
--	@(#) dbcreate/cfsec/pgsql/crsp_delete_secinc.pgsql
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
create or replace function cfsec213.sp_delete_secinc(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClusterId bigint,
	argSecGrpIncId bigint,
	argRevision int )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
	oldClusterId bigint;
	oldSecGrpIncId bigint;
	oldSecGroupId integer;
	oldIncludeGroupId integer;
	oldRevision int;
	permissionFlag boolean;
begin
		select
			ClusId,
			SecGrpIncId,
			SecGrpId,
			IncGrpId,
			revision
		into
			oldClusterId,
			oldSecGrpIncId,
			oldSecGroupId,
			oldIncludeGroupId,
			oldRevision
		from cfsec213.SecInc
		where
			ClusId = argClusterId
			and SecGrpIncId = argSecGrpIncId
		for update;

	if( oldClusterId != secClusterId )
	then
		select cfsec213.sp_is_system_user( argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- Data is not owned by logged in cluster';
		end if;
	end if;

	select cfsec213.sp_is_cluster_user( oldClusterId,
		'DeleteSecGrpInc',
		argAuditUserId )
	into permissionFlag;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in cluster SecGroup for DeleteSecGrpInc';
	end if;

	insert into cfsec213.SecInc_h (
			ClusId,
			SecGrpIncId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			SecGrpId,
			IncGrpId,
			revision,
			auditaction )
		select
			a00e.ClusId,
			a00e.SecGrpIncId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a00e.SecGrpId,
			a00e.IncGrpId,
			argRevision + 1,
			2
		from cfsec213.SecInc as a00e
		where
			a00e.clusid = argClusterId
			and a00e.secgrpincid = argSecGrpIncId;


	delete from cfsec213.SecInc
	where
		clusid = argClusterId
		and secgrpincid = argSecGrpIncId;

	get diagnostics RowsAffected = row_count;
	if RowsAffected != 1 and RowsAffected != 0
	then
		raise exception 'sp_delete_secinc() Expected to affect 1 SecInc, not %', RowsAffected;
	end if;

	return true;
end;
$$ language plpgsql;
