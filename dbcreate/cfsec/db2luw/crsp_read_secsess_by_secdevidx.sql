--
--	@(#) dbcreate/cfsec/db2luw/crsp_read_secsess_by_secdevidx.sql
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
create or replace procedure sp_read_secsess_by_secdevidx(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argSecUserId varchar(36),	\
	in argSecDevName varchar(127) )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare isSystemUser integer;	\
	declare syscurs cursor with return to client for	\
		select	\
				a010.secsessionid as secsessionid,	\
			a010.secuserid as secuserid,	\
			a010.secdevname as secdevname,	\
			to_char( a010.start_ts, 'YYYY-MM-DD-HH24.MI.SS' ) as start_ts,	\
			to_char( a010.finish_ts, 'YYYY-MM-DD-HH24.MI.SS' ) as finish_ts,	\
			a010.secproxyid as secproxyid,	\
			a010.revision as revision	\
		from cfsec213.SecSess as a010	\
		where	\
			a010.secuserid = argSecUserId	\
		and ( ( ( argSecDevName is null ) and ( a010.secdevname is null ) )	\
				or ( ( argSecDevName is not null ) and ( a010.secdevname = argSecDevName ) ) )	\
		order by SecSessionId desc;	\
	declare usercurs cursor with return to client for	\
		select	\
				a010.secsessionid as secsessionid,	\
			a010.secuserid as secuserid,	\
			a010.secdevname as secdevname,	\
			to_char( a010.start_ts, 'YYYY-MM-DD-HH24.MI.SS' ) as start_ts,	\
			to_char( a010.finish_ts, 'YYYY-MM-DD-HH24.MI.SS' ) as finish_ts,	\
			a010.secproxyid as secproxyid,	\
			a010.revision as revision	\
		from cfsec213.SecSess as a010	\
		where	\
			a010.secuserid = argSecUserId	\
		and ( ( ( argSecDevName is null ) and ( a010.secdevname is null ) )	\
				or ( ( argSecDevName is not null ) and ( a010.secdevname = argSecDevName ) ) )	\
		order by SecSessionId desc;	\
	begin	\
		open syscurs;	\
	end;	\
end