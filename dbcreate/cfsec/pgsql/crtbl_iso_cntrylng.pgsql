--
--	@(#) dbcreate/cfsec/pgsql/crtbl_iso_cntrylng.pgsql
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
CREATE TABLE cfsec213.iso_cntrylng (
	createdat	TIMESTAMP NOT NULL,
	createdby	VARCHAR(36) NOT NULL,
	updatedat	TIMESTAMP NOT NULL,
	updatedby	VARCHAR(36) NOT NULL,
	isoctryid	smallint NOT NULL,
	isolangid	smallint NOT NULL,
	revision	INTEGER NOT NULL)
	WITHOUT OIDS
	TABLESPACE cfsec213_data1;

CREATE UNIQUE INDEX isocountrylang_pk ON cfsec213.iso_cntrylng (
	isoctryid,
	isolangid )
	TABLESPACE cfsec213_idx1;

ALTER TABLE cfsec213.iso_cntrylng
	ADD CONSTRAINT pk_isocountrylang_pk PRIMARY KEY ( isoctryid, isolangid );
