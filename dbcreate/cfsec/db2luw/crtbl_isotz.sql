--
--	@(#) dbcreate/cfsec/db2luw/crtbl_isotz.sql
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
CREATE TABLE cfsec213.ISOTz (	\
	createdat	TIMESTAMP NOT NULL,	\
	createdby	VARCHAR(36) NOT NULL,	\
	updatedat	TIMESTAMP NOT NULL,	\
	updatedby	VARCHAR(36) NOT NULL,	\
	ISOTZoneId	SMALLINT NOT NULL,	\
	Iso8601	VARCHAR(6) NOT NULL,	\
	TZName	VARCHAR(64) NOT NULL,	\
	TZHourOffset	SMALLINT NOT NULL,	\
	TZMinOffset	SMALLINT NOT NULL,	\
	Description	VARCHAR(128) NOT NULL,	\
	Visible	CHAR(1) NOT NULL,	\
	Revision	int NOT NULL)	\
IN msidata1

CREATE UNIQUE INDEX CFSec213.ITz_pidx ON CFSec213.ISOTz (	\
	ISOTZoneId )

ALTER TABLE CFSec213.ISOTz	\
	ADD CONSTRAINT pk_itz_pidx PRIMARY KEY ( ISOTZoneId )

commit
