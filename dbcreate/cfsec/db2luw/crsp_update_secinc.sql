--
--	@(#) dbcreate/cfsec/db2luw/crsp_update_secinc.sql
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

create or replace procedure sp_update_secinc(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argClusterId bigint,	\
	in argSecGrpIncId bigint,	\
	in argSecGroupId integer,	\
	in argIncludeGroupId integer,	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldClusterId bigint;	\
	declare oldSecGrpIncId bigint;	\
	declare oldSecGroupId integer;	\
	declare oldIncludeGroupId integer;	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
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
		and a00e.secgrpincid = argSecGrpIncId;	\
	begin	\
		if( argClassCode = 'a00e' )	\
		then	\
			set( permissionFlag ) = ( sp_is_cluster_user( argClusterId,	\
					'UpdateSecGrpInc',	\
					argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for UpdateSecGrpInc' );	\
			end if;	\
		end if;	\
	\
		select	\
			ClusId,	\
			SecGrpIncId,	\
			SecGrpId,	\
			IncGrpId,	\
			revision	\
		into	\
			oldClusterId,	\
			oldSecGrpIncId,	\
			oldSecGroupId,	\
			oldIncludeGroupId,	\
			oldRevision	\
		from cfsec213.SecInc	\
		where	\
			ClusId = argClusterId	\
			and SecGrpIncId = argSecGrpIncId	\
		for update;	\
	\
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_secinc() Data collision detected' );	\
		end if;	\
	\
		update cfsec213.SecInc	\
		set	\
			revision = argRevision + 1,	\
			updatedby = argAuditUserId,	\
			updatedat = current timestamp,	\
			secgrpid = argSecGroupId,	\
			incgrpid = argIncludeGroupId	\
		where	\
			clusid = argClusterId	\
		and secgrpincid = argSecGrpIncId	\
		and revision = argRevision;	\
	\
		insert into cfsec213.SecInc_h (	\
				clusid,	\
				secgrpincid,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				secgrpid,	\
				incgrpid,	\
			revision,	\
			auditaction )	\
		select	\
				a00e.clusid,	\
				a00e.secgrpincid,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a00e.secgrpid,	\
				a00e.incgrpid,	\
			a00e.revision,	\
			2	\
		from cfsec213.SecInc as a00e	\
		where	\
			a00e.clusid = argClusterId	\
		and a00e.secgrpincid = argSecGrpIncId;	\
	\
		open retcursor;	\
	end;	\
end
