--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_iso_cntry.sql
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
