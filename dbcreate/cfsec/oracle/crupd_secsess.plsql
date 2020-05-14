--
--	@(#) dbcreate/cfsec/oracle/crupd_secsess.plsql
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


create or replace procedure cfsec213.upd_secsess(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argSecSessionId varchar2,
	argSecUserId varchar2,
	argSecDevName varchar2,
	argstart_ts timestamp,
	argfinish_ts timestamp,
	argSecProxyId varchar2,
	argRevision integer ) authid definer
is
	oldSecSessionId varchar2(36);
	oldSecUserId varchar2(36);
	oldSecDevName varchar2(127);
	oldstart_ts timestamp;
	oldfinish_ts timestamp;
	oldSecProxyId varchar2(36);
	oldRevision integer;
	dataCollision exception;
	dataUpdateFailed exception;
	permissionDenied exception;
	permissionFlag integer;
begin
		select
			SecSessionId,
			SecUserId,
			SecDevName,
			start_ts,
			finish_ts,
			SecProxyId,
			revision
		into
			oldSecSessionId,
			oldSecUserId,
			oldSecDevName,
			oldstart_ts,
			oldfinish_ts,
			oldSecProxyId,
			oldRevision
		from cfsec213.SecSess
		where
			SecSessionId = argSecSessionId
		for update;

	if argRevision != oldRevision
	then
		raise dataCollision;
	end if;

	update cfsec213.SecSess
	set
		revision = argRevision + 1,
		SecUserId = argSecUserId,
		SecDevName = argSecDevName,
		start_ts = argstart_ts,
		finish_ts = argfinish_ts,
		SecProxyId = argSecProxyId
	where
		SecSessionId = argSecSessionId
		and revision = argRevision;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;


	open retCursor for select
			a010.SecSessionId as SecSessionId,
			a010.SecUserId as SecUserId,
			a010.SecDevName as SecDevName,
			to_char( a010.start_ts, 'YYYY-MM-DD HH24:MI:SS' ) as start_ts,
			to_char( a010.finish_ts, 'YYYY-MM-DD HH24:MI:SS' ) as finish_ts,
			a010.SecProxyId as SecProxyId,
		a010.revision as revision
	from cfsec213.SecSess a010
	where
		a010.SecSessionId = argSecSessionId;
end upd_secsess;

/

show errors procedure cfsec213.upd_secsess;
