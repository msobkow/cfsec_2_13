--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_sysclus.sql
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
create or replace procedure sp_delete_sysclus(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argSingletonId integer,	\
	in argRevision int )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldSingletonId integer;	\
	declare oldClusterId bigint;	\
	declare oldRevision int;	\
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
		select	\
			sgltn_id,	\
			sys_clus_id,	\
			revision	\
		into	\
			oldSingletonId,	\
			oldClusterId,	\
			oldRevision	\
		from cfsec213.sysclus	\
		where	\
			sgltn_id = argSingletonId	\
		for update;	\
	\
		set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20001, 'Permission denied -- only system user can delete SysCluster records' );	\
		end if;	\
	\
	\
		delete from cfsec213.sysclus	\
		where	\
			sgltn_id = argSingletonId;	\
	\
		open retcursor;	\
	end;	\
end
