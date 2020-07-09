--
--	@(#) dbcreate/cfsec/pgsql/crsp_page_secdev_by_useridx.pgsql
--
--	org.msscf.msscf.CFSec
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
create or replace function cfsec213.sp_page_secdev_by_useridx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argSecUserId varchar(36),
	priorSecUserId varchar(36),
	priorDevName varchar(127) )
returns setof cfsec213.type_secdev_rec as $$
begin
	if( ( priorSecUserId is not null )and ( priorDevName is not null ) )
	then
		return query select
			a00a.createdby,
			to_char( a00a.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00a.updatedby,
			to_char( a00a.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00a.secuserid as secuserid,
			a00a.devname as devname,
			a00a.pubkey as pubkey,
			a00a.revision as revision
		from cfsec213.SecDev as a00a
		where
				a00a.secuserid = argSecUserId
			and ( ( ( a00a.SecUserId = priorSecUserId )
					and ( a00a.DevName < priorDevName ) )
				or ( ( a00a.SecUserId < priorSecUserId ) ) )
				order by SecUserId desc,
					DevName desc
			limit 25;
	else
		return query select
			a00a.createdby,
			to_char( a00a.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00a.updatedby,
			to_char( a00a.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00a.secuserid as secuserid,
			a00a.devname as devname,
			a00a.pubkey as pubkey,
			a00a.revision as revision
		from cfsec213.SecDev as a00a
		where
				a00a.secuserid = argSecUserId
				order by SecUserId desc,
					DevName desc
			limit 25;
	end if;
	return;
end
$$ language plpgsql;
