#!/bin/bash
#
#	@(#) dbcreate/cfsec/pgsql/crschema_cfsec213.bash
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

echo "Dropping old schema cfsec213 for ${pguser}"
echo "Dropping old schema cfsec213 for ${pguser}" >>${logfilename}

psql -h ${pghost} ${PGPORT} -U ${pguser} -a -e -c "drop schema cfsec213" >>${logfilename} 2>&1

echo "Creating schema CFSec213 in database ${pgdb} for ${pguser}"
echo "Creating schema CFSec213 in database ${pgdb} for ${pguser}" >>${logfilename}

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -c "create schema cfsec213" >>${logfilename} 2>&1


#
#	Create the database tables
#
if [ -f ./crtbl_cfsec213.bash ]; then
	echo "	Creating database tables ..."
	echo "" >>${logfilename}
	echo "#" >>${logfilename}
	echo "#	Executing script crtbl_cfsec213.bash" >>${logfilename}
	echo "#" >>${logfilename}
	./crtbl_cfsec213.bash -H ${pghost} ${PASSPGPORT} -d ${pgdb} -U ${pguser} -P ${pgpwd} -L ${logfilename}
fi

#
#	Create the database indexes
#
if [ -f ./cridx_cfsec213.bash ]; then
	echo "	Creating database indexes ..."
	echo "#" >>${logfilename}
	echo "#	Executing script cridx_cfsec213.bash" >>${logfilename}
	echo "#" >>${logfilename}
	./cridx_cfsec213.bash -H ${pghost} ${PASSPGPORT} -d ${pgdb} -U ${pguser} -P ${pgpwd} -L ${logfilename}
fi

#
#	Create the database relations
#
if [ -f ./crrel_cfsec213.bash ]; then
	echo "	Creating database relations ..."
	echo "" >>${logfilename}
	echo "#" >>${logfilename}
	echo "#	Executing script crrel_cfsec213.bash" >>${logfilename}
	echo "#" >>${logfilename}
	./crrel_cfsec213.bash -H ${pghost} ${PASSPGPORT} -d ${pgdb} -U ${pguser} -P ${pgpwd} -L ${logfilename}
fi

#
#	Create the database sequences
#
if [ -f ./crseq_cfsec213.bash ]; then
	echo "	Creating database sequences..."
	echo "" >>${logfilename}
	echo "#" >>${logfilename}
	echo "#	Executing script crseq_cfsec213.bash" >>${logfilename}
	echo "#" >>${logfilename}
	./crseq_cfsec213.bash -H ${pghost} ${PASSPGPORT} -d ${pgdb} -U ${pguser} -P ${pgpwd} -L ${logfilename}
fi

#
#	Create the return record types for the stored procedures
#
if [ -f ./crtypes_cfsec213.bash ]; then
	echo "	Creating database types..."
	echo "" >>${logfilename}
	echo "#" >>${logfilename}
	echo "#	Executing script crtypes_cfsec213.bash" >>${logfilename}
	echo "#" >>${logfilename}
	./crtypes_cfsec213.bash -H ${pghost} ${PASSPGPORT} -d ${pgdb} -U ${pguser} -P ${pgpwd} -L ${logfilename}
fi

#
#	Create the stored procedures
#
if [ -f ./crprocs_cfsec213.bash ]; then
	echo "	Creating stored procedures..."
	echo "" >>${logfilename}
	echo "#" >>${logfilename}
	echo "#	Executing script crprocs_cfsec213.bash" >>${logfilename}
	echo "#" >>${logfilename}
	./crprocs_cfsec213.bash -H ${pghost} ${PASSPGPORT} -d ${pgdb} -U ${pguser} -P ${pgpwd} -L ${logfilename}
fi

#
#	Load initial data
#
if [ -f ./load_cfsec213.bash ]; then
	echo "	Loading initial data ..."
	echo "" >>${logfilename}
	echo "#" >>${logfilename}
	echo "#	Executing script load_cfsec213.bash" >>${logfilename}
	echo "#" >>${logfilename}
	./load_cfsec213.bash -H ${pghost} ${PASSPGPORT} -d ${pgdb} -U ${pguser} -P ${pgpwd} -L ${logfilename}
fi

#
#	Create the database triggers
#
if [ -f ./crtrg_cfsec213.bash ]; then
	echo "	Creating database triggers ..."
	echo "" >>${logfilename}
	echo "#" >>${logfilename}
	echo "#	Executing script crtrg_cfsec213.bash" >>${logfilename}
	echo "#" >>${logfilename}
	./crtrg_cfsec213.bash -H ${pghost} ${PASSPGPORT} -d ${pgdb} -U ${pguser} -P ${pgpwd} -L ${logfilename}
fi

exit 0

