--
--	@(#) dbcreate/cfsec/db2luw/crsp_create_iso_ccy.sql
--
--	org.msscf.msscf.CFSec
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	MSS Code Factory CFSec 2.13 Security Essentials
--	
--	Copyright 2020 Mark Stephen Sobkow
--	
--		This file is part of MSS Code Factory.
--	
--		MSS Code Factory is available under dual commercial license from Mark Stephen
--		Sobkow, or under the terms of the GNU General Public License, Version 3
--		or later.
--	
--	    MSS Code Factory is free software: you can redistribute it and/or modify
--	    it under the terms of the GNU General Public License as published by
--	    the Free Software Foundation, either version 3 of the License, or
--	    (at your option) any later version.
--	
--	    MSS Code Factory is distributed in the hope that it will be useful,
--	    but WITHOUT ANY WARRANTY; without even the implied warranty of
--	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--	    GNU General Public License for more details.
--	
--	    You should have received a copy of the GNU General Public License
--	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
--	
--	Donations to support MSS Code Factory can be made at
--	https://www.paypal.com/paypalme2/MarkSobkow
--	
--	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
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
