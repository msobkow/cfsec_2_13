#!/bin/bash
#
#	@(#) dbcreate/cfsec/db2luw/crprocs_cfsec213.bash
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
echo "#	Running crsp_is_system_user.sql ..."
db2 -l db2output.log -f crsp_is_system_user.sql
echo "#	Running crsp_is_cluster_user.sql ..."
db2 -l db2output.log -f crsp_is_cluster_user.sql
echo "#	Running crsp_is_tenant_user.sql ..."
db2 -l db2output.log -f crsp_is_tenant_user.sql
echo "#	Running crsp_next_isoccyidgen.sql ..."
db2 -l db2output.log -f crsp_next_isoccyidgen.sql

echo "#	Running crsf_next_isoccyidgen.sql ..."
db2 -l db2output.log -f crsf_next_isoccyidgen.sql
echo "#	Running crsp_next_isoctryidgen.sql ..."
db2 -l db2output.log -f crsp_next_isoctryidgen.sql

echo "#	Running crsf_next_isoctryidgen.sql ..."
db2 -l db2output.log -f crsf_next_isoctryidgen.sql
echo "#	Running crsp_next_isolangidgen.sql ..."
db2 -l db2output.log -f crsp_next_isolangidgen.sql

echo "#	Running crsf_next_isolangidgen.sql ..."
db2 -l db2output.log -f crsf_next_isolangidgen.sql
echo "#	Running crsp_next_isotzoneidgen.sql ..."
db2 -l db2output.log -f crsp_next_isotzoneidgen.sql

echo "#	Running crsf_next_isotzoneidgen.sql ..."
db2 -l db2output.log -f crsf_next_isotzoneidgen.sql
echo "#	Running crsp_next_servicetypeidgen.sql ..."
db2 -l db2output.log -f crsp_next_servicetypeidgen.sql

echo "#	Running crsf_next_servicetypeidgen.sql ..."
db2 -l db2output.log -f crsf_next_servicetypeidgen.sql
echo "#	Running crsp_next_clusteridgen.sql ..."
db2 -l db2output.log -f crsp_next_clusteridgen.sql

echo "#	Running crsf_next_clusteridgen.sql ..."
db2 -l db2output.log -f crsf_next_clusteridgen.sql
echo "#	Running crsp_next_tenantidgen.sql ..."
db2 -l db2output.log -f crsp_next_tenantidgen.sql

echo "#	Running crsf_next_tenantidgen.sql ..."
db2 -l db2output.log -f crsf_next_tenantidgen.sql
echo "#	Running crsp_next_secappidgen.sql ..."
db2 -l db2output.log -f crsp_next_secappidgen.sql

echo "#	Running crsf_next_secappidgen.sql ..."
db2 -l db2output.log -f crsf_next_secappidgen.sql
echo "#	Running crsp_next_secformidgen.sql ..."
db2 -l db2output.log -f crsp_next_secformidgen.sql

echo "#	Running crsf_next_secformidgen.sql ..."
db2 -l db2output.log -f crsf_next_secformidgen.sql
echo "#	Running crsp_next_secgroupidgen.sql ..."
db2 -l db2output.log -f crsp_next_secgroupidgen.sql

echo "#	Running crsf_next_secgroupidgen.sql ..."
db2 -l db2output.log -f crsf_next_secgroupidgen.sql
echo "#	Running crsp_next_hostnodeidgen.sql ..."
db2 -l db2output.log -f crsp_next_hostnodeidgen.sql

echo "#	Running crsf_next_hostnodeidgen.sql ..."
db2 -l db2output.log -f crsf_next_hostnodeidgen.sql
echo "#	Running crsp_next_secgroupformidgen.sql ..."
db2 -l db2output.log -f crsp_next_secgroupformidgen.sql

echo "#	Running crsf_next_secgroupformidgen.sql ..."
db2 -l db2output.log -f crsf_next_secgroupformidgen.sql
echo "#	Running crsp_next_secgrpincidgen.sql ..."
db2 -l db2output.log -f crsp_next_secgrpincidgen.sql

echo "#	Running crsf_next_secgrpincidgen.sql ..."
db2 -l db2output.log -f crsf_next_secgrpincidgen.sql
echo "#	Running crsp_next_secgrpmembidgen.sql ..."
db2 -l db2output.log -f crsp_next_secgrpmembidgen.sql

echo "#	Running crsf_next_secgrpmembidgen.sql ..."
db2 -l db2output.log -f crsf_next_secgrpmembidgen.sql
echo "#	Running crsp_next_serviceidgen.sql ..."
db2 -l db2output.log -f crsp_next_serviceidgen.sql

echo "#	Running crsf_next_serviceidgen.sql ..."
db2 -l db2output.log -f crsf_next_serviceidgen.sql
echo "#	Running crsp_next_tsecgroupidgen.sql ..."
db2 -l db2output.log -f crsp_next_tsecgroupidgen.sql

echo "#	Running crsf_next_tsecgroupidgen.sql ..."
db2 -l db2output.log -f crsf_next_tsecgroupidgen.sql
echo "#	Running crsp_next_tsecgrpincidgen.sql ..."
db2 -l db2output.log -f crsp_next_tsecgrpincidgen.sql

echo "#	Running crsf_next_tsecgrpincidgen.sql ..."
db2 -l db2output.log -f crsf_next_tsecgrpincidgen.sql
echo "#	Running crsp_next_tsecgrpmembidgen.sql ..."
db2 -l db2output.log -f crsp_next_tsecgrpmembidgen.sql

echo "#	Running crsf_next_tsecgrpmembidgen.sql ..."
db2 -l db2output.log -f crsf_next_tsecgrpmembidgen.sql
echo "#	Running crsp_bootstrap.sql ..."
db2 -l db2output.log -f crsp_bootstrap.sql
echo "#	Running crsp_create_clus.sql ..."
db2 -l db2output.log -f crsp_create_clus.sql
echo "#	Running crsp_lock_clus.sql ..."
db2 -l db2output.log -f crsp_lock_clus.sql
echo "#	Running crsp_read_clus.sql ..."
db2 -l db2output.log -f crsp_read_clus.sql
echo "#	Running crsp_read_clus_all.sql ..."
db2 -l db2output.log -f crsp_read_clus_all.sql
echo "#	Running crsp_page_clus_all.sql ..."
db2 -l db2output.log -f crsp_page_clus_all.sql
echo "#	Running crsp_read_clus_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_clus_by_ididx.sql
echo "#	Running crsp_read_clus_by_udomnameidx.sql ..."
db2 -l db2output.log -f crsp_read_clus_by_udomnameidx.sql
echo "#	Running crsp_read_clus_by_udescridx.sql ..."
db2 -l db2output.log -f crsp_read_clus_by_udescridx.sql
echo "#	Running crsp_update_clus.sql ..."
db2 -l db2output.log -f crsp_update_clus.sql
echo "#	Running crsp_create_hostnode.sql ..."
db2 -l db2output.log -f crsp_create_hostnode.sql
echo "#	Running crsp_lock_hostnode.sql ..."
db2 -l db2output.log -f crsp_lock_hostnode.sql
echo "#	Running crsp_read_hostnode.sql ..."
db2 -l db2output.log -f crsp_read_hostnode.sql
echo "#	Running crsp_read_hostnode_all.sql ..."
db2 -l db2output.log -f crsp_read_hostnode_all.sql
echo "#	Running crsp_page_hostnode_all.sql ..."
db2 -l db2output.log -f crsp_page_hostnode_all.sql
echo "#	Running crsp_read_hostnode_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_hostnode_by_ididx.sql
echo "#	Running crsp_read_hostnode_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_read_hostnode_by_clusteridx.sql
echo "#	Running crsp_page_hostnode_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_page_hostnode_by_clusteridx.sql
echo "#	Running crsp_read_hostnode_by_udescridx.sql ..."
db2 -l db2output.log -f crsp_read_hostnode_by_udescridx.sql
echo "#	Running crsp_read_hostnode_by_hostnameidx.sql ..."
db2 -l db2output.log -f crsp_read_hostnode_by_hostnameidx.sql
echo "#	Running crsp_update_hostnode.sql ..."
db2 -l db2output.log -f crsp_update_hostnode.sql
echo "#	Running crsp_create_iso_ccy.sql ..."
db2 -l db2output.log -f crsp_create_iso_ccy.sql
echo "#	Running crsp_lock_iso_ccy.sql ..."
db2 -l db2output.log -f crsp_lock_iso_ccy.sql
echo "#	Running crsp_read_iso_ccy.sql ..."
db2 -l db2output.log -f crsp_read_iso_ccy.sql
echo "#	Running crsp_read_iso_ccy_all.sql ..."
db2 -l db2output.log -f crsp_read_iso_ccy_all.sql
echo "#	Running crsp_read_iso_ccy_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_iso_ccy_by_ididx.sql
echo "#	Running crsp_read_iso_ccy_by_ccycdidx.sql ..."
db2 -l db2output.log -f crsp_read_iso_ccy_by_ccycdidx.sql
echo "#	Running crsp_read_iso_ccy_by_ccynmidx.sql ..."
db2 -l db2output.log -f crsp_read_iso_ccy_by_ccynmidx.sql
echo "#	Running crsp_update_iso_ccy.sql ..."
db2 -l db2output.log -f crsp_update_iso_ccy.sql
echo "#	Running crsp_create_iso_cntry.sql ..."
db2 -l db2output.log -f crsp_create_iso_cntry.sql
echo "#	Running crsp_lock_iso_cntry.sql ..."
db2 -l db2output.log -f crsp_lock_iso_cntry.sql
echo "#	Running crsp_read_iso_cntry.sql ..."
db2 -l db2output.log -f crsp_read_iso_cntry.sql
echo "#	Running crsp_read_iso_cntry_all.sql ..."
db2 -l db2output.log -f crsp_read_iso_cntry_all.sql
echo "#	Running crsp_read_iso_cntry_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_iso_cntry_by_ididx.sql
echo "#	Running crsp_read_iso_cntry_by_isocodeidx.sql ..."
db2 -l db2output.log -f crsp_read_iso_cntry_by_isocodeidx.sql
echo "#	Running crsp_read_iso_cntry_by_nameidx.sql ..."
db2 -l db2output.log -f crsp_read_iso_cntry_by_nameidx.sql
echo "#	Running crsp_update_iso_cntry.sql ..."
db2 -l db2output.log -f crsp_update_iso_cntry.sql
echo "#	Running crsp_create_iso_cntryccy.sql ..."
db2 -l db2output.log -f crsp_create_iso_cntryccy.sql
echo "#	Running crsp_lock_iso_cntryccy.sql ..."
db2 -l db2output.log -f crsp_lock_iso_cntryccy.sql
echo "#	Running crsp_read_iso_cntryccy.sql ..."
db2 -l db2output.log -f crsp_read_iso_cntryccy.sql
echo "#	Running crsp_read_iso_cntryccy_all.sql ..."
db2 -l db2output.log -f crsp_read_iso_cntryccy_all.sql
echo "#	Running crsp_read_iso_cntryccy_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_iso_cntryccy_by_ididx.sql
echo "#	Running crsp_read_iso_cntryccy_by_ctryidx.sql ..."
db2 -l db2output.log -f crsp_read_iso_cntryccy_by_ctryidx.sql
echo "#	Running crsp_read_iso_cntryccy_by_ccyidx.sql ..."
db2 -l db2output.log -f crsp_read_iso_cntryccy_by_ccyidx.sql
echo "#	Running crsp_update_iso_cntryccy.sql ..."
db2 -l db2output.log -f crsp_update_iso_cntryccy.sql
echo "#	Running crsp_create_iso_cntrylng.sql ..."
db2 -l db2output.log -f crsp_create_iso_cntrylng.sql
echo "#	Running crsp_lock_iso_cntrylng.sql ..."
db2 -l db2output.log -f crsp_lock_iso_cntrylng.sql
echo "#	Running crsp_read_iso_cntrylng.sql ..."
db2 -l db2output.log -f crsp_read_iso_cntrylng.sql
echo "#	Running crsp_read_iso_cntrylng_all.sql ..."
db2 -l db2output.log -f crsp_read_iso_cntrylng_all.sql
echo "#	Running crsp_read_iso_cntrylng_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_iso_cntrylng_by_ididx.sql
echo "#	Running crsp_read_iso_cntrylng_by_ctryidx.sql ..."
db2 -l db2output.log -f crsp_read_iso_cntrylng_by_ctryidx.sql
echo "#	Running crsp_read_iso_cntrylng_by_langidx.sql ..."
db2 -l db2output.log -f crsp_read_iso_cntrylng_by_langidx.sql
echo "#	Running crsp_update_iso_cntrylng.sql ..."
db2 -l db2output.log -f crsp_update_iso_cntrylng.sql
echo "#	Running crsp_create_iso_lang.sql ..."
db2 -l db2output.log -f crsp_create_iso_lang.sql
echo "#	Running crsp_lock_iso_lang.sql ..."
db2 -l db2output.log -f crsp_lock_iso_lang.sql
echo "#	Running crsp_read_iso_lang.sql ..."
db2 -l db2output.log -f crsp_read_iso_lang.sql
echo "#	Running crsp_read_iso_lang_all.sql ..."
db2 -l db2output.log -f crsp_read_iso_lang_all.sql
echo "#	Running crsp_read_iso_lang_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_iso_lang_by_ididx.sql
echo "#	Running crsp_read_iso_lang_by_code3idx.sql ..."
db2 -l db2output.log -f crsp_read_iso_lang_by_code3idx.sql
echo "#	Running crsp_read_iso_lang_by_code2idx.sql ..."
db2 -l db2output.log -f crsp_read_iso_lang_by_code2idx.sql
echo "#	Running crsp_update_iso_lang.sql ..."
db2 -l db2output.log -f crsp_update_iso_lang.sql
echo "#	Running crsp_create_isotz.sql ..."
db2 -l db2output.log -f crsp_create_isotz.sql
echo "#	Running crsp_lock_isotz.sql ..."
db2 -l db2output.log -f crsp_lock_isotz.sql
echo "#	Running crsp_read_isotz.sql ..."
db2 -l db2output.log -f crsp_read_isotz.sql
echo "#	Running crsp_read_isotz_all.sql ..."
db2 -l db2output.log -f crsp_read_isotz_all.sql
echo "#	Running crsp_read_isotz_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_isotz_by_ididx.sql
echo "#	Running crsp_read_isotz_by_offsetidx.sql ..."
db2 -l db2output.log -f crsp_read_isotz_by_offsetidx.sql
echo "#	Running crsp_read_isotz_by_utznameidx.sql ..."
db2 -l db2output.log -f crsp_read_isotz_by_utznameidx.sql
echo "#	Running crsp_read_isotz_by_iso8601idx.sql ..."
db2 -l db2output.log -f crsp_read_isotz_by_iso8601idx.sql
echo "#	Running crsp_update_isotz.sql ..."
db2 -l db2output.log -f crsp_update_isotz.sql
echo "#	Running crsp_create_secapp.sql ..."
db2 -l db2output.log -f crsp_create_secapp.sql
echo "#	Running crsp_lock_secapp.sql ..."
db2 -l db2output.log -f crsp_lock_secapp.sql
echo "#	Running crsp_read_secapp.sql ..."
db2 -l db2output.log -f crsp_read_secapp.sql
echo "#	Running crsp_read_secapp_all.sql ..."
db2 -l db2output.log -f crsp_read_secapp_all.sql
echo "#	Running crsp_page_secapp_all.sql ..."
db2 -l db2output.log -f crsp_page_secapp_all.sql
echo "#	Running crsp_read_secapp_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_secapp_by_ididx.sql
echo "#	Running crsp_read_secapp_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_read_secapp_by_clusteridx.sql
echo "#	Running crsp_page_secapp_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_page_secapp_by_clusteridx.sql
echo "#	Running crsp_read_secapp_by_ujeemountidx.sql ..."
db2 -l db2output.log -f crsp_read_secapp_by_ujeemountidx.sql
echo "#	Running crsp_update_secapp.sql ..."
db2 -l db2output.log -f crsp_update_secapp.sql
echo "#	Running crsp_create_secdev.sql ..."
db2 -l db2output.log -f crsp_create_secdev.sql
echo "#	Running crsp_lock_secdev.sql ..."
db2 -l db2output.log -f crsp_lock_secdev.sql
echo "#	Running crsp_read_secdev.sql ..."
db2 -l db2output.log -f crsp_read_secdev.sql
echo "#	Running crsp_read_secdev_all.sql ..."
db2 -l db2output.log -f crsp_read_secdev_all.sql
echo "#	Running crsp_page_secdev_all.sql ..."
db2 -l db2output.log -f crsp_page_secdev_all.sql
echo "#	Running crsp_read_secdev_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_secdev_by_ididx.sql
echo "#	Running crsp_read_secdev_by_nameidx.sql ..."
db2 -l db2output.log -f crsp_read_secdev_by_nameidx.sql
echo "#	Running crsp_read_secdev_by_useridx.sql ..."
db2 -l db2output.log -f crsp_read_secdev_by_useridx.sql
echo "#	Running crsp_page_secdev_by_useridx.sql ..."
db2 -l db2output.log -f crsp_page_secdev_by_useridx.sql
echo "#	Running crsp_update_secdev.sql ..."
db2 -l db2output.log -f crsp_update_secdev.sql
echo "#	Running crsp_create_secform.sql ..."
db2 -l db2output.log -f crsp_create_secform.sql
echo "#	Running crsp_lock_secform.sql ..."
db2 -l db2output.log -f crsp_lock_secform.sql
echo "#	Running crsp_read_secform.sql ..."
db2 -l db2output.log -f crsp_read_secform.sql
echo "#	Running crsp_read_secform_all.sql ..."
db2 -l db2output.log -f crsp_read_secform_all.sql
echo "#	Running crsp_page_secform_all.sql ..."
db2 -l db2output.log -f crsp_page_secform_all.sql
echo "#	Running crsp_read_secform_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_secform_by_ididx.sql
echo "#	Running crsp_read_secform_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_read_secform_by_clusteridx.sql
echo "#	Running crsp_page_secform_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_page_secform_by_clusteridx.sql
echo "#	Running crsp_read_secform_by_secappidx.sql ..."
db2 -l db2output.log -f crsp_read_secform_by_secappidx.sql
echo "#	Running crsp_page_secform_by_secappidx.sql ..."
db2 -l db2output.log -f crsp_page_secform_by_secappidx.sql
echo "#	Running crsp_read_secform_by_ujeeservletidx.sql ..."
db2 -l db2output.log -f crsp_read_secform_by_ujeeservletidx.sql
echo "#	Running crsp_update_secform.sql ..."
db2 -l db2output.log -f crsp_update_secform.sql
echo "#	Running crsp_create_secgrp.sql ..."
db2 -l db2output.log -f crsp_create_secgrp.sql
echo "#	Running crsp_lock_secgrp.sql ..."
db2 -l db2output.log -f crsp_lock_secgrp.sql
echo "#	Running crsp_read_secgrp.sql ..."
db2 -l db2output.log -f crsp_read_secgrp.sql
echo "#	Running crsp_read_secgrp_all.sql ..."
db2 -l db2output.log -f crsp_read_secgrp_all.sql
echo "#	Running crsp_read_secgrp_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_secgrp_by_ididx.sql
echo "#	Running crsp_read_secgrp_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_read_secgrp_by_clusteridx.sql
echo "#	Running crsp_read_secgrp_by_clustervisidx.sql ..."
db2 -l db2output.log -f crsp_read_secgrp_by_clustervisidx.sql
echo "#	Running crsp_read_secgrp_by_unameidx.sql ..."
db2 -l db2output.log -f crsp_read_secgrp_by_unameidx.sql
echo "#	Running crsp_update_secgrp.sql ..."
db2 -l db2output.log -f crsp_update_secgrp.sql
echo "#	Running crsp_create_secgrpfrm.sql ..."
db2 -l db2output.log -f crsp_create_secgrpfrm.sql
echo "#	Running crsp_lock_secgrpfrm.sql ..."
db2 -l db2output.log -f crsp_lock_secgrpfrm.sql
echo "#	Running crsp_read_secgrpfrm.sql ..."
db2 -l db2output.log -f crsp_read_secgrpfrm.sql
echo "#	Running crsp_read_secgrpfrm_all.sql ..."
db2 -l db2output.log -f crsp_read_secgrpfrm_all.sql
echo "#	Running crsp_page_secgrpfrm_all.sql ..."
db2 -l db2output.log -f crsp_page_secgrpfrm_all.sql
echo "#	Running crsp_read_secgrpfrm_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_secgrpfrm_by_ididx.sql
echo "#	Running crsp_read_secgrpfrm_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_read_secgrpfrm_by_clusteridx.sql
echo "#	Running crsp_page_secgrpfrm_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_page_secgrpfrm_by_clusteridx.sql
echo "#	Running crsp_read_secgrpfrm_by_groupidx.sql ..."
db2 -l db2output.log -f crsp_read_secgrpfrm_by_groupidx.sql
echo "#	Running crsp_page_secgrpfrm_by_groupidx.sql ..."
db2 -l db2output.log -f crsp_page_secgrpfrm_by_groupidx.sql
echo "#	Running crsp_read_secgrpfrm_by_appidx.sql ..."
db2 -l db2output.log -f crsp_read_secgrpfrm_by_appidx.sql
echo "#	Running crsp_page_secgrpfrm_by_appidx.sql ..."
db2 -l db2output.log -f crsp_page_secgrpfrm_by_appidx.sql
echo "#	Running crsp_read_secgrpfrm_by_formidx.sql ..."
db2 -l db2output.log -f crsp_read_secgrpfrm_by_formidx.sql
echo "#	Running crsp_page_secgrpfrm_by_formidx.sql ..."
db2 -l db2output.log -f crsp_page_secgrpfrm_by_formidx.sql
echo "#	Running crsp_read_secgrpfrm_by_uformidx.sql ..."
db2 -l db2output.log -f crsp_read_secgrpfrm_by_uformidx.sql
echo "#	Running crsp_update_secgrpfrm.sql ..."
db2 -l db2output.log -f crsp_update_secgrpfrm.sql
echo "#	Running crsp_create_secinc.sql ..."
db2 -l db2output.log -f crsp_create_secinc.sql
echo "#	Running crsp_lock_secinc.sql ..."
db2 -l db2output.log -f crsp_lock_secinc.sql
echo "#	Running crsp_read_secinc.sql ..."
db2 -l db2output.log -f crsp_read_secinc.sql
echo "#	Running crsp_read_secinc_all.sql ..."
db2 -l db2output.log -f crsp_read_secinc_all.sql
echo "#	Running crsp_page_secinc_all.sql ..."
db2 -l db2output.log -f crsp_page_secinc_all.sql
echo "#	Running crsp_read_secinc_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_secinc_by_ididx.sql
echo "#	Running crsp_read_secinc_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_read_secinc_by_clusteridx.sql
echo "#	Running crsp_page_secinc_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_page_secinc_by_clusteridx.sql
echo "#	Running crsp_read_secinc_by_groupidx.sql ..."
db2 -l db2output.log -f crsp_read_secinc_by_groupidx.sql
echo "#	Running crsp_page_secinc_by_groupidx.sql ..."
db2 -l db2output.log -f crsp_page_secinc_by_groupidx.sql
echo "#	Running crsp_read_secinc_by_includeidx.sql ..."
db2 -l db2output.log -f crsp_read_secinc_by_includeidx.sql
echo "#	Running crsp_page_secinc_by_includeidx.sql ..."
db2 -l db2output.log -f crsp_page_secinc_by_includeidx.sql
echo "#	Running crsp_read_secinc_by_uincludeidx.sql ..."
db2 -l db2output.log -f crsp_read_secinc_by_uincludeidx.sql
echo "#	Running crsp_update_secinc.sql ..."
db2 -l db2output.log -f crsp_update_secinc.sql
echo "#	Running crsp_create_secmemb.sql ..."
db2 -l db2output.log -f crsp_create_secmemb.sql
echo "#	Running crsp_lock_secmemb.sql ..."
db2 -l db2output.log -f crsp_lock_secmemb.sql
echo "#	Running crsp_read_secmemb.sql ..."
db2 -l db2output.log -f crsp_read_secmemb.sql
echo "#	Running crsp_read_secmemb_all.sql ..."
db2 -l db2output.log -f crsp_read_secmemb_all.sql
echo "#	Running crsp_page_secmemb_all.sql ..."
db2 -l db2output.log -f crsp_page_secmemb_all.sql
echo "#	Running crsp_read_secmemb_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_secmemb_by_ididx.sql
echo "#	Running crsp_read_secmemb_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_read_secmemb_by_clusteridx.sql
echo "#	Running crsp_page_secmemb_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_page_secmemb_by_clusteridx.sql
echo "#	Running crsp_read_secmemb_by_groupidx.sql ..."
db2 -l db2output.log -f crsp_read_secmemb_by_groupidx.sql
echo "#	Running crsp_page_secmemb_by_groupidx.sql ..."
db2 -l db2output.log -f crsp_page_secmemb_by_groupidx.sql
echo "#	Running crsp_read_secmemb_by_useridx.sql ..."
db2 -l db2output.log -f crsp_read_secmemb_by_useridx.sql
echo "#	Running crsp_page_secmemb_by_useridx.sql ..."
db2 -l db2output.log -f crsp_page_secmemb_by_useridx.sql
echo "#	Running crsp_read_secmemb_by_uuseridx.sql ..."
db2 -l db2output.log -f crsp_read_secmemb_by_uuseridx.sql
echo "#	Running crsp_update_secmemb.sql ..."
db2 -l db2output.log -f crsp_update_secmemb.sql
echo "#	Running crsp_create_secsess.sql ..."
db2 -l db2output.log -f crsp_create_secsess.sql
echo "#	Running crsp_lock_secsess.sql ..."
db2 -l db2output.log -f crsp_lock_secsess.sql
echo "#	Running crsp_read_secsess.sql ..."
db2 -l db2output.log -f crsp_read_secsess.sql
echo "#	Running crsp_read_secsess_all.sql ..."
db2 -l db2output.log -f crsp_read_secsess_all.sql
echo "#	Running crsp_page_secsess_all.sql ..."
db2 -l db2output.log -f crsp_page_secsess_all.sql
echo "#	Running crsp_read_secsess_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_secsess_by_ididx.sql
echo "#	Running crsp_read_secsess_by_secuseridx.sql ..."
db2 -l db2output.log -f crsp_read_secsess_by_secuseridx.sql
echo "#	Running crsp_page_secsess_by_secuseridx.sql ..."
db2 -l db2output.log -f crsp_page_secsess_by_secuseridx.sql
echo "#	Running crsp_read_secsess_by_secdevidx.sql ..."
db2 -l db2output.log -f crsp_read_secsess_by_secdevidx.sql
echo "#	Running crsp_page_secsess_by_secdevidx.sql ..."
db2 -l db2output.log -f crsp_page_secsess_by_secdevidx.sql
echo "#	Running crsp_read_secsess_by_startidx.sql ..."
db2 -l db2output.log -f crsp_read_secsess_by_startidx.sql
echo "#	Running crsp_read_secsess_by_finishidx.sql ..."
db2 -l db2output.log -f crsp_read_secsess_by_finishidx.sql
echo "#	Running crsp_page_secsess_by_finishidx.sql ..."
db2 -l db2output.log -f crsp_page_secsess_by_finishidx.sql
echo "#	Running crsp_read_secsess_by_secproxyidx.sql ..."
db2 -l db2output.log -f crsp_read_secsess_by_secproxyidx.sql
echo "#	Running crsp_page_secsess_by_secproxyidx.sql ..."
db2 -l db2output.log -f crsp_page_secsess_by_secproxyidx.sql
echo "#	Running crsp_update_secsess.sql ..."
db2 -l db2output.log -f crsp_update_secsess.sql
echo "#	Running crsp_create_secuser.sql ..."
db2 -l db2output.log -f crsp_create_secuser.sql
echo "#	Running crsp_lock_secuser.sql ..."
db2 -l db2output.log -f crsp_lock_secuser.sql
echo "#	Running crsp_read_secuser.sql ..."
db2 -l db2output.log -f crsp_read_secuser.sql
echo "#	Running crsp_read_secuser_all.sql ..."
db2 -l db2output.log -f crsp_read_secuser_all.sql
echo "#	Running crsp_page_secuser_all.sql ..."
db2 -l db2output.log -f crsp_page_secuser_all.sql
echo "#	Running crsp_read_secuser_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_secuser_by_ididx.sql
echo "#	Running crsp_read_secuser_by_uloginidx.sql ..."
db2 -l db2output.log -f crsp_read_secuser_by_uloginidx.sql
echo "#	Running crsp_read_secuser_by_emconfidx.sql ..."
db2 -l db2output.log -f crsp_read_secuser_by_emconfidx.sql
echo "#	Running crsp_page_secuser_by_emconfidx.sql ..."
db2 -l db2output.log -f crsp_page_secuser_by_emconfidx.sql
echo "#	Running crsp_read_secuser_by_pwdresetidx.sql ..."
db2 -l db2output.log -f crsp_read_secuser_by_pwdresetidx.sql
echo "#	Running crsp_page_secuser_by_pwdresetidx.sql ..."
db2 -l db2output.log -f crsp_page_secuser_by_pwdresetidx.sql
echo "#	Running crsp_read_secuser_by_defdevidx.sql ..."
db2 -l db2output.log -f crsp_read_secuser_by_defdevidx.sql
echo "#	Running crsp_page_secuser_by_defdevidx.sql ..."
db2 -l db2output.log -f crsp_page_secuser_by_defdevidx.sql
echo "#	Running crsp_update_secuser.sql ..."
db2 -l db2output.log -f crsp_update_secuser.sql
echo "#	Running crsp_create_hostsvc.sql ..."
db2 -l db2output.log -f crsp_create_hostsvc.sql
echo "#	Running crsp_lock_hostsvc.sql ..."
db2 -l db2output.log -f crsp_lock_hostsvc.sql
echo "#	Running crsp_read_hostsvc.sql ..."
db2 -l db2output.log -f crsp_read_hostsvc.sql
echo "#	Running crsp_read_hostsvc_all.sql ..."
db2 -l db2output.log -f crsp_read_hostsvc_all.sql
echo "#	Running crsp_page_hostsvc_all.sql ..."
db2 -l db2output.log -f crsp_page_hostsvc_all.sql
echo "#	Running crsp_read_hostsvc_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_hostsvc_by_ididx.sql
echo "#	Running crsp_read_hostsvc_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_read_hostsvc_by_clusteridx.sql
echo "#	Running crsp_page_hostsvc_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_page_hostsvc_by_clusteridx.sql
echo "#	Running crsp_read_hostsvc_by_hostidx.sql ..."
db2 -l db2output.log -f crsp_read_hostsvc_by_hostidx.sql
echo "#	Running crsp_page_hostsvc_by_hostidx.sql ..."
db2 -l db2output.log -f crsp_page_hostsvc_by_hostidx.sql
echo "#	Running crsp_read_hostsvc_by_typeidx.sql ..."
db2 -l db2output.log -f crsp_read_hostsvc_by_typeidx.sql
echo "#	Running crsp_page_hostsvc_by_typeidx.sql ..."
db2 -l db2output.log -f crsp_page_hostsvc_by_typeidx.sql
echo "#	Running crsp_read_hostsvc_by_utypeidx.sql ..."
db2 -l db2output.log -f crsp_read_hostsvc_by_utypeidx.sql
echo "#	Running crsp_read_hostsvc_by_uhostportidx.sql ..."
db2 -l db2output.log -f crsp_read_hostsvc_by_uhostportidx.sql
echo "#	Running crsp_update_hostsvc.sql ..."
db2 -l db2output.log -f crsp_update_hostsvc.sql
echo "#	Running crsp_create_svctype.sql ..."
db2 -l db2output.log -f crsp_create_svctype.sql
echo "#	Running crsp_lock_svctype.sql ..."
db2 -l db2output.log -f crsp_lock_svctype.sql
echo "#	Running crsp_read_svctype.sql ..."
db2 -l db2output.log -f crsp_read_svctype.sql
echo "#	Running crsp_read_svctype_all.sql ..."
db2 -l db2output.log -f crsp_read_svctype_all.sql
echo "#	Running crsp_read_svctype_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_svctype_by_ididx.sql
echo "#	Running crsp_read_svctype_by_udescridx.sql ..."
db2 -l db2output.log -f crsp_read_svctype_by_udescridx.sql
echo "#	Running crsp_update_svctype.sql ..."
db2 -l db2output.log -f crsp_update_svctype.sql
echo "#	Running crsp_create_sysclus.sql ..."
db2 -l db2output.log -f crsp_create_sysclus.sql
echo "#	Running crsp_lock_sysclus.sql ..."
db2 -l db2output.log -f crsp_lock_sysclus.sql
echo "#	Running crsp_read_sysclus.sql ..."
db2 -l db2output.log -f crsp_read_sysclus.sql
echo "#	Running crsp_read_sysclus_all.sql ..."
db2 -l db2output.log -f crsp_read_sysclus_all.sql
echo "#	Running crsp_read_sysclus_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_sysclus_by_ididx.sql
echo "#	Running crsp_read_sysclus_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_read_sysclus_by_clusteridx.sql
echo "#	Running crsp_update_sysclus.sql ..."
db2 -l db2output.log -f crsp_update_sysclus.sql
echo "#	Running crsp_create_tsecgrp.sql ..."
db2 -l db2output.log -f crsp_create_tsecgrp.sql
echo "#	Running crsp_lock_tsecgrp.sql ..."
db2 -l db2output.log -f crsp_lock_tsecgrp.sql
echo "#	Running crsp_read_tsecgrp.sql ..."
db2 -l db2output.log -f crsp_read_tsecgrp.sql
echo "#	Running crsp_read_tsecgrp_all.sql ..."
db2 -l db2output.log -f crsp_read_tsecgrp_all.sql
echo "#	Running crsp_read_tsecgrp_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_tsecgrp_by_ididx.sql
echo "#	Running crsp_read_tsecgrp_by_tenantidx.sql ..."
db2 -l db2output.log -f crsp_read_tsecgrp_by_tenantidx.sql
echo "#	Running crsp_read_tsecgrp_by_tenantvisidx.sql ..."
db2 -l db2output.log -f crsp_read_tsecgrp_by_tenantvisidx.sql
echo "#	Running crsp_read_tsecgrp_by_unameidx.sql ..."
db2 -l db2output.log -f crsp_read_tsecgrp_by_unameidx.sql
echo "#	Running crsp_update_tsecgrp.sql ..."
db2 -l db2output.log -f crsp_update_tsecgrp.sql
echo "#	Running crsp_create_tsecinc.sql ..."
db2 -l db2output.log -f crsp_create_tsecinc.sql
echo "#	Running crsp_lock_tsecinc.sql ..."
db2 -l db2output.log -f crsp_lock_tsecinc.sql
echo "#	Running crsp_read_tsecinc.sql ..."
db2 -l db2output.log -f crsp_read_tsecinc.sql
echo "#	Running crsp_read_tsecinc_all.sql ..."
db2 -l db2output.log -f crsp_read_tsecinc_all.sql
echo "#	Running crsp_page_tsecinc_all.sql ..."
db2 -l db2output.log -f crsp_page_tsecinc_all.sql
echo "#	Running crsp_read_tsecinc_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_tsecinc_by_ididx.sql
echo "#	Running crsp_read_tsecinc_by_tenantidx.sql ..."
db2 -l db2output.log -f crsp_read_tsecinc_by_tenantidx.sql
echo "#	Running crsp_page_tsecinc_by_tenantidx.sql ..."
db2 -l db2output.log -f crsp_page_tsecinc_by_tenantidx.sql
echo "#	Running crsp_read_tsecinc_by_groupidx.sql ..."
db2 -l db2output.log -f crsp_read_tsecinc_by_groupidx.sql
echo "#	Running crsp_page_tsecinc_by_groupidx.sql ..."
db2 -l db2output.log -f crsp_page_tsecinc_by_groupidx.sql
echo "#	Running crsp_read_tsecinc_by_includeidx.sql ..."
db2 -l db2output.log -f crsp_read_tsecinc_by_includeidx.sql
echo "#	Running crsp_page_tsecinc_by_includeidx.sql ..."
db2 -l db2output.log -f crsp_page_tsecinc_by_includeidx.sql
echo "#	Running crsp_read_tsecinc_by_uincludeidx.sql ..."
db2 -l db2output.log -f crsp_read_tsecinc_by_uincludeidx.sql
echo "#	Running crsp_update_tsecinc.sql ..."
db2 -l db2output.log -f crsp_update_tsecinc.sql
echo "#	Running crsp_create_tsecmemb.sql ..."
db2 -l db2output.log -f crsp_create_tsecmemb.sql
echo "#	Running crsp_lock_tsecmemb.sql ..."
db2 -l db2output.log -f crsp_lock_tsecmemb.sql
echo "#	Running crsp_read_tsecmemb.sql ..."
db2 -l db2output.log -f crsp_read_tsecmemb.sql
echo "#	Running crsp_read_tsecmemb_all.sql ..."
db2 -l db2output.log -f crsp_read_tsecmemb_all.sql
echo "#	Running crsp_page_tsecmemb_all.sql ..."
db2 -l db2output.log -f crsp_page_tsecmemb_all.sql
echo "#	Running crsp_read_tsecmemb_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_tsecmemb_by_ididx.sql
echo "#	Running crsp_read_tsecmemb_by_tenantidx.sql ..."
db2 -l db2output.log -f crsp_read_tsecmemb_by_tenantidx.sql
echo "#	Running crsp_page_tsecmemb_by_tenantidx.sql ..."
db2 -l db2output.log -f crsp_page_tsecmemb_by_tenantidx.sql
echo "#	Running crsp_read_tsecmemb_by_groupidx.sql ..."
db2 -l db2output.log -f crsp_read_tsecmemb_by_groupidx.sql
echo "#	Running crsp_page_tsecmemb_by_groupidx.sql ..."
db2 -l db2output.log -f crsp_page_tsecmemb_by_groupidx.sql
echo "#	Running crsp_read_tsecmemb_by_useridx.sql ..."
db2 -l db2output.log -f crsp_read_tsecmemb_by_useridx.sql
echo "#	Running crsp_page_tsecmemb_by_useridx.sql ..."
db2 -l db2output.log -f crsp_page_tsecmemb_by_useridx.sql
echo "#	Running crsp_read_tsecmemb_by_uuseridx.sql ..."
db2 -l db2output.log -f crsp_read_tsecmemb_by_uuseridx.sql
echo "#	Running crsp_update_tsecmemb.sql ..."
db2 -l db2output.log -f crsp_update_tsecmemb.sql
echo "#	Running crsp_create_tenant.sql ..."
db2 -l db2output.log -f crsp_create_tenant.sql
echo "#	Running crsp_lock_tenant.sql ..."
db2 -l db2output.log -f crsp_lock_tenant.sql
echo "#	Running crsp_read_tenant.sql ..."
db2 -l db2output.log -f crsp_read_tenant.sql
echo "#	Running crsp_read_tenant_all.sql ..."
db2 -l db2output.log -f crsp_read_tenant_all.sql
echo "#	Running crsp_page_tenant_all.sql ..."
db2 -l db2output.log -f crsp_page_tenant_all.sql
echo "#	Running crsp_read_tenant_by_ididx.sql ..."
db2 -l db2output.log -f crsp_read_tenant_by_ididx.sql
echo "#	Running crsp_read_tenant_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_read_tenant_by_clusteridx.sql
echo "#	Running crsp_page_tenant_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_page_tenant_by_clusteridx.sql
echo "#	Running crsp_read_tenant_by_unameidx.sql ..."
db2 -l db2output.log -f crsp_read_tenant_by_unameidx.sql
echo "#	Running crsp_update_tenant.sql ..."
db2 -l db2output.log -f crsp_update_tenant.sql
echo "#	Running crsp_delete_clus_stub.sql ..."
db2 -l db2output.log -f crsp_delete_clus_stub.sql

echo "#	Running crsp_delete_hostnode_stub.sql ..."
db2 -l db2output.log -f crsp_delete_hostnode_stub.sql

echo "#	Running crsp_delete_iso_ccy_stub.sql ..."
db2 -l db2output.log -f crsp_delete_iso_ccy_stub.sql

echo "#	Running crsp_delete_iso_cntry_stub.sql ..."
db2 -l db2output.log -f crsp_delete_iso_cntry_stub.sql

echo "#	Running crsp_delete_iso_cntryccy_stub.sql ..."
db2 -l db2output.log -f crsp_delete_iso_cntryccy_stub.sql

echo "#	Running crsp_delete_iso_cntrylng_stub.sql ..."
db2 -l db2output.log -f crsp_delete_iso_cntrylng_stub.sql

echo "#	Running crsp_delete_iso_lang_stub.sql ..."
db2 -l db2output.log -f crsp_delete_iso_lang_stub.sql

echo "#	Running crsp_delete_isotz_stub.sql ..."
db2 -l db2output.log -f crsp_delete_isotz_stub.sql

echo "#	Running crsp_delete_secapp_stub.sql ..."
db2 -l db2output.log -f crsp_delete_secapp_stub.sql

echo "#	Running crsp_delete_secdev_stub.sql ..."
db2 -l db2output.log -f crsp_delete_secdev_stub.sql

echo "#	Running crsp_delete_secform_stub.sql ..."
db2 -l db2output.log -f crsp_delete_secform_stub.sql

echo "#	Running crsp_delete_secgrp_stub.sql ..."
db2 -l db2output.log -f crsp_delete_secgrp_stub.sql

echo "#	Running crsp_delete_secgrpfrm_stub.sql ..."
db2 -l db2output.log -f crsp_delete_secgrpfrm_stub.sql

echo "#	Running crsp_delete_secinc_stub.sql ..."
db2 -l db2output.log -f crsp_delete_secinc_stub.sql

echo "#	Running crsp_delete_secmemb_stub.sql ..."
db2 -l db2output.log -f crsp_delete_secmemb_stub.sql

echo "#	Running crsp_delete_secsess_stub.sql ..."
db2 -l db2output.log -f crsp_delete_secsess_stub.sql

echo "#	Running crsp_delete_secuser_stub.sql ..."
db2 -l db2output.log -f crsp_delete_secuser_stub.sql

echo "#	Running crsp_delete_hostsvc_stub.sql ..."
db2 -l db2output.log -f crsp_delete_hostsvc_stub.sql

echo "#	Running crsp_delete_svctype_stub.sql ..."
db2 -l db2output.log -f crsp_delete_svctype_stub.sql

echo "#	Running crsp_delete_sysclus_stub.sql ..."
db2 -l db2output.log -f crsp_delete_sysclus_stub.sql

echo "#	Running crsp_delete_tsecgrp_stub.sql ..."
db2 -l db2output.log -f crsp_delete_tsecgrp_stub.sql

echo "#	Running crsp_delete_tsecinc_stub.sql ..."
db2 -l db2output.log -f crsp_delete_tsecinc_stub.sql

echo "#	Running crsp_delete_tsecmemb_stub.sql ..."
db2 -l db2output.log -f crsp_delete_tsecmemb_stub.sql

echo "#	Running crsp_delete_tenant_stub.sql ..."
db2 -l db2output.log -f crsp_delete_tenant_stub.sql

echo "#	Running crsp_delete_clus_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_clus_by_ididx.sql
echo "#	Running crsp_delete_clus_by_udomnameidx.sql ..."
db2 -l db2output.log -f crsp_delete_clus_by_udomnameidx.sql
echo "#	Running crsp_delete_clus_by_udescridx.sql ..."
db2 -l db2output.log -f crsp_delete_clus_by_udescridx.sql

echo "#	Running crsp_delete_hostnode_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_hostnode_by_ididx.sql
echo "#	Running crsp_delete_hostnode_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_delete_hostnode_by_clusteridx.sql
echo "#	Running crsp_delete_hostnode_by_udescridx.sql ..."
db2 -l db2output.log -f crsp_delete_hostnode_by_udescridx.sql
echo "#	Running crsp_delete_hostnode_by_hostnameidx.sql ..."
db2 -l db2output.log -f crsp_delete_hostnode_by_hostnameidx.sql

echo "#	Running crsp_delete_iso_ccy_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_iso_ccy_by_ididx.sql
echo "#	Running crsp_delete_iso_ccy_by_ccycdidx.sql ..."
db2 -l db2output.log -f crsp_delete_iso_ccy_by_ccycdidx.sql
echo "#	Running crsp_delete_iso_ccy_by_ccynmidx.sql ..."
db2 -l db2output.log -f crsp_delete_iso_ccy_by_ccynmidx.sql

echo "#	Running crsp_delete_iso_cntry_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_iso_cntry_by_ididx.sql
echo "#	Running crsp_delete_iso_cntry_by_isocodeidx.sql ..."
db2 -l db2output.log -f crsp_delete_iso_cntry_by_isocodeidx.sql
echo "#	Running crsp_delete_iso_cntry_by_nameidx.sql ..."
db2 -l db2output.log -f crsp_delete_iso_cntry_by_nameidx.sql

echo "#	Running crsp_delete_iso_cntryccy_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_iso_cntryccy_by_ididx.sql
echo "#	Running crsp_delete_iso_cntryccy_by_ctryidx.sql ..."
db2 -l db2output.log -f crsp_delete_iso_cntryccy_by_ctryidx.sql
echo "#	Running crsp_delete_iso_cntryccy_by_ccyidx.sql ..."
db2 -l db2output.log -f crsp_delete_iso_cntryccy_by_ccyidx.sql

echo "#	Running crsp_delete_iso_cntrylng_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_iso_cntrylng_by_ididx.sql
echo "#	Running crsp_delete_iso_cntrylng_by_ctryidx.sql ..."
db2 -l db2output.log -f crsp_delete_iso_cntrylng_by_ctryidx.sql
echo "#	Running crsp_delete_iso_cntrylng_by_langidx.sql ..."
db2 -l db2output.log -f crsp_delete_iso_cntrylng_by_langidx.sql

echo "#	Running crsp_delete_iso_lang_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_iso_lang_by_ididx.sql
echo "#	Running crsp_delete_iso_lang_by_code3idx.sql ..."
db2 -l db2output.log -f crsp_delete_iso_lang_by_code3idx.sql
echo "#	Running crsp_delete_iso_lang_by_code2idx.sql ..."
db2 -l db2output.log -f crsp_delete_iso_lang_by_code2idx.sql

echo "#	Running crsp_delete_isotz_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_isotz_by_ididx.sql
echo "#	Running crsp_delete_isotz_by_offsetidx.sql ..."
db2 -l db2output.log -f crsp_delete_isotz_by_offsetidx.sql
echo "#	Running crsp_delete_isotz_by_utznameidx.sql ..."
db2 -l db2output.log -f crsp_delete_isotz_by_utznameidx.sql
echo "#	Running crsp_delete_isotz_by_iso8601idx.sql ..."
db2 -l db2output.log -f crsp_delete_isotz_by_iso8601idx.sql

echo "#	Running crsp_delete_secapp_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_secapp_by_ididx.sql
echo "#	Running crsp_delete_secapp_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_delete_secapp_by_clusteridx.sql
echo "#	Running crsp_delete_secapp_by_ujeemountidx.sql ..."
db2 -l db2output.log -f crsp_delete_secapp_by_ujeemountidx.sql

echo "#	Running crsp_delete_secdev_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_secdev_by_ididx.sql
echo "#	Running crsp_delete_secdev_by_nameidx.sql ..."
db2 -l db2output.log -f crsp_delete_secdev_by_nameidx.sql
echo "#	Running crsp_delete_secdev_by_useridx.sql ..."
db2 -l db2output.log -f crsp_delete_secdev_by_useridx.sql

echo "#	Running crsp_delete_secform_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_secform_by_ididx.sql
echo "#	Running crsp_delete_secform_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_delete_secform_by_clusteridx.sql
echo "#	Running crsp_delete_secform_by_secappidx.sql ..."
db2 -l db2output.log -f crsp_delete_secform_by_secappidx.sql
echo "#	Running crsp_delete_secform_by_ujeeservletidx.sql ..."
db2 -l db2output.log -f crsp_delete_secform_by_ujeeservletidx.sql

echo "#	Running crsp_delete_secgrp_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_secgrp_by_ididx.sql
echo "#	Running crsp_delete_secgrp_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_delete_secgrp_by_clusteridx.sql
echo "#	Running crsp_delete_secgrp_by_clustervisidx.sql ..."
db2 -l db2output.log -f crsp_delete_secgrp_by_clustervisidx.sql
echo "#	Running crsp_delete_secgrp_by_unameidx.sql ..."
db2 -l db2output.log -f crsp_delete_secgrp_by_unameidx.sql

echo "#	Running crsp_delete_secgrpfrm_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_secgrpfrm_by_ididx.sql
echo "#	Running crsp_delete_secgrpfrm_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_delete_secgrpfrm_by_clusteridx.sql
echo "#	Running crsp_delete_secgrpfrm_by_groupidx.sql ..."
db2 -l db2output.log -f crsp_delete_secgrpfrm_by_groupidx.sql
echo "#	Running crsp_delete_secgrpfrm_by_appidx.sql ..."
db2 -l db2output.log -f crsp_delete_secgrpfrm_by_appidx.sql
echo "#	Running crsp_delete_secgrpfrm_by_formidx.sql ..."
db2 -l db2output.log -f crsp_delete_secgrpfrm_by_formidx.sql
echo "#	Running crsp_delete_secgrpfrm_by_uformidx.sql ..."
db2 -l db2output.log -f crsp_delete_secgrpfrm_by_uformidx.sql

echo "#	Running crsp_delete_secinc_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_secinc_by_ididx.sql
echo "#	Running crsp_delete_secinc_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_delete_secinc_by_clusteridx.sql
echo "#	Running crsp_delete_secinc_by_groupidx.sql ..."
db2 -l db2output.log -f crsp_delete_secinc_by_groupidx.sql
echo "#	Running crsp_delete_secinc_by_includeidx.sql ..."
db2 -l db2output.log -f crsp_delete_secinc_by_includeidx.sql
echo "#	Running crsp_delete_secinc_by_uincludeidx.sql ..."
db2 -l db2output.log -f crsp_delete_secinc_by_uincludeidx.sql

echo "#	Running crsp_delete_secmemb_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_secmemb_by_ididx.sql
echo "#	Running crsp_delete_secmemb_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_delete_secmemb_by_clusteridx.sql
echo "#	Running crsp_delete_secmemb_by_groupidx.sql ..."
db2 -l db2output.log -f crsp_delete_secmemb_by_groupidx.sql
echo "#	Running crsp_delete_secmemb_by_useridx.sql ..."
db2 -l db2output.log -f crsp_delete_secmemb_by_useridx.sql
echo "#	Running crsp_delete_secmemb_by_uuseridx.sql ..."
db2 -l db2output.log -f crsp_delete_secmemb_by_uuseridx.sql

echo "#	Running crsp_delete_secsess_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_secsess_by_ididx.sql
echo "#	Running crsp_delete_secsess_by_secuseridx.sql ..."
db2 -l db2output.log -f crsp_delete_secsess_by_secuseridx.sql
echo "#	Running crsp_delete_secsess_by_secdevidx.sql ..."
db2 -l db2output.log -f crsp_delete_secsess_by_secdevidx.sql
echo "#	Running crsp_delete_secsess_by_startidx.sql ..."
db2 -l db2output.log -f crsp_delete_secsess_by_startidx.sql
echo "#	Running crsp_delete_secsess_by_finishidx.sql ..."
db2 -l db2output.log -f crsp_delete_secsess_by_finishidx.sql
echo "#	Running crsp_delete_secsess_by_secproxyidx.sql ..."
db2 -l db2output.log -f crsp_delete_secsess_by_secproxyidx.sql

echo "#	Running crsp_delete_secuser_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_secuser_by_ididx.sql
echo "#	Running crsp_delete_secuser_by_uloginidx.sql ..."
db2 -l db2output.log -f crsp_delete_secuser_by_uloginidx.sql
echo "#	Running crsp_delete_secuser_by_emconfidx.sql ..."
db2 -l db2output.log -f crsp_delete_secuser_by_emconfidx.sql
echo "#	Running crsp_delete_secuser_by_pwdresetidx.sql ..."
db2 -l db2output.log -f crsp_delete_secuser_by_pwdresetidx.sql
echo "#	Running crsp_delete_secuser_by_defdevidx.sql ..."
db2 -l db2output.log -f crsp_delete_secuser_by_defdevidx.sql

echo "#	Running crsp_delete_hostsvc_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_hostsvc_by_ididx.sql
echo "#	Running crsp_delete_hostsvc_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_delete_hostsvc_by_clusteridx.sql
echo "#	Running crsp_delete_hostsvc_by_hostidx.sql ..."
db2 -l db2output.log -f crsp_delete_hostsvc_by_hostidx.sql
echo "#	Running crsp_delete_hostsvc_by_typeidx.sql ..."
db2 -l db2output.log -f crsp_delete_hostsvc_by_typeidx.sql
echo "#	Running crsp_delete_hostsvc_by_utypeidx.sql ..."
db2 -l db2output.log -f crsp_delete_hostsvc_by_utypeidx.sql
echo "#	Running crsp_delete_hostsvc_by_uhostportidx.sql ..."
db2 -l db2output.log -f crsp_delete_hostsvc_by_uhostportidx.sql

echo "#	Running crsp_delete_svctype_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_svctype_by_ididx.sql
echo "#	Running crsp_delete_svctype_by_udescridx.sql ..."
db2 -l db2output.log -f crsp_delete_svctype_by_udescridx.sql

echo "#	Running crsp_delete_sysclus_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_sysclus_by_ididx.sql
echo "#	Running crsp_delete_sysclus_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_delete_sysclus_by_clusteridx.sql

echo "#	Running crsp_delete_tsecgrp_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_tsecgrp_by_ididx.sql
echo "#	Running crsp_delete_tsecgrp_by_tenantidx.sql ..."
db2 -l db2output.log -f crsp_delete_tsecgrp_by_tenantidx.sql
echo "#	Running crsp_delete_tsecgrp_by_tenantvisidx.sql ..."
db2 -l db2output.log -f crsp_delete_tsecgrp_by_tenantvisidx.sql
echo "#	Running crsp_delete_tsecgrp_by_unameidx.sql ..."
db2 -l db2output.log -f crsp_delete_tsecgrp_by_unameidx.sql

echo "#	Running crsp_delete_tsecinc_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_tsecinc_by_ididx.sql
echo "#	Running crsp_delete_tsecinc_by_tenantidx.sql ..."
db2 -l db2output.log -f crsp_delete_tsecinc_by_tenantidx.sql
echo "#	Running crsp_delete_tsecinc_by_groupidx.sql ..."
db2 -l db2output.log -f crsp_delete_tsecinc_by_groupidx.sql
echo "#	Running crsp_delete_tsecinc_by_includeidx.sql ..."
db2 -l db2output.log -f crsp_delete_tsecinc_by_includeidx.sql
echo "#	Running crsp_delete_tsecinc_by_uincludeidx.sql ..."
db2 -l db2output.log -f crsp_delete_tsecinc_by_uincludeidx.sql

echo "#	Running crsp_delete_tsecmemb_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_tsecmemb_by_ididx.sql
echo "#	Running crsp_delete_tsecmemb_by_tenantidx.sql ..."
db2 -l db2output.log -f crsp_delete_tsecmemb_by_tenantidx.sql
echo "#	Running crsp_delete_tsecmemb_by_groupidx.sql ..."
db2 -l db2output.log -f crsp_delete_tsecmemb_by_groupidx.sql
echo "#	Running crsp_delete_tsecmemb_by_useridx.sql ..."
db2 -l db2output.log -f crsp_delete_tsecmemb_by_useridx.sql
echo "#	Running crsp_delete_tsecmemb_by_uuseridx.sql ..."
db2 -l db2output.log -f crsp_delete_tsecmemb_by_uuseridx.sql

echo "#	Running crsp_delete_tenant_by_ididx.sql ..."
db2 -l db2output.log -f crsp_delete_tenant_by_ididx.sql
echo "#	Running crsp_delete_tenant_by_clusteridx.sql ..."
db2 -l db2output.log -f crsp_delete_tenant_by_clusteridx.sql
echo "#	Running crsp_delete_tenant_by_unameidx.sql ..."
db2 -l db2output.log -f crsp_delete_tenant_by_unameidx.sql

echo "#	Running crsp_delete_clus.sql ..."
db2 -l db2output.log -f crsp_delete_clus.sql

echo "#	Running crsp_delete_hostnode.sql ..."
db2 -l db2output.log -f crsp_delete_hostnode.sql

echo "#	Running crsp_delete_iso_ccy.sql ..."
db2 -l db2output.log -f crsp_delete_iso_ccy.sql

echo "#	Running crsp_delete_iso_cntry.sql ..."
db2 -l db2output.log -f crsp_delete_iso_cntry.sql

echo "#	Running crsp_delete_iso_cntryccy.sql ..."
db2 -l db2output.log -f crsp_delete_iso_cntryccy.sql

echo "#	Running crsp_delete_iso_cntrylng.sql ..."
db2 -l db2output.log -f crsp_delete_iso_cntrylng.sql

echo "#	Running crsp_delete_iso_lang.sql ..."
db2 -l db2output.log -f crsp_delete_iso_lang.sql

echo "#	Running crsp_delete_isotz.sql ..."
db2 -l db2output.log -f crsp_delete_isotz.sql

echo "#	Running crsp_delete_secapp.sql ..."
db2 -l db2output.log -f crsp_delete_secapp.sql

echo "#	Running crsp_delete_secdev.sql ..."
db2 -l db2output.log -f crsp_delete_secdev.sql

echo "#	Running crsp_delete_secform.sql ..."
db2 -l db2output.log -f crsp_delete_secform.sql

echo "#	Running crsp_delete_secgrp.sql ..."
db2 -l db2output.log -f crsp_delete_secgrp.sql

echo "#	Running crsp_delete_secgrpfrm.sql ..."
db2 -l db2output.log -f crsp_delete_secgrpfrm.sql

echo "#	Running crsp_delete_secinc.sql ..."
db2 -l db2output.log -f crsp_delete_secinc.sql

echo "#	Running crsp_delete_secmemb.sql ..."
db2 -l db2output.log -f crsp_delete_secmemb.sql

echo "#	Running crsp_delete_secsess.sql ..."
db2 -l db2output.log -f crsp_delete_secsess.sql

echo "#	Running crsp_delete_secuser.sql ..."
db2 -l db2output.log -f crsp_delete_secuser.sql

echo "#	Running crsp_delete_hostsvc.sql ..."
db2 -l db2output.log -f crsp_delete_hostsvc.sql

echo "#	Running crsp_delete_svctype.sql ..."
db2 -l db2output.log -f crsp_delete_svctype.sql

echo "#	Running crsp_delete_sysclus.sql ..."
db2 -l db2output.log -f crsp_delete_sysclus.sql

echo "#	Running crsp_delete_tsecgrp.sql ..."
db2 -l db2output.log -f crsp_delete_tsecgrp.sql

echo "#	Running crsp_delete_tsecinc.sql ..."
db2 -l db2output.log -f crsp_delete_tsecinc.sql

echo "#	Running crsp_delete_tsecmemb.sql ..."
db2 -l db2output.log -f crsp_delete_tsecmemb.sql

echo "#	Running crsp_delete_tenant.sql ..."
db2 -l db2output.log -f crsp_delete_tenant.sql


