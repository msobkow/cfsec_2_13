#!/bin/bash
#
#	@(#) dbcreate/cfsec/db2luw/crrel_cfsec213.bash
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

echo "#	Running crrel_clus.sql ..."
db2 -l db2output.log -f crrel_clus.sql
echo "#	Running crrel_hostnode.sql ..."
db2 -l db2output.log -f crrel_hostnode.sql
echo "#	Running crrel_iso_ccy.sql ..."
db2 -l db2output.log -f crrel_iso_ccy.sql
echo "#	Running crrel_iso_cntry.sql ..."
db2 -l db2output.log -f crrel_iso_cntry.sql
echo "#	Running crrel_iso_cntryccy.sql ..."
db2 -l db2output.log -f crrel_iso_cntryccy.sql
echo "#	Running crrel_iso_cntrylng.sql ..."
db2 -l db2output.log -f crrel_iso_cntrylng.sql
echo "#	Running crrel_iso_lang.sql ..."
db2 -l db2output.log -f crrel_iso_lang.sql
echo "#	Running crrel_isotz.sql ..."
db2 -l db2output.log -f crrel_isotz.sql
echo "#	Running crrel_secapp.sql ..."
db2 -l db2output.log -f crrel_secapp.sql
echo "#	Running crrel_secdev.sql ..."
db2 -l db2output.log -f crrel_secdev.sql
echo "#	Running crrel_secform.sql ..."
db2 -l db2output.log -f crrel_secform.sql
echo "#	Running crrel_secgrp.sql ..."
db2 -l db2output.log -f crrel_secgrp.sql
echo "#	Running crrel_secgrpfrm.sql ..."
db2 -l db2output.log -f crrel_secgrpfrm.sql
echo "#	Running crrel_secinc.sql ..."
db2 -l db2output.log -f crrel_secinc.sql
echo "#	Running crrel_secmemb.sql ..."
db2 -l db2output.log -f crrel_secmemb.sql
echo "#	Running crrel_secsess.sql ..."
db2 -l db2output.log -f crrel_secsess.sql
echo "#	Running crrel_secuser.sql ..."
db2 -l db2output.log -f crrel_secuser.sql
echo "#	Running crrel_hostsvc.sql ..."
db2 -l db2output.log -f crrel_hostsvc.sql
echo "#	Running crrel_svctype.sql ..."
db2 -l db2output.log -f crrel_svctype.sql
echo "#	Running crrel_sysclus.sql ..."
db2 -l db2output.log -f crrel_sysclus.sql
echo "#	Running crrel_tsecgrp.sql ..."
db2 -l db2output.log -f crrel_tsecgrp.sql
echo "#	Running crrel_tsecinc.sql ..."
db2 -l db2output.log -f crrel_tsecinc.sql
echo "#	Running crrel_tsecmemb.sql ..."
db2 -l db2output.log -f crrel_tsecmemb.sql
echo "#	Running crrel_tenant.sql ..."
db2 -l db2output.log -f crrel_tenant.sql

