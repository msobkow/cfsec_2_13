--
--	@(#) dbcreate/cfsec/db2luw/crtbl_tenant_idg64.sql
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
CREATE TABLE cfsec213.tenant_idg64 (	\
	id	BIGINT NOT NULL,	\
	slice_id	SMALLINT NOT NULL,	\
	next_id	BIGINT NOT NULL )	\
IN msidata1

ALTER TABLE cfsec213.tenant_idg64	\
	ADD CONSTRAINT pk_tenant_idg64 PRIMARY KEY ( Id, slice_id )
