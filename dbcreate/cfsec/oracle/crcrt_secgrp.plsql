--
--	@(#) dbcreate/cfsec/oracle/crcrt_secgrp.plsql
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

create or replace procedure cfsec213.crt_secgrp(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argClusterId numeric,
	argsafe_name varchar2,
	argIsVisible char ) authid definer
is
	permissionDenied exception;
	use_stamp cfsec213.SecGrp_h.auditstamp%type;
	permissionFlag integer;
	argSecGroupId integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a00c' )
	then
		permissionFlag := cfsec213.sp_is_cluster_user( argClusterId,
			'CreateSecGroup',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	argSecGroupId := cfsec213.nxt_secgroupidgen( argClusterId );
	insert into cfsec213.secgrp(
		createdby,
		createdat,
		updatedby,
		updatedat,
		ClusterId,
		SecGroupId,
		safe_name,
		IsVisible,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argClusterId,
		argSecGroupId,
		argsafe_name,
		argIsVisible,
		1 );
	insert into cfsec213.SecGrp_h (
			ClusterId,
			SecGroupId,
			revision,
			auditclusterid,
			auditsessionid,
			safe_name,
			IsVisible,
			auditaction,
			auditstamp )
		select
			a00c.ClusterId as ClusterId,
			a00c.SecGroupId as SecGroupId,
			a00c.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a00c.safe_name as safe_name,
			a00c.IsVisible as IsVisible,
			0,
			use_stamp
		from cfsec213.SecGrp a00c
		where
			a00c.ClusterId = argClusterId
			and a00c.SecGroupId = argSecGroupId;

	open retCursor for select
			a00c.createdby,
			to_char( a00c.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00c.updatedby,
			to_char( a00c.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00c.ClusterId as ClusterId,
			a00c.SecGroupId as SecGroupId,
			a00c.safe_name as safe_name,
			a00c.IsVisible as IsVisible,
		a00c.revision as revision
	from cfsec213.SecGrp a00c
	where
		a00c.ClusterId = argClusterId
			and a00c.SecGroupId = argSecGroupId;
end crt_secgrp;
/

show errors procedure cfsec213.crt_secgrp;
