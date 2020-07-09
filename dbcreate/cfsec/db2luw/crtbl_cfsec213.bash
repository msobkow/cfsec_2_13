#!/bin/bash
#
#	@(#) dbcreate/cfsec/db2luw/crtbl_cfsec213.bash
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

echo "#	Running crtbl_cfsec213_idg16.sql..."
db2 -l db2output.log -f crtbl_cfsec213_idg16.sql
echo "#	Running crtbl_cfsec213_idg32.sql..."
db2 -l db2output.log -f crtbl_cfsec213_idg32.sql
echo "#	Running crtbl_cfsec213_idg64.sql..."
db2 -l db2output.log -f crtbl_cfsec213_idg64.sql
echo "#	Running crtbl_clus.sql..."
db2 -l db2output.log -f crtbl_clus.sql
echo "#	Running crtbl_clus_idg32.sql..."
db2 -l db2output.log -f crtbl_clus_idg32.sql
echo "#	Running crtbl_clus_idg64.sql..."
db2 -l db2output.log -f crtbl_clus_idg64.sql
echo "#	Running crtbl_secapp.sql..."
db2 -l db2output.log -f crtbl_secapp.sql
echo "#	Running crtbl_secform.sql..."
db2 -l db2output.log -f crtbl_secform.sql
echo "#	Running crtbl_secgrp.sql..."
db2 -l db2output.log -f crtbl_secgrp.sql
echo "#	Running crtbl_secgrpfrm.sql..."
db2 -l db2output.log -f crtbl_secgrpfrm.sql
echo "#	Running crtbl_secsess.sql..."
db2 -l db2output.log -f crtbl_secsess.sql
echo "#	Running crtbl_secuser.sql..."
db2 -l db2output.log -f crtbl_secuser.sql
echo "#	Running crtbl_tenant.sql..."
db2 -l db2output.log -f crtbl_tenant.sql
echo "#	Running crtbl_tenant_idg32.sql..."
db2 -l db2output.log -f crtbl_tenant_idg32.sql
echo "#	Running crtbl_tenant_idg64.sql..."
db2 -l db2output.log -f crtbl_tenant_idg64.sql
echo "#	Running crtbl_hostnode.sql..."
db2 -l db2output.log -f crtbl_hostnode.sql
echo "#	Running crtbl_iso_ccy.sql..."
db2 -l db2output.log -f crtbl_iso_ccy.sql
echo "#	Running crtbl_iso_cntry.sql..."
db2 -l db2output.log -f crtbl_iso_cntry.sql
echo "#	Running crtbl_iso_cntryccy.sql..."
db2 -l db2output.log -f crtbl_iso_cntryccy.sql
echo "#	Running crtbl_iso_cntrylng.sql..."
db2 -l db2output.log -f crtbl_iso_cntrylng.sql
echo "#	Running crtbl_iso_lang.sql..."
db2 -l db2output.log -f crtbl_iso_lang.sql
echo "#	Running crtbl_isotz.sql..."
db2 -l db2output.log -f crtbl_isotz.sql
echo "#	Running crtbl_secdev.sql..."
db2 -l db2output.log -f crtbl_secdev.sql
echo "#	Running crtbl_secinc.sql..."
db2 -l db2output.log -f crtbl_secinc.sql
echo "#	Running crtbl_secmemb.sql..."
db2 -l db2output.log -f crtbl_secmemb.sql
echo "#	Running crtbl_hostsvc.sql..."
db2 -l db2output.log -f crtbl_hostsvc.sql
echo "#	Running crtbl_svctype.sql..."
db2 -l db2output.log -f crtbl_svctype.sql
echo "#	Running crtbl_sysclus.sql..."
db2 -l db2output.log -f crtbl_sysclus.sql
echo "#	Running crtbl_tsecgrp.sql..."
db2 -l db2output.log -f crtbl_tsecgrp.sql
echo "#	Running crtbl_tsecinc.sql..."
db2 -l db2output.log -f crtbl_tsecinc.sql
echo "#	Running crtbl_tsecmemb.sql..."
db2 -l db2output.log -f crtbl_tsecmemb.sql
echo "#	Running crtbl_clus_h.sql..."
db2 -l db2output.log -f crtbl_clus_h.sql
echo "#	Running crtbl_hostnode_h.sql..."
db2 -l db2output.log -f crtbl_hostnode_h.sql
echo "#	Running crtbl_iso_ccy_h.sql..."
db2 -l db2output.log -f crtbl_iso_ccy_h.sql
echo "#	Running crtbl_iso_cntry_h.sql..."
db2 -l db2output.log -f crtbl_iso_cntry_h.sql
echo "#	Running crtbl_iso_cntryccy_h.sql..."
db2 -l db2output.log -f crtbl_iso_cntryccy_h.sql
echo "#	Running crtbl_iso_cntrylng_h.sql..."
db2 -l db2output.log -f crtbl_iso_cntrylng_h.sql
echo "#	Running crtbl_iso_lang_h.sql..."
db2 -l db2output.log -f crtbl_iso_lang_h.sql
echo "#	Running crtbl_isotz_h.sql..."
db2 -l db2output.log -f crtbl_isotz_h.sql
echo "#	Running crtbl_secapp_h.sql..."
db2 -l db2output.log -f crtbl_secapp_h.sql
echo "#	Running crtbl_secdev_h.sql..."
db2 -l db2output.log -f crtbl_secdev_h.sql
echo "#	Running crtbl_secform_h.sql..."
db2 -l db2output.log -f crtbl_secform_h.sql
echo "#	Running crtbl_secgrp_h.sql..."
db2 -l db2output.log -f crtbl_secgrp_h.sql
echo "#	Running crtbl_secgrpfrm_h.sql..."
db2 -l db2output.log -f crtbl_secgrpfrm_h.sql
echo "#	Running crtbl_secinc_h.sql..."
db2 -l db2output.log -f crtbl_secinc_h.sql
echo "#	Running crtbl_secmemb_h.sql..."
db2 -l db2output.log -f crtbl_secmemb_h.sql
echo "#	Running crtbl_secuser_h.sql..."
db2 -l db2output.log -f crtbl_secuser_h.sql
echo "#	Running crtbl_hostsvc_h.sql..."
db2 -l db2output.log -f crtbl_hostsvc_h.sql
echo "#	Running crtbl_svctype_h.sql..."
db2 -l db2output.log -f crtbl_svctype_h.sql
echo "#	Running crtbl_tsecgrp_h.sql..."
db2 -l db2output.log -f crtbl_tsecgrp_h.sql
echo "#	Running crtbl_tsecinc_h.sql..."
db2 -l db2output.log -f crtbl_tsecinc_h.sql
echo "#	Running crtbl_tsecmemb_h.sql..."
db2 -l db2output.log -f crtbl_tsecmemb_h.sql
echo "#	Running crtbl_tenant_h.sql..."
db2 -l db2output.log -f crtbl_tenant_h.sql

