--
--	@(#) dbcreate/cfsec/pgsql/crsp_delete_iso_cntrylng.pgsql
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
create or replace function cfsec213.sp_delete_iso_cntrylng(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argISOCtryId smallint,
	argISOLangId smallint,
	argRevision int )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
	oldISOCtryId smallint;
	oldISOLangId smallint;
	oldRevision int;
	permissionFlag boolean;
begin
		select
			ISOCtryId,
			ISOLangId,
			revision
		into
			oldISOCtryId,
			oldISOLangId,
			oldRevision
		from cfsec213.iso_cntrylng
		where
			ISOCtryId = argISOCtryId
			and ISOLangId = argISOLangId
		for update;

	select cfsec213.sp_is_system_user( argAuditUserId ) into permissionFlag;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- only system user can delete ISOCtryLang records';
	end if;

	insert into cfsec213.iso_cntrylng_h (
			ISOCtryId,
			ISOLangId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			revision,
			auditaction )
		select
			a006.ISOCtryId,
			a006.ISOLangId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			argRevision + 1,
			2
		from cfsec213.iso_cntrylng as a006
		where
			a006.isoctryid = argISOCtryId
			and a006.isolangid = argISOLangId;


	delete from cfsec213.iso_cntrylng
	where
		isoctryid = argISOCtryId
		and isolangid = argISOLangId;

	get diagnostics RowsAffected = row_count;
	if RowsAffected != 1 and RowsAffected != 0
	then
		raise exception 'sp_delete_iso_cntrylng() Expected to affect 1 iso_cntrylng, not %', RowsAffected;
	end if;

	return true;
end;
$$ language plpgsql;
