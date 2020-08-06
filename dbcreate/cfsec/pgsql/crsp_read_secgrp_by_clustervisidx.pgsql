--
--	@(#) dbcreate/cfsec/pgsql/crsp_read_secgrp_by_clustervisidx.pgsql
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
create or replace function cfsec213.sp_read_secgrp_by_clustervisidx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClusterId bigint,
	argIsVisible boolean )
returns setof cfsec213.type_secgrp_rec as $$
declare
	permissionFlag boolean;
	isSystemUser boolean;
begin
	select cfsec213.sp_is_cluster_user( secClusterId,
			'ReadSecGroup',
			argAuditUserId ),
		cfsec213.sp_is_system_user( argAuditUserId )
	into permissionFlag, isSystemUser;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in cluster SecGroup for ReadSecGroup';
	end if;
	if( isSystemUser )
	then
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
			and a00c.isvisible = argIsVisible
				order by ClusterId desc,
					SecGroupId desc;
	else
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
			and a00c.isvisible = argIsVisible
			and a00c.ClusterId = secClusterId
				order by ClusterId desc,
					SecGroupId desc;
	end if;
	return;
end
$$ language plpgsql;
