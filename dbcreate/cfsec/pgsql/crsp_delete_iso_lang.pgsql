--
--	@(#) dbcreate/cfsec/pgsql/crsp_delete_iso_lang.pgsql
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
create or replace function cfsec213.sp_delete_iso_lang(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argISOLangId smallint,
	argRevision int )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
	oldISOLangId smallint;
	oldISO6392Code varchar(3);
	oldISO6391Code varchar(2);
	oldEnglishName varchar(64);
	oldRevision int;
	permissionFlag boolean;
begin
		select
			ISOLangId,
			iso_code3,
			iso_code2,
			eng_name,
			revision
		into
			oldISOLangId,
			oldISO6392Code,
			oldISO6391Code,
			oldEnglishName,
			oldRevision
		from cfsec213.iso_lang
		where
			ISOLangId = argISOLangId
		for update;

	select cfsec213.sp_is_system_user( argAuditUserId ) into permissionFlag;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- only system user can delete ISOLang records';
	end if;

	insert into cfsec213.iso_lang_h (
			ISOLangId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			iso_code3,
			iso_code2,
			eng_name,
			revision,
			auditaction )
		select
			a007.ISOLangId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a007.iso_code3,
			a007.iso_code2,
			a007.eng_name,
			argRevision + 1,
			2
		from cfsec213.iso_lang as a007
		where
			a007.isolangid = argISOLangId;


	delete from cfsec213.iso_lang
	where
		isolangid = argISOLangId;

	get diagnostics RowsAffected = row_count;
	if RowsAffected != 1 and RowsAffected != 0
	then
		raise exception 'sp_delete_iso_lang() Expected to affect 1 iso_lang, not %', RowsAffected;
	end if;

	return true;
end;
$$ language plpgsql;
