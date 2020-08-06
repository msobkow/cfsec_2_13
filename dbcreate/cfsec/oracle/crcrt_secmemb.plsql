--
--	@(#) dbcreate/cfsec/oracle/crcrt_secmemb.plsql
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

create or replace procedure cfsec213.crt_secmemb(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argClusterId numeric,
	argSecGroupId integer,
	argSecUserId varchar2 ) authid definer
is
	permissionDenied exception;
	use_stamp cfsec213.SecMemb_h.auditstamp%type;
	permissionFlag integer;
	argSecGrpMembId numeric;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a00f' )
	then
		permissionFlag := cfsec213.sp_is_cluster_user( argClusterId,
			'CreateSecGrpMemb',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	argSecGrpMembId := cfsec213.nxt_secgrpmembidgen( argClusterId );
	insert into cfsec213.secmemb(
		createdby,
		createdat,
		updatedby,
		updatedat,
		ClusterId,
		SecGrpMembId,
		SecGroupId,
		SecUserId,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argClusterId,
		argSecGrpMembId,
		argSecGroupId,
		argSecUserId,
		1 );
	insert into cfsec213.SecMemb_h (
			ClusterId,
			SecGrpMembId,
			revision,
			auditclusterid,
			auditsessionid,
			SecGroupId,
			SecUserId,
			auditaction,
			auditstamp )
		select
			a00f.ClusterId as ClusterId,
			a00f.SecGrpMembId as SecGrpMembId,
			a00f.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a00f.SecGroupId as SecGroupId,
			a00f.SecUserId as SecUserId,
			0,
			use_stamp
		from cfsec213.SecMemb a00f
		where
			a00f.ClusterId = argClusterId
			and a00f.SecGrpMembId = argSecGrpMembId;

	open retCursor for select
			a00f.createdby,
			to_char( a00f.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00f.updatedby,
			to_char( a00f.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00f.ClusterId as ClusterId,
			a00f.SecGrpMembId as SecGrpMembId,
			a00f.SecGroupId as SecGroupId,
			a00f.SecUserId as SecUserId,
		a00f.revision as revision
	from cfsec213.SecMemb a00f
	where
		a00f.ClusterId = argClusterId
			and a00f.SecGrpMembId = argSecGrpMembId;
end crt_secmemb;
/

show errors procedure cfsec213.crt_secmemb;
