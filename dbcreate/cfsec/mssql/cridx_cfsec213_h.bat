@ECHO OFF
REM	@(#) dbcreate/cfsec/mssql/cridx_cfsec213_h.bat
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

%cmddb% <cridx_clus_h_udomnameidx.tsql >>%logfilename%
%cmddb% <cridx_clus_h_udescridx.tsql >>%logfilename%
%cmddb% <cridx_hostnode_h_clusteridx.tsql >>%logfilename%
%cmddb% <cridx_hostnode_h_udescridx.tsql >>%logfilename%
%cmddb% <cridx_hostnode_h_hostnameidx.tsql >>%logfilename%
%cmddb% <cridx_iso_ccy_h_ccycdidx.tsql >>%logfilename%
%cmddb% <cridx_iso_ccy_h_ccynmidx.tsql >>%logfilename%
%cmddb% <cridx_iso_cntry_h_isocodeidx.tsql >>%logfilename%
%cmddb% <cridx_iso_cntry_h_nameidx.tsql >>%logfilename%
%cmddb% <cridx_iso_cntryccy_h_ctryidx.tsql >>%logfilename%
%cmddb% <cridx_iso_cntryccy_h_ccyidx.tsql >>%logfilename%
%cmddb% <cridx_iso_cntrylng_h_ctryidx.tsql >>%logfilename%
%cmddb% <cridx_iso_cntrylng_h_langidx.tsql >>%logfilename%
%cmddb% <cridx_iso_lang_h_code3idx.tsql >>%logfilename%
%cmddb% <cridx_iso_lang_h_code2idx.tsql >>%logfilename%
%cmddb% <cridx_isotz_h_offsetidx.tsql >>%logfilename%
%cmddb% <cridx_isotz_h_utznameidx.tsql >>%logfilename%
%cmddb% <cridx_isotz_h_iso8601idx.tsql >>%logfilename%
%cmddb% <cridx_secapp_h_clusteridx.tsql >>%logfilename%
%cmddb% <cridx_secapp_h_ujeemountidx.tsql >>%logfilename%
%cmddb% <cridx_secdev_h_nameidx.tsql >>%logfilename%
%cmddb% <cridx_secdev_h_useridx.tsql >>%logfilename%
%cmddb% <cridx_secform_h_clusteridx.tsql >>%logfilename%
%cmddb% <cridx_secform_h_secappidx.tsql >>%logfilename%
%cmddb% <cridx_secform_h_ujeeservletidx.tsql >>%logfilename%
%cmddb% <cridx_secgrp_h_clusteridx.tsql >>%logfilename%
%cmddb% <cridx_secgrp_h_clustervisidx.tsql >>%logfilename%
%cmddb% <cridx_secgrp_h_unameidx.tsql >>%logfilename%
%cmddb% <cridx_secgrpfrm_h_clusteridx.tsql >>%logfilename%
%cmddb% <cridx_secgrpfrm_h_groupidx.tsql >>%logfilename%
%cmddb% <cridx_secgrpfrm_h_appidx.tsql >>%logfilename%
%cmddb% <cridx_secgrpfrm_h_formidx.tsql >>%logfilename%
%cmddb% <cridx_secgrpfrm_h_uformidx.tsql >>%logfilename%
%cmddb% <cridx_secinc_h_clusteridx.tsql >>%logfilename%
%cmddb% <cridx_secinc_h_groupidx.tsql >>%logfilename%
%cmddb% <cridx_secinc_h_includeidx.tsql >>%logfilename%
%cmddb% <cridx_secinc_h_uincludeidx.tsql >>%logfilename%
%cmddb% <cridx_secmemb_h_clusteridx.tsql >>%logfilename%
%cmddb% <cridx_secmemb_h_groupidx.tsql >>%logfilename%
%cmddb% <cridx_secmemb_h_useridx.tsql >>%logfilename%
%cmddb% <cridx_secmemb_h_uuseridx.tsql >>%logfilename%
%cmddb% <cridx_secuser_h_uloginidx.tsql >>%logfilename%
%cmddb% <cridx_secuser_h_emconfidx.tsql >>%logfilename%
%cmddb% <cridx_secuser_h_pwdresetidx.tsql >>%logfilename%
%cmddb% <cridx_secuser_h_defdevidx.tsql >>%logfilename%
%cmddb% <cridx_hostsvc_h_clusteridx.tsql >>%logfilename%
%cmddb% <cridx_hostsvc_h_hostidx.tsql >>%logfilename%
%cmddb% <cridx_hostsvc_h_typeidx.tsql >>%logfilename%
%cmddb% <cridx_hostsvc_h_utypeidx.tsql >>%logfilename%
%cmddb% <cridx_hostsvc_h_uhostportidx.tsql >>%logfilename%
%cmddb% <cridx_svctype_h_udescridx.tsql >>%logfilename%
%cmddb% <cridx_tsecgrp_h_tenantidx.tsql >>%logfilename%
%cmddb% <cridx_tsecgrp_h_tenantvisidx.tsql >>%logfilename%
%cmddb% <cridx_tsecgrp_h_unameidx.tsql >>%logfilename%
%cmddb% <cridx_tsecinc_h_tenantidx.tsql >>%logfilename%
%cmddb% <cridx_tsecinc_h_groupidx.tsql >>%logfilename%
%cmddb% <cridx_tsecinc_h_includeidx.tsql >>%logfilename%
%cmddb% <cridx_tsecinc_h_uincludeidx.tsql >>%logfilename%
%cmddb% <cridx_tsecmemb_h_tenantidx.tsql >>%logfilename%
%cmddb% <cridx_tsecmemb_h_groupidx.tsql >>%logfilename%
%cmddb% <cridx_tsecmemb_h_useridx.tsql >>%logfilename%
%cmddb% <cridx_tsecmemb_h_uuseridx.tsql >>%logfilename%
%cmddb% <cridx_tenant_h_clusteridx.tsql >>%logfilename%
%cmddb% <cridx_tenant_h_unameidx.tsql >>%logfilename%

