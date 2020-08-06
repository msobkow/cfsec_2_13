--
--	@(#) dbcreate/cfsec/pgsql/crsp_delete_secgrp.pgsql
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
create or replace function cfsec213.sp_delete_secgrp(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClusterId bigint,
	argSecGroupId integer,
	argRevision int )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
	oldClusterId bigint;
	oldSecGroupId integer;
	oldName varchar(64);
	oldIsVisible boolean;
	oldRevision int;
	permissionFlag boolean;
begin
		select
			ClusterId,
			SecGroupId,
			safe_name,
			IsVisible,
			revision
		into
			oldClusterId,
			oldSecGroupId,
			oldName,
			oldIsVisible,
			oldRevision
		from cfsec213.SecGrp
		where
			ClusterId = argClusterId
			and SecGroupId = argSecGroupId
		for update;

	if( oldClusterId != secClusterId )
	then
		select cfsec213.sp_is_system_user( argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- Data is not owned by logged in cluster';
		end if;
	end if;

	select cfsec213.sp_is_cluster_user( oldClusterId,
		'DeleteSecGroup',
		argAuditUserId )
	into permissionFlag;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in cluster SecGroup for DeleteSecGroup';
	end if;

	insert into cfsec213.SecGrp_h (
			ClusterId,
			SecGroupId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			safe_name,
			IsVisible,
			revision,
			auditaction )
		select
			a00c.ClusterId,
			a00c.SecGroupId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a00c.safe_name,
			a00c.IsVisible,
			argRevision + 1,
			2
		from cfsec213.SecGrp as a00c
		where
			a00c.clusterid = argClusterId
			and a00c.secgroupid = argSecGroupId;

	for cur in
		select
			a00d.ClusId,
			a00d.SecGrpFrmId
		from cfsec213.SecGrp as a00c
			inner join cfsec213.secgrpfrm a00d on 
				a00c.ClusterId = a00d.ClusId
				and a00c.SecGroupId = a00d.SecGrpId
		where
			a00c.ClusterId = argClusterId
			and a00c.SecGroupId = argSecGroupId
	loop
		select cfsec213.sp_delete_secgrpfrm_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.SecGroupFormId )
			into subret;
	end loop;

	for cur in
		select
			a00e.ClusId,
			a00e.SecGrpIncId
		from cfsec213.SecGrp as a00c
			inner join cfsec213.secinc a00e on 
				a00c.ClusterId = a00e.ClusId
				and a00c.SecGroupId = a00e.IncGrpId
		where
			a00c.ClusterId = argClusterId
			and a00c.SecGroupId = argSecGroupId
	loop
		select cfsec213.sp_delete_secinc_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.SecGrpIncId )
			into subret;
	end loop;

	for cur in
		select
			a00f.ClusterId,
			a00f.SecGrpMembId
		from cfsec213.SecGrp as a00c
			inner join cfsec213.secmemb a00f on 
				a00c.ClusterId = a00f.ClusterId
				and a00c.SecGroupId = a00f.SecGroupId
		where
			a00c.ClusterId = argClusterId
			and a00c.SecGroupId = argSecGroupId
	loop
		select cfsec213.sp_delete_secmemb_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.SecGrpMembId )
			into subret;
	end loop;

	for cur in
		select
			a00e.ClusId,
			a00e.SecGrpIncId
		from cfsec213.SecGrp as a00c
			inner join cfsec213.secinc a00e on 
				a00c.ClusterId = a00e.ClusId
				and a00c.SecGroupId = a00e.SecGrpId
		where
			a00c.ClusterId = argClusterId
			and a00c.SecGroupId = argSecGroupId
	loop
		select cfsec213.sp_delete_secinc_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.SecGrpIncId )
			into subret;
	end loop;


	delete from cfsec213.SecGrp
	where
		clusterid = argClusterId
		and secgroupid = argSecGroupId;

	get diagnostics RowsAffected = row_count;
	if RowsAffected != 1 and RowsAffected != 0
	then
		raise exception 'sp_delete_secgrp() Expected to affect 1 SecGrp, not %', RowsAffected;
	end if;

	return true;
end;
$$ language plpgsql;
