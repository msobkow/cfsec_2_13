--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_svctype.sql
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
create or replace procedure sp_delete_svctype(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argServiceTypeId integer,	\
	in argRevision int )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldServiceTypeId integer;	\
	declare oldDescription varchar(50);	\
	declare oldRevision int;	\
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
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
		set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20001, 'Permission denied -- only system user can delete ServiceType records' );	\
		end if;	\
	\
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
			a013.revision + 1,	\
			2	\
		from cfsec213.SvcType as a013	\
		where	\
			a013.servicetypeid = argServiceTypeId;	\
	\
		delete from cfsec213.SvcType	\
		where	\
			servicetypeid = argServiceTypeId;	\
	\
		open retcursor;	\
	end;	\
end
