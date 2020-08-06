#!/bin/bash
#
#	@(#) dbcreate/cfsec/mysql/crtbl_cfsec213.bash
#
#	org.msscf.msscf.CFSec
#
#	Copyright (c) 2020 Mark Stephen Sobkow
#	
#	MSS Code Factory CFSec 2.13 Security Essentials
#	
#	Copyright 2020 Mark Stephen Sobkow
#	
#		This file is part of MSS Code Factory.
#	
#		MSS Code Factory is available under dual commercial license from Mark Stephen
#		Sobkow, or under the terms of the GNU General Public License, Version 3
#		or later.
#	
#	    MSS Code Factory is free software: you can redistribute it and/or modify
#	    it under the terms of the GNU General Public License as published by
#	    the Free Software Foundation, either version 3 of the License, or
#	    (at your option) any later version.
#	
#	    MSS Code Factory is distributed in the hope that it will be useful,
#	    but WITHOUT ANY WARRANTY; without even the implied warranty of
#	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#	    GNU General Public License for more details.
#	
#	    You should have received a copy of the GNU General Public License
#	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
#	
#	Donations to support MSS Code Factory can be made at
#	https://www.paypal.com/paypalme2/MarkSobkow
#	
#	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
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

echo "crtbl_cfsec213_idg16.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_cfsec213_idg16.mysql >>$logfilename 2>&1
echo "crtbl_cfsec213_idg32.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_cfsec213_idg32.mysql >>$logfilename 2>&1
echo "crtbl_cfsec213_idg64.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_cfsec213_idg64.mysql >>$logfilename 2>&1
echo "crtbl_clus.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_clus.mysql >>$logfilename 2>&1
echo "crtbl_clus_idg32.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_clus_idg32.mysql >>$logfilename 2>&1
echo "crtbl_clus_idg64.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_clus_idg64.mysql >>$logfilename 2>&1
echo "crtbl_secapp.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_secapp.mysql >>$logfilename 2>&1
echo "crtbl_secform.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_secform.mysql >>$logfilename 2>&1
echo "crtbl_secgrp.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_secgrp.mysql >>$logfilename 2>&1
echo "crtbl_secgrpfrm.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_secgrpfrm.mysql >>$logfilename 2>&1
echo "crtbl_secsess.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_secsess.mysql >>$logfilename 2>&1
echo "crtbl_secuser.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_secuser.mysql >>$logfilename 2>&1
echo "crtbl_tenant.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_tenant.mysql >>$logfilename 2>&1
echo "crtbl_tenant_idg32.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_tenant_idg32.mysql >>$logfilename 2>&1
echo "crtbl_tenant_idg64.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_tenant_idg64.mysql >>$logfilename 2>&1
echo "crtbl_hostnode.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_hostnode.mysql >>$logfilename 2>&1
echo "crtbl_iso_ccy.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_iso_ccy.mysql >>$logfilename 2>&1
echo "crtbl_iso_cntry.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_iso_cntry.mysql >>$logfilename 2>&1
echo "crtbl_iso_cntryccy.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_iso_cntryccy.mysql >>$logfilename 2>&1
echo "crtbl_iso_cntrylng.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_iso_cntrylng.mysql >>$logfilename 2>&1
echo "crtbl_iso_lang.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_iso_lang.mysql >>$logfilename 2>&1
echo "crtbl_isotz.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_isotz.mysql >>$logfilename 2>&1
echo "crtbl_secdev.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_secdev.mysql >>$logfilename 2>&1
echo "crtbl_secinc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_secinc.mysql >>$logfilename 2>&1
echo "crtbl_secmemb.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_secmemb.mysql >>$logfilename 2>&1
echo "crtbl_hostsvc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_hostsvc.mysql >>$logfilename 2>&1
echo "crtbl_svctype.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_svctype.mysql >>$logfilename 2>&1
echo "crtbl_sysclus.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_sysclus.mysql >>$logfilename 2>&1
echo "crtbl_tsecgrp.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_tsecgrp.mysql >>$logfilename 2>&1
echo "crtbl_tsecinc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_tsecinc.mysql >>$logfilename 2>&1
echo "crtbl_tsecmemb.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_tsecmemb.mysql >>$logfilename 2>&1
echo "crtbl_clus_h.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_clus_h.mysql >>$logfilename 2>&1
echo "crtbl_hostnode_h.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_hostnode_h.mysql >>$logfilename 2>&1
echo "crtbl_iso_ccy_h.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_iso_ccy_h.mysql >>$logfilename 2>&1
echo "crtbl_iso_cntry_h.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_iso_cntry_h.mysql >>$logfilename 2>&1
echo "crtbl_iso_cntryccy_h.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_iso_cntryccy_h.mysql >>$logfilename 2>&1
echo "crtbl_iso_cntrylng_h.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_iso_cntrylng_h.mysql >>$logfilename 2>&1
echo "crtbl_iso_lang_h.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_iso_lang_h.mysql >>$logfilename 2>&1
echo "crtbl_isotz_h.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_isotz_h.mysql >>$logfilename 2>&1
echo "crtbl_secapp_h.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_secapp_h.mysql >>$logfilename 2>&1
echo "crtbl_secdev_h.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_secdev_h.mysql >>$logfilename 2>&1
echo "crtbl_secform_h.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_secform_h.mysql >>$logfilename 2>&1
echo "crtbl_secgrp_h.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_secgrp_h.mysql >>$logfilename 2>&1
echo "crtbl_secgrpfrm_h.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_secgrpfrm_h.mysql >>$logfilename 2>&1
echo "crtbl_secinc_h.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_secinc_h.mysql >>$logfilename 2>&1
echo "crtbl_secmemb_h.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_secmemb_h.mysql >>$logfilename 2>&1
echo "crtbl_secuser_h.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_secuser_h.mysql >>$logfilename 2>&1
echo "crtbl_hostsvc_h.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_hostsvc_h.mysql >>$logfilename 2>&1
echo "crtbl_svctype_h.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_svctype_h.mysql >>$logfilename 2>&1
echo "crtbl_tsecgrp_h.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_tsecgrp_h.mysql >>$logfilename 2>&1
echo "crtbl_tsecinc_h.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_tsecinc_h.mysql >>$logfilename 2>&1
echo "crtbl_tsecmemb_h.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_tsecmemb_h.mysql >>$logfilename 2>&1
echo "crtbl_tenant_h.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crtbl_tenant_h.mysql >>$logfilename 2>&1
