--
--	@(#) dbcreate/cfsec/pgsql/crsp_page_secsess_by_secproxyidx.pgsql
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
create or replace function cfsec213.sp_page_secsess_by_secproxyidx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argSecProxyId varchar(36),
	priorSecSessionId varchar(36) )
returns setof cfsec213.type_secsess_rec as $$
begin
	if( ( priorSecSessionId is not null ) )
	then
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
				( ( ( argSecProxyId is null ) and ( a010.secproxyid is null ) )
				or ( ( argSecProxyId is not null ) and ( a010.secproxyid = argSecProxyId ) ) )
			and ( ( ( a010.SecSessionId < priorSecSessionId ) ) )
				order by SecSessionId desc
			limit 25;
	else
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
				( ( ( argSecProxyId is null ) and ( a010.secproxyid is null ) )
				or ( ( argSecProxyId is not null ) and ( a010.secproxyid = argSecProxyId ) ) )
				order by SecSessionId desc
			limit 25;
	end if;
	return;
end
$$ language plpgsql;
