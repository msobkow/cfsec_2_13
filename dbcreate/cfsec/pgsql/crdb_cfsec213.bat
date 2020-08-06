@ECHO off
REM
REM	@(#) dbcreate/cfsec/pgsql/crdb_cfsec213.bat
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
