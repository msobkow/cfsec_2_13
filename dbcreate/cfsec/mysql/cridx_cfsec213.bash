#!/bin/bash
#
#	@(#) dbcreate/cfsec/mysql/cridx_cfsec213.bash
#
#	org.msscf.msscf.CFSec
#
#	Copyright (c) 2020 Mark Stephen Sobkow
#	
#	This file is part of MSS Code Factory.
#	
#	Licensed under the Apache License, Version 2.0 (the "License");
#	you may not use this file except in compliance with the License.
#	You may obtain a copy of the License at
#	
#	    http://www.apache.org/licenses/LICENSE-2.0
#	
#	Unless required by applicable law or agreed to in writing, software
#	distributed under the License is distributed on an "AS IS" BASIS,
#	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#	See the License for the specific language governing permissions and
#	limitations under the License.
#	
#	Donations to support MSS Code Factory can be made at
#	https://www.paypal.com/paypalme2/MarkSobkow
#
#	Manufactured by MSS Code Factory 2.12
#

#
#	Initialize locals
#
mysqlpwd=""
mysqluser=""
logfilename=""
parmerrors=""
TK_DUALCASE_IN_CASE_STATEMENTS=true

#
#	Parse the command line options
#
while [ -n "$1" ]
do
	case "$1" in

		-L)
			shift
			logfilename=$1
			shift
			;;

		-P)
			shift
			mysqlpwd=$1
			shift
			;;

		-U)
			shift
			mysqluser=$1
			shift
			;;

		*)
			echo >&2 "ERROR: Option $1 not recognized."
			shift
			parmerrors="Y"
			;;
	esac
done

#
#	Validate parameters
#

if [ "$mysqluser" = "" ]; then
	echo >&2 "ERROR: MySQL user must be specified with '-U username'"
	parmerrors="Y"
fi

if [ "$mysqlpwd" = "" ]; then
	echo >&2 "ERROR: Password must be specified with '-P password'"
	parmerrors="Y"
fi

if [ "$parmerrors" != "" ]; then
	echo >&2 "ABORT: Cannot continue"
	exit 1
fi

if [ "$logfilename" = "" ]; then
	logfilename=`date +'$GenFileBaseName$-%Y%m%d_%Hh%M.log'`
	echo "" >$logfilename
fi

echo "cridx_cluster_xufdname.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_cluster_xufdname.mysql >>$logfilename 2>&1
echo "cridx_cluster_xudescr.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_cluster_xudescr.mysql >>$logfilename 2>&1
echo "cridx_hostnode_xcluster.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_hostnode_xcluster.mysql >>$logfilename 2>&1
echo "cridx_hostnode_xudsc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_hostnode_xudsc.mysql >>$logfilename 2>&1
echo "cridx_hostnode_xhnm.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_hostnode_xhnm.mysql >>$logfilename 2>&1
echo "cridx_isocurrency_xcode.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_isocurrency_xcode.mysql >>$logfilename 2>&1
echo "cridx_isocurrency_xuname.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_isocurrency_xuname.mysql >>$logfilename 2>&1
echo "cridx_isocountry_xcode.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_isocountry_xcode.mysql >>$logfilename 2>&1
echo "cridx_isocountry_xuname.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_isocountry_xuname.mysql >>$logfilename 2>&1
echo "cridx_isocountryccy_xcountry.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_isocountryccy_xcountry.mysql >>$logfilename 2>&1
echo "cridx_isocountryccy_xccy.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_isocountryccy_xccy.mysql >>$logfilename 2>&1
echo "cridx_isocountrylang_xcountry.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_isocountrylang_xcountry.mysql >>$logfilename 2>&1
echo "cridx_isocountrylang_xlang.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_isocountrylang_xlang.mysql >>$logfilename 2>&1
echo "cridx_isolang_x6392.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_isolang_x6392.mysql >>$logfilename 2>&1
echo "cridx_isolang_x6391.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_isolang_x6391.mysql >>$logfilename 2>&1
echo "cridx_itz_xoffset.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_itz_xoffset.mysql >>$logfilename 2>&1
echo "cridx_itz_xuname.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_itz_xuname.mysql >>$logfilename 2>&1
echo "cridx_itz_xiso.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_itz_xiso.mysql >>$logfilename 2>&1
echo "cridx_secapp_xcluster.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secapp_xcluster.mysql >>$logfilename 2>&1
echo "cridx_secapp_xujeemnt.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secapp_xujeemnt.mysql >>$logfilename 2>&1
echo "cridx_secdev_nameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secdev_nameidx.mysql >>$logfilename 2>&1
echo "cridx_secdev_usridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secdev_usridx.mysql >>$logfilename 2>&1
echo "cridx_secform_xcluster.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secform_xcluster.mysql >>$logfilename 2>&1
echo "cridx_secform_xsecapp.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secform_xsecapp.mysql >>$logfilename 2>&1
echo "cridx_secform_xujeesvlt.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secform_xujeesvlt.mysql >>$logfilename 2>&1
echo "cridx_secgroup_xcluster.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secgroup_xcluster.mysql >>$logfilename 2>&1
echo "cridx_secgroup_xclustervis.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secgroup_xclustervis.mysql >>$logfilename 2>&1
echo "cridx_secgroup_xuname.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secgroup_xuname.mysql >>$logfilename 2>&1
echo "cridx_secgroupform_xcluster.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secgroupform_xcluster.mysql >>$logfilename 2>&1
echo "cridx_secgroupform_xgroup.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secgroupform_xgroup.mysql >>$logfilename 2>&1
echo "cridx_secgroupform_xapp.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secgroupform_xapp.mysql >>$logfilename 2>&1
echo "cridx_secgroupform_xform.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secgroupform_xform.mysql >>$logfilename 2>&1
echo "cridx_secgroupform_xuform.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secgroupform_xuform.mysql >>$logfilename 2>&1
echo "cridx_secinclude_xcluster.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secinclude_xcluster.mysql >>$logfilename 2>&1
echo "cridx_secinclude_xgroup.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secinclude_xgroup.mysql >>$logfilename 2>&1
echo "cridx_secinclude_xinc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secinclude_xinc.mysql >>$logfilename 2>&1
echo "cridx_secinclude_xuinc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secinclude_xuinc.mysql >>$logfilename 2>&1
echo "cridx_secmember_xcluster.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secmember_xcluster.mysql >>$logfilename 2>&1
echo "cridx_secmember_xgroup.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secmember_xgroup.mysql >>$logfilename 2>&1
echo "cridx_secmember_xuser.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secmember_xuser.mysql >>$logfilename 2>&1
echo "cridx_secmember_xuuser.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secmember_xuuser.mysql >>$logfilename 2>&1
echo "cridx_session_xsecuser.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_session_xsecuser.mysql >>$logfilename 2>&1
echo "cridx_session_xsecdev.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_session_xsecdev.mysql >>$logfilename 2>&1
echo "cridx_session_xstart.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_session_xstart.mysql >>$logfilename 2>&1
echo "cridx_session_xfnsh.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_session_xfnsh.mysql >>$logfilename 2>&1
echo "cridx_session_xproxy.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_session_xproxy.mysql >>$logfilename 2>&1
echo "cridx_secuser_xulogin.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secuser_xulogin.mysql >>$logfilename 2>&1
echo "cridx_secuser_xemconf.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secuser_xemconf.mysql >>$logfilename 2>&1
echo "cridx_secuser_xpwdrst.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secuser_xpwdrst.mysql >>$logfilename 2>&1
echo "cridx_secuser_defdevidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_secuser_defdevidx.mysql >>$logfilename 2>&1
echo "cridx_service_xcluster.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_service_xcluster.mysql >>$logfilename 2>&1
echo "cridx_service_xhost.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_service_xhost.mysql >>$logfilename 2>&1
echo "cridx_service_xtype.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_service_xtype.mysql >>$logfilename 2>&1
echo "cridx_service_xutype.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_service_xutype.mysql >>$logfilename 2>&1
echo "cridx_service_xuhpt.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_service_xuhpt.mysql >>$logfilename 2>&1
echo "cridx_servicetype_xudsc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_servicetype_xudsc.mysql >>$logfilename 2>&1
echo "cridx_sysclus_xclus.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_sysclus_xclus.mysql >>$logfilename 2>&1
echo "cridx_tsecgroup_xtenant.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_tsecgroup_xtenant.mysql >>$logfilename 2>&1
echo "cridx_tsecgroup_xtenantvis.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_tsecgroup_xtenantvis.mysql >>$logfilename 2>&1
echo "cridx_tsecgroup_xuname.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_tsecgroup_xuname.mysql >>$logfilename 2>&1
echo "cridx_tsecinclude_xtenant.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_tsecinclude_xtenant.mysql >>$logfilename 2>&1
echo "cridx_tsecinclude_xgroup.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_tsecinclude_xgroup.mysql >>$logfilename 2>&1
echo "cridx_tsecinclude_xinc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_tsecinclude_xinc.mysql >>$logfilename 2>&1
echo "cridx_tsecinclude_xuinc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_tsecinclude_xuinc.mysql >>$logfilename 2>&1
echo "cridx_tsecmember_xtenant.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_tsecmember_xtenant.mysql >>$logfilename 2>&1
echo "cridx_tsecmember_xgroup.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_tsecmember_xgroup.mysql >>$logfilename 2>&1
echo "cridx_tsecmember_xuser.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_tsecmember_xuser.mysql >>$logfilename 2>&1
echo "cridx_tsecmember_xuuser.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_tsecmember_xuuser.mysql >>$logfilename 2>&1
echo "cridx_tenant_xcluster.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_tenant_xcluster.mysql >>$logfilename 2>&1
echo "cridx_tenant_xuname.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < cridx_tenant_xuname.mysql >>$logfilename 2>&1

