--
--	@(#) dbcreate/cfsec/oracle/crsp_bootstrap.plsql
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
