--
--	@(#) dbcreate/cfsec/pgsql/crsp_is_tenant_user.pgsql
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
create or replace function cfsec213.sp_is_tenant_user(
	argTenantId bigint,
	argSecGroupName varchar(64),
	argSecUserId varchar(36) )
returns boolean as $$
declare
	retval boolean;
	cur record;
begin
	select false into retval;
	for cur in
			select
				susr.secuserid
			from cfsec213.SecUser as susr
			where
					susr.secuserid = argSecUserId
				and susr.login_id = 'system'
		union
			select
				smemb1.secuserid
			from cfsec213.TSecGrp sgrp1
				inner join cfsec213.TSecMemb smemb1 on
					smemb1.tenantid = sgrp1.tenantid
					and smemb1.tsecgroupid = sgrp1.tsecgroupid
			where
					sgrp1.tenantid = argTenantId
				and sgrp1.safe_name = argSecGroupName
				and smemb1.secuserid = argSecUserId
		union
			select
				smemb2.secuserid
			from cfsec213.TSecGrp sgrp2
				inner join cfsec213.TSecInc sinc2a on
					sinc2a.tenantid = sgrp2.tenantid
					and sinc2a.tsecgrpid = sgrp2.tsecgroupid
				inner join cfsec213.TSecMemb smemb2 on
					smemb2.tenantid = sinc2a.tenantid
					and smemb2.tsecgroupid = sinc2a.incgrpid
			where
					sgrp2.tenantid = argTenantId
				and sgrp2.safe_name = argSecGroupName
				and smemb2.secuserid = argSecUserId
		union
			select
				smemb3.secuserid
			from cfsec213.TSecGrp sgrp3
				inner join cfsec213.TSecInc sinc3a on
					sinc3a.tenantid = sgrp3.tenantid
					and sinc3a.tsecgrpid = sgrp3.tsecgroupid
				inner join cfsec213.TSecInc sinc3b on
					sinc3b.tenantid = sinc3a.tenantid
					and sinc3b.tsecgrpid = sinc3a.incgrpid
				inner join cfsec213.TSecMemb smemb3 on
					smemb3.tenantid = sinc3b.tenantid
					and smemb3.tsecgroupid = sinc3b.incgrpid
			where
					sgrp3.tenantid = argTenantId
				and sgrp3.safe_name = argSecGroupName
				and smemb3.secuserid = argSecUserId
		union
			select
				smemb4.secuserid
			from cfsec213.TSecGrp sgrp4
				inner join cfsec213.TSecInc sinc4a on
					sinc4a.tenantid = sgrp4.tenantid
					and sinc4a.tsecgrpid = sgrp4.tsecgroupid
				inner join cfsec213.TSecInc sinc4b on
					sinc4b.tenantid = sinc4a.tenantid
					and sinc4b.tsecgrpid = sinc4a.incgrpid
				inner join cfsec213.TSecInc sinc4c on
					sinc4c.tenantid = sinc4b.tenantid
					and sinc4c.tsecgrpid = sinc4b.incgrpid
				inner join cfsec213.TSecMemb smemb4 on
					smemb4.tenantid = sinc4c.tenantid
					and smemb4.tsecgroupid = sinc4c.incgrpid
			where
					sgrp4.tenantid = argTenantId
				and sgrp4.safe_name = argSecGroupName
				and smemb4.secuserid = argSecUserId
		union
			select
				smemb5.secuserid
			from cfsec213.TSecGrp sgrp5
				inner join cfsec213.TSecInc sinc5a on
					sinc5a.tenantid = sgrp5.tenantid
					and sinc5a.tsecgrpid = sgrp5.tsecgroupid
				inner join cfsec213.TSecInc sinc5b on
					sinc5b.tenantid = sinc5a.tenantid
					and sinc5b.tsecgrpid = sinc5a.incgrpid
				inner join cfsec213.TSecInc sinc5c on
					sinc5c.tenantid = sinc5b.tenantid
					and sinc5c.tsecgrpid = sinc5b.incgrpid
				inner join cfsec213.TSecInc sinc5d on
					sinc5d.tenantid = sinc5c.tenantid
					and sinc5d.tsecgrpid = sinc5c.incgrpid
				inner join cfsec213.TSecMemb smemb5 on
					smemb5.tenantid = sinc5d.tenantid
					and smemb5.tsecgroupid = sinc5d.incgrpid
			where
					sgrp5.tenantid = argTenantId
				and sgrp5.safe_name = argSecGroupName
				and smemb5.secuserid = argSecUserId
		union
			select
				smemb6.secuserid
			from cfsec213.TSecGrp sgrp6
				inner join cfsec213.TSecInc sinc6a on
					sinc6a.tenantid = sgrp6.tenantid
					and sinc6a.tsecgrpid = sgrp6.tsecgroupid
				inner join cfsec213.TSecInc sinc6b on
					sinc6b.tenantid = sinc6a.tenantid
					and sinc6b.tsecgrpid = sinc6a.incgrpid
				inner join cfsec213.TSecInc sinc6c on
					sinc6c.tenantid = sinc6b.tenantid
					and sinc6c.tsecgrpid = sinc6b.incgrpid
				inner join cfsec213.TSecInc sinc6d on
					sinc6d.tenantid = sinc6c.tenantid
					and sinc6d.tsecgrpid = sinc6c.incgrpid
				inner join cfsec213.TSecInc sinc6e on
					sinc6e.tenantid = sinc6d.tenantid
					and sinc6e.tsecgrpid = sinc6d.incgrpid
				inner join cfsec213.TSecMemb smemb6 on
					smemb6.tenantid = sinc6e.tenantid
					and smemb6.tsecgroupid = sinc6e.incgrpid
			where
					sgrp6.tenantid = argTenantId
				and sgrp6.safe_name = argSecGroupName
				and smemb6.secuserid = argSecUserId
		union
			select
				smemb7.secuserid
			from cfsec213.TSecGrp sgrp7
				inner join cfsec213.TSecInc sinc7a on
					sinc7a.tenantid = sgrp7.tenantid
					and sinc7a.tsecgrpid = sgrp7.tsecgroupid
				inner join cfsec213.TSecInc sinc7b on
					sinc7b.tenantid = sinc7a.tenantid
					and sinc7b.tsecgrpid = sinc7a.incgrpid
				inner join cfsec213.TSecInc sinc7c on
					sinc7c.tenantid = sinc7b.tenantid
					and sinc7c.tsecgrpid = sinc7b.incgrpid
				inner join cfsec213.TSecInc sinc7d on
					sinc7d.tenantid = sinc7c.tenantid
					and sinc7d.tsecgrpid = sinc7c.incgrpid
				inner join cfsec213.TSecInc sinc7e on
					sinc7e.tenantid = sinc7d.tenantid
					and sinc7e.tsecgrpid = sinc7d.incgrpid
				inner join cfsec213.TSecInc sinc7f on
					sinc7f.tenantid = sinc7e.tenantid
					and sinc7f.tsecgrpid = sinc7e.incgrpid
				inner join cfsec213.TSecMemb smemb7 on
					smemb7.tenantid = sinc7f.tenantid
					and smemb7.tsecgroupid = sinc7f.incgrpid
			where
					sgrp7.tenantid = argTenantId
				and sgrp7.safe_name = argSecGroupName
				and smemb7.secuserid = argSecUserId
		union
			select
				smemb8.secuserid
			from cfsec213.TSecGrp sgrp8
				inner join cfsec213.TSecInc sinc8a on
					sinc8a.tenantid = sgrp8.tenantid
					and sinc8a.tsecgrpid = sgrp8.tsecgroupid
				inner join cfsec213.TSecInc sinc8b on
					sinc8b.tenantid = sinc8a.tenantid
					and sinc8b.tsecgrpid = sinc8a.incgrpid
				inner join cfsec213.TSecInc sinc8c on
					sinc8c.tenantid = sinc8b.tenantid
					and sinc8c.tsecgrpid = sinc8b.incgrpid
				inner join cfsec213.TSecInc sinc8d on
					sinc8d.tenantid = sinc8c.tenantid
					and sinc8d.tsecgrpid = sinc8c.incgrpid
				inner join cfsec213.TSecInc sinc8e on
					sinc8e.tenantid = sinc8d.tenantid
					and sinc8e.tsecgrpid = sinc8d.incgrpid
				inner join cfsec213.TSecInc sinc8f on
					sinc8f.tenantid = sinc8e.tenantid
					and sinc8f.tsecgrpid = sinc8e.incgrpid
				inner join cfsec213.TSecInc sinc8g on
					sinc8g.tenantid = sinc8f.tenantid
					and sinc8g.tsecgrpid = sinc8f.incgrpid
				inner join cfsec213.TSecMemb smemb8 on
					smemb8.tenantid = sinc8g.tenantid
					and smemb8.tsecgroupid = sinc8g.incgrpid
			where
					sgrp8.tenantid = argTenantId
				and sgrp8.safe_name = argSecGroupName
				and smemb8.secuserid = argSecUserId
	loop
		select true into retval;
		exit;
	end loop;
	return retval;
end
$$ language plpgsql;
