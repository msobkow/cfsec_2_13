--
--	@(#) dbcreate/cfsec/db2luw/crsp_create_iso_cntry.sql
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
create or replace procedure sp_create_iso_cntry(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argISOCode varchar(2),	\
	in argName varchar(64) )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
		declare argISOCtryId smallint;	\
	declare retcursor cursor with return to client for	\
		select	\
				a004.createdby as createdby,	\
				to_char( a004.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a004.updatedby as updatedby,	\
				to_char( a004.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a004.isoctryid as isoctryid,	\
			a004.iso_code as iso_code,	\
			a004.country_name as country_name,	\
			a004.revision as revision	\
		from cfsec213.iso_cntry as a004	\
		where	\
			a004.isoctryid = argISOCtryId;	\
	begin	\
		if( argClassCode = 'a004' )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20001, 'Permission denied -- only system user can create ISOCtry records' );	\
			end if;	\
		end if;	\
		call sp_next_isoctryidgen( argISOCtryId );	\
		insert into cfsec213.iso_cntry(	\
			createdby,	\
			createdat,	\
			updatedby,	\
			updatedat,	\
			isoctryid,	\
			iso_code,	\
			country_name,	\
			revision )	\
		values (	\
			argAuditUserId,	\
			current timestamp,	\
			argAuditUserId,	\
			current timestamp,	\
			argISOCtryId,	\
			argISOCode,	\
			argName,	\
			1 );	\
	\
		insert into cfsec213.iso_cntry_h (	\
				isoctryid,	\
				auditclusterid,	\
				auditsessionid,	\
				auditstamp,	\
				iso_code,	\
				country_name,	\
				revision,	\
				auditaction )	\
		select	\
				a004.isoctryid,	\
				argAuditClusterId,	\
				argAuditSessionId,	\
				current timestamp,	\
				a004.iso_code,	\
				a004.country_name,	\
				a004.revision,	\
				0	\
		from cfsec213.iso_cntry as a004	\
		where	\
				a004.isoctryid = argISOCtryId;	\
	\
		open retcursor;	\
	end;	\
end