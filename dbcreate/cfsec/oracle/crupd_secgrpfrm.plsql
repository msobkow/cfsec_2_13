--
--	@(#) dbcreate/cfsec/oracle/crupd_secgrpfrm.plsql
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


create or replace procedure cfsec213.upd_secgrpfrm(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argClusId numeric,
	argSecGrpFrmId numeric,
	argSecGrpId integer,
	argSecAppId integer,
	argSecFrmId integer,
	argRevision integer ) authid definer
is
	use_stamp cfsec213.SecGrpFrm_h.auditstamp%type;
	oldClusId numeric(22,0);
	oldSecGrpFrmId numeric(22,0);
	oldSecGrpId integer;
	oldSecAppId integer;
	oldSecFrmId integer;
	oldRevision integer;
	dataCollision exception;
	dataUpdateFailed exception;
	permissionDenied exception;
	permissionFlag integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a00d' )
	then
		permissionFlag := cfsec213.sp_is_cluster_user( argClusId,
			'UpdateSecGroupForm',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

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

	if argRevision != oldRevision
	then
		raise dataCollision;
	end if;

	update cfsec213.SecGrpFrm
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = use_stamp,
		SecGrpId = argSecGrpId,
		SecAppId = argSecAppId,
		SecFrmId = argSecFrmId
	where
		ClusId = argClusId
		and SecGrpFrmId = argSecGrpFrmId
		and revision = argRevision;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
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
			1,
			use_stamp
		from cfsec213.SecGrpFrm a00d
		where
			a00d.ClusId = argClusId
			and a00d.SecGrpFrmId = argSecGrpFrmId;

	open retCursor for select
			a00d.createdby,
			to_char( a00d.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00d.updatedby,
			to_char( a00d.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00d.ClusId as ClusId,
			a00d.SecGrpFrmId as SecGrpFrmId,
			a00d.SecGrpId as SecGrpId,
			a00d.SecAppId as SecAppId,
			a00d.SecFrmId as SecFrmId,
		a00d.revision as revision
	from cfsec213.SecGrpFrm a00d
	where
		a00d.ClusId = argClusId
			and a00d.SecGrpFrmId = argSecGrpFrmId;
end upd_secgrpfrm;

/

show errors procedure cfsec213.upd_secgrpfrm;
