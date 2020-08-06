--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_secuser.sql
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
create or replace procedure sp_delete_secuser(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argSecUserId varchar(36),	\
	in argRevision int )	\
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
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
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
		set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20001, 'Permission denied -- only system user can delete SecUser records' );	\
		end if;	\
	\
	\
		for cur as	\
			select	\
				a011.secuserid as curSecUserId	\
			from cfsec213.SecUser as a011	\
			where	\
				a011.secuserid = argSecUserId	\
		do	\
			update cfsec213.secuser	\
			set	\
				defdevuserid = null,	\
				defdevname = null	\
			where	\
				secuserid = curSecUserId;	\
	\
		end for;	\
	\
		update cfsec213.secuser	\
		set	\
			secuserid = argSecUserId,	\
			defdevuserid = null,	\
			defdevname = null	\
		where	\
			SecUserId = argSecUserId;	\
	\
		for cur as	\
			select	\
				a018.tenantid as tenantid,	\
				a018.tsecgrpmembid as tsecgrpmembid	\
			from cfsec213.SecUser as a011	\
				inner join cfsec213.tsecmemb a018 on 	\
					a011.secuserid = a018.secuserid	\
			where	\
				a011.secuserid = argSecUserId	\
		do	\
			call sp_delete_tsecmemb_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					tenantid,	\
					tsecgrpmembid );	\
		end for;	\
	\
		for cur as	\
			select	\
				a00f.clusterid as clusterid,	\
				a00f.secgrpmembid as secgrpmembid	\
			from cfsec213.SecUser as a011	\
				inner join cfsec213.secmemb a00f on 	\
					a011.secuserid = a00f.secuserid	\
			where	\
				a011.secuserid = argSecUserId	\
		do	\
			call sp_delete_secmemb_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					clusterid,	\
					secgrpmembid );	\
		end for;	\
	\
		for cur as	\
			select	\
				a010.secsessionid as secsessionid	\
			from cfsec213.SecUser as a011	\
				inner join cfsec213.secsess a010 on 	\
					a011.secuserid = a010.secuserid	\
			where	\
				a011.secuserid = argSecUserId	\
		do	\
			call sp_delete_secsess_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					secsessionid );	\
		end for;	\
	\
		for cur as	\
			select	\
				a010.secsessionid as secsessionid	\
			from cfsec213.SecUser as a011	\
				inner join cfsec213.secsess a010 on 	\
					a011.secuserid = a010.secproxyid	\
			where	\
				a011.secuserid = argSecUserId	\
		do	\
			call sp_delete_secsess_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					secsessionid );	\
		end for;	\
	\
		for cur as	\
			select	\
				a00a.secuserid as secuserid,	\
				a00a.devname as devname	\
			from cfsec213.SecUser as a011	\
				inner join cfsec213.secdev a00a on 	\
					a011.secuserid = a00a.secuserid	\
			where	\
				a011.secuserid = argSecUserId	\
		do	\
			call sp_delete_secdev_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					secuserid,	\
					devname );	\
		end for;	\
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
			a011.revision + 1,	\
			2	\
		from cfsec213.SecUser as a011	\
		where	\
			a011.secuserid = argSecUserId;	\
	\
		delete from cfsec213.SecUser	\
		where	\
			secuserid = argSecUserId;	\
	\
		open retcursor;	\
	end;	\
end
