--
--	@(#) dbcreate/cfsec/oracle/crupd_secinc.plsql
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


create or replace procedure cfsec213.upd_secinc(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argClusId numeric,
	argSecGrpIncId numeric,
	argSecGrpId integer,
	argIncGrpId integer,
	argRevision integer ) authid definer
is
	use_stamp cfsec213.SecInc_h.auditstamp%type;
	oldClusId numeric(22,0);
	oldSecGrpIncId numeric(22,0);
	oldSecGrpId integer;
	oldIncGrpId integer;
	oldRevision integer;
	dataCollision exception;
	dataUpdateFailed exception;
	permissionDenied exception;
	permissionFlag integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a00e' )
	then
		permissionFlag := cfsec213.sp_is_cluster_user( argClusId,
			'UpdateSecGrpInc',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

		select
			ClusId,
			SecGrpIncId,
			SecGrpId,
			IncGrpId,
			revision
		into
			oldClusId,
			oldSecGrpIncId,
			oldSecGrpId,
			oldIncGrpId,
			oldRevision
		from cfsec213.SecInc
		where
			ClusId = argClusId
			and SecGrpIncId = argSecGrpIncId
		for update;

	if argRevision != oldRevision
	then
		raise dataCollision;
	end if;

	update cfsec213.SecInc
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = use_stamp,
		SecGrpId = argSecGrpId,
		IncGrpId = argIncGrpId
	where
		ClusId = argClusId
		and SecGrpIncId = argSecGrpIncId
		and revision = argRevision;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;


	insert into cfsec213.SecInc_h (
			ClusId,
			SecGrpIncId,
			revision,
			auditclusterid,
			auditsessionid,
			SecGrpId,
			IncGrpId,
			auditaction,
			auditstamp )
		select
			a00e.ClusId as ClusId,
			a00e.SecGrpIncId as SecGrpIncId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a00e.SecGrpId as SecGrpId,
			a00e.IncGrpId as IncGrpId,
			1,
			use_stamp
		from cfsec213.SecInc a00e
		where
			a00e.ClusId = argClusId
			and a00e.SecGrpIncId = argSecGrpIncId;

	open retCursor for select
			a00e.createdby,
			to_char( a00e.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00e.updatedby,
			to_char( a00e.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00e.ClusId as ClusId,
			a00e.SecGrpIncId as SecGrpIncId,
			a00e.SecGrpId as SecGrpId,
			a00e.IncGrpId as IncGrpId,
		a00e.revision as revision
	from cfsec213.SecInc a00e
	where
		a00e.ClusId = argClusId
			and a00e.SecGrpIncId = argSecGrpIncId;
end upd_secinc;

/

show errors procedure cfsec213.upd_secinc;
