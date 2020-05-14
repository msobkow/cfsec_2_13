--
--	@(#) dbcreate/cfsec/pgsql/crsp_delete_secgrpfrm.pgsql
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
create or replace function cfsec213.sp_delete_secgrpfrm(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClusterId bigint,
	argSecGroupFormId bigint,
	argRevision int )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
	oldClusterId bigint;
	oldSecGroupFormId bigint;
	oldSecGroupId integer;
	oldSecAppId integer;
	oldSecFormId integer;
	oldRevision int;
	permissionFlag boolean;
begin
		select
			ClusId,
			SecGrpFrmId,
			SecGrpId,
			SecAppId,
			SecFrmId,
			revision
		into
			oldClusterId,
			oldSecGroupFormId,
			oldSecGroupId,
			oldSecAppId,
			oldSecFormId,
			oldRevision
		from cfsec213.SecGrpFrm
		where
			ClusId = argClusterId
			and SecGrpFrmId = argSecGroupFormId
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
		'DeleteSecGroupForm',
		argAuditUserId )
	into permissionFlag;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in cluster SecGroup for DeleteSecGroupForm';
	end if;

	insert into cfsec213.SecGrpFrm_h (
			ClusId,
			SecGrpFrmId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			SecGrpId,
			SecAppId,
			SecFrmId,
			revision,
			auditaction )
		select
			a00d.ClusId,
			a00d.SecGrpFrmId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a00d.SecGrpId,
			a00d.SecAppId,
			a00d.SecFrmId,
			argRevision + 1,
			2
		from cfsec213.SecGrpFrm as a00d
		where
			a00d.clusid = argClusterId
			and a00d.secgrpfrmid = argSecGroupFormId;


	delete from cfsec213.SecGrpFrm
	where
		clusid = argClusterId
		and secgrpfrmid = argSecGroupFormId;

	get diagnostics RowsAffected = row_count;
	if RowsAffected != 1 and RowsAffected != 0
	then
		raise exception 'sp_delete_secgrpfrm() Expected to affect 1 SecGrpFrm, not %', RowsAffected;
	end if;

	return true;
end;
$$ language plpgsql;
