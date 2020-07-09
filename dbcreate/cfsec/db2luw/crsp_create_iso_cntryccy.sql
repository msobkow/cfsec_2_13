--
--	@(#) dbcreate/cfsec/db2luw/crsp_create_iso_cntryccy.sql
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
create or replace procedure sp_create_iso_cntryccy(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argISOCtryId smallint,	\
	in argISOCcyId smallint )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select	\
				a005.createdby as createdby,	\
				to_char( a005.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a005.updatedby as updatedby,	\
				to_char( a005.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a005.isoctryid as isoctryid,	\
			a005.isoccyid as isoccyid,	\
			a005.revision as revision	\
		from cfsec213.iso_cntryccy as a005	\
		where	\
			a005.isoctryid = argISOCtryId	\
		and a005.isoccyid = argISOCcyId;	\
	begin	\
		if( argClassCode = 'a005' )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20001, 'Permission denied -- only system user can create ISOCtryCcy records' );	\
			end if;	\
		end if;	\
		insert into cfsec213.iso_cntryccy(	\
			createdby,	\
			createdat,	\
			updatedby,	\
			updatedat,	\
			isoctryid,	\
			isoccyid,	\
			revision )	\
		values (	\
			argAuditUserId,	\
			current timestamp,	\
			argAuditUserId,	\
			current timestamp,	\
			argISOCtryId,	\
			argISOCcyId,	\
			1 );	\
	\
		insert into cfsec213.iso_cntryccy_h (	\
				isoctryid,	\
				isoccyid,	\
				auditclusterid,	\
				auditsessionid,	\
				auditstamp,	\
				revision,	\
				auditaction )	\
		select	\
				a005.isoctryid,	\
				a005.isoccyid,	\
				argAuditClusterId,	\
				argAuditSessionId,	\
				current timestamp,	\
				a005.revision,	\
				0	\
		from cfsec213.iso_cntryccy as a005	\
		where	\
				a005.isoctryid = argISOCtryId	\
		and a005.isoccyid = argISOCcyId;	\
	\
		open retcursor;	\
	end;	\
end
