--
--	@(#) dbcreate/cfsec/db2luw/crtbl_secdev_h.sql
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
CREATE TABLE cfsec213.secdev_h (	\
	secuserid	CHAR(36) NOT NULL,	\
	devname	VARCHAR(127) NOT NULL,	\
	Revision	int NOT NULL,	\
	auditclusterid	BIGINT NOT NULL,	\
		CONSTRAINT chk_secdev_h_auditcluster	\
			FOREIGN KEY ( auditclusterid )	\
			REFERENCES cfsec213.clus( id )	\
			ON DELETE CASCADE,	\
	auditsessionid	VARCHAR(36) NOT NULL,	\
		CONSTRAINT chk_secdev_h_auditsession	\
			FOREIGN KEY ( auditsessionid )	\
			REFERENCES cfsec213.SecSess( secsessionid )	\
			ON DELETE CASCADE,	\
	PubKey	CLOB(10000),	\
	auditaction	SMALLINT NOT NULL,	\
	auditstamp	TIMESTAMP NOT NULL )	\
IN msidata1

CREATE UNIQUE INDEX cfsec213.secdev_h_ididx ON cfsec213.secdev_h (	\
	auditclusterid,	\
	auditstamp,	\
	SecUserId,	\
	DevName,	\
	auditaction,	\
	revision )

ALTER TABLE cfsec213.secdev_h	\
	ADD CONSTRAINT pk_secdev_pidx_h PRIMARY KEY (	\
	auditclusterid,	\
	auditstamp, SecUserId, DevName,	\
	auditaction,	\
	revision )
