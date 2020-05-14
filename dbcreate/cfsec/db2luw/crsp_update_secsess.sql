--
--	@(#) dbcreate/cfsec/db2luw/crsp_update_secsess.sql
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

create or replace procedure sp_update_secsess(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argSecSessionId varchar(36),	\
	in argSecUserId varchar(36),	\
	in argSecDevName varchar(127),	\
	in argStart timestamp,	\
	in argFinish timestamp,	\
	in argSecProxyId varchar(36),	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldSecSessionId varchar(36);	\
	declare oldSecUserId varchar(36);	\
	declare oldSecDevName varchar(127);	\
	declare oldStart timestamp;	\
	declare oldFinish timestamp;	\
	declare oldSecProxyId varchar(36);	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select	\
				a010.secsessionid as secsessionid,	\
			a010.secuserid as secuserid,	\
			a010.secdevname as secdevname,	\
			to_char( a010.start_ts, 'YYYY-MM-DD-HH24.MI.SS' ) as start_ts,	\
			to_char( a010.finish_ts, 'YYYY-MM-DD-HH24.MI.SS' ) as finish_ts,	\
			a010.secproxyid as secproxyid,	\
			a010.revision as revision	\
		from cfsec213.SecSess as a010	\
		where	\
			a010.secsessionid = argSecSessionId;	\
	begin	\
		select	\
			SecSessionId,	\
			SecUserId,	\
			SecDevName,	\
			start_ts,	\
			finish_ts,	\
			SecProxyId,	\
			revision	\
		into	\
			oldSecSessionId,	\
			oldSecUserId,	\
			oldSecDevName,	\
			oldStart,	\
			oldFinish,	\
			oldSecProxyId,	\
			oldRevision	\
		from cfsec213.SecSess	\
		where	\
			SecSessionId = argSecSessionId	\
		for update;	\
	\
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_secsess() Data collision detected' );	\
		end if;	\
	\
		update cfsec213.SecSess	\
		set	\
			revision = argRevision + 1,	\
			secuserid = argSecUserId,	\
			secdevname = argSecDevName,	\
			start_ts = argStart,	\
			finish_ts = argFinish,	\
			secproxyid = argSecProxyId	\
		where	\
			secsessionid = argSecSessionId	\
		and revision = argRevision;	\
	\
		open retcursor;	\
	end;	\
end
