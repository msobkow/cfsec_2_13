--
--	@(#) dbcreate/cfsec/oracle/crupd_secuser.plsql
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
alter session set plsql_warnings = 'ENABLE:ALL';
/


create or replace procedure cfsec213.upd_secuser(
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
	argpwdrstuuid varchar2,
	argRevision integer ) authid definer
is
	use_stamp cfsec213.SecUser_h.auditstamp%type;
	oldSecUserId varchar2(36);
	oldlogin_id varchar2(32);
	oldemail_addr varchar2(192);
	oldem_confuuid varchar2(36);
	oldDefDevUserId varchar2(36);
	oldDefDevName varchar2(127);
	oldpwd_hash varchar2(256);
	oldpwdrstuuid varchar2(36);
	oldRevision integer;
	dataCollision exception;
	dataUpdateFailed exception;
	permissionDenied exception;
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

		select
			SecUserId,
			login_id,
			email_addr,
			em_confuuid,
			DefDevUserId,
			DefDevName,
			pwd_hash,
			pwdrstuuid,
			revision
		into
			oldSecUserId,
			oldlogin_id,
			oldemail_addr,
			oldem_confuuid,
			oldDefDevUserId,
			oldDefDevName,
			oldpwd_hash,
			oldpwdrstuuid,
			oldRevision
		from cfsec213.SecUser
		where
			SecUserId = argSecUserId
		for update;

	if argRevision != oldRevision
	then
		raise dataCollision;
	end if;

	update cfsec213.SecUser
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = use_stamp,
		login_id = arglogin_id,
		email_addr = argemail_addr,
		em_confuuid = argem_confuuid,
		DefDevUserId = argDefDevUserId,
		DefDevName = argDefDevName,
		pwd_hash = argpwd_hash,
		pwdrstuuid = argpwdrstuuid
	where
		SecUserId = argSecUserId
		and revision = argRevision;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;


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
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a011.login_id as login_id,
			a011.email_addr as email_addr,
			a011.em_confuuid as em_confuuid,
			a011.DefDevUserId as DefDevUserId,
			a011.DefDevName as DefDevName,
			a011.pwd_hash as pwd_hash,
			a011.pwdrstuuid as pwdrstuuid,
			1,
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
end upd_secuser;

/

show errors procedure cfsec213.upd_secuser;
