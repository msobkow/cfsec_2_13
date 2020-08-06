--
--	@(#) dbcreate/cfsec/pgsql/crsp_delete_secapp.pgsql
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
create or replace function cfsec213.sp_delete_secapp(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClusterId bigint,
	argSecAppId integer,
	argRevision int )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
	oldClusterId bigint;
	oldSecAppId integer;
	oldJEEMountName varchar(192);
	oldRevision int;
	permissionFlag boolean;
begin
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

	if( oldClusterId != secClusterId )
	then
		select cfsec213.sp_is_system_user( argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- Data is not owned by logged in cluster';
		end if;
	end if;

	select cfsec213.sp_is_cluster_user( oldClusterId,
		'DeleteSecApp',
		argAuditUserId )
	into permissionFlag;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in cluster SecGroup for DeleteSecApp';
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
			2
		from cfsec213.SecApp as a009
		where
			a009.clusterid = argClusterId
			and a009.secappid = argSecAppId;

	for cur in
		select
			a00b.ClusterId,
			a00b.SecFormId
		from cfsec213.SecApp as a009
			inner join cfsec213.secform a00b on 
				a009.ClusterId = a00b.ClusterId
				and a009.SecAppId = a00b.SecAppId
		where
			a009.ClusterId = argClusterId
			and a009.SecAppId = argSecAppId
	loop
		select cfsec213.sp_delete_secform_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.SecFormId )
			into subret;
	end loop;


	delete from cfsec213.SecApp
	where
		clusterid = argClusterId
		and secappid = argSecAppId;

	get diagnostics RowsAffected = row_count;
	if RowsAffected != 1 and RowsAffected != 0
	then
		raise exception 'sp_delete_secapp() Expected to affect 1 SecApp, not %', RowsAffected;
	end if;

	return true;
end;
$$ language plpgsql;
