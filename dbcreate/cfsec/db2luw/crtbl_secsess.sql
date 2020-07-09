--
--	@(#) dbcreate/cfsec/db2luw/crtbl_secsess.sql
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
CREATE TABLE cfsec213.SecSess (	\
	SecSessionId	CHAR(36) NOT NULL,	\
	SecUserId	CHAR(36) NOT NULL,	\
	SecDevName	VARCHAR(127),	\
	start_ts	TIMESTAMP NOT NULL,	\
	finish_ts	TIMESTAMP,	\
	SecProxyId	CHAR(36),	\
	Revision	int NOT NULL)	\
IN msidata1

CREATE UNIQUE INDEX CFSec213.Session_pidx ON CFSec213.SecSess (	\
	SecSessionId )

ALTER TABLE CFSec213.SecSess	\
	ADD CONSTRAINT pk_session_pidx PRIMARY KEY ( SecSessionId )

commit
