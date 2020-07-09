--
--	@(#) dbcreate/cfsec/pgsql/crsp_delete_secsess.pgsql
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
create or replace function cfsec213.sp_delete_secsess(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argSecSessionId varchar(36),
	argRevision int )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
	oldSecSessionId varchar(36);
	oldSecUserId varchar(36);
	oldSecDevName varchar(127);
	oldStart timestamp;
	oldFinish timestamp;
	oldSecProxyId varchar(36);
	oldRevision int;
	permissionFlag boolean;
begin
		select
			SecSessionId,
			SecUserId,
			SecDevName,
			start_ts,
			finish_ts,
			SecProxyId,
			revision
		into
			oldSecSessionId,
			oldSecUserId,
			oldSecDevName,
			oldStart,
			oldFinish,
			oldSecProxyId,
			oldRevision
		from cfsec213.SecSess
		where
			SecSessionId = argSecSessionId
		for update;

	select cfsec213.sp_is_system_user( argAuditUserId ) into permissionFlag;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- only system user can delete SecSession records';
	end if;


	delete from cfsec213.SecSess
	where
		secsessionid = argSecSessionId;

	get diagnostics RowsAffected = row_count;
	if RowsAffected != 1 and RowsAffected != 0
	then
		raise exception 'sp_delete_secsess() Expected to affect 1 SecSess, not %', RowsAffected;
	end if;

	return true;
end;
$$ language plpgsql;
