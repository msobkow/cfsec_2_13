--
--	@(#) dbcreate/cfsec/pgsql/crsp_delete_secdev.pgsql
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
create or replace function cfsec213.sp_delete_secdev(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argSecUserId varchar(36),
	argDevName varchar(127),
	argRevision int )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
	oldSecUserId varchar(36);
	oldDevName varchar(127);
	oldPubKey text;
	oldRevision int;
	permissionFlag boolean;
begin
		select
			SecUserId,
			DevName,
			PubKey,
			revision
		into
			oldSecUserId,
			oldDevName,
			oldPubKey,
			oldRevision
		from cfsec213.SecDev
		where
			SecUserId = argSecUserId
			and DevName = argDevName
		for update;

	select cfsec213.sp_is_system_user( argAuditUserId ) into permissionFlag;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- only system user can delete SecDevice records';
	end if;

	insert into cfsec213.SecDev_h (
			SecUserId,
			DevName,
			auditclusterid,
			auditsessionid,
			auditstamp,
			PubKey,
			revision,
			auditaction )
		select
			a00a.SecUserId,
			a00a.DevName,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a00a.PubKey,
			argRevision + 1,
			2
		from cfsec213.SecDev as a00a
		where
			a00a.secuserid = argSecUserId
			and a00a.devname = argDevName;


	delete from cfsec213.SecDev
	where
		secuserid = argSecUserId
		and devname = argDevName;

	get diagnostics RowsAffected = row_count;
	if RowsAffected != 1 and RowsAffected != 0
	then
		raise exception 'sp_delete_secdev() Expected to affect 1 SecDev, not %', RowsAffected;
	end if;

	return true;
end;
$$ language plpgsql;
