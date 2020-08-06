--
--	@(#) dbcreate/cfsec/pgsql/crsp_update_hostnode.pgsql
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

create or replace function cfsec213.sp_update_hostnode(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argClusterId bigint,
	argHostNodeId bigint,
	argDescription varchar(255),
	argHostName varchar(192),
	argRevision integer )
returns setof cfsec213.type_hostnode_rec as $$
declare
	RowsAffected integer;
	oldClusterId bigint;
	oldHostNodeId bigint;
	oldDescription varchar(255);
	oldHostName varchar(192);
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a002' )
	then
		select cfsec213.sp_is_cluster_user( argClusterId,
			'UpdateHostNode',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in cluster SecGroup for UpdateHostNode';
		end if;
	end if;

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


	if argRevision != oldRevision
	then
		raise exception 'sp_update_hostnode() Data collision detected';
	end if;


	update cfsec213.HostNode
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		description = argDescription,
		hostname = argHostName
	where
		ClusterId = argClusterId
			and HostNodeId = argHostNodeId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_hostnode() Expected to affect one HostNode row, not %', RowsAffected;
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
			1
		from cfsec213.HostNode as a002
		where
			a002.clusterid = argClusterId
			and a002.hostnodeid = argHostNodeId;
	return query select
			a002.createdby,
			to_char( a002.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a002.updatedby,
			to_char( a002.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a002.clusterid as clusterid,
			a002.hostnodeid as hostnodeid,
			a002.description as description,
			a002.hostname as hostname,
		a002.revision as revision
	from cfsec213.HostNode as a002
	where
		a002.clusterid = argClusterId
			and a002.hostnodeid = argHostNodeId;

	return;
end;
$$ language plpgsql;
