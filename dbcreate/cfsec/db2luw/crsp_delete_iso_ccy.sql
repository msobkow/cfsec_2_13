--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_iso_ccy.sql
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
create or replace procedure sp_delete_iso_ccy(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argISOCcyId smallint,	\
	in argRevision int )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldISOCcyId smallint;	\
	declare oldISOCode varchar(3);	\
	declare oldName varchar(64);	\
	declare oldUnitSymbol varchar(4);	\
	declare oldPrecis smallint;	\
	declare oldRevision int;	\
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
		select	\
			ISOCcyId,	\
			iso_code,	\
			ccy_name,	\
			unit_symbol,	\
			precis,	\
			revision	\
		into	\
			oldISOCcyId,	\
			oldISOCode,	\
			oldName,	\
			oldUnitSymbol,	\
			oldPrecis,	\
			oldRevision	\
		from cfsec213.iso_ccy	\
		where	\
			ISOCcyId = argISOCcyId	\
		for update;	\
	\
		set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20001, 'Permission denied -- only system user can delete ISOCcy records' );	\
		end if;	\
	\
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
			a003.revision + 1,	\
			2	\
		from cfsec213.iso_ccy as a003	\
		where	\
			a003.isoccyid = argISOCcyId;	\
	\
		delete from cfsec213.iso_ccy	\
		where	\
			isoccyid = argISOCcyId;	\
	\
		open retcursor;	\
	end;	\
end
