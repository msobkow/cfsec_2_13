--
--	@(#) dbcreate/cfsec/db2luw/crsp_update_tsecinc.sql
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

create or replace procedure sp_update_tsecinc(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argTenantId bigint,	\
	in argTSecGrpIncId bigint,	\
	in argTSecGroupId integer,	\
	in argIncludeGroupId integer,	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldTenantId bigint;	\
	declare oldTSecGrpIncId bigint;	\
	declare oldTSecGroupId integer;	\
	declare oldIncludeGroupId integer;	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select	\
				a017.createdby as createdby,	\
				to_char( a017.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a017.updatedby as updatedby,	\
				to_char( a017.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a017.tenantid as tenantid,	\
			a017.tsecgrpincid as tsecgrpincid,	\
			a017.tsecgrpid as tsecgrpid,	\
			a017.incgrpid as incgrpid,	\
			a017.revision as revision	\
		from cfsec213.TSecInc as a017	\
		where	\
			a017.tenantid = argTenantId	\
		and a017.tsecgrpincid = argTSecGrpIncId;	\
	begin	\
		if( argClassCode = 'a017' )	\
		then	\
			set( permissionFlag ) = ( sp_is_tenant_user( argTenantId,	\
					'UpdateTSecGrpInc',	\
					argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20003, 'Permission denied -- User not found in tenant TSecGroup for UpdateTSecGrpInc' );	\
			end if;	\
		end if;	\
	\
		select	\
			TenantId,	\
			TSecGrpIncId,	\
			TSecGrpId,	\
			IncGrpId,	\
			revision	\
		into	\
			oldTenantId,	\
			oldTSecGrpIncId,	\
			oldTSecGroupId,	\
			oldIncludeGroupId,	\
			oldRevision	\
		from cfsec213.TSecInc	\
		where	\
			TenantId = argTenantId	\
			and TSecGrpIncId = argTSecGrpIncId	\
		for update;	\
	\
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_tsecinc() Data collision detected' );	\
		end if;	\
	\
		update cfsec213.TSecInc	\
		set	\
			revision = argRevision + 1,	\
			updatedby = argAuditUserId,	\
			updatedat = current timestamp,	\
			tsecgrpid = argTSecGroupId,	\
			incgrpid = argIncludeGroupId	\
		where	\
			tenantid = argTenantId	\
		and tsecgrpincid = argTSecGrpIncId	\
		and revision = argRevision;	\
	\
		insert into cfsec213.TSecInc_h (	\
				tenantid,	\
				tsecgrpincid,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				tsecgrpid,	\
				incgrpid,	\
			revision,	\
			auditaction )	\
		select	\
				a017.tenantid,	\
				a017.tsecgrpincid,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a017.tsecgrpid,	\
				a017.incgrpid,	\
			a017.revision,	\
			2	\
		from cfsec213.TSecInc as a017	\
		where	\
			a017.tenantid = argTenantId	\
		and a017.tsecgrpincid = argTSecGrpIncId;	\
	\
		open retcursor;	\
	end;	\
end
