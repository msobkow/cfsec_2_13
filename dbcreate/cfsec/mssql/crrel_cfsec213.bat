@ECHO OFF
REM	@(#) dbcreate/cfsec/mssql/crrel_cfsec213.bat
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

