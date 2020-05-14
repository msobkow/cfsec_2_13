--
--	@(#) dbcreate/cfsec/db2luw/crsp_create_iso_ccy.sql
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
create or replace procedure sp_create_iso_ccy(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argISOCode varchar(3),	\
	in argName varchar(64),	\
	in argUnitSymbol varchar(4),	\
	in argPrecis smallint )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
		declare argISOCcyId smallint;	\
	declare retcursor cursor with return to client for	\
		select	\
				a003.createdby as createdby,	\
				to_char( a003.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a003.updatedby as updatedby,	\
				to_char( a003.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a003.isoccyid as isoccyid,	\
			a003.iso_code as iso_code,	\
			a003.ccy_name as ccy_name,	\
			a003.unit_symbol as unit_symbol,	\
			a003.precis as precis,	\
			a003.revision as revision	\
		from cfsec213.iso_ccy as a003	\
		where	\
			a003.isoccyid = argISOCcyId;	\
	begin	\
		if( argClassCode = 'a003' )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20001, 'Permission denied -- only system user can create ISOCcy records' );	\
			end if;	\
		end if;	\
		call sp_next_isoccyidgen( argISOCcyId );	\
		insert into cfsec213.iso_ccy(	\
			createdby,	\
			createdat,	\
			updatedby,	\
			updatedat,	\
			isoccyid,	\
			iso_code,	\
			ccy_name,	\
			unit_symbol,	\
			precis,	\
			revision )	\
		values (	\
			argAuditUserId,	\
			current timestamp,	\
			argAuditUserId,	\
			current timestamp,	\
			argISOCcyId,	\
			argISOCode,	\
			argName,	\
			argUnitSymbol,	\
			argPrecis,	\
			1 );	\
	\
		insert into cfsec213.iso_ccy_h (	\
				isoccyid,	\
				auditclusterid,	\
				auditsessionid,	\
				auditstamp,	\
				iso_code,	\
				ccy_name,	\
				unit_symbol,	\
				precis,	\
				revision,	\
				auditaction )	\
		select	\
				a003.isoccyid,	\
				argAuditClusterId,	\
				argAuditSessionId,	\
				current timestamp,	\
				a003.iso_code,	\
				a003.ccy_name,	\
				a003.unit_symbol,	\
				a003.precis,	\
				a003.revision,	\
				0	\
		from cfsec213.iso_ccy as a003	\
		where	\
				a003.isoccyid = argISOCcyId;	\
	\
		open retcursor;	\
	end;	\
end
