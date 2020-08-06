--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_secgrpfrm.sql
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
create or replace procedure sp_delete_secgrpfrm(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClusterId bigint,	\
	in argSecGroupFormId bigint,	\
	in argRevision int )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldClusterId bigint;	\
	declare oldSecGroupFormId bigint;	\
	declare oldSecGroupId integer;	\
	declare oldSecAppId integer;	\
	declare oldSecFormId integer;	\
	declare oldRevision int;	\
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
		select	\
			ClusId,	\
			SecGrpFrmId,	\
			SecGrpId,	\
			SecAppId,	\
			SecFrmId,	\
			revision	\
		into	\
			oldClusterId,	\
			oldSecGroupFormId,	\
			oldSecGroupId,	\
			oldSecAppId,	\
			oldSecFormId,	\
			oldRevision	\
		from cfsec213.SecGrpFrm	\
		where	\
			ClusId = argClusterId	\
			and SecGrpFrmId = argSecGroupFormId	\
		for update;	\
	\
		if( oldClusterId != secClusterId )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20002, 'Permission denied -- Data is not owned by logged in cluster' );	\
			end if;	\
		end if;	\
	\
		set( permissionFlag ) = ( sp_is_cluster_user( oldClusterId,	\
				'DeleteSecGroupForm',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for DeleteSecGroupForm' );	\
		end if;	\
	\
	\
		insert into cfsec213.SecGrpFrm_h (	\
				clusid,	\
				secgrpfrmid,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				secgrpid,	\
				secappid,	\
				secfrmid,	\
			revision,	\
			auditaction )	\
		select	\
				a00d.clusid,	\
				a00d.secgrpfrmid,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a00d.secgrpid,	\
				a00d.secappid,	\
				a00d.secfrmid,	\
			a00d.revision + 1,	\
			2	\
		from cfsec213.SecGrpFrm as a00d	\
		where	\
			a00d.clusid = argClusterId	\
		and a00d.secgrpfrmid = argSecGroupFormId;	\
	\
		delete from cfsec213.SecGrpFrm	\
		where	\
			clusid = argClusterId	\
			and secgrpfrmid = argSecGroupFormId;	\
	\
		open retcursor;	\
	end;	\
end
