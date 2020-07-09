#!/bin/bash
#
#	@(#) dbcreate/cfsec/db2luw/cridx_cfsec213_h.bash
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
echo "#	cridx_clus_h_udomnameidx.sql ..."
db2 -l db2output.log -f cridx_clus_h_udomnameidx.sql
echo "#	cridx_clus_h_udescridx.sql ..."
db2 -l db2output.log -f cridx_clus_h_udescridx.sql
echo "#	cridx_hostnode_h_clusteridx.sql ..."
db2 -l db2output.log -f cridx_hostnode_h_clusteridx.sql
echo "#	cridx_hostnode_h_udescridx.sql ..."
db2 -l db2output.log -f cridx_hostnode_h_udescridx.sql
echo "#	cridx_hostnode_h_hostnameidx.sql ..."
db2 -l db2output.log -f cridx_hostnode_h_hostnameidx.sql
echo "#	cridx_iso_ccy_h_ccycdidx.sql ..."
db2 -l db2output.log -f cridx_iso_ccy_h_ccycdidx.sql
echo "#	cridx_iso_ccy_h_ccynmidx.sql ..."
db2 -l db2output.log -f cridx_iso_ccy_h_ccynmidx.sql
echo "#	cridx_iso_cntry_h_isocodeidx.sql ..."
db2 -l db2output.log -f cridx_iso_cntry_h_isocodeidx.sql
echo "#	cridx_iso_cntry_h_nameidx.sql ..."
db2 -l db2output.log -f cridx_iso_cntry_h_nameidx.sql
echo "#	cridx_iso_cntryccy_h_ctryidx.sql ..."
db2 -l db2output.log -f cridx_iso_cntryccy_h_ctryidx.sql
echo "#	cridx_iso_cntryccy_h_ccyidx.sql ..."
db2 -l db2output.log -f cridx_iso_cntryccy_h_ccyidx.sql
echo "#	cridx_iso_cntrylng_h_ctryidx.sql ..."
db2 -l db2output.log -f cridx_iso_cntrylng_h_ctryidx.sql
echo "#	cridx_iso_cntrylng_h_langidx.sql ..."
db2 -l db2output.log -f cridx_iso_cntrylng_h_langidx.sql
echo "#	cridx_iso_lang_h_code3idx.sql ..."
db2 -l db2output.log -f cridx_iso_lang_h_code3idx.sql
echo "#	cridx_iso_lang_h_code2idx.sql ..."
db2 -l db2output.log -f cridx_iso_lang_h_code2idx.sql
echo "#	cridx_isotz_h_offsetidx.sql ..."
db2 -l db2output.log -f cridx_isotz_h_offsetidx.sql
echo "#	cridx_isotz_h_utznameidx.sql ..."
db2 -l db2output.log -f cridx_isotz_h_utznameidx.sql
echo "#	cridx_isotz_h_iso8601idx.sql ..."
db2 -l db2output.log -f cridx_isotz_h_iso8601idx.sql
echo "#	cridx_secapp_h_clusteridx.sql ..."
db2 -l db2output.log -f cridx_secapp_h_clusteridx.sql
echo "#	cridx_secapp_h_ujeemountidx.sql ..."
db2 -l db2output.log -f cridx_secapp_h_ujeemountidx.sql
echo "#	cridx_secdev_h_nameidx.sql ..."
db2 -l db2output.log -f cridx_secdev_h_nameidx.sql
echo "#	cridx_secdev_h_useridx.sql ..."
db2 -l db2output.log -f cridx_secdev_h_useridx.sql
echo "#	cridx_secform_h_clusteridx.sql ..."
db2 -l db2output.log -f cridx_secform_h_clusteridx.sql
echo "#	cridx_secform_h_secappidx.sql ..."
db2 -l db2output.log -f cridx_secform_h_secappidx.sql
echo "#	cridx_secform_h_ujeeservletidx.sql ..."
db2 -l db2output.log -f cridx_secform_h_ujeeservletidx.sql
echo "#	cridx_secgrp_h_clusteridx.sql ..."
db2 -l db2output.log -f cridx_secgrp_h_clusteridx.sql
echo "#	cridx_secgrp_h_clustervisidx.sql ..."
db2 -l db2output.log -f cridx_secgrp_h_clustervisidx.sql
echo "#	cridx_secgrp_h_unameidx.sql ..."
db2 -l db2output.log -f cridx_secgrp_h_unameidx.sql
echo "#	cridx_secgrpfrm_h_clusteridx.sql ..."
db2 -l db2output.log -f cridx_secgrpfrm_h_clusteridx.sql
echo "#	cridx_secgrpfrm_h_groupidx.sql ..."
db2 -l db2output.log -f cridx_secgrpfrm_h_groupidx.sql
echo "#	cridx_secgrpfrm_h_appidx.sql ..."
db2 -l db2output.log -f cridx_secgrpfrm_h_appidx.sql
echo "#	cridx_secgrpfrm_h_formidx.sql ..."
db2 -l db2output.log -f cridx_secgrpfrm_h_formidx.sql
echo "#	cridx_secgrpfrm_h_uformidx.sql ..."
db2 -l db2output.log -f cridx_secgrpfrm_h_uformidx.sql
echo "#	cridx_secinc_h_clusteridx.sql ..."
db2 -l db2output.log -f cridx_secinc_h_clusteridx.sql
echo "#	cridx_secinc_h_groupidx.sql ..."
db2 -l db2output.log -f cridx_secinc_h_groupidx.sql
echo "#	cridx_secinc_h_includeidx.sql ..."
db2 -l db2output.log -f cridx_secinc_h_includeidx.sql
echo "#	cridx_secinc_h_uincludeidx.sql ..."
db2 -l db2output.log -f cridx_secinc_h_uincludeidx.sql
echo "#	cridx_secmemb_h_clusteridx.sql ..."
db2 -l db2output.log -f cridx_secmemb_h_clusteridx.sql
echo "#	cridx_secmemb_h_groupidx.sql ..."
db2 -l db2output.log -f cridx_secmemb_h_groupidx.sql
echo "#	cridx_secmemb_h_useridx.sql ..."
db2 -l db2output.log -f cridx_secmemb_h_useridx.sql
echo "#	cridx_secmemb_h_uuseridx.sql ..."
db2 -l db2output.log -f cridx_secmemb_h_uuseridx.sql
echo "#	cridx_secuser_h_uloginidx.sql ..."
db2 -l db2output.log -f cridx_secuser_h_uloginidx.sql
echo "#	cridx_secuser_h_emconfidx.sql ..."
db2 -l db2output.log -f cridx_secuser_h_emconfidx.sql
echo "#	cridx_secuser_h_pwdresetidx.sql ..."
db2 -l db2output.log -f cridx_secuser_h_pwdresetidx.sql
echo "#	cridx_secuser_h_defdevidx.sql ..."
db2 -l db2output.log -f cridx_secuser_h_defdevidx.sql
echo "#	cridx_hostsvc_h_clusteridx.sql ..."
db2 -l db2output.log -f cridx_hostsvc_h_clusteridx.sql
echo "#	cridx_hostsvc_h_hostidx.sql ..."
db2 -l db2output.log -f cridx_hostsvc_h_hostidx.sql
echo "#	cridx_hostsvc_h_typeidx.sql ..."
db2 -l db2output.log -f cridx_hostsvc_h_typeidx.sql
echo "#	cridx_hostsvc_h_utypeidx.sql ..."
db2 -l db2output.log -f cridx_hostsvc_h_utypeidx.sql
echo "#	cridx_hostsvc_h_uhostportidx.sql ..."
db2 -l db2output.log -f cridx_hostsvc_h_uhostportidx.sql
echo "#	cridx_svctype_h_udescridx.sql ..."
db2 -l db2output.log -f cridx_svctype_h_udescridx.sql
echo "#	cridx_tsecgrp_h_tenantidx.sql ..."
db2 -l db2output.log -f cridx_tsecgrp_h_tenantidx.sql
echo "#	cridx_tsecgrp_h_tenantvisidx.sql ..."
db2 -l db2output.log -f cridx_tsecgrp_h_tenantvisidx.sql
echo "#	cridx_tsecgrp_h_unameidx.sql ..."
db2 -l db2output.log -f cridx_tsecgrp_h_unameidx.sql
echo "#	cridx_tsecinc_h_tenantidx.sql ..."
db2 -l db2output.log -f cridx_tsecinc_h_tenantidx.sql
echo "#	cridx_tsecinc_h_groupidx.sql ..."
db2 -l db2output.log -f cridx_tsecinc_h_groupidx.sql
echo "#	cridx_tsecinc_h_includeidx.sql ..."
db2 -l db2output.log -f cridx_tsecinc_h_includeidx.sql
echo "#	cridx_tsecinc_h_uincludeidx.sql ..."
db2 -l db2output.log -f cridx_tsecinc_h_uincludeidx.sql
echo "#	cridx_tsecmemb_h_tenantidx.sql ..."
db2 -l db2output.log -f cridx_tsecmemb_h_tenantidx.sql
echo "#	cridx_tsecmemb_h_groupidx.sql ..."
db2 -l db2output.log -f cridx_tsecmemb_h_groupidx.sql
echo "#	cridx_tsecmemb_h_useridx.sql ..."
db2 -l db2output.log -f cridx_tsecmemb_h_useridx.sql
echo "#	cridx_tsecmemb_h_uuseridx.sql ..."
db2 -l db2output.log -f cridx_tsecmemb_h_uuseridx.sql
echo "#	cridx_tenant_h_clusteridx.sql ..."
db2 -l db2output.log -f cridx_tenant_h_clusteridx.sql
echo "#	cridx_tenant_h_unameidx.sql ..."
db2 -l db2output.log -f cridx_tenant_h_unameidx.sql

