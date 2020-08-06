--
--	@(#) dbcreate/cfsec/db2luw/crsp_update_secmemb.sql
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

create or replace procedure sp_update_secmemb(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argClusterId bigint,	\
	in argSecGrpMembId bigint,	\
	in argSecGroupId integer,	\
	in argSecUserId varchar(36),	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldClusterId bigint;	\
	declare oldSecGrpMembId bigint;	\
	declare oldSecGroupId integer;	\
	declare oldSecUserId varchar(36);	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
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
			a00f.clusterid = argClusterId	\
		and a00f.secgrpmembid = argSecGrpMembId;	\
	begin	\
		if( argClassCode = 'a00f' )	\
		then	\
			set( permissionFlag ) = ( sp_is_cluster_user( argClusterId,	\
					'UpdateSecGrpMemb',	\
					argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for UpdateSecGrpMemb' );	\
			end if;	\
		end if;	\
	\
		select	\
			ClusterId,	\
			SecGrpMembId,	\
			SecGroupId,	\
			SecUserId,	\
			revision	\
		into	\
			oldClusterId,	\
			oldSecGrpMembId,	\
			oldSecGroupId,	\
			oldSecUserId,	\
			oldRevision	\
		from cfsec213.SecMemb	\
		where	\
			ClusterId = argClusterId	\
			and SecGrpMembId = argSecGrpMembId	\
		for update;	\
	\
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_secmemb() Data collision detected' );	\
		end if;	\
	\
		update cfsec213.SecMemb	\
		set	\
			revision = argRevision + 1,	\
			updatedby = argAuditUserId,	\
			updatedat = current timestamp,	\
			secgroupid = argSecGroupId,	\
			secuserid = argSecUserId	\
		where	\
			clusterid = argClusterId	\
		and secgrpmembid = argSecGrpMembId	\
		and revision = argRevision;	\
	\
		insert into cfsec213.SecMemb_h (	\
				clusterid,	\
				secgrpmembid,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				secgroupid,	\
				secuserid,	\
			revision,	\
			auditaction )	\
		select	\
				a00f.clusterid,	\
				a00f.secgrpmembid,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a00f.secgroupid,	\
				a00f.secuserid,	\
			a00f.revision,	\
			2	\
		from cfsec213.SecMemb as a00f	\
		where	\
			a00f.clusterid = argClusterId	\
		and a00f.secgrpmembid = argSecGrpMembId;	\
	\
		open retcursor;	\
	end;	\
end
