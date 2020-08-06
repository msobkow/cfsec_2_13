--
--	@(#) dbcreate/cfsec/oracle/crdl_secincbyididx.plsql
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

create or replace procedure cfsec213.dl_secincbyididx(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClusId numeric,
	argSecGrpIncId numeric ) authid definer
is
	unrecognizedClassCode exception;
	permissionFlag integer;
	cursor cursSystem is
		select
			a00e.ClusId as ClusId,
			a00e.SecGrpIncId as SecGrpIncId,
				a00e.revision as revision
		from cfsec213.SecInc a00e
		where
				a00e.ClusId = argClusId
			and a00e.SecGrpIncId = argSecGrpIncId;
	cursor cursRestrict is
		select
			a00e.ClusId as ClusId,
			a00e.SecGrpIncId as SecGrpIncId,
				a00e.revision as revision
		from cfsec213.SecInc a00e
		where
				a00e.ClusId = argClusId
			and a00e.SecGrpIncId = argSecGrpIncId
				and a00e.ClusId = secClusterId;
begin
	permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 1 )
	then
		for cur in cursSystem
		loop
			cfsec213.dl_secinc( argAuditClusterId,
					argAuditUserId,
					argAuditSessionId,
					secClusterId,
					secTenantId,
					cur.clusid,
					cur.secgrpincid,
					cur.revision );
		end loop;
	else
		for cur in cursRestrict
		loop
			cfsec213.dl_secinc( argAuditClusterId,
					argAuditUserId,
					argAuditSessionId,
					secClusterId,
					secTenantId,
					cur.clusid,
					cur.secgrpincid,
					cur.revision );
		end loop;
	end if;
end dl_secincbyididx;
/

show errors procedure cfsec213.dl_secincbyididx;
