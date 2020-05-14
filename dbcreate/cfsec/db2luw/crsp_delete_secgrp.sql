--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_secgrp.sql
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
