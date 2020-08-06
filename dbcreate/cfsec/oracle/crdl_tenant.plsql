--
--	@(#) dbcreate/cfsec/oracle/crdl_tenant.plsql
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
alter session set plsql_warnings = 'ENABLE:ALL';
/

create or replace procedure cfsec213.dl_tenant(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argId numeric,
	argRevision int ) authid definer
is
	use_stamp cfsec213.tenant_h.auditstamp%type;
	oldClusterId numeric(22,0);
	oldId numeric(22,0);
	oldTenantName varchar2(192);
	oldRevision integer;
	cursor cursDelIncludedByGroup is
		select
			a017.TenantId,
			a017.TSecGrpIncId
		from cfsec213.tenant a015
			inner join cfsec213.tsecgrp a016 on
				a015.Id = a016.TenantId
			inner join cfsec213.tsecinc a017 on
				a016.TenantId = a017.TenantId
				and a016.TSecGroupId = a017.IncGrpId
		where
			a015.Id = argId;
	cursor cursDelGrpMembs is
		select
			a018.TenantId,
			a018.TSecGrpMembId
		from cfsec213.tenant a015
			inner join cfsec213.tsecgrp a016 on
				a015.Id = a016.TenantId
			inner join cfsec213.tsecmemb a018 on
				a016.TenantId = a018.TenantId
				and a016.TSecGroupId = a018.TSecGroupId
		where
			a015.Id = argId;
	cursor cursDelGrpIncs is
		select
			a017.TenantId,
			a017.TSecGrpIncId
		from cfsec213.tenant a015
			inner join cfsec213.tsecgrp a016 on
				a015.Id = a016.TenantId
			inner join cfsec213.tsecinc a017 on
				a016.TenantId = a017.TenantId
				and a016.TSecGroupId = a017.TSecGrpId
		where
			a015.Id = argId;
	cursor cursDelTSecGroups is
		select
			a016.TenantId,
			a016.TSecGroupId
		from cfsec213.tenant a015
			inner join cfsec213.tsecgrp a016 on
				a015.Id = a016.TenantId
		where
			a015.Id = argId;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
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

	permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;

	insert into cfsec213.tenant_h (
			Id,
			revision,
			auditclusterid,
			auditsessionid,
			ClusterId,
			TenantName,
			auditaction,
			auditstamp )
		select
			a015.Id as Id,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a015.ClusterId as ClusterId,
			a015.TenantName as TenantName,
			2,
			use_stamp
		from cfsec213.tenant a015
		where
			a015.Id = argId;

	for cur in cursDelIncludedByGroup
	loop
		cfsec213.dl_tsecincbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.TenantId,
				cur.TSecGrpIncId );
	end loop;
	for cur in cursDelGrpMembs
	loop
		cfsec213.dl_tsecmembbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.TenantId,
				cur.TSecGrpMembId );
	end loop;
	for cur in cursDelGrpIncs
	loop
		cfsec213.dl_tsecincbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.TenantId,
				cur.TSecGrpIncId );
	end loop;
	for cur in cursDelTSecGroups
	loop
		cfsec213.dl_tsecgrpbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.TenantId,
				cur.TSecGroupId );
	end loop;
	delete from cfsec213.tenant
	where
		Id = argId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_tenant;
/

show errors procedure cfsec213.dl_tenant;
