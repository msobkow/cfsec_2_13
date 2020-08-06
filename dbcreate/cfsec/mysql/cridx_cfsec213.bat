@echo off
REM
REM	@(#) dbcreate/cfsec/mysql/cridx_cfsec213.bat
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

echo cridx_cluster_xufdname.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_cluster_xufdname.mysql >>%logfilename% 2>&1
echo cridx_cluster_xudescr.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_cluster_xudescr.mysql >>%logfilename% 2>&1
echo cridx_hostnode_xcluster.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_hostnode_xcluster.mysql >>%logfilename% 2>&1
echo cridx_hostnode_xudsc.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_hostnode_xudsc.mysql >>%logfilename% 2>&1
echo cridx_hostnode_xhnm.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_hostnode_xhnm.mysql >>%logfilename% 2>&1
echo cridx_isocurrency_xcode.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_isocurrency_xcode.mysql >>%logfilename% 2>&1
echo cridx_isocurrency_xuname.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_isocurrency_xuname.mysql >>%logfilename% 2>&1
echo cridx_isocountry_xcode.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_isocountry_xcode.mysql >>%logfilename% 2>&1
echo cridx_isocountry_xuname.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_isocountry_xuname.mysql >>%logfilename% 2>&1
echo cridx_isocountryccy_xcountry.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_isocountryccy_xcountry.mysql >>%logfilename% 2>&1
echo cridx_isocountryccy_xccy.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_isocountryccy_xccy.mysql >>%logfilename% 2>&1
echo cridx_isocountrylang_xcountry.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_isocountrylang_xcountry.mysql >>%logfilename% 2>&1
echo cridx_isocountrylang_xlang.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_isocountrylang_xlang.mysql >>%logfilename% 2>&1
echo cridx_isolang_x6392.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_isolang_x6392.mysql >>%logfilename% 2>&1
echo cridx_isolang_x6391.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_isolang_x6391.mysql >>%logfilename% 2>&1
echo cridx_itz_xoffset.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_itz_xoffset.mysql >>%logfilename% 2>&1
echo cridx_itz_xuname.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_itz_xuname.mysql >>%logfilename% 2>&1
echo cridx_itz_xiso.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_itz_xiso.mysql >>%logfilename% 2>&1
echo cridx_secapp_xcluster.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secapp_xcluster.mysql >>%logfilename% 2>&1
echo cridx_secapp_xujeemnt.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secapp_xujeemnt.mysql >>%logfilename% 2>&1
echo cridx_secdev_nameidx.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secdev_nameidx.mysql >>%logfilename% 2>&1
echo cridx_secdev_usridx.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secdev_usridx.mysql >>%logfilename% 2>&1
echo cridx_secform_xcluster.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secform_xcluster.mysql >>%logfilename% 2>&1
echo cridx_secform_xsecapp.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secform_xsecapp.mysql >>%logfilename% 2>&1
echo cridx_secform_xujeesvlt.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secform_xujeesvlt.mysql >>%logfilename% 2>&1
echo cridx_secgroup_xcluster.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secgroup_xcluster.mysql >>%logfilename% 2>&1
echo cridx_secgroup_xclustervis.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secgroup_xclustervis.mysql >>%logfilename% 2>&1
echo cridx_secgroup_xuname.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secgroup_xuname.mysql >>%logfilename% 2>&1
echo cridx_secgroupform_xcluster.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secgroupform_xcluster.mysql >>%logfilename% 2>&1
echo cridx_secgroupform_xgroup.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secgroupform_xgroup.mysql >>%logfilename% 2>&1
echo cridx_secgroupform_xapp.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secgroupform_xapp.mysql >>%logfilename% 2>&1
echo cridx_secgroupform_xform.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secgroupform_xform.mysql >>%logfilename% 2>&1
echo cridx_secgroupform_xuform.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secgroupform_xuform.mysql >>%logfilename% 2>&1
echo cridx_secinclude_xcluster.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secinclude_xcluster.mysql >>%logfilename% 2>&1
echo cridx_secinclude_xgroup.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secinclude_xgroup.mysql >>%logfilename% 2>&1
echo cridx_secinclude_xinc.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secinclude_xinc.mysql >>%logfilename% 2>&1
echo cridx_secinclude_xuinc.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secinclude_xuinc.mysql >>%logfilename% 2>&1
echo cridx_secmember_xcluster.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secmember_xcluster.mysql >>%logfilename% 2>&1
echo cridx_secmember_xgroup.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secmember_xgroup.mysql >>%logfilename% 2>&1
echo cridx_secmember_xuser.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secmember_xuser.mysql >>%logfilename% 2>&1
echo cridx_secmember_xuuser.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secmember_xuuser.mysql >>%logfilename% 2>&1
echo cridx_session_xsecuser.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_session_xsecuser.mysql >>%logfilename% 2>&1
echo cridx_session_xsecdev.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_session_xsecdev.mysql >>%logfilename% 2>&1
echo cridx_session_xstart.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_session_xstart.mysql >>%logfilename% 2>&1
echo cridx_session_xfnsh.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_session_xfnsh.mysql >>%logfilename% 2>&1
echo cridx_session_xproxy.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_session_xproxy.mysql >>%logfilename% 2>&1
echo cridx_secuser_xulogin.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secuser_xulogin.mysql >>%logfilename% 2>&1
echo cridx_secuser_xemconf.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secuser_xemconf.mysql >>%logfilename% 2>&1
echo cridx_secuser_xpwdrst.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secuser_xpwdrst.mysql >>%logfilename% 2>&1
echo cridx_secuser_defdevidx.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_secuser_defdevidx.mysql >>%logfilename% 2>&1
echo cridx_service_xcluster.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_service_xcluster.mysql >>%logfilename% 2>&1
echo cridx_service_xhost.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_service_xhost.mysql >>%logfilename% 2>&1
echo cridx_service_xtype.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_service_xtype.mysql >>%logfilename% 2>&1
echo cridx_service_xutype.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_service_xutype.mysql >>%logfilename% 2>&1
echo cridx_service_xuhpt.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_service_xuhpt.mysql >>%logfilename% 2>&1
echo cridx_servicetype_xudsc.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_servicetype_xudsc.mysql >>%logfilename% 2>&1
echo cridx_sysclus_xclus.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_sysclus_xclus.mysql >>%logfilename% 2>&1
echo cridx_tsecgroup_xtenant.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_tsecgroup_xtenant.mysql >>%logfilename% 2>&1
echo cridx_tsecgroup_xtenantvis.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_tsecgroup_xtenantvis.mysql >>%logfilename% 2>&1
echo cridx_tsecgroup_xuname.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_tsecgroup_xuname.mysql >>%logfilename% 2>&1
echo cridx_tsecinclude_xtenant.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_tsecinclude_xtenant.mysql >>%logfilename% 2>&1
echo cridx_tsecinclude_xgroup.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_tsecinclude_xgroup.mysql >>%logfilename% 2>&1
echo cridx_tsecinclude_xinc.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_tsecinclude_xinc.mysql >>%logfilename% 2>&1
echo cridx_tsecinclude_xuinc.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_tsecinclude_xuinc.mysql >>%logfilename% 2>&1
echo cridx_tsecmember_xtenant.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_tsecmember_xtenant.mysql >>%logfilename% 2>&1
echo cridx_tsecmember_xgroup.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_tsecmember_xgroup.mysql >>%logfilename% 2>&1
echo cridx_tsecmember_xuser.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_tsecmember_xuser.mysql >>%logfilename% 2>&1
echo cridx_tsecmember_xuuser.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_tsecmember_xuuser.mysql >>%logfilename% 2>&1
echo cridx_tenant_xcluster.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_tenant_xcluster.mysql >>%logfilename% 2>&1
echo cridx_tenant_xuname.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < cridx_tenant_xuname.mysql >>%logfilename% 2>&1

