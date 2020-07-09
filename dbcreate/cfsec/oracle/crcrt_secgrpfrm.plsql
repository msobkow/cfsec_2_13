--
--	@(#) dbcreate/cfsec/oracle/crcrt_secgrpfrm.plsql
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

create or replace procedure cfsec213.crt_secgrpfrm(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argClusId numeric,
	argSecGrpId integer,
	argSecAppId integer,
	argSecFrmId integer ) authid definer
is
	permissionDenied exception;
	use_stamp cfsec213.SecGrpFrm_h.auditstamp%type;
	permissionFlag integer;
	argSecGrpFrmId numeric;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a00d' )
	then
		permissionFlag := cfsec213.sp_is_cluster_user( argClusId,
			'CreateSecGroupForm',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	argSecGrpFrmId := cfsec213.nxt_secgroupformidgen( argClusId );
	insert into cfsec213.secgrpfrm(
		createdby,
		createdat,
		updatedby,
		updatedat,
		ClusId,
		SecGrpFrmId,
		SecGrpId,
		SecAppId,
		SecFrmId,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argClusId,
		argSecGrpFrmId,
		argSecGrpId,
		argSecAppId,
		argSecFrmId,
		1 );
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
			a00d.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a00d.SecGrpId as SecGrpId,
			a00d.SecAppId as SecAppId,
			a00d.SecFrmId as SecFrmId,
			0,
			use_stamp
		from cfsec213.SecGrpFrm a00d
		where
			a00d.ClusId = argClusId
			and a00d.SecGrpFrmId = argSecGrpFrmId;

	open retCursor for select
			a00d.createdby,
			to_char( a00d.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00d.updatedby,
			to_char( a00d.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00d.ClusId as ClusId,
			a00d.SecGrpFrmId as SecGrpFrmId,
			a00d.SecGrpId as SecGrpId,
			a00d.SecAppId as SecAppId,
			a00d.SecFrmId as SecFrmId,
		a00d.revision as revision
	from cfsec213.SecGrpFrm a00d
	where
		a00d.ClusId = argClusId
			and a00d.SecGrpFrmId = argSecGrpFrmId;
end crt_secgrpfrm;
/

show errors procedure cfsec213.crt_secgrpfrm;
