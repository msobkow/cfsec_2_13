--
--	@(#) dbcreate/cfsec/oracle/crdl_secmemb.plsql
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

create or replace procedure cfsec213.dl_secmemb(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClusterId numeric,
	argSecGrpMembId numeric,
	argRevision int ) authid definer
is
	use_stamp cfsec213.SecMemb_h.auditstamp%type;
	oldClusterId numeric(22,0);
	oldSecGrpMembId numeric(22,0);
	oldSecGroupId integer;
	oldSecUserId varchar2(36);
	oldRevision integer;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
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

	if( oldClusterId != secClusterId )
	then
		permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	permissionFlag := cfsec213.sp_is_cluster_user( oldClusterId,
		'DeleteSecGrpMemb',
		argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
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
			2,
			use_stamp
		from cfsec213.SecMemb a00f
		where
			a00f.ClusterId = argClusterId
			and a00f.SecGrpMembId = argSecGrpMembId;

	delete from cfsec213.SecMemb
	where
		ClusterId = argClusterId
		and SecGrpMembId = argSecGrpMembId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_secmemb;
/

show errors procedure cfsec213.dl_secmemb;
