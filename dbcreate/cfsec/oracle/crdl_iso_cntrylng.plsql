--
--	@(#) dbcreate/cfsec/oracle/crdl_iso_cntrylng.plsql
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

create or replace procedure cfsec213.dl_iso_cntrylng(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argISOCtryId smallint,
	argISOLangId smallint,
	argRevision int ) authid definer
is
	use_stamp cfsec213.iso_cntrylng_h.auditstamp%type;
	oldISOCtryId smallint;
	oldISOLangId smallint;
	oldRevision integer;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
		select
			ISOCtryId,
			ISOLangId,
			revision
		into
			oldISOCtryId,
			oldISOLangId,
			oldRevision
		from cfsec213.iso_cntrylng
		where
			ISOCtryId = argISOCtryId
			and ISOLangId = argISOLangId
		for update;

	permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;

	insert into cfsec213.iso_cntrylng_h (
			ISOCtryId,
			ISOLangId,
			revision,
			auditclusterid,
			auditsessionid,
			auditaction,
			auditstamp )
		select
			a006.ISOCtryId as ISOCtryId,
			a006.ISOLangId as ISOLangId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			2,
			use_stamp
		from cfsec213.iso_cntrylng a006
		where
			a006.ISOCtryId = argISOCtryId
			and a006.ISOLangId = argISOLangId;

	delete from cfsec213.iso_cntrylng
	where
		ISOCtryId = argISOCtryId
		and ISOLangId = argISOLangId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_iso_cntrylng;
/

show errors procedure cfsec213.dl_iso_cntrylng;
