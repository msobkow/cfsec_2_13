--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_secapp.sql
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
create or replace procedure sp_delete_secapp(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClusterId bigint,	\
	in argSecAppId integer,	\
	in argRevision int )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldClusterId bigint;	\
	declare oldSecAppId integer;	\
	declare oldJEEMountName varchar(192);	\
	declare oldRevision int;	\
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
		select	\
			ClusterId,	\
			SecAppId,	\
			JEEMountName,	\
			revision	\
		into	\
			oldClusterId,	\
			oldSecAppId,	\
			oldJEEMountName,	\
			oldRevision	\
		from cfsec213.SecApp	\
		where	\
			ClusterId = argClusterId	\
			and SecAppId = argSecAppId	\
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
				'DeleteSecApp',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20002, 'Permission denied -- User not found in cluster SecGroup for DeleteSecApp' );	\
		end if;	\
	\
	\
		for cur as	\
			select	\
				a00b.clusterid as clusterid,	\
				a00b.secformid as secformid	\
			from cfsec213.SecApp as a009	\
				inner join cfsec213.secform a00b on 	\
					a009.clusterid = a00b.clusterid	\
					and a009.secappid = a00b.secappid	\
			where	\
				a009.clusterid = argClusterId	\
				and a009.secappid = argSecAppId	\
		do	\
			call sp_delete_secform_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					clusterid,	\
					secformid );	\
		end for;	\
	\
		insert into cfsec213.SecApp_h (	\
				clusterid,	\
				secappid,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				jeemountname,	\
			revision,	\
			auditaction )	\
		select	\
				a009.clusterid,	\
				a009.secappid,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a009.jeemountname,	\
			a009.revision + 1,	\
			2	\
		from cfsec213.SecApp as a009	\
		where	\
			a009.clusterid = argClusterId	\
		and a009.secappid = argSecAppId;	\
	\
		delete from cfsec213.SecApp	\
		where	\
			clusterid = argClusterId	\
			and secappid = argSecAppId;	\
	\
		open retcursor;	\
	end;	\
end