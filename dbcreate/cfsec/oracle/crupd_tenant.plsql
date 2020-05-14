--
--	@(#) dbcreate/cfsec/oracle/crupd_tenant.plsql
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


create or replace procedure cfsec213.upd_tenant(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argClusterId numeric,
	argId numeric,
	argTenantName varchar2,
	argRevision integer ) authid definer
is
	use_stamp cfsec213.tenant_h.auditstamp%type;
	oldClusterId numeric(22,0);
	oldId numeric(22,0);
	oldTenantName varchar2(192);
	oldRevision integer;
	dataCollision exception;
	dataUpdateFailed exception;
	permissionDenied exception;
	permissionFlag integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a015' )
	then
		permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

		select
			ClusterId,
			Id,
			TenantName,
			revision
		into
			oldClusterId,
			oldId,
			oldTenantName,
			oldRevision
		from cfsec213.tenant
		where
			Id = argId
		for update;

	if argRevision != oldRevision
	then
		raise dataCollision;
	end if;

	update cfsec213.tenant
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = use_stamp,
		ClusterId = argClusterId,
		TenantName = argTenantName
	where
		Id = argId
		and revision = argRevision;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;


	insert into cfsec213.tenant_h (
			Id,
			revision,
			auditclusterid,
			auditsessionid,
			ClusterId,
			TenantName,
			auditaction,
			auditstamp )
		select
			a015.Id as Id,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a015.ClusterId as ClusterId,
			a015.TenantName as TenantName,
			1,
			use_stamp
		from cfsec213.tenant a015
		where
			a015.Id = argId;

	open retCursor for select
			a015.createdby,
			to_char( a015.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a015.updatedby,
			to_char( a015.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a015.ClusterId as ClusterId,
			a015.Id as Id,
			a015.TenantName as TenantName,
		a015.revision as revision
	from cfsec213.tenant a015
	where
		a015.Id = argId;
end upd_tenant;

/

show errors procedure cfsec213.upd_tenant;
