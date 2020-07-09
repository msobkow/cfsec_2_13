--
--	@(#) dbcreate/cfsec/oracle/crupd_iso_cntrylng.plsql
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
alter session set plsql_warnings = 'ENABLE:ALL';
/


create or replace procedure cfsec213.upd_iso_cntrylng(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argISOCtryId smallint,
	argISOLangId smallint,
	argRevision integer ) authid definer
is
	use_stamp cfsec213.iso_cntrylng_h.auditstamp%type;
	oldISOCtryId smallint;
	oldISOLangId smallint;
	oldRevision integer;
	dataCollision exception;
	dataUpdateFailed exception;
	permissionDenied exception;
	permissionFlag integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a006' )
	then
		permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

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

	if argRevision != oldRevision
	then
		raise dataCollision;
	end if;

	update cfsec213.iso_cntrylng
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = use_stamp
	where
		ISOCtryId = argISOCtryId
		and ISOLangId = argISOLangId
		and revision = argRevision;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
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
			1,
			use_stamp
		from cfsec213.iso_cntrylng a006
		where
			a006.ISOCtryId = argISOCtryId
			and a006.ISOLangId = argISOLangId;

	open retCursor for select
			a006.createdby,
			to_char( a006.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a006.updatedby,
			to_char( a006.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a006.ISOCtryId as ISOCtryId,
			a006.ISOLangId as ISOLangId,
		a006.revision as revision
	from cfsec213.iso_cntrylng a006
	where
		a006.ISOCtryId = argISOCtryId
			and a006.ISOLangId = argISOLangId;
end upd_iso_cntrylng;

/

show errors procedure cfsec213.upd_iso_cntrylng;
