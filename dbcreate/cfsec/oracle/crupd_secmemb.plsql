--
--	@(#) dbcreate/cfsec/oracle/crupd_secmemb.plsql
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


create or replace procedure cfsec213.upd_secmemb(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argClusterId numeric,
	argSecGrpMembId numeric,
	argSecGroupId integer,
	argSecUserId varchar2,
	argRevision integer ) authid definer
is
	use_stamp cfsec213.SecMemb_h.auditstamp%type;
	oldClusterId numeric(22,0);
	oldSecGrpMembId numeric(22,0);
	oldSecGroupId integer;
	oldSecUserId varchar2(36);
	oldRevision integer;
	dataCollision exception;
	dataUpdateFailed exception;
	permissionDenied exception;
	permissionFlag integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a00f' )
	then
		permissionFlag := cfsec213.sp_is_cluster_user( argClusterId,
			'UpdateSecGrpMemb',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

		select
			ClusterId,
			SecGrpMembId,
			SecGroupId,
			SecUserId,
			revision
		into
			oldClusterId,
			oldSecGrpMembId,
			oldSecGroupId,
			oldSecUserId,
			oldRevision
		from cfsec213.SecMemb
		where
			ClusterId = argClusterId
			and SecGrpMembId = argSecGrpMembId
		for update;

	if argRevision != oldRevision
	then
		raise dataCollision;
	end if;

	update cfsec213.SecMemb
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = use_stamp,
		SecGroupId = argSecGroupId,
		SecUserId = argSecUserId
	where
		ClusterId = argClusterId
		and SecGrpMembId = argSecGrpMembId
		and revision = argRevision;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;


	insert into cfsec213.SecMemb_h (
			ClusterId,
			SecGrpMembId,
			revision,
			auditclusterid,
			auditsessionid,
			SecGroupId,
			SecUserId,
			auditaction,
			auditstamp )
		select
			a00f.ClusterId as ClusterId,
			a00f.SecGrpMembId as SecGrpMembId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a00f.SecGroupId as SecGroupId,
			a00f.SecUserId as SecUserId,
			1,
			use_stamp
		from cfsec213.SecMemb a00f
		where
			a00f.ClusterId = argClusterId
			and a00f.SecGrpMembId = argSecGrpMembId;

	open retCursor for select
			a00f.createdby,
			to_char( a00f.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00f.updatedby,
			to_char( a00f.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00f.ClusterId as ClusterId,
			a00f.SecGrpMembId as SecGrpMembId,
			a00f.SecGroupId as SecGroupId,
			a00f.SecUserId as SecUserId,
		a00f.revision as revision
	from cfsec213.SecMemb a00f
	where
		a00f.ClusterId = argClusterId
			and a00f.SecGrpMembId = argSecGrpMembId;
end upd_secmemb;

/

show errors procedure cfsec213.upd_secmemb;
