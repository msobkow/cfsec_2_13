--
--	@(#) dbcreate/cfsec/db2luw/crsp_page_secuser_by_defdevidx.sql
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
create or replace procedure sp_page_secuser_by_defdevidx(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argDfltDevUserId varchar(36),	\
	in argDfltDevName varchar(127),	\
	in priorSecUserId varchar(36) )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare isSystemUser integer;	\
	declare syscurs cursor with return to client for	\
		select	\
				a011.createdby as createdby,	\
				to_char( a011.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a011.updatedby as updatedby,	\
				to_char( a011.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a011.secuserid as secuserid,	\
			a011.login_id as login_id,	\
			a011.email_addr as email_addr,	\
			a011.em_confuuid as em_confuuid,	\
			a011.defdevuserid as defdevuserid,	\
			a011.defdevname as defdevname,	\
			a011.pwd_hash as pwd_hash,	\
			a011.pwdrstuuid as pwdrstuuid,	\
			a011.revision as revision	\
		from cfsec213.SecUser as a011	\
		where	\
			( ( ( argDfltDevUserId is null ) and ( a011.defdevuserid is null ) )	\
				or ( ( argDfltDevUserId is not null ) and ( a011.defdevuserid = argDfltDevUserId ) ) )	\
		and ( ( ( argDfltDevName is null ) and ( a011.defdevname is null ) )	\
				or ( ( argDfltDevName is not null ) and ( a011.defdevname = argDfltDevName ) ) )	\
		order by SecUserId desc	\
		fetch first 25 rows only;	\
	declare syspage cursor with return to client for	\
		select	\
				a011.createdby as createdby,	\
				to_char( a011.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a011.updatedby as updatedby,	\
				to_char( a011.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a011.secuserid as secuserid,	\
			a011.login_id as login_id,	\
			a011.email_addr as email_addr,	\
			a011.em_confuuid as em_confuuid,	\
			a011.defdevuserid as defdevuserid,	\
			a011.defdevname as defdevname,	\
			a011.pwd_hash as pwd_hash,	\
			a011.pwdrstuuid as pwdrstuuid,	\
			a011.revision as revision	\
		from cfsec213.SecUser as a011	\
		where	\
			( ( ( argDfltDevUserId is null ) and ( a011.defdevuserid is null ) )	\
				or ( ( argDfltDevUserId is not null ) and ( a011.defdevuserid = argDfltDevUserId ) ) )	\
		and ( ( ( argDfltDevName is null ) and ( a011.defdevname is null ) )	\
				or ( ( argDfltDevName is not null ) and ( a011.defdevname = argDfltDevName ) ) )	\
			and ( ( ( a011.SecUserId < priorSecUserId ) ) )	\
		order by SecUserId desc	\
		fetch first 25 rows only;	\
	declare usercurs cursor with return to client for	\
		select	\
				a011.createdby as createdby,	\
				to_char( a011.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a011.updatedby as updatedby,	\
				to_char( a011.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a011.secuserid as secuserid,	\
			a011.login_id as login_id,	\
			a011.email_addr as email_addr,	\
			a011.em_confuuid as em_confuuid,	\
			a011.defdevuserid as defdevuserid,	\
			a011.defdevname as defdevname,	\
			a011.pwd_hash as pwd_hash,	\
			a011.pwdrstuuid as pwdrstuuid,	\
			a011.revision as revision	\
		from cfsec213.SecUser as a011	\
		where	\
			( ( ( argDfltDevUserId is null ) and ( a011.defdevuserid is null ) )	\
				or ( ( argDfltDevUserId is not null ) and ( a011.defdevuserid = argDfltDevUserId ) ) )	\
		and ( ( ( argDfltDevName is null ) and ( a011.defdevname is null ) )	\
				or ( ( argDfltDevName is not null ) and ( a011.defdevname = argDfltDevName ) ) )	\
		order by SecUserId desc	\
		fetch first 25 rows only;	\
	declare userpage cursor with return to client for	\
		select	\
				a011.createdby as createdby,	\
				to_char( a011.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a011.updatedby as updatedby,	\
				to_char( a011.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a011.secuserid as secuserid,	\
			a011.login_id as login_id,	\
			a011.email_addr as email_addr,	\
			a011.em_confuuid as em_confuuid,	\
			a011.defdevuserid as defdevuserid,	\
			a011.defdevname as defdevname,	\
			a011.pwd_hash as pwd_hash,	\
			a011.pwdrstuuid as pwdrstuuid,	\
			a011.revision as revision	\
		from cfsec213.SecUser as a011	\
		where	\
			( ( ( argDfltDevUserId is null ) and ( a011.defdevuserid is null ) )	\
				or ( ( argDfltDevUserId is not null ) and ( a011.defdevuserid = argDfltDevUserId ) ) )	\
		and ( ( ( argDfltDevName is null ) and ( a011.defdevname is null ) )	\
				or ( ( argDfltDevName is not null ) and ( a011.defdevname = argDfltDevName ) ) )	\
			and ( ( ( a011.SecUserId < priorSecUserId ) ) )	\
		order by SecUserId desc	\
		fetch first 25 rows only;	\
	begin	\
		if( ( priorSecUserId is not null ) )	\
		then	\
			open syspage;	\
		end if;	\
		if( not ( ( priorSecUserId is not null ) ) )	\
		then	\
			open syscurs;	\
		end if;	\
	end;	\
end
