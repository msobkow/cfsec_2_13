--
--	@(#) dbcreate/cfsec/pgsql/crtbl_secuser.pgsql
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
CREATE TABLE cfsec213.SecUser (
	createdat	TIMESTAMP NOT NULL,
	createdby	VARCHAR(36) NOT NULL,
	updatedat	TIMESTAMP NOT NULL,
	updatedby	VARCHAR(36) NOT NULL,
	secuserid	varchar(36) NOT NULL,
	login_id	varchar(32) NOT NULL,
	email_addr	varchar(192) NOT NULL,
	em_confuuid	varchar(36) NULL,
	defdevuserid	varchar(36) NULL,
	defdevname	varchar(127) NULL,
	pwd_hash	varchar(256) NOT NULL,
	pwdrstuuid	varchar(36) NULL,
	revision	INTEGER NOT NULL)
	WITHOUT OIDS
	TABLESPACE cfsec213_data1;

CREATE UNIQUE INDEX SecUser_pidx ON cfsec213.SecUser (
	secuserid )
	TABLESPACE cfsec213_idx1;

ALTER TABLE cfsec213.SecUser
	ADD CONSTRAINT pk_secuser_pidx PRIMARY KEY ( secuserid );
