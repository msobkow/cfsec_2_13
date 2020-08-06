--
--	@(#) dbcreate/cfsec/oracle/crcrt_svctype.plsql
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

create or replace procedure cfsec213.crt_svctype(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argDescription varchar2 ) authid definer
is
	permissionDenied exception;
	use_stamp cfsec213.SvcType_h.auditstamp%type;
	permissionFlag integer;
	argServiceTypeId integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a013' )
	then
		permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	argServiceTypeId := cfsec213.nxt_servicetypeidgen();
	insert into cfsec213.svctype(
		createdby,
		createdat,
		updatedby,
		updatedat,
		ServiceTypeId,
		Description,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argServiceTypeId,
		argDescription,
		1 );
	insert into cfsec213.SvcType_h (
			ServiceTypeId,
			revision,
			auditclusterid,
			auditsessionid,
			Description,
			auditaction,
			auditstamp )
		select
			a013.ServiceTypeId as ServiceTypeId,
			a013.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a013.Description as Description,
			0,
			use_stamp
		from cfsec213.SvcType a013
		where
			a013.ServiceTypeId = argServiceTypeId;

	open retCursor for select
			a013.createdby,
			to_char( a013.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a013.updatedby,
			to_char( a013.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a013.ServiceTypeId as ServiceTypeId,
			a013.Description as Description,
		a013.revision as revision
	from cfsec213.SvcType a013
	where
		a013.ServiceTypeId = argServiceTypeId;
end crt_svctype;
/

show errors procedure cfsec213.crt_svctype;
