--
--	@(#) dbcreate/cfsec/pgsql/crsp_update_sysclus.pgsql
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

create or replace function cfsec213.sp_update_sysclus(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argSingletonId integer,
	argClusterId bigint,
	argRevision integer )
returns setof cfsec213.type_sysclus_rec as $$
declare
	RowsAffected integer;
	oldSingletonId integer;
	oldClusterId bigint;
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a014' )
	then
		select cfsec213.sp_is_system_user( argAuditUserId ) into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- only system user can update SysCluster records';
		end if;
	end if;

		select
			sgltn_id,
			sys_clus_id,
			revision
		into
			oldSingletonId,
			oldClusterId,
			oldRevision
		from cfsec213.sysclus
		where
			sgltn_id = argSingletonId
		for update;


	if argRevision != oldRevision
	then
		raise exception 'sp_update_sysclus() Data collision detected';
	end if;


	update cfsec213.sysclus
	set
		revision = argRevision + 1,
		sys_clus_id = argClusterId
	where
		sgltn_id = argSingletonId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_sysclus() Expected to affect one sysclus row, not %', RowsAffected;
	end if;


	return query select
			a014.sgltn_id as sgltn_id,
			a014.sys_clus_id as sys_clus_id,
		a014.revision as revision
	from cfsec213.sysclus as a014
	where
		a014.sgltn_id = argSingletonId;

	return;
end;
$$ language plpgsql;
