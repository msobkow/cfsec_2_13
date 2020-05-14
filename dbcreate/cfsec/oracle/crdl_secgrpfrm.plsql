--
--	@(#) dbcreate/cfsec/oracle/crdl_secgrpfrm.plsql
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

create or replace procedure cfsec213.dl_secgrpfrm(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClusId numeric,
	argSecGrpFrmId numeric,
	argRevision int ) authid definer
is
	use_stamp cfsec213.SecGrpFrm_h.auditstamp%type;
	oldClusId numeric(22,0);
	oldSecGrpFrmId numeric(22,0);
	oldSecGrpId integer;
	oldSecAppId integer;
	oldSecFrmId integer;
	oldRevision integer;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
		select
			ClusId,
			SecGrpFrmId,
			SecGrpId,
			SecAppId,
			SecFrmId,
			revision
		into
			oldClusId,
			oldSecGrpFrmId,
			oldSecGrpId,
			oldSecAppId,
			oldSecFrmId,
			oldRevision
		from cfsec213.SecGrpFrm
		where
			ClusId = argClusId
			and SecGrpFrmId = argSecGrpFrmId
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
		'DeleteSecGroupForm',
		argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;

	insert into cfsec213.SecGrpFrm_h (
			ClusId,
			SecGrpFrmId,
			revision,
			auditclusterid,
			auditsessionid,
			SecGrpId,
			SecAppId,
			SecFrmId,
			auditaction,
			auditstamp )
		select
			a00d.ClusId as ClusId,
			a00d.SecGrpFrmId as SecGrpFrmId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a00d.SecGrpId as SecGrpId,
			a00d.SecAppId as SecAppId,
			a00d.SecFrmId as SecFrmId,
			2,
			use_stamp
		from cfsec213.SecGrpFrm a00d
		where
			a00d.ClusId = argClusId
			and a00d.SecGrpFrmId = argSecGrpFrmId;

	delete from cfsec213.SecGrpFrm
	where
		ClusId = argClusId
		and SecGrpFrmId = argSecGrpFrmId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_secgrpfrm;
/

show errors procedure cfsec213.dl_secgrpfrm;
