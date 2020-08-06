--
--	@(#) dbcreate/cfsec/db2luw/crsp_bootstrap.sql
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
create or replace procedure sp_bootstrap()	\
modifies sql data	\
language sql	\
begin	\
	declare	curtime timestamp;	\
	declare clusid bigint;	\
	declare tenantid bigint;	\
  begin	\
	set( curtime ) = ( current timestamp );	\
	\
	\
	\
	\
	insert into cfsec213.SecUser (	\
		createdat,	\
		createdby,	\
		updatedat,	\
		updatedby,	\
		secuserid,	\
		login_id,	\
		email_addr,	\
		pwd_hash,	\
		revision )	\
	values (	\
		curtime,	\
		'654dbba0-eda7-11e1-aff1-0800200c9a66',	\
		curtime,	\
		'654dbba0-eda7-11e1-aff1-0800200c9a66',	\
		'654dbba0-eda7-11e1-aff1-0800200c9a66',	\
		'system',	\
		'root',	\
		'bootstrap',	\
		1 );	\
	\
	call sp_next_clusteridgen( clusid );	\
	insert into cfsec213.clus (	\
		createdat,	\
		createdby,	\
		updatedat,	\
		updatedby,	\
		id,	\
		fulldomainname,	\
		description,	\
		revision )	\
	values (	\
		curtime,	\
		'654dbba0-eda7-11e1-aff1-0800200c9a66',	\
		curtime,	\
		'654dbba0-eda7-11e1-aff1-0800200c9a66',	\
		clusid,	\
		'system',	\
		'system',	\
		1 );	\
	select id	\
	into clusid	\
	from cfsec213.clus	\
	where fulldomainname = 'system';	\
	\
	call sp_next_tenantidgen( tenantid );	\
	insert into cfsec213.tenant (	\
		createdat,	\
		createdby,	\
		updatedat,	\
		updatedby,	\
		clusterid,	\
		id,	\
		tenantname,	\
		revision )	\
	select	\
		curtime,	\
		'654dbba0-eda7-11e1-aff1-0800200c9a66',	\
		curtime,	\
		'654dbba0-eda7-11e1-aff1-0800200c9a66',	\
		clus.id,	\
		tenantid,	\
		'system',	\
		1	\
	from cfsec213.clus as clus	\
	where	\
		clus.fulldomainname = 'system';	\
	\
	insert into cfsec213.SecSess(	\
		secsessionid,	\
		secuserid,	\
		start_ts,	\
		finish_ts,	\
		revision )	\
	values (	\
		'cb56d150-ea1a-11e2-91e2-0800200c9a66',	\
		'654dbba0-eda7-11e1-aff1-0800200c9a66',	\
		curtime,	\
		curtime,	\
		1 );	\
	\
	insert into cfsec213.SecUser_h (	\
		secuserid,	\
		auditclusterid,	\
		auditsessionid,	\
		auditaction,	\
		auditstamp,	\
		login_id,	\
		email_addr,	\
		pwd_hash,	\
		revision )	\
	select	\
		susr.secuserid,	\
		clusid,	\
		'cb56d150-ea1a-11e2-91e2-0800200c9a66',	\
		0,	\
		curtime,	\
		susr.login_id,	\
		susr.email_addr,	\
		susr.pwd_hash,	\
		susr.revision	\
	from	\
		cfsec213.SecUser as susr	\
		where login_id = 'system';	\
	\
	insert into cfsec213.clus_h (	\
		id,	\
		auditclusterid,	\
		auditsessionid,	\
		auditaction,	\
		auditstamp,	\
		fulldomainname,	\
		description,	\
		revision )	\
	select	\
		clus.id,	\
		clusid,	\
		'cb56d150-ea1a-11e2-91e2-0800200c9a66',	\
		0,	\
		curtime,	\
		clus.fulldomainname,	\
		clus.description,	\
		clus.revision	\
	from cfsec213.clus as clus	\
	where	\
		clus.fulldomainname = 'system';	\
	\
	insert into cfsec213.tenant_h (	\
		clusterid,	\
		id,	\
		auditclusterid,	\
		auditsessionid,	\
		auditaction,	\
		auditstamp,	\
		tenantname,	\
		revision )	\
	select	\
		tent.clusterid,	\
		tent.id,	\
		clusid,	\
		'cb56d150-ea1a-11e2-91e2-0800200c9a66',	\
		0,	\
		curtime,	\
		tent.tenantname,	\
		tent.revision	\
	from cfsec213.tenant as tent	\
	where	\
		tent.clusterid = clusid	\
		and tent.tenantname = 'system';	\
  end;	\
end

call sp_bootstrap()

commit

drop procedure sp_bootstrap()
