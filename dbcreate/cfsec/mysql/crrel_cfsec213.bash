#!/bin/bash
#
#	@(#) dbcreate/cfsec/mysql/crrel_cfsec213.bash
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

echo "crrel_clus.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_clus.mysql >>$logfilename 2>&1
echo "crrel_clus_idg32.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_clus_idg32.mysql >>$logfilename 2>&1
echo "crrel_clus_idg64.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_clus_idg64.mysql >>$logfilename 2>&1
echo "crrel_hostnode.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_hostnode.mysql >>$logfilename 2>&1
echo "crrel_iso_ccy.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_iso_ccy.mysql >>$logfilename 2>&1
echo "crrel_iso_cntry.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_iso_cntry.mysql >>$logfilename 2>&1
echo "crrel_iso_cntryccy.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_iso_cntryccy.mysql >>$logfilename 2>&1
echo "crrel_iso_cntrylng.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_iso_cntrylng.mysql >>$logfilename 2>&1
echo "crrel_iso_lang.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_iso_lang.mysql >>$logfilename 2>&1
echo "crrel_isotz.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_isotz.mysql >>$logfilename 2>&1
echo "crrel_secapp.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_secapp.mysql >>$logfilename 2>&1
echo "crrel_secdev.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_secdev.mysql >>$logfilename 2>&1
echo "crrel_secform.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_secform.mysql >>$logfilename 2>&1
echo "crrel_secgrp.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_secgrp.mysql >>$logfilename 2>&1
echo "crrel_secgrpfrm.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_secgrpfrm.mysql >>$logfilename 2>&1
echo "crrel_secinc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_secinc.mysql >>$logfilename 2>&1
echo "crrel_secmemb.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_secmemb.mysql >>$logfilename 2>&1
echo "crrel_secsess.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_secsess.mysql >>$logfilename 2>&1
echo "crrel_secuser.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_secuser.mysql >>$logfilename 2>&1
echo "crrel_hostsvc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_hostsvc.mysql >>$logfilename 2>&1
echo "crrel_svctype.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_svctype.mysql >>$logfilename 2>&1
echo "crrel_sysclus.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_sysclus.mysql >>$logfilename 2>&1
echo "crrel_tsecgrp.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_tsecgrp.mysql >>$logfilename 2>&1
echo "crrel_tsecinc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_tsecinc.mysql >>$logfilename 2>&1
echo "crrel_tsecmemb.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_tsecmemb.mysql >>$logfilename 2>&1
echo "crrel_tenant.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_tenant.mysql >>$logfilename 2>&1
echo "crrel_tenant_idg32.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_tenant_idg32.mysql >>$logfilename 2>&1
echo "crrel_tenant_idg64.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crrel_tenant_idg64.mysql >>$logfilename 2>&1

