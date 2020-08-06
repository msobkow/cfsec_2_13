--
--	@(#) dbcreate/cfsec/pgsql/crsp_update_secsess.pgsql
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

create or replace function cfsec213.sp_update_secsess(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argSecSessionId varchar(36),
	argSecUserId varchar(36),
	argSecDevName varchar(127),
	argStart timestamp,
	argFinish timestamp,
	argSecProxyId varchar(36),
	argRevision integer )
returns setof cfsec213.type_secsess_rec as $$
declare
	RowsAffected integer;
	oldSecSessionId varchar(36);
	oldSecUserId varchar(36);
	oldSecDevName varchar(127);
	oldStart timestamp;
	oldFinish timestamp;
	oldSecProxyId varchar(36);
	oldRevision int;
	permissionFlag boolean;
begin
		select
			SecSessionId,
			SecUserId,
			SecDevName,
			start_ts,
			finish_ts,
			SecProxyId,
			revision
		into
			oldSecSessionId,
			oldSecUserId,
			oldSecDevName,
			oldStart,
			oldFinish,
			oldSecProxyId,
			oldRevision
		from cfsec213.SecSess
		where
			SecSessionId = argSecSessionId
		for update;


	if argRevision != oldRevision
	then
		raise exception 'sp_update_secsess() Data collision detected';
	end if;


	update cfsec213.SecSess
	set
		revision = argRevision + 1,
		secuserid = argSecUserId,
		secdevname = argSecDevName,
		start_ts = argStart,
		finish_ts = argFinish,
		secproxyid = argSecProxyId
	where
		SecSessionId = argSecSessionId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_secsess() Expected to affect one SecSess row, not %', RowsAffected;
	end if;


	return query select
			a010.secsessionid as secsessionid,
			a010.secuserid as secuserid,
			a010.secdevname as secdevname,
			to_char( a010.start_ts, 'YYYY-MM-DD HH24:MI:SS' ) as start_ts,
			to_char( a010.finish_ts, 'YYYY-MM-DD HH24:MI:SS' ) as finish_ts,
			a010.secproxyid as secproxyid,
		a010.revision as revision
	from cfsec213.SecSess as a010
	where
		a010.secsessionid = argSecSessionId;

	return;
end;
$$ language plpgsql;
