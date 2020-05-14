--
--	@(#) dbcreate/cfsec/db2luw/reorg_cfsec213.sql
--
--	com.github.msobkow.CFSec
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	This file is part of MSS Code Factory.
--	
--	Licensed under the Apache License, Version 2.0 (the "License");
--	you may not use this file except in compliance with the License.
--	You may obtain a copy of the License at
--	
--	    http://www.apache.org/licenses/LICENSE-2.0
--	
--	Unless required by applicable law or agreed to in writing, software
--	distributed under the License is distributed on an "AS IS" BASIS,
--	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
--	See the License for the specific language governing permissions and
--	limitations under the License.
--	
--	Donations to support MSS Code Factory can be made at
--	https://www.paypal.com/paypalme2/MarkSobkow
--
--	Manufactured by MSS Code Factory 2.12
--
REORG TABLE CFSec213.clus index CFSec213.cluster_pk
REORG TABLE CFSec213.HostNode index CFSec213.HostNode_pidx
REORG TABLE CFSec213.iso_ccy index CFSec213.isocurrency_pk
REORG TABLE CFSec213.iso_cntry index CFSec213.isocountry_pk
REORG TABLE CFSec213.iso_cntryccy index CFSec213.isocountryccy_pk
REORG TABLE CFSec213.iso_cntrylng index CFSec213.isocountrylang_pk
REORG TABLE CFSec213.iso_lang index CFSec213.isolang_pk
REORG TABLE CFSec213.ISOTz index CFSec213.ITz_pidx
REORG TABLE CFSec213.SecApp index CFSec213.SecApp_pidx
REORG TABLE CFSec213.SecDev index CFSec213.SecDev_pidx
REORG TABLE CFSec213.SecForm index CFSec213.SecForm_pidx
REORG TABLE CFSec213.SecGrp index CFSec213.SecGroup_pidx
REORG TABLE CFSec213.SecGrpFrm index CFSec213.SecGroupForm_pidx
REORG TABLE CFSec213.SecInc index CFSec213.SecInclude_pidx
REORG TABLE CFSec213.SecMemb index CFSec213.SecMember_pidx
REORG TABLE CFSec213.SecSess index CFSec213.Session_pidx
REORG TABLE CFSec213.SecUser index CFSec213.SecUser_pidx
REORG TABLE CFSec213.HostSvc index CFSec213.Service_pidx
REORG TABLE CFSec213.SvcType index CFSec213.ServiceType_pidx
REORG TABLE CFSec213.sysclus index CFSec213.syscluster_pk
REORG TABLE CFSec213.TSecGrp index CFSec213.TSecGroup_pidx
REORG TABLE CFSec213.TSecInc index CFSec213.TSecInclude_pidx
REORG TABLE CFSec213.TSecMemb index CFSec213.TSecMember_pidx
REORG TABLE CFSec213.tenant index CFSec213.tenant_pk

commit
