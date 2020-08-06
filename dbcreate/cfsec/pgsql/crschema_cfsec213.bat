@ECHO off
REM
REM	@(#) dbcreate/cfsec/pgsqlcrschema_cfsec213.bat
REM
REM	org.msscf.msscf.CFSec
REM
REM	Copyright (c) 2020 Mark Stephen Sobkow
REM	
REM	MSS Code Factory CFSec 2.13 Security Essentials
REM	
REM	Copyright 2020 Mark Stephen Sobkow
REM	
REM		This file is part of MSS Code Factory.
REM	
REM		MSS Code Factory is available under dual commercial license from Mark Stephen
REM		Sobkow, or under the terms of the GNU General Public License, Version 3
REM		or later.
REM	
REM	    MSS Code Factory is free software: you can redistribute it and/or modify
REM	    it under the terms of the GNU General Public License as published by
REM	    the Free Software Foundation, either version 3 of the License, or
REM	    (at your option) any later version.
REM	
REM	    MSS Code Factory is distributed in the hope that it will be useful,
REM	    but WITHOUT ANY WARRANTY; without even the implied warranty of
REM	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
REM	    GNU General Public License for more details.
REM	
REM	    You should have received a copy of the GNU General Public License
REM	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
REM	
REM	Donations to support MSS Code Factory can be made at
REM	https://www.paypal.com/paypalme2/MarkSobkow
REM	
REM	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
REM
REM Manufactured by MSS Code Factory 2.12
REM

REM
REM	Initialize locals
REM
SET pgdb=""
SET pghost=""
SET pgpwd=""
SET pgsrv=""
SET pguser=""
SET logfilename=$GenFileBaseName$.log
IF NOT "%1" == "" SET pghost=%1
IF NOT "%2" == "" SET pgdb=%2
IF NOT "%3" == "" SET pguser=%3
IF NOT "%4" == "" SET pgpwd=%4
IF NOT "%5" == "" SET logfilename=%5
SET TK_DUALCASE_IN_CASE_STATEMENTS=true

REM
REM	Validate parameters
REM

IF "%pguser%" == "" (
	ECHO "ERROR: User must be specified as argument 3'"
	PAUSE
	EXIT
)

IF "%pgpwd%" == "" (
	ECHO "ERROR: Password must be specified as argument 4'"
	PAUSE
	EXIT
)

IF "%pghost%" == "" (
	ECHO "ERROR: Server host name must be specified as argument 1'"
	PAUSE
	EXIT
)

IF "%pgdb%" == "" (
	ECHO "ERROR: Database name must be specified as argument 2'"
	PAUSE
	EXIT
)

SET PGPASSWORD=%pgpwd%

ECHO Dropping old schema cfsec213 for %pguser%
ECHO Dropping old schema cfsec213 for %pguser% >>%logfilename%

psql -h %pghost% -U %pguser% -a -e -c "drop schema cfsec213" >>%logfilename% 2>&1

ECHO Creating schema CFSec213 in database %pgdb% for %pguser%
ECHO Creating schema CFSec213 in database %pgdb% for %pguser% >>%logfilename%

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -c "create schema cfsec213" >>%logfilename% 2>&1


REM
REM	Create the database tables
REM
ECHO 	Creating database tables ...
ECHO  >>%logfilename%
ECHO REM >>%logfilename%
ECHO REM	Executing script crtbl_cfsec213.bat >>%logfilename%
ECHO REM >>%logfilename%
CALL crtbl_cfsec213.bat %pghost% %pgdb% %pguser% %pgpwd% %logfilename%

REM
REM	Create the database indexes
REM
ECHO 	Creating database indexes ...
ECHO REM >>%logfilename%
ECHO REM	Executing script cridx_cfsec213.bat >>%logfilename%
ECHO REM >>%logfilename%
CALL cridx_cfsec213.bat %pghost% %pgdb% %pguser% %pgpwd% %logfilename%

REM
REM	Create the database relations
REM
ECHO 	Creating database relations ...
ECHO  >>%logfilename%
ECHO REM >>%logfilename%
ECHO REM	Executing script crrel_cfsec213.bat >>%logfilename%
ECHO REM >>%logfilename%
CALL crrel_cfsec213.bat %pghost% %pgdb% %pguser% %pgpwd% %logfilename%

REM
REM	Create the database sequences
REM
ECHO 	Creating database sequences...
ECHO  >>%logfilename%
ECHO REM >>%logfilename%
ECHO REM	Executing script crseq_cfsec213.bat >>%logfilename%
ECHO REM >>%logfilename%
CALL crseq_cfsec213.bat %pghost% %pgdb% %pguser% %pgpwd% %logfilename%

REM
REM	Create the return record types for the stored procedures
REM
ECHO 	Creating database types...
ECHO  >>%logfilename%
ECHO REM >>%logfilename%
ECHO REM	Executing script crtypes_cfsec213.bat >>%logfilename%
ECHO REM >>%logfilename%
CALL crtypes_cfsec213.bat %pghost% %pgdb% %pguser% %pgpwd% %logfilename%

REM
REM	Create the stored procedures
REM
ECHO 	Creating stored procedures...
ECHO  >>%logfilename%
ECHO REM >>%logfilename%
ECHO REM	Executing script crprocs_cfsec213.bat >>%logfilename%
ECHO REM >>%logfilename%
CALL crprocs_cfsec213.bat %pghost% %pgdb% %pguser% %pgpwd% %logfilename%

