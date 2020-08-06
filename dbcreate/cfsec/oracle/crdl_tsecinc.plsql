--
--	@(#) dbcreate/cfsec/oracle/crdl_tsecinc.plsql
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

create or replace procedure cfsec213.dl_tsecinc(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argTenantId numeric,
	argTSecGrpIncId numeric,
	argRevision int ) authid definer
is
	use_stamp cfsec213.TSecInc_h.auditstamp%type;
	oldTenantId numeric(22,0);
	oldTSecGrpIncId numeric(22,0);
	oldTSecGrpId integer;
	oldIncGrpId integer;
	oldRevision integer;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
		select
			TenantId,
			TSecGrpIncId,
			TSecGrpId,
			IncGrpId,
			revision
		into
			oldTenantId,
			oldTSecGrpIncId,
			oldTSecGrpId,
			oldIncGrpId,
			oldRevision
		from cfsec213.TSecInc
		where
			TenantId = argTenantId
			and TSecGrpIncId = argTSecGrpIncId
		for update;

	if( oldTenantId != secTenantId )
	then
		permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	permissionFlag := cfsec213.sp_is_tenant_user( oldTenantId,
		'DeleteTSecGrpInc',
		argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;

	insert into cfsec213.TSecInc_h (
			TenantId,
			TSecGrpIncId,
			revision,
			auditclusterid,
			auditsessionid,
			TSecGrpId,
			IncGrpId,
			auditaction,
			auditstamp )
		select
			a017.TenantId as TenantId,
			a017.TSecGrpIncId as TSecGrpIncId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a017.TSecGrpId as TSecGrpId,
			a017.IncGrpId as IncGrpId,
			2,
			use_stamp
		from cfsec213.TSecInc a017
		where
			a017.TenantId = argTenantId
			and a017.TSecGrpIncId = argTSecGrpIncId;

	delete from cfsec213.TSecInc
	where
		TenantId = argTenantId
		and TSecGrpIncId = argTSecGrpIncId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_tsecinc;
/

show errors procedure cfsec213.dl_tsecinc;