--
--	@(#) dbcreate/cfsec/oracle/crdl_secmembbyididx.plsql
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

create or replace procedure cfsec213.dl_secmembbyididx(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClusterId numeric,
	argSecGrpMembId numeric ) authid definer
is
	unrecognizedClassCode exception;
	permissionFlag integer;
	cursor cursSystem is
		select
			a00f.ClusterId as ClusterId,
			a00f.SecGrpMembId as SecGrpMembId,
				a00f.revision as revision
		from cfsec213.SecMemb a00f
		where
				a00f.ClusterId = argClusterId
			and a00f.SecGrpMembId = argSecGrpMembId;
	cursor cursRestrict is
		select
			a00f.ClusterId as ClusterId,
			a00f.SecGrpMembId as SecGrpMembId,
				a00f.revision as revision
		from cfsec213.SecMemb a00f
		where
				a00f.ClusterId = argClusterId
			and a00f.SecGrpMembId = argSecGrpMembId
				and a00f.ClusterId = secClusterId;
begin
	permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 1 )
	then
		for cur in cursSystem
		loop
			cfsec213.dl_secmemb( argAuditClusterId,
					argAuditUserId,
					argAuditSessionId,
					secClusterId,
					secTenantId,
					cur.clusterid,
					cur.secgrpmembid,
					cur.revision );
		end loop;
	else
		for cur in cursRestrict
		loop
			cfsec213.dl_secmemb( argAuditClusterId,
					argAuditUserId,
					argAuditSessionId,
					secClusterId,
					secTenantId,
					cur.clusterid,
					cur.secgrpmembid,
					cur.revision );
		end loop;
	end if;
end dl_secmembbyididx;
/

show errors procedure cfsec213.dl_secmembbyididx;
