--
--	@(#) dbcreate/cfsec/pgsql/crsp_update_tsecmemb.pgsql
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

create or replace function cfsec213.sp_update_tsecmemb(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argTenantId bigint,
	argTSecGrpMembId bigint,
	argTSecGroupId integer,
	argSecUserId varchar(36),
	argRevision integer )
returns setof cfsec213.type_tsecmemb_rec as $$
declare
	RowsAffected integer;
	oldTenantId bigint;
	oldTSecGrpMembId bigint;
	oldTSecGroupId integer;
	oldSecUserId varchar(36);
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a018' )
	then
		select cfsec213.sp_is_tenant_user( argTenantId,
			'UpdateTSecGrpMemb',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in tenant TSecGroup for UpdateTSecGrpMemb';
		end if;
	end if;

		select
			TenantId,
			TSecGrpMembId,
			TSecGroupId,
			SecUserId,
			revision
		into
			oldTenantId,
			oldTSecGrpMembId,
			oldTSecGroupId,
			oldSecUserId,
			oldRevision
		from cfsec213.TSecMemb
		where
			TenantId = argTenantId
			and TSecGrpMembId = argTSecGrpMembId
		for update;


	if argRevision != oldRevision
	then
		raise exception 'sp_update_tsecmemb() Data collision detected';
	end if;


	update cfsec213.TSecMemb
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		tsecgroupid = argTSecGroupId,
		secuserid = argSecUserId
	where
		TenantId = argTenantId
			and TSecGrpMembId = argTSecGrpMembId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_tsecmemb() Expected to affect one TSecMemb row, not %', RowsAffected;
	end if;


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
			argRevision + 1,
			1
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
