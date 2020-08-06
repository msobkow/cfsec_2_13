--
--	@(#) dbcreate/cfsec/pgsql/crsp_delete_tsecinc.pgsql
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
create or replace function cfsec213.sp_delete_tsecinc(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argTenantId bigint,
	argTSecGrpIncId bigint,
	argRevision int )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
	oldTenantId bigint;
	oldTSecGrpIncId bigint;
	oldTSecGroupId integer;
	oldIncludeGroupId integer;
	oldRevision int;
	permissionFlag boolean;
begin
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
		'DeleteTSecGrpInc',
		argAuditUserId )
	into permissionFlag;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in tenant TSecGroup for DeleteTSecGrpInc';
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
			2
		from cfsec213.TSecInc as a017
		where
			a017.tenantid = argTenantId
			and a017.tsecgrpincid = argTSecGrpIncId;


	delete from cfsec213.TSecInc
	where
		tenantid = argTenantId
		and tsecgrpincid = argTSecGrpIncId;

	get diagnostics RowsAffected = row_count;
	if RowsAffected != 1 and RowsAffected != 0
	then
		raise exception 'sp_delete_tsecinc() Expected to affect 1 TSecInc, not %', RowsAffected;
	end if;

	return true;
end;
$$ language plpgsql;
