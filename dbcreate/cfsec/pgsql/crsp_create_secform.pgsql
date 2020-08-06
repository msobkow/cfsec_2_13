--
--	@(#) dbcreate/cfsec/pgsql/crsp_create_secform.pgsql
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
create or replace function cfsec213.sp_create_secform(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argClusterId bigint,
	argSecAppId integer,
	argJEEServletMapName varchar(192) )
returns setof cfsec213.type_secform_rec as $$
declare
	permissionFlag boolean;
	argSecFormId integer;
begin
	if( argClassCode = 'a00b' )
	then
		select cfsec213.sp_is_cluster_user( argClusterId,
			'CreateSecForm',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in cluster SecGroup for CreateSecForm';
		end if;
	end if;

	select cfsec213.sp_next_secformidgen( argClusterId )
	into argSecFormId;

	insert into cfsec213.secform(
		createdby,
		createdat,
		updatedby,
		updatedat,
		clusterid,
		secformid,
		secappid,
		jeeservletmapname,
		revision )
	values (
		argAuditUserId,
		now(),
		argAuditUserId,
		now(),
		argClusterId,
		argSecFormId,
		argSecAppId,
		argJEEServletMapName,
		1 );
	insert into cfsec213.SecForm_h (
			ClusterId,
			SecFormId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			SecAppId,
			JEEServletMapName,
			revision,
			auditaction )
		select
			a00b.ClusterId,
			a00b.SecFormId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a00b.SecAppId,
			a00b.JEEServletMapName,
			a00b.revision,
			0
		from cfsec213.SecForm as a00b
		where
			a00b.clusterid = argClusterId
			and a00b.secformid = argSecFormId;

	return query select
			a00b.createdby,
			to_char( a00b.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00b.updatedby,
			to_char( a00b.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00b.clusterid as clusterid,
			a00b.secformid as secformid,
			a00b.secappid as secappid,
			a00b.jeeservletmapname as jeeservletmapname,
			a00b.revision as revision
	from cfsec213.SecForm as a00b
	where
			a00b.clusterid = argClusterId
			and a00b.secformid = argSecFormId;

	return;
end;
$$ language plpgsql;
