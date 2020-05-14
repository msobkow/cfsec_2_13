--
--	@(#) dbcreate/cfsec/oracle/crupd_iso_cntry.plsql
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
