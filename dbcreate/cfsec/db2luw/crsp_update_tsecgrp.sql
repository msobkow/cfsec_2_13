--
--	@(#) dbcreate/cfsec/db2luw/crsp_update_tsecgrp.sql
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

create or replace procedure sp_update_tsecgrp(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argTenantId bigint,	\
	in argTSecGroupId integer,	\
	in argName varchar(64),	\
	in argIsVisible char(1),	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldTenantId bigint;	\
	declare oldTSecGroupId integer;	\
	declare oldName varchar(64);	\
	declare oldIsVisible char(1);	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select	\
				a016.createdby as createdby,	\
				to_char( a016.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a016.updatedby as updatedby,	\
				to_char( a016.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a016.tenantid as tenantid,	\
			a016.tsecgroupid as tsecgroupid,	\
			a016.safe_name as safe_name,	\
			a016.isvisible as isvisible,	\
			a016.revision as revision	\
		from cfsec213.TSecGrp as a016	\
		where	\
			a016.tenantid = argTenantId	\
		and a016.tsecgroupid = argTSecGroupId;	\
	begin	\
		if( argClassCode = 'a016' )	\
		then	\
			set( permissionFlag ) = ( sp_is_tenant_user( argTenantId,	\
					'UpdateTSecGroup',	\
					argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20003, 'Permission denied -- User not found in tenant TSecGroup for UpdateTSecGroup' );	\
			end if;	\
		end if;	\
	\
		select	\
			TenantId,	\
			TSecGroupId,	\
			safe_name,	\
			IsVisible,	\
			revision	\
		into	\
			oldTenantId,	\
			oldTSecGroupId,	\
			oldName,	\
			oldIsVisible,	\
			oldRevision	\
		from cfsec213.TSecGrp	\
		where	\
			TenantId = argTenantId	\
			and TSecGroupId = argTSecGroupId	\
		for update;	\
	\
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_tsecgrp() Data collision detected' );	\
		end if;	\
	\
		update cfsec213.TSecGrp	\
		set	\
			revision = argRevision + 1,	\
			updatedby = argAuditUserId,	\
			updatedat = current timestamp,	\
			safe_name = argName,	\
			isvisible = argIsVisible	\
		where	\
			tenantid = argTenantId	\
		and tsecgroupid = argTSecGroupId	\
		and revision = argRevision;	\
	\
		insert into cfsec213.TSecGrp_h (	\
				tenantid,	\
				tsecgroupid,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				safe_name,	\
				isvisible,	\
			revision,	\
			auditaction )	\
		select	\
				a016.tenantid,	\
				a016.tsecgroupid,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a016.safe_name,	\
				a016.isvisible,	\
			a016.revision,	\
			2	\
		from cfsec213.TSecGrp as a016	\
		where	\
			a016.tenantid = argTenantId	\
		and a016.tsecgroupid = argTSecGroupId;	\
	\
		open retcursor;	\
	end;	\
end
