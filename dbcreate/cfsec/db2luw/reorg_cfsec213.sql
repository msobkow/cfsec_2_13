--
--	@(#) dbcreate/cfsec/db2luw/reorg_cfsec213.sql
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
