--
--	@(#) dbcreate/cfsec/pgsql/crsp_create_clus.pgsql
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
create or replace function cfsec213.sp_create_clus(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argFullDomName varchar(192),
	argDescription varchar(128) )
returns setof cfsec213.type_clus_rec as $$
declare
	permissionFlag boolean;
	argId bigint;
begin
	if( argClassCode = 'a001' )
	then
		select cfsec213.sp_is_system_user( argAuditUserId ) into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- only system user can create Cluster records';
		end if;
	end if;

	select cfsec213.sp_next_clusteridgen()
	into argId;

	insert into cfsec213.clus(
		createdby,
		createdat,
		updatedby,
		updatedat,
		id,
		fulldomname,
		description,
		revision )
	values (
		argAuditUserId,
		now(),
		argAuditUserId,
		now(),
		argId,
		argFullDomName,
		argDescription,
		1 );
	insert into cfsec213.clus_h (
			Id,
			auditclusterid,
			auditsessionid,
			auditstamp,
			FullDomName,
			Description,
			revision,
			auditaction )
		select
			a001.Id,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a001.FullDomName,
			a001.Description,
			a001.revision,
			0
		from cfsec213.clus as a001
		where
			a001.id = argId;

	return query select
			a001.createdby,
			to_char( a001.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a001.updatedby,
			to_char( a001.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a001.id as id,
			a001.fulldomname as fulldomname,
			a001.description as description,
			a001.revision as revision
	from cfsec213.clus as a001
	where
			a001.id = argId;

	return;
end;
$$ language plpgsql;
