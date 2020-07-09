--
--	@(#) dbcreate/cfsec/db2luw/crsp_update_secgrp.sql
--
--	org.msscf.msscf.CFSec
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	This file is part of MSS Code Factory.
--	
--	Licensed under the Apache License, Version 2.0 (the "License");
--	you may not use this file except in compliance with the License.
--	You may obtain a copy of the License at
--	
--	    http://www.apache.org/licenses/LICENSE-2.0
--	
--	Unless required by applicable law or agreed to in writing, software
--	distributed under the License is distributed on an "AS IS" BASIS,
--	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
--	See the License for the specific language governing permissions and
--	limitations under the License.
--	
--	Donations to support MSS Code Factory can be made at
--	https://www.paypal.com/paypalme2/MarkSobkow
--
--	Manufactured by MSS Code Factory 2.12
--

create or replace procedure sp_update_secgrp(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argClusterId bigint,	\
	in argSecGroupId integer,	\
	in argName varchar(64),	\
	in argIsVisible char(1),	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldClusterId bigint;	\
	declare oldSecGroupId integer;	\
	declare oldName varchar(64);	\
	declare oldIsVisible char(1);	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
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
					'UpdateSecGroup',	\
					argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for UpdateSecGroup' );	\
			end if;	\
		end if;	\
	\
		select	\
			ClusterId,	\
			SecGroupId,	\
			safe_name,	\
			IsVisible,	\
			revision	\
		into	\
			oldClusterId,	\
			oldSecGroupId,	\
			oldName,	\
			oldIsVisible,	\
			oldRevision	\
		from cfsec213.SecGrp	\
		where	\
			ClusterId = argClusterId	\
			and SecGroupId = argSecGroupId	\
		for update;	\
	\
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_secgrp() Data collision detected' );	\
		end if;	\
	\
		update cfsec213.SecGrp	\
		set	\
			revision = argRevision + 1,	\
			updatedby = argAuditUserId,	\
			updatedat = current timestamp,	\
			safe_name = argName,	\
			isvisible = argIsVisible	\
		where	\
			clusterid = argClusterId	\
		and secgroupid = argSecGroupId	\
		and revision = argRevision;	\
	\
		insert into cfsec213.SecGrp_h (	\
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
			2	\
		from cfsec213.SecGrp as a00c	\
		where	\
			a00c.clusterid = argClusterId	\
		and a00c.secgroupid = argSecGroupId;	\
	\
		open retcursor;	\
	end;	\
end
