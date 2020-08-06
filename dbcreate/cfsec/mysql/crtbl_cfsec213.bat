@echo off
REM
REM	@(#) dbcreate/cfsec/mysql/crtbl_cfsec213.bat
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

echo crtbl_cfsec213_idg16.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_cfsec213_idg16.mysql >>%logfilename% 2>&1
echo crtbl_cfsec213_idg32.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_cfsec213_idg32.mysql >>%logfilename% 2>&1
echo crtbl_cfsec213_idg64.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_cfsec213_idg64.mysql >>%logfilename% 2>&1
echo crtbl_clus.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_clus.mysql >>%logfilename% 2>&1
echo crtbl_clus_idg32.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_clus_idg32.mysql >>%logfilename% 2>&1
echo crtbl_clus_idg64.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_clus_idg64.mysql >>%logfilename% 2>&1
echo crtbl_secapp.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secapp.mysql >>%logfilename% 2>&1
echo crtbl_secform.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secform.mysql >>%logfilename% 2>&1
echo crtbl_secgrp.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secgrp.mysql >>%logfilename% 2>&1
echo crtbl_secgrpfrm.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secgrpfrm.mysql >>%logfilename% 2>&1
echo crtbl_secsess.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secsess.mysql >>%logfilename% 2>&1
echo crtbl_secuser.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secuser.mysql >>%logfilename% 2>&1
echo crtbl_tenant.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tenant.mysql >>%logfilename% 2>&1
echo crtbl_tenant_idg32.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tenant_idg32.mysql >>%logfilename% 2>&1
echo crtbl_tenant_idg64.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tenant_idg64.mysql >>%logfilename% 2>&1
echo crtbl_hostnode.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_hostnode.mysql >>%logfilename% 2>&1
echo crtbl_iso_ccy.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_iso_ccy.mysql >>%logfilename% 2>&1
echo crtbl_iso_cntry.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_iso_cntry.mysql >>%logfilename% 2>&1
echo crtbl_iso_cntryccy.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_iso_cntryccy.mysql >>%logfilename% 2>&1
echo crtbl_iso_cntrylng.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_iso_cntrylng.mysql >>%logfilename% 2>&1
echo crtbl_iso_lang.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_iso_lang.mysql >>%logfilename% 2>&1
echo crtbl_isotz.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_isotz.mysql >>%logfilename% 2>&1
echo crtbl_secdev.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secdev.mysql >>%logfilename% 2>&1
echo crtbl_secinc.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secinc.mysql >>%logfilename% 2>&1
echo crtbl_secmemb.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secmemb.mysql >>%logfilename% 2>&1
echo crtbl_hostsvc.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_hostsvc.mysql >>%logfilename% 2>&1
echo crtbl_svctype.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_svctype.mysql >>%logfilename% 2>&1
echo crtbl_sysclus.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_sysclus.mysql >>%logfilename% 2>&1
echo crtbl_tsecgrp.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tsecgrp.mysql >>%logfilename% 2>&1
echo crtbl_tsecinc.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tsecinc.mysql >>%logfilename% 2>&1
echo crtbl_tsecmemb.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tsecmemb.mysql >>%logfilename% 2>&1
echo crtbl_clus_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_clus_h.mysql >>%logfilename% 2>&1
echo crtbl_hostnode_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_hostnode_h.mysql >>%logfilename% 2>&1
echo crtbl_iso_ccy_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_iso_ccy_h.mysql >>%logfilename% 2>&1
echo crtbl_iso_cntry_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_iso_cntry_h.mysql >>%logfilename% 2>&1
echo crtbl_iso_cntryccy_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_iso_cntryccy_h.mysql >>%logfilename% 2>&1
echo crtbl_iso_cntrylng_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_iso_cntrylng_h.mysql >>%logfilename% 2>&1
echo crtbl_iso_lang_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_iso_lang_h.mysql >>%logfilename% 2>&1
echo crtbl_isotz_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_isotz_h.mysql >>%logfilename% 2>&1
echo crtbl_secapp_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secapp_h.mysql >>%logfilename% 2>&1
echo crtbl_secdev_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secdev_h.mysql >>%logfilename% 2>&1
echo crtbl_secform_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secform_h.mysql >>%logfilename% 2>&1
echo crtbl_secgrp_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secgrp_h.mysql >>%logfilename% 2>&1
echo crtbl_secgrpfrm_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secgrpfrm_h.mysql >>%logfilename% 2>&1
echo crtbl_secinc_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secinc_h.mysql >>%logfilename% 2>&1
echo crtbl_secmemb_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secmemb_h.mysql >>%logfilename% 2>&1
echo crtbl_secuser_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secuser_h.mysql >>%logfilename% 2>&1
echo crtbl_hostsvc_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_hostsvc_h.mysql >>%logfilename% 2>&1
echo crtbl_svctype_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_svctype_h.mysql >>%logfilename% 2>&1
echo crtbl_tsecgrp_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tsecgrp_h.mysql >>%logfilename% 2>&1
echo crtbl_tsecinc_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tsecinc_h.mysql >>%logfilename% 2>&1
echo crtbl_tsecmemb_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tsecmemb_h.mysql >>%logfilename% 2>&1
echo crtbl_tenant_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tenant_h.mysql >>%logfilename% 2>&1

