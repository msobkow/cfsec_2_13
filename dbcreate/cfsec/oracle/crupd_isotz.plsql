--
--	@(#) dbcreate/cfsec/oracle/crupd_isotz.plsql
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


create or replace procedure cfsec213.upd_isotz(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argISOTZoneId smallint,
	argIso8601 varchar2,
	argTZName varchar2,
	argTZHourOffset smallint,
	argTZMinOffset smallint,
	argDescription varchar2,
	argVisible char,
	argRevision integer ) authid definer
is
	use_stamp cfsec213.ISOTz_h.auditstamp%type;
	oldISOTZoneId smallint;
	oldIso8601 varchar2(6);
	oldTZName varchar2(64);
	oldTZHourOffset smallint;
	oldTZMinOffset smallint;
	oldDescription varchar2(128);
	oldVisible char(1);
	oldRevision integer;
	dataCollision exception;
	dataUpdateFailed exception;
	permissionDenied exception;
	permissionFlag integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a008' )
	then
		permissionFlag := cfsec213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

		select
			ISOTZoneId,
			Iso8601,
			TZName,
			TZHourOffset,
			TZMinOffset,
			Description,
			Visible,
			revision
		into
			oldISOTZoneId,
			oldIso8601,
			oldTZName,
			oldTZHourOffset,
			oldTZMinOffset,
			oldDescription,
			oldVisible,
			oldRevision
		from cfsec213.ISOTz
		where
			ISOTZoneId = argISOTZoneId
		for update;

	if argRevision != oldRevision
	then
		raise dataCollision;
	end if;

	update cfsec213.ISOTz
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = use_stamp,
		Iso8601 = argIso8601,
		TZName = argTZName,
		TZHourOffset = argTZHourOffset,
		TZMinOffset = argTZMinOffset,
		Description = argDescription,
		Visible = argVisible
	where
		ISOTZoneId = argISOTZoneId
		and revision = argRevision;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;


	insert into cfsec213.ISOTz_h (
			ISOTZoneId,
			revision,
			auditclusterid,
			auditsessionid,
			Iso8601,
			TZName,
			TZHourOffset,
			TZMinOffset,
			Description,
			Visible,
			auditaction,
			auditstamp )
		select
			a008.ISOTZoneId as ISOTZoneId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a008.Iso8601 as Iso8601,
			a008.TZName as TZName,
			a008.TZHourOffset as TZHourOffset,
			a008.TZMinOffset as TZMinOffset,
			a008.Description as Description,
			a008.Visible as Visible,
			1,
			use_stamp
		from cfsec213.ISOTz a008
		where
			a008.ISOTZoneId = argISOTZoneId;

	open retCursor for select
			a008.createdby,
			to_char( a008.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a008.updatedby,
			to_char( a008.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a008.ISOTZoneId as ISOTZoneId,
			a008.Iso8601 as Iso8601,
			a008.TZName as TZName,
			a008.TZHourOffset as TZHourOffset,
			a008.TZMinOffset as TZMinOffset,
			a008.Description as Description,
			a008.Visible as Visible,
		a008.revision as revision
	from cfsec213.ISOTz a008
	where
		a008.ISOTZoneId = argISOTZoneId;
end upd_isotz;

/

show errors procedure cfsec213.upd_isotz;
