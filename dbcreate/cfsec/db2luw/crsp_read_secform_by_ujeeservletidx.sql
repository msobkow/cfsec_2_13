--
--	@(#) dbcreate/cfsec/db2luw/crsp_read_secform_by_ujeeservletidx.sql
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
create or replace procedure sp_read_secform_by_ujeeservletidx(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClusterId bigint,	\
	in argSecAppId integer,	\
	in argJEEServletMapName varchar(192) )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare isSystemUser integer;	\
	declare syscurs cursor with return to client for	\
		select	\
				a00b.createdby as createdby,	\
				to_char( a00b.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00b.updatedby as updatedby,	\
				to_char( a00b.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00b.clusterid as clusterid,	\
			a00b.secformid as secformid,	\
			a00b.secappid as secappid,	\
			a00b.jeeservletmapname as jeeservletmapname,	\
			a00b.revision as revision	\
		from cfsec213.SecForm as a00b	\
		where	\
			a00b.clusterid = argClusterId	\
		and a00b.secappid = argSecAppId	\
		and a00b.jeeservletmapname = argJEEServletMapName;	\
	declare usercurs cursor with return to client for	\
		select	\
				a00b.createdby as createdby,	\
				to_char( a00b.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00b.updatedby as updatedby,	\
				to_char( a00b.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00b.clusterid as clusterid,	\
			a00b.secformid as secformid,	\
			a00b.secappid as secappid,	\
			a00b.jeeservletmapname as jeeservletmapname,	\
			a00b.revision as revision	\
		from cfsec213.SecForm as a00b	\
		where	\
			a00b.clusterid = argClusterId	\
		and a00b.secappid = argSecAppId	\
		and a00b.jeeservletmapname = argJEEServletMapName	\
			and ( a00b.ClusterId = secClusterId );	\
	begin	\
		set( permissionFlag ) = ( sp_is_cluster_user( secClusterId,	\
				'ReadSecForm',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for ReadSecForm' );	\
		end if;	\
		set( isSystemUser ) = ( sp_is_system_user( argAuditUserId ) );	\
		if( isSystemUser = 1 )	\
		then	\
			open syscurs;	\
		else	\
			open usercurs;	\
		end if;	\
	end;	\
end