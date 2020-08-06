@ECHO off
REM
REM	@(#) dbcreate/cfsec/pgsql/cridx_cfsec213.bat
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

psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_cluster_xufdname.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_cluster_xudescr.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_hostnode_xcluster.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_hostnode_xudsc.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_hostnode_xhnm.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_isocurrency_xcode.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_isocurrency_xuname.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_isocountry_xcode.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_isocountry_xuname.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_isocountryccy_xcountry.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_isocountryccy_xccy.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_isocountrylang_xcountry.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_isocountrylang_xlang.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_isolang_x6392.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_isolang_x6391.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_itz_xoffset.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_itz_xuname.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_itz_xiso.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secapp_xcluster.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secapp_xujeemnt.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secdev_nameidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secdev_usridx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secform_xcluster.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secform_xsecapp.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secform_xujeesvlt.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secgroup_xcluster.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secgroup_xclustervis.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secgroup_xuname.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secgroupform_xcluster.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secgroupform_xgroup.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secgroupform_xapp.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secgroupform_xform.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secgroupform_xuform.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secinclude_xcluster.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secinclude_xgroup.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secinclude_xinc.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secinclude_xuinc.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secmember_xcluster.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secmember_xgroup.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secmember_xuser.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secmember_xuuser.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_session_xsecuser.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_session_xsecdev.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_session_xstart.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_session_xfnsh.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_session_xproxy.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secuser_xulogin.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secuser_xemconf.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secuser_xpwdrst.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_secuser_defdevidx.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_service_xcluster.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_service_xhost.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_service_xtype.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_service_xutype.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_service_xuhpt.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_servicetype_xudsc.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_sysclus_xclus.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tsecgroup_xtenant.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tsecgroup_xtenantvis.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tsecgroup_xuname.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tsecinclude_xtenant.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tsecinclude_xgroup.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tsecinclude_xinc.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tsecinclude_xuinc.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tsecmember_xtenant.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tsecmember_xgroup.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tsecmember_xuser.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tsecmember_xuuser.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tenant_xcluster.pgsql >>%logfilename% 2>&1
psql -h %pghost% -d %pgdb% -U %pguser% -a -e -f cridx_tenant_xuname.pgsql >>%logfilename% 2>&1

