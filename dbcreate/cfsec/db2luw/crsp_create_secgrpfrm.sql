--
--	@(#) dbcreate/cfsec/db2luw/crsp_create_secgrpfrm.sql
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
create or replace procedure sp_create_secgrpfrm(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argClusterId bigint,	\
	in argSecGroupId integer,	\
	in argSecAppId integer,	\
	in argSecFormId integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
		declare argSecGroupFormId bigint;	\
	declare retcursor cursor with return to client for	\
		select	\
				a00d.createdby as createdby,	\
				to_char( a00d.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00d.updatedby as updatedby,	\
				to_char( a00d.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00d.clusid as clusid,	\
			a00d.secgrpfrmid as secgrpfrmid,	\
			a00d.secgrpid as secgrpid,	\
			a00d.secappid as secappid,	\
			a00d.secfrmid as secfrmid,	\
			a00d.revision as revision	\
		from cfsec213.SecGrpFrm as a00d	\
		where	\
			a00d.clusid = argClusterId	\
		and a00d.secgrpfrmid = argSecGroupFormId;	\
	begin	\
		if( argClassCode = 'a00d' )	\
		then	\
			set( permissionFlag ) = ( sp_is_cluster_user( argClusterId,	\
					'CreateSecGroupForm',	\
					argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for CreateSecGroupForm' );	\
			end if;	\
		end if;	\
	\
		call sp_next_secgroupformidgen( argClusterId,	\
			argSecGroupFormId );	\
		insert into cfsec213.secgrpfrm(	\
			createdby,	\
			createdat,	\
			updatedby,	\
			updatedat,	\
			clusid,	\
			secgrpfrmid,	\
			secgrpid,	\
			secappid,	\
			secfrmid,	\
			revision )	\
		values (	\
			argAuditUserId,	\
			current timestamp,	\
			argAuditUserId,	\
			current timestamp,	\
			argClusterId,	\
			argSecGroupFormId,	\
			argSecGroupId,	\
			argSecAppId,	\
			argSecFormId,	\
			1 );	\
	\
		insert into cfsec213.secgrpfrm_h (	\
				clusid,	\
				secgrpfrmid,	\
				auditclusterid,	\
				auditsessionid,	\
				auditstamp,	\
				secgrpid,	\
				secappid,	\
				secfrmid,	\
				revision,	\
				auditaction )	\
		select	\
				a00d.clusid,	\
				a00d.secgrpfrmid,	\
				argAuditClusterId,	\
				argAuditSessionId,	\
				current timestamp,	\
				a00d.secgrpid,	\
				a00d.secappid,	\
				a00d.secfrmid,	\
				a00d.revision,	\
				0	\
		from cfsec213.SecGrpFrm as a00d	\
		where	\
				a00d.clusid = argClusterId	\
		and a00d.secgrpfrmid = argSecGroupFormId;	\
	\
		open retcursor;	\
	end;	\
end
