--
--	@(#) dbcreate/cfsec/oracle/crupd_secgrp.plsql
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


create or replace procedure cfsec213.upd_secgrp(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argClusterId numeric,
	argSecGroupId integer,
	argsafe_name varchar2,
	argIsVisible char,
	argRevision integer ) authid definer
is
	use_stamp cfsec213.SecGrp_h.auditstamp%type;
	oldClusterId numeric(22,0);
	oldSecGroupId integer;
	oldsafe_name varchar2(64);
	oldIsVisible char(1);
	oldRevision integer;
	dataCollision exception;
	dataUpdateFailed exception;
	permissionDenied exception;
	permissionFlag integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a00c' )
	then
		permissionFlag := cfsec213.sp_is_cluster_user( argClusterId,
			'UpdateSecGroup',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

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

	if argRevision != oldRevision
	then
		raise dataCollision;
	end if;

	update cfsec213.SecGrp
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = use_stamp,
		safe_name = argsafe_name,
		IsVisible = argIsVisible
	where
		ClusterId = argClusterId
		and SecGroupId = argSecGroupId
		and revision = argRevision;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
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
			1,
			use_stamp
		from cfsec213.SecGrp a00c
		where
			a00c.ClusterId = argClusterId
			and a00c.SecGroupId = argSecGroupId;

	open retCursor for select
			a00c.createdby,
			to_char( a00c.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00c.updatedby,
			to_char( a00c.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00c.ClusterId as ClusterId,
			a00c.SecGroupId as SecGroupId,
			a00c.safe_name as safe_name,
			a00c.IsVisible as IsVisible,
		a00c.revision as revision
	from cfsec213.SecGrp a00c
	where
		a00c.ClusterId = argClusterId
			and a00c.SecGroupId = argSecGroupId;
end upd_secgrp;

/

show errors procedure cfsec213.upd_secgrp;
