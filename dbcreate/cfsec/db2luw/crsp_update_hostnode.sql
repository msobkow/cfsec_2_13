--
--	@(#) dbcreate/cfsec/db2luw/crsp_update_hostnode.sql
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

create or replace procedure sp_update_hostnode(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argClusterId bigint,	\
	in argHostNodeId bigint,	\
	in argDescription varchar(255),	\
	in argHostName varchar(192),	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldClusterId bigint;	\
	declare oldHostNodeId bigint;	\
	declare oldDescription varchar(255);	\
	declare oldHostName varchar(192);	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select	\
				a002.createdby as createdby,	\
				to_char( a002.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a002.updatedby as updatedby,	\
				to_char( a002.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a002.clusterid as clusterid,	\
			a002.hostnodeid as hostnodeid,	\
			a002.description as description,	\
			a002.hostname as hostname,	\
			a002.revision as revision	\
		from cfsec213.HostNode as a002	\
		where	\
			a002.clusterid = argClusterId	\
		and a002.hostnodeid = argHostNodeId;	\
	begin	\
		if( argClassCode = 'a002' )	\
		then	\
			set( permissionFlag ) = ( sp_is_cluster_user( argClusterId,	\
					'UpdateHostNode',	\
					argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for UpdateHostNode' );	\
			end if;	\
		end if;	\
	\
		select	\
			ClusterId,	\
			HostNodeId,	\
			Description,	\
			HostName,	\
			revision	\
		into	\
			oldClusterId,	\
			oldHostNodeId,	\
			oldDescription,	\
			oldHostName,	\
			oldRevision	\
		from cfsec213.HostNode	\
		where	\
			ClusterId = argClusterId	\
			and HostNodeId = argHostNodeId	\
		for update;	\
	\
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_hostnode() Data collision detected' );	\
		end if;	\
	\
		update cfsec213.HostNode	\
		set	\
			revision = argRevision + 1,	\
			updatedby = argAuditUserId,	\
			updatedat = current timestamp,	\
			description = argDescription,	\
			hostname = argHostName	\
		where	\
			clusterid = argClusterId	\
		and hostnodeid = argHostNodeId	\
		and revision = argRevision;	\
	\
		insert into cfsec213.HostNode_h (	\
				clusterid,	\
				hostnodeid,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				description,	\
				hostname,	\
			revision,	\
			auditaction )	\
		select	\
				a002.clusterid,	\
				a002.hostnodeid,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a002.description,	\
				a002.hostname,	\
			a002.revision,	\
			2	\
		from cfsec213.HostNode as a002	\
		where	\
			a002.clusterid = argClusterId	\
		and a002.hostnodeid = argHostNodeId;	\
	\
		open retcursor;	\
	end;	\
end
