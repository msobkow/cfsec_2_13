--
--	@(#) dbcreate/cfsec/oracle/crcrt_svctype.plsql
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

create or replace procedure cfsec213.crt_svctype(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argDescription varchar2 ) authid definer
is
	permissionDenied exception;
	use_stamp cfsec213.SvcType_h.auditstamp%type;
	permissionFlag integer;
	argServiceTypeId integer;
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

	argServiceTypeId := cfsec213.nxt_servicetypeidgen();
	insert into cfsec213.svctype(
		createdby,
		createdat,
		updatedby,
		updatedat,
		ServiceTypeId,
		Description,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argServiceTypeId,
		argDescription,
		1 );
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
			a013.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a013.Description as Description,
			0,
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
end crt_svctype;
/

show errors procedure cfsec213.crt_svctype;
