@ECHO OFF
REM	@(#) dbcreate/cfsec/mssql/cridx_cfsec213.bat
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

%cmddb% <cridx_cluster_xufdname.tsql >>%logfilename%
%cmddb% <cridx_cluster_xudescr.tsql >>%logfilename%
%cmddb% <cridx_hostnode_xcluster.tsql >>%logfilename%
%cmddb% <cridx_hostnode_xudsc.tsql >>%logfilename%
%cmddb% <cridx_hostnode_xhnm.tsql >>%logfilename%
%cmddb% <cridx_isocurrency_xcode.tsql >>%logfilename%
%cmddb% <cridx_isocurrency_xuname.tsql >>%logfilename%
%cmddb% <cridx_isocountry_xcode.tsql >>%logfilename%
%cmddb% <cridx_isocountry_xuname.tsql >>%logfilename%
%cmddb% <cridx_isocountryccy_xcountry.tsql >>%logfilename%
%cmddb% <cridx_isocountryccy_xccy.tsql >>%logfilename%
%cmddb% <cridx_isocountrylang_xcountry.tsql >>%logfilename%
%cmddb% <cridx_isocountrylang_xlang.tsql >>%logfilename%
%cmddb% <cridx_isolang_x6392.tsql >>%logfilename%
%cmddb% <cridx_isolang_x6391.tsql >>%logfilename%
%cmddb% <cridx_itz_xoffset.tsql >>%logfilename%
%cmddb% <cridx_itz_xuname.tsql >>%logfilename%
%cmddb% <cridx_itz_xiso.tsql >>%logfilename%
%cmddb% <cridx_secapp_xcluster.tsql >>%logfilename%
%cmddb% <cridx_secapp_xujeemnt.tsql >>%logfilename%
%cmddb% <cridx_secdev_nameidx.tsql >>%logfilename%
%cmddb% <cridx_secdev_usridx.tsql >>%logfilename%
%cmddb% <cridx_secform_xcluster.tsql >>%logfilename%
%cmddb% <cridx_secform_xsecapp.tsql >>%logfilename%
%cmddb% <cridx_secform_xujeesvlt.tsql >>%logfilename%
%cmddb% <cridx_secgroup_xcluster.tsql >>%logfilename%
%cmddb% <cridx_secgroup_xclustervis.tsql >>%logfilename%
%cmddb% <cridx_secgroup_xuname.tsql >>%logfilename%
%cmddb% <cridx_secgroupform_xcluster.tsql >>%logfilename%
%cmddb% <cridx_secgroupform_xgroup.tsql >>%logfilename%
%cmddb% <cridx_secgroupform_xapp.tsql >>%logfilename%
%cmddb% <cridx_secgroupform_xform.tsql >>%logfilename%
%cmddb% <cridx_secgroupform_xuform.tsql >>%logfilename%
%cmddb% <cridx_secinclude_xcluster.tsql >>%logfilename%
%cmddb% <cridx_secinclude_xgroup.tsql >>%logfilename%
%cmddb% <cridx_secinclude_xinc.tsql >>%logfilename%
%cmddb% <cridx_secinclude_xuinc.tsql >>%logfilename%
%cmddb% <cridx_secmember_xcluster.tsql >>%logfilename%
%cmddb% <cridx_secmember_xgroup.tsql >>%logfilename%
%cmddb% <cridx_secmember_xuser.tsql >>%logfilename%
%cmddb% <cridx_secmember_xuuser.tsql >>%logfilename%
%cmddb% <cridx_session_xsecuser.tsql >>%logfilename%
%cmddb% <cridx_session_xsecdev.tsql >>%logfilename%
%cmddb% <cridx_session_xstart.tsql >>%logfilename%
%cmddb% <cridx_session_xfnsh.tsql >>%logfilename%
%cmddb% <cridx_session_xproxy.tsql >>%logfilename%
%cmddb% <cridx_secuser_xulogin.tsql >>%logfilename%
%cmddb% <cridx_secuser_xemconf.tsql >>%logfilename%
%cmddb% <cridx_secuser_xpwdrst.tsql >>%logfilename%
%cmddb% <cridx_secuser_defdevidx.tsql >>%logfilename%
%cmddb% <cridx_service_xcluster.tsql >>%logfilename%
%cmddb% <cridx_service_xhost.tsql >>%logfilename%
%cmddb% <cridx_service_xtype.tsql >>%logfilename%
%cmddb% <cridx_service_xutype.tsql >>%logfilename%
%cmddb% <cridx_service_xuhpt.tsql >>%logfilename%
%cmddb% <cridx_servicetype_xudsc.tsql >>%logfilename%
%cmddb% <cridx_sysclus_xclus.tsql >>%logfilename%
%cmddb% <cridx_tsecgroup_xtenant.tsql >>%logfilename%
%cmddb% <cridx_tsecgroup_xtenantvis.tsql >>%logfilename%
%cmddb% <cridx_tsecgroup_xuname.tsql >>%logfilename%
%cmddb% <cridx_tsecinclude_xtenant.tsql >>%logfilename%
%cmddb% <cridx_tsecinclude_xgroup.tsql >>%logfilename%
%cmddb% <cridx_tsecinclude_xinc.tsql >>%logfilename%
%cmddb% <cridx_tsecinclude_xuinc.tsql >>%logfilename%
%cmddb% <cridx_tsecmember_xtenant.tsql >>%logfilename%
%cmddb% <cridx_tsecmember_xgroup.tsql >>%logfilename%
%cmddb% <cridx_tsecmember_xuser.tsql >>%logfilename%
%cmddb% <cridx_tsecmember_xuuser.tsql >>%logfilename%
%cmddb% <cridx_tenant_xcluster.tsql >>%logfilename%
%cmddb% <cridx_tenant_xuname.tsql >>%logfilename%

