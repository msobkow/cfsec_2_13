--
--	@(#) dbcreate/cfsec/pgsql/crsp_delete_secuser_by_emconfidx.pgsql
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
create or replace function cfsec213.sp_delete_secuser_by_emconfidx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argEMailConfirmUuid varchar(36) )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
begin
	for cur in
		select
					a011.secuserid as secuserid,
				a011.revision as revision
		from cfsec213.SecUser as a011
		where
				( ( ( argEMailConfirmUuid is null ) and ( a011.em_confuuid is null ) )
				or ( ( argEMailConfirmUuid is not null ) and ( a011.em_confuuid = argEMailConfirmUuid ) ) )
	loop
				select cfsec213.sp_delete_secuser( argAuditClusterId,
						argAuditUserId,
						argAuditSessionId,
						secClusterId,
						secTenantId,
							cur.secuserid,
						cur.revision )
					into subret;
	end loop;
	return true;
end;
$$ language plpgsql;
