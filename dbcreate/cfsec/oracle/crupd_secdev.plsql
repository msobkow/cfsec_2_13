--
--	@(#) dbcreate/cfsec/oracle/crupd_secdev.plsql
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


create or replace procedure cfsec213.upd_secdev(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argSecUserId varchar2,
	argDevName varchar2,
	argPubKey clob,
	argRevision integer ) authid definer
is
	use_stamp cfsec213.SecDev_h.auditstamp%type;
	oldSecUserId varchar2(36);
	oldDevName varchar2(127);
	oldPubKey clob;
	oldRevision integer;
	dataCollision exception;
	dataUpdateFailed exception;
	permissionDenied exception;
	permissionFlag integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a00a' )
	then
		permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

		select
			SecUserId,
			DevName,
			PubKey,
			revision
		into
			oldSecUserId,
			oldDevName,
			oldPubKey,
			oldRevision
		from cfsec213.SecDev
		where
			SecUserId = argSecUserId
			and DevName = argDevName
		for update;

	if argRevision != oldRevision
	then
		raise dataCollision;
	end if;

	update cfsec213.SecDev
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = use_stamp,
		PubKey = argPubKey
	where
		SecUserId = argSecUserId
		and DevName = argDevName
		and revision = argRevision;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;


	insert into cfsec213.SecDev_h (
			SecUserId,
			DevName,
			revision,
			auditclusterid,
			auditsessionid,
			PubKey,
			auditaction,
			auditstamp )
		select
			a00a.SecUserId as SecUserId,
			a00a.DevName as DevName,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a00a.PubKey as PubKey,
			1,
			use_stamp
		from cfsec213.SecDev a00a
		where
			a00a.SecUserId = argSecUserId
			and a00a.DevName = argDevName;

	open retCursor for select
			a00a.createdby,
			to_char( a00a.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00a.updatedby,
			to_char( a00a.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00a.SecUserId as SecUserId,
			a00a.DevName as DevName,
			a00a.PubKey as PubKey,
		a00a.revision as revision
	from cfsec213.SecDev a00a
	where
		a00a.SecUserId = argSecUserId
			and a00a.DevName = argDevName;
end upd_secdev;

/

show errors procedure cfsec213.upd_secdev;
