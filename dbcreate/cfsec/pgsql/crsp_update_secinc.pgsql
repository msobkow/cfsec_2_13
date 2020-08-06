--
--	@(#) dbcreate/cfsec/pgsql/crsp_update_secinc.pgsql
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

create or replace function cfsec213.sp_update_secinc(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argClusterId bigint,
	argSecGrpIncId bigint,
	argSecGroupId integer,
	argIncludeGroupId integer,
	argRevision integer )
returns setof cfsec213.type_secinc_rec as $$
declare
	RowsAffected integer;
	oldClusterId bigint;
	oldSecGrpIncId bigint;
	oldSecGroupId integer;
	oldIncludeGroupId integer;
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a00e' )
	then
		select cfsec213.sp_is_cluster_user( argClusterId,
			'UpdateSecGrpInc',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in cluster SecGroup for UpdateSecGrpInc';
		end if;
	end if;

		select
			ClusId,
			SecGrpIncId,
			SecGrpId,
			IncGrpId,
			revision
		into
			oldClusterId,
			oldSecGrpIncId,
			oldSecGroupId,
			oldIncludeGroupId,
			oldRevision
		from cfsec213.SecInc
		where
			ClusId = argClusterId
			and SecGrpIncId = argSecGrpIncId
		for update;


	if argRevision != oldRevision
	then
		raise exception 'sp_update_secinc() Data collision detected';
	end if;


	update cfsec213.SecInc
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		secgrpid = argSecGroupId,
		incgrpid = argIncludeGroupId
	where
		ClusId = argClusterId
			and SecGrpIncId = argSecGrpIncId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_secinc() Expected to affect one SecInc row, not %', RowsAffected;
	end if;


	insert into cfsec213.SecInc_h (
			ClusId,
			SecGrpIncId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			SecGrpId,
			IncGrpId,
			revision,
			auditaction )
		select
			a00e.ClusId,
			a00e.SecGrpIncId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a00e.SecGrpId,
			a00e.IncGrpId,
			argRevision + 1,
			1
		from cfsec213.SecInc as a00e
		where
			a00e.clusid = argClusterId
			and a00e.secgrpincid = argSecGrpIncId;
	return query select
			a00e.createdby,
			to_char( a00e.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00e.updatedby,
			to_char( a00e.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00e.clusid as clusid,
			a00e.secgrpincid as secgrpincid,
			a00e.secgrpid as secgrpid,
			a00e.incgrpid as incgrpid,
		a00e.revision as revision
	from cfsec213.SecInc as a00e
	where
		a00e.clusid = argClusterId
			and a00e.secgrpincid = argSecGrpIncId;

	return;
end;
$$ language plpgsql;
