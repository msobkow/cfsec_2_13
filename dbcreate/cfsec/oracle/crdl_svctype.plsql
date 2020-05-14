--
--	@(#) dbcreate/cfsec/oracle/crdl_svctype.plsql
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

create or replace procedure cfsec213.dl_svctype(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argServiceTypeId integer,
	argRevision int ) authid definer
is
	use_stamp cfsec213.SvcType_h.auditstamp%type;
	oldServiceTypeId integer;
	oldDescription varchar2(50);
	oldRevision integer;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
		select
			ServiceTypeId,
			Description,
			revision
		into
			oldServiceTypeId,
			oldDescription,
			oldRevision
		from cfsec213.SvcType
		where
			ServiceTypeId = argServiceTypeId
		for update;

	permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;

	insert into cfsec213.SvcType_h (
			ServiceTypeId,
			revision,
			auditclusterid,
			auditsessionid,
			Description,
			auditaction,
			auditstamp )
		select
			a013.ServiceTypeId as ServiceTypeId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a013.Description as Description,
			2,
			use_stamp
		from cfsec213.SvcType a013
		where
			a013.ServiceTypeId = argServiceTypeId;

	delete from cfsec213.SvcType
	where
		ServiceTypeId = argServiceTypeId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_svctype;
/

show errors procedure cfsec213.dl_svctype;
