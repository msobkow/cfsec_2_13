--
--	@(#) dbcreate/cfsec/oracle/crdl_secsessbysecdevidx.plsql
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

create or replace procedure cfsec213.dl_secsessbysecdevidx(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argSecUserId varchar2,
	argSecDevName varchar2 ) authid definer
is
	unrecognizedClassCode exception;
	permissionFlag integer;
	cursor cursNormal is
		select
			a010.SecSessionId as SecSessionId,
				a010.revision as revision
		from cfsec213.SecSess a010
		where
				a010.SecUserId = argSecUserId
			and ( ( ( argSecDevName is null ) and ( a010.SecDevName is null ) )
				or ( ( argSecDevName is not null ) and ( a010.SecDevName = argSecDevName ) ) );
begin
	for cur in cursNormal
	loop
			cfsec213.dl_secsess( argAuditClusterId,
					argAuditUserId,
					argAuditSessionId,
					secClusterId,
					secTenantId,
					cur.secsessionid,
					cur.revision );
	end loop;
end dl_secsessbysecdevidx;
/

show errors procedure cfsec213.dl_secsessbysecdevidx;
