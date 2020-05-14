--
--	@(#) dbcreate/cfsec/pgsql/crtbl_secuser_h.pgsql
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
CREATE TABLE cfsec213.SecUser_h (
	secuserid	varchar(36) NOT NULL,
	revision	INTEGER NOT NULL,
	auditclusterid	BIGINT NOT NULL,
		CONSTRAINT chk_secuser_h_auditcluster
			FOREIGN KEY ( auditclusterid )
			REFERENCES cfsec213.clus( id )
			ON DELETE CASCADE,
	auditsessionid	VARCHAR(36) NOT NULL,
		CONSTRAINT chk_secuser_h_auditsession
			FOREIGN KEY ( auditsessionid )
			REFERENCES cfsec213.SecSess( secsessionid )
			ON DELETE CASCADE,
	login_id	varchar(32) NOT NULL,
	email_addr	varchar(192) NOT NULL,
	em_confuuid	varchar(36) NULL,
	defdevuserid	varchar(36) NULL,
	defdevname	varchar(127) NULL,
	pwd_hash	varchar(256) NOT NULL,
	pwdrstuuid	varchar(36) NULL,
	auditaction	SMALLINT NOT NULL,
	auditstamp	TIMESTAMP NOT NULL )
	WITHOUT OIDS
	TABLESPACE cfsec213_data1;

CREATE UNIQUE INDEX secuser_h_ididx ON cfsec213.secuser_h (
	auditclusterid,
	auditstamp,
	secuserid,
	auditaction,
	revision )
	TABLESPACE cfsec213_idx1;

ALTER TABLE cfsec213.secuser_h
	ADD CONSTRAINT pk_secuser_h_ididx PRIMARY KEY ( auditclusterid, auditstamp, secuserid, auditaction, revision );
