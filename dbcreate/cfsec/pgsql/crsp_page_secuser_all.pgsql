--
--	@(#) dbcreate/cfsec/pgsql/crsp_page_secuser_all.pgsql
--
--	org.msscf.msscf.CFSec
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	MSS Code Factory CFSec 2.13 Security Essentials
--	
--	Copyright 2020 Mark Stephen Sobkow
--	
--		This file is part of MSS Code Factory.
--	
--		MSS Code Factory is available under dual commercial license from Mark Stephen
--		Sobkow, or under the terms of the GNU General Public License, Version 3
--		or later.
--	
--	    MSS Code Factory is free software: you can redistribute it and/or modify
--	    it under the terms of the GNU General Public License as published by
--	    the Free Software Foundation, either version 3 of the License, or
--	    (at your option) any later version.
--	
--	    MSS Code Factory is distributed in the hope that it will be useful,
--	    but WITHOUT ANY WARRANTY; without even the implied warranty of
--	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--	    GNU General Public License for more details.
--	
--	    You should have received a copy of the GNU General Public License
--	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
--	
--	Donations to support MSS Code Factory can be made at
--	https://www.paypal.com/paypalme2/MarkSobkow
--	
--	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
--
--	Manufactured by MSS Code Factory 2.12
--
create or replace function cfsec213.sp_page_secuser_all(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
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
			( ( ( a011.SecUserId < priorSecUserId ) ) )
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
				order by SecUserId desc
			limit 25;
	end if;

	return;
end;
$$ language plpgsql;
