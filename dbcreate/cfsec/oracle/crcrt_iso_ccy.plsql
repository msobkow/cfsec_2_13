--
--	@(#) dbcreate/cfsec/oracle/crcrt_iso_ccy.plsql
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
alter session set plsql_warnings = 'ENABLE:ALL';
/

create or replace procedure cfsec213.crt_iso_ccy(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argiso_code varchar2,
	argccy_name varchar2,
	argunit_symbol varchar2,
	argprecis smallint ) authid definer
is
	permissionDenied exception;
	use_stamp cfsec213.iso_ccy_h.auditstamp%type;
	permissionFlag integer;
	argISOCcyId smallint;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a003' )
	then
		permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	argISOCcyId := cfsec213.nxt_isoccyidgen();
	insert into cfsec213.iso_ccy(
		createdby,
		createdat,
		updatedby,
		updatedat,
		ISOCcyId,
		iso_code,
		ccy_name,
		unit_symbol,
		precis,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argISOCcyId,
		argiso_code,
		argccy_name,
		argunit_symbol,
		argprecis,
		1 );
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
			a003.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a003.iso_code as iso_code,
			a003.ccy_name as ccy_name,
			a003.unit_symbol as unit_symbol,
			a003.precis as precis,
			0,
			use_stamp
		from cfsec213.iso_ccy a003
		where
			a003.ISOCcyId = argISOCcyId;

	open retCursor for select
			a003.createdby,
			to_char( a003.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a003.updatedby,
			to_char( a003.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a003.ISOCcyId as ISOCcyId,
			a003.iso_code as iso_code,
			a003.ccy_name as ccy_name,
			a003.unit_symbol as unit_symbol,
			a003.precis as precis,
		a003.revision as revision
	from cfsec213.iso_ccy a003
	where
		a003.ISOCcyId = argISOCcyId;
end crt_iso_ccy;
/

show errors procedure cfsec213.crt_iso_ccy;
