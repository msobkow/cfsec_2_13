--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_iso_lang.sql
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
create or replace procedure sp_delete_iso_lang(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argISOLangId smallint,	\
	in argRevision int )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldISOLangId smallint;	\
	declare oldISO6392Code varchar(3);	\
	declare oldISO6391Code varchar(2);	\
	declare oldEnglishName varchar(64);	\
	declare oldRevision int;	\
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
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
		set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20001, 'Permission denied -- only system user can delete ISOLang records' );	\
		end if;	\
	\
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
			a007.revision + 1,	\
			2	\
		from cfsec213.iso_lang as a007	\
		where	\
			a007.isolangid = argISOLangId;	\
	\
		delete from cfsec213.iso_lang	\
		where	\
			isolangid = argISOLangId;	\
	\
		open retcursor;	\
	end;	\
end
