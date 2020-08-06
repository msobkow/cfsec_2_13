--
--	@(#) dbcreate/cfsec/db2luw/crsp_create_secgrp.sql
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
create or replace procedure sp_create_secgrp(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argClusterId bigint,	\
	in argName varchar(64),	\
	in argIsVisible char(1) )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
		declare argSecGroupId integer;	\
	declare retcursor cursor with return to client for	\
		select	\
				a00c.createdby as createdby,	\
				to_char( a00c.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00c.updatedby as updatedby,	\
				to_char( a00c.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00c.clusterid as clusterid,	\
			a00c.secgroupid as secgroupid,	\
			a00c.safe_name as safe_name,	\
			a00c.isvisible as isvisible,	\
			a00c.revision as revision	\
		from cfsec213.SecGrp as a00c	\
		where	\
			a00c.clusterid = argClusterId	\
		and a00c.secgroupid = argSecGroupId;	\
	begin	\
		if( argClassCode = 'a00c' )	\
		then	\
			set( permissionFlag ) = ( sp_is_cluster_user( argClusterId,	\
					'CreateSecGroup',	\
					argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for CreateSecGroup' );	\
			end if;	\
		end if;	\
	\
		call sp_next_secgroupidgen( argClusterId,	\
			argSecGroupId );	\
		insert into cfsec213.secgrp(	\
			createdby,	\
			createdat,	\
			updatedby,	\
			updatedat,	\
			clusterid,	\
			secgroupid,	\
			safe_name,	\
			isvisible,	\
			revision )	\
		values (	\
			argAuditUserId,	\
			current timestamp,	\
			argAuditUserId,	\
			current timestamp,	\
			argClusterId,	\
			argSecGroupId,	\
			argName,	\
			argIsVisible,	\
			1 );	\
	\
		insert into cfsec213.secgrp_h (	\
				clusterid,	\
				secgroupid,	\
				auditclusterid,	\
				auditsessionid,	\
				auditstamp,	\
				safe_name,	\
				isvisible,	\
				revision,	\
				auditaction )	\
		select	\
				a00c.clusterid,	\
				a00c.secgroupid,	\
				argAuditClusterId,	\
				argAuditSessionId,	\
				current timestamp,	\
				a00c.safe_name,	\
				a00c.isvisible,	\
				a00c.revision,	\
				0	\
		from cfsec213.SecGrp as a00c	\
		where	\
				a00c.clusterid = argClusterId	\
		and a00c.secgroupid = argSecGroupId;	\
	\
		open retcursor;	\
	end;	\
end
