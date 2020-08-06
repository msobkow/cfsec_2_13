@ECHO off
REM
REM	@(#) dbcreate/cfsec/pgsql/cridx_cfsec213_h.bat
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

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_clus_h_udomnameidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_clus_h_udescridx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_hostnode_h_clusteridx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_hostnode_h_udescridx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_hostnode_h_hostnameidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_iso_ccy_h_ccycdidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_iso_ccy_h_ccynmidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_iso_cntry_h_isocodeidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_iso_cntry_h_nameidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_iso_cntryccy_h_ctryidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_iso_cntryccy_h_ccyidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_iso_cntrylng_h_ctryidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_iso_cntrylng_h_langidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_iso_lang_h_code3idx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_iso_lang_h_code2idx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_isotz_h_offsetidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_isotz_h_utznameidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_isotz_h_iso8601idx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secapp_h_clusteridx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secapp_h_ujeemountidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secdev_h_nameidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secdev_h_useridx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secform_h_clusteridx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secform_h_secappidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secform_h_ujeeservletidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secgrp_h_clusteridx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secgrp_h_clustervisidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secgrp_h_unameidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secgrpfrm_h_clusteridx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secgrpfrm_h_groupidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secgrpfrm_h_appidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secgrpfrm_h_formidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secgrpfrm_h_uformidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secinc_h_clusteridx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secinc_h_groupidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secinc_h_includeidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secinc_h_uincludeidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secmemb_h_clusteridx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secmemb_h_groupidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secmemb_h_useridx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secmemb_h_uuseridx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secuser_h_uloginidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secuser_h_emconfidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secuser_h_pwdresetidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secuser_h_defdevidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_hostsvc_h_clusteridx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_hostsvc_h_hostidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_hostsvc_h_typeidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_hostsvc_h_utypeidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_hostsvc_h_uhostportidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_svctype_h_udescridx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tsecgrp_h_tenantidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tsecgrp_h_tenantvisidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tsecgrp_h_unameidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tsecinc_h_tenantidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tsecinc_h_groupidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tsecinc_h_includeidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tsecinc_h_uincludeidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tsecmemb_h_tenantidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tsecmemb_h_groupidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tsecmemb_h_useridx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tsecmemb_h_uuseridx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tenant_h_clusteridx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tenant_h_unameidx.pgsql >>%logfilename% 2>&1

