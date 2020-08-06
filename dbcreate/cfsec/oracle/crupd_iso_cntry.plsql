--
--	@(#) dbcreate/cfsec/oracle/crupd_iso_cntry.plsql
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


create or replace procedure cfsec213.upd_iso_cntry(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argISOCtryId smallint,
	argiso_code varchar2,
	argcountry_name varchar2,
	argRevision integer ) authid definer
is
	use_stamp cfsec213.iso_cntry_h.auditstamp%type;
	oldISOCtryId smallint;
	oldiso_code varchar2(2);
	oldcountry_name varchar2(64);
	oldRevision integer;
	dataCollision exception;
	dataUpdateFailed exception;
	permissionDenied exception;
	permissionFlag integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a004' )
	then
		permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

		select
			ISOCtryId,
			iso_code,
			country_name,
			revision
		into
			oldISOCtryId,
			oldiso_code,
			oldcountry_name,
			oldRevision
		from cfsec213.iso_cntry
		where
			ISOCtryId = argISOCtryId
		for update;

	if argRevision != oldRevision
	then
		raise dataCollision;
	end if;

	update cfsec213.iso_cntry
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = use_stamp,
		iso_code = argiso_code,
		country_name = argcountry_name
	where
		ISOCtryId = argISOCtryId
		and revision = argRevision;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;


	insert into cfsec213.iso_cntry_h (
			ISOCtryId,
			revision,
			auditclusterid,
			auditsessionid,
			iso_code,
			country_name,
			auditaction,
			auditstamp )
		select
			a004.ISOCtryId as ISOCtryId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a004.iso_code as iso_code,
			a004.country_name as country_name,
			1,
			use_stamp
		from cfsec213.iso_cntry a004
		where
			a004.ISOCtryId = argISOCtryId;

	open retCursor for select
			a004.createdby,
			to_char( a004.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a004.updatedby,
			to_char( a004.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a004.ISOCtryId as ISOCtryId,
			a004.iso_code as iso_code,
			a004.country_name as country_name,
		a004.revision as revision
	from cfsec213.iso_cntry a004
	where
		a004.ISOCtryId = argISOCtryId;
end upd_iso_cntry;

/

show errors procedure cfsec213.upd_iso_cntry;
