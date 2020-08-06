--
--	@(#) dbcreate/cfsec/db2luw/crsp_create_clus.sql
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
create or replace procedure sp_create_clus(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argFullDomName varchar(192),	\
	in argDescription varchar(128) )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
		declare argId bigint;	\
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
				call raise_application_error( -20001, 'Permission denied -- only system user can create Cluster records' );	\
			end if;	\
		end if;	\
		call sp_next_clusteridgen( argId );	\
		insert into cfsec213.clus(	\
			createdby,	\
			createdat,	\
			updatedby,	\
			updatedat,	\
			id,	\
			fulldomname,	\
			description,	\
			revision )	\
		values (	\
			argAuditUserId,	\
			current timestamp,	\
			argAuditUserId,	\
			current timestamp,	\
			argId,	\
			argFullDomName,	\
			argDescription,	\
			1 );	\
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
				0	\
		from cfsec213.clus as a001	\
		where	\
				a001.id = argId;	\
	\
		open retcursor;	\
	end;	\
end
