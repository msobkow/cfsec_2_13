--
--	@(#) dbcreate/cfsec/oracle/crupd_clus.plsql
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


create or replace procedure cfsec213.upd_clus(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argId numeric,
	argFullDomName varchar2,
	argDescription varchar2,
	argRevision integer ) authid definer
is
	use_stamp cfsec213.clus_h.auditstamp%type;
	oldId numeric(22,0);
	oldFullDomName varchar2(192);
	oldDescription varchar2(128);
	oldRevision integer;
	dataCollision exception;
	dataUpdateFailed exception;
	permissionDenied exception;
	permissionFlag integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a001' )
	then
		permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

		select
			Id,
			FullDomName,
			Description,
			revision
		into
			oldId,
			oldFullDomName,
			oldDescription,
			oldRevision
		from cfsec213.clus
		where
			Id = argId
		for update;

	if argRevision != oldRevision
	then
		raise dataCollision;
	end if;

	update cfsec213.clus
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = use_stamp,
		FullDomName = argFullDomName,
		Description = argDescription
	where
		Id = argId
		and revision = argRevision;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;


	insert into cfsec213.clus_h (
			Id,
			revision,
			auditclusterid,
			auditsessionid,
			FullDomName,
			Description,
			auditaction,
			auditstamp )
		select
			a001.Id as Id,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a001.FullDomName as FullDomName,
			a001.Description as Description,
			1,
			use_stamp
		from cfsec213.clus a001
		where
			a001.Id = argId;

	open retCursor for select
			a001.createdby,
			to_char( a001.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a001.updatedby,
			to_char( a001.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a001.Id as Id,
			a001.FullDomName as FullDomName,
			a001.Description as Description,
		a001.revision as revision
	from cfsec213.clus a001
	where
		a001.Id = argId;
end upd_clus;

/

show errors procedure cfsec213.upd_clus;
