--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_secinc.sql
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
create or replace procedure sp_delete_secinc(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClusterId bigint,	\
	in argSecGrpIncId bigint,	\
	in argRevision int )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldClusterId bigint;	\
	declare oldSecGrpIncId bigint;	\
	declare oldSecGroupId integer;	\
	declare oldIncludeGroupId integer;	\
	declare oldRevision int;	\
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
		select	\
			ClusId,	\
			SecGrpIncId,	\
			SecGrpId,	\
			IncGrpId,	\
			revision	\
		into	\
			oldClusterId,	\
			oldSecGrpIncId,	\
			oldSecGroupId,	\
			oldIncludeGroupId,	\
			oldRevision	\
		from cfsec213.SecInc	\
		where	\
			ClusId = argClusterId	\
			and SecGrpIncId = argSecGrpIncId	\
		for update;	\
	\
		if( oldClusterId != secClusterId )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20002, 'Permission denied -- Data is not owned by logged in cluster' );	\
			end if;	\
		end if;	\
	\
		set( permissionFlag ) = ( sp_is_cluster_user( oldClusterId,	\
				'DeleteSecGrpInc',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for DeleteSecGrpInc' );	\
		end if;	\
	\
	\
		insert into cfsec213.SecInc_h (	\
				clusid,	\
				secgrpincid,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				secgrpid,	\
				incgrpid,	\
			revision,	\
			auditaction )	\
		select	\
				a00e.clusid,	\
				a00e.secgrpincid,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a00e.secgrpid,	\
				a00e.incgrpid,	\
			a00e.revision + 1,	\
			2	\
		from cfsec213.SecInc as a00e	\
		where	\
			a00e.clusid = argClusterId	\
		and a00e.secgrpincid = argSecGrpIncId;	\
	\
		delete from cfsec213.SecInc	\
		where	\
			clusid = argClusterId	\
			and secgrpincid = argSecGrpIncId;	\
	\
		open retcursor;	\
	end;	\
end
