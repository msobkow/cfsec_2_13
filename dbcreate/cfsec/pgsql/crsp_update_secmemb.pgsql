--
--	@(#) dbcreate/cfsec/pgsql/crsp_update_secmemb.pgsql
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

create or replace function cfsec213.sp_update_secmemb(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argClusterId bigint,
	argSecGrpMembId bigint,
	argSecGroupId integer,
	argSecUserId varchar(36),
	argRevision integer )
returns setof cfsec213.type_secmemb_rec as $$
declare
	RowsAffected integer;
	oldClusterId bigint;
	oldSecGrpMembId bigint;
	oldSecGroupId integer;
	oldSecUserId varchar(36);
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a00f' )
	then
		select cfsec213.sp_is_cluster_user( argClusterId,
			'UpdateSecGrpMemb',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in cluster SecGroup for UpdateSecGrpMemb';
		end if;
	end if;

		select
			ClusterId,
			SecGrpMembId,
			SecGroupId,
			SecUserId,
			revision
		into
			oldClusterId,
			oldSecGrpMembId,
			oldSecGroupId,
			oldSecUserId,
			oldRevision
		from cfsec213.SecMemb
		where
			ClusterId = argClusterId
			and SecGrpMembId = argSecGrpMembId
		for update;


	if argRevision != oldRevision
	then
		raise exception 'sp_update_secmemb() Data collision detected';
	end if;


	update cfsec213.SecMemb
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		secgroupid = argSecGroupId,
		secuserid = argSecUserId
	where
		ClusterId = argClusterId
			and SecGrpMembId = argSecGrpMembId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_secmemb() Expected to affect one SecMemb row, not %', RowsAffected;
	end if;


	insert into cfsec213.SecMemb_h (
			ClusterId,
			SecGrpMembId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			SecGroupId,
			SecUserId,
			revision,
			auditaction )
		select
			a00f.ClusterId,
			a00f.SecGrpMembId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a00f.SecGroupId,
			a00f.SecUserId,
			argRevision + 1,
			1
		from cfsec213.SecMemb as a00f
		where
			a00f.clusterid = argClusterId
			and a00f.secgrpmembid = argSecGrpMembId;
	return query select
			a00f.createdby,
			to_char( a00f.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00f.updatedby,
			to_char( a00f.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00f.clusterid as clusterid,
			a00f.secgrpmembid as secgrpmembid,
			a00f.secgroupid as secgroupid,
			a00f.secuserid as secuserid,
		a00f.revision as revision
	from cfsec213.SecMemb as a00f
	where
		a00f.clusterid = argClusterId
			and a00f.secgrpmembid = argSecGrpMembId;

	return;
end;
$$ language plpgsql;
