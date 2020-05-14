--
--	@(#) dbcreate/cfsec/oracle/crdl_tsecmembbyididx.plsql
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

create or replace procedure cfsec213.dl_tsecmembbyididx(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argTenantId numeric,
	argTSecGrpMembId numeric ) authid definer
is
	unrecognizedClassCode exception;
	permissionFlag integer;
	cursor cursSystem is
		select
			a018.TenantId as TenantId,
			a018.TSecGrpMembId as TSecGrpMembId,
				a018.revision as revision
		from cfsec213.TSecMemb a018
		where
				a018.TenantId = argTenantId
			and a018.TSecGrpMembId = argTSecGrpMembId;
	cursor cursRestrict is
		select
			a018.TenantId as TenantId,
			a018.TSecGrpMembId as TSecGrpMembId,
				a018.revision as revision
		from cfsec213.TSecMemb a018
		where
				a018.TenantId = argTenantId
			and a018.TSecGrpMembId = argTSecGrpMembId
				and a018.TenantId = secTenantId;
begin
	permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 1 )
	then
		for cur in cursSystem
		loop
			cfsec213.dl_tsecmemb( argAuditClusterId,
					argAuditUserId,
					argAuditSessionId,
					secClusterId,
					secTenantId,
					cur.tenantid,
					cur.tsecgrpmembid,
					cur.revision );
		end loop;
	else
		for cur in cursRestrict
		loop
			cfsec213.dl_tsecmemb( argAuditClusterId,
					argAuditUserId,
					argAuditSessionId,
					secClusterId,
					secTenantId,
					cur.tenantid,
					cur.tsecgrpmembid,
					cur.revision );
		end loop;
	end if;
end dl_tsecmembbyididx;
/

show errors procedure cfsec213.dl_tsecmembbyididx;
