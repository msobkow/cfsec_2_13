--
--	@(#) dbcreate/cfsec/db2luw/crtbl_secuser.sql
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
CREATE TABLE cfsec213.SecUser (	\
	createdat	TIMESTAMP NOT NULL,	\
	createdby	VARCHAR(36) NOT NULL,	\
	updatedat	TIMESTAMP NOT NULL,	\
	updatedby	VARCHAR(36) NOT NULL,	\
	SecUserId	CHAR(36) NOT NULL,	\
	login_id	VARCHAR(32) NOT NULL,	\
	email_addr	VARCHAR(192) NOT NULL,	\
	em_confuuid	CHAR(36),	\
	DefDevUserId	CHAR(36),	\
	DefDevName	VARCHAR(127),	\
	pwd_hash	VARCHAR(256) NOT NULL,	\
	pwdrstuuid	CHAR(36),	\
	Revision	int NOT NULL)	\
IN msidata1

CREATE UNIQUE INDEX CFSec213.SecUser_pidx ON CFSec213.SecUser (	\
	SecUserId )

ALTER TABLE CFSec213.SecUser	\
	ADD CONSTRAINT pk_secuser_pidx PRIMARY KEY ( SecUserId )

commit