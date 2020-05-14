--
--	@(#) dbcreate/cfsec/pgsql/crsp_create_secapp.pgsql
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
create or replace function cfsec213.sp_create_secapp(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argClusterId bigint,
	argJEEMountName varchar(192) )
returns setof cfsec213.type_secapp_rec as $$
declare
	permissionFlag boolean;
	argSecAppId integer;
begin
	if( argClassCode = 'a009' )
	then
		select cfsec213.sp_is_cluster_user( argClusterId,
			'CreateSecApp',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in cluster SecGroup for CreateSecApp';
		end if;
	end if;

	select cfsec213.sp_next_secappidgen( argClusterId )
	into argSecAppId;

	insert into cfsec213.secapp(
		createdby,
		createdat,
		updatedby,
		updatedat,
		clusterid,
		secappid,
		jeemountname,
		revision )
	values (
		argAuditUserId,
		now(),
		argAuditUserId,
		now(),
		argClusterId,
		argSecAppId,
		argJEEMountName,
		1 );
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
			a009.revision,
			0
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
