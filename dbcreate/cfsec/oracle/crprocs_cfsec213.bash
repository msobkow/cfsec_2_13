#!/bin/bash
#
#	@(#) dbcreate/cfsec/oracle/crprocs_cfsec213.bash
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

echo "#crsp_is_system_user.plsql" >>${logfilename}
${sqlpluscmd} <crsp_is_system_user.plsql >>${logfilename} 2>&1
echo "#crsp_is_cluster_user.plsql" >>${logfilename}
${sqlpluscmd} <crsp_is_cluster_user.plsql >>${logfilename} 2>&1
echo "#crsp_is_tenant_user.plsql" >>${logfilename}
${sqlpluscmd} <crsp_is_tenant_user.plsql >>${logfilename} 2>&1
echo "#crnxt_isoccyidgen.plsql" >>${logfilename}
${sqlpluscmd} <crnxt_isoccyidgen.plsql >>${logfilename} 2>&1
echo "#crnxt_isoctryidgen.plsql" >>${logfilename}
${sqlpluscmd} <crnxt_isoctryidgen.plsql >>${logfilename} 2>&1
echo "#crnxt_isolangidgen.plsql" >>${logfilename}
${sqlpluscmd} <crnxt_isolangidgen.plsql >>${logfilename} 2>&1
echo "#crnxt_isotzoneidgen.plsql" >>${logfilename}
${sqlpluscmd} <crnxt_isotzoneidgen.plsql >>${logfilename} 2>&1
echo "#	crnxt_servicetypeidgen.plsql" >>${logfilename}
${sqlpluscmd} < crnxt_servicetypeidgen.plsql >>$logfilename 2>&1
echo "#	crnxt_clusteridgen.plsql" >>${logfilename}
${sqlpluscmd} < crnxt_clusteridgen.plsql >>$logfilename 2>&1
echo "#	crnxt_tenantidgen.plsql" >>${logfilename}
${sqlpluscmd} < crnxt_tenantidgen.plsql >>$logfilename 2>&1
echo "#	crnxt_secappidgen.plsql" >>${logfilename}
${sqlpluscmd} < crnxt_secappidgen.plsql >>$logfilename 2>&1
echo "#	crnxt_secformidgen.plsql" >>${logfilename}
${sqlpluscmd} < crnxt_secformidgen.plsql >>$logfilename 2>&1
echo "#	crnxt_secgroupidgen.plsql" >>${logfilename}
${sqlpluscmd} < crnxt_secgroupidgen.plsql >>$logfilename 2>&1
echo "# crnxt_hostnodeidgen.plsql" >>$logfilename 2>&1
${sqlpluscmd} <crnxt_hostnodeidgen.plsql >>${logfilename} 2>&1
echo "# crnxt_secgroupformidgen.plsql" >>$logfilename 2>&1
${sqlpluscmd} <crnxt_secgroupformidgen.plsql >>${logfilename} 2>&1
echo "# crnxt_secgrpincidgen.plsql" >>$logfilename 2>&1
${sqlpluscmd} <crnxt_secgrpincidgen.plsql >>${logfilename} 2>&1
echo "# crnxt_secgrpmembidgen.plsql" >>$logfilename 2>&1
${sqlpluscmd} <crnxt_secgrpmembidgen.plsql >>${logfilename} 2>&1
echo "# crnxt_serviceidgen.plsql" >>$logfilename 2>&1
${sqlpluscmd} <crnxt_serviceidgen.plsql >>${logfilename} 2>&1
echo "#	crnxt_tsecgroupidgen.plsql" >>${logfilename}
${sqlpluscmd} < crnxt_tsecgroupidgen.plsql >>$logfilename 2>&1
echo "# crnxt_tsecgrpincidgen.plsql" >>$logfilename 2>&1
${sqlpluscmd} <crnxt_tsecgrpincidgen.plsql >>${logfilename} 2>&1
echo "# crnxt_tsecgrpmembidgen.plsql" >>$logfilename 2>&1
${sqlpluscmd} <crnxt_tsecgrpmembidgen.plsql >>${logfilename} 2>&1
echo "#crsp_bootstrap.plsql" >>${logfilename}
${sqlpluscmd} <crsp_bootstrap.plsql >>${logfilename} 2>&1


echo "#	crcrt_clus.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_clus.plsql >>$logfilename 2>&1
echo "#	crcrt_hostnode.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_hostnode.plsql >>$logfilename 2>&1
echo "#	crcrt_iso_ccy.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_iso_ccy.plsql >>$logfilename 2>&1
echo "#	crcrt_iso_cntry.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_iso_cntry.plsql >>$logfilename 2>&1
echo "#	crcrt_iso_cntryccy.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_iso_cntryccy.plsql >>$logfilename 2>&1
echo "#	crcrt_iso_cntrylng.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_iso_cntrylng.plsql >>$logfilename 2>&1
echo "#	crcrt_iso_lang.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_iso_lang.plsql >>$logfilename 2>&1
echo "#	crcrt_isotz.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_isotz.plsql >>$logfilename 2>&1
echo "#	crcrt_secapp.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_secapp.plsql >>$logfilename 2>&1
echo "#	crcrt_secdev.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_secdev.plsql >>$logfilename 2>&1
echo "#	crcrt_secform.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_secform.plsql >>$logfilename 2>&1
echo "#	crcrt_secgrp.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_secgrp.plsql >>$logfilename 2>&1
echo "#	crcrt_secgrpfrm.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_secgrpfrm.plsql >>$logfilename 2>&1
echo "#	crcrt_secinc.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_secinc.plsql >>$logfilename 2>&1
echo "#	crcrt_secmemb.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_secmemb.plsql >>$logfilename 2>&1
echo "#	crcrt_secsess.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_secsess.plsql >>$logfilename 2>&1
echo "#	crcrt_secuser.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_secuser.plsql >>$logfilename 2>&1
echo "#	crcrt_hostsvc.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_hostsvc.plsql >>$logfilename 2>&1
echo "#	crcrt_svctype.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_svctype.plsql >>$logfilename 2>&1
echo "#	crcrt_sysclus.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_sysclus.plsql >>$logfilename 2>&1
echo "#	crcrt_tsecgrp.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_tsecgrp.plsql >>$logfilename 2>&1
echo "#	crcrt_tsecinc.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_tsecinc.plsql >>$logfilename 2>&1
echo "#	crcrt_tsecmemb.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_tsecmemb.plsql >>$logfilename 2>&1
echo "#	crcrt_tenant.plsql" >>${logfilename}
${sqlpluscmd} < crcrt_tenant.plsql >>$logfilename 2>&1

echo "#	crlck_clus.plsql" >>${logfilename}
${sqlpluscmd} < crlck_clus.plsql >>$logfilename 2>&1
echo "#	crlck_hostnode.plsql" >>${logfilename}
${sqlpluscmd} < crlck_hostnode.plsql >>$logfilename 2>&1
echo "#	crlck_iso_ccy.plsql" >>${logfilename}
${sqlpluscmd} < crlck_iso_ccy.plsql >>$logfilename 2>&1
echo "#	crlck_iso_cntry.plsql" >>${logfilename}
${sqlpluscmd} < crlck_iso_cntry.plsql >>$logfilename 2>&1
echo "#	crlck_iso_cntryccy.plsql" >>${logfilename}
${sqlpluscmd} < crlck_iso_cntryccy.plsql >>$logfilename 2>&1
echo "#	crlck_iso_cntrylng.plsql" >>${logfilename}
${sqlpluscmd} < crlck_iso_cntrylng.plsql >>$logfilename 2>&1
echo "#	crlck_iso_lang.plsql" >>${logfilename}
${sqlpluscmd} < crlck_iso_lang.plsql >>$logfilename 2>&1
echo "#	crlck_isotz.plsql" >>${logfilename}
${sqlpluscmd} < crlck_isotz.plsql >>$logfilename 2>&1
echo "#	crlck_secapp.plsql" >>${logfilename}
${sqlpluscmd} < crlck_secapp.plsql >>$logfilename 2>&1
echo "#	crlck_secdev.plsql" >>${logfilename}
${sqlpluscmd} < crlck_secdev.plsql >>$logfilename 2>&1
echo "#	crlck_secform.plsql" >>${logfilename}
${sqlpluscmd} < crlck_secform.plsql >>$logfilename 2>&1
echo "#	crlck_secgrp.plsql" >>${logfilename}
${sqlpluscmd} < crlck_secgrp.plsql >>$logfilename 2>&1
echo "#	crlck_secgrpfrm.plsql" >>${logfilename}
${sqlpluscmd} < crlck_secgrpfrm.plsql >>$logfilename 2>&1
echo "#	crlck_secinc.plsql" >>${logfilename}
${sqlpluscmd} < crlck_secinc.plsql >>$logfilename 2>&1
echo "#	crlck_secmemb.plsql" >>${logfilename}
${sqlpluscmd} < crlck_secmemb.plsql >>$logfilename 2>&1
echo "#	crlck_secsess.plsql" >>${logfilename}
${sqlpluscmd} < crlck_secsess.plsql >>$logfilename 2>&1
echo "#	crlck_secuser.plsql" >>${logfilename}
${sqlpluscmd} < crlck_secuser.plsql >>$logfilename 2>&1
echo "#	crlck_hostsvc.plsql" >>${logfilename}
${sqlpluscmd} < crlck_hostsvc.plsql >>$logfilename 2>&1
echo "#	crlck_svctype.plsql" >>${logfilename}
${sqlpluscmd} < crlck_svctype.plsql >>$logfilename 2>&1
echo "#	crlck_sysclus.plsql" >>${logfilename}
${sqlpluscmd} < crlck_sysclus.plsql >>$logfilename 2>&1
echo "#	crlck_tsecgrp.plsql" >>${logfilename}
${sqlpluscmd} < crlck_tsecgrp.plsql >>$logfilename 2>&1
echo "#	crlck_tsecinc.plsql" >>${logfilename}
${sqlpluscmd} < crlck_tsecinc.plsql >>$logfilename 2>&1
echo "#	crlck_tsecmemb.plsql" >>${logfilename}
${sqlpluscmd} < crlck_tsecmemb.plsql >>$logfilename 2>&1
echo "#	crlck_tenant.plsql" >>${logfilename}
${sqlpluscmd} < crlck_tenant.plsql >>$logfilename 2>&1

echo "#	crrd_clus.plsql" >>${logfilename}
${sqlpluscmd} < crrd_clus.plsql >>$logfilename 2>&1
echo "#	crrd_clusall.plsql" >>${logfilename}
${sqlpluscmd} < crrd_clusall.plsql >>$logfilename 2>&1
echo "#	crpg_clusall.plsql" >>${logfilename}
${sqlpluscmd} < crpg_clusall.plsql >>$logfilename 2>&1
echo "#	crrd_clusbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_clusbyididx.plsql >>$logfilename 2>&1
echo "#	crrd_clusbyudomnameidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_clusbyudomnameidx.plsql >>$logfilename 2>&1
echo "#	crrd_clusbyudescridx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_clusbyudescridx.plsql >>$logfilename 2>&1
echo "#	crrd_hostnode.plsql" >>${logfilename}
${sqlpluscmd} < crrd_hostnode.plsql >>$logfilename 2>&1
echo "#	crrd_hostnodeall.plsql" >>${logfilename}
${sqlpluscmd} < crrd_hostnodeall.plsql >>$logfilename 2>&1
echo "#	crpg_hostnodeall.plsql" >>${logfilename}
${sqlpluscmd} < crpg_hostnodeall.plsql >>$logfilename 2>&1
echo "#	crrd_hostnodebyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_hostnodebyididx.plsql >>$logfilename 2>&1
echo "#	crrd_hostnodebyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_hostnodebyclusteridx.plsql >>$logfilename 2>&1
echo "#	crpg_hostnodebyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_hostnodebyclusteridx.plsql >>$logfilename 2>&1
echo "#	crrd_hostnodebyudescridx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_hostnodebyudescridx.plsql >>$logfilename 2>&1
echo "#	crrd_hostnodebyhostnameidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_hostnodebyhostnameidx.plsql >>$logfilename 2>&1
echo "#	crrd_iso_ccy.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_ccy.plsql >>$logfilename 2>&1
echo "#	crrd_iso_ccyall.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_ccyall.plsql >>$logfilename 2>&1
echo "#	crrd_iso_ccybyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_ccybyididx.plsql >>$logfilename 2>&1
echo "#	crrd_iso_ccybyccycdidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_ccybyccycdidx.plsql >>$logfilename 2>&1
echo "#	crrd_iso_ccybyccynmidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_ccybyccynmidx.plsql >>$logfilename 2>&1
echo "#	crrd_iso_cntry.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_cntry.plsql >>$logfilename 2>&1
echo "#	crrd_iso_cntryall.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_cntryall.plsql >>$logfilename 2>&1
echo "#	crrd_iso_cntrybyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_cntrybyididx.plsql >>$logfilename 2>&1
echo "#	crrd_iso_cntrybyisocodeidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_cntrybyisocodeidx.plsql >>$logfilename 2>&1
echo "#	crrd_iso_cntrybynameidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_cntrybynameidx.plsql >>$logfilename 2>&1
echo "#	crrd_iso_cntryccy.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_cntryccy.plsql >>$logfilename 2>&1
echo "#	crrd_iso_cntryccyall.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_cntryccyall.plsql >>$logfilename 2>&1
echo "#	crrd_iso_cntryccybyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_cntryccybyididx.plsql >>$logfilename 2>&1
echo "#	crrd_iso_cntryccybyctryidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_cntryccybyctryidx.plsql >>$logfilename 2>&1
echo "#	crrd_iso_cntryccybyccyidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_cntryccybyccyidx.plsql >>$logfilename 2>&1
echo "#	crrd_iso_cntrylng.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_cntrylng.plsql >>$logfilename 2>&1
echo "#	crrd_iso_cntrylngall.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_cntrylngall.plsql >>$logfilename 2>&1
echo "#	crrd_iso_cntrylngbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_cntrylngbyididx.plsql >>$logfilename 2>&1
echo "#	crrd_iso_cntrylngbyctryidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_cntrylngbyctryidx.plsql >>$logfilename 2>&1
echo "#	crrd_iso_cntrylngbylangidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_cntrylngbylangidx.plsql >>$logfilename 2>&1
echo "#	crrd_iso_lang.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_lang.plsql >>$logfilename 2>&1
echo "#	crrd_iso_langall.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_langall.plsql >>$logfilename 2>&1
echo "#	crrd_iso_langbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_langbyididx.plsql >>$logfilename 2>&1
echo "#	crrd_iso_langbycode3idx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_langbycode3idx.plsql >>$logfilename 2>&1
echo "#	crrd_iso_langbycode2idx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_iso_langbycode2idx.plsql >>$logfilename 2>&1
echo "#	crrd_isotz.plsql" >>${logfilename}
${sqlpluscmd} < crrd_isotz.plsql >>$logfilename 2>&1
echo "#	crrd_isotzall.plsql" >>${logfilename}
${sqlpluscmd} < crrd_isotzall.plsql >>$logfilename 2>&1
echo "#	crrd_isotzbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_isotzbyididx.plsql >>$logfilename 2>&1
echo "#	crrd_isotzbyoffsetidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_isotzbyoffsetidx.plsql >>$logfilename 2>&1
echo "#	crrd_isotzbyutznameidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_isotzbyutznameidx.plsql >>$logfilename 2>&1
echo "#	crrd_isotzbyiso8601idx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_isotzbyiso8601idx.plsql >>$logfilename 2>&1
echo "#	crrd_secapp.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secapp.plsql >>$logfilename 2>&1
echo "#	crrd_secappall.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secappall.plsql >>$logfilename 2>&1
echo "#	crpg_secappall.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secappall.plsql >>$logfilename 2>&1
echo "#	crrd_secappbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secappbyididx.plsql >>$logfilename 2>&1
echo "#	crrd_secappbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secappbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crpg_secappbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secappbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crrd_secappbyujeemountidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secappbyujeemountidx.plsql >>$logfilename 2>&1
echo "#	crrd_secdev.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secdev.plsql >>$logfilename 2>&1
echo "#	crrd_secdevall.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secdevall.plsql >>$logfilename 2>&1
echo "#	crpg_secdevall.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secdevall.plsql >>$logfilename 2>&1
echo "#	crrd_secdevbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secdevbyididx.plsql >>$logfilename 2>&1
echo "#	crrd_secdevbynameidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secdevbynameidx.plsql >>$logfilename 2>&1
echo "#	crrd_secdevbyuseridx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secdevbyuseridx.plsql >>$logfilename 2>&1
echo "#	crpg_secdevbyuseridx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secdevbyuseridx.plsql >>$logfilename 2>&1
echo "#	crrd_secform.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secform.plsql >>$logfilename 2>&1
echo "#	crrd_secformall.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secformall.plsql >>$logfilename 2>&1
echo "#	crpg_secformall.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secformall.plsql >>$logfilename 2>&1
echo "#	crrd_secformbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secformbyididx.plsql >>$logfilename 2>&1
echo "#	crrd_secformbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secformbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crpg_secformbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secformbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crrd_secformbysecappidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secformbysecappidx.plsql >>$logfilename 2>&1
echo "#	crpg_secformbysecappidx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secformbysecappidx.plsql >>$logfilename 2>&1
echo "#	crrd_secformbyujeeservletidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secformbyujeeservletidx.plsql >>$logfilename 2>&1
echo "#	crrd_secgrp.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secgrp.plsql >>$logfilename 2>&1
echo "#	crrd_secgrpall.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secgrpall.plsql >>$logfilename 2>&1
echo "#	crrd_secgrpbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secgrpbyididx.plsql >>$logfilename 2>&1
echo "#	crrd_secgrpbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secgrpbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crrd_secgrpbyclustervisidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secgrpbyclustervisidx.plsql >>$logfilename 2>&1
echo "#	crrd_secgrpbyunameidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secgrpbyunameidx.plsql >>$logfilename 2>&1
echo "#	crrd_secgrpfrm.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secgrpfrm.plsql >>$logfilename 2>&1
echo "#	crrd_secgrpfrmall.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secgrpfrmall.plsql >>$logfilename 2>&1
echo "#	crpg_secgrpfrmall.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secgrpfrmall.plsql >>$logfilename 2>&1
echo "#	crrd_secgrpfrmbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secgrpfrmbyididx.plsql >>$logfilename 2>&1
echo "#	crrd_secgrpfrmbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secgrpfrmbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crpg_secgrpfrmbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secgrpfrmbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crrd_secgrpfrmbygroupidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secgrpfrmbygroupidx.plsql >>$logfilename 2>&1
echo "#	crpg_secgrpfrmbygroupidx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secgrpfrmbygroupidx.plsql >>$logfilename 2>&1
echo "#	crrd_secgrpfrmbyappidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secgrpfrmbyappidx.plsql >>$logfilename 2>&1
echo "#	crpg_secgrpfrmbyappidx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secgrpfrmbyappidx.plsql >>$logfilename 2>&1
echo "#	crrd_secgrpfrmbyformidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secgrpfrmbyformidx.plsql >>$logfilename 2>&1
echo "#	crpg_secgrpfrmbyformidx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secgrpfrmbyformidx.plsql >>$logfilename 2>&1
echo "#	crrd_secgrpfrmbyuformidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secgrpfrmbyuformidx.plsql >>$logfilename 2>&1
echo "#	crrd_secinc.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secinc.plsql >>$logfilename 2>&1
echo "#	crrd_secincall.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secincall.plsql >>$logfilename 2>&1
echo "#	crpg_secincall.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secincall.plsql >>$logfilename 2>&1
echo "#	crrd_secincbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secincbyididx.plsql >>$logfilename 2>&1
echo "#	crrd_secincbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secincbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crpg_secincbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secincbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crrd_secincbygroupidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secincbygroupidx.plsql >>$logfilename 2>&1
echo "#	crpg_secincbygroupidx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secincbygroupidx.plsql >>$logfilename 2>&1
echo "#	crrd_secincbyincludeidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secincbyincludeidx.plsql >>$logfilename 2>&1
echo "#	crpg_secincbyincludeidx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secincbyincludeidx.plsql >>$logfilename 2>&1
echo "#	crrd_secincbyuincludeidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secincbyuincludeidx.plsql >>$logfilename 2>&1
echo "#	crrd_secmemb.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secmemb.plsql >>$logfilename 2>&1
echo "#	crrd_secmemball.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secmemball.plsql >>$logfilename 2>&1
echo "#	crpg_secmemball.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secmemball.plsql >>$logfilename 2>&1
echo "#	crrd_secmembbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secmembbyididx.plsql >>$logfilename 2>&1
echo "#	crrd_secmembbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secmembbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crpg_secmembbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secmembbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crrd_secmembbygroupidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secmembbygroupidx.plsql >>$logfilename 2>&1
echo "#	crpg_secmembbygroupidx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secmembbygroupidx.plsql >>$logfilename 2>&1
echo "#	crrd_secmembbyuseridx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secmembbyuseridx.plsql >>$logfilename 2>&1
echo "#	crpg_secmembbyuseridx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secmembbyuseridx.plsql >>$logfilename 2>&1
echo "#	crrd_secmembbyuuseridx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secmembbyuuseridx.plsql >>$logfilename 2>&1
echo "#	crrd_secsess.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secsess.plsql >>$logfilename 2>&1
echo "#	crrd_secsessall.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secsessall.plsql >>$logfilename 2>&1
echo "#	crpg_secsessall.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secsessall.plsql >>$logfilename 2>&1
echo "#	crrd_secsessbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secsessbyididx.plsql >>$logfilename 2>&1
echo "#	crrd_secsessbysecuseridx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secsessbysecuseridx.plsql >>$logfilename 2>&1
echo "#	crpg_secsessbysecuseridx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secsessbysecuseridx.plsql >>$logfilename 2>&1
echo "#	crrd_secsessbysecdevidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secsessbysecdevidx.plsql >>$logfilename 2>&1
echo "#	crpg_secsessbysecdevidx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secsessbysecdevidx.plsql >>$logfilename 2>&1
echo "#	crrd_secsessbystartidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secsessbystartidx.plsql >>$logfilename 2>&1
echo "#	crrd_secsessbyfinishidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secsessbyfinishidx.plsql >>$logfilename 2>&1
echo "#	crpg_secsessbyfinishidx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secsessbyfinishidx.plsql >>$logfilename 2>&1
echo "#	crrd_secsessbysecproxyidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secsessbysecproxyidx.plsql >>$logfilename 2>&1
echo "#	crpg_secsessbysecproxyidx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secsessbysecproxyidx.plsql >>$logfilename 2>&1
echo "#	crrd_secuser.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secuser.plsql >>$logfilename 2>&1
echo "#	crrd_secuserall.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secuserall.plsql >>$logfilename 2>&1
echo "#	crpg_secuserall.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secuserall.plsql >>$logfilename 2>&1
echo "#	crrd_secuserbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secuserbyididx.plsql >>$logfilename 2>&1
echo "#	crrd_secuserbyuloginidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secuserbyuloginidx.plsql >>$logfilename 2>&1
echo "#	crrd_secuserbyemconfidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secuserbyemconfidx.plsql >>$logfilename 2>&1
echo "#	crpg_secuserbyemconfidx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secuserbyemconfidx.plsql >>$logfilename 2>&1
echo "#	crrd_secuserbypwdresetidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secuserbypwdresetidx.plsql >>$logfilename 2>&1
echo "#	crpg_secuserbypwdresetidx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secuserbypwdresetidx.plsql >>$logfilename 2>&1
echo "#	crrd_secuserbydefdevidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_secuserbydefdevidx.plsql >>$logfilename 2>&1
echo "#	crpg_secuserbydefdevidx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_secuserbydefdevidx.plsql >>$logfilename 2>&1
echo "#	crrd_hostsvc.plsql" >>${logfilename}
${sqlpluscmd} < crrd_hostsvc.plsql >>$logfilename 2>&1
echo "#	crrd_hostsvcall.plsql" >>${logfilename}
${sqlpluscmd} < crrd_hostsvcall.plsql >>$logfilename 2>&1
echo "#	crpg_hostsvcall.plsql" >>${logfilename}
${sqlpluscmd} < crpg_hostsvcall.plsql >>$logfilename 2>&1
echo "#	crrd_hostsvcbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_hostsvcbyididx.plsql >>$logfilename 2>&1
echo "#	crrd_hostsvcbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_hostsvcbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crpg_hostsvcbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_hostsvcbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crrd_hostsvcbyhostidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_hostsvcbyhostidx.plsql >>$logfilename 2>&1
echo "#	crpg_hostsvcbyhostidx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_hostsvcbyhostidx.plsql >>$logfilename 2>&1
echo "#	crrd_hostsvcbytypeidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_hostsvcbytypeidx.plsql >>$logfilename 2>&1
echo "#	crpg_hostsvcbytypeidx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_hostsvcbytypeidx.plsql >>$logfilename 2>&1
echo "#	crrd_hostsvcbyutypeidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_hostsvcbyutypeidx.plsql >>$logfilename 2>&1
echo "#	crrd_hostsvcbyuhostportidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_hostsvcbyuhostportidx.plsql >>$logfilename 2>&1
echo "#	crrd_svctype.plsql" >>${logfilename}
${sqlpluscmd} < crrd_svctype.plsql >>$logfilename 2>&1
echo "#	crrd_svctypeall.plsql" >>${logfilename}
${sqlpluscmd} < crrd_svctypeall.plsql >>$logfilename 2>&1
echo "#	crrd_svctypebyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_svctypebyididx.plsql >>$logfilename 2>&1
echo "#	crrd_svctypebyudescridx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_svctypebyudescridx.plsql >>$logfilename 2>&1
echo "#	crrd_sysclus.plsql" >>${logfilename}
${sqlpluscmd} < crrd_sysclus.plsql >>$logfilename 2>&1
echo "#	crrd_sysclusall.plsql" >>${logfilename}
${sqlpluscmd} < crrd_sysclusall.plsql >>$logfilename 2>&1
echo "#	crrd_sysclusbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_sysclusbyididx.plsql >>$logfilename 2>&1
echo "#	crrd_sysclusbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_sysclusbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crrd_tsecgrp.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tsecgrp.plsql >>$logfilename 2>&1
echo "#	crrd_tsecgrpall.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tsecgrpall.plsql >>$logfilename 2>&1
echo "#	crrd_tsecgrpbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tsecgrpbyididx.plsql >>$logfilename 2>&1
echo "#	crrd_tsecgrpbytenantidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tsecgrpbytenantidx.plsql >>$logfilename 2>&1
echo "#	crrd_tsecgrpbytenantvisidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tsecgrpbytenantvisidx.plsql >>$logfilename 2>&1
echo "#	crrd_tsecgrpbyunameidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tsecgrpbyunameidx.plsql >>$logfilename 2>&1
echo "#	crrd_tsecinc.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tsecinc.plsql >>$logfilename 2>&1
echo "#	crrd_tsecincall.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tsecincall.plsql >>$logfilename 2>&1
echo "#	crpg_tsecincall.plsql" >>${logfilename}
${sqlpluscmd} < crpg_tsecincall.plsql >>$logfilename 2>&1
echo "#	crrd_tsecincbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tsecincbyididx.plsql >>$logfilename 2>&1
echo "#	crrd_tsecincbytenantidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tsecincbytenantidx.plsql >>$logfilename 2>&1
echo "#	crpg_tsecincbytenantidx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_tsecincbytenantidx.plsql >>$logfilename 2>&1
echo "#	crrd_tsecincbygroupidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tsecincbygroupidx.plsql >>$logfilename 2>&1
echo "#	crpg_tsecincbygroupidx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_tsecincbygroupidx.plsql >>$logfilename 2>&1
echo "#	crrd_tsecincbyincludeidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tsecincbyincludeidx.plsql >>$logfilename 2>&1
echo "#	crpg_tsecincbyincludeidx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_tsecincbyincludeidx.plsql >>$logfilename 2>&1
echo "#	crrd_tsecincbyuincludeidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tsecincbyuincludeidx.plsql >>$logfilename 2>&1
echo "#	crrd_tsecmemb.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tsecmemb.plsql >>$logfilename 2>&1
echo "#	crrd_tsecmemball.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tsecmemball.plsql >>$logfilename 2>&1
echo "#	crpg_tsecmemball.plsql" >>${logfilename}
${sqlpluscmd} < crpg_tsecmemball.plsql >>$logfilename 2>&1
echo "#	crrd_tsecmembbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tsecmembbyididx.plsql >>$logfilename 2>&1
echo "#	crrd_tsecmembbytenantidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tsecmembbytenantidx.plsql >>$logfilename 2>&1
echo "#	crpg_tsecmembbytenantidx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_tsecmembbytenantidx.plsql >>$logfilename 2>&1
echo "#	crrd_tsecmembbygroupidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tsecmembbygroupidx.plsql >>$logfilename 2>&1
echo "#	crpg_tsecmembbygroupidx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_tsecmembbygroupidx.plsql >>$logfilename 2>&1
echo "#	crrd_tsecmembbyuseridx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tsecmembbyuseridx.plsql >>$logfilename 2>&1
echo "#	crpg_tsecmembbyuseridx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_tsecmembbyuseridx.plsql >>$logfilename 2>&1
echo "#	crrd_tsecmembbyuuseridx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tsecmembbyuuseridx.plsql >>$logfilename 2>&1
echo "#	crrd_tenant.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tenant.plsql >>$logfilename 2>&1
echo "#	crrd_tenantall.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tenantall.plsql >>$logfilename 2>&1
echo "#	crpg_tenantall.plsql" >>${logfilename}
${sqlpluscmd} < crpg_tenantall.plsql >>$logfilename 2>&1
echo "#	crrd_tenantbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tenantbyididx.plsql >>$logfilename 2>&1
echo "#	crrd_tenantbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tenantbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crpg_tenantbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crpg_tenantbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crrd_tenantbyunameidx.plsql" >>${logfilename}
${sqlpluscmd} < crrd_tenantbyunameidx.plsql >>$logfilename 2>&1

echo "#	crupd_clus.plsql" >>${logfilename}
${sqlpluscmd} < crupd_clus.plsql >>$logfilename 2>&1
echo "#	crupd_hostnode.plsql" >>${logfilename}
${sqlpluscmd} < crupd_hostnode.plsql >>$logfilename 2>&1
echo "#	crupd_iso_ccy.plsql" >>${logfilename}
${sqlpluscmd} < crupd_iso_ccy.plsql >>$logfilename 2>&1
echo "#	crupd_iso_cntry.plsql" >>${logfilename}
${sqlpluscmd} < crupd_iso_cntry.plsql >>$logfilename 2>&1
echo "#	crupd_iso_cntryccy.plsql" >>${logfilename}
${sqlpluscmd} < crupd_iso_cntryccy.plsql >>$logfilename 2>&1
echo "#	crupd_iso_cntrylng.plsql" >>${logfilename}
${sqlpluscmd} < crupd_iso_cntrylng.plsql >>$logfilename 2>&1
echo "#	crupd_iso_lang.plsql" >>${logfilename}
${sqlpluscmd} < crupd_iso_lang.plsql >>$logfilename 2>&1
echo "#	crupd_isotz.plsql" >>${logfilename}
${sqlpluscmd} < crupd_isotz.plsql >>$logfilename 2>&1
echo "#	crupd_secapp.plsql" >>${logfilename}
${sqlpluscmd} < crupd_secapp.plsql >>$logfilename 2>&1
echo "#	crupd_secdev.plsql" >>${logfilename}
${sqlpluscmd} < crupd_secdev.plsql >>$logfilename 2>&1
echo "#	crupd_secform.plsql" >>${logfilename}
${sqlpluscmd} < crupd_secform.plsql >>$logfilename 2>&1
echo "#	crupd_secgrp.plsql" >>${logfilename}
${sqlpluscmd} < crupd_secgrp.plsql >>$logfilename 2>&1
echo "#	crupd_secgrpfrm.plsql" >>${logfilename}
${sqlpluscmd} < crupd_secgrpfrm.plsql >>$logfilename 2>&1
echo "#	crupd_secinc.plsql" >>${logfilename}
${sqlpluscmd} < crupd_secinc.plsql >>$logfilename 2>&1
echo "#	crupd_secmemb.plsql" >>${logfilename}
${sqlpluscmd} < crupd_secmemb.plsql >>$logfilename 2>&1
echo "#	crupd_secsess.plsql" >>${logfilename}
${sqlpluscmd} < crupd_secsess.plsql >>$logfilename 2>&1
echo "#	crupd_secuser.plsql" >>${logfilename}
${sqlpluscmd} < crupd_secuser.plsql >>$logfilename 2>&1
echo "#	crupd_hostsvc.plsql" >>${logfilename}
${sqlpluscmd} < crupd_hostsvc.plsql >>$logfilename 2>&1
echo "#	crupd_svctype.plsql" >>${logfilename}
${sqlpluscmd} < crupd_svctype.plsql >>$logfilename 2>&1
echo "#	crupd_sysclus.plsql" >>${logfilename}
${sqlpluscmd} < crupd_sysclus.plsql >>$logfilename 2>&1
echo "#	crupd_tsecgrp.plsql" >>${logfilename}
${sqlpluscmd} < crupd_tsecgrp.plsql >>$logfilename 2>&1
echo "#	crupd_tsecinc.plsql" >>${logfilename}
${sqlpluscmd} < crupd_tsecinc.plsql >>$logfilename 2>&1
echo "#	crupd_tsecmemb.plsql" >>${logfilename}
${sqlpluscmd} < crupd_tsecmemb.plsql >>$logfilename 2>&1
echo "#	crupd_tenant.plsql" >>${logfilename}
${sqlpluscmd} < crupd_tenant.plsql >>$logfilename 2>&1



echo "#	crdl_clus_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_clus_stub.plsql >>$logfilename 2>&1
echo "#	crdl_hostnode_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_hostnode_stub.plsql >>$logfilename 2>&1
echo "#	crdl_iso_ccy_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_ccy_stub.plsql >>$logfilename 2>&1
echo "#	crdl_iso_cntry_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_cntry_stub.plsql >>$logfilename 2>&1
echo "#	crdl_iso_cntryccy_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_cntryccy_stub.plsql >>$logfilename 2>&1
echo "#	crdl_iso_cntrylng_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_cntrylng_stub.plsql >>$logfilename 2>&1
echo "#	crdl_iso_lang_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_lang_stub.plsql >>$logfilename 2>&1
echo "#	crdl_isotz_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_isotz_stub.plsql >>$logfilename 2>&1
echo "#	crdl_secapp_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secapp_stub.plsql >>$logfilename 2>&1
echo "#	crdl_secdev_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secdev_stub.plsql >>$logfilename 2>&1
echo "#	crdl_secform_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secform_stub.plsql >>$logfilename 2>&1
echo "#	crdl_secgrp_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secgrp_stub.plsql >>$logfilename 2>&1
echo "#	crdl_secgrpfrm_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secgrpfrm_stub.plsql >>$logfilename 2>&1
echo "#	crdl_secinc_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secinc_stub.plsql >>$logfilename 2>&1
echo "#	crdl_secmemb_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secmemb_stub.plsql >>$logfilename 2>&1
echo "#	crdl_secsess_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secsess_stub.plsql >>$logfilename 2>&1
echo "#	crdl_secuser_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secuser_stub.plsql >>$logfilename 2>&1
echo "#	crdl_hostsvc_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_hostsvc_stub.plsql >>$logfilename 2>&1
echo "#	crdl_svctype_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_svctype_stub.plsql >>$logfilename 2>&1
echo "#	crdl_sysclus_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_sysclus_stub.plsql >>$logfilename 2>&1
echo "#	crdl_tsecgrp_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tsecgrp_stub.plsql >>$logfilename 2>&1
echo "#	crdl_tsecinc_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tsecinc_stub.plsql >>$logfilename 2>&1
echo "#	crdl_tsecmemb_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tsecmemb_stub.plsql >>$logfilename 2>&1
echo "#	crdl_tenant_stub.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tenant_stub.plsql >>$logfilename 2>&1

echo "#	crdl_clusbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_clusbyididx.plsql >>$logfilename 2>&1
echo "#	crdl_clusbyudomnameidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_clusbyudomnameidx.plsql >>$logfilename 2>&1
echo "#	crdl_clusbyudescridx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_clusbyudescridx.plsql >>$logfilename 2>&1
echo "#	crdl_hostnodebyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_hostnodebyididx.plsql >>$logfilename 2>&1
echo "#	crdl_hostnodebyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_hostnodebyclusteridx.plsql >>$logfilename 2>&1
echo "#	crdl_hostnodebyudescridx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_hostnodebyudescridx.plsql >>$logfilename 2>&1
echo "#	crdl_hostnodebyhostnameidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_hostnodebyhostnameidx.plsql >>$logfilename 2>&1
echo "#	crdl_iso_ccybyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_ccybyididx.plsql >>$logfilename 2>&1
echo "#	crdl_iso_ccybyccycdidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_ccybyccycdidx.plsql >>$logfilename 2>&1
echo "#	crdl_iso_ccybyccynmidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_ccybyccynmidx.plsql >>$logfilename 2>&1
echo "#	crdl_iso_cntrybyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_cntrybyididx.plsql >>$logfilename 2>&1
echo "#	crdl_iso_cntrybyisocodeidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_cntrybyisocodeidx.plsql >>$logfilename 2>&1
echo "#	crdl_iso_cntrybynameidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_cntrybynameidx.plsql >>$logfilename 2>&1
echo "#	crdl_iso_cntryccybyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_cntryccybyididx.plsql >>$logfilename 2>&1
echo "#	crdl_iso_cntryccybyctryidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_cntryccybyctryidx.plsql >>$logfilename 2>&1
echo "#	crdl_iso_cntryccybyccyidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_cntryccybyccyidx.plsql >>$logfilename 2>&1
echo "#	crdl_iso_cntrylngbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_cntrylngbyididx.plsql >>$logfilename 2>&1
echo "#	crdl_iso_cntrylngbyctryidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_cntrylngbyctryidx.plsql >>$logfilename 2>&1
echo "#	crdl_iso_cntrylngbylangidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_cntrylngbylangidx.plsql >>$logfilename 2>&1
echo "#	crdl_iso_langbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_langbyididx.plsql >>$logfilename 2>&1
echo "#	crdl_iso_langbycode3idx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_langbycode3idx.plsql >>$logfilename 2>&1
echo "#	crdl_iso_langbycode2idx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_langbycode2idx.plsql >>$logfilename 2>&1
echo "#	crdl_isotzbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_isotzbyididx.plsql >>$logfilename 2>&1
echo "#	crdl_isotzbyoffsetidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_isotzbyoffsetidx.plsql >>$logfilename 2>&1
echo "#	crdl_isotzbyutznameidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_isotzbyutznameidx.plsql >>$logfilename 2>&1
echo "#	crdl_isotzbyiso8601idx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_isotzbyiso8601idx.plsql >>$logfilename 2>&1
echo "#	crdl_secappbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secappbyididx.plsql >>$logfilename 2>&1
echo "#	crdl_secappbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secappbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crdl_secappbyujeemountidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secappbyujeemountidx.plsql >>$logfilename 2>&1
echo "#	crdl_secdevbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secdevbyididx.plsql >>$logfilename 2>&1
echo "#	crdl_secdevbynameidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secdevbynameidx.plsql >>$logfilename 2>&1
echo "#	crdl_secdevbyuseridx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secdevbyuseridx.plsql >>$logfilename 2>&1
echo "#	crdl_secformbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secformbyididx.plsql >>$logfilename 2>&1
echo "#	crdl_secformbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secformbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crdl_secformbysecappidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secformbysecappidx.plsql >>$logfilename 2>&1
echo "#	crdl_secformbyujeeservletidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secformbyujeeservletidx.plsql >>$logfilename 2>&1
echo "#	crdl_secgrpbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secgrpbyididx.plsql >>$logfilename 2>&1
echo "#	crdl_secgrpbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secgrpbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crdl_secgrpbyclustervisidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secgrpbyclustervisidx.plsql >>$logfilename 2>&1
echo "#	crdl_secgrpbyunameidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secgrpbyunameidx.plsql >>$logfilename 2>&1
echo "#	crdl_secgrpfrmbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secgrpfrmbyididx.plsql >>$logfilename 2>&1
echo "#	crdl_secgrpfrmbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secgrpfrmbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crdl_secgrpfrmbygroupidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secgrpfrmbygroupidx.plsql >>$logfilename 2>&1
echo "#	crdl_secgrpfrmbyappidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secgrpfrmbyappidx.plsql >>$logfilename 2>&1
echo "#	crdl_secgrpfrmbyformidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secgrpfrmbyformidx.plsql >>$logfilename 2>&1
echo "#	crdl_secgrpfrmbyuformidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secgrpfrmbyuformidx.plsql >>$logfilename 2>&1
echo "#	crdl_secincbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secincbyididx.plsql >>$logfilename 2>&1
echo "#	crdl_secincbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secincbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crdl_secincbygroupidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secincbygroupidx.plsql >>$logfilename 2>&1
echo "#	crdl_secincbyincludeidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secincbyincludeidx.plsql >>$logfilename 2>&1
echo "#	crdl_secincbyuincludeidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secincbyuincludeidx.plsql >>$logfilename 2>&1
echo "#	crdl_secmembbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secmembbyididx.plsql >>$logfilename 2>&1
echo "#	crdl_secmembbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secmembbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crdl_secmembbygroupidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secmembbygroupidx.plsql >>$logfilename 2>&1
echo "#	crdl_secmembbyuseridx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secmembbyuseridx.plsql >>$logfilename 2>&1
echo "#	crdl_secmembbyuuseridx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secmembbyuuseridx.plsql >>$logfilename 2>&1
echo "#	crdl_secsessbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secsessbyididx.plsql >>$logfilename 2>&1
echo "#	crdl_secsessbysecuseridx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secsessbysecuseridx.plsql >>$logfilename 2>&1
echo "#	crdl_secsessbysecdevidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secsessbysecdevidx.plsql >>$logfilename 2>&1
echo "#	crdl_secsessbystartidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secsessbystartidx.plsql >>$logfilename 2>&1
echo "#	crdl_secsessbyfinishidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secsessbyfinishidx.plsql >>$logfilename 2>&1
echo "#	crdl_secsessbysecproxyidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secsessbysecproxyidx.plsql >>$logfilename 2>&1
echo "#	crdl_secuserbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secuserbyididx.plsql >>$logfilename 2>&1
echo "#	crdl_secuserbyuloginidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secuserbyuloginidx.plsql >>$logfilename 2>&1
echo "#	crdl_secuserbyemconfidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secuserbyemconfidx.plsql >>$logfilename 2>&1
echo "#	crdl_secuserbypwdresetidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secuserbypwdresetidx.plsql >>$logfilename 2>&1
echo "#	crdl_secuserbydefdevidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secuserbydefdevidx.plsql >>$logfilename 2>&1
echo "#	crdl_hostsvcbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_hostsvcbyididx.plsql >>$logfilename 2>&1
echo "#	crdl_hostsvcbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_hostsvcbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crdl_hostsvcbyhostidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_hostsvcbyhostidx.plsql >>$logfilename 2>&1
echo "#	crdl_hostsvcbytypeidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_hostsvcbytypeidx.plsql >>$logfilename 2>&1
echo "#	crdl_hostsvcbyutypeidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_hostsvcbyutypeidx.plsql >>$logfilename 2>&1
echo "#	crdl_hostsvcbyuhostportidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_hostsvcbyuhostportidx.plsql >>$logfilename 2>&1
echo "#	crdl_svctypebyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_svctypebyididx.plsql >>$logfilename 2>&1
echo "#	crdl_svctypebyudescridx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_svctypebyudescridx.plsql >>$logfilename 2>&1
echo "#	crdl_sysclusbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_sysclusbyididx.plsql >>$logfilename 2>&1
echo "#	crdl_sysclusbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_sysclusbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crdl_tsecgrpbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tsecgrpbyididx.plsql >>$logfilename 2>&1
echo "#	crdl_tsecgrpbytenantidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tsecgrpbytenantidx.plsql >>$logfilename 2>&1
echo "#	crdl_tsecgrpbytenantvisidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tsecgrpbytenantvisidx.plsql >>$logfilename 2>&1
echo "#	crdl_tsecgrpbyunameidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tsecgrpbyunameidx.plsql >>$logfilename 2>&1
echo "#	crdl_tsecincbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tsecincbyididx.plsql >>$logfilename 2>&1
echo "#	crdl_tsecincbytenantidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tsecincbytenantidx.plsql >>$logfilename 2>&1
echo "#	crdl_tsecincbygroupidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tsecincbygroupidx.plsql >>$logfilename 2>&1
echo "#	crdl_tsecincbyincludeidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tsecincbyincludeidx.plsql >>$logfilename 2>&1
echo "#	crdl_tsecincbyuincludeidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tsecincbyuincludeidx.plsql >>$logfilename 2>&1
echo "#	crdl_tsecmembbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tsecmembbyididx.plsql >>$logfilename 2>&1
echo "#	crdl_tsecmembbytenantidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tsecmembbytenantidx.plsql >>$logfilename 2>&1
echo "#	crdl_tsecmembbygroupidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tsecmembbygroupidx.plsql >>$logfilename 2>&1
echo "#	crdl_tsecmembbyuseridx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tsecmembbyuseridx.plsql >>$logfilename 2>&1
echo "#	crdl_tsecmembbyuuseridx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tsecmembbyuuseridx.plsql >>$logfilename 2>&1
echo "#	crdl_tenantbyididx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tenantbyididx.plsql >>$logfilename 2>&1
echo "#	crdl_tenantbyclusteridx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tenantbyclusteridx.plsql >>$logfilename 2>&1
echo "#	crdl_tenantbyunameidx.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tenantbyunameidx.plsql >>$logfilename 2>&1

echo "#	crdl_clus.plsql" >>${logfilename}
${sqlpluscmd} < crdl_clus.plsql >>$logfilename 2>&1
echo "#	crdl_hostnode.plsql" >>${logfilename}
${sqlpluscmd} < crdl_hostnode.plsql >>$logfilename 2>&1
echo "#	crdl_iso_ccy.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_ccy.plsql >>$logfilename 2>&1
echo "#	crdl_iso_cntry.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_cntry.plsql >>$logfilename 2>&1
echo "#	crdl_iso_cntryccy.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_cntryccy.plsql >>$logfilename 2>&1
echo "#	crdl_iso_cntrylng.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_cntrylng.plsql >>$logfilename 2>&1
echo "#	crdl_iso_lang.plsql" >>${logfilename}
${sqlpluscmd} < crdl_iso_lang.plsql >>$logfilename 2>&1
echo "#	crdl_isotz.plsql" >>${logfilename}
${sqlpluscmd} < crdl_isotz.plsql >>$logfilename 2>&1
echo "#	crdl_secapp.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secapp.plsql >>$logfilename 2>&1
echo "#	crdl_secdev.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secdev.plsql >>$logfilename 2>&1
echo "#	crdl_secform.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secform.plsql >>$logfilename 2>&1
echo "#	crdl_secgrp.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secgrp.plsql >>$logfilename 2>&1
echo "#	crdl_secgrpfrm.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secgrpfrm.plsql >>$logfilename 2>&1
echo "#	crdl_secinc.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secinc.plsql >>$logfilename 2>&1
echo "#	crdl_secmemb.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secmemb.plsql >>$logfilename 2>&1
echo "#	crdl_secsess.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secsess.plsql >>$logfilename 2>&1
echo "#	crdl_secuser.plsql" >>${logfilename}
${sqlpluscmd} < crdl_secuser.plsql >>$logfilename 2>&1
echo "#	crdl_hostsvc.plsql" >>${logfilename}
${sqlpluscmd} < crdl_hostsvc.plsql >>$logfilename 2>&1
echo "#	crdl_svctype.plsql" >>${logfilename}
${sqlpluscmd} < crdl_svctype.plsql >>$logfilename 2>&1
echo "#	crdl_sysclus.plsql" >>${logfilename}
${sqlpluscmd} < crdl_sysclus.plsql >>$logfilename 2>&1
echo "#	crdl_tsecgrp.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tsecgrp.plsql >>$logfilename 2>&1
echo "#	crdl_tsecinc.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tsecinc.plsql >>$logfilename 2>&1
echo "#	crdl_tsecmemb.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tsecmemb.plsql >>$logfilename 2>&1
echo "#	crdl_tenant.plsql" >>${logfilename}
${sqlpluscmd} < crdl_tenant.plsql >>$logfilename 2>&1

