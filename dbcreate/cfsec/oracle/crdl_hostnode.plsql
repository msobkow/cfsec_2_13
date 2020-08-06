--
--	@(#) dbcreate/cfsec/oracle/crdl_hostnode.plsql
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

create or replace procedure cfsec213.dl_hostnode(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClusterId numeric,
	argHostNodeId numeric,
	argRevision int ) authid definer
is
	use_stamp cfsec213.HostNode_h.auditstamp%type;
	oldClusterId numeric(22,0);
	oldHostNodeId numeric(22,0);
	oldDescription varchar2(255);
	oldHostName varchar2(192);
	oldRevision integer;
	cursor cursDelServices is
		select
			a012.ClusterId,
			a012.ServiceId
		from cfsec213.HostNode a002
			inner join cfsec213.hostsvc a012 on
				a002.ClusterId = a012.ClusterId
				and a002.HostNodeId = a012.HostNodeId
		where
			a002.ClusterId = argClusterId
			and a002.HostNodeId = argHostNodeId;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
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
		permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	permissionFlag := cfsec213.sp_is_cluster_user( oldClusterId,
		'DeleteHostNode',
		argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;

	insert into cfsec213.HostNode_h (
			ClusterId,
			HostNodeId,
			revision,
			auditclusterid,
			auditsessionid,
			Description,
			HostName,
			auditaction,
			auditstamp )
		select
			a002.ClusterId as ClusterId,
			a002.HostNodeId as HostNodeId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a002.Description as Description,
			a002.HostName as HostName,
			2,
			use_stamp
		from cfsec213.HostNode a002
		where
			a002.ClusterId = argClusterId
			and a002.HostNodeId = argHostNodeId;

	for cur in cursDelServices
	loop
		cfsec213.dl_hostsvcbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.ServiceId );
	end loop;
	delete from cfsec213.HostNode
	where
		ClusterId = argClusterId
		and HostNodeId = argHostNodeId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_hostnode;
/

show errors procedure cfsec213.dl_hostnode;
