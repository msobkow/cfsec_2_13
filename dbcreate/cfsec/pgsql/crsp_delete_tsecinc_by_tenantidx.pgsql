--
--	@(#) dbcreate/cfsec/pgsql/crsp_delete_tsecinc_by_tenantidx.pgsql
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
create or replace function cfsec213.sp_delete_tsecinc_by_tenantidx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argTenantId bigint )
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
					a017.tenantid as tenantid,
						a017.tsecgrpincid as tsecgrpincid,
					a017.revision as revision
			from cfsec213.TSecInc as a017
			where
					a017.tenantid = argTenantId
		loop
				select cfsec213.sp_delete_tsecinc( argAuditClusterId,
						argAuditUserId,
						argAuditSessionId,
						secClusterId,
						secTenantId,
							cur.tenantid,
							cur.tsecgrpincid,
						cur.revision )
					into subret;
		end loop;
	else
		for cur in
			select
					a017.tenantid as tenantid,
						a017.tsecgrpincid as tsecgrpincid,
					a017.revision as revision
			from cfsec213.TSecInc as a017
			where
					a017.tenantid = argTenantId
					and a017.TenantId = secTenantId
		loop
				select cfsec213.sp_delete_tsecinc( argAuditClusterId,
						argAuditUserId,
						argAuditSessionId,
						secClusterId,
						secTenantId,
							cur.tenantid,
							cur.tsecgrpincid,
						cur.revision )
					into subret;
		end loop;
	end if;
	return true;
end;
$$ language plpgsql;
