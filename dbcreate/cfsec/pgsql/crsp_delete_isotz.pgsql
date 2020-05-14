--
--	@(#) dbcreate/cfsec/pgsql/crsp_delete_isotz.pgsql
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
create or replace function cfsec213.sp_delete_isotz(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argISOTZoneId smallint,
	argRevision int )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
	oldISOTZoneId smallint;
	oldIso8601 varchar(6);
	oldTZName varchar(64);
	oldTZHourOffset smallint;
	oldTZMinOffset smallint;
	oldDescription varchar(128);
	oldVisible boolean;
	oldRevision int;
	permissionFlag boolean;
begin
		select
			ISOTZoneId,
			Iso8601,
			TZName,
			TZHourOffset,
			TZMinOffset,
			Description,
			Visible,
			revision
		into
			oldISOTZoneId,
			oldIso8601,
			oldTZName,
			oldTZHourOffset,
			oldTZMinOffset,
			oldDescription,
			oldVisible,
			oldRevision
		from cfsec213.ISOTz
		where
			ISOTZoneId = argISOTZoneId
		for update;

	select cfsec213.sp_is_system_user( argAuditUserId ) into permissionFlag;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- only system user can delete ISOTZone records';
	end if;

	insert into cfsec213.ISOTz_h (
			ISOTZoneId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			Iso8601,
			TZName,
			TZHourOffset,
			TZMinOffset,
			Description,
			Visible,
			revision,
			auditaction )
		select
			a008.ISOTZoneId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a008.Iso8601,
			a008.TZName,
			a008.TZHourOffset,
			a008.TZMinOffset,
			a008.Description,
			a008.Visible,
			argRevision + 1,
			2
		from cfsec213.ISOTz as a008
		where
			a008.isotzoneid = argISOTZoneId;


	delete from cfsec213.ISOTz
	where
		isotzoneid = argISOTZoneId;

	get diagnostics RowsAffected = row_count;
	if RowsAffected != 1 and RowsAffected != 0
	then
		raise exception 'sp_delete_isotz() Expected to affect 1 ISOTz, not %', RowsAffected;
	end if;

	return true;
end;
$$ language plpgsql;
