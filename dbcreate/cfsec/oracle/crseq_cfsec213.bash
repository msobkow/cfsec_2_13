#!/bin/bash
#
#	@(#) dbcreate/cfsec/oracle/crseq_cfsec213.bash
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

echo "# crseq_isoccyidgenseq.plsql" >>${logfilename}
${sqlpluscmd} <crseq_isoccyidgenseq.plsql >>${logfilename} 2>&1
echo "# crseq_isoctryidgenseq.plsql" >>${logfilename}
${sqlpluscmd} <crseq_isoctryidgenseq.plsql >>${logfilename} 2>&1
echo "# crseq_isolangidgenseq.plsql" >>${logfilename}
${sqlpluscmd} <crseq_isolangidgenseq.plsql >>${logfilename} 2>&1
echo "# crseq_isotzoneidgenseq.plsql" >>${logfilename}
${sqlpluscmd} <crseq_isotzoneidgenseq.plsql >>${logfilename} 2>&1
echo "# crseq_servicetypeidgenseq.plsql" >>${logfilename}
${sqlpluscmd} <crseq_servicetypeidgenseq.plsql >>${logfilename} 2>&1
echo "# crseq_clusteridgenseq.plsql" >>${logfilename}
${sqlpluscmd} <crseq_clusteridgenseq.plsql >>${logfilename} 2>&1
echo "# crseq_tenantidgenseq.plsql" >>${logfilename}
${sqlpluscmd} <crseq_tenantidgenseq.plsql >>${logfilename} 2>&1

