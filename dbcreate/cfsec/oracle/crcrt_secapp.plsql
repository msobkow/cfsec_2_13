--
--	@(#) dbcreate/cfsec/oracle/crcrt_secapp.plsql
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

create or replace procedure cfsec213.crt_secapp(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argClusterId numeric,
	argJEEMountName varchar2 ) authid definer
is
	permissionDenied exception;
	use_stamp cfsec213.SecApp_h.auditstamp%type;
	permissionFlag integer;
	argSecAppId integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a009' )
	then
		permissionFlag := cfsec213.sp_is_cluster_user( argClusterId,
			'CreateSecApp',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	argSecAppId := cfsec213.nxt_secappidgen( argClusterId );
	insert into cfsec213.secapp(
		createdby,
		createdat,
		updatedby,
		updatedat,
		ClusterId,
		SecAppId,
		JEEMountName,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argClusterId,
		argSecAppId,
		argJEEMountName,
		1 );
	insert into cfsec213.SecApp_h (
			ClusterId,
			SecAppId,
			revision,
			auditclusterid,
			auditsessionid,
			JEEMountName,
			auditaction,
			auditstamp )
		select
			a009.ClusterId as ClusterId,
			a009.SecAppId as SecAppId,
			a009.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a009.JEEMountName as JEEMountName,
			0,
			use_stamp
		from cfsec213.SecApp a009
		where
			a009.ClusterId = argClusterId
			and a009.SecAppId = argSecAppId;

	open retCursor for select
			a009.createdby,
			to_char( a009.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a009.updatedby,
			to_char( a009.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a009.ClusterId as ClusterId,
			a009.SecAppId as SecAppId,
			a009.JEEMountName as JEEMountName,
		a009.revision as revision
	from cfsec213.SecApp a009
	where
		a009.ClusterId = argClusterId
			and a009.SecAppId = argSecAppId;
end crt_secapp;
/

show errors procedure cfsec213.crt_secapp;
