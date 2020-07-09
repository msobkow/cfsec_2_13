--
--	@(#) dbcreate/cfsec/oracle/crdl_secmembbygroupidx.plsql
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

create or replace procedure cfsec213.dl_secmembbygroupidx(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClusterId numeric,
	argSecGroupId integer ) authid definer
is
	unrecognizedClassCode exception;
	permissionFlag integer;
	cursor cursSystem is
		select
			a00f.ClusterId as ClusterId,
			a00f.SecGrpMembId as SecGrpMembId,
				a00f.revision as revision
		from cfsec213.SecMemb a00f
		where
				a00f.ClusterId = argClusterId
			and a00f.SecGroupId = argSecGroupId;
	cursor cursRestrict is
		select
			a00f.ClusterId as ClusterId,
			a00f.SecGrpMembId as SecGrpMembId,
				a00f.revision as revision
		from cfsec213.SecMemb a00f
		where
				a00f.ClusterId = argClusterId
			and a00f.SecGroupId = argSecGroupId
				and a00f.ClusterId = secClusterId;
begin
	permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 1 )
	then
		for cur in cursSystem
		loop
			cfsec213.dl_secmemb( argAuditClusterId,
					argAuditUserId,
					argAuditSessionId,
					secClusterId,
					secTenantId,
					cur.clusterid,
					cur.secgrpmembid,
					cur.revision );
		end loop;
	else
		for cur in cursRestrict
		loop
			cfsec213.dl_secmemb( argAuditClusterId,
					argAuditUserId,
					argAuditSessionId,
					secClusterId,
					secTenantId,
					cur.clusterid,
					cur.secgrpmembid,
					cur.revision );
		end loop;
	end if;
end dl_secmembbygroupidx;
/

show errors procedure cfsec213.dl_secmembbygroupidx;
