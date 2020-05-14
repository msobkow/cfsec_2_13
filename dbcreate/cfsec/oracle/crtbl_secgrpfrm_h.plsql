--
--	@(#) dbcreate/cfsec/oracle/crtbl_secgrpfrm_h.plsql
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
CREATE TABLE cfsec213.SecGrpFrm_h (
	clusid	numeric(22,0) NOT NULL,
	secgrpfrmid	numeric(22,0) NOT NULL,
	revision	INTEGER NOT NULL,
	auditclusterid	NUMERIC(22,0) NOT NULL,
		CONSTRAINT chkh_secgrpfrmauditcluster
			FOREIGN KEY ( auditclusterid )
			REFERENCES cfsec213.clus( id )
			ON DELETE CASCADE,
	auditsessionid	VARCHAR(36) NOT NULL,
		CONSTRAINT chkh_secgrpfrmauditsession
			FOREIGN KEY ( auditsessionid )
			REFERENCES cfsec213.SecSess( secsessionid )
			ON DELETE CASCADE,
	secgrpid	integer NOT NULL,
	secappid	integer NOT NULL,
	secfrmid	integer NOT NULL,
	auditaction	SMALLINT NOT NULL,
	auditstamp	TIMESTAMP NOT NULL )
	TABLESPACE cfsec213_data1;

CREATE UNIQUE INDEX secgrpfrm_hididx ON cfsec213.secgrpfrm_h (
	auditclusterid,
	auditstamp,
	clusid,
	secgrpfrmid,
	auditaction,
	revision )
	TABLESPACE cfsec213_idx1;

ALTER TABLE cfsec213.secgrpfrm_h
	ADD CONSTRAINT pk_secgrpfrm_hididx PRIMARY KEY ( auditclusterid, auditstamp, clusid, secgrpfrmid, auditaction, revision );