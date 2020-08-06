--
--	@(#) dbcreate/cfsec/oracle/crcrt_secuser.plsql
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
alter session set plsql_warnings = 'ENABLE:ALL';
/

create or replace procedure cfsec213.crt_secuser(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argSecUserId varchar2,
	arglogin_id varchar2,
	argemail_addr varchar2,
	argem_confuuid varchar2,
	argDefDevUserId varchar2,
	argDefDevName varchar2,
	argpwd_hash varchar2,
	argpwdrstuuid varchar2 ) authid definer
is
	permissionDenied exception;
	use_stamp cfsec213.SecUser_h.auditstamp%type;
	permissionFlag integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a011' )
	then
		permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	insert into cfsec213.secuser(
		createdby,
		createdat,
		updatedby,
		updatedat,
		SecUserId,
		login_id,
		email_addr,
		em_confuuid,
		DefDevUserId,
		DefDevName,
		pwd_hash,
		pwdrstuuid,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argSecUserId,
		arglogin_id,
		argemail_addr,
		argem_confuuid,
		argDefDevUserId,
		argDefDevName,
		argpwd_hash,
		argpwdrstuuid,
		1 );
	insert into cfsec213.SecUser_h (
			SecUserId,
			revision,
			auditclusterid,
			auditsessionid,
			login_id,
			email_addr,
			em_confuuid,
			DefDevUserId,
			DefDevName,
			pwd_hash,
			pwdrstuuid,
			auditaction,
			auditstamp )
		select
			a011.SecUserId as SecUserId,
			a011.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a011.login_id as login_id,
			a011.email_addr as email_addr,
			a011.em_confuuid as em_confuuid,
			a011.DefDevUserId as DefDevUserId,
			a011.DefDevName as DefDevName,
			a011.pwd_hash as pwd_hash,
			a011.pwdrstuuid as pwdrstuuid,
			0,
			use_stamp
		from cfsec213.SecUser a011
		where
			a011.SecUserId = argSecUserId;

	open retCursor for select
			a011.createdby,
			to_char( a011.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a011.updatedby,
			to_char( a011.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a011.SecUserId as SecUserId,
			a011.login_id as login_id,
			a011.email_addr as email_addr,
			a011.em_confuuid as em_confuuid,
			a011.DefDevUserId as DefDevUserId,
			a011.DefDevName as DefDevName,
			a011.pwd_hash as pwd_hash,
			a011.pwdrstuuid as pwdrstuuid,
		a011.revision as revision
	from cfsec213.SecUser a011
	where
		a011.SecUserId = argSecUserId;
end crt_secuser;
/

show errors procedure cfsec213.crt_secuser;
