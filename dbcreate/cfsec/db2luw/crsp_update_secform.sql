--
--	@(#) dbcreate/cfsec/db2luw/crsp_update_secform.sql
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

create or replace procedure sp_update_secform(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argClusterId bigint,	\
	in argSecFormId integer,	\
	in argSecAppId integer,	\
	in argJEEServletMapName varchar(192),	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldClusterId bigint;	\
	declare oldSecFormId integer;	\
	declare oldSecAppId integer;	\
	declare oldJEEServletMapName varchar(192);	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
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
		and a00b.secformid = argSecFormId;	\
	begin	\
		if( argClassCode = 'a00b' )	\
		then	\
			set( permissionFlag ) = ( sp_is_cluster_user( argClusterId,	\
					'UpdateSecForm',	\
					argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for UpdateSecForm' );	\
			end if;	\
		end if;	\
	\
		select	\
			ClusterId,	\
			SecFormId,	\
			SecAppId,	\
			JEEServletMapName,	\
			revision	\
		into	\
			oldClusterId,	\
			oldSecFormId,	\
			oldSecAppId,	\
			oldJEEServletMapName,	\
			oldRevision	\
		from cfsec213.SecForm	\
		where	\
			ClusterId = argClusterId	\
			and SecFormId = argSecFormId	\
		for update;	\
	\
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_secform() Data collision detected' );	\
		end if;	\
	\
		update cfsec213.SecForm	\
		set	\
			revision = argRevision + 1,	\
			updatedby = argAuditUserId,	\
			updatedat = current timestamp,	\
			secappid = argSecAppId,	\
			jeeservletmapname = argJEEServletMapName	\
		where	\
			clusterid = argClusterId	\
		and secformid = argSecFormId	\
		and revision = argRevision;	\
	\
		insert into cfsec213.SecForm_h (	\
				clusterid,	\
				secformid,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				secappid,	\
				jeeservletmapname,	\
			revision,	\
			auditaction )	\
		select	\
				a00b.clusterid,	\
				a00b.secformid,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a00b.secappid,	\
				a00b.jeeservletmapname,	\
			a00b.revision,	\
			2	\
		from cfsec213.SecForm as a00b	\
		where	\
			a00b.clusterid = argClusterId	\
		and a00b.secformid = argSecFormId;	\
	\
		open retcursor;	\
	end;	\
end
