--
--	@(#) dbcreate/cfsec/pgsql/crsp_create_hostnode.pgsql
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
create or replace function cfsec213.sp_create_hostnode(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argClusterId bigint,
	argDescription varchar(255),
	argHostName varchar(192) )
returns setof cfsec213.type_hostnode_rec as $$
declare
	permissionFlag boolean;
	argHostNodeId bigint;
begin
	if( argClassCode = 'a002' )
	then
		select cfsec213.sp_is_cluster_user( argClusterId,
			'CreateHostNode',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in cluster SecGroup for CreateHostNode';
		end if;
	end if;

	select cfsec213.sp_next_hostnodeidgen( argClusterId )
	into argHostNodeId;

	insert into cfsec213.hostnode(
		createdby,
		createdat,
		updatedby,
		updatedat,
		clusterid,
		hostnodeid,
		description,
		hostname,
		revision )
	values (
		argAuditUserId,
		now(),
		argAuditUserId,
		now(),
		argClusterId,
		argHostNodeId,
		argDescription,
		argHostName,
		1 );
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
			a002.revision,
			0
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
