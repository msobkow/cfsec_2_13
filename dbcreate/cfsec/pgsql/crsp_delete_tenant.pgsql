--
--	@(#) dbcreate/cfsec/pgsql/crsp_delete_tenant.pgsql
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
create or replace function cfsec213.sp_delete_tenant(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argId bigint,
	argRevision int )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
	oldClusterId bigint;
	oldId bigint;
	oldTenantName varchar(192);
	oldRevision int;
	permissionFlag boolean;
begin
		select
			ClusterId,
			Id,
			TenantName,
			revision
		into
			oldClusterId,
			oldId,
			oldTenantName,
			oldRevision
		from cfsec213.tenant
		where
			Id = argId
		for update;

	select cfsec213.sp_is_system_user( argAuditUserId ) into permissionFlag;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- only system user can delete Tenant records';
	end if;

	insert into cfsec213.tenant_h (
			Id,
			auditclusterid,
			auditsessionid,
			auditstamp,
			ClusterId,
			TenantName,
			revision,
			auditaction )
		select
			a015.Id,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a015.ClusterId,
			a015.TenantName,
			argRevision + 1,
			2
		from cfsec213.tenant as a015
		where
			a015.id = argId;

	for cur in
		select
			a017.TenantId,
			a017.TSecGrpIncId
		from cfsec213.tenant as a015
			inner join cfsec213.tsecgrp a016 on 
				a015.Id = a016.TenantId
			inner join cfsec213.tsecinc a017 on 
				a016.TenantId = a017.TenantId
				and a016.TSecGroupId = a017.IncGrpId
		where
			a015.Id = argId
	loop
		select cfsec213.sp_delete_tsecinc_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.TenantId,
				cur.TSecGrpIncId )
			into subret;
	end loop;

	for cur in
		select
			a018.TenantId,
			a018.TSecGrpMembId
		from cfsec213.tenant as a015
			inner join cfsec213.tsecgrp a016 on 
				a015.Id = a016.TenantId
			inner join cfsec213.tsecmemb a018 on 
				a016.TenantId = a018.TenantId
				and a016.TSecGroupId = a018.TSecGroupId
		where
			a015.Id = argId
	loop
		select cfsec213.sp_delete_tsecmemb_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.TenantId,
				cur.TSecGrpMembId )
			into subret;
	end loop;

	for cur in
		select
			a017.TenantId,
			a017.TSecGrpIncId
		from cfsec213.tenant as a015
			inner join cfsec213.tsecgrp a016 on 
				a015.Id = a016.TenantId
			inner join cfsec213.tsecinc a017 on 
				a016.TenantId = a017.TenantId
				and a016.TSecGroupId = a017.TSecGrpId
		where
			a015.Id = argId
	loop
		select cfsec213.sp_delete_tsecinc_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.TenantId,
				cur.TSecGrpIncId )
			into subret;
	end loop;

	for cur in
		select
			a016.TenantId,
			a016.TSecGroupId
		from cfsec213.tenant as a015
			inner join cfsec213.tsecgrp a016 on 
				a015.Id = a016.TenantId
		where
			a015.Id = argId
	loop
		select cfsec213.sp_delete_tsecgrp_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.TenantId,
				cur.TSecGroupId )
			into subret;
	end loop;


	delete from cfsec213.tenant
	where
		id = argId;

	get diagnostics RowsAffected = row_count;
	if RowsAffected != 1 and RowsAffected != 0
	then
		raise exception 'sp_delete_tenant() Expected to affect 1 tenant, not %', RowsAffected;
	end if;

	return true;
end;
$$ language plpgsql;
