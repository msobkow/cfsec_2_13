--
--	@(#) dbcreate/cfsec/db2luw/crsp_create_tsecmemb.sql
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
create or replace procedure sp_create_tsecmemb(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argTenantId bigint,	\
	in argTSecGroupId integer,	\
	in argSecUserId varchar(36) )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
		declare argTSecGrpMembId bigint;	\
	declare retcursor cursor with return to client for	\
		select	\
				a018.createdby as createdby,	\
				to_char( a018.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a018.updatedby as updatedby,	\
				to_char( a018.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a018.tenantid as tenantid,	\
			a018.tsecgrpmembid as tsecgrpmembid,	\
			a018.tsecgroupid as tsecgroupid,	\
			a018.secuserid as secuserid,	\
			a018.revision as revision	\
		from cfsec213.TSecMemb as a018	\
		where	\
			a018.tenantid = argTenantId	\
		and a018.tsecgrpmembid = argTSecGrpMembId;	\
	begin	\
		if( argClassCode = 'a018' )	\
		then	\
			set( permissionFlag ) = ( sp_is_tenant_user( argTenantId,	\
					'CreateTSecGrpMemb',	\
					argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20003, 'Permission denied -- User not found in tenant TSecGroup for CreateTSecGrpMemb' );	\
			end if;	\
		end if;	\
	\
		call sp_next_tsecgrpmembidgen( argTenantId,	\
			argTSecGrpMembId );	\
		insert into cfsec213.tsecmemb(	\
			createdby,	\
			createdat,	\
			updatedby,	\
			updatedat,	\
			tenantid,	\
			tsecgrpmembid,	\
			tsecgroupid,	\
			secuserid,	\
			revision )	\
		values (	\
			argAuditUserId,	\
			current timestamp,	\
			argAuditUserId,	\
			current timestamp,	\
			argTenantId,	\
			argTSecGrpMembId,	\
			argTSecGroupId,	\
			argSecUserId,	\
			1 );	\
	\
		insert into cfsec213.tsecmemb_h (	\
				tenantid,	\
				tsecgrpmembid,	\
				auditclusterid,	\
				auditsessionid,	\
				auditstamp,	\
				tsecgroupid,	\
				secuserid,	\
				revision,	\
				auditaction )	\
		select	\
				a018.tenantid,	\
				a018.tsecgrpmembid,	\
				argAuditClusterId,	\
				argAuditSessionId,	\
				current timestamp,	\
				a018.tsecgroupid,	\
				a018.secuserid,	\
				a018.revision,	\
				0	\
		from cfsec213.TSecMemb as a018	\
		where	\
				a018.tenantid = argTenantId	\
		and a018.tsecgrpmembid = argTSecGrpMembId;	\
	\
		open retcursor;	\
	end;	\
end
