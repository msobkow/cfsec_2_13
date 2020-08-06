--
--	@(#) dbcreate/cfsec/pgsql/crsp_read_iso_cntryccy_by_ccyidx.pgsql
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
create or replace function cfsec213.sp_read_iso_cntryccy_by_ccyidx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argISOCcyId smallint )
returns setof cfsec213.type_iso_cntryccy_rec as $$
begin
	return query select
			a005.createdby,
			to_char( a005.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a005.updatedby,
			to_char( a005.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a005.isoctryid as isoctryid,
			a005.isoccyid as isoccyid,
			a005.revision as revision
	from cfsec213.iso_cntryccy as a005
	where
			a005.isoccyid = argISOCcyId
				order by ISOCtryId desc,
					ISOCcyId desc;
	return;
end
$$ language plpgsql;
