--
--	@(#) dbcreate/cfsec/pgsql/crsp_create_secgrp.pgsql
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
create or replace function cfsec213.sp_create_secgrp(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argClusterId bigint,
	argName varchar(64),
	argIsVisible boolean )
returns setof cfsec213.type_secgrp_rec as $$
declare
	permissionFlag boolean;
	argSecGroupId integer;
begin
	if( argClassCode = 'a00c' )
	then
		select cfsec213.sp_is_cluster_user( argClusterId,
			'CreateSecGroup',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in cluster SecGroup for CreateSecGroup';
		end if;
	end if;

	select cfsec213.sp_next_secgroupidgen( argClusterId )
	into argSecGroupId;

	insert into cfsec213.secgrp(
		createdby,
		createdat,
		updatedby,
		updatedat,
		clusterid,
		secgroupid,
		safe_name,
		isvisible,
		revision )
	values (
		argAuditUserId,
		now(),
		argAuditUserId,
		now(),
		argClusterId,
		argSecGroupId,
		argName,
		argIsVisible,
		1 );
	insert into cfsec213.SecGrp_h (
			ClusterId,
			SecGroupId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			safe_name,
			IsVisible,
			revision,
			auditaction )
		select
			a00c.ClusterId,
			a00c.SecGroupId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a00c.safe_name,
			a00c.IsVisible,
			a00c.revision,
			0
		from cfsec213.SecGrp as a00c
		where
			a00c.clusterid = argClusterId
			and a00c.secgroupid = argSecGroupId;

	return query select
			a00c.createdby,
			to_char( a00c.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00c.updatedby,
			to_char( a00c.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00c.clusterid as clusterid,
			a00c.secgroupid as secgroupid,
			a00c.safe_name as safe_name,
			a00c.isvisible as isvisible,
			a00c.revision as revision
	from cfsec213.SecGrp as a00c
	where
			a00c.clusterid = argClusterId
			and a00c.secgroupid = argSecGroupId;

	return;
end;
$$ language plpgsql;
