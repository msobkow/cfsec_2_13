--
--	@(#) dbcreate/cfsec/oracle/crupd_svctype.plsql
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


create or replace procedure cfsec213.upd_svctype(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argServiceTypeId integer,
	argDescription varchar2,
	argRevision integer ) authid definer
is
	use_stamp cfsec213.SvcType_h.auditstamp%type;
	oldServiceTypeId integer;
	oldDescription varchar2(50);
	oldRevision integer;
	dataCollision exception;
	dataUpdateFailed exception;
	permissionDenied exception;
	permissionFlag integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a013' )
	then
		permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

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

	if argRevision != oldRevision
	then
		raise dataCollision;
	end if;

	update cfsec213.SvcType
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = use_stamp,
		Description = argDescription
	where
		ServiceTypeId = argServiceTypeId
		and revision = argRevision;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
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
			1,
			use_stamp
		from cfsec213.SvcType a013
		where
			a013.ServiceTypeId = argServiceTypeId;

	open retCursor for select
			a013.createdby,
			to_char( a013.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a013.updatedby,
			to_char( a013.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a013.ServiceTypeId as ServiceTypeId,
			a013.Description as Description,
		a013.revision as revision
	from cfsec213.SvcType a013
	where
		a013.ServiceTypeId = argServiceTypeId;
end upd_svctype;

/

show errors procedure cfsec213.upd_svctype;
