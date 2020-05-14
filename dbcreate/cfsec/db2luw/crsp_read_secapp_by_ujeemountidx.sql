--
--	@(#) dbcreate/cfsec/db2luw/crsp_read_secapp_by_ujeemountidx.sql
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
create or replace procedure sp_read_secapp_by_ujeemountidx(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClusterId bigint,	\
	in argJEEMountName varchar(192) )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare isSystemUser integer;	\
	declare syscurs cursor with return to client for	\
		select	\
				a009.createdby as createdby,	\
				to_char( a009.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a009.updatedby as updatedby,	\
				to_char( a009.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a009.clusterid as clusterid,	\
			a009.secappid as secappid,	\
			a009.jeemountname as jeemountname,	\
			a009.revision as revision	\
		from cfsec213.SecApp as a009	\
		where	\
			a009.clusterid = argClusterId	\
		and a009.jeemountname = argJEEMountName;	\
	declare usercurs cursor with return to client for	\
		select	\
				a009.createdby as createdby,	\
				to_char( a009.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a009.updatedby as updatedby,	\
				to_char( a009.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a009.clusterid as clusterid,	\
			a009.secappid as secappid,	\
			a009.jeemountname as jeemountname,	\
			a009.revision as revision	\
		from cfsec213.SecApp as a009	\
		where	\
			a009.clusterid = argClusterId	\
		and a009.jeemountname = argJEEMountName	\
			and ( a009.ClusterId = secClusterId );	\
	begin	\
		set( permissionFlag ) = ( sp_is_cluster_user( secClusterId,	\
				'ReadSecApp',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for ReadSecApp' );	\
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
