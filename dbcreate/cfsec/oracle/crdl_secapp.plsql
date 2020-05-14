--
--	@(#) dbcreate/cfsec/oracle/crdl_secapp.plsql
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
alter session set plsql_warnings = 'ENABLE:ALL';
/

create or replace procedure cfsec213.dl_secapp(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClusterId numeric,
	argSecAppId integer,
	argRevision int ) authid definer
is
	use_stamp cfsec213.SecApp_h.auditstamp%type;
	oldClusterId numeric(22,0);
	oldSecAppId integer;
	oldJEEMountName varchar2(192);
	oldRevision integer;
	cursor cursDelSecAppForms is
		select
			a00b.ClusterId,
			a00b.SecFormId
		from cfsec213.SecApp a009
			inner join cfsec213.secform a00b on
				a009.ClusterId = a00b.ClusterId
				and a009.SecAppId = a00b.SecAppId
		where
			a009.ClusterId = argClusterId
			and a009.SecAppId = argSecAppId;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
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
		permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	permissionFlag := cfsec213.sp_is_cluster_user( oldClusterId,
		'DeleteSecApp',
		argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;

	insert into cfsec213.SecApp_h (
			ClusterId,
			SecAppId,
			revision,
			auditclusterid,
			auditsessionid,
			JEEMountName,
			auditaction,
			auditstamp )
		select
			a009.ClusterId as ClusterId,
			a009.SecAppId as SecAppId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a009.JEEMountName as JEEMountName,
			2,
			use_stamp
		from cfsec213.SecApp a009
		where
			a009.ClusterId = argClusterId
			and a009.SecAppId = argSecAppId;

	for cur in cursDelSecAppForms
	loop
		cfsec213.dl_secformbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.SecFormId );
	end loop;
	delete from cfsec213.SecApp
	where
		ClusterId = argClusterId
		and SecAppId = argSecAppId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_secapp;
/

show errors procedure cfsec213.dl_secapp;
