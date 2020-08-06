--
--	@(#) dbcreate/cfsec/pgsql/crsp_create_tsecinc.pgsql
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
create or replace function cfsec213.sp_create_tsecinc(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argTenantId bigint,
	argTSecGroupId integer,
	argIncludeGroupId integer )
returns setof cfsec213.type_tsecinc_rec as $$
declare
	permissionFlag boolean;
	argTSecGrpIncId bigint;
begin
	if( argClassCode = 'a017' )
	then
		select cfsec213.sp_is_tenant_user( argTenantId,
			'CreateTSecGrpInc',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in tenant TSecGroup for CreateTSecGrpInc';
		end if;
	end if;

	select cfsec213.sp_next_tsecgrpincidgen( argTenantId )
	into argTSecGrpIncId;

	insert into cfsec213.tsecinc(
		createdby,
		createdat,
		updatedby,
		updatedat,
		tenantid,
		tsecgrpincid,
		tsecgrpid,
		incgrpid,
		revision )
	values (
		argAuditUserId,
		now(),
		argAuditUserId,
		now(),
		argTenantId,
		argTSecGrpIncId,
		argTSecGroupId,
		argIncludeGroupId,
		1 );
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
			a017.revision,
			0
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
