#!/bin/bash
#
#	@(#) dbcreate/cfsec/pgsql/cridx_cfsec213_h.bash
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
pgdb=""
pghost=""
pgport=""
pgpwd=""
pgsrv=""
pguser=""
logfilename=""
parmerrors=""
TK_DUALCASE_IN_CASE_STATEMENTS=true

#
#	Parse the command line options
#
while [ -n "$1" ]
do
	case "$1" in

		-d)
			shift
			pgdb=$1
			shift
			;;

		-L)
			shift
			logfilename=$1
			shift
			;;

		-H)
			shift
			pghost=$1
			shift
			;;

		-p)
			shift
			pgport=$1
			shift
			;;

		-P)
			shift
			pgpwd=$1
			shift
			;;

		-S)
			shift
			pgsrv=$1
			shift
			;;

		-U)
			shift
			pguser=$1
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

if [ "${pguser}" = "" ]; then
	echo >&2 "ERROR: User must be specified with '-U username'"
	parmerrors="Y"
fi

if [ "${pgpwd}" = "" ]; then
	echo >&2 "ERROR: Password must be specified with '-P password'"
	parmerrors="Y"
fi

if [ "${pghost}" = "" ]; then
	echo >&2 "ERROR: Server host name must be specified with '-H hostname'"
	parmerrors="Y"
fi

if [ "${pgdb}" = "" ]; then
	echo >&2 "ERROR: Database name must be specified with '-d dbname'"
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

export PGPASSWORD="${pgpwd}"

if [ "${pgport}" != "" ]; then
	export PGPORT="--port=${pgport} "
	export PASSPGPORT="-p ${pgport} "
else
	export PGPORT=""
	export PASSPGPORT=""
fi

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_clus_h_udomnameidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_clus_h_udescridx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_hostnode_h_clusteridx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_hostnode_h_udescridx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_hostnode_h_hostnameidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_iso_ccy_h_ccycdidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_iso_ccy_h_ccynmidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_iso_cntry_h_isocodeidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_iso_cntry_h_nameidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_iso_cntryccy_h_ctryidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_iso_cntryccy_h_ccyidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_iso_cntrylng_h_ctryidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_iso_cntrylng_h_langidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_iso_lang_h_code3idx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_iso_lang_h_code2idx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_isotz_h_offsetidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_isotz_h_utznameidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_isotz_h_iso8601idx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secapp_h_clusteridx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secapp_h_ujeemountidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secdev_h_nameidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secdev_h_useridx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secform_h_clusteridx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secform_h_secappidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secform_h_ujeeservletidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secgrp_h_clusteridx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secgrp_h_clustervisidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secgrp_h_unameidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secgrpfrm_h_clusteridx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secgrpfrm_h_groupidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secgrpfrm_h_appidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secgrpfrm_h_formidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secgrpfrm_h_uformidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secinc_h_clusteridx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secinc_h_groupidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secinc_h_includeidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secinc_h_uincludeidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secmemb_h_clusteridx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secmemb_h_groupidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secmemb_h_useridx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secmemb_h_uuseridx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secuser_h_uloginidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secuser_h_emconfidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secuser_h_pwdresetidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secuser_h_defdevidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_hostsvc_h_clusteridx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_hostsvc_h_hostidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_hostsvc_h_typeidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_hostsvc_h_utypeidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_hostsvc_h_uhostportidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_svctype_h_udescridx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tsecgrp_h_tenantidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tsecgrp_h_tenantvisidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tsecgrp_h_unameidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tsecinc_h_tenantidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tsecinc_h_groupidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tsecinc_h_includeidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tsecinc_h_uincludeidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tsecmemb_h_tenantidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tsecmemb_h_groupidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tsecmemb_h_useridx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tsecmemb_h_uuseridx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tenant_h_clusteridx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tenant_h_unameidx.pgsql >>${logfilename} 2>&1

