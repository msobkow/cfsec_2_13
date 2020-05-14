--
--	@(#) dbcreate/cfsec/pgsql/crsp_page_secuser_by_defdevidx.pgsql
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
create or replace function cfsec213.sp_page_secuser_by_defdevidx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argDfltDevUserId varchar(36),
	argDfltDevName varchar(127),
	priorSecUserId varchar(36) )
returns setof cfsec213.type_secuser_rec as $$
begin
	if( ( priorSecUserId is not null ) )
	then
		return query select
			a011.createdby,
			to_char( a011.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a011.updatedby,
			to_char( a011.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a011.secuserid as secuserid,
			a011.login_id as login_id,
			a011.email_addr as email_addr,
			a011.em_confuuid as em_confuuid,
			a011.defdevuserid as defdevuserid,
			a011.defdevname as defdevname,
			a011.pwd_hash as pwd_hash,
			a011.pwdrstuuid as pwdrstuuid,
			a011.revision as revision
		from cfsec213.SecUser as a011
		where
				( ( ( argDfltDevUserId is null ) and ( a011.defdevuserid is null ) )
				or ( ( argDfltDevUserId is not null ) and ( a011.defdevuserid = argDfltDevUserId ) ) )
			and ( ( ( argDfltDevName is null ) and ( a011.defdevname is null ) )
				or ( ( argDfltDevName is not null ) and ( a011.defdevname = argDfltDevName ) ) )
			and ( ( ( a011.SecUserId < priorSecUserId ) ) )
				order by SecUserId desc
			limit 25;
	else
		return query select
			a011.createdby,
			to_char( a011.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a011.updatedby,
			to_char( a011.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a011.secuserid as secuserid,
			a011.login_id as login_id,
			a011.email_addr as email_addr,
			a011.em_confuuid as em_confuuid,
			a011.defdevuserid as defdevuserid,
			a011.defdevname as defdevname,
			a011.pwd_hash as pwd_hash,
			a011.pwdrstuuid as pwdrstuuid,
			a011.revision as revision
		from cfsec213.SecUser as a011
		where
				( ( ( argDfltDevUserId is null ) and ( a011.defdevuserid is null ) )
				or ( ( argDfltDevUserId is not null ) and ( a011.defdevuserid = argDfltDevUserId ) ) )
			and ( ( ( argDfltDevName is null ) and ( a011.defdevname is null ) )
				or ( ( argDfltDevName is not null ) and ( a011.defdevname = argDfltDevName ) ) )
				order by SecUserId desc
			limit 25;
	end if;
	return;
end
$$ language plpgsql;
