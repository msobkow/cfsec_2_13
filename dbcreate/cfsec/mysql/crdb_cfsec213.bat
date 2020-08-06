@echo off
REM
REM	@(#) dbcreate/cfsec/mysql/crdb_cfsec213.bat
$ScriptLicenseBat$
REM
REM	Initialize locals
REM

SET mysqlpwd=""
SET mysqluser=""
SET logfilename=$GenFileBaseName$.log
SET TK_DUALCASE_IN_CASE_STATEMENTS=true

IF NOT "%1" == "" SET mysqluser=%1
IF NOT "%2" == "" SET mysqlpwd=%2
IF NOT "%3" == "" SET logfilename=%3

REM
REM	Validate parameters
REM

IF "%mysqluser%" == "" (
	ECHO ERROR: MySQL DBA login not specified as argument 1
	PAUSE
	EXIT
)

IF "%mysqlpwd%" == "" (
	ECHO ERROR: Password must be specified as argument 2 >&2
	PAUSE
	EXIT
)

REM
REM	Create the schema
REM

call crschema_cfsec213.bat %mysqluser% %mysqlpwd% %logfilename%