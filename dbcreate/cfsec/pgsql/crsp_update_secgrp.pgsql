--
--	@(#) dbcreate/cfsec/pgsql/crsp_update_secgrp.pgsql
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

create or replace function cfsec213.sp_update_secgrp(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argClusterId bigint,
	argSecGroupId integer,
	argName varchar(64),
	argIsVisible boolean,
	argRevision integer )
returns setof cfsec213.type_secgrp_rec as $$
declare
	RowsAffected integer;
	oldClusterId bigint;
	oldSecGroupId integer;
	oldName varchar(64);
	oldIsVisible boolean;
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a00c' )
	then
		select cfsec213.sp_is_cluster_user( argClusterId,
			'UpdateSecGroup',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in cluster SecGroup for UpdateSecGroup';
		end if;
	end if;

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


	if argRevision != oldRevision
	then
		raise exception 'sp_update_secgrp() Data collision detected';
	end if;


	update cfsec213.SecGrp
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		safe_name = argName,
		isvisible = argIsVisible
	where
		ClusterId = argClusterId
			and SecGroupId = argSecGroupId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_secgrp() Expected to affect one SecGrp row, not %', RowsAffected;
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
			1
		from cfsec213.SecGrp as a00c
		where
			a00c.clusterid = argClusterId
			and a00c.secgroupid = argSecGroupId;
	return query select
			a00c.createdby,
			to_char( a00c.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00c.updatedby,
			to_char( a00c.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00c.clusterid as clusterid,
			a00c.secgroupid as secgroupid,
			a00c.safe_name as safe_name,
			a00c.isvisible as isvisible,
		a00c.revision as revision
	from cfsec213.SecGrp as a00c
	where
		a00c.clusterid = argClusterId
			and a00c.secgroupid = argSecGroupId;

	return;
end;
$$ language plpgsql;
