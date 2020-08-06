--
--	@(#) dbcreate/cfsec/db2luw/crsp_update_iso_cntryccy.sql
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

create or replace procedure sp_update_iso_cntryccy(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argISOCtryId smallint,	\
	in argISOCcyId smallint,	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldISOCtryId smallint;	\
	declare oldISOCcyId smallint;	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select	\
				a005.createdby as createdby,	\
				to_char( a005.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a005.updatedby as updatedby,	\
				to_char( a005.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a005.isoctryid as isoctryid,	\
			a005.isoccyid as isoccyid,	\
			a005.revision as revision	\
		from cfsec213.iso_cntryccy as a005	\
		where	\
			a005.isoctryid = argISOCtryId	\
		and a005.isoccyid = argISOCcyId;	\
	begin	\
		if( argClassCode = 'a005' )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20001, 'Permission denied -- only system user can update ISOCtryCcy records' );	\
			end if;	\
		end if;	\
	\
		select	\
			ISOCtryId,	\
			ISOCcyId,	\
			revision	\
		into	\
			oldISOCtryId,	\
			oldISOCcyId,	\
			oldRevision	\
		from cfsec213.iso_cntryccy	\
		where	\
			ISOCtryId = argISOCtryId	\
			and ISOCcyId = argISOCcyId	\
		for update;	\
	\
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_iso_cntryccy() Data collision detected' );	\
		end if;	\
	\
		update cfsec213.iso_cntryccy	\
		set	\
			revision = argRevision + 1,	\
			updatedby = argAuditUserId,	\
			updatedat = current timestamp	\
		where	\
			isoctryid = argISOCtryId	\
		and isoccyid = argISOCcyId	\
		and revision = argRevision;	\
	\
		insert into cfsec213.iso_cntryccy_h (	\
				isoctryid,	\
				isoccyid,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
			revision,	\
			auditaction )	\
		select	\
				a005.isoctryid,	\
				a005.isoccyid,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
			a005.revision,	\
			2	\
		from cfsec213.iso_cntryccy as a005	\
		where	\
			a005.isoctryid = argISOCtryId	\
		and a005.isoccyid = argISOCcyId;	\
	\
		open retcursor;	\
	end;	\
end
