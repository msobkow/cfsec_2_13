--
--	@(#) dbcreate/cfsec/pgsql/crsp_delete_tsecgrp.pgsql
--
--	org.msscf.msscf.CFSec
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	MSS Code Factory CFSec 2.13 Security Essentials
--	
--	Copyright 2020 Mark Stephen Sobkow
--	
--		This file is part of MSS Code Factory.
--	
--		MSS Code Factory is available under dual commercial license from Mark Stephen
--		Sobkow, or under the terms of the GNU General Public License, Version 3
--		or later.
--	
--	    MSS Code Factory is free software: you can redistribute it and/or modify
--	    it under the terms of the GNU General Public License as published by
--	    the Free Software Foundation, either version 3 of the License, or
--	    (at your option) any later version.
--	
--	    MSS Code Factory is distributed in the hope that it will be useful,
--	    but WITHOUT ANY WARRANTY; without even the implied warranty of
--	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--	    GNU General Public License for more details.
--	
--	    You should have received a copy of the GNU General Public License
--	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
--	
--	Donations to support MSS Code Factory can be made at
--	https://www.paypal.com/paypalme2/MarkSobkow
--	
--	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
--
--	Manufactured by MSS Code Factory 2.12
--
create or replace function cfsec213.sp_delete_tsecgrp(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argTenantId bigint,
	argTSecGroupId integer,
	argRevision int )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
	oldTenantId bigint;
	oldTSecGroupId integer;
	oldName varchar(64);
	oldIsVisible boolean;
	oldRevision int;
	permissionFlag boolean;
begin
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

	if( oldTenantId != secTenantId )
	then
		select cfsec213.sp_is_system_user( argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- Data is not owned by logged in tenant';
		end if;
	end if;

	select cfsec213.sp_is_tenant_user( oldTenantId,
		'DeleteTSecGroup',
		argAuditUserId )
	into permissionFlag;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in tenant TSecGroup for DeleteTSecGroup';
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
			2
		from cfsec213.TSecGrp as a016
		where
			a016.tenantid = argTenantId
			and a016.tsecgroupid = argTSecGroupId;

	for cur in
		select
			a017.TenantId,
			a017.TSecGrpIncId
		from cfsec213.TSecGrp as a016
			inner join cfsec213.tsecinc a017 on 
				a016.TenantId = a017.TenantId
				and a016.TSecGroupId = a017.IncGrpId
		where
			a016.TenantId = argTenantId
			and a016.TSecGroupId = argTSecGroupId
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
		from cfsec213.TSecGrp as a016
			inner join cfsec213.tsecmemb a018 on 
				a016.TenantId = a018.TenantId
				and a016.TSecGroupId = a018.TSecGroupId
		where
			a016.TenantId = argTenantId
			and a016.TSecGroupId = argTSecGroupId
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
		from cfsec213.TSecGrp as a016
			inner join cfsec213.tsecinc a017 on 
				a016.TenantId = a017.TenantId
				and a016.TSecGroupId = a017.TSecGrpId
		where
			a016.TenantId = argTenantId
			and a016.TSecGroupId = argTSecGroupId
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


	delete from cfsec213.TSecGrp
	where
		tenantid = argTenantId
		and tsecgroupid = argTSecGroupId;

	get diagnostics RowsAffected = row_count;
	if RowsAffected != 1 and RowsAffected != 0
	then
		raise exception 'sp_delete_tsecgrp() Expected to affect 1 TSecGrp, not %', RowsAffected;
	end if;

	return true;
end;
$$ language plpgsql;
