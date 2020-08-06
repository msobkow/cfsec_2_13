--
--	@(#) dbcreate/cfsec/oracle/crdl_secgrp.plsql
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
alter session set plsql_warnings = 'ENABLE:ALL';
/

create or replace procedure cfsec213.dl_secgrp(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClusterId numeric,
	argSecGroupId integer,
	argRevision int ) authid definer
is
	use_stamp cfsec213.SecGrp_h.auditstamp%type;
	oldClusterId numeric(22,0);
	oldSecGroupId integer;
	oldsafe_name varchar2(64);
	oldIsVisible char(1);
	oldRevision integer;
	cursor cursDelSecGroupForms is
		select
			a00d.ClusId,
			a00d.SecGrpFrmId
		from cfsec213.SecGrp a00c
			inner join cfsec213.secgrpfrm a00d on
				a00c.ClusterId = a00d.ClusId
				and a00c.SecGroupId = a00d.SecGrpId
		where
			a00c.ClusterId = argClusterId
			and a00c.SecGroupId = argSecGroupId;
	cursor cursDelSecGrpIncByGroup is
		select
			a00e.ClusId,
			a00e.SecGrpIncId
		from cfsec213.SecGrp a00c
			inner join cfsec213.secinc a00e on
				a00c.ClusterId = a00e.ClusId
				and a00c.SecGroupId = a00e.IncGrpId
		where
			a00c.ClusterId = argClusterId
			and a00c.SecGroupId = argSecGroupId;
	cursor cursDelSecGrpMembs is
		select
			a00f.ClusterId,
			a00f.SecGrpMembId
		from cfsec213.SecGrp a00c
			inner join cfsec213.secmemb a00f on
				a00c.ClusterId = a00f.ClusterId
				and a00c.SecGroupId = a00f.SecGroupId
		where
			a00c.ClusterId = argClusterId
			and a00c.SecGroupId = argSecGroupId;
	cursor cursDelSecGrpIncs is
		select
			a00e.ClusId,
			a00e.SecGrpIncId
		from cfsec213.SecGrp a00c
			inner join cfsec213.secinc a00e on
				a00c.ClusterId = a00e.ClusId
				and a00c.SecGroupId = a00e.SecGrpId
		where
			a00c.ClusterId = argClusterId
			and a00c.SecGroupId = argSecGroupId;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
		select
			ClusterId,
			SecGroupId,
			safe_name,
			IsVisible,
			revision
		into
			oldClusterId,
			oldSecGroupId,
			oldsafe_name,
			oldIsVisible,
			oldRevision
		from cfsec213.SecGrp
		where
			ClusterId = argClusterId
			and SecGroupId = argSecGroupId
		for update;

	if( oldClusterId != secClusterId )
	then
		permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	permissionFlag := cfsec213.sp_is_cluster_user( oldClusterId,
		'DeleteSecGroup',
		argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;

	insert into cfsec213.SecGrp_h (
			ClusterId,
			SecGroupId,
			revision,
			auditclusterid,
			auditsessionid,
			safe_name,
			IsVisible,
			auditaction,
			auditstamp )
		select
			a00c.ClusterId as ClusterId,
			a00c.SecGroupId as SecGroupId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a00c.safe_name as safe_name,
			a00c.IsVisible as IsVisible,
			2,
			use_stamp
		from cfsec213.SecGrp a00c
		where
			a00c.ClusterId = argClusterId
			and a00c.SecGroupId = argSecGroupId;

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
	delete from cfsec213.SecGrp
	where
		ClusterId = argClusterId
		and SecGroupId = argSecGroupId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_secgrp;
/

show errors procedure cfsec213.dl_secgrp;
