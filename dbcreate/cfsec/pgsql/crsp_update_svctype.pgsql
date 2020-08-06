--
--	@(#) dbcreate/cfsec/pgsql/crsp_update_svctype.pgsql
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

create or replace function cfsec213.sp_update_svctype(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argServiceTypeId integer,
	argDescription varchar(50),
	argRevision integer )
returns setof cfsec213.type_svctype_rec as $$
declare
	RowsAffected integer;
	oldServiceTypeId integer;
	oldDescription varchar(50);
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a013' )
	then
		select cfsec213.sp_is_system_user( argAuditUserId ) into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- only system user can update ServiceType records';
		end if;
	end if;

		select
			ServiceTypeId,
			Description,
			revision
		into
			oldServiceTypeId,
			oldDescription,
			oldRevision
		from cfsec213.SvcType
		where
			ServiceTypeId = argServiceTypeId
		for update;


	if argRevision != oldRevision
	then
		raise exception 'sp_update_svctype() Data collision detected';
	end if;


	update cfsec213.SvcType
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		description = argDescription
	where
		ServiceTypeId = argServiceTypeId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_svctype() Expected to affect one SvcType row, not %', RowsAffected;
	end if;


	insert into cfsec213.SvcType_h (
			ServiceTypeId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			Description,
			revision,
			auditaction )
		select
			a013.ServiceTypeId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a013.Description,
			argRevision + 1,
			1
		from cfsec213.SvcType as a013
		where
			a013.servicetypeid = argServiceTypeId;
	return query select
			a013.createdby,
			to_char( a013.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a013.updatedby,
			to_char( a013.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a013.servicetypeid as servicetypeid,
			a013.description as description,
		a013.revision as revision
	from cfsec213.SvcType as a013
	where
		a013.servicetypeid = argServiceTypeId;

	return;
end;
$$ language plpgsql;
