--
--	@(#) dbcreate/cfsec/db2luw/crsp_page_secinc_by_clusteridx.sql
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
create or replace procedure sp_page_secinc_by_clusteridx(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClusterId bigint,	\
	in priorClusterId bigint,	\
	in priorSecGrpIncId bigint )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare isSystemUser integer;	\
	declare syscurs cursor with return to client for	\
		select	\
				a00e.createdby as createdby,	\
				to_char( a00e.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00e.updatedby as updatedby,	\
				to_char( a00e.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00e.clusid as clusid,	\
			a00e.secgrpincid as secgrpincid,	\
			a00e.secgrpid as secgrpid,	\
			a00e.incgrpid as incgrpid,	\
			a00e.revision as revision	\
		from cfsec213.SecInc as a00e	\
		where	\
			a00e.clusid = argClusterId	\
		order by ClusId desc,	\
			SecGrpIncId desc	\
		fetch first 25 rows only;	\
	declare syspage cursor with return to client for	\
		select	\
				a00e.createdby as createdby,	\
				to_char( a00e.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00e.updatedby as updatedby,	\
				to_char( a00e.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00e.clusid as clusid,	\
			a00e.secgrpincid as secgrpincid,	\
			a00e.secgrpid as secgrpid,	\
			a00e.incgrpid as incgrpid,	\
			a00e.revision as revision	\
		from cfsec213.SecInc as a00e	\
		where	\
			a00e.clusid = argClusterId	\
			and ( ( ( a00e.ClusId = priorClusterId )	\
					and ( a00e.SecGrpIncId < priorSecGrpIncId ) )	\
				or ( ( a00e.ClusId < priorClusterId ) ) )	\
		order by ClusId desc,	\
			SecGrpIncId desc	\
		fetch first 25 rows only;	\
	declare usercurs cursor with return to client for	\
		select	\
				a00e.createdby as createdby,	\
				to_char( a00e.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00e.updatedby as updatedby,	\
				to_char( a00e.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00e.clusid as clusid,	\
			a00e.secgrpincid as secgrpincid,	\
			a00e.secgrpid as secgrpid,	\
			a00e.incgrpid as incgrpid,	\
			a00e.revision as revision	\
		from cfsec213.SecInc as a00e	\
		where	\
			a00e.clusid = argClusterId	\
			and ( a00e.ClusId = secClusterId )	\
		order by ClusId desc,	\
			SecGrpIncId desc	\
		fetch first 25 rows only;	\
	declare userpage cursor with return to client for	\
		select	\
				a00e.createdby as createdby,	\
				to_char( a00e.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00e.updatedby as updatedby,	\
				to_char( a00e.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00e.clusid as clusid,	\
			a00e.secgrpincid as secgrpincid,	\
			a00e.secgrpid as secgrpid,	\
			a00e.incgrpid as incgrpid,	\
			a00e.revision as revision	\
		from cfsec213.SecInc as a00e	\
		where	\
			a00e.clusid = argClusterId	\
			and ( a00e.ClusId = secClusterId )	\
			and ( ( ( a00e.ClusId = priorClusterId )	\
					and ( a00e.SecGrpIncId < priorSecGrpIncId ) )	\
				or ( ( a00e.ClusId < priorClusterId ) ) )	\
		order by ClusId desc,	\
			SecGrpIncId desc	\
		fetch first 25 rows only;	\
	begin	\
		set( permissionFlag ) = ( sp_is_cluster_user( secClusterId,	\
				'ReadSecGrpInc',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for ReadSecGrpInc' );	\
		end if;	\
		set( isSystemUser ) = ( sp_is_system_user( argAuditUserId ) );	\
		if( ( isSystemUser = 1 ) and ( ( priorClusterId is not null ) and ( priorSecGrpIncId is not null ) ) )	\
		then	\
			open syspage;	\
		end if;	\
		if( ( isSystemUser = 1 ) and ( not ( ( priorClusterId is not null ) and ( priorSecGrpIncId is not null ) ) ) )	\
		then	\
			open syscurs;	\
		end if;	\
		if( ( isSystemUser = 0 ) and ( ( priorClusterId is not null ) and ( priorSecGrpIncId is not null ) ) )	\
		then	\
			open userpage;	\
		end if;	\
		if( ( isSystemUser = 0 ) and ( not ( ( priorClusterId is not null ) and ( priorSecGrpIncId is not null ) ) ) )	\
		then	\
			open usercurs;	\
		end if;	\
	end;	\
end