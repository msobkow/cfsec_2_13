--
--	@(#) dbcreate/cfsec/pgsql/crsp_update_secgrpfrm.pgsql
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

create or replace function cfsec213.sp_update_secgrpfrm(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argClusterId bigint,
	argSecGroupFormId bigint,
	argSecGroupId integer,
	argSecAppId integer,
	argSecFormId integer,
	argRevision integer )
returns setof cfsec213.type_secgrpfrm_rec as $$
declare
	RowsAffected integer;
	oldClusterId bigint;
	oldSecGroupFormId bigint;
	oldSecGroupId integer;
	oldSecAppId integer;
	oldSecFormId integer;
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a00d' )
	then
		select cfsec213.sp_is_cluster_user( argClusterId,
			'UpdateSecGroupForm',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in cluster SecGroup for UpdateSecGroupForm';
		end if;
	end if;

		select
			ClusId,
			SecGrpFrmId,
			SecGrpId,
			SecAppId,
			SecFrmId,
			revision
		into
			oldClusterId,
			oldSecGroupFormId,
			oldSecGroupId,
			oldSecAppId,
			oldSecFormId,
			oldRevision
		from cfsec213.SecGrpFrm
		where
			ClusId = argClusterId
			and SecGrpFrmId = argSecGroupFormId
		for update;


	if argRevision != oldRevision
	then
		raise exception 'sp_update_secgrpfrm() Data collision detected';
	end if;


	update cfsec213.SecGrpFrm
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		secgrpid = argSecGroupId,
		secappid = argSecAppId,
		secfrmid = argSecFormId
	where
		ClusId = argClusterId
			and SecGrpFrmId = argSecGroupFormId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_secgrpfrm() Expected to affect one SecGrpFrm row, not %', RowsAffected;
	end if;


	insert into cfsec213.SecGrpFrm_h (
			ClusId,
			SecGrpFrmId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			SecGrpId,
			SecAppId,
			SecFrmId,
			revision,
			auditaction )
		select
			a00d.ClusId,
			a00d.SecGrpFrmId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a00d.SecGrpId,
			a00d.SecAppId,
			a00d.SecFrmId,
			argRevision + 1,
			1
		from cfsec213.SecGrpFrm as a00d
		where
			a00d.clusid = argClusterId
			and a00d.secgrpfrmid = argSecGroupFormId;
	return query select
			a00d.createdby,
			to_char( a00d.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00d.updatedby,
			to_char( a00d.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00d.clusid as clusid,
			a00d.secgrpfrmid as secgrpfrmid,
			a00d.secgrpid as secgrpid,
			a00d.secappid as secappid,
			a00d.secfrmid as secfrmid,
		a00d.revision as revision
	from cfsec213.SecGrpFrm as a00d
	where
		a00d.clusid = argClusterId
			and a00d.secgrpfrmid = argSecGroupFormId;

	return;
end;
$$ language plpgsql;
