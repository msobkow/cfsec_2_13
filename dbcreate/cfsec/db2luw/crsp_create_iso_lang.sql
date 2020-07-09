--
--	@(#) dbcreate/cfsec/db2luw/crsp_create_iso_lang.sql
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
create or replace procedure sp_create_iso_lang(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argISO6392Code varchar(3),	\
	in argISO6391Code varchar(2),	\
	in argEnglishName varchar(64) )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
		declare argISOLangId smallint;	\
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
				call raise_application_error( -20001, 'Permission denied -- only system user can create ISOLang records' );	\
			end if;	\
		end if;	\
		call sp_next_isolangidgen( argISOLangId );	\
		insert into cfsec213.iso_lang(	\
			createdby,	\
			createdat,	\
			updatedby,	\
			updatedat,	\
			isolangid,	\
			iso_code3,	\
			iso_code2,	\
			eng_name,	\
			revision )	\
		values (	\
			argAuditUserId,	\
			current timestamp,	\
			argAuditUserId,	\
			current timestamp,	\
			argISOLangId,	\
			argISO6392Code,	\
			argISO6391Code,	\
			argEnglishName,	\
			1 );	\
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
				0	\
		from cfsec213.iso_lang as a007	\
		where	\
				a007.isolangid = argISOLangId;	\
	\
		open retcursor;	\
	end;	\
end
