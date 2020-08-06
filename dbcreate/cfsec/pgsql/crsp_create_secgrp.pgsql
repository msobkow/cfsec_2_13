--
--	@(#) dbcreate/cfsec/pgsql/crsp_create_secgrp.pgsql
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
create or replace function cfsec213.sp_create_secgrp(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argClusterId bigint,
	argName varchar(64),
	argIsVisible boolean )
returns setof cfsec213.type_secgrp_rec as $$
declare
	permissionFlag boolean;
	argSecGroupId integer;
begin
	if( argClassCode = 'a00c' )
	then
		select cfsec213.sp_is_cluster_user( argClusterId,
			'CreateSecGroup',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in cluster SecGroup for CreateSecGroup';
		end if;
	end if;

	select cfsec213.sp_next_secgroupidgen( argClusterId )
	into argSecGroupId;

	insert into cfsec213.secgrp(
		createdby,
		createdat,
		updatedby,
		updatedat,
		clusterid,
		secgroupid,
		safe_name,
		isvisible,
		revision )
	values (
		argAuditUserId,
		now(),
		argAuditUserId,
		now(),
		argClusterId,
		argSecGroupId,
		argName,
		argIsVisible,
		1 );
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
			a00c.revision,
			0
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
