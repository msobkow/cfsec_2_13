--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_clus.sql
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
create or replace procedure sp_delete_clus(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argId bigint,	\
	in argRevision int )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldId bigint;	\
	declare oldFullDomName varchar(192);	\
	declare oldDescription varchar(128);	\
	declare oldRevision int;	\
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
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
		set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20001, 'Permission denied -- only system user can delete Cluster records' );	\
		end if;	\
	\
	\
		for cur as	\
			select	\
				a00d.clusid as clusid,	\
				a00d.secgrpfrmid as secgrpfrmid	\
			from cfsec213.clus as a001	\
				inner join cfsec213.secgrp a00c on 	\
					a001.id = a00c.clusterid	\
				inner join cfsec213.secgrpfrm a00d on 	\
					a00c.clusterid = a00d.clusid	\
					and a00c.secgroupid = a00d.secgrpid	\
			where	\
				a001.id = argId	\
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
			from cfsec213.clus as a001	\
				inner join cfsec213.secgrp a00c on 	\
					a001.id = a00c.clusterid	\
				inner join cfsec213.secinc a00e on 	\
					a00c.clusterid = a00e.clusid	\
					and a00c.secgroupid = a00e.incgrpid	\
			where	\
				a001.id = argId	\
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
			from cfsec213.clus as a001	\
				inner join cfsec213.secgrp a00c on 	\
					a001.id = a00c.clusterid	\
				inner join cfsec213.secmemb a00f on 	\
					a00c.clusterid = a00f.clusterid	\
					and a00c.secgroupid = a00f.secgroupid	\
			where	\
				a001.id = argId	\
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
			from cfsec213.clus as a001	\
				inner join cfsec213.secgrp a00c on 	\
					a001.id = a00c.clusterid	\
				inner join cfsec213.secinc a00e on 	\
					a00c.clusterid = a00e.clusid	\
					and a00c.secgroupid = a00e.secgrpid	\
			where	\
				a001.id = argId	\
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
				a00c.clusterid as clusterid,	\
				a00c.secgroupid as secgroupid	\
			from cfsec213.clus as a001	\
				inner join cfsec213.secgrp a00c on 	\
					a001.id = a00c.clusterid	\
			where	\
				a001.id = argId	\
		do	\
			call sp_delete_secgrp_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					clusterid,	\
					secgroupid );	\
		end for;	\
	\
		for cur as	\
			select	\
				a00b.clusterid as clusterid,	\
				a00b.secformid as secformid	\
			from cfsec213.clus as a001	\
				inner join cfsec213.secapp a009 on 	\
					a001.id = a009.clusterid	\
				inner join cfsec213.secform a00b on 	\
					a009.clusterid = a00b.clusterid	\
					and a009.secappid = a00b.secappid	\
			where	\
				a001.id = argId	\
		do	\
			call sp_delete_secform_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					clusterid,	\
					secformid );	\
		end for;	\
	\
		for cur as	\
			select	\
				a009.clusterid as clusterid,	\
				a009.secappid as secappid	\
			from cfsec213.clus as a001	\
				inner join cfsec213.secapp a009 on 	\
					a001.id = a009.clusterid	\
			where	\
				a001.id = argId	\
		do	\
			call sp_delete_secapp_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					clusterid,	\
					secappid );	\
		end for;	\
	\
		for cur as	\
			select	\
				a015.id as id	\
			from cfsec213.clus as a001	\
				inner join cfsec213.tenant a015 on 	\
					a001.id = a015.clusterid	\
			where	\
				a001.id = argId	\
		do	\
			call sp_delete_tenant_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					id );	\
		end for;	\
	\
		for cur as	\
			select	\
				a002.clusterid as clusterid,	\
				a002.hostnodeid as hostnodeid	\
			from cfsec213.clus as a001	\
				inner join cfsec213.hostnode a002 on 	\
					a001.id = a002.clusterid	\
			where	\
				a001.id = argId	\
		do	\
			call sp_delete_hostnode_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					clusterid,	\
					hostnodeid );	\
		end for;	\
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
			a001.revision + 1,	\
			2	\
		from cfsec213.clus as a001	\
		where	\
			a001.id = argId;	\
	\
		delete from cfsec213.clus	\
		where	\
			id = argId;	\
	\
		open retcursor;	\
	end;	\
end
