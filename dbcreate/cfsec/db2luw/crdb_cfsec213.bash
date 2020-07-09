#!/bin/bash
#
#	@(#) dbcreate/cfsec/db2luw/crdb_cfsec213.bash
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
#	You must be logged in with full DBA authority
#	before sourcing this script.
#

echo "#"
echo "#	Running crtbl_cfsec213.bash..."
echo "#"
. crtbl_cfsec213.bash
echo "#"
echo "#	Running cridx_cfsec213.bash..."
echo "#"
. cridx_cfsec213.bash
echo "#"
echo "#	Running crrel_cfsec213.bash..."
echo "#"
. crrel_cfsec213.bash
echo "#"
echo "#	Running crprocs_cfsec213.bash..."
echo "#"
. crprocs_cfsec213.bash
