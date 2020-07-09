--
--	@(#) dbcreate/cfsec/oracle/crdl_tsecgrp.plsql
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

create or replace procedure cfsec213.dl_tsecgrp(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argTenantId numeric,
	argTSecGroupId integer,
	argRevision int ) authid definer
is
	use_stamp cfsec213.TSecGrp_h.auditstamp%type;
	oldTenantId numeric(22,0);
	oldTSecGroupId integer;
	oldsafe_name varchar2(64);
	oldIsVisible char(1);
	oldRevision integer;
	cursor cursDelIncludedByGroup is
		select
			a017.TenantId,
			a017.TSecGrpIncId
		from cfsec213.TSecGrp a016
			inner join cfsec213.tsecinc a017 on
				a016.TenantId = a017.TenantId
				and a016.TSecGroupId = a017.IncGrpId
		where
			a016.TenantId = argTenantId
			and a016.TSecGroupId = argTSecGroupId;
	cursor cursDelGrpMembs is
		select
			a018.TenantId,
			a018.TSecGrpMembId
		from cfsec213.TSecGrp a016
			inner join cfsec213.tsecmemb a018 on
				a016.TenantId = a018.TenantId
				and a016.TSecGroupId = a018.TSecGroupId
		where
			a016.TenantId = argTenantId
			and a016.TSecGroupId = argTSecGroupId;
	cursor cursDelGrpIncs is
		select
			a017.TenantId,
			a017.TSecGrpIncId
		from cfsec213.TSecGrp a016
			inner join cfsec213.tsecinc a017 on
				a016.TenantId = a017.TenantId
				and a016.TSecGroupId = a017.TSecGrpId
		where
			a016.TenantId = argTenantId
			and a016.TSecGroupId = argTSecGroupId;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
		select
			TenantId,
			TSecGroupId,
			safe_name,
			IsVisible,
			revision
		into
			oldTenantId,
			oldTSecGroupId,
			oldsafe_name,
			oldIsVisible,
			oldRevision
		from cfsec213.TSecGrp
		where
			TenantId = argTenantId
			and TSecGroupId = argTSecGroupId
		for update;

	if( oldTenantId != secTenantId )
	then
		permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	permissionFlag := cfsec213.sp_is_tenant_user( oldTenantId,
		'DeleteTSecGroup',
		argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;

	insert into cfsec213.TSecGrp_h (
			TenantId,
			TSecGroupId,
			revision,
			auditclusterid,
			auditsessionid,
			safe_name,
			IsVisible,
			auditaction,
			auditstamp )
		select
			a016.TenantId as TenantId,
			a016.TSecGroupId as TSecGroupId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a016.safe_name as safe_name,
			a016.IsVisible as IsVisible,
			2,
			use_stamp
		from cfsec213.TSecGrp a016
		where
			a016.TenantId = argTenantId
			and a016.TSecGroupId = argTSecGroupId;

	for cur in cursDelIncludedByGroup
	loop
		cfsec213.dl_tsecincbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.TenantId,
				cur.TSecGrpIncId );
	end loop;
	for cur in cursDelGrpMembs
	loop
		cfsec213.dl_tsecmembbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.TenantId,
				cur.TSecGrpMembId );
	end loop;
	for cur in cursDelGrpIncs
	loop
		cfsec213.dl_tsecincbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.TenantId,
				cur.TSecGrpIncId );
	end loop;
	delete from cfsec213.TSecGrp
	where
		TenantId = argTenantId
		and TSecGroupId = argTSecGroupId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_tsecgrp;
/

show errors procedure cfsec213.dl_tsecgrp;
