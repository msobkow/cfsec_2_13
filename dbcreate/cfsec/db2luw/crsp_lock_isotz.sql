--
--	@(#) dbcreate/cfsec/db2luw/crsp_lock_isotz.sql
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

create or replace procedure sp_lock_isotz(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argISOTZoneId smallint )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare isSystemUser integer;	\
	declare syscurs cursor with return to client for	\
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
			a008.isotzoneid = argISOTZoneId	\
		for update;	\
	declare usercurs cursor with return to client for	\
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
			a008.isotzoneid = argISOTZoneId	\
		for update;	\
	begin	\
		set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20001, 'Permission denied -- only system user can create ISOTZone records' );	\
		end if;	\
		set( isSystemUser ) = ( sp_is_system_user( argAuditUserId ) );	\
		if( isSystemUser = 1 )	\
		then	\
			open syscurs;	\
		else	\
			open usercurs;	\
		end if;	\
	end;	\
end
