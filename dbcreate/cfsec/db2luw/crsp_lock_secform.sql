--
--	@(#) dbcreate/cfsec/db2luw/crsp_lock_secform.sql
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

create or replace procedure sp_lock_secform(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClusterId bigint,	\
	in argSecFormId integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare isSystemUser integer;	\
	declare syscurs cursor with return to client for	\
		select	\
				a00b.createdby as createdby,	\
				to_char( a00b.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00b.updatedby as updatedby,	\
				to_char( a00b.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00b.clusterid as clusterid,	\
			a00b.secformid as secformid,	\
			a00b.secappid as secappid,	\
			a00b.jeeservletmapname as jeeservletmapname,	\
			a00b.revision as revision	\
		from cfsec213.SecForm as a00b	\
		where	\
			a00b.clusterid = argClusterId	\
		and a00b.secformid = argSecFormId	\
		for update;	\
	declare usercurs cursor with return to client for	\
		select	\
				a00b.createdby as createdby,	\
				to_char( a00b.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00b.updatedby as updatedby,	\
				to_char( a00b.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00b.clusterid as clusterid,	\
			a00b.secformid as secformid,	\
			a00b.secappid as secappid,	\
			a00b.jeeservletmapname as jeeservletmapname,	\
			a00b.revision as revision	\
		from cfsec213.SecForm as a00b	\
		where	\
			a00b.clusterid = argClusterId	\
		and a00b.secformid = argSecFormId	\
			and ( a00b.ClusterId = secClusterId )	\
		for update;	\
	begin	\
		set( permissionFlag ) = ( sp_is_cluster_user( secClusterId,	\
				'UpdateSecForm',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for UpdateSecForm' );	\
		end if;	\
		set( isSystemUser ) = ( sp_is_system_user( argAuditUserId ) );	\
		if( isSystemUser = 1 )	\
		then	\
			open syscurs;	\
		else	\
			open usercurs;	\
		end if;	\
	end;	\
end