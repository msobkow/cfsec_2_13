--
--	@(#) dbcreate/cfsec/oracle/crdl_iso_cntry.plsql
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

create or replace procedure cfsec213.dl_iso_cntry(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argISOCtryId smallint,
	argRevision int ) authid definer
is
	use_stamp cfsec213.iso_cntry_h.auditstamp%type;
	oldISOCtryId smallint;
	oldiso_code varchar2(2);
	oldcountry_name varchar2(64);
	oldRevision integer;
	cursor cursDelCtryLangs is
		select
			a006.ISOCtryId,
			a006.ISOLangId
		from cfsec213.iso_cntry a004
			inner join cfsec213.iso_cntrylng a006 on
				a004.ISOCtryId = a006.ISOCtryId
		where
			a004.ISOCtryId = argISOCtryId;
	cursor cursDelCtryCcys is
		select
			a005.ISOCtryId,
			a005.ISOCcyId
		from cfsec213.iso_cntry a004
			inner join cfsec213.iso_cntryccy a005 on
				a004.ISOCtryId = a005.ISOCtryId
		where
			a004.ISOCtryId = argISOCtryId;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
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

	permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
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
			2,
			use_stamp
		from cfsec213.iso_cntry a004
		where
			a004.ISOCtryId = argISOCtryId;

	for cur in cursDelCtryLangs
	loop
		cfsec213.dl_iso_cntrylngbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ISOCtryId,
				cur.ISOLangId );
	end loop;
	for cur in cursDelCtryCcys
	loop
		cfsec213.dl_iso_cntryccybyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ISOCtryId,
				cur.ISOCcyId );
	end loop;
	delete from cfsec213.iso_cntry
	where
		ISOCtryId = argISOCtryId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_iso_cntry;
/

show errors procedure cfsec213.dl_iso_cntry;
