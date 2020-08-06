#!/bin/bash
#
#	@(#) dbcreate/cfsec/db2luw/crrel_cfsec213.bash
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

