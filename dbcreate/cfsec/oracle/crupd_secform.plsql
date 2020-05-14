--
--	@(#) dbcreate/cfsec/oracle/crupd_secform.plsql
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


create or replace procedure cfsec213.upd_secform(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argClusterId numeric,
	argSecFormId integer,
	argSecAppId integer,
	argJEEServletMapName varchar2,
	argRevision integer ) authid definer
is
	use_stamp cfsec213.SecForm_h.auditstamp%type;
	oldClusterId numeric(22,0);
	oldSecFormId integer;
	oldSecAppId integer;
	oldJEEServletMapName varchar2(192);
	oldRevision integer;
	dataCollision exception;
	dataUpdateFailed exception;
	permissionDenied exception;
	permissionFlag integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a00b' )
	then
		permissionFlag := cfsec213.sp_is_cluster_user( argClusterId,
			'UpdateSecForm',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

		select
			ClusterId,
			SecFormId,
			SecAppId,
			JEEServletMapName,
			revision
		into
			oldClusterId,
			oldSecFormId,
			oldSecAppId,
			oldJEEServletMapName,
			oldRevision
		from cfsec213.SecForm
		where
			ClusterId = argClusterId
			and SecFormId = argSecFormId
		for update;

	if argRevision != oldRevision
	then
		raise dataCollision;
	end if;

	update cfsec213.SecForm
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = use_stamp,
		SecAppId = argSecAppId,
		JEEServletMapName = argJEEServletMapName
	where
		ClusterId = argClusterId
		and SecFormId = argSecFormId
		and revision = argRevision;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;


	insert into cfsec213.SecForm_h (
			ClusterId,
			SecFormId,
			revision,
			auditclusterid,
			auditsessionid,
			SecAppId,
			JEEServletMapName,
			auditaction,
			auditstamp )
		select
			a00b.ClusterId as ClusterId,
			a00b.SecFormId as SecFormId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a00b.SecAppId as SecAppId,
			a00b.JEEServletMapName as JEEServletMapName,
			1,
			use_stamp
		from cfsec213.SecForm a00b
		where
			a00b.ClusterId = argClusterId
			and a00b.SecFormId = argSecFormId;

	open retCursor for select
			a00b.createdby,
			to_char( a00b.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00b.updatedby,
			to_char( a00b.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00b.ClusterId as ClusterId,
			a00b.SecFormId as SecFormId,
			a00b.SecAppId as SecAppId,
			a00b.JEEServletMapName as JEEServletMapName,
		a00b.revision as revision
	from cfsec213.SecForm a00b
	where
		a00b.ClusterId = argClusterId
			and a00b.SecFormId = argSecFormId;
end upd_secform;

/

show errors procedure cfsec213.upd_secform;