#!/bin/bash
#
#	@(#) dbcreate/cfsec/pgsql/cridx_cfsec213.bash
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

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_cluster_xufdname.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_cluster_xudescr.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_hostnode_xcluster.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_hostnode_xudsc.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_hostnode_xhnm.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_isocurrency_xcode.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_isocurrency_xuname.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_isocountry_xcode.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_isocountry_xuname.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_isocountryccy_xcountry.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_isocountryccy_xccy.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_isocountrylang_xcountry.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_isocountrylang_xlang.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_isolang_x6392.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_isolang_x6391.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_itz_xoffset.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_itz_xuname.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_itz_xiso.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secapp_xcluster.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secapp_xujeemnt.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secdev_nameidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secdev_usridx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secform_xcluster.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secform_xsecapp.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secform_xujeesvlt.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secgroup_xcluster.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secgroup_xclustervis.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secgroup_xuname.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secgroupform_xcluster.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secgroupform_xgroup.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secgroupform_xapp.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secgroupform_xform.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secgroupform_xuform.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secinclude_xcluster.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secinclude_xgroup.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secinclude_xinc.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secinclude_xuinc.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secmember_xcluster.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secmember_xgroup.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secmember_xuser.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secmember_xuuser.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_session_xsecuser.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_session_xsecdev.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_session_xstart.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_session_xfnsh.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_session_xproxy.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secuser_xulogin.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secuser_xemconf.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secuser_xpwdrst.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_secuser_defdevidx.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_service_xcluster.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_service_xhost.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_service_xtype.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_service_xutype.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_service_xuhpt.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_servicetype_xudsc.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_sysclus_xclus.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tsecgroup_xtenant.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tsecgroup_xtenantvis.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tsecgroup_xuname.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tsecinclude_xtenant.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tsecinclude_xgroup.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tsecinclude_xinc.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tsecinclude_xuinc.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tsecmember_xtenant.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tsecmember_xgroup.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tsecmember_xuser.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tsecmember_xuuser.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tenant_xcluster.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f cridx_tenant_xuname.pgsql >>${logfilename} 2>&1

