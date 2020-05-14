@ECHO off
REM
REM	@(#) dbcreate/cfsec/pgsql/crdb_cfsec213.bat
REM
REM	com.github.msobkow.CFSec
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
SET pghost=""
SET pgpwd=""
SET pgsrv=""
SET pguser=""
SET logfilename=$GenFileBaseName$.log
SET pgdatadir=""
IF NOT "%1" == "" SET pghost=%1
IF NOT "%2" == "" SET pguser=%2
IF NOT "%3" == "" SET pgpwd=%3
IF NOT "%4" == "" SET pgdatadir=%4
SET TK_DUALCASE_IN_CASE_STATEMENTS=true


REM
REM	Validate parameters
REM

IF "%pguser%" == "" (
	ECHO "ERROR: User must be specified as argument 2"
	PAUSE
	EXIT
)

IF "%pgpwd%" == "" (
	ECHO "ERROR: Password must be specified as argument 3"
	PAUSE
	EXIT
)

IF "%pghost%" == "" (
	ECHO "ERROR: Server host name must be specified as argument 1"
	PAUSE
	EXIT
)

SET PGPASSWORD=%pgpwd%

IF "%pgdatadir%" == "" (
	ECHO "WARNING: Database data directory was not specified as argument 4, tablespaces will not be created"
)

ECHO REM >%logfilename%


REM
REM	Create the tablespaces
REM

IF NOT "%pgdatadir%" == "" (

	ECHO Creating tablespace directories >> %logfilename%

	mkdir %pgdatadir%
	mkdir %pgdatadir%\cfsec213_data1
	mkdir %pgdatadir%\cfsec213_idx1

	ECHO >> %logfilename%
	ECHO Creating tablespaces cfsec213_data1, cfsec213_idx1
	ECHO Creating tablespaces cfsec213_data1, cfsec213_idx1 >> %logfilename%
	psql -h %pghost% -d template1 -U %pguser% -a -e -c "create tablespace cfsec213_data1 location '%pgdatadir%/cfsec213_data1'" >>%logfilename% 2>&1

	psql -h %pghost% -d template1 -U %pguser% -a -e -c "create tablespace cfsec213_idx1 location '%pgdatadir%/cfsec213_idx1'" >>%logfilename% 2>&1

)


REM 
REM Create the database instance
REM 
ECHO Recreating database cfsec213 ...
ECHO Recreating database cfsec213 ... >> %logfilename%

ECHO  >>%logfilename%
ECHO REM >>%logfilename%
ECHO REM Drop database cfsec213 >>%logfilename%
ECHO REM >>%logfilename%

psql -h %pghost% -d template1 -U %pguser% -a -e -c "drop database cfsec213" >>%logfilename% 2>&1

ECHO  >>%logfilename%
ECHO REM >>%logfilename%
ECHO REM Create database cfsec213 >>%logfilename%
ECHO REM >>%logfilename%

psql -h %pghost% -d template1 -U %pguser% -a -e -c "create database cfsec213 tablespace cfsec213_data1" >>%logfilename% 2>&1

CALL crschema_cfsec213.bat %pghost% cfsec213 %pguser% %pgpwd% %logfilename%
