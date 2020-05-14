--
--	@(#) dbcreate/cfsec/oracle/crcrt_tsecmemb.plsql
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

create or replace procedure cfsec213.crt_tsecmemb(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argTenantId numeric,
	argTSecGroupId integer,
	argSecUserId varchar2 ) authid definer
is
	permissionDenied exception;
	use_stamp cfsec213.TSecMemb_h.auditstamp%type;
	permissionFlag integer;
	argTSecGrpMembId numeric;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a018' )
	then
		permissionFlag := cfsec213.sp_is_tenant_user( argTenantId,
			'CreateTSecGrpMemb',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	argTSecGrpMembId := cfsec213.nxt_tsecgrpmembidgen( argTenantId );
	insert into cfsec213.tsecmemb(
		createdby,
		createdat,
		updatedby,
		updatedat,
		TenantId,
		TSecGrpMembId,
		TSecGroupId,
		SecUserId,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argTenantId,
		argTSecGrpMembId,
		argTSecGroupId,
		argSecUserId,
		1 );
	insert into cfsec213.TSecMemb_h (
			TenantId,
			TSecGrpMembId,
			revision,
			auditclusterid,
			auditsessionid,
			TSecGroupId,
			SecUserId,
			auditaction,
			auditstamp )
		select
			a018.TenantId as TenantId,
			a018.TSecGrpMembId as TSecGrpMembId,
			a018.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a018.TSecGroupId as TSecGroupId,
			a018.SecUserId as SecUserId,
			0,
			use_stamp
		from cfsec213.TSecMemb a018
		where
			a018.TenantId = argTenantId
			and a018.TSecGrpMembId = argTSecGrpMembId;

	open retCursor for select
			a018.createdby,
			to_char( a018.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a018.updatedby,
			to_char( a018.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a018.TenantId as TenantId,
			a018.TSecGrpMembId as TSecGrpMembId,
			a018.TSecGroupId as TSecGroupId,
			a018.SecUserId as SecUserId,
		a018.revision as revision
	from cfsec213.TSecMemb a018
	where
		a018.TenantId = argTenantId
			and a018.TSecGrpMembId = argTSecGrpMembId;
end crt_tsecmemb;
/

show errors procedure cfsec213.crt_tsecmemb;
