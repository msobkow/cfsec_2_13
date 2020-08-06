--
--	@(#) dbcreate/cfsec/db2luw/crsp_update_secdev.sql
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

create or replace procedure sp_update_secdev(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argSecUserId varchar(36),	\
	in argDevName varchar(127),	\
	in argPubKey clob(10000),	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldSecUserId varchar(36);	\
	declare oldDevName varchar(127);	\
	declare oldPubKey clob(10000);	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select	\
				a00a.createdby as createdby,	\
				to_char( a00a.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00a.updatedby as updatedby,	\
				to_char( a00a.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00a.secuserid as secuserid,	\
			a00a.devname as devname,	\
			a00a.pubkey as pubkey,	\
			a00a.revision as revision	\
		from cfsec213.SecDev as a00a	\
		where	\
			a00a.secuserid = argSecUserId	\
		and a00a.devname = argDevName;	\
	begin	\
		if( argClassCode = 'a00a' )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20001, 'Permission denied -- only system user can update SecDevice records' );	\
			end if;	\
		end if;	\
	\
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
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_secdev() Data collision detected' );	\
		end if;	\
	\
		update cfsec213.SecDev	\
		set	\
			revision = argRevision + 1,	\
			updatedby = argAuditUserId,	\
			updatedat = current timestamp,	\
			pubkey = argPubKey	\
		where	\
			secuserid = argSecUserId	\
		and devname = argDevName	\
		and revision = argRevision;	\
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
			a00a.revision,	\
			2	\
		from cfsec213.SecDev as a00a	\
		where	\
			a00a.secuserid = argSecUserId	\
		and a00a.devname = argDevName;	\
	\
		open retcursor;	\
	end;	\
end