--
--	@(#) dbcreate/cfsec/pgsql/crsp_lock_isotz.pgsql
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

create or replace function cfsec213.sp_lock_isotz(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argISOTZoneId smallint )
returns setof cfsec213.type_isotz_rec as $$
begin
	return query select
			a008.createdby,
			to_char( a008.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a008.updatedby,
			to_char( a008.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a008.isotzoneid as isotzoneid,
			a008.iso8601 as iso8601,
			a008.tzname as tzname,
			a008.tzhouroffset as tzhouroffset,
			a008.tzminoffset as tzminoffset,
			a008.description as description,
			a008.visible as visible,
			a008.revision as revision
	from cfsec213.ISOTz as a008
	where
			a008.isotzoneid = argISOTZoneId
	for update;
	return;
end;
$$ language plpgsql;
