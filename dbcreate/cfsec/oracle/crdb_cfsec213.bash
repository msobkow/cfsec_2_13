#!/bin/bash
#
#	@(#) dbcreate/cfsec/oracle/crdb_cfsec213.bash
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
oradatadir=""
orapwd=""
oraservice=""
orahost=""
oraport=""
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

		-D)
			shift
			oradatadir=$1
			shift
			;;

		-H)
			shift
			orahost=$1
			shift
			;;

		-L)
			shift
			logfilename=$1
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


#
#	Create the tablespaces
#

if [ "${oradatadir}" != "" ]; then

	need_dirs="N"

	if [ ! -d ${oradatadir} ]; then
		need_dirs="Y"
	fi

	if [ "${need_dirs}" = "Y" ]; then
		echo "Creating tablespace directories" | tee -a ${logfilename}

		mkdir ${oradatadir}
	fi

	echo "" | tee -a ${logfilename}
	echo "Creating tablespaces cfsec213_data1 and cfsec213_idx1" | tee -a ${logfilename}
	echo "create tablespace cfsec213_data1 datafile '${oradatadir}/cfsec213_data1' size 1G autoextend off;" | ${sqlpluscmd} >>${logfilename} 2>&1

	echo "create tablespace cfsec213_idx1 datafile '${oradatadir}/cfsec213_idx1' size 1G autoextend off;" | ${sqlpluscmd} >>${logfilename} 2>&1

fi


#
#	Create the database user
#
echo "Creating user cfsec213 ..." | tee -a ${logfilename}

echo "" >>${logfilename}
echo "#" >>${logfilename}
echo "#	Create user cfsec213" >>${logfilename}
echo "#" >>${logfilename}

echo "create user cfsec213 identified by ${orapwd};" | ${sqlpluscmd} >>${logfilename} 2>&1
echo "alter user cfsec213 quota unlimited on cfsec213_data1;" | ${sqlpluscmd} >>${logfilename} 2>&1
echo "alter user cfsec213 quota unlimited on cfsec213_idx1;" | ${sqlpluscmd} >>${logfilename} 2>&1


#
#	Create the database instance
#
echo "Creating database cfsec213 ..." | tee -a ${logfilename}

echo "" >>${logfilename}
echo "#" >>${logfilename}
echo "#	Create database cfsec213" >>${logfilename}
echo "#" >>${logfilename}

echo "create database cfsec213 tablespace cfsec213_data1;" | ${sqlpluscmd} >>${logfilename} 2>&1

if [ "${orahost}" == "" ]; then
	./crschema_cfsec213.bash -U ${orauser} -P ${orapwd} -L ${logfilename}
else
	./crschema_cfsec213.bash -H ${orahost} -U ${orauser} -P ${orapwd} -L ${logfilename}
fi

