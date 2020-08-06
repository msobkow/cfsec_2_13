--
--	@(#) dbcreate/cfsec/pgsql/crsp_page_tsecmemb_by_groupidx.pgsql
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
create or replace function cfsec213.sp_page_tsecmemb_by_groupidx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argTenantId bigint,
	argTSecGroupId integer,
	priorTenantId bigint,
	priorTSecGrpMembId bigint )
returns setof cfsec213.type_tsecmemb_rec as $$
declare
	permissionFlag boolean;
	isSystemUser boolean;
begin
	select cfsec213.sp_is_tenant_user( secTenantId,
			'ReadTSecGrpMemb',
			argAuditUserId ),
		cfsec213.sp_is_system_user( argAuditUserId )
	into permissionFlag, isSystemUser;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in tenant TSecGroup for ReadTSecGrpMemb';
	end if;
	if( isSystemUser )
	then
		if( ( priorTenantId is not null )and ( priorTSecGrpMembId is not null ) )
		then
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
			and a018.tsecgroupid = argTSecGroupId
			and ( ( ( a018.TenantId = priorTenantId )
					and ( a018.TSecGrpMembId < priorTSecGrpMembId ) )
				or ( ( a018.TenantId < priorTenantId ) ) )
				order by TenantId desc,
					TSecGrpMembId desc
			limit 25;
		else
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
			and a018.tsecgroupid = argTSecGroupId
				order by TenantId desc,
					TSecGrpMembId desc
			limit 25;
		end if;
	else
		if( ( priorTenantId is not null )and ( priorTSecGrpMembId is not null ) )
		then
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
			and a018.tsecgroupid = argTSecGroupId
				and a018.TenantId = secTenantId
			and ( ( ( a018.TenantId = priorTenantId )
					and ( a018.TSecGrpMembId < priorTSecGrpMembId ) )
				or ( ( a018.TenantId < priorTenantId ) ) )
				order by TenantId desc,
					TSecGrpMembId desc
			limit 25;
		else
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
			and a018.tsecgroupid = argTSecGroupId
				and a018.TenantId = secTenantId
				order by TenantId desc,
					TSecGrpMembId desc
			limit 25;
		end if;
	end if;
	return;
end
$$ language plpgsql;
