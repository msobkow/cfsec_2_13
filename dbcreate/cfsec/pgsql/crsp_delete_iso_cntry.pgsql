--
--	@(#) dbcreate/cfsec/pgsql/crsp_delete_iso_cntry.pgsql
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
create or replace function cfsec213.sp_delete_iso_cntry(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argISOCtryId smallint,
	argRevision int )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
	oldISOCtryId smallint;
	oldISOCode varchar(2);
	oldName varchar(64);
	oldRevision int;
	permissionFlag boolean;
begin
		select
			ISOCtryId,
			iso_code,
			country_name,
			revision
		into
			oldISOCtryId,
			oldISOCode,
			oldName,
			oldRevision
		from cfsec213.iso_cntry
		where
			ISOCtryId = argISOCtryId
		for update;

	select cfsec213.sp_is_system_user( argAuditUserId ) into permissionFlag;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- only system user can delete ISOCtry records';
	end if;

	insert into cfsec213.iso_cntry_h (
			ISOCtryId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			iso_code,
			country_name,
			revision,
			auditaction )
		select
			a004.ISOCtryId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a004.iso_code,
			a004.country_name,
			argRevision + 1,
			2
		from cfsec213.iso_cntry as a004
		where
			a004.isoctryid = argISOCtryId;

	for cur in
		select
			a006.ISOCtryId,
			a006.ISOLangId
		from cfsec213.iso_cntry as a004
			inner join cfsec213.iso_cntrylng a006 on 
				a004.ISOCtryId = a006.ISOCtryId
		where
			a004.ISOCtryId = argISOCtryId
	loop
		select cfsec213.sp_delete_iso_cntrylng_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ISOCtryId,
				cur.ISOLangId )
			into subret;
	end loop;

	for cur in
		select
			a005.ISOCtryId,
			a005.ISOCcyId
		from cfsec213.iso_cntry as a004
			inner join cfsec213.iso_cntryccy a005 on 
				a004.ISOCtryId = a005.ISOCtryId
		where
			a004.ISOCtryId = argISOCtryId
	loop
		select cfsec213.sp_delete_iso_cntryccy_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ISOCtryId,
				cur.ISOCcyId )
			into subret;
	end loop;


	delete from cfsec213.iso_cntry
	where
		isoctryid = argISOCtryId;

	get diagnostics RowsAffected = row_count;
	if RowsAffected != 1 and RowsAffected != 0
	then
		raise exception 'sp_delete_iso_cntry() Expected to affect 1 iso_cntry, not %', RowsAffected;
	end if;

	return true;
end;
$$ language plpgsql;
