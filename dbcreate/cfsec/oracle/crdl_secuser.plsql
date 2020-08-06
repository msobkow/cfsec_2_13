--
--	@(#) dbcreate/cfsec/oracle/crdl_secuser.plsql
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

create or replace procedure cfsec213.dl_secuser(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argSecUserId varchar2,
	argRevision int ) authid definer
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
	cursor cursClearSecUserDefDev is
		select
			a011.SecUserId
		from cfsec213.SecUser a011
		where
			a011.SecUserId = argSecUserId;
	cursor cursDelTSecGrpMembs is
		select
			a018.TenantId,
			a018.TSecGrpMembId
		from cfsec213.SecUser a011
			inner join cfsec213.tsecmemb a018 on
				a011.SecUserId = a018.SecUserId
		where
			a011.SecUserId = argSecUserId;
	cursor cursDelSecGrpMembs is
		select
			a00f.ClusterId,
			a00f.SecGrpMembId
		from cfsec213.SecUser a011
			inner join cfsec213.secmemb a00f on
				a011.SecUserId = a00f.SecUserId
		where
			a011.SecUserId = argSecUserId;
	cursor cursDelSecSessions is
		select
			a010.SecSessionId
		from cfsec213.SecUser a011
			inner join cfsec213.secsess a010 on
				a011.SecUserId = a010.SecUserId
		where
			a011.SecUserId = argSecUserId;
	cursor cursDelSecProxySessions is
		select
			a010.SecSessionId
		from cfsec213.SecUser a011
			inner join cfsec213.secsess a010 on
				a011.SecUserId = a010.SecProxyId
		where
			a011.SecUserId = argSecUserId;
	cursor cursDelSecDevices is
		select
			a00a.SecUserId,
			a00a.DevName
		from cfsec213.SecUser a011
			inner join cfsec213.secdev a00a on
				a011.SecUserId = a00a.SecUserId
		where
			a011.SecUserId = argSecUserId;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
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

	permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
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
			2,
			use_stamp
		from cfsec213.SecUser a011
		where
			a011.SecUserId = argSecUserId;

	for cur in cursClearSecUserDefDev
	loop
		update cfsec213.secuser
		set
			DefDevUserId = null,
			DefDevName = null
		where
			SecUserId = cur.SecUserId;

	end loop;

	update cfsec213.SecUser
	set
		SecUserId = argSecUserId,
		DefDevUserId = null,
		DefDevName = null
	where
		SecUserId = argSecUserId;

	for cur in cursDelTSecGrpMembs
	loop
		cfsec213.dl_tsecmembbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.TenantId,
				cur.TSecGrpMembId );
	end loop;
	for cur in cursDelSecGrpMembs
	loop
		cfsec213.dl_secmembbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.SecGrpMembId );
	end loop;
	for cur in cursDelSecSessions
	loop
		cfsec213.dl_secsessbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.SecSessionId );
	end loop;
	for cur in cursDelSecProxySessions
	loop
		cfsec213.dl_secsessbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.SecSessionId );
	end loop;
	for cur in cursDelSecDevices
	loop
		cfsec213.dl_secdevbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.SecUserId,
				cur.DevName );
	end loop;
	delete from cfsec213.SecUser
	where
		SecUserId = argSecUserId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_secuser;
/

show errors procedure cfsec213.dl_secuser;
