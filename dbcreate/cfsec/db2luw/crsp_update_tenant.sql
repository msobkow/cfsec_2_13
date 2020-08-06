--
--	@(#) dbcreate/cfsec/db2luw/crsp_update_tenant.sql
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

create or replace procedure sp_update_tenant(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argClusterId bigint,	\
	in argId bigint,	\
	in argTenantName varchar(192),	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldClusterId bigint;	\
	declare oldId bigint;	\
	declare oldTenantName varchar(192);	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select	\
				a015.createdby as createdby,	\
				to_char( a015.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a015.updatedby as updatedby,	\
				to_char( a015.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a015.clusterid as clusterid,	\
			a015.id as id,	\
			a015.tenantname as tenantname,	\
			a015.revision as revision	\
		from cfsec213.tenant as a015	\
		where	\
			a015.id = argId;	\
	begin	\
		if( argClassCode = 'a015' )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20001, 'Permission denied -- only system user can update Tenant records' );	\
			end if;	\
		end if;	\
	\
		select	\
			ClusterId,	\
			Id,	\
			TenantName,	\
			revision	\
		into	\
			oldClusterId,	\
			oldId,	\
			oldTenantName,	\
			oldRevision	\
		from cfsec213.tenant	\
		where	\
			Id = argId	\
		for update;	\
	\
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_tenant() Data collision detected' );	\
		end if;	\
	\
		update cfsec213.tenant	\
		set	\
			revision = argRevision + 1,	\
			updatedby = argAuditUserId,	\
			updatedat = current timestamp,	\
			clusterid = argClusterId,	\
			tenantname = argTenantName	\
		where	\
			id = argId	\
		and revision = argRevision;	\
	\
		insert into cfsec213.tenant_h (	\
				id,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				clusterid,	\
				tenantname,	\
			revision,	\
			auditaction )	\
		select	\
				a015.id,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a015.clusterid,	\
				a015.tenantname,	\
			a015.revision,	\
			2	\
		from cfsec213.tenant as a015	\
		where	\
			a015.id = argId;	\
	\
		open retcursor;	\
	end;	\
end
