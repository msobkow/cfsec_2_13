--
--	@(#) dbcreate/cfsec/pgsql/crsp_page_secgrpfrm_by_appidx.pgsql
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
create or replace function cfsec213.sp_page_secgrpfrm_by_appidx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClusterId bigint,
	argSecAppId integer,
	priorClusterId bigint,
	priorSecGroupFormId bigint )
returns setof cfsec213.type_secgrpfrm_rec as $$
declare
	permissionFlag boolean;
	isSystemUser boolean;
begin
	select cfsec213.sp_is_cluster_user( secClusterId,
			'ReadSecGroupForm',
			argAuditUserId ),
		cfsec213.sp_is_system_user( argAuditUserId )
	into permissionFlag, isSystemUser;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in cluster SecGroup for ReadSecGroupForm';
	end if;
	if( isSystemUser )
	then
		if( ( priorClusterId is not null )and ( priorSecGroupFormId is not null ) )
		then
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
			and a00d.secappid = argSecAppId
			and ( ( ( a00d.ClusId = priorClusterId )
					and ( a00d.SecGrpFrmId < priorSecGroupFormId ) )
				or ( ( a00d.ClusId < priorClusterId ) ) )
				order by ClusId desc,
					SecGrpFrmId desc
			limit 25;
		else
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
			and a00d.secappid = argSecAppId
				order by ClusId desc,
					SecGrpFrmId desc
			limit 25;
		end if;
	else
		if( ( priorClusterId is not null )and ( priorSecGroupFormId is not null ) )
		then
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
			and a00d.secappid = argSecAppId
				and a00d.ClusId = secClusterId
			and ( ( ( a00d.ClusId = priorClusterId )
					and ( a00d.SecGrpFrmId < priorSecGroupFormId ) )
				or ( ( a00d.ClusId < priorClusterId ) ) )
				order by ClusId desc,
					SecGrpFrmId desc
			limit 25;
		else
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
			and a00d.secappid = argSecAppId
				and a00d.ClusId = secClusterId
				order by ClusId desc,
					SecGrpFrmId desc
			limit 25;
		end if;
	end if;
	return;
end
$$ language plpgsql;
