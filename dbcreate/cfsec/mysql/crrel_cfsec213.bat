@echo off
REM
REM	@(#) dbcreate/cfsec/mysql/crrel_cfsec213.bat
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

echo crrel_clus.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_clus.mysql >>%logfilename% 2>&1
echo crrel_clus_idg32.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_clus_idg32.mysql >>%logfilename% 2>&1
echo crrel_clus_idg64.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_clus_idg64.mysql >>%logfilename% 2>&1
echo crrel_hostnode.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_hostnode.mysql >>%logfilename% 2>&1
echo crrel_iso_ccy.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_iso_ccy.mysql >>%logfilename% 2>&1
echo crrel_iso_cntry.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_iso_cntry.mysql >>%logfilename% 2>&1
echo crrel_iso_cntryccy.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_iso_cntryccy.mysql >>%logfilename% 2>&1
echo crrel_iso_cntrylng.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_iso_cntrylng.mysql >>%logfilename% 2>&1
echo crrel_iso_lang.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_iso_lang.mysql >>%logfilename% 2>&1
echo crrel_isotz.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_isotz.mysql >>%logfilename% 2>&1
echo crrel_secapp.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_secapp.mysql >>%logfilename% 2>&1
echo crrel_secdev.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_secdev.mysql >>%logfilename% 2>&1
echo crrel_secform.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_secform.mysql >>%logfilename% 2>&1
echo crrel_secgrp.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_secgrp.mysql >>%logfilename% 2>&1
echo crrel_secgrpfrm.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_secgrpfrm.mysql >>%logfilename% 2>&1
echo crrel_secinc.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_secinc.mysql >>%logfilename% 2>&1
echo crrel_secmemb.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_secmemb.mysql >>%logfilename% 2>&1
echo crrel_secsess.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_secsess.mysql >>%logfilename% 2>&1
echo crrel_secuser.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_secuser.mysql >>%logfilename% 2>&1
echo crrel_hostsvc.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_hostsvc.mysql >>%logfilename% 2>&1
echo crrel_svctype.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_svctype.mysql >>%logfilename% 2>&1
echo crrel_sysclus.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_sysclus.mysql >>%logfilename% 2>&1
echo crrel_tsecgrp.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_tsecgrp.mysql >>%logfilename% 2>&1
echo crrel_tsecinc.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_tsecinc.mysql >>%logfilename% 2>&1
echo crrel_tsecmemb.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_tsecmemb.mysql >>%logfilename% 2>&1
echo crrel_tenant.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_tenant.mysql >>%logfilename% 2>&1
echo crrel_tenant_idg32.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_tenant_idg32.mysql >>%logfilename% 2>&1
echo crrel_tenant_idg64.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crrel_tenant_idg64.mysql >>%logfilename% 2>&1

