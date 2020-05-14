--
--	@(#) dbcreate/cfsec/pgsql/crsp_delete_secuser.pgsql
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
create or replace function cfsec213.sp_delete_secuser(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argSecUserId varchar(36),
	argRevision int )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
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

	select cfsec213.sp_is_system_user( argAuditUserId ) into permissionFlag;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- only system user can delete SecUser records';
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
			2
		from cfsec213.SecUser as a011
		where
			a011.secuserid = argSecUserId;

	for cur in
		select
			a011.SecUserId as SecUserId
		from cfsec213.SecUser as a011
		where
			a011.SecUserId = argSecUserId
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

	for cur in
		select
			a018.TenantId,
			a018.TSecGrpMembId
		from cfsec213.SecUser as a011
			inner join cfsec213.tsecmemb a018 on 
				a011.SecUserId = a018.SecUserId
		where
			a011.SecUserId = argSecUserId
	loop
		select cfsec213.sp_delete_tsecmemb_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.TenantId,
				cur.TSecGrpMembId )
			into subret;
	end loop;

	for cur in
		select
			a00f.ClusterId,
			a00f.SecGrpMembId
		from cfsec213.SecUser as a011
			inner join cfsec213.secmemb a00f on 
				a011.SecUserId = a00f.SecUserId
		where
			a011.SecUserId = argSecUserId
	loop
		select cfsec213.sp_delete_secmemb_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.SecGrpMembId )
			into subret;
	end loop;

	for cur in
		select
			a010.SecSessionId
		from cfsec213.SecUser as a011
			inner join cfsec213.secsess a010 on 
				a011.SecUserId = a010.SecUserId
		where
			a011.SecUserId = argSecUserId
	loop
		select cfsec213.sp_delete_secsess_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.SecSessionId )
			into subret;
	end loop;

	for cur in
		select
			a010.SecSessionId
		from cfsec213.SecUser as a011
			inner join cfsec213.secsess a010 on 
				a011.SecUserId = a010.SecProxyId
		where
			a011.SecUserId = argSecUserId
	loop
		select cfsec213.sp_delete_secsess_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.SecSessionId )
			into subret;
	end loop;

	for cur in
		select
			a00a.SecUserId,
			a00a.DevName
		from cfsec213.SecUser as a011
			inner join cfsec213.secdev a00a on 
				a011.SecUserId = a00a.SecUserId
		where
			a011.SecUserId = argSecUserId
	loop
		select cfsec213.sp_delete_secdev_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.SecUserId,
				cur.DevName )
			into subret;
	end loop;


	delete from cfsec213.SecUser
	where
		secuserid = argSecUserId;

	get diagnostics RowsAffected = row_count;
	if RowsAffected != 1 and RowsAffected != 0
	then
		raise exception 'sp_delete_secuser() Expected to affect 1 SecUser, not %', RowsAffected;
	end if;

	return true;
end;
$$ language plpgsql;
