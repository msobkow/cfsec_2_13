--
--	@(#) dbcreate/cfsec/db2luw/crsp_create_sysclus.sql
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
create or replace procedure sp_create_sysclus(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argSingletonId integer,	\
	in argClusterId bigint )	\
dynamic result sets 1	\
language sql	\
begin	\
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
				call raise_application_error( -20001, 'Permission denied -- only system user can create SysCluster records' );	\
			end if;	\
		end if;	\
		insert into cfsec213.sysclus(	\
			sgltn_id,	\
			sys_clus_id,	\
			revision )	\
		values (	\
			argSingletonId,	\
			argClusterId,	\
			1 );	\
	\
		open retcursor;	\
	end;	\
end
