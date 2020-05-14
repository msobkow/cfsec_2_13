--
--	@(#) dbcreate/cfsec/db2luw/crsp_create_secmemb.sql
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
create or replace procedure sp_create_secmemb(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argClusterId bigint,	\
	in argSecGroupId integer,	\
	in argSecUserId varchar(36) )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
		declare argSecGrpMembId bigint;	\
	declare retcursor cursor with return to client for	\
		select	\
				a00f.createdby as createdby,	\
				to_char( a00f.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00f.updatedby as updatedby,	\
				to_char( a00f.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00f.clusterid as clusterid,	\
			a00f.secgrpmembid as secgrpmembid,	\
			a00f.secgroupid as secgroupid,	\
			a00f.secuserid as secuserid,	\
			a00f.revision as revision	\
		from cfsec213.SecMemb as a00f	\
		where	\
			a00f.clusterid = argClusterId	\
		and a00f.secgrpmembid = argSecGrpMembId;	\
	begin	\
		if( argClassCode = 'a00f' )	\
		then	\
			set( permissionFlag ) = ( sp_is_cluster_user( argClusterId,	\
					'CreateSecGrpMemb',	\
					argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for CreateSecGrpMemb' );	\
			end if;	\
		end if;	\
	\
		call sp_next_secgrpmembidgen( argClusterId,	\
			argSecGrpMembId );	\
		insert into cfsec213.secmemb(	\
			createdby,	\
			createdat,	\
			updatedby,	\
			updatedat,	\
			clusterid,	\
			secgrpmembid,	\
			secgroupid,	\
			secuserid,	\
			revision )	\
		values (	\
			argAuditUserId,	\
			current timestamp,	\
			argAuditUserId,	\
			current timestamp,	\
			argClusterId,	\
			argSecGrpMembId,	\
			argSecGroupId,	\
			argSecUserId,	\
			1 );	\
	\
		insert into cfsec213.secmemb_h (	\
				clusterid,	\
				secgrpmembid,	\
				auditclusterid,	\
				auditsessionid,	\
				auditstamp,	\
				secgroupid,	\
				secuserid,	\
				revision,	\
				auditaction )	\
		select	\
				a00f.clusterid,	\
				a00f.secgrpmembid,	\
				argAuditClusterId,	\
				argAuditSessionId,	\
				current timestamp,	\
				a00f.secgroupid,	\
				a00f.secuserid,	\
				a00f.revision,	\
				0	\
		from cfsec213.SecMemb as a00f	\
		where	\
				a00f.clusterid = argClusterId	\
		and a00f.secgrpmembid = argSecGrpMembId;	\
	\
		open retcursor;	\
	end;	\
end