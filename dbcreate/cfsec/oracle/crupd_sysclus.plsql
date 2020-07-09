--
--	@(#) dbcreate/cfsec/oracle/crupd_sysclus.plsql
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


create or replace procedure cfsec213.upd_sysclus(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argsgltn_id integer,
	argsys_clus_id numeric,
	argRevision integer ) authid definer
is
	oldsgltn_id integer;
	oldsys_clus_id numeric(22,0);
	oldRevision integer;
	dataCollision exception;
	dataUpdateFailed exception;
	permissionDenied exception;
	permissionFlag integer;
begin
	if( argClassCode = 'a014' )
	then
		permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

		select
			sgltn_id,
			sys_clus_id,
			revision
		into
			oldsgltn_id,
			oldsys_clus_id,
			oldRevision
		from cfsec213.sysclus
		where
			sgltn_id = argsgltn_id
		for update;

	if argRevision != oldRevision
	then
		raise dataCollision;
	end if;

	update cfsec213.sysclus
	set
		revision = argRevision + 1,
		sys_clus_id = argsys_clus_id
	where
		sgltn_id = argsgltn_id
		and revision = argRevision;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;


	open retCursor for select
			a014.sgltn_id as sgltn_id,
			a014.sys_clus_id as sys_clus_id,
		a014.revision as revision
	from cfsec213.sysclus a014
	where
		a014.sgltn_id = argsgltn_id;
end upd_sysclus;

/

show errors procedure cfsec213.upd_sysclus;
