--
--	@(#) dbcreate/cfsec/oracle/crtbl_isotz.plsql
--
--	org.msscf.msscf.CFSec
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	MSS Code Factory CFSec 2.13 Security Essentials
--	
--	Copyright 2020 Mark Stephen Sobkow
--	
--		This file is part of MSS Code Factory.
--	
--		MSS Code Factory is available under dual commercial license from Mark Stephen
--		Sobkow, or under the terms of the GNU General Public License, Version 3
--		or later.
--	
--	    MSS Code Factory is free software: you can redistribute it and/or modify
--	    it under the terms of the GNU General Public License as published by
--	    the Free Software Foundation, either version 3 of the License, or
--	    (at your option) any later version.
--	
--	    MSS Code Factory is distributed in the hope that it will be useful,
--	    but WITHOUT ANY WARRANTY; without even the implied warranty of
--	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--	    GNU General Public License for more details.
--	
--	    You should have received a copy of the GNU General Public License
--	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
--	
--	Donations to support MSS Code Factory can be made at
--	https://www.paypal.com/paypalme2/MarkSobkow
--	
--	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
--
--	Manufactured by MSS Code Factory 2.12
--
CREATE TABLE cfsec213.ISOTz (
	createdat	TIMESTAMP NOT NULL,
	createdby	VARCHAR(36) NOT NULL,
	updatedat	TIMESTAMP NOT NULL,
	updatedby	VARCHAR(36) NOT NULL,
	isotzoneid	smallint NOT NULL,
	iso8601	varchar2(6) NOT NULL,
	tzname	varchar2(64) NOT NULL,
	tzhouroffset	smallint NOT NULL,
	tzminoffset	smallint NOT NULL,
	description	varchar2(128) NOT NULL,
	visible	char(1) NOT NULL,
	revision	INTEGER NOT NULL)
TABLESPACE cfsec213_data1;

CREATE UNIQUE INDEX ITz_pidx ON cfsec213.ISOTz (
	isotzoneid ) TABLESPACE cfsec213_idx1;

ALTER TABLE cfsec213.ISOTz
	ADD CONSTRAINT pk_itz_pidx PRIMARY KEY ( isotzoneid );

