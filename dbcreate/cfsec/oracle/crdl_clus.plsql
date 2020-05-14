--
--	@(#) dbcreate/cfsec/oracle/crdl_clus.plsql
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
alter session set plsql_warnings = 'ENABLE:ALL';
/

create or replace procedure cfsec213.dl_clus(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argId numeric,
	argRevision int ) authid definer
is
	use_stamp cfsec213.clus_h.auditstamp%type;
	oldId numeric(22,0);
	oldFullDomName varchar2(192);
	oldDescription varchar2(128);
	oldRevision integer;
	cursor cursDelSecGroupForms is
		select
			a00d.ClusId,
			a00d.SecGrpFrmId
		from cfsec213.clus a001
			inner join cfsec213.secgrp a00c on
				a001.Id = a00c.ClusterId
			inner join cfsec213.secgrpfrm a00d on
				a00c.ClusterId = a00d.ClusId
				and a00c.SecGroupId = a00d.SecGrpId
		where
			a001.Id = argId;
	cursor cursDelSecGrpIncByGroup is
		select
			a00e.ClusId,
			a00e.SecGrpIncId
		from cfsec213.clus a001
			inner join cfsec213.secgrp a00c on
				a001.Id = a00c.ClusterId
			inner join cfsec213.secinc a00e on
				a00c.ClusterId = a00e.ClusId
				and a00c.SecGroupId = a00e.IncGrpId
		where
			a001.Id = argId;
	cursor cursDelSecGrpMembs is
		select
			a00f.ClusterId,
			a00f.SecGrpMembId
		from cfsec213.clus a001
			inner join cfsec213.secgrp a00c on
				a001.Id = a00c.ClusterId
			inner join cfsec213.secmemb a00f on
				a00c.ClusterId = a00f.ClusterId
				and a00c.SecGroupId = a00f.SecGroupId
		where
			a001.Id = argId;
	cursor cursDelSecGrpIncs is
		select
			a00e.ClusId,
			a00e.SecGrpIncId
		from cfsec213.clus a001
			inner join cfsec213.secgrp a00c on
				a001.Id = a00c.ClusterId
			inner join cfsec213.secinc a00e on
				a00c.ClusterId = a00e.ClusId
				and a00c.SecGroupId = a00e.SecGrpId
		where
			a001.Id = argId;
	cursor cursDelSecGroups is
		select
			a00c.ClusterId,
			a00c.SecGroupId
		from cfsec213.clus a001
			inner join cfsec213.secgrp a00c on
				a001.Id = a00c.ClusterId
		where
			a001.Id = argId;
	cursor cursDelSecAppForms is
		select
			a00b.ClusterId,
			a00b.SecFormId
		from cfsec213.clus a001
			inner join cfsec213.secapp a009 on
				a001.Id = a009.ClusterId
			inner join cfsec213.secform a00b on
				a009.ClusterId = a00b.ClusterId
				and a009.SecAppId = a00b.SecAppId
		where
			a001.Id = argId;
	cursor cursDelSecApps is
		select
			a009.ClusterId,
			a009.SecAppId
		from cfsec213.clus a001
			inner join cfsec213.secapp a009 on
				a001.Id = a009.ClusterId
		where
			a001.Id = argId;
	cursor cursDelTenants is
		select
			a015.Id
		from cfsec213.clus a001
			inner join cfsec213.tenant a015 on
				a001.Id = a015.ClusterId
		where
			a001.Id = argId;
	cursor cursDelHostNodes is
		select
			a002.ClusterId,
			a002.HostNodeId
		from cfsec213.clus a001
			inner join cfsec213.hostnode a002 on
				a001.Id = a002.ClusterId
		where
			a001.Id = argId;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
		select
			Id,
			FullDomName,
			Description,
			revision
		into
			oldId,
			oldFullDomName,
			oldDescription,
			oldRevision
		from cfsec213.clus
		where
			Id = argId
		for update;

	permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;

	insert into cfsec213.clus_h (
			Id,
			revision,
			auditclusterid,
			auditsessionid,
			FullDomName,
			Description,
			auditaction,
			auditstamp )
		select
			a001.Id as Id,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a001.FullDomName as FullDomName,
			a001.Description as Description,
			2,
			use_stamp
		from cfsec213.clus a001
		where
			a001.Id = argId;

	for cur in cursDelSecGroupForms
	loop
		cfsec213.dl_secgrpfrmbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusId,
				cur.SecGrpFrmId );
	end loop;
	for cur in cursDelSecGrpIncByGroup
	loop
		cfsec213.dl_secincbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusId,
				cur.SecGrpIncId );
	end loop;
	for cur in cursDelSecGrpMembs
	loop
		cfsec213.dl_secmembbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.SecGrpMembId );
	end loop;
	for cur in cursDelSecGrpIncs
	loop
		cfsec213.dl_secincbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusId,
				cur.SecGrpIncId );
	end loop;
	for cur in cursDelSecGroups
	loop
		cfsec213.dl_secgrpbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.SecGroupId );
	end loop;
	for cur in cursDelSecAppForms
	loop
		cfsec213.dl_secformbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.SecFormId );
	end loop;
	for cur in cursDelSecApps
	loop
		cfsec213.dl_secappbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.SecAppId );
	end loop;
	for cur in cursDelTenants
	loop
		cfsec213.dl_tenantbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.Id );
	end loop;
	for cur in cursDelHostNodes
	loop
		cfsec213.dl_hostnodebyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.HostNodeId );
	end loop;
	delete from cfsec213.clus
	where
		Id = argId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_clus;
/

show errors procedure cfsec213.dl_clus;
