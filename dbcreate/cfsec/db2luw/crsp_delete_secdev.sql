--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_secdev.sql
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
create or replace procedure sp_delete_secdev(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argSecUserId varchar(36),	\
	in argDevName varchar(127),	\
	in argRevision int )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldSecUserId varchar(36);	\
	declare oldDevName varchar(127);	\
	declare oldPubKey clob(10000);	\
	declare oldRevision int;	\
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
		select	\
			SecUserId,	\
			DevName,	\
			PubKey,	\
			revision	\
		into	\
			oldSecUserId,	\
			oldDevName,	\
			oldPubKey,	\
			oldRevision	\
		from cfsec213.SecDev	\
		where	\
			SecUserId = argSecUserId	\
			and DevName = argDevName	\
		for update;	\
	\
		set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20001, 'Permission denied -- only system user can delete SecDevice records' );	\
		end if;	\
	\
	\
		insert into cfsec213.SecDev_h (	\
				secuserid,	\
				devname,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				pubkey,	\
			revision,	\
			auditaction )	\
		select	\
				a00a.secuserid,	\
				a00a.devname,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a00a.pubkey,	\
			a00a.revision + 1,	\
			2	\
		from cfsec213.SecDev as a00a	\
		where	\
			a00a.secuserid = argSecUserId	\
		and a00a.devname = argDevName;	\
	\
		delete from cfsec213.SecDev	\
		where	\
			secuserid = argSecUserId	\
			and devname = argDevName;	\
	\
		open retcursor;	\
	end;	\
end
