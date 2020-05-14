--
--	@(#) dbcreate/cfsec/db2luw/crsp_update_sysclus.sql
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

create or replace procedure sp_update_sysclus(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argSingletonId integer,	\
	in argClusterId bigint,	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldSingletonId integer;	\
	declare oldClusterId bigint;	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select	\
				a014.sgltn_id as sgltn_id,	\
			a014.sys_clus_id as sys_clus_id,	\
			a014.revision as revision	\
		from cfsec213.sysclus as a014	\
		where	\
			a014.sgltn_id = argSingletonId;	\
	begin	\
		if( argClassCode = 'a014' )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20001, 'Permission denied -- only system user can update SysCluster records' );	\
			end if;	\
		end if;	\
	\
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
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_sysclus() Data collision detected' );	\
		end if;	\
	\
		update cfsec213.sysclus	\
		set	\
			revision = argRevision + 1,	\
			sys_clus_id = argClusterId	\
		where	\
			sgltn_id = argSingletonId	\
		and revision = argRevision;	\
	\
		open retcursor;	\
	end;	\
end
