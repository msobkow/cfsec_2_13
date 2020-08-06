--
--	@(#) dbcreate/cfsec/pgsql/reorg_cfsec213.pgsql
--
--	org.msscf.msscf.CFSec
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	MSS Code Factory CFSec 2.13 Security Essentials
--	
--	Copyright 2020 Mark Stephen Sobkow
--	
--		This file is part of MSS Code Factory.
--	
--		MSS Code Factory is available under dual commercial license from Mark Stephen
--		Sobkow, or under the terms of the GNU General Public License, Version 3
--		or later.
--	
--	    MSS Code Factory is free software: you can redistribute it and/or modify
--	    it under the terms of the GNU General Public License as published by
--	    the Free Software Foundation, either version 3 of the License, or
--	    (at your option) any later version.
--	
--	    MSS Code Factory is distributed in the hope that it will be useful,
--	    but WITHOUT ANY WARRANTY; without even the implied warranty of
--	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--	    GNU General Public License for more details.
--	
--	    You should have received a copy of the GNU General Public License
--	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
--	
--	Donations to support MSS Code Factory can be made at
--	https://www.paypal.com/paypalme2/MarkSobkow
--	
--	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
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

