--
--	@(#) dbcreate/cfsec/oracle/crcrt_tsecinc.plsql
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

create or replace procedure cfsec213.crt_tsecinc(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argTenantId numeric,
	argTSecGrpId integer,
	argIncGrpId integer ) authid definer
is
	permissionDenied exception;
	use_stamp cfsec213.TSecInc_h.auditstamp%type;
	permissionFlag integer;
	argTSecGrpIncId numeric;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a017' )
	then
		permissionFlag := cfsec213.sp_is_tenant_user( argTenantId,
			'CreateTSecGrpInc',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	argTSecGrpIncId := cfsec213.nxt_tsecgrpincidgen( argTenantId );
	insert into cfsec213.tsecinc(
		createdby,
		createdat,
		updatedby,
		updatedat,
		TenantId,
		TSecGrpIncId,
		TSecGrpId,
		IncGrpId,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argTenantId,
		argTSecGrpIncId,
		argTSecGrpId,
		argIncGrpId,
		1 );
	insert into cfsec213.TSecInc_h (
			TenantId,
			TSecGrpIncId,
			revision,
			auditclusterid,
			auditsessionid,
			TSecGrpId,
			IncGrpId,
			auditaction,
			auditstamp )
		select
			a017.TenantId as TenantId,
			a017.TSecGrpIncId as TSecGrpIncId,
			a017.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a017.TSecGrpId as TSecGrpId,
			a017.IncGrpId as IncGrpId,
			0,
			use_stamp
		from cfsec213.TSecInc a017
		where
			a017.TenantId = argTenantId
			and a017.TSecGrpIncId = argTSecGrpIncId;

	open retCursor for select
			a017.createdby,
			to_char( a017.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a017.updatedby,
			to_char( a017.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a017.TenantId as TenantId,
			a017.TSecGrpIncId as TSecGrpIncId,
			a017.TSecGrpId as TSecGrpId,
			a017.IncGrpId as IncGrpId,
		a017.revision as revision
	from cfsec213.TSecInc a017
	where
		a017.TenantId = argTenantId
			and a017.TSecGrpIncId = argTSecGrpIncId;
end crt_tsecinc;
/

show errors procedure cfsec213.crt_tsecinc;
