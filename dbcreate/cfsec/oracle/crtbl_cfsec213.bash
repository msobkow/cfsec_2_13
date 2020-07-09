#!/bin/bash
#
#	@(#) dbcreate/cfsec/oracle/crtbl_cfsec213.bash
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

echo "# crtbl_clus.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_clus.plsql >>${logfilename} 2>&1
echo "# crtbl_clus_idg32.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_clus_idg32.plsql >>${logfilename} 2>&1
echo "# crtbl_clus_idg64.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_clus_idg64.plsql >>${logfilename} 2>&1
echo "# crtbl_secapp.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_secapp.plsql >>${logfilename} 2>&1
echo "# crtbl_secform.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_secform.plsql >>${logfilename} 2>&1
echo "# crtbl_secgrp.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_secgrp.plsql >>${logfilename} 2>&1
echo "# crtbl_secgrpfrm.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_secgrpfrm.plsql >>${logfilename} 2>&1
echo "# crtbl_secsess.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_secsess.plsql >>${logfilename} 2>&1
echo "# crtbl_secuser.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_secuser.plsql >>${logfilename} 2>&1
echo "# crtbl_tenant.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_tenant.plsql >>${logfilename} 2>&1
echo "# crtbl_tenant_idg32.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_tenant_idg32.plsql >>${logfilename} 2>&1
echo "# crtbl_tenant_idg64.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_tenant_idg64.plsql >>${logfilename} 2>&1
echo "# crtbl_hostnode.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_hostnode.plsql >>${logfilename} 2>&1
echo "# crtbl_iso_ccy.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_iso_ccy.plsql >>${logfilename} 2>&1
echo "# crtbl_iso_cntry.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_iso_cntry.plsql >>${logfilename} 2>&1
echo "# crtbl_iso_cntryccy.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_iso_cntryccy.plsql >>${logfilename} 2>&1
echo "# crtbl_iso_cntrylng.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_iso_cntrylng.plsql >>${logfilename} 2>&1
echo "# crtbl_iso_lang.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_iso_lang.plsql >>${logfilename} 2>&1
echo "# crtbl_isotz.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_isotz.plsql >>${logfilename} 2>&1
echo "# crtbl_secdev.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_secdev.plsql >>${logfilename} 2>&1
echo "# crtbl_secinc.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_secinc.plsql >>${logfilename} 2>&1
echo "# crtbl_secmemb.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_secmemb.plsql >>${logfilename} 2>&1
echo "# crtbl_hostsvc.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_hostsvc.plsql >>${logfilename} 2>&1
echo "# crtbl_svctype.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_svctype.plsql >>${logfilename} 2>&1
echo "# crtbl_sysclus.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_sysclus.plsql >>${logfilename} 2>&1
echo "# crtbl_tsecgrp.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_tsecgrp.plsql >>${logfilename} 2>&1
echo "# crtbl_tsecinc.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_tsecinc.plsql >>${logfilename} 2>&1
echo "# crtbl_tsecmemb.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_tsecmemb.plsql >>${logfilename} 2>&1
echo "# crtbl_clus_h.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_clus_h.plsql >>${logfilename} 2>&1
echo "# crtbl_hostnode_h.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_hostnode_h.plsql >>${logfilename} 2>&1
echo "# crtbl_iso_ccy_h.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_iso_ccy_h.plsql >>${logfilename} 2>&1
echo "# crtbl_iso_cntry_h.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_iso_cntry_h.plsql >>${logfilename} 2>&1
echo "# crtbl_iso_cntryccy_h.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_iso_cntryccy_h.plsql >>${logfilename} 2>&1
echo "# crtbl_iso_cntrylng_h.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_iso_cntrylng_h.plsql >>${logfilename} 2>&1
echo "# crtbl_iso_lang_h.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_iso_lang_h.plsql >>${logfilename} 2>&1
echo "# crtbl_isotz_h.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_isotz_h.plsql >>${logfilename} 2>&1
echo "# crtbl_secapp_h.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_secapp_h.plsql >>${logfilename} 2>&1
echo "# crtbl_secdev_h.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_secdev_h.plsql >>${logfilename} 2>&1
echo "# crtbl_secform_h.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_secform_h.plsql >>${logfilename} 2>&1
echo "# crtbl_secgrp_h.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_secgrp_h.plsql >>${logfilename} 2>&1
echo "# crtbl_secgrpfrm_h.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_secgrpfrm_h.plsql >>${logfilename} 2>&1
echo "# crtbl_secinc_h.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_secinc_h.plsql >>${logfilename} 2>&1
echo "# crtbl_secmemb_h.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_secmemb_h.plsql >>${logfilename} 2>&1
echo "# crtbl_secuser_h.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_secuser_h.plsql >>${logfilename} 2>&1
echo "# crtbl_hostsvc_h.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_hostsvc_h.plsql >>${logfilename} 2>&1
echo "# crtbl_svctype_h.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_svctype_h.plsql >>${logfilename} 2>&1
echo "# crtbl_tsecgrp_h.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_tsecgrp_h.plsql >>${logfilename} 2>&1
echo "# crtbl_tsecinc_h.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_tsecinc_h.plsql >>${logfilename} 2>&1
echo "# crtbl_tsecmemb_h.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_tsecmemb_h.plsql >>${logfilename} 2>&1
echo "# crtbl_tenant_h.plsql" >>${logfilename}
${sqlpluscmd} <crtbl_tenant_h.plsql >>${logfilename} 2>&1

