@ECHO off
REM
REM	@(#) dbcreate/cfsec/pgsqlcrschema_cfsec213.bat
REM
REM	org.msscf.msscf.CFSec
REM
REM	Copyright (c) 2020 Mark Stephen Sobkow
REM	
REM	This file is part of MSS Code Factory.
REM	
REM	Licensed under the Apache License, Version 2.0 (the "License");
REM	you may not use this file except in compliance with the License.
REM	You may obtain a copy of the License at
REM	
REM	    http://www.apache.org/licenses/LICENSE-2.0
REM	
REM	Unless required by applicable law or agreed to in writing, software
REM	distributed under the License is distributed on an "AS IS" BASIS,
REM	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
REM	See the License for the specific language governing permissions and
REM	limitations under the License.
REM	
REM	Donations to support MSS Code Factory can be made at
REM	https://www.paypal.com/paypalme2/MarkSobkow
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

