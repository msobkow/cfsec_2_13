#!/bin/bash
#
#	@(#) dbcreate/cfsec/oracle/crrel_cfsec213.bash
#
#	com.github.msobkow.CFSec
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

echo "# crrel_clus.plsql" >>${logfilename}
${sqlpluscmd} <crrel_clus.plsql >>${logfilename} 2>&1
echo "# crrel_clus_idg32.plsql" >>${logfilename}
${sqlpluscmd} <crrel_clus_idg32.plsql >>${logfilename} 2>&1
echo "# crrel_clus_idg64.plsql" >>${logfilename}
${sqlpluscmd} <crrel_clus_idg64.plsql >>${logfilename} 2>&1
echo "# crrel_hostnode.plsql" >>${logfilename}
${sqlpluscmd} <crrel_hostnode.plsql >>${logfilename} 2>&1
echo "# crrel_iso_ccy.plsql" >>${logfilename}
${sqlpluscmd} <crrel_iso_ccy.plsql >>${logfilename} 2>&1
echo "# crrel_iso_cntry.plsql" >>${logfilename}
${sqlpluscmd} <crrel_iso_cntry.plsql >>${logfilename} 2>&1
echo "# crrel_iso_cntryccy.plsql" >>${logfilename}
${sqlpluscmd} <crrel_iso_cntryccy.plsql >>${logfilename} 2>&1
echo "# crrel_iso_cntrylng.plsql" >>${logfilename}
${sqlpluscmd} <crrel_iso_cntrylng.plsql >>${logfilename} 2>&1
echo "# crrel_iso_lang.plsql" >>${logfilename}
${sqlpluscmd} <crrel_iso_lang.plsql >>${logfilename} 2>&1
echo "# crrel_isotz.plsql" >>${logfilename}
${sqlpluscmd} <crrel_isotz.plsql >>${logfilename} 2>&1
echo "# crrel_secapp.plsql" >>${logfilename}
${sqlpluscmd} <crrel_secapp.plsql >>${logfilename} 2>&1
echo "# crrel_secdev.plsql" >>${logfilename}
${sqlpluscmd} <crrel_secdev.plsql >>${logfilename} 2>&1
echo "# crrel_secform.plsql" >>${logfilename}
${sqlpluscmd} <crrel_secform.plsql >>${logfilename} 2>&1
echo "# crrel_secgrp.plsql" >>${logfilename}
${sqlpluscmd} <crrel_secgrp.plsql >>${logfilename} 2>&1
echo "# crrel_secgrpfrm.plsql" >>${logfilename}
${sqlpluscmd} <crrel_secgrpfrm.plsql >>${logfilename} 2>&1
echo "# crrel_secinc.plsql" >>${logfilename}
${sqlpluscmd} <crrel_secinc.plsql >>${logfilename} 2>&1
echo "# crrel_secmemb.plsql" >>${logfilename}
${sqlpluscmd} <crrel_secmemb.plsql >>${logfilename} 2>&1
echo "# crrel_secsess.plsql" >>${logfilename}
${sqlpluscmd} <crrel_secsess.plsql >>${logfilename} 2>&1
echo "# crrel_secuser.plsql" >>${logfilename}
${sqlpluscmd} <crrel_secuser.plsql >>${logfilename} 2>&1
echo "# crrel_hostsvc.plsql" >>${logfilename}
${sqlpluscmd} <crrel_hostsvc.plsql >>${logfilename} 2>&1
echo "# crrel_svctype.plsql" >>${logfilename}
${sqlpluscmd} <crrel_svctype.plsql >>${logfilename} 2>&1
echo "# crrel_sysclus.plsql" >>${logfilename}
${sqlpluscmd} <crrel_sysclus.plsql >>${logfilename} 2>&1
echo "# crrel_tsecgrp.plsql" >>${logfilename}
${sqlpluscmd} <crrel_tsecgrp.plsql >>${logfilename} 2>&1
echo "# crrel_tsecinc.plsql" >>${logfilename}
${sqlpluscmd} <crrel_tsecinc.plsql >>${logfilename} 2>&1
echo "# crrel_tsecmemb.plsql" >>${logfilename}
${sqlpluscmd} <crrel_tsecmemb.plsql >>${logfilename} 2>&1
echo "# crrel_tenant.plsql" >>${logfilename}
${sqlpluscmd} <crrel_tenant.plsql >>${logfilename} 2>&1
echo "# crrel_tenant_idg32.plsql" >>${logfilename}
${sqlpluscmd} <crrel_tenant_idg32.plsql >>${logfilename} 2>&1
echo "# crrel_tenant_idg64.plsql" >>${logfilename}
${sqlpluscmd} <crrel_tenant_idg64.plsql >>${logfilename} 2>&1

