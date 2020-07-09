@ECHO off
REM
REM	@(#) dbcreate/cfsec/pgsql/crtypes_cfsec213.bat
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

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_cfsec213_cc_rec.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_clus_rec.pgsql >>%logfilename% 2>&1

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_hostnode_rec.pgsql >>%logfilename% 2>&1

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_iso_ccy_rec.pgsql >>%logfilename% 2>&1

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_iso_cntry_rec.pgsql >>%logfilename% 2>&1

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_iso_cntryccy_rec.pgsql >>%logfilename% 2>&1

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_iso_cntrylng_rec.pgsql >>%logfilename% 2>&1

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_iso_lang_rec.pgsql >>%logfilename% 2>&1

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_isotz_rec.pgsql >>%logfilename% 2>&1

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_secapp_rec.pgsql >>%logfilename% 2>&1

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_secdev_rec.pgsql >>%logfilename% 2>&1

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_secform_rec.pgsql >>%logfilename% 2>&1

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_secgrp_rec.pgsql >>%logfilename% 2>&1

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_secgrpfrm_rec.pgsql >>%logfilename% 2>&1

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_secinc_rec.pgsql >>%logfilename% 2>&1

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_secmemb_rec.pgsql >>%logfilename% 2>&1

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_secsess_rec.pgsql >>%logfilename% 2>&1

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_secuser_rec.pgsql >>%logfilename% 2>&1

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_hostsvc_rec.pgsql >>%logfilename% 2>&1

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_svctype_rec.pgsql >>%logfilename% 2>&1

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_sysclus_rec.pgsql >>%logfilename% 2>&1

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_tsecgrp_rec.pgsql >>%logfilename% 2>&1

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_tsecinc_rec.pgsql >>%logfilename% 2>&1

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_tsecmemb_rec.pgsql >>%logfilename% 2>&1

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crtype_tenant_rec.pgsql >>%logfilename% 2>&1


