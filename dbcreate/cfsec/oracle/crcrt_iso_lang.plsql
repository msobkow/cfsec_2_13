--
--	@(#) dbcreate/cfsec/oracle/crcrt_iso_lang.plsql
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

create or replace procedure cfsec213.crt_iso_lang(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argiso_code3 varchar2,
	argiso_code2 varchar2,
	argeng_name varchar2 ) authid definer
is
	permissionDenied exception;
	use_stamp cfsec213.iso_lang_h.auditstamp%type;
	permissionFlag integer;
	argISOLangId smallint;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a007' )
	then
		permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	argISOLangId := cfsec213.nxt_isolangidgen();
	insert into cfsec213.iso_lang(
		createdby,
		createdat,
		updatedby,
		updatedat,
		ISOLangId,
		iso_code3,
		iso_code2,
		eng_name,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argISOLangId,
		argiso_code3,
		argiso_code2,
		argeng_name,
		1 );
	insert into cfsec213.iso_lang_h (
			ISOLangId,
			revision,
			auditclusterid,
			auditsessionid,
			iso_code3,
			iso_code2,
			eng_name,
			auditaction,
			auditstamp )
		select
			a007.ISOLangId as ISOLangId,
			a007.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a007.iso_code3 as iso_code3,
			a007.iso_code2 as iso_code2,
			a007.eng_name as eng_name,
			0,
			use_stamp
		from cfsec213.iso_lang a007
		where
			a007.ISOLangId = argISOLangId;

	open retCursor for select
			a007.createdby,
			to_char( a007.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a007.updatedby,
			to_char( a007.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a007.ISOLangId as ISOLangId,
			a007.iso_code3 as iso_code3,
			a007.iso_code2 as iso_code2,
			a007.eng_name as eng_name,
		a007.revision as revision
	from cfsec213.iso_lang a007
	where
		a007.ISOLangId = argISOLangId;
end crt_iso_lang;
/

show errors procedure cfsec213.crt_iso_lang;
