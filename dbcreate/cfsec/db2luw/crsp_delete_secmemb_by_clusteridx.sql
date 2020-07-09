--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_secmemb_by_clusteridx.sql
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
create or replace procedure sp_delete_secmemb_by_clusteridx(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClusterId bigint )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
begin 	\
	set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
	if( permissionFlag = 1 )	\
	then	\
		for cur as 	\
			select	\
					a00f.clusterid as clusterid,	\
					a00f.secgrpmembid as secgrpmembid,	\
					a00f.revision as revision	\
			from cfsec213.SecMemb as a00f	\
			where	\
					a00f.clusterid = argClusterId	\
		do	\
			call sp_delete_secmemb( argAuditClusterId,	\
							argAuditUserId,	\
							argAuditSessionId,	\
							secClusterId,	\
							secTenantId,	\
							clusterid,	\
							secgrpmembid,	\
							revision );	\
		end for;	\
	else	\
		for cur as	\
			select	\
					a00f.clusterid as clusterid,	\
					a00f.secgrpmembid as secgrpmembid,	\
					a00f.revision as revision	\
			from cfsec213.SecMemb as a00f	\
			where	\
					a00f.clusterid = argClusterId	\
					and a00f.ClusterId = secClusterId	\
		do	\
			call sp_delete_secmemb( argAuditClusterId,	\
							argAuditUserId,	\
							argAuditSessionId,	\
							secClusterId,	\
							secTenantId,	\
							clusterid,	\
							secgrpmembid,	\
							revision );	\
		end for;	\
	end if;	\
		open retcursor;	\
	end;	\
end
