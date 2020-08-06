--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_secgrp.sql
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
create or replace procedure sp_delete_secgrp(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClusterId bigint,	\
	in argSecGroupId integer,	\
	in argRevision int )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldClusterId bigint;	\
	declare oldSecGroupId integer;	\
	declare oldName varchar(64);	\
	declare oldIsVisible char(1);	\
	declare oldRevision int;	\
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
		select	\
			ClusterId,	\
			SecGroupId,	\
			safe_name,	\
			IsVisible,	\
			revision	\
		into	\
			oldClusterId,	\
			oldSecGroupId,	\
			oldName,	\
			oldIsVisible,	\
			oldRevision	\
		from cfsec213.SecGrp	\
		where	\
			ClusterId = argClusterId	\
			and SecGroupId = argSecGroupId	\
		for update;	\
	\
		if( oldClusterId != secClusterId )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20002, 'Permission denied -- Data is not owned by logged in cluster' );	\
			end if;	\
		end if;	\
	\
		set( permissionFlag ) = ( sp_is_cluster_user( oldClusterId,	\
				'DeleteSecGroup',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for DeleteSecGroup' );	\
		end if;	\
	\
	\
		for cur as	\
			select	\
				a00d.clusid as clusid,	\
				a00d.secgrpfrmid as secgrpfrmid	\
			from cfsec213.SecGrp as a00c	\
				inner join cfsec213.secgrpfrm a00d on 	\
					a00c.clusterid = a00d.clusid	\
					and a00c.secgroupid = a00d.secgrpid	\
			where	\
				a00c.clusterid = argClusterId	\
				and a00c.secgroupid = argSecGroupId	\
		do	\
			call sp_delete_secgrpfrm_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					clusid,	\
					secgrpfrmid );	\
		end for;	\
	\
		for cur as	\
			select	\
				a00e.clusid as clusid,	\
				a00e.secgrpincid as secgrpincid	\
			from cfsec213.SecGrp as a00c	\
				inner join cfsec213.secinc a00e on 	\
					a00c.clusterid = a00e.clusid	\
					and a00c.secgroupid = a00e.incgrpid	\
			where	\
				a00c.clusterid = argClusterId	\
				and a00c.secgroupid = argSecGroupId	\
		do	\
			call sp_delete_secinc_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					clusid,	\
					secgrpincid );	\
		end for;	\
	\
		for cur as	\
			select	\
				a00f.clusterid as clusterid,	\
				a00f.secgrpmembid as secgrpmembid	\
			from cfsec213.SecGrp as a00c	\
				inner join cfsec213.secmemb a00f on 	\
					a00c.clusterid = a00f.clusterid	\
					and a00c.secgroupid = a00f.secgroupid	\
			where	\
				a00c.clusterid = argClusterId	\
				and a00c.secgroupid = argSecGroupId	\
		do	\
			call sp_delete_secmemb_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					clusterid,	\
					secgrpmembid );	\
		end for;	\
	\
		for cur as	\
			select	\
				a00e.clusid as clusid,	\
				a00e.secgrpincid as secgrpincid	\
			from cfsec213.SecGrp as a00c	\
				inner join cfsec213.secinc a00e on 	\
					a00c.clusterid = a00e.clusid	\
					and a00c.secgroupid = a00e.secgrpid	\
			where	\
				a00c.clusterid = argClusterId	\
				and a00c.secgroupid = argSecGroupId	\
		do	\
			call sp_delete_secinc_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					clusid,	\
					secgrpincid );	\
		end for;	\
	\
		insert into cfsec213.SecGrp_h (	\
				clusterid,	\
				secgroupid,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				safe_name,	\
				isvisible,	\
			revision,	\
			auditaction )	\
		select	\
				a00c.clusterid,	\
				a00c.secgroupid,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a00c.safe_name,	\
				a00c.isvisible,	\
			a00c.revision + 1,	\
			2	\
		from cfsec213.SecGrp as a00c	\
		where	\
			a00c.clusterid = argClusterId	\
		and a00c.secgroupid = argSecGroupId;	\
	\
		delete from cfsec213.SecGrp	\
		where	\
			clusterid = argClusterId	\
			and secgroupid = argSecGroupId;	\
	\
		open retcursor;	\
	end;	\
end
