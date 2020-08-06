--
--	@(#) dbcreate/cfsec/pgsql/crsp_page_secapp_by_clusteridx.pgsql
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
create or replace function cfsec213.sp_page_secapp_by_clusteridx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClusterId bigint,
	priorClusterId bigint,
	priorSecAppId integer )
returns setof cfsec213.type_secapp_rec as $$
declare
	permissionFlag boolean;
	isSystemUser boolean;
begin
	select cfsec213.sp_is_cluster_user( secClusterId,
			'ReadSecApp',
			argAuditUserId ),
		cfsec213.sp_is_system_user( argAuditUserId )
	into permissionFlag, isSystemUser;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in cluster SecGroup for ReadSecApp';
	end if;
	if( isSystemUser )
	then
		if( ( priorClusterId is not null )and ( priorSecAppId is not null ) )
		then
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
			and ( ( ( a009.ClusterId = priorClusterId )
					and ( a009.SecAppId < priorSecAppId ) )
				or ( ( a009.ClusterId < priorClusterId ) ) )
				order by ClusterId desc,
					SecAppId desc
			limit 25;
		else
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
				order by ClusterId desc,
					SecAppId desc
			limit 25;
		end if;
	else
		if( ( priorClusterId is not null )and ( priorSecAppId is not null ) )
		then
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
				and a009.ClusterId = secClusterId
			and ( ( ( a009.ClusterId = priorClusterId )
					and ( a009.SecAppId < priorSecAppId ) )
				or ( ( a009.ClusterId < priorClusterId ) ) )
				order by ClusterId desc,
					SecAppId desc
			limit 25;
		else
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
				and a009.ClusterId = secClusterId
				order by ClusterId desc,
					SecAppId desc
			limit 25;
		end if;
	end if;
	return;
end
$$ language plpgsql;
