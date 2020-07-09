--
--	@(#) dbcreate/cfsec/pgsql/crsp_create_tsecmemb.pgsql
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
create or replace function cfsec213.sp_create_tsecmemb(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argTenantId bigint,
	argTSecGroupId integer,
	argSecUserId varchar(36) )
returns setof cfsec213.type_tsecmemb_rec as $$
declare
	permissionFlag boolean;
	argTSecGrpMembId bigint;
begin
	if( argClassCode = 'a018' )
	then
		select cfsec213.sp_is_tenant_user( argTenantId,
			'CreateTSecGrpMemb',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in tenant TSecGroup for CreateTSecGrpMemb';
		end if;
	end if;

	select cfsec213.sp_next_tsecgrpmembidgen( argTenantId )
	into argTSecGrpMembId;

	insert into cfsec213.tsecmemb(
		createdby,
		createdat,
		updatedby,
		updatedat,
		tenantid,
		tsecgrpmembid,
		tsecgroupid,
		secuserid,
		revision )
	values (
		argAuditUserId,
		now(),
		argAuditUserId,
		now(),
		argTenantId,
		argTSecGrpMembId,
		argTSecGroupId,
		argSecUserId,
		1 );
	insert into cfsec213.TSecMemb_h (
			TenantId,
			TSecGrpMembId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			TSecGroupId,
			SecUserId,
			revision,
			auditaction )
		select
			a018.TenantId,
			a018.TSecGrpMembId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a018.TSecGroupId,
			a018.SecUserId,
			a018.revision,
			0
		from cfsec213.TSecMemb as a018
		where
			a018.tenantid = argTenantId
			and a018.tsecgrpmembid = argTSecGrpMembId;

	return query select
			a018.createdby,
			to_char( a018.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a018.updatedby,
			to_char( a018.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a018.tenantid as tenantid,
			a018.tsecgrpmembid as tsecgrpmembid,
			a018.tsecgroupid as tsecgroupid,
			a018.secuserid as secuserid,
			a018.revision as revision
	from cfsec213.TSecMemb as a018
	where
			a018.tenantid = argTenantId
			and a018.tsecgrpmembid = argTSecGrpMembId;

	return;
end;
$$ language plpgsql;
