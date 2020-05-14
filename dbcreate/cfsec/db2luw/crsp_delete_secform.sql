--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_secform.sql
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
create or replace procedure sp_delete_secform(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClusterId bigint,	\
	in argSecFormId integer,	\
	in argRevision int )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldClusterId bigint;	\
	declare oldSecFormId integer;	\
	declare oldSecAppId integer;	\
	declare oldJEEServletMapName varchar(192);	\
	declare oldRevision int;	\
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
		select	\
			ClusterId,	\
			SecFormId,	\
			SecAppId,	\
			JEEServletMapName,	\
			revision	\
		into	\
			oldClusterId,	\
			oldSecFormId,	\
			oldSecAppId,	\
			oldJEEServletMapName,	\
			oldRevision	\
		from cfsec213.SecForm	\
		where	\
			ClusterId = argClusterId	\
			and SecFormId = argSecFormId	\
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
				'DeleteSecForm',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for DeleteSecForm' );	\
		end if;	\
	\
	\
		insert into cfsec213.SecForm_h (	\
				clusterid,	\
				secformid,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				secappid,	\
				jeeservletmapname,	\
			revision,	\
			auditaction )	\
		select	\
				a00b.clusterid,	\
				a00b.secformid,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a00b.secappid,	\
				a00b.jeeservletmapname,	\
			a00b.revision + 1,	\
			2	\
		from cfsec213.SecForm as a00b	\
		where	\
			a00b.clusterid = argClusterId	\
		and a00b.secformid = argSecFormId;	\
	\
		delete from cfsec213.SecForm	\
		where	\
			clusterid = argClusterId	\
			and secformid = argSecFormId;	\
	\
		open retcursor;	\
	end;	\
end