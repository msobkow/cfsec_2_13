--
--	@(#) dbcreate/cfsec/pgsql/crsp_delete_hostnode.pgsql
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
create or replace function cfsec213.sp_delete_hostnode(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClusterId bigint,
	argHostNodeId bigint,
	argRevision int )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
	oldClusterId bigint;
	oldHostNodeId bigint;
	oldDescription varchar(255);
	oldHostName varchar(192);
	oldRevision int;
	permissionFlag boolean;
begin
		select
			ClusterId,
			HostNodeId,
			Description,
			HostName,
			revision
		into
			oldClusterId,
			oldHostNodeId,
			oldDescription,
			oldHostName,
			oldRevision
		from cfsec213.HostNode
		where
			ClusterId = argClusterId
			and HostNodeId = argHostNodeId
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
		'DeleteHostNode',
		argAuditUserId )
	into permissionFlag;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in cluster SecGroup for DeleteHostNode';
	end if;

	insert into cfsec213.HostNode_h (
			ClusterId,
			HostNodeId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			Description,
			HostName,
			revision,
			auditaction )
		select
			a002.ClusterId,
			a002.HostNodeId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a002.Description,
			a002.HostName,
			argRevision + 1,
			2
		from cfsec213.HostNode as a002
		where
			a002.clusterid = argClusterId
			and a002.hostnodeid = argHostNodeId;

	for cur in
		select
			a012.ClusterId,
			a012.ServiceId
		from cfsec213.HostNode as a002
			inner join cfsec213.hostsvc a012 on 
				a002.ClusterId = a012.ClusterId
				and a002.HostNodeId = a012.HostNodeId
		where
			a002.ClusterId = argClusterId
			and a002.HostNodeId = argHostNodeId
	loop
		select cfsec213.sp_delete_hostsvc_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.ServiceId )
			into subret;
	end loop;


	delete from cfsec213.HostNode
	where
		clusterid = argClusterId
		and hostnodeid = argHostNodeId;

	get diagnostics RowsAffected = row_count;
	if RowsAffected != 1 and RowsAffected != 0
	then
		raise exception 'sp_delete_hostnode() Expected to affect 1 HostNode, not %', RowsAffected;
	end if;

	return true;
end;
$$ language plpgsql;
