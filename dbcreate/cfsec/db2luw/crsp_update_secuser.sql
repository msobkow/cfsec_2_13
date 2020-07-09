--
--	@(#) dbcreate/cfsec/db2luw/crsp_update_secuser.sql
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

create or replace procedure sp_update_secuser(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argSecUserId varchar(36),	\
	in argLoginId varchar(32),	\
	in argEMailAddress varchar(192),	\
	in argEMailConfirmUuid varchar(36),	\
	in argDfltDevUserId varchar(36),	\
	in argDfltDevName varchar(127),	\
	in argPasswordHash varchar(256),	\
	in argPasswordResetUuid varchar(36),	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldSecUserId varchar(36);	\
	declare oldLoginId varchar(32);	\
	declare oldEMailAddress varchar(192);	\
	declare oldEMailConfirmUuid varchar(36);	\
	declare oldDfltDevUserId varchar(36);	\
	declare oldDfltDevName varchar(127);	\
	declare oldPasswordHash varchar(256);	\
	declare oldPasswordResetUuid varchar(36);	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
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
			a011.secuserid = argSecUserId;	\
	begin	\
		if( argClassCode = 'a011' )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20001, 'Permission denied -- only system user can update SecUser records' );	\
			end if;	\
		end if;	\
	\
		select	\
			SecUserId,	\
			login_id,	\
			email_addr,	\
			em_confuuid,	\
			DefDevUserId,	\
			DefDevName,	\
			pwd_hash,	\
			pwdrstuuid,	\
			revision	\
		into	\
			oldSecUserId,	\
			oldLoginId,	\
			oldEMailAddress,	\
			oldEMailConfirmUuid,	\
			oldDfltDevUserId,	\
			oldDfltDevName,	\
			oldPasswordHash,	\
			oldPasswordResetUuid,	\
			oldRevision	\
		from cfsec213.SecUser	\
		where	\
			SecUserId = argSecUserId	\
		for update;	\
	\
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_secuser() Data collision detected' );	\
		end if;	\
	\
		update cfsec213.SecUser	\
		set	\
			revision = argRevision + 1,	\
			updatedby = argAuditUserId,	\
			updatedat = current timestamp,	\
			login_id = argLoginId,	\
			email_addr = argEMailAddress,	\
			em_confuuid = argEMailConfirmUuid,	\
			defdevuserid = argDfltDevUserId,	\
			defdevname = argDfltDevName,	\
			pwd_hash = argPasswordHash,	\
			pwdrstuuid = argPasswordResetUuid	\
		where	\
			secuserid = argSecUserId	\
		and revision = argRevision;	\
	\
		insert into cfsec213.SecUser_h (	\
				secuserid,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				login_id,	\
				email_addr,	\
				em_confuuid,	\
				defdevuserid,	\
				defdevname,	\
				pwd_hash,	\
				pwdrstuuid,	\
			revision,	\
			auditaction )	\
		select	\
				a011.secuserid,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a011.login_id,	\
				a011.email_addr,	\
				a011.em_confuuid,	\
				a011.defdevuserid,	\
				a011.defdevname,	\
				a011.pwd_hash,	\
				a011.pwdrstuuid,	\
			a011.revision,	\
			2	\
		from cfsec213.SecUser as a011	\
		where	\
			a011.secuserid = argSecUserId;	\
	\
		open retcursor;	\
	end;	\
end
