--
--	@(#) dbcreate/cfsec/oracle/crdl_secgrpfrm.plsql
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

create or replace procedure cfsec213.dl_secgrpfrm(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClusId numeric,
	argSecGrpFrmId numeric,
	argRevision int ) authid definer
is
	use_stamp cfsec213.SecGrpFrm_h.auditstamp%type;
	oldClusId numeric(22,0);
	oldSecGrpFrmId numeric(22,0);
	oldSecGrpId integer;
	oldSecAppId integer;
	oldSecFrmId integer;
	oldRevision integer;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
		select
			ClusId,
			SecGrpFrmId,
			SecGrpId,
			SecAppId,
			SecFrmId,
			revision
		into
			oldClusId,
			oldSecGrpFrmId,
			oldSecGrpId,
			oldSecAppId,
			oldSecFrmId,
			oldRevision
		from cfsec213.SecGrpFrm
		where
			ClusId = argClusId
			and SecGrpFrmId = argSecGrpFrmId
		for update;

	if( oldClusId != secClusterId )
	then
		permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	permissionFlag := cfsec213.sp_is_cluster_user( oldClusId,
		'DeleteSecGroupForm',
		argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;

	insert into cfsec213.SecGrpFrm_h (
			ClusId,
			SecGrpFrmId,
			revision,
			auditclusterid,
			auditsessionid,
			SecGrpId,
			SecAppId,
			SecFrmId,
			auditaction,
			auditstamp )
		select
			a00d.ClusId as ClusId,
			a00d.SecGrpFrmId as SecGrpFrmId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a00d.SecGrpId as SecGrpId,
			a00d.SecAppId as SecAppId,
			a00d.SecFrmId as SecFrmId,
			2,
			use_stamp
		from cfsec213.SecGrpFrm a00d
		where
			a00d.ClusId = argClusId
			and a00d.SecGrpFrmId = argSecGrpFrmId;

	delete from cfsec213.SecGrpFrm
	where
		ClusId = argClusId
		and SecGrpFrmId = argSecGrpFrmId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_secgrpfrm;
/

show errors procedure cfsec213.dl_secgrpfrm;
