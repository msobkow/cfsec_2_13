--
--	@(#) dbcreate/cfsec/db2luw/crsp_create_isotz.sql
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
create or replace procedure sp_create_isotz(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argIso8601 varchar(6),	\
	in argTZName varchar(64),	\
	in argTZHourOffset smallint,	\
	in argTZMinOffset smallint,	\
	in argDescription varchar(128),	\
	in argVisible char(1) )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
		declare argISOTZoneId smallint;	\
	declare retcursor cursor with return to client for	\
		select	\
				a008.createdby as createdby,	\
				to_char( a008.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a008.updatedby as updatedby,	\
				to_char( a008.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a008.isotzoneid as isotzoneid,	\
			a008.iso8601 as iso8601,	\
			a008.tzname as tzname,	\
			a008.tzhouroffset as tzhouroffset,	\
			a008.tzminoffset as tzminoffset,	\
			a008.description as description,	\
			a008.visible as visible,	\
			a008.revision as revision	\
		from cfsec213.ISOTz as a008	\
		where	\
			a008.isotzoneid = argISOTZoneId;	\
	begin	\
		if( argClassCode = 'a008' )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20001, 'Permission denied -- only system user can create ISOTZone records' );	\
			end if;	\
		end if;	\
		call sp_next_isotzoneidgen( argISOTZoneId );	\
		insert into cfsec213.isotz(	\
			createdby,	\
			createdat,	\
			updatedby,	\
			updatedat,	\
			isotzoneid,	\
			iso8601,	\
			tzname,	\
			tzhouroffset,	\
			tzminoffset,	\
			description,	\
			visible,	\
			revision )	\
		values (	\
			argAuditUserId,	\
			current timestamp,	\
			argAuditUserId,	\
			current timestamp,	\
			argISOTZoneId,	\
			argIso8601,	\
			argTZName,	\
			argTZHourOffset,	\
			argTZMinOffset,	\
			argDescription,	\
			argVisible,	\
			1 );	\
	\
		insert into cfsec213.isotz_h (	\
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
				a008.revision,	\
				0	\
		from cfsec213.ISOTz as a008	\
		where	\
				a008.isotzoneid = argISOTZoneId;	\
	\
		open retcursor;	\
	end;	\
end
