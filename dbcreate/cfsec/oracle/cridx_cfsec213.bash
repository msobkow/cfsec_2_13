#!/bin/bash
#
#	@(#) dbcreate/cfsec/oracle/cridx_cfsec213.bash
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
orahost=""
oraport=""
orapwd=""
oraservice=""
orauser=""
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

		-H)
			shift
			orahost=$1
			shift
			;;

		-P)
			shift
			orapwd=$1
			shift
			;;

		-p)
			shift
			oraport=$1
			shift
			;;

		-S)
			shift
			oraservice=$1
			shift
			;;

		-U)
			shift
			orauser=$1
			shift
			;;

		*)
			echo >&2 "ERROR: Option $1 not recognized."
			parmerrors="Y"
			shift
			;;
	esac
done

#
#	Validate parameters
#

if [ "${orauser}" = "" ]; then
	echo >&2 "ERROR: User must be specified with '-U username'"
	parmerrors="Y"
fi

if [ "${orapwd}" = "" ]; then
	echo >&2 "ERROR: Password must be specified with '-P password'"
	parmerrors="Y"
fi

if [ "${parmerrors}" != "" ]; then
	echo >&2 "ABORT: Cannot continue"
	exit 1
fi

if [ "${logfilename}" = "" ]; then
	logfilename=`date +'$GenFileBaseName$-%Y%m%d_%Hh%M.log'`
	echo "" >$logfilename
fi

if [ "${orahost}" = "" ]; then
	export sqlpluscmd="sqlplus ${orauser}/${orapwd} "
else
	if [ "${oraport}" = "" ]; then
		if [ "${oraservice}" = "" ]; then
			export sqlpluscmd="sqlplus ${orauser}/${orapwd}@//${orahost} "
		else
			export sqlpluscmd="sqlplus ${orauser}/${orapwd}@//${orahost}/${oraservice} "
		fi
	else
		if [ "${oraservice}" = "" ]; then
			export sqlpluscmd="sqlplus ${orauser}/${orapwd}@//${orahost}:${oraport} "
		else
			export sqlpluscmd="sqlplus ${orauser}/${orapwd}@//${orahost}:${oraport}/${oraservice} "
		fi
	fi
fi

echo "# cridx_cluster_xufdname.plsql" >>${logfilename}
${sqlpluscmd} <cridx_cluster_xufdname.plsql >>${logfilename} 2>&1
echo "# cridx_cluster_xudescr.plsql" >>${logfilename}
${sqlpluscmd} <cridx_cluster_xudescr.plsql >>${logfilename} 2>&1
echo "# cridx_hostnode_xcluster.plsql" >>${logfilename}
${sqlpluscmd} <cridx_hostnode_xcluster.plsql >>${logfilename} 2>&1
echo "# cridx_hostnode_xudsc.plsql" >>${logfilename}
${sqlpluscmd} <cridx_hostnode_xudsc.plsql >>${logfilename} 2>&1
echo "# cridx_hostnode_xhnm.plsql" >>${logfilename}
${sqlpluscmd} <cridx_hostnode_xhnm.plsql >>${logfilename} 2>&1
echo "# cridx_isocurrency_xcode.plsql" >>${logfilename}
${sqlpluscmd} <cridx_isocurrency_xcode.plsql >>${logfilename} 2>&1
echo "# cridx_isocurrency_xuname.plsql" >>${logfilename}
${sqlpluscmd} <cridx_isocurrency_xuname.plsql >>${logfilename} 2>&1
echo "# cridx_isocountry_xcode.plsql" >>${logfilename}
${sqlpluscmd} <cridx_isocountry_xcode.plsql >>${logfilename} 2>&1
echo "# cridx_isocountry_xuname.plsql" >>${logfilename}
${sqlpluscmd} <cridx_isocountry_xuname.plsql >>${logfilename} 2>&1
echo "# cridx_isocountryccy_xcountry.plsql" >>${logfilename}
${sqlpluscmd} <cridx_isocountryccy_xcountry.plsql >>${logfilename} 2>&1
echo "# cridx_isocountryccy_xccy.plsql" >>${logfilename}
${sqlpluscmd} <cridx_isocountryccy_xccy.plsql >>${logfilename} 2>&1
echo "# cridx_isocountrylang_xcountry.plsql" >>${logfilename}
${sqlpluscmd} <cridx_isocountrylang_xcountry.plsql >>${logfilename} 2>&1
echo "# cridx_isocountrylang_xlang.plsql" >>${logfilename}
${sqlpluscmd} <cridx_isocountrylang_xlang.plsql >>${logfilename} 2>&1
echo "# cridx_isolang_x6392.plsql" >>${logfilename}
${sqlpluscmd} <cridx_isolang_x6392.plsql >>${logfilename} 2>&1
echo "# cridx_itz_xoffset.plsql" >>${logfilename}
${sqlpluscmd} <cridx_itz_xoffset.plsql >>${logfilename} 2>&1
echo "# cridx_itz_xuname.plsql" >>${logfilename}
${sqlpluscmd} <cridx_itz_xuname.plsql >>${logfilename} 2>&1
echo "# cridx_itz_xiso.plsql" >>${logfilename}
${sqlpluscmd} <cridx_itz_xiso.plsql >>${logfilename} 2>&1
echo "# cridx_secapp_xcluster.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secapp_xcluster.plsql >>${logfilename} 2>&1
echo "# cridx_secapp_xujeemnt.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secapp_xujeemnt.plsql >>${logfilename} 2>&1
echo "# cridx_secdev_nameidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secdev_nameidx.plsql >>${logfilename} 2>&1
echo "# cridx_secdev_usridx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secdev_usridx.plsql >>${logfilename} 2>&1
echo "# cridx_secform_xcluster.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secform_xcluster.plsql >>${logfilename} 2>&1
echo "# cridx_secform_xsecapp.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secform_xsecapp.plsql >>${logfilename} 2>&1
echo "# cridx_secform_xujeesvlt.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secform_xujeesvlt.plsql >>${logfilename} 2>&1
echo "# cridx_secgroup_xcluster.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secgroup_xcluster.plsql >>${logfilename} 2>&1
echo "# cridx_secgroup_xclustervis.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secgroup_xclustervis.plsql >>${logfilename} 2>&1
echo "# cridx_secgroup_xuname.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secgroup_xuname.plsql >>${logfilename} 2>&1
echo "# cridx_secgroupform_xcluster.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secgroupform_xcluster.plsql >>${logfilename} 2>&1
echo "# cridx_secgroupform_xgroup.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secgroupform_xgroup.plsql >>${logfilename} 2>&1
echo "# cridx_secgroupform_xapp.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secgroupform_xapp.plsql >>${logfilename} 2>&1
echo "# cridx_secgroupform_xform.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secgroupform_xform.plsql >>${logfilename} 2>&1
echo "# cridx_secgroupform_xuform.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secgroupform_xuform.plsql >>${logfilename} 2>&1
echo "# cridx_secinclude_xcluster.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secinclude_xcluster.plsql >>${logfilename} 2>&1
echo "# cridx_secinclude_xgroup.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secinclude_xgroup.plsql >>${logfilename} 2>&1
echo "# cridx_secinclude_xinc.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secinclude_xinc.plsql >>${logfilename} 2>&1
echo "# cridx_secinclude_xuinc.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secinclude_xuinc.plsql >>${logfilename} 2>&1
echo "# cridx_secmember_xcluster.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secmember_xcluster.plsql >>${logfilename} 2>&1
echo "# cridx_secmember_xgroup.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secmember_xgroup.plsql >>${logfilename} 2>&1
echo "# cridx_secmember_xuser.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secmember_xuser.plsql >>${logfilename} 2>&1
echo "# cridx_secmember_xuuser.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secmember_xuuser.plsql >>${logfilename} 2>&1
echo "# cridx_session_xsecuser.plsql" >>${logfilename}
${sqlpluscmd} <cridx_session_xsecuser.plsql >>${logfilename} 2>&1
echo "# cridx_session_xstart.plsql" >>${logfilename}
${sqlpluscmd} <cridx_session_xstart.plsql >>${logfilename} 2>&1
echo "# cridx_secuser_xulogin.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secuser_xulogin.plsql >>${logfilename} 2>&1
echo "# cridx_service_xcluster.plsql" >>${logfilename}
${sqlpluscmd} <cridx_service_xcluster.plsql >>${logfilename} 2>&1
echo "# cridx_service_xhost.plsql" >>${logfilename}
${sqlpluscmd} <cridx_service_xhost.plsql >>${logfilename} 2>&1
echo "# cridx_service_xtype.plsql" >>${logfilename}
${sqlpluscmd} <cridx_service_xtype.plsql >>${logfilename} 2>&1
echo "# cridx_service_xutype.plsql" >>${logfilename}
${sqlpluscmd} <cridx_service_xutype.plsql >>${logfilename} 2>&1
echo "# cridx_service_xuhpt.plsql" >>${logfilename}
${sqlpluscmd} <cridx_service_xuhpt.plsql >>${logfilename} 2>&1
echo "# cridx_servicetype_xudsc.plsql" >>${logfilename}
${sqlpluscmd} <cridx_servicetype_xudsc.plsql >>${logfilename} 2>&1
echo "# cridx_sysclus_xclus.plsql" >>${logfilename}
${sqlpluscmd} <cridx_sysclus_xclus.plsql >>${logfilename} 2>&1
echo "# cridx_tsecgroup_xtenant.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tsecgroup_xtenant.plsql >>${logfilename} 2>&1
echo "# cridx_tsecgroup_xtenantvis.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tsecgroup_xtenantvis.plsql >>${logfilename} 2>&1
echo "# cridx_tsecgroup_xuname.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tsecgroup_xuname.plsql >>${logfilename} 2>&1
echo "# cridx_tsecinclude_xtenant.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tsecinclude_xtenant.plsql >>${logfilename} 2>&1
echo "# cridx_tsecinclude_xgroup.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tsecinclude_xgroup.plsql >>${logfilename} 2>&1
echo "# cridx_tsecinclude_xinc.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tsecinclude_xinc.plsql >>${logfilename} 2>&1
echo "# cridx_tsecinclude_xuinc.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tsecinclude_xuinc.plsql >>${logfilename} 2>&1
echo "# cridx_tsecmember_xtenant.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tsecmember_xtenant.plsql >>${logfilename} 2>&1
echo "# cridx_tsecmember_xgroup.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tsecmember_xgroup.plsql >>${logfilename} 2>&1
echo "# cridx_tsecmember_xuser.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tsecmember_xuser.plsql >>${logfilename} 2>&1
echo "# cridx_tsecmember_xuuser.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tsecmember_xuuser.plsql >>${logfilename} 2>&1
echo "# cridx_tenant_xcluster.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tenant_xcluster.plsql >>${logfilename} 2>&1
echo "# cridx_tenant_xuname.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tenant_xuname.plsql >>${logfilename} 2>&1

