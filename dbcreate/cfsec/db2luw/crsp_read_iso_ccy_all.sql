--
--	@(#) dbcreate/cfsec/db2luw/crsp_read_iso_ccy_all.sql
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
create or replace procedure sp_read_iso_ccy_all(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare isSystemUser integer;	\
	declare syscurs cursor with return to client for	\
		select	\
				a003.createdby as createdby,	\
				to_char( a003.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a003.updatedby as updatedby,	\
				to_char( a003.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a003.isoccyid as isoccyid,	\
			a003.iso_code as iso_code,	\
			a003.ccy_name as ccy_name,	\
			a003.unit_symbol as unit_symbol,	\
			a003.precis as precis,	\
			a003.revision as revision	\
		from cfsec213.iso_ccy as a003	\
		order by ISOCcyId desc;	\
	declare usercurs cursor with return to client for	\
		select	\
				a003.createdby as createdby,	\
				to_char( a003.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a003.updatedby as updatedby,	\
				to_char( a003.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a003.isoccyid as isoccyid,	\
			a003.iso_code as iso_code,	\
			a003.ccy_name as ccy_name,	\
			a003.unit_symbol as unit_symbol,	\
			a003.precis as precis,	\
			a003.revision as revision	\
		from cfsec213.iso_ccy as a003	\
		order by ISOCcyId desc;	\
	begin	\
		open syscurs;	\
	end;	\
end
