--
--	@(#) dbcreate/cfsec/oracle/crdl_secsess.plsql
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

create or replace procedure cfsec213.dl_secsess(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argSecSessionId varchar2,
	argRevision int ) authid definer
is
	oldSecSessionId varchar2(36);
	oldSecUserId varchar2(36);
	oldSecDevName varchar2(127);
	oldstart_ts timestamp;
	oldfinish_ts timestamp;
	oldSecProxyId varchar2(36);
	oldRevision integer;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
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

	permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;

	delete from cfsec213.SecSess
	where
		SecSessionId = argSecSessionId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_secsess;
/

show errors procedure cfsec213.dl_secsess;
