--
--	@(#) dbcreate/cfsec/pgsql/crsp_update_secinc.pgsql
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

create or replace function cfsec213.sp_update_secinc(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argClusterId bigint,
	argSecGrpIncId bigint,
	argSecGroupId integer,
	argIncludeGroupId integer,
	argRevision integer )
returns setof cfsec213.type_secinc_rec as $$
declare
	RowsAffected integer;
	oldClusterId bigint;
	oldSecGrpIncId bigint;
	oldSecGroupId integer;
	oldIncludeGroupId integer;
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a00e' )
	then
		select cfsec213.sp_is_cluster_user( argClusterId,
			'UpdateSecGrpInc',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in cluster SecGroup for UpdateSecGrpInc';
		end if;
	end if;

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


	if argRevision != oldRevision
	then
		raise exception 'sp_update_secinc() Data collision detected';
	end if;


	update cfsec213.SecInc
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		secgrpid = argSecGroupId,
		incgrpid = argIncludeGroupId
	where
		ClusId = argClusterId
			and SecGrpIncId = argSecGrpIncId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_secinc() Expected to affect one SecInc row, not %', RowsAffected;
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
			1
		from cfsec213.SecInc as a00e
		where
			a00e.clusid = argClusterId
			and a00e.secgrpincid = argSecGrpIncId;
	return query select
			a00e.createdby,
			to_char( a00e.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00e.updatedby,
			to_char( a00e.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00e.clusid as clusid,
			a00e.secgrpincid as secgrpincid,
			a00e.secgrpid as secgrpid,
			a00e.incgrpid as incgrpid,
		a00e.revision as revision
	from cfsec213.SecInc as a00e
	where
		a00e.clusid = argClusterId
			and a00e.secgrpincid = argSecGrpIncId;

	return;
end;
$$ language plpgsql;
