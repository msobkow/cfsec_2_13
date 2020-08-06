--
--	@(#) dbcreate/cfsec/pgsql/crsp_delete_secmemb_by_groupidx.pgsql
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
create or replace function cfsec213.sp_delete_secmemb_by_groupidx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClusterId bigint,
	argSecGroupId integer )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
begin
	select cfsec213.sp_is_system_user( argAuditUserId ) into subret;
	if( subret )
	then
		for cur in
			select
					a00f.clusterid as clusterid,
						a00f.secgrpmembid as secgrpmembid,
					a00f.revision as revision
			from cfsec213.SecMemb as a00f
			where
					a00f.clusterid = argClusterId
			and a00f.secgroupid = argSecGroupId
		loop
				select cfsec213.sp_delete_secmemb( argAuditClusterId,
						argAuditUserId,
						argAuditSessionId,
						secClusterId,
						secTenantId,
							cur.clusterid,
							cur.secgrpmembid,
						cur.revision )
					into subret;
		end loop;
	else
		for cur in
			select
					a00f.clusterid as clusterid,
						a00f.secgrpmembid as secgrpmembid,
					a00f.revision as revision
			from cfsec213.SecMemb as a00f
			where
					a00f.clusterid = argClusterId
			and a00f.secgroupid = argSecGroupId
					and a00f.ClusterId = secClusterId
		loop
				select cfsec213.sp_delete_secmemb( argAuditClusterId,
						argAuditUserId,
						argAuditSessionId,
						secClusterId,
						secTenantId,
							cur.clusterid,
							cur.secgrpmembid,
						cur.revision )
					into subret;
		end loop;
	end if;
	return true;
end;
$$ language plpgsql;
