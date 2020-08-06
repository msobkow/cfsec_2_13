--
--	@(#) dbcreate/cfsec/pgsql/crsp_create_tsecgrp.pgsql
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
create or replace function cfsec213.sp_create_tsecgrp(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argTenantId bigint,
	argName varchar(64),
	argIsVisible boolean )
returns setof cfsec213.type_tsecgrp_rec as $$
declare
	permissionFlag boolean;
	argTSecGroupId integer;
begin
	if( argClassCode = 'a016' )
	then
		select cfsec213.sp_is_tenant_user( argTenantId,
			'CreateTSecGroup',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in tenant TSecGroup for CreateTSecGroup';
		end if;
	end if;

	select cfsec213.sp_next_tsecgroupidgen( argTenantId )
	into argTSecGroupId;

	insert into cfsec213.tsecgrp(
		createdby,
		createdat,
		updatedby,
		updatedat,
		tenantid,
		tsecgroupid,
		safe_name,
		isvisible,
		revision )
	values (
		argAuditUserId,
		now(),
		argAuditUserId,
		now(),
		argTenantId,
		argTSecGroupId,
		argName,
		argIsVisible,
		1 );
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
			a016.revision,
			0
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
