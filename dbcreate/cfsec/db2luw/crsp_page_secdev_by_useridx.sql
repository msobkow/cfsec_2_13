--
--	@(#) dbcreate/cfsec/db2luw/crsp_page_secdev_by_useridx.sql
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
create or replace procedure sp_page_secdev_by_useridx(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argSecUserId varchar(36),	\
	in priorSecUserId varchar(36),	\
	in priorDevName varchar(127) )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare isSystemUser integer;	\
	declare syscurs cursor with return to client for	\
		select	\
				a00a.createdby as createdby,	\
				to_char( a00a.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00a.updatedby as updatedby,	\
				to_char( a00a.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00a.secuserid as secuserid,	\
			a00a.devname as devname,	\
			a00a.pubkey as pubkey,	\
			a00a.revision as revision	\
		from cfsec213.SecDev as a00a	\
		where	\
			a00a.secuserid = argSecUserId	\
		order by SecUserId desc,	\
			DevName desc	\
		fetch first 25 rows only;	\
	declare syspage cursor with return to client for	\
		select	\
				a00a.createdby as createdby,	\
				to_char( a00a.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00a.updatedby as updatedby,	\
				to_char( a00a.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00a.secuserid as secuserid,	\
			a00a.devname as devname,	\
			a00a.pubkey as pubkey,	\
			a00a.revision as revision	\
		from cfsec213.SecDev as a00a	\
		where	\
			a00a.secuserid = argSecUserId	\
			and ( ( ( a00a.SecUserId = priorSecUserId )	\
					and ( a00a.DevName < priorDevName ) )	\
				or ( ( a00a.SecUserId < priorSecUserId ) ) )	\
		order by SecUserId desc,	\
			DevName desc	\
		fetch first 25 rows only;	\
	declare usercurs cursor with return to client for	\
		select	\
				a00a.createdby as createdby,	\
				to_char( a00a.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00a.updatedby as updatedby,	\
				to_char( a00a.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00a.secuserid as secuserid,	\
			a00a.devname as devname,	\
			a00a.pubkey as pubkey,	\
			a00a.revision as revision	\
		from cfsec213.SecDev as a00a	\
		where	\
			a00a.secuserid = argSecUserId	\
		order by SecUserId desc,	\
			DevName desc	\
		fetch first 25 rows only;	\
	declare userpage cursor with return to client for	\
		select	\
				a00a.createdby as createdby,	\
				to_char( a00a.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00a.updatedby as updatedby,	\
				to_char( a00a.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00a.secuserid as secuserid,	\
			a00a.devname as devname,	\
			a00a.pubkey as pubkey,	\
			a00a.revision as revision	\
		from cfsec213.SecDev as a00a	\
		where	\
			a00a.secuserid = argSecUserId	\
			and ( ( ( a00a.SecUserId = priorSecUserId )	\
					and ( a00a.DevName < priorDevName ) )	\
				or ( ( a00a.SecUserId < priorSecUserId ) ) )	\
		order by SecUserId desc,	\
			DevName desc	\
		fetch first 25 rows only;	\
	begin	\
		if( ( priorSecUserId is not null ) and ( priorDevName is not null ) )	\
		then	\
			open syspage;	\
		end if;	\
		if( not ( ( priorSecUserId is not null ) and ( priorDevName is not null ) ) )	\
		then	\
			open syscurs;	\
		end if;	\
	end;	\
end
