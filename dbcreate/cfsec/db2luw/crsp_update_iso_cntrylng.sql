--
--	@(#) dbcreate/cfsec/db2luw/crsp_update_iso_cntrylng.sql
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

create or replace procedure sp_update_iso_cntrylng(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argISOCtryId smallint,	\
	in argISOLangId smallint,	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldISOCtryId smallint;	\
	declare oldISOLangId smallint;	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select	\
				a006.createdby as createdby,	\
				to_char( a006.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a006.updatedby as updatedby,	\
				to_char( a006.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a006.isoctryid as isoctryid,	\
			a006.isolangid as isolangid,	\
			a006.revision as revision	\
		from cfsec213.iso_cntrylng as a006	\
		where	\
			a006.isoctryid = argISOCtryId	\
		and a006.isolangid = argISOLangId;	\
	begin	\
		if( argClassCode = 'a006' )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20001, 'Permission denied -- only system user can update ISOCtryLang records' );	\
			end if;	\
		end if;	\
	\
		select	\
			ISOCtryId,	\
			ISOLangId,	\
			revision	\
		into	\
			oldISOCtryId,	\
			oldISOLangId,	\
			oldRevision	\
		from cfsec213.iso_cntrylng	\
		where	\
			ISOCtryId = argISOCtryId	\
			and ISOLangId = argISOLangId	\
		for update;	\
	\
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_iso_cntrylng() Data collision detected' );	\
		end if;	\
	\
		update cfsec213.iso_cntrylng	\
		set	\
			revision = argRevision + 1,	\
			updatedby = argAuditUserId,	\
			updatedat = current timestamp	\
		where	\
			isoctryid = argISOCtryId	\
		and isolangid = argISOLangId	\
		and revision = argRevision;	\
	\
		insert into cfsec213.iso_cntrylng_h (	\
				isoctryid,	\
				isolangid,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
			revision,	\
			auditaction )	\
		select	\
				a006.isoctryid,	\
				a006.isolangid,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
			a006.revision,	\
			2	\
		from cfsec213.iso_cntrylng as a006	\
		where	\
			a006.isoctryid = argISOCtryId	\
		and a006.isolangid = argISOLangId;	\
	\
		open retcursor;	\
	end;	\
end
