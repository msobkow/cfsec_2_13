--
--	@(#) dbcreate/cfsec/oracle/crcrt_hostnode.plsql
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

create or replace procedure cfsec213.crt_hostnode(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argClusterId numeric,
	argDescription varchar2,
	argHostName varchar2 ) authid definer
is
	permissionDenied exception;
	use_stamp cfsec213.HostNode_h.auditstamp%type;
	permissionFlag integer;
	argHostNodeId numeric;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a002' )
	then
		permissionFlag := cfsec213.sp_is_cluster_user( argClusterId,
			'CreateHostNode',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	argHostNodeId := cfsec213.nxt_hostnodeidgen( argClusterId );
	insert into cfsec213.hostnode(
		createdby,
		createdat,
		updatedby,
		updatedat,
		ClusterId,
		HostNodeId,
		Description,
		HostName,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argClusterId,
		argHostNodeId,
		argDescription,
		argHostName,
		1 );
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
			a002.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a002.Description as Description,
			a002.HostName as HostName,
			0,
			use_stamp
		from cfsec213.HostNode a002
		where
			a002.ClusterId = argClusterId
			and a002.HostNodeId = argHostNodeId;

	open retCursor for select
			a002.createdby,
			to_char( a002.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a002.updatedby,
			to_char( a002.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a002.ClusterId as ClusterId,
			a002.HostNodeId as HostNodeId,
			a002.Description as Description,
			a002.HostName as HostName,
		a002.revision as revision
	from cfsec213.HostNode a002
	where
		a002.ClusterId = argClusterId
			and a002.HostNodeId = argHostNodeId;
end crt_hostnode;
/

show errors procedure cfsec213.crt_hostnode;
