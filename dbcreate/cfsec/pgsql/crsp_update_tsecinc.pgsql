--
--	@(#) dbcreate/cfsec/pgsql/crsp_update_tsecinc.pgsql
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

create or replace function cfsec213.sp_update_tsecinc(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argTenantId bigint,
	argTSecGrpIncId bigint,
	argTSecGroupId integer,
	argIncludeGroupId integer,
	argRevision integer )
returns setof cfsec213.type_tsecinc_rec as $$
declare
	RowsAffected integer;
	oldTenantId bigint;
	oldTSecGrpIncId bigint;
	oldTSecGroupId integer;
	oldIncludeGroupId integer;
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a017' )
	then
		select cfsec213.sp_is_tenant_user( argTenantId,
			'UpdateTSecGrpInc',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in tenant TSecGroup for UpdateTSecGrpInc';
		end if;
	end if;

		select
			TenantId,
			TSecGrpIncId,
			TSecGrpId,
			IncGrpId,
			revision
		into
			oldTenantId,
			oldTSecGrpIncId,
			oldTSecGroupId,
			oldIncludeGroupId,
			oldRevision
		from cfsec213.TSecInc
		where
			TenantId = argTenantId
			and TSecGrpIncId = argTSecGrpIncId
		for update;


	if argRevision != oldRevision
	then
		raise exception 'sp_update_tsecinc() Data collision detected';
	end if;


	update cfsec213.TSecInc
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		tsecgrpid = argTSecGroupId,
		incgrpid = argIncludeGroupId
	where
		TenantId = argTenantId
			and TSecGrpIncId = argTSecGrpIncId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_tsecinc() Expected to affect one TSecInc row, not %', RowsAffected;
	end if;


	insert into cfsec213.TSecInc_h (
			TenantId,
			TSecGrpIncId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			TSecGrpId,
			IncGrpId,
			revision,
			auditaction )
		select
			a017.TenantId,
			a017.TSecGrpIncId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a017.TSecGrpId,
			a017.IncGrpId,
			argRevision + 1,
			1
		from cfsec213.TSecInc as a017
		where
			a017.tenantid = argTenantId
			and a017.tsecgrpincid = argTSecGrpIncId;
	return query select
			a017.createdby,
			to_char( a017.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a017.updatedby,
			to_char( a017.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a017.tenantid as tenantid,
			a017.tsecgrpincid as tsecgrpincid,
			a017.tsecgrpid as tsecgrpid,
			a017.incgrpid as incgrpid,
		a017.revision as revision
	from cfsec213.TSecInc as a017
	where
		a017.tenantid = argTenantId
			and a017.tsecgrpincid = argTSecGrpIncId;

	return;
end;
$$ language plpgsql;
