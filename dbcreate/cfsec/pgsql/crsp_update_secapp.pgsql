--
--	@(#) dbcreate/cfsec/pgsql/crsp_update_secapp.pgsql
--
--	org.msscf.msscf.CFSec
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	MSS Code Factory CFSec 2.13 Security Essentials
--	
--	Copyright 2020 Mark Stephen Sobkow
--	
--		This file is part of MSS Code Factory.
--	
--		MSS Code Factory is available under dual commercial license from Mark Stephen
--		Sobkow, or under the terms of the GNU General Public License, Version 3
--		or later.
--	
--	    MSS Code Factory is free software: you can redistribute it and/or modify
--	    it under the terms of the GNU General Public License as published by
--	    the Free Software Foundation, either version 3 of the License, or
--	    (at your option) any later version.
--	
--	    MSS Code Factory is distributed in the hope that it will be useful,
--	    but WITHOUT ANY WARRANTY; without even the implied warranty of
--	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--	    GNU General Public License for more details.
--	
--	    You should have received a copy of the GNU General Public License
--	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
--	
--	Donations to support MSS Code Factory can be made at
--	https://www.paypal.com/paypalme2/MarkSobkow
--	
--	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
--
--	Manufactured by MSS Code Factory 2.12
--

create or replace function cfsec213.sp_update_secapp(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argClusterId bigint,
	argSecAppId integer,
	argJEEMountName varchar(192),
	argRevision integer )
returns setof cfsec213.type_secapp_rec as $$
declare
	RowsAffected integer;
	oldClusterId bigint;
	oldSecAppId integer;
	oldJEEMountName varchar(192);
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a009' )
	then
		select cfsec213.sp_is_cluster_user( argClusterId,
			'UpdateSecApp',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in cluster SecGroup for UpdateSecApp';
		end if;
	end if;

		select
			ClusterId,
			SecAppId,
			JEEMountName,
			revision
		into
			oldClusterId,
			oldSecAppId,
			oldJEEMountName,
			oldRevision
		from cfsec213.SecApp
		where
			ClusterId = argClusterId
			and SecAppId = argSecAppId
		for update;


	if argRevision != oldRevision
	then
		raise exception 'sp_update_secapp() Data collision detected';
	end if;


	update cfsec213.SecApp
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		jeemountname = argJEEMountName
	where
		ClusterId = argClusterId
			and SecAppId = argSecAppId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_secapp() Expected to affect one SecApp row, not %', RowsAffected;
	end if;


	insert into cfsec213.SecApp_h (
			ClusterId,
			SecAppId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			JEEMountName,
			revision,
			auditaction )
		select
			a009.ClusterId,
			a009.SecAppId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a009.JEEMountName,
			argRevision + 1,
			1
		from cfsec213.SecApp as a009
		where
			a009.clusterid = argClusterId
			and a009.secappid = argSecAppId;
	return query select
			a009.createdby,
			to_char( a009.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a009.updatedby,
			to_char( a009.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a009.clusterid as clusterid,
			a009.secappid as secappid,
			a009.jeemountname as jeemountname,
		a009.revision as revision
	from cfsec213.SecApp as a009
	where
		a009.clusterid = argClusterId
			and a009.secappid = argSecAppId;

	return;
end;
$$ language plpgsql;
