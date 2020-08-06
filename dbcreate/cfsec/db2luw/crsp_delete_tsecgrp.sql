--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_tsecgrp.sql
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
create or replace procedure sp_delete_tsecgrp(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argTenantId bigint,	\
	in argTSecGroupId integer,	\
	in argRevision int )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldTenantId bigint;	\
	declare oldTSecGroupId integer;	\
	declare oldName varchar(64);	\
	declare oldIsVisible char(1);	\
	declare oldRevision int;	\
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
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
		if( oldTenantId != secTenantId )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20003, 'Permission denied -- Data is not owned by logged in tenant' );	\
			end if;	\
		end if;	\
	\
		set( permissionFlag ) = ( sp_is_tenant_user( oldTenantId,	\
				'DeleteTSecGroup',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20003, 'Permission denied -- User not found in tenant TSecGroup for DeleteTSecGroup' );	\
		end if;	\
	\
	\
		for cur as	\
			select	\
				a017.tenantid as tenantid,	\
				a017.tsecgrpincid as tsecgrpincid	\
			from cfsec213.TSecGrp as a016	\
				inner join cfsec213.tsecinc a017 on 	\
					a016.tenantid = a017.tenantid	\
					and a016.tsecgroupid = a017.incgrpid	\
			where	\
				a016.tenantid = argTenantId	\
				and a016.tsecgroupid = argTSecGroupId	\
		do	\
			call sp_delete_tsecinc_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					tenantid,	\
					tsecgrpincid );	\
		end for;	\
	\
		for cur as	\
			select	\
				a018.tenantid as tenantid,	\
				a018.tsecgrpmembid as tsecgrpmembid	\
			from cfsec213.TSecGrp as a016	\
				inner join cfsec213.tsecmemb a018 on 	\
					a016.tenantid = a018.tenantid	\
					and a016.tsecgroupid = a018.tsecgroupid	\
			where	\
				a016.tenantid = argTenantId	\
				and a016.tsecgroupid = argTSecGroupId	\
		do	\
			call sp_delete_tsecmemb_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					tenantid,	\
					tsecgrpmembid );	\
		end for;	\
	\
		for cur as	\
			select	\
				a017.tenantid as tenantid,	\
				a017.tsecgrpincid as tsecgrpincid	\
			from cfsec213.TSecGrp as a016	\
				inner join cfsec213.tsecinc a017 on 	\
					a016.tenantid = a017.tenantid	\
					and a016.tsecgroupid = a017.tsecgrpid	\
			where	\
				a016.tenantid = argTenantId	\
				and a016.tsecgroupid = argTSecGroupId	\
		do	\
			call sp_delete_tsecinc_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					tenantid,	\
					tsecgrpincid );	\
		end for;	\
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
			a016.revision + 1,	\
			2	\
		from cfsec213.TSecGrp as a016	\
		where	\
			a016.tenantid = argTenantId	\
		and a016.tsecgroupid = argTSecGroupId;	\
	\
		delete from cfsec213.TSecGrp	\
		where	\
			tenantid = argTenantId	\
			and tsecgroupid = argTSecGroupId;	\
	\
		open retcursor;	\
	end;	\
end
