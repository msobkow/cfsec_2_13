--
--	@(#) dbcreate/cfsec/db2luw/crtbl_hostnode.sql
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
CREATE TABLE cfsec213.HostNode (	\
	createdat	TIMESTAMP NOT NULL,	\
	createdby	VARCHAR(36) NOT NULL,	\
	updatedat	TIMESTAMP NOT NULL,	\
	updatedby	VARCHAR(36) NOT NULL,	\
	ClusterId	BIGINT NOT NULL,	\
	HostNodeId	BIGINT NOT NULL,	\
	Description	VARCHAR(255) NOT NULL,	\
	HostName	VARCHAR(192) NOT NULL,	\
	Revision	int NOT NULL)	\
IN msidata1

CREATE UNIQUE INDEX CFSec213.HostNode_pidx ON CFSec213.HostNode (	\
	ClusterId,	\
	HostNodeId )

ALTER TABLE CFSec213.HostNode	\
	ADD CONSTRAINT pk_hostnode_pidx PRIMARY KEY ( ClusterId, HostNodeId )

commit
