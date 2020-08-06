--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_isotz.sql
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
create or replace procedure sp_delete_isotz(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argISOTZoneId smallint,	\
	in argRevision int )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldISOTZoneId smallint;	\
	declare oldIso8601 varchar(6);	\
	declare oldTZName varchar(64);	\
	declare oldTZHourOffset smallint;	\
	declare oldTZMinOffset smallint;	\
	declare oldDescription varchar(128);	\
	declare oldVisible char(1);	\
	declare oldRevision int;	\
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
		select	\
			ISOTZoneId,	\
			Iso8601,	\
			TZName,	\
			TZHourOffset,	\
			TZMinOffset,	\
			Description,	\
			Visible,	\
			revision	\
		into	\
			oldISOTZoneId,	\
			oldIso8601,	\
			oldTZName,	\
			oldTZHourOffset,	\
			oldTZMinOffset,	\
			oldDescription,	\
			oldVisible,	\
			oldRevision	\
		from cfsec213.ISOTz	\
		where	\
			ISOTZoneId = argISOTZoneId	\
		for update;	\
	\
		set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20001, 'Permission denied -- only system user can delete ISOTZone records' );	\
		end if;	\
	\
	\
		insert into cfsec213.ISOTz_h (	\
				isotzoneid,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				iso8601,	\
				tzname,	\
				tzhouroffset,	\
				tzminoffset,	\
				description,	\
				visible,	\
			revision,	\
			auditaction )	\
		select	\
				a008.isotzoneid,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a008.iso8601,	\
				a008.tzname,	\
				a008.tzhouroffset,	\
				a008.tzminoffset,	\
				a008.description,	\
				a008.visible,	\
			a008.revision + 1,	\
			2	\
		from cfsec213.ISOTz as a008	\
		where	\
			a008.isotzoneid = argISOTZoneId;	\
	\
		delete from cfsec213.ISOTz	\
		where	\
			isotzoneid = argISOTZoneId;	\
	\
		open retcursor;	\
	end;	\
end
