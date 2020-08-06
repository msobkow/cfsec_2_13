--
--	@(#) dbcreate/cfsec/db2luw/crsp_create_svctype.sql
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
create or replace procedure sp_create_svctype(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argDescription varchar(50) )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
		declare argServiceTypeId integer;	\
	declare retcursor cursor with return to client for	\
		select	\
				a013.createdby as createdby,	\
				to_char( a013.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a013.updatedby as updatedby,	\
				to_char( a013.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a013.servicetypeid as servicetypeid,	\
			a013.description as description,	\
			a013.revision as revision	\
		from cfsec213.SvcType as a013	\
		where	\
			a013.servicetypeid = argServiceTypeId;	\
	begin	\
		if( argClassCode = 'a013' )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20001, 'Permission denied -- only system user can create ServiceType records' );	\
			end if;	\
		end if;	\
		call sp_next_servicetypeidgen( argServiceTypeId );	\
		insert into cfsec213.svctype(	\
			createdby,	\
			createdat,	\
			updatedby,	\
			updatedat,	\
			servicetypeid,	\
			description,	\
			revision )	\
		values (	\
			argAuditUserId,	\
			current timestamp,	\
			argAuditUserId,	\
			current timestamp,	\
			argServiceTypeId,	\
			argDescription,	\
			1 );	\
	\
		insert into cfsec213.svctype_h (	\
				servicetypeid,	\
				auditclusterid,	\
				auditsessionid,	\
				auditstamp,	\
				description,	\
				revision,	\
				auditaction )	\
		select	\
				a013.servicetypeid,	\
				argAuditClusterId,	\
				argAuditSessionId,	\
				current timestamp,	\
				a013.description,	\
				a013.revision,	\
				0	\
		from cfsec213.SvcType as a013	\
		where	\
				a013.servicetypeid = argServiceTypeId;	\
	\
		open retcursor;	\
	end;	\
end
