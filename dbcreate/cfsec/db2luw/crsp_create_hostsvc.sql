--
--	@(#) dbcreate/cfsec/db2luw/crsp_create_hostsvc.sql
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
create or replace procedure sp_create_hostsvc(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argClusterId bigint,	\
	in argHostNodeId bigint,	\
	in argServiceTypeId integer,	\
	in argHostPort smallint )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
		declare argServiceId bigint;	\
	declare retcursor cursor with return to client for	\
		select	\
				a012.createdby as createdby,	\
				to_char( a012.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a012.updatedby as updatedby,	\
				to_char( a012.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a012.clusterid as clusterid,	\
			a012.serviceid as serviceid,	\
			a012.hostnodeid as hostnodeid,	\
			a012.servicetypeid as servicetypeid,	\
			a012.hostport as hostport,	\
			a012.revision as revision	\
		from cfsec213.HostSvc as a012	\
		where	\
			a012.clusterid = argClusterId	\
		and a012.serviceid = argServiceId;	\
	begin	\
		if( argClassCode = 'a012' )	\
		then	\
			set( permissionFlag ) = ( sp_is_cluster_user( argClusterId,	\
					'CreateService',	\
					argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for CreateService' );	\
			end if;	\
		end if;	\
	\
		call sp_next_serviceidgen( argClusterId,	\
			argServiceId );	\
		insert into cfsec213.hostsvc(	\
			createdby,	\
			createdat,	\
			updatedby,	\
			updatedat,	\
			clusterid,	\
			serviceid,	\
			hostnodeid,	\
			servicetypeid,	\
			hostport,	\
			revision )	\
		values (	\
			argAuditUserId,	\
			current timestamp,	\
			argAuditUserId,	\
			current timestamp,	\
			argClusterId,	\
			argServiceId,	\
			argHostNodeId,	\
			argServiceTypeId,	\
			argHostPort,	\
			1 );	\
	\
		insert into cfsec213.hostsvc_h (	\
				clusterid,	\
				serviceid,	\
				auditclusterid,	\
				auditsessionid,	\
				auditstamp,	\
				hostnodeid,	\
				servicetypeid,	\
				hostport,	\
				revision,	\
				auditaction )	\
		select	\
				a012.clusterid,	\
				a012.serviceid,	\
				argAuditClusterId,	\
				argAuditSessionId,	\
				current timestamp,	\
				a012.hostnodeid,	\
				a012.servicetypeid,	\
				a012.hostport,	\
				a012.revision,	\
				0	\
		from cfsec213.HostSvc as a012	\
		where	\
				a012.clusterid = argClusterId	\
		and a012.serviceid = argServiceId;	\
	\
		open retcursor;	\
	end;	\
end
