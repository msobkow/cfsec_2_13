--
--	@(#) dbcreate/cfsec/db2luw/crsp_update_clus.sql
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

create or replace procedure sp_update_clus(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argId bigint,	\
	in argFullDomName varchar(192),	\
	in argDescription varchar(128),	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldId bigint;	\
	declare oldFullDomName varchar(192);	\
	declare oldDescription varchar(128);	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select	\
				a001.createdby as createdby,	\
				to_char( a001.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a001.updatedby as updatedby,	\
				to_char( a001.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a001.id as id,	\
			a001.fulldomname as fulldomname,	\
			a001.description as description,	\
			a001.revision as revision	\
		from cfsec213.clus as a001	\
		where	\
			a001.id = argId;	\
	begin	\
		if( argClassCode = 'a001' )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20001, 'Permission denied -- only system user can update Cluster records' );	\
			end if;	\
		end if;	\
	\
		select	\
			Id,	\
			FullDomName,	\
			Description,	\
			revision	\
		into	\
			oldId,	\
			oldFullDomName,	\
			oldDescription,	\
			oldRevision	\
		from cfsec213.clus	\
		where	\
			Id = argId	\
		for update;	\
	\
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_clus() Data collision detected' );	\
		end if;	\
	\
		update cfsec213.clus	\
		set	\
			revision = argRevision + 1,	\
			updatedby = argAuditUserId,	\
			updatedat = current timestamp,	\
			fulldomname = argFullDomName,	\
			description = argDescription	\
		where	\
			id = argId	\
		and revision = argRevision;	\
	\
		insert into cfsec213.clus_h (	\
				id,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				fulldomname,	\
				description,	\
			revision,	\
			auditaction )	\
		select	\
				a001.id,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a001.fulldomname,	\
				a001.description,	\
			a001.revision,	\
			2	\
		from cfsec213.clus as a001	\
		where	\
			a001.id = argId;	\
	\
		open retcursor;	\
	end;	\
end
