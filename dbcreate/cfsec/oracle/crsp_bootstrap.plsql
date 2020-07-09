--
--	@(#) dbcreate/cfsec/oracle/crsp_bootstrap.plsql
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
alter session set plsql_warnings = 'ENABLE:ALL';
/

create or replace procedure cfsec213.sp_bootstrap authid definer
is
	curtime timestamp;
	clusid numeric(22,0);
	tenantid numeric(22,0);
begin
	curtime := sysdate;




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

	select cfsec213.nxt_clusteridgen()
	into clusid
	from dual;

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
		clusid,
		'system',
		'system',
		1 );

	select id
	into clusid
	from cfsec213.clus
	where fulldomainname = 'system';

	select cfsec213.nxt_tenantidgen()
	into tenantid
	from dual;

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
		clusid,
		tenantid,
		'system',
		1
	from dual;

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

	insert into cfsec213.SecUser_h
	select
		secuserid,
		revision,
		clusid,
		'cb56d150-ea1a-11e2-91e2-0800200c9a66',
		login_id,
		email_addr,
		null,
		null,
		null,
		pwd_hash,
		null,
		0,
		curtime
	from
		cfsec213.SecUser
		where login_id = 'system';

	insert into cfsec213.clus_h
	select
		id,
		revision,
		clusid,
		'cb56d150-ea1a-11e2-91e2-0800200c9a66',
		fulldomainname,
		description,
		0,
		curtime
	from cfsec213.clus
	where fulldomainname = 'system';

	insert into cfsec213.tenant_h
	select
		id,
		revision,
		clusid,
		'cb56d150-ea1a-11e2-91e2-0800200c9a66',
		clusterid,
		tenantname,
		0,
		curtime
	from cfsec213.tenant
	where
		clusterid = clusid
		and tenantname = 'system';
end sp_bootstrap;
/

show errors procedure cfsec213.sp_bootstrap;

call cfsec213.sp_bootstrap();

--drop function cfsec213.sp_bootstrap;
--/
