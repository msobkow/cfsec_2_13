--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_iso_cntry.sql
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
create or replace procedure sp_delete_iso_cntry(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argISOCtryId smallint,	\
	in argRevision int )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldISOCtryId smallint;	\
	declare oldISOCode varchar(2);	\
	declare oldName varchar(64);	\
	declare oldRevision int;	\
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
		select	\
			ISOCtryId,	\
			iso_code,	\
			country_name,	\
			revision	\
		into	\
			oldISOCtryId,	\
			oldISOCode,	\
			oldName,	\
			oldRevision	\
		from cfsec213.iso_cntry	\
		where	\
			ISOCtryId = argISOCtryId	\
		for update;	\
	\
		set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20001, 'Permission denied -- only system user can delete ISOCtry records' );	\
		end if;	\
	\
	\
		for cur as	\
			select	\
				a006.isoctryid as isoctryid,	\
				a006.isolangid as isolangid	\
			from cfsec213.iso_cntry as a004	\
				inner join cfsec213.iso_cntrylng a006 on 	\
					a004.isoctryid = a006.isoctryid	\
			where	\
				a004.isoctryid = argISOCtryId	\
		do	\
			call sp_delete_iso_cntrylng_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					isoctryid,	\
					isolangid );	\
		end for;	\
	\
		for cur as	\
			select	\
				a005.isoctryid as isoctryid,	\
				a005.isoccyid as isoccyid	\
			from cfsec213.iso_cntry as a004	\
				inner join cfsec213.iso_cntryccy a005 on 	\
					a004.isoctryid = a005.isoctryid	\
			where	\
				a004.isoctryid = argISOCtryId	\
		do	\
			call sp_delete_iso_cntryccy_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					isoctryid,	\
					isoccyid );	\
		end for;	\
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
			a004.revision + 1,	\
			2	\
		from cfsec213.iso_cntry as a004	\
		where	\
			a004.isoctryid = argISOCtryId;	\
	\
		delete from cfsec213.iso_cntry	\
		where	\
			isoctryid = argISOCtryId;	\
	\
		open retcursor;	\
	end;	\
end
