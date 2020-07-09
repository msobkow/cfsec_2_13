--
--	@(#) dbcreate/cfsec/oracle/crtbl_secsess.plsql
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
CREATE TABLE cfsec213.SecSess (
	secsessionid	varchar(36) NOT NULL,
	secuserid	varchar(36) NOT NULL,
	secdevname	varchar2(127) NULL,
	start_ts	timestamp NOT NULL,
	finish_ts	timestamp NULL,
	secproxyid	varchar(36) NULL,
	revision	INTEGER NOT NULL)
TABLESPACE cfsec213_data1;

CREATE UNIQUE INDEX Session_pidx ON cfsec213.SecSess (
	secsessionid ) TABLESPACE cfsec213_idx1;

ALTER TABLE cfsec213.SecSess
	ADD CONSTRAINT pk_session_pidx PRIMARY KEY ( secsessionid );

