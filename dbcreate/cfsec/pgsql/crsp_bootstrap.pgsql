--
--	@(#) dbcreate/cfsec/pgsql/crsp_bootstrap.pgsql
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
create or replace function cfsec213.sp_bootstrap()
returns boolean as $$
declare
	curtime timestamp;
	clusid bigint;
begin

	select now() into curtime;




	-- Bootstrap core data

	insert into cfsec213.SecUser (
		createdat,
		createdby,
		updatedat,
		updatedby,
		secuserid,
		login_id,
		email_addr,
		pwd_hash,
		revision )
	values (
		curtime,
		'654dbba0-eda7-11e1-aff1-0800200c9a66',
		curtime,
		'654dbba0-eda7-11e1-aff1-0800200c9a66',
		'654dbba0-eda7-11e1-aff1-0800200c9a66',
		'system',
		'root',
		'bootstrap',
		1 );

	insert into cfsec213.clus (
		createdat,
		createdby,
		updatedat,
		updatedby,
		id,
		fulldomainname,
		description,
		revision )
	values (
		curtime,
		'654dbba0-eda7-11e1-aff1-0800200c9a66',
		curtime,
		'654dbba0-eda7-11e1-aff1-0800200c9a66',
		cfsec213.sp_next_clusteridgen(),
		'system',
		'system',
		1 );

	select id
	into clusid
	from cfsec213.clus
	where fulldomainname = 'system';

	insert into cfsec213.tenant (
		createdat,
		createdby,
		updatedat,
		updatedby,
		clusterid,
		id,
		tenantname,
		revision )
	select
		curtime,
		'654dbba0-eda7-11e1-aff1-0800200c9a66',
		curtime,
		'654dbba0-eda7-11e1-aff1-0800200c9a66',
		clus.id,
		cfsec213.sp_next_tenantidgen(),
		'system',
		1
	from cfsec213.clus as clus
	where
		clus.fulldomainname = 'system';

	-- Log history for core data

	insert into cfsec213.SecSess(
		secsessionid,
		secuserid,
		start_ts,
		finish_ts,
		revision )
	values (
		'cb56d150-ea1a-11e2-91e2-0800200c9a66',
		'654dbba0-eda7-11e1-aff1-0800200c9a66',
		curtime,
		curtime,
		1 );

	insert into cfsec213.SecUser_h (
		secuserid,
		auditclusterid,
		auditsessionid,
		auditaction,
		auditstamp,
		login_id,
		email_addr,
		pwd_hash,
		revision )
	select
		susr.secuserid,
		clusid,
		'cb56d150-ea1a-11e2-91e2-0800200c9a66',
		0,
		curtime,
		susr.login_id,
		susr.email_addr,
		susr.pwd_hash,
		susr.revision
	from
		cfsec213.SecUser as susr
		where login_id = 'system';

	insert into cfsec213.clus_h (
		id,
		auditclusterid,
		auditsessionid,
		auditaction,
		auditstamp,
		fulldomainname,
		description,
		revision )
	select
		clus.id,
		clusid,
		'cb56d150-ea1a-11e2-91e2-0800200c9a66',
		0,
		curtime,
		clus.fulldomainname,
		clus.description,
		clus.revision
	from cfsec213.clus as clus
	where
		clus.fulldomainname = 'system';

	insert into cfsec213.tenant_h (
		clusterid,
		id,
		auditclusterid,
		auditsessionid,
		auditaction,
		auditstamp,
		tenantname,
		revision )
	select
		tent.clusterid,
		tent.id,
		clusid,
		'cb56d150-ea1a-11e2-91e2-0800200c9a66',
		0,
		curtime,
		tent.tenantname,
		tent.revision
	from cfsec213.tenant as tent
	where
		tent.clusterid = clusid
		and tent.tenantname = 'system';

	return true;
end;
$$ language plpgsql;

select cfsec213.sp_bootstrap();

drop function cfsec213.sp_bootstrap();
