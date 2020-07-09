@ECHO OFF
REM	@(#) dbcreate/cfsec/mssql/crdb_cfsec213.bat
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

REM	Initialize locals
SET mssqlpwd=""
SET mssqlsrv=""
SET mssqluser=""
SET logfilename=$GenFileBaseName$.log

IF NOT "%1" == "" SET mssqlsrv=%1
IF NOT "%2" == "" SET mssqluser=%2
IF NOT "%3" == "" SET mssqlpwd=%3
IF NOT "%4" == "" SET logfilename=%4

IF "%mssqluser%" == "" (
	ECHO "ERROR: User must be specified as second argument"
	PAUSE
	EXIT
)

IF "%mssqlpwd%" == "" (
	ECHO "ERROR: Password must be specified as third argument"
	PAUSE
	EXIT
)

IF "%mssqlsrv%" == "" (
	ECHO "ERROR: Server must be specified as first argument"
	PAUSE
	EXIT
)

SET cmddb=sqlcmd -S %mssqlsrv% -U %mssqluser% -P %mssqlpwd% -e

if exist %logfilename% (
	DEL %logfilename%
)


REM
REM	Drop the database, if it exists
REM
if exist drdb_cfsec213.tsql (
	echo 	Dropping any existing database 'cfsec213' ...
	echo REM >>%logfilename%
	echo REM	Executing SQL script drdb_cfsec213.tsql >>%logfilename%
	echo REM >>%logfilename%
	%cmddb% <drdb_cfsec213.tsql >>%logfilename%
)

REM
REM	Create the database owner
REM
if exist crdb_owner.tsql (
	echo 	Creating database owner 'cfsec213' ...
	echo REM >>%logfilename%
	echo REM	Executing SQL script crdb_owner.tsql >>%logfilename%
	echo REM >>%logfilename%
	%cmddb% <crdb_owner.tsql >>%logfilename%
)

REM
REM	Create the database logins
REM
if exist crdb_logins.tsql (
	echo 	Creating database logins ...
	echo REM >>%logfilename%
	echo REM	Executing SQL script crdb_logins.tsql >>%logfilename%
	echo REM >>%logfilename%
	%cmddb% <crdb_logins.tsql >>%logfilename%
)

REM
REM	Create the database groups
REM
if exist crdb_groups.tsql (
	echo 	Creating database groups ...
	echo REM >>%logfilename%
	echo REM	Executing SQL script crdb_groups.tsql >>%logfilename%
	echo REM >>%logfilename%
	%cmddb% <crdb_groups.tsql >>%logfilename%
)

REM
REM	Create the database roles
REM
if exist crdb_roles.tsql (
	echo 	Creating database roles ...
	echo REM >>%logfilename%
	echo REM	Executing SQL script crdb_roles.tsql >>%logfilename%
	echo REM >>%logfilename%
	%cmddb% <crdb_roles.tsql >>%logfilename%
)

REM
REM	Create the database users
REM
if exist crdb_users.tsql (
	echo 	Creating database users ...
	echo REM >>%logfilename%
	echo REM	Executing SQL script crdb_users.tsql >>%logfilename%
	echo REM >>%logfilename%
	%cmddb% <crdb_users.tsql >>%logfilename%
)

REM
REM	Create the database defaults
REM
if exist crdb_defaults.tsql (
	echo 	Creating database defaults ...
	echo REM >>%logfilename%
	echo REM	Executing SQL script crdb_defaults.tsql >>%logfilename%
	echo REM >>%logfilename%
	%cmddb% <crdb_defaults.tsql >>%logfilename%
)

REM
REM	Create the database
REM
if exist crdb_cfsec213.tsql (
	echo 	Creating database cfsec213 ...
	echo REM >>%logfilename%
	echo REM	Executing SQL script crdb_cfsec213.tsql >>%logfilename%
	echo REM >>%logfilename%
	%cmddb% <crdb_cfsec213.tsql >>%logfilename%
)

REM
REM	Create the database rules
REM
if exist crdb_rules.tsql (
	echo 	Creating database rules ...
	echo REM >>%logfilename%
	echo REM	Executing SQL script crdb_rules.tsql >>%logfilename%
	echo REM >>%logfilename%
	%cmddb% <crdb_rules.tsql >>%logfilename%
)

REM
REM	Create the database types
REM
if exist crdb_types.tsql (
	echo 	Creating database types ...
	echo REM >>%logfilename%
	echo REM	Executing SQL script crdb_types.tsql >>%logfilename%
	echo REM >>%logfilename%
	%cmddb% <crdb_types.tsql >>%logfilename%
)

REM
REM	Create the database tables
REM
if exist crtbl_cfsec213.bat (
	echo 	Creating database tables ...
	echo REM >>%logfilename%
	echo REM	Executing script crtbl_cfsec213.bat >>%logfilename%
	echo REM >>%logfilename%
	CALL crtbl_cfsec213.bat %mssqlsrv% %mssqluser% %mssqlpwd% %logfilename%
)

REM
REM	Create the database indexes
REM
if exist cridx_cfsec213.bat (
	echo 	Creating database indexes ...
	echo REM >>%logfilename%
	echo REM	Executing script cridx_cfsec213.bat >>%logfilename%
	echo REM >>%logfilename%
	CALL cridx_cfsec213.bat %mssqlsrv% %mssqluser% %mssqlpwd% %logfilename%
)

REM
REM	Create the database relations
REM
if exist crrel_cfsec213.bat (
	echo 	Creating database relations ...
	echo REM >>%logfilename%
	echo REM	Executing script crrel_cfsec213.bat >>%logfilename%
	echo REM >>%logfilename%
	CALL crrel_cfsec213.bat %mssqlsrv% %mssqluser% %mssqlpwd% %logfilename%
)

REM
REM	Create the database stored procedures
REM
if exist crprocs_cfsec213.bat (
	echo 	Creating database stored procedures ...
	echo REM >>%logfilename%
	echo REM	Executing script crprocs_cfsec213.bat >>%logfilename%
	echo REM >>%logfilename%
	CALL crprocs_cfsec213.bat %mssqlsrv% %mssqluser% %mssqlpwd% %logfilename%
)

REM
REM	Load initial data
REM
if exist load_cfsec213.bat (
	echo 	Loading initial data ...
	echo REM >>%logfilename%
	echo REM	Executing script load_cfsec213.bat >>%logfilename%
	echo REM >>%logfilename%
	CALL load_cfsec213.bat %mssqlsrv% %mssqluser% %mssqlpwd% %logfilename%
)

REM
REM	Create the database triggers
REM
if exist crtrg_cfsec213.bat (
	echo 	Creating database triggers ...
	echo REM >>%logfilename%
	echo REM	Executing script crtrg_cfsec213.bat >>%logfilename%
	echo REM >>%logfilename%
	CALL crtrg_cfsec213.bat %mssqlsrv% %mssqluser% %mssqlpwd% %logfilename%
)

PAUSE
