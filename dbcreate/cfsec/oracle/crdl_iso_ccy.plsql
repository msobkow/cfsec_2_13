--
--	@(#) dbcreate/cfsec/oracle/crdl_iso_ccy.plsql
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

create or replace procedure cfsec213.dl_iso_ccy(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argISOCcyId smallint,
	argRevision int ) authid definer
is
	use_stamp cfsec213.iso_ccy_h.auditstamp%type;
	oldISOCcyId smallint;
	oldiso_code varchar2(3);
	oldccy_name varchar2(64);
	oldunit_symbol varchar2(4);
	oldprecis smallint;
	oldRevision integer;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
		select
			ISOCcyId,
			iso_code,
			ccy_name,
			unit_symbol,
			precis,
			revision
		into
			oldISOCcyId,
			oldiso_code,
			oldccy_name,
			oldunit_symbol,
			oldprecis,
			oldRevision
		from cfsec213.iso_ccy
		where
			ISOCcyId = argISOCcyId
		for update;

	permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;

	insert into cfsec213.iso_ccy_h (
			ISOCcyId,
			revision,
			auditclusterid,
			auditsessionid,
			iso_code,
			ccy_name,
			unit_symbol,
			precis,
			auditaction,
			auditstamp )
		select
			a003.ISOCcyId as ISOCcyId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a003.iso_code as iso_code,
			a003.ccy_name as ccy_name,
			a003.unit_symbol as unit_symbol,
			a003.precis as precis,
			2,
			use_stamp
		from cfsec213.iso_ccy a003
		where
			a003.ISOCcyId = argISOCcyId;

	delete from cfsec213.iso_ccy
	where
		ISOCcyId = argISOCcyId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_iso_ccy;
/

show errors procedure cfsec213.dl_iso_ccy;
