--
--	@(#) dbcreate/cfsec/pgsql/crsp_delete_sysclus.pgsql
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
create or replace function cfsec213.sp_delete_sysclus(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argSingletonId integer,
	argRevision int )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
	oldSingletonId integer;
	oldClusterId bigint;
	oldRevision int;
	permissionFlag boolean;
begin
		select
			sgltn_id,
			sys_clus_id,
			revision
		into
			oldSingletonId,
			oldClusterId,
			oldRevision
		from cfsec213.sysclus
		where
			sgltn_id = argSingletonId
		for update;

	select cfsec213.sp_is_system_user( argAuditUserId ) into permissionFlag;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- only system user can delete SysCluster records';
	end if;


	delete from cfsec213.sysclus
	where
		sgltn_id = argSingletonId;

	get diagnostics RowsAffected = row_count;
	if RowsAffected != 1 and RowsAffected != 0
	then
		raise exception 'sp_delete_sysclus() Expected to affect 1 sysclus, not %', RowsAffected;
	end if;

	return true;
end;
$$ language plpgsql;
