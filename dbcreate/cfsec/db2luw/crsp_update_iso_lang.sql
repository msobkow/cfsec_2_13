--
--	@(#) dbcreate/cfsec/db2luw/crsp_update_iso_lang.sql
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

create or replace procedure sp_update_iso_lang(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argISOLangId smallint,	\
	in argISO6392Code varchar(3),	\
	in argISO6391Code varchar(2),	\
	in argEnglishName varchar(64),	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldISOLangId smallint;	\
	declare oldISO6392Code varchar(3);	\
	declare oldISO6391Code varchar(2);	\
	declare oldEnglishName varchar(64);	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select	\
				a007.createdby as createdby,	\
				to_char( a007.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a007.updatedby as updatedby,	\
				to_char( a007.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a007.isolangid as isolangid,	\
			a007.iso_code3 as iso_code3,	\
			a007.iso_code2 as iso_code2,	\
			a007.eng_name as eng_name,	\
			a007.revision as revision	\
		from cfsec213.iso_lang as a007	\
		where	\
			a007.isolangid = argISOLangId;	\
	begin	\
		if( argClassCode = 'a007' )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20001, 'Permission denied -- only system user can update ISOLang records' );	\
			end if;	\
		end if;	\
	\
		select	\
			ISOLangId,	\
			iso_code3,	\
			iso_code2,	\
			eng_name,	\
			revision	\
		into	\
			oldISOLangId,	\
			oldISO6392Code,	\
			oldISO6391Code,	\
			oldEnglishName,	\
			oldRevision	\
		from cfsec213.iso_lang	\
		where	\
			ISOLangId = argISOLangId	\
		for update;	\
	\
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_iso_lang() Data collision detected' );	\
		end if;	\
	\
		update cfsec213.iso_lang	\
		set	\
			revision = argRevision + 1,	\
			updatedby = argAuditUserId,	\
			updatedat = current timestamp,	\
			iso_code3 = argISO6392Code,	\
			iso_code2 = argISO6391Code,	\
			eng_name = argEnglishName	\
		where	\
			isolangid = argISOLangId	\
		and revision = argRevision;	\
	\
		insert into cfsec213.iso_lang_h (	\
				isolangid,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				iso_code3,	\
				iso_code2,	\
				eng_name,	\
			revision,	\
			auditaction )	\
		select	\
				a007.isolangid,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a007.iso_code3,	\
				a007.iso_code2,	\
				a007.eng_name,	\
			a007.revision,	\
			2	\
		from cfsec213.iso_lang as a007	\
		where	\
			a007.isolangid = argISOLangId;	\
	\
		open retcursor;	\
	end;	\
end