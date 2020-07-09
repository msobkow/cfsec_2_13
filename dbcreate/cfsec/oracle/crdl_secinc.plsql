--
--	@(#) dbcreate/cfsec/oracle/crdl_secinc.plsql
--
--	org.msscf.msscf.CFSec
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

create or replace procedure cfsec213.dl_secinc(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClusId numeric,
	argSecGrpIncId numeric,
	argRevision int ) authid definer
is
	use_stamp cfsec213.SecInc_h.auditstamp%type;
	oldClusId numeric(22,0);
	oldSecGrpIncId numeric(22,0);
	oldSecGrpId integer;
	oldIncGrpId integer;
	oldRevision integer;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
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

	if( oldClusId != secClusterId )
	then
		permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	permissionFlag := cfsec213.sp_is_cluster_user( oldClusId,
		'DeleteSecGrpInc',
		argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
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
			2,
			use_stamp
		from cfsec213.SecInc a00e
		where
			a00e.ClusId = argClusId
			and a00e.SecGrpIncId = argSecGrpIncId;

	delete from cfsec213.SecInc
	where
		ClusId = argClusId
		and SecGrpIncId = argSecGrpIncId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_secinc;
/

show errors procedure cfsec213.dl_secinc;
