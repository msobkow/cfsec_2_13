--
--	@(#) dbcreate/cfsec/pgsql/crsp_create_iso_ccy.pgsql
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
create or replace function cfsec213.sp_create_iso_ccy(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argISOCode varchar(3),
	argName varchar(64),
	argUnitSymbol varchar(4),
	argPrecis smallint )
returns setof cfsec213.type_iso_ccy_rec as $$
declare
	permissionFlag boolean;
	argISOCcyId smallint;
begin
	if( argClassCode = 'a003' )
	then
		select cfsec213.sp_is_system_user( argAuditUserId ) into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- only system user can create ISOCcy records';
		end if;
	end if;

	select cfsec213.sp_next_isoccyidgen()
	into argISOCcyId;

	insert into cfsec213.iso_ccy(
		createdby,
		createdat,
		updatedby,
		updatedat,
		isoccyid,
		iso_code,
		ccy_name,
		unit_symbol,
		precis,
		revision )
	values (
		argAuditUserId,
		now(),
		argAuditUserId,
		now(),
		argISOCcyId,
		argISOCode,
		argName,
		argUnitSymbol,
		argPrecis,
		1 );
	insert into cfsec213.iso_ccy_h (
			ISOCcyId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			iso_code,
			ccy_name,
			unit_symbol,
			precis,
			revision,
			auditaction )
		select
			a003.ISOCcyId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a003.iso_code,
			a003.ccy_name,
			a003.unit_symbol,
			a003.precis,
			a003.revision,
			0
		from cfsec213.iso_ccy as a003
		where
			a003.isoccyid = argISOCcyId;

	return query select
			a003.createdby,
			to_char( a003.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a003.updatedby,
			to_char( a003.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a003.isoccyid as isoccyid,
			a003.iso_code as iso_code,
			a003.ccy_name as ccy_name,
			a003.unit_symbol as unit_symbol,
			a003.precis as precis,
			a003.revision as revision
	from cfsec213.iso_ccy as a003
	where
			a003.isoccyid = argISOCcyId;

	return;
end;
$$ language plpgsql;
