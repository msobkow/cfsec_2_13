--
--	@(#) dbcreate/cfsec/db2luw/crsp_update_svctype.sql
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

create or replace procedure sp_update_svctype(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argServiceTypeId integer,	\
	in argDescription varchar(50),	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldServiceTypeId integer;	\
	declare oldDescription varchar(50);	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
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
				call raise_application_error( -20001, 'Permission denied -- only system user can update ServiceType records' );	\
			end if;	\
		end if;	\
	\
		select	\
			ServiceTypeId,	\
			Description,	\
			revision	\
		into	\
			oldServiceTypeId,	\
			oldDescription,	\
			oldRevision	\
		from cfsec213.SvcType	\
		where	\
			ServiceTypeId = argServiceTypeId	\
		for update;	\
	\
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_svctype() Data collision detected' );	\
		end if;	\
	\
		update cfsec213.SvcType	\
		set	\
			revision = argRevision + 1,	\
			updatedby = argAuditUserId,	\
			updatedat = current timestamp,	\
			description = argDescription	\
		where	\
			servicetypeid = argServiceTypeId	\
		and revision = argRevision;	\
	\
		insert into cfsec213.SvcType_h (	\
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
			2	\
		from cfsec213.SvcType as a013	\
		where	\
			a013.servicetypeid = argServiceTypeId;	\
	\
		open retcursor;	\
	end;	\
end
