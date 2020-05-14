@ECHO OFF
REM	@(#) dbcreate/cfsec/mssql/crrel_cfsec213.bat
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

%cmddb% <crrel_clus.tsql >>%logfilename%
%cmddb% <crrel_clus_idg32.tsql >>%logfilename%
%cmddb% <crrel_clus_idg64.tsql >>%logfilename%
%cmddb% <crrel_hostnode.tsql >>%logfilename%
%cmddb% <crrel_iso_ccy.tsql >>%logfilename%
%cmddb% <crrel_iso_cntry.tsql >>%logfilename%
%cmddb% <crrel_iso_cntryccy.tsql >>%logfilename%
%cmddb% <crrel_iso_cntrylng.tsql >>%logfilename%
%cmddb% <crrel_iso_lang.tsql >>%logfilename%
%cmddb% <crrel_isotz.tsql >>%logfilename%
%cmddb% <crrel_secapp.tsql >>%logfilename%
%cmddb% <crrel_secdev.tsql >>%logfilename%
%cmddb% <crrel_secform.tsql >>%logfilename%
%cmddb% <crrel_secgrp.tsql >>%logfilename%
%cmddb% <crrel_secgrpfrm.tsql >>%logfilename%
%cmddb% <crrel_secinc.tsql >>%logfilename%
%cmddb% <crrel_secmemb.tsql >>%logfilename%
%cmddb% <crrel_secsess.tsql >>%logfilename%
%cmddb% <crrel_secuser.tsql >>%logfilename%
%cmddb% <crrel_hostsvc.tsql >>%logfilename%
%cmddb% <crrel_svctype.tsql >>%logfilename%
%cmddb% <crrel_sysclus.tsql >>%logfilename%
%cmddb% <crrel_tsecgrp.tsql >>%logfilename%
%cmddb% <crrel_tsecinc.tsql >>%logfilename%
%cmddb% <crrel_tsecmemb.tsql >>%logfilename%
%cmddb% <crrel_tenant.tsql >>%logfilename%
%cmddb% <crrel_tenant_idg32.tsql >>%logfilename%
%cmddb% <crrel_tenant_idg64.tsql >>%logfilename%

