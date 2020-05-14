--
--	@(#) dbcreate/cfsec/pgsql/crsp_update_tsecgrp.pgsql
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

create or replace function cfsec213.sp_update_tsecgrp(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argTenantId bigint,
	argTSecGroupId integer,
	argName varchar(64),
	argIsVisible boolean,
	argRevision integer )
returns setof cfsec213.type_tsecgrp_rec as $$
declare
	RowsAffected integer;
	oldTenantId bigint;
	oldTSecGroupId integer;
	oldName varchar(64);
	oldIsVisible boolean;
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a016' )
	then
		select cfsec213.sp_is_tenant_user( argTenantId,
			'UpdateTSecGroup',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in tenant TSecGroup for UpdateTSecGroup';
		end if;
	end if;

		select
			TenantId,
			TSecGroupId,
			safe_name,
			IsVisible,
			revision
		into
			oldTenantId,
			oldTSecGroupId,
			oldName,
			oldIsVisible,
			oldRevision
		from cfsec213.TSecGrp
		where
			TenantId = argTenantId
			and TSecGroupId = argTSecGroupId
		for update;


	if argRevision != oldRevision
	then
		raise exception 'sp_update_tsecgrp() Data collision detected';
	end if;


	update cfsec213.TSecGrp
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		safe_name = argName,
		isvisible = argIsVisible
	where
		TenantId = argTenantId
			and TSecGroupId = argTSecGroupId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_tsecgrp() Expected to affect one TSecGrp row, not %', RowsAffected;
	end if;


	insert into cfsec213.TSecGrp_h (
			TenantId,
			TSecGroupId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			safe_name,
			IsVisible,
			revision,
			auditaction )
		select
			a016.TenantId,
			a016.TSecGroupId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a016.safe_name,
			a016.IsVisible,
			argRevision + 1,
			1
		from cfsec213.TSecGrp as a016
		where
			a016.tenantid = argTenantId
			and a016.tsecgroupid = argTSecGroupId;
	return query select
			a016.createdby,
			to_char( a016.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a016.updatedby,
			to_char( a016.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a016.tenantid as tenantid,
			a016.tsecgroupid as tsecgroupid,
			a016.safe_name as safe_name,
			a016.isvisible as isvisible,
		a016.revision as revision
	from cfsec213.TSecGrp as a016
	where
		a016.tenantid = argTenantId
			and a016.tsecgroupid = argTSecGroupId;

	return;
end;
$$ language plpgsql;
