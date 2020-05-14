@ECHO OFF
REM	@(#) dbcreate/cfsec/mssql/crtbl_cfsec213.bat
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

%cmddb% <crtbl_cfsec213_idg16.tsql >>%logfilename%
%cmddb% <crtbl_cfsec213_idg32.tsql >>%logfilename%
%cmddb% <crtbl_cfsec213_idg64.tsql >>%logfilename%
%cmddb% <crtbl_clus.tsql >>%logfilename%
%cmddb% <crtbl_clus_idg32.tsql >>%logfilename%
%cmddb% <crtbl_clus_idg64.tsql >>%logfilename%
%cmddb% <crtbl_secapp.tsql >>%logfilename%
%cmddb% <crtbl_secform.tsql >>%logfilename%
%cmddb% <crtbl_secgrp.tsql >>%logfilename%
%cmddb% <crtbl_secgrpfrm.tsql >>%logfilename%
%cmddb% <crtbl_secsess.tsql >>%logfilename%
%cmddb% <crtbl_secuser.tsql >>%logfilename%
%cmddb% <crtbl_tenant.tsql >>%logfilename%
%cmddb% <crtbl_tenant_idg32.tsql >>%logfilename%
%cmddb% <crtbl_tenant_idg64.tsql >>%logfilename%
%cmddb% <crtbl_hostnode.tsql >>%logfilename%
%cmddb% <crtbl_iso_ccy.tsql >>%logfilename%
%cmddb% <crtbl_iso_cntry.tsql >>%logfilename%
%cmddb% <crtbl_iso_cntryccy.tsql >>%logfilename%
%cmddb% <crtbl_iso_cntrylng.tsql >>%logfilename%
%cmddb% <crtbl_iso_lang.tsql >>%logfilename%
%cmddb% <crtbl_isotz.tsql >>%logfilename%
%cmddb% <crtbl_secdev.tsql >>%logfilename%
%cmddb% <crtbl_secinc.tsql >>%logfilename%
%cmddb% <crtbl_secmemb.tsql >>%logfilename%
%cmddb% <crtbl_hostsvc.tsql >>%logfilename%
%cmddb% <crtbl_svctype.tsql >>%logfilename%
%cmddb% <crtbl_sysclus.tsql >>%logfilename%
%cmddb% <crtbl_tsecgrp.tsql >>%logfilename%
%cmddb% <crtbl_tsecinc.tsql >>%logfilename%
%cmddb% <crtbl_tsecmemb.tsql >>%logfilename%
%cmddb% <crtbl_clus_h.tsql >>%logfilename%
%cmddb% <crtbl_hostnode_h.tsql >>%logfilename%
%cmddb% <crtbl_iso_ccy_h.tsql >>%logfilename%
%cmddb% <crtbl_iso_cntry_h.tsql >>%logfilename%
%cmddb% <crtbl_iso_cntryccy_h.tsql >>%logfilename%
%cmddb% <crtbl_iso_cntrylng_h.tsql >>%logfilename%
%cmddb% <crtbl_iso_lang_h.tsql >>%logfilename%
%cmddb% <crtbl_isotz_h.tsql >>%logfilename%
%cmddb% <crtbl_secapp_h.tsql >>%logfilename%
%cmddb% <crtbl_secdev_h.tsql >>%logfilename%
%cmddb% <crtbl_secform_h.tsql >>%logfilename%
%cmddb% <crtbl_secgrp_h.tsql >>%logfilename%
%cmddb% <crtbl_secgrpfrm_h.tsql >>%logfilename%
%cmddb% <crtbl_secinc_h.tsql >>%logfilename%
%cmddb% <crtbl_secmemb_h.tsql >>%logfilename%
%cmddb% <crtbl_secuser_h.tsql >>%logfilename%
%cmddb% <crtbl_hostsvc_h.tsql >>%logfilename%
%cmddb% <crtbl_svctype_h.tsql >>%logfilename%
%cmddb% <crtbl_tsecgrp_h.tsql >>%logfilename%
%cmddb% <crtbl_tsecinc_h.tsql >>%logfilename%
%cmddb% <crtbl_tsecmemb_h.tsql >>%logfilename%
%cmddb% <crtbl_tenant_h.tsql >>%logfilename%

