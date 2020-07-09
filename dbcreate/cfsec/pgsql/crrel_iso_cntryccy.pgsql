--
--	@(#) dbcreate/cfsec/pgsql/crrel_iso_cntryccy.pgsql
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

ALTER TABLE cfsec213.iso_cntryccy ADD CONSTRAINT isocntryccy_cntry
	FOREIGN KEY (
		isoctryid
	) REFERENCES cfsec213.iso_cntry (
		isoctryid
	) ON DELETE RESTRICT;

ALTER TABLE cfsec213.iso_cntryccy ADD CONSTRAINT isocntryccy_ccy
	FOREIGN KEY (
		isoccyid
	) REFERENCES cfsec213.iso_ccy (
		isoccyid
	) ON DELETE RESTRICT;

ALTER TABLE cfsec213.iso_cntryccy ADD CONSTRAINT chk_iso_cntryccy_createdby
	FOREIGN KEY ( createdby )
	REFERENCES cfsec213.SecUser ( secuserid )
	ON DELETE RESTRICT;


ALTER TABLE cfsec213.iso_cntryccy ADD CONSTRAINT chk_iso_cntryccy_updatedby
	FOREIGN KEY ( updatedby )
	REFERENCES cfsec213.SecUser ( secuserid )
	ON DELETE RESTRICT;

