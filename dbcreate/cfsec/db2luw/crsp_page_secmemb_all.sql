--
--	@(#) dbcreate/cfsec/db2luw/crsp_page_secmemb_all.sql
--
--	com.github.msobkow.CFSec
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	This file is part of MSS Code Factory.
--	
--	Licensed under the Apache License, Version 2.0 (the "License");
--	you may not use this file except in compliance with the License.
--	You may obtain a copy of the License at
--	
--	    http://www.apache.org/licenses/LICENSE-2.0
--	
--	Unless required by applicable law or agreed to in writing, software
--	distributed under the License is distributed on an "AS IS" BASIS,
--	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
--	See the License for the specific language governing permissions and
--	limitations under the License.
--	
--	Donations to support MSS Code Factory can be made at
--	https://www.paypal.com/paypalme2/MarkSobkow
--
--	Manufactured by MSS Code Factory 2.12
--
create or replace procedure sp_page_secmemb_all(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in priorClusterId bigint,	\
	in priorSecGrpMembId bigint )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare isSystemUser integer;	\
	declare syscurs cursor with return to client for	\
		select	\
				a00f.createdby as createdby,	\
				to_char( a00f.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00f.updatedby as updatedby,	\
				to_char( a00f.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00f.clusterid as clusterid,	\
			a00f.secgrpmembid as secgrpmembid,	\
			a00f.secgroupid as secgroupid,	\
			a00f.secuserid as secuserid,	\
			a00f.revision as revision	\
		from cfsec213.SecMemb as a00f	\
		order by ClusterId desc,	\
			SecGrpMembId desc	\
		fetch first 25 rows only;	\
	declare syspage cursor with return to client for	\
		select	\
				a00f.createdby as createdby,	\
				to_char( a00f.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00f.updatedby as updatedby,	\
				to_char( a00f.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00f.clusterid as clusterid,	\
			a00f.secgrpmembid as secgrpmembid,	\
			a00f.secgroupid as secgroupid,	\
			a00f.secuserid as secuserid,	\
			a00f.revision as revision	\
		from cfsec213.SecMemb as a00f	\
		where ( ( ( a00f.ClusterId = priorClusterId )	\
					and ( a00f.SecGrpMembId < priorSecGrpMembId ) )	\
				or ( ( a00f.ClusterId < priorClusterId ) ) )	\
		order by ClusterId desc,	\
			SecGrpMembId desc	\
		fetch first 25 rows only;	\
	declare usercurs cursor with return to client for	\
		select	\
				a00f.createdby as createdby,	\
				to_char( a00f.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00f.updatedby as updatedby,	\
				to_char( a00f.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00f.clusterid as clusterid,	\
			a00f.secgrpmembid as secgrpmembid,	\
			a00f.secgroupid as secgroupid,	\
			a00f.secuserid as secuserid,	\
			a00f.revision as revision	\
		from cfsec213.SecMemb as a00f	\
		where	\
			a00f.clusterid = secClusterId	\
		order by ClusterId desc,	\
			SecGrpMembId desc	\
		fetch first 25 rows only;	\
	declare userpage cursor with return to client for	\
		select	\
				a00f.createdby as createdby,	\
				to_char( a00f.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00f.updatedby as updatedby,	\
				to_char( a00f.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00f.clusterid as clusterid,	\
			a00f.secgrpmembid as secgrpmembid,	\
			a00f.secgroupid as secgroupid,	\
			a00f.secuserid as secuserid,	\
			a00f.revision as revision	\
		from cfsec213.SecMemb as a00f	\
		where	\
			a00f.clusterid = secClusterId	\
			and ( ( ( a00f.ClusterId = priorClusterId )	\
					and ( a00f.SecGrpMembId < priorSecGrpMembId ) )	\
				or ( ( a00f.ClusterId < priorClusterId ) ) )	\
		order by ClusterId desc,	\
			SecGrpMembId desc	\
		fetch first 25 rows only;	\
	begin	\
		set( permissionFlag ) = ( sp_is_cluster_user( secClusterId,	\
				'ReadSecGrpMemb',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for ReadSecGrpMemb' );	\
		end if;	\
		set( isSystemUser ) = ( sp_is_system_user( argAuditUserId ) );	\
		if( ( isSystemUser = 1 ) and ( ( priorClusterId is not null ) and ( priorSecGrpMembId is not null ) ) )	\
		then	\
			open syspage;	\
		end if;	\
		if( ( isSystemUser = 1 ) and ( not ( ( priorClusterId is not null ) and ( priorSecGrpMembId is not null ) ) ) )	\
		then	\
			open syscurs;	\
		end if;	\
		if( ( isSystemUser = 0 ) and ( ( priorClusterId is not null ) and ( priorSecGrpMembId is not null ) ) )	\
		then	\
			open userpage;	\
		end if;	\
		if( ( isSystemUser = 0 ) and ( not ( ( priorClusterId is not null ) and ( priorSecGrpMembId is not null ) ) ) )	\
		then	\
			open usercurs;	\
		end if;	\
	end;	\
end
