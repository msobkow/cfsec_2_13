--
--	@(#) dbcreate/cfsec/pgsql/crsp_delete_secgrp_by_unameidx.pgsql
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
create or replace function cfsec213.sp_delete_secgrp_by_unameidx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClusterId bigint,
	argName varchar(64) )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
begin
	select cfsec213.sp_is_system_user( argAuditUserId ) into subret;
	if( subret )
	then
		for cur in
			select
					a00c.clusterid as clusterid,
						a00c.secgroupid as secgroupid,
					a00c.revision as revision
			from cfsec213.SecGrp as a00c
			where
					a00c.clusterid = argClusterId
			and a00c.safe_name = argName
		loop
				select cfsec213.sp_delete_secgrp( argAuditClusterId,
						argAuditUserId,
						argAuditSessionId,
						secClusterId,
						secTenantId,
							cur.clusterid,
							cur.secgroupid,
						cur.revision )
					into subret;
		end loop;
	else
		for cur in
			select
					a00c.clusterid as clusterid,
						a00c.secgroupid as secgroupid,
					a00c.revision as revision
			from cfsec213.SecGrp as a00c
			where
					a00c.clusterid = argClusterId
			and a00c.safe_name = argName
					and a00c.ClusterId = secClusterId
		loop
				select cfsec213.sp_delete_secgrp( argAuditClusterId,
						argAuditUserId,
						argAuditSessionId,
						secClusterId,
						secTenantId,
							cur.clusterid,
							cur.secgroupid,
						cur.revision )
					into subret;
		end loop;
	end if;
	return true;
end;
$$ language plpgsql;