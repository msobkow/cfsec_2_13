#!/bin/bash
#
#	@(#) dbcreate/cfsec/pgsql/crdb_cfsec213.bash
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
pgdatadir=""
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

		-D)
			shift
			pgdatadir=$1
			shift
			;;

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
	echo >&2 "WARNING: Postgres DBA login not specified with '-U username', using default 'postgres'"
fi

if [ "${pgpwd}" = "" ]; then
	echo >&2 "ERROR: Password must be specified with '-P password'"
	parmerrors="Y"
fi

if [ "${pghost}" = "" ]; then
	echo >&2 "ERROR: Server hostname must be specified with '-H hostname'"
	parmerrors="Y"
fi

if [ "${pgdatadir}" = "" ]; then
	echo >&2 "WARNING: Database data directory was not specified with '-D directory', tablespaces will not be created"
fi

if [ "$parmerrors" != "" ]; then
	echo >&2 "ABORT: Cannot continue"
	exit 1
fi

if [ "${logfilename}" = "" ]; then
	logfilename=`date +'crdb_cfsec213-%Y%m%d_%Hh%M.log'`
	echo "" >${logfilename}
fi

export PGPASSWORD="${pgpwd}"

if [ "${pgport}" != "" ]; then
	export PGPORT="--port=${pgport} "
	export PASSPGPORT="-p ${pgport} "
else
	export PGPORT=""
	export PASSPGPORT=""
fi


#
#	Create the tablespaces
#

if [ "${pgdatadir}" != "" ]; then

	need_dirs="N"

	if [ ! -d ${pgdatadir} ]; then
		need_dirs="Y"
	fi

	if [ ! -d ${pgdatadir}/cfsec213_data1 ]; then
		need_dirs="Y"
	fi

	if [ ! -d ${pgdatadir}/cfsec213_idx1 ]; then
		need_dirs="Y"
	fi

	if [ "${need_dirs}" = "Y" ]; then
		echo "Creating tablespace directories" | tee -a ${logfilename}

		if [ "${OS}" != "Windows_NT" ]; then
			su ${pguser} --command="mkdir ${pgdatadir} ${pgdatadir}/cfsec213_data1 ${pgdatadir}/cfsec213_idx1"
		else
			runas /user:${COMPUTERNAME}\\${pguser} "mkdir ${pgdatadir} ${pgdatadir}/cfsec213_data1 ${pgdatadir}/cfsec213_idx1"
		fi
	fi

	echo "" | tee -a ${logfilename}
	echo "Creating tablespaces cfsec213_data1 and cfsec213_idx1" | tee -a ${logfilename}
	psql -h ${pghost} ${PGPORT} -d template1 -U ${pguser} -a -e -c "create tablespace cfsec213_data1 location '${pgdatadir}/cfsec213_data1'" >>${logfilename} 2>&1

	psql -h ${pghost} ${PGPORT} -d template1 -U ${pguser} -a -e -c "create tablespace cfsec213_idx1 location '${pgdatadir}/cfsec213_idx1'" >>${logfilename} 2>&1

fi


#
#	Recreate the database instance
#
echo "Recreating database cfsec213 ..." | tee -a ${logfilename}

echo "" >>${logfilename}
echo "#" >>${logfilename}
echo "#	Drop database cfsec213" >>${logfilename}
echo "#" >>${logfilename}

psql -h ${pghost} ${PGPORT} -d template1 -U ${pguser} -a -e -c "drop database cfsec213" >>${logfilename} 2>&1

echo "" >>${logfilename}
echo "#" >>${logfilename}
echo "#	Create database cfsec213" >>${logfilename}
echo "#" >>${logfilename}

psql -h ${pghost} ${PGPORT} -d template1 -U ${pguser} -a -e -c "create database cfsec213 tablespace cfsec213_data1" >>${logfilename} 2>&1

./crschema_cfsec213.bash -H ${pghost} ${PASSPGPORT} -d cfsec213 -U ${pguser} -P ${pgpwd} -L ${logfilename}
