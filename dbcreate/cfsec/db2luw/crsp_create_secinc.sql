--
--	@(#) dbcreate/cfsec/db2luw/crsp_create_secinc.sql
--
--	com.github.msobkow.CFSec
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
create or replace procedure sp_create_secinc(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argClusterId bigint,	\
	in argSecGroupId integer,	\
	in argIncludeGroupId integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
		declare argSecGrpIncId bigint;	\
	declare retcursor cursor with return to client for	\
		select	\
				a00e.createdby as createdby,	\
				to_char( a00e.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00e.updatedby as updatedby,	\
				to_char( a00e.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00e.clusid as clusid,	\
			a00e.secgrpincid as secgrpincid,	\
			a00e.secgrpid as secgrpid,	\
			a00e.incgrpid as incgrpid,	\
			a00e.revision as revision	\
		from cfsec213.SecInc as a00e	\
		where	\
			a00e.clusid = argClusterId	\
		and a00e.secgrpincid = argSecGrpIncId;	\
	begin	\
		if( argClassCode = 'a00e' )	\
		then	\
			set( permissionFlag ) = ( sp_is_cluster_user( argClusterId,	\
					'CreateSecGrpInc',	\
					argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for CreateSecGrpInc' );	\
			end if;	\
		end if;	\
	\
		call sp_next_secgrpincidgen( argClusterId,	\
			argSecGrpIncId );	\
		insert into cfsec213.secinc(	\
			createdby,	\
			createdat,	\
			updatedby,	\
			updatedat,	\
			clusid,	\
			secgrpincid,	\
			secgrpid,	\
			incgrpid,	\
			revision )	\
		values (	\
			argAuditUserId,	\
			current timestamp,	\
			argAuditUserId,	\
			current timestamp,	\
			argClusterId,	\
			argSecGrpIncId,	\
			argSecGroupId,	\
			argIncludeGroupId,	\
			1 );	\
	\
		insert into cfsec213.secinc_h (	\
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
				a00e.revision,	\
				0	\
		from cfsec213.SecInc as a00e	\
		where	\
				a00e.clusid = argClusterId	\
		and a00e.secgrpincid = argSecGrpIncId;	\
	\
		open retcursor;	\
	end;	\
end
