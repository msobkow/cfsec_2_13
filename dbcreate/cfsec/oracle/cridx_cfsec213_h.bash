#!/bin/bash
#
#	@(#) dbcreate/cfsec/oracle/cridx_cfsec213_h.bash
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

echo "# cridx_clus_hudomnameidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_clus_hudomnameidx.plsql >>${logfilename} 2>&1
echo "# cridx_clus_hudescridx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_clus_hudescridx.plsql >>${logfilename} 2>&1
echo "# cridx_hostnode_hclusteridx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_hostnode_hclusteridx.plsql >>${logfilename} 2>&1
echo "# cridx_hostnode_hudescridx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_hostnode_hudescridx.plsql >>${logfilename} 2>&1
echo "# cridx_hostnode_hhostnameidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_hostnode_hhostnameidx.plsql >>${logfilename} 2>&1
echo "# cridx_iso_ccy_hccycdidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_iso_ccy_hccycdidx.plsql >>${logfilename} 2>&1
echo "# cridx_iso_ccy_hccynmidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_iso_ccy_hccynmidx.plsql >>${logfilename} 2>&1
echo "# cridx_iso_cntry_hisocodeidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_iso_cntry_hisocodeidx.plsql >>${logfilename} 2>&1
echo "# cridx_iso_cntry_hnameidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_iso_cntry_hnameidx.plsql >>${logfilename} 2>&1
echo "# cridx_iso_cntryccy_hctryidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_iso_cntryccy_hctryidx.plsql >>${logfilename} 2>&1
echo "# cridx_iso_cntryccy_hccyidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_iso_cntryccy_hccyidx.plsql >>${logfilename} 2>&1
echo "# cridx_iso_cntrylng_hctryidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_iso_cntrylng_hctryidx.plsql >>${logfilename} 2>&1
echo "# cridx_iso_cntrylng_hlangidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_iso_cntrylng_hlangidx.plsql >>${logfilename} 2>&1
echo "# cridx_iso_lang_hcode3idx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_iso_lang_hcode3idx.plsql >>${logfilename} 2>&1
echo "# cridx_iso_lang_hcode2idx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_iso_lang_hcode2idx.plsql >>${logfilename} 2>&1
echo "# cridx_isotz_hoffsetidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_isotz_hoffsetidx.plsql >>${logfilename} 2>&1
echo "# cridx_isotz_hutznameidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_isotz_hutznameidx.plsql >>${logfilename} 2>&1
echo "# cridx_isotz_hiso8601idx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_isotz_hiso8601idx.plsql >>${logfilename} 2>&1
echo "# cridx_secapp_hclusteridx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secapp_hclusteridx.plsql >>${logfilename} 2>&1
echo "# cridx_secapp_hujeemountidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secapp_hujeemountidx.plsql >>${logfilename} 2>&1
echo "# cridx_secdev_hnameidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secdev_hnameidx.plsql >>${logfilename} 2>&1
echo "# cridx_secdev_huseridx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secdev_huseridx.plsql >>${logfilename} 2>&1
echo "# cridx_secform_hclusteridx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secform_hclusteridx.plsql >>${logfilename} 2>&1
echo "# cridx_secform_hsecappidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secform_hsecappidx.plsql >>${logfilename} 2>&1
echo "# cridx_secform_hujeeservletidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secform_hujeeservletidx.plsql >>${logfilename} 2>&1
echo "# cridx_secgrp_hclusteridx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secgrp_hclusteridx.plsql >>${logfilename} 2>&1
echo "# cridx_secgrp_hclustervisidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secgrp_hclustervisidx.plsql >>${logfilename} 2>&1
echo "# cridx_secgrp_hunameidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secgrp_hunameidx.plsql >>${logfilename} 2>&1
echo "# cridx_secgrpfrm_hclusteridx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secgrpfrm_hclusteridx.plsql >>${logfilename} 2>&1
echo "# cridx_secgrpfrm_hgroupidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secgrpfrm_hgroupidx.plsql >>${logfilename} 2>&1
echo "# cridx_secgrpfrm_happidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secgrpfrm_happidx.plsql >>${logfilename} 2>&1
echo "# cridx_secgrpfrm_hformidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secgrpfrm_hformidx.plsql >>${logfilename} 2>&1
echo "# cridx_secgrpfrm_huformidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secgrpfrm_huformidx.plsql >>${logfilename} 2>&1
echo "# cridx_secinc_hclusteridx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secinc_hclusteridx.plsql >>${logfilename} 2>&1
echo "# cridx_secinc_hgroupidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secinc_hgroupidx.plsql >>${logfilename} 2>&1
echo "# cridx_secinc_hincludeidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secinc_hincludeidx.plsql >>${logfilename} 2>&1
echo "# cridx_secinc_huincludeidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secinc_huincludeidx.plsql >>${logfilename} 2>&1
echo "# cridx_secmemb_hclusteridx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secmemb_hclusteridx.plsql >>${logfilename} 2>&1
echo "# cridx_secmemb_hgroupidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secmemb_hgroupidx.plsql >>${logfilename} 2>&1
echo "# cridx_secmemb_huseridx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secmemb_huseridx.plsql >>${logfilename} 2>&1
echo "# cridx_secmemb_huuseridx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secmemb_huuseridx.plsql >>${logfilename} 2>&1
echo "# cridx_secuser_huloginidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secuser_huloginidx.plsql >>${logfilename} 2>&1
echo "# cridx_secuser_hemconfidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secuser_hemconfidx.plsql >>${logfilename} 2>&1
echo "# cridx_secuser_hpwdresetidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secuser_hpwdresetidx.plsql >>${logfilename} 2>&1
echo "# cridx_secuser_hdefdevidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_secuser_hdefdevidx.plsql >>${logfilename} 2>&1
echo "# cridx_hostsvc_hclusteridx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_hostsvc_hclusteridx.plsql >>${logfilename} 2>&1
echo "# cridx_hostsvc_hhostidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_hostsvc_hhostidx.plsql >>${logfilename} 2>&1
echo "# cridx_hostsvc_htypeidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_hostsvc_htypeidx.plsql >>${logfilename} 2>&1
echo "# cridx_hostsvc_hutypeidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_hostsvc_hutypeidx.plsql >>${logfilename} 2>&1
echo "# cridx_hostsvc_huhostportidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_hostsvc_huhostportidx.plsql >>${logfilename} 2>&1
echo "# cridx_svctype_hudescridx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_svctype_hudescridx.plsql >>${logfilename} 2>&1
echo "# cridx_tsecgrp_htenantidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tsecgrp_htenantidx.plsql >>${logfilename} 2>&1
echo "# cridx_tsecgrp_htenantvisidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tsecgrp_htenantvisidx.plsql >>${logfilename} 2>&1
echo "# cridx_tsecgrp_hunameidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tsecgrp_hunameidx.plsql >>${logfilename} 2>&1
echo "# cridx_tsecinc_htenantidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tsecinc_htenantidx.plsql >>${logfilename} 2>&1
echo "# cridx_tsecinc_hgroupidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tsecinc_hgroupidx.plsql >>${logfilename} 2>&1
echo "# cridx_tsecinc_hincludeidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tsecinc_hincludeidx.plsql >>${logfilename} 2>&1
echo "# cridx_tsecinc_huincludeidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tsecinc_huincludeidx.plsql >>${logfilename} 2>&1
echo "# cridx_tsecmemb_htenantidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tsecmemb_htenantidx.plsql >>${logfilename} 2>&1
echo "# cridx_tsecmemb_hgroupidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tsecmemb_hgroupidx.plsql >>${logfilename} 2>&1
echo "# cridx_tsecmemb_huseridx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tsecmemb_huseridx.plsql >>${logfilename} 2>&1
echo "# cridx_tsecmemb_huuseridx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tsecmemb_huuseridx.plsql >>${logfilename} 2>&1
echo "# cridx_tenant_hclusteridx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tenant_hclusteridx.plsql >>${logfilename} 2>&1
echo "# cridx_tenant_hunameidx.plsql" >>${logfilename}
${sqlpluscmd} <cridx_tenant_hunameidx.plsql >>${logfilename} 2>&1

