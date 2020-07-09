--
--	@(#) dbcreate/cfsec/pgsql/crsp_update_secdev.pgsql
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

create or replace function cfsec213.sp_update_secdev(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argSecUserId varchar(36),
	argDevName varchar(127),
	argPubKey text,
	argRevision integer )
returns setof cfsec213.type_secdev_rec as $$
declare
	RowsAffected integer;
	oldSecUserId varchar(36);
	oldDevName varchar(127);
	oldPubKey text;
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a00a' )
	then
		select cfsec213.sp_is_system_user( argAuditUserId ) into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- only system user can update SecDevice records';
		end if;
	end if;

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


	if argRevision != oldRevision
	then
		raise exception 'sp_update_secdev() Data collision detected';
	end if;


	update cfsec213.SecDev
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		pubkey = argPubKey
	where
		SecUserId = argSecUserId
			and DevName = argDevName
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_secdev() Expected to affect one SecDev row, not %', RowsAffected;
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
			1
		from cfsec213.SecDev as a00a
		where
			a00a.secuserid = argSecUserId
			and a00a.devname = argDevName;
	return query select
			a00a.createdby,
			to_char( a00a.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00a.updatedby,
			to_char( a00a.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00a.secuserid as secuserid,
			a00a.devname as devname,
			a00a.pubkey as pubkey,
		a00a.revision as revision
	from cfsec213.SecDev as a00a
	where
		a00a.secuserid = argSecUserId
			and a00a.devname = argDevName;

	return;
end;
$$ language plpgsql;
