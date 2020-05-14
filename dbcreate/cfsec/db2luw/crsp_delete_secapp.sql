--
--	@(#) dbcreate/cfsec/db2luw/crsp_delete_secapp.sql
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
