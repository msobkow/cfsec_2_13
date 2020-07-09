--
--	@(#) dbcreate/cfsec/oracle/reorg_cfsec213.plsql
--
--	org.msscf.msscf.CFSec
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
REORG TABLE cfsec213.clus index cfsec213.cluster_pk;
REORG TABLE cfsec213.HostNode index cfsec213.HostNode_pidx;
REORG TABLE cfsec213.iso_ccy index cfsec213.isocurrency_pk;
REORG TABLE cfsec213.iso_cntry index cfsec213.isocountry_pk;
REORG TABLE cfsec213.iso_cntryccy index cfsec213.isocountryccy_pk;
REORG TABLE cfsec213.iso_cntrylng index cfsec213.isocountrylang_pk;
REORG TABLE cfsec213.iso_lang index cfsec213.isolang_pk;
REORG TABLE cfsec213.ISOTz index cfsec213.ITz_pidx;
REORG TABLE cfsec213.SecApp index cfsec213.SecApp_pidx;
REORG TABLE cfsec213.SecDev index cfsec213.SecDev_pidx;
REORG TABLE cfsec213.SecForm index cfsec213.SecForm_pidx;
REORG TABLE cfsec213.SecGrp index cfsec213.SecGroup_pidx;
REORG TABLE cfsec213.SecGrpFrm index cfsec213.SecGroupForm_pidx;
REORG TABLE cfsec213.SecInc index cfsec213.SecInclude_pidx;
REORG TABLE cfsec213.SecMemb index cfsec213.SecMember_pidx;
REORG TABLE cfsec213.SecSess index cfsec213.Session_pidx;
REORG TABLE cfsec213.SecUser index cfsec213.SecUser_pidx;
REORG TABLE cfsec213.HostSvc index cfsec213.Service_pidx;
REORG TABLE cfsec213.SvcType index cfsec213.ServiceType_pidx;
REORG TABLE cfsec213.sysclus index cfsec213.syscluster_pk;
REORG TABLE cfsec213.TSecGrp index cfsec213.TSecGroup_pidx;
REORG TABLE cfsec213.TSecInc index cfsec213.TSecInclude_pidx;
REORG TABLE cfsec213.TSecMemb index cfsec213.TSecMember_pidx;
REORG TABLE cfsec213.tenant index cfsec213.tenant_pk;

