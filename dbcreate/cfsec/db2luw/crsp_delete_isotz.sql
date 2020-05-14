--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_isotz.sql
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
