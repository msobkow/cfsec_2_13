--
--	@(#) dbcreate/cfsec/pgsql/crsp_update_iso_lang.pgsql
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

create or replace function cfsec213.sp_update_iso_lang(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argISOLangId smallint,
	argISO6392Code varchar(3),
	argISO6391Code varchar(2),
	argEnglishName varchar(64),
	argRevision integer )
returns setof cfsec213.type_iso_lang_rec as $$
declare
	RowsAffected integer;
	oldISOLangId smallint;
	oldISO6392Code varchar(3);
	oldISO6391Code varchar(2);
	oldEnglishName varchar(64);
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a007' )
	then
		select cfsec213.sp_is_system_user( argAuditUserId ) into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- only system user can update ISOLang records';
		end if;
	end if;

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


	if argRevision != oldRevision
	then
		raise exception 'sp_update_iso_lang() Data collision detected';
	end if;


	update cfsec213.iso_lang
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		iso_code3 = argISO6392Code,
		iso_code2 = argISO6391Code,
		eng_name = argEnglishName
	where
		ISOLangId = argISOLangId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_iso_lang() Expected to affect one iso_lang row, not %', RowsAffected;
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
			1
		from cfsec213.iso_lang as a007
		where
			a007.isolangid = argISOLangId;
	return query select
			a007.createdby,
			to_char( a007.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a007.updatedby,
			to_char( a007.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a007.isolangid as isolangid,
			a007.iso_code3 as iso_code3,
			a007.iso_code2 as iso_code2,
			a007.eng_name as eng_name,
		a007.revision as revision
	from cfsec213.iso_lang as a007
	where
		a007.isolangid = argISOLangId;

	return;
end;
$$ language plpgsql;