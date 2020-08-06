@ECHO off
REM
REM	@(#) dbcreate/cfsec/pgsql/crrel_cfsec213.bat
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

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_clus.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_clus_idg32.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_clus_idg64.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_hostnode.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_iso_ccy.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_iso_cntry.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_iso_cntryccy.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_iso_cntrylng.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_iso_lang.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_isotz.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_secapp.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_secdev.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_secform.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_secgrp.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_secgrpfrm.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_secinc.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_secmemb.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_secsess.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_secuser.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_hostsvc.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_svctype.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_sysclus.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_tsecgrp.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_tsecinc.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_tsecmemb.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_tenant.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_tenant_idg32.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f crrel_tenant_idg64.pgsql >>%logfilename% 2>&1

