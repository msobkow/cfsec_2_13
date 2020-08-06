--
--	@(#) dbcreate/cfsec/pgsql/crsp_update_secuser.pgsql
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

create or replace function cfsec213.sp_update_secuser(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argSecUserId varchar(36),
	argLoginId varchar(32),
	argEMailAddress varchar(192),
	argEMailConfirmUuid varchar(36),
	argDfltDevUserId varchar(36),
	argDfltDevName varchar(127),
	argPasswordHash varchar(256),
	argPasswordResetUuid varchar(36),
	argRevision integer )
returns setof cfsec213.type_secuser_rec as $$
declare
	RowsAffected integer;
	oldSecUserId varchar(36);
	oldLoginId varchar(32);
	oldEMailAddress varchar(192);
	oldEMailConfirmUuid varchar(36);
	oldDfltDevUserId varchar(36);
	oldDfltDevName varchar(127);
	oldPasswordHash varchar(256);
	oldPasswordResetUuid varchar(36);
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a011' )
	then
		select cfsec213.sp_is_system_user( argAuditUserId ) into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- only system user can update SecUser records';
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
			oldLoginId,
			oldEMailAddress,
			oldEMailConfirmUuid,
			oldDfltDevUserId,
			oldDfltDevName,
			oldPasswordHash,
			oldPasswordResetUuid,
			oldRevision
		from cfsec213.SecUser
		where
			SecUserId = argSecUserId
		for update;


	if argRevision != oldRevision
	then
		raise exception 'sp_update_secuser() Data collision detected';
	end if;


	update cfsec213.SecUser
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		login_id = argLoginId,
		email_addr = argEMailAddress,
		em_confuuid = argEMailConfirmUuid,
		defdevuserid = argDfltDevUserId,
		defdevname = argDfltDevName,
		pwd_hash = argPasswordHash,
		pwdrstuuid = argPasswordResetUuid
	where
		SecUserId = argSecUserId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_secuser() Expected to affect one SecUser row, not %', RowsAffected;
	end if;


	insert into cfsec213.SecUser_h (
			SecUserId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			login_id,
			email_addr,
			em_confuuid,
			DefDevUserId,
			DefDevName,
			pwd_hash,
			pwdrstuuid,
			revision,
			auditaction )
		select
			a011.SecUserId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a011.login_id,
			a011.email_addr,
			a011.em_confuuid,
			a011.DefDevUserId,
			a011.DefDevName,
			a011.pwd_hash,
			a011.pwdrstuuid,
			argRevision + 1,
			1
		from cfsec213.SecUser as a011
		where
			a011.secuserid = argSecUserId;
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
		a011.secuserid = argSecUserId;

	return;
end;
$$ language plpgsql;
