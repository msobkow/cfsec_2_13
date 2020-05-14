--
--	@(#) dbcreate/cfsec/pgsql/crsp_create_secform.pgsql
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
create or replace function cfsec213.sp_create_secform(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argClusterId bigint,
	argSecAppId integer,
	argJEEServletMapName varchar(192) )
returns setof cfsec213.type_secform_rec as $$
declare
	permissionFlag boolean;
	argSecFormId integer;
begin
	if( argClassCode = 'a00b' )
	then
		select cfsec213.sp_is_cluster_user( argClusterId,
			'CreateSecForm',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in cluster SecGroup for CreateSecForm';
		end if;
	end if;

	select cfsec213.sp_next_secformidgen( argClusterId )
	into argSecFormId;

	insert into cfsec213.secform(
		createdby,
		createdat,
		updatedby,
		updatedat,
		clusterid,
		secformid,
		secappid,
		jeeservletmapname,
		revision )
	values (
		argAuditUserId,
		now(),
		argAuditUserId,
		now(),
		argClusterId,
		argSecFormId,
		argSecAppId,
		argJEEServletMapName,
		1 );
	insert into cfsec213.SecForm_h (
			ClusterId,
			SecFormId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			SecAppId,
			JEEServletMapName,
			revision,
			auditaction )
		select
			a00b.ClusterId,
			a00b.SecFormId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a00b.SecAppId,
			a00b.JEEServletMapName,
			a00b.revision,
			0
		from cfsec213.SecForm as a00b
		where
			a00b.clusterid = argClusterId
			and a00b.secformid = argSecFormId;

	return query select
			a00b.createdby,
			to_char( a00b.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00b.updatedby,
			to_char( a00b.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00b.clusterid as clusterid,
			a00b.secformid as secformid,
			a00b.secappid as secappid,
			a00b.jeeservletmapname as jeeservletmapname,
			a00b.revision as revision
	from cfsec213.SecForm as a00b
	where
			a00b.clusterid = argClusterId
			and a00b.secformid = argSecFormId;

	return;
end;
$$ language plpgsql;
