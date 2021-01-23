#pragma once

// Description: C++18 interface for a CFSec public invoker.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow
 *	
 *		This file is part of MSS Code Factory.
 *	
 *		MSS Code Factory is available under dual commercial license from Mark Stephen
 *		Sobkow, or under the terms of the GNU General Public License, Version 3
 *		or later.
 *	
 *	    MSS Code Factory is free software: you can redistribute it and/or modify
 *	    it under the terms of the GNU General Public License as published by
 *	    the Free Software Foundation, either version 3 of the License, or
 *	    (at your option) any later version.
 *	
 *	    MSS Code Factory is distributed in the hope that it will be useful,
 *	    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	    GNU General Public License for more details.
 *	
 *	    You should have received a copy of the GNU General Public License
 *	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
 *	
 *	Please contact Mark Stephen Sobkow at mark.sobkow@gmail.com for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <uuid/uuid.h>

#include <array>
#include <cassert>
#include <cstddef>
#include <chrono>
#include <ctime>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <vector>

#include <cflib/ICFLibPublic.hpp>

namespace cfsec {

	class CFSecClusterPKey;
	class CFSecHostNodePKey;
	class CFSecISOCcyPKey;
	class CFSecISOCtryPKey;
	class CFSecISOCtryCcyPKey;
	class CFSecISOCtryLangPKey;
	class CFSecISOLangPKey;
	class CFSecISOTZonePKey;
	class CFSecSecAppPKey;
	class CFSecSecDevicePKey;
	class CFSecSecFormPKey;
	class CFSecSecGroupPKey;
	class CFSecSecGroupFormPKey;
	class CFSecSecGrpIncPKey;
	class CFSecSecGrpMembPKey;
	class CFSecSecSessionPKey;
	class CFSecSecUserPKey;
	class CFSecServicePKey;
	class CFSecServiceTypePKey;
	class CFSecSysClusterPKey;
	class CFSecTSecGroupPKey;
	class CFSecTSecGrpIncPKey;
	class CFSecTSecGrpMembPKey;
	class CFSecTenantPKey;

	class CFSecClusterHPKey;
	class CFSecHostNodeHPKey;
	class CFSecISOCcyHPKey;
	class CFSecISOCtryHPKey;
	class CFSecISOCtryCcyHPKey;
	class CFSecISOCtryLangHPKey;
	class CFSecISOLangHPKey;
	class CFSecISOTZoneHPKey;
	class CFSecSecAppHPKey;
	class CFSecSecDeviceHPKey;
	class CFSecSecFormHPKey;
	class CFSecSecGroupHPKey;
	class CFSecSecGroupFormHPKey;
	class CFSecSecGrpIncHPKey;
	class CFSecSecGrpMembHPKey;
	class CFSecSecUserHPKey;
	class CFSecServiceHPKey;
	class CFSecServiceTypeHPKey;
	class CFSecTSecGroupHPKey;
	class CFSecTSecGrpIncHPKey;
	class CFSecTSecGrpMembHPKey;
	class CFSecTenantHPKey;

	class CFSecClusterBuff;
	class CFSecHostNodeBuff;
	class CFSecISOCcyBuff;
	class CFSecISOCtryBuff;
	class CFSecISOCtryCcyBuff;
	class CFSecISOCtryLangBuff;
	class CFSecISOLangBuff;
	class CFSecISOTZoneBuff;
	class CFSecSecAppBuff;
	class CFSecSecDeviceBuff;
	class CFSecSecFormBuff;
	class CFSecSecGroupBuff;
	class CFSecSecGroupFormBuff;
	class CFSecSecGrpIncBuff;
	class CFSecSecGrpMembBuff;
	class CFSecSecSessionBuff;
	class CFSecSecUserBuff;
	class CFSecServiceBuff;
	class CFSecServiceTypeBuff;
	class CFSecSysClusterBuff;
	class CFSecTSecGroupBuff;
	class CFSecTSecGrpIncBuff;
	class CFSecTSecGrpMembBuff;
	class CFSecTenantBuff;

	class CFSecClusterHBuff;
	class CFSecHostNodeHBuff;
	class CFSecISOCcyHBuff;
	class CFSecISOCtryHBuff;
	class CFSecISOCtryCcyHBuff;
	class CFSecISOCtryLangHBuff;
	class CFSecISOLangHBuff;
	class CFSecISOTZoneHBuff;
	class CFSecSecAppHBuff;
	class CFSecSecDeviceHBuff;
	class CFSecSecFormHBuff;
	class CFSecSecGroupHBuff;
	class CFSecSecGroupFormHBuff;
	class CFSecSecGrpIncHBuff;
	class CFSecSecGrpMembHBuff;
	class CFSecSecUserHBuff;
	class CFSecServiceHBuff;
	class CFSecServiceTypeHBuff;
	class CFSecTSecGroupHBuff;
	class CFSecTSecGrpIncHBuff;
	class CFSecTSecGrpMembHBuff;
	class CFSecTenantHBuff;

	class CFSecClusterByUDomNameIdxKey;
	class CFSecClusterByUDescrIdxKey;
	class CFSecHostNodeByClusterIdxKey;
	class CFSecHostNodeByUDescrIdxKey;
	class CFSecHostNodeByHostNameIdxKey;
	class CFSecISOCcyByCcyCdIdxKey;
	class CFSecISOCcyByCcyNmIdxKey;
	class CFSecISOCtryByISOCodeIdxKey;
	class CFSecISOCtryByNameIdxKey;
	class CFSecISOCtryCcyByCtryIdxKey;
	class CFSecISOCtryCcyByCcyIdxKey;
	class CFSecISOCtryLangByCtryIdxKey;
	class CFSecISOCtryLangByLangIdxKey;
	class CFSecISOLangByCode3IdxKey;
	class CFSecISOLangByCode2IdxKey;
	class CFSecISOTZoneByOffsetIdxKey;
	class CFSecISOTZoneByUTZNameIdxKey;
	class CFSecISOTZoneByIso8601IdxKey;
	class CFSecSecAppByClusterIdxKey;
	class CFSecSecAppByUJEEMountIdxKey;
	class CFSecSecDeviceByNameIdxKey;
	class CFSecSecDeviceByUserIdxKey;
	class CFSecSecFormByClusterIdxKey;
	class CFSecSecFormBySecAppIdxKey;
	class CFSecSecFormByUJEEServletIdxKey;
	class CFSecSecGroupByClusterIdxKey;
	class CFSecSecGroupByClusterVisIdxKey;
	class CFSecSecGroupByUNameIdxKey;
	class CFSecSecGroupFormByClusterIdxKey;
	class CFSecSecGroupFormByGroupIdxKey;
	class CFSecSecGroupFormByAppIdxKey;
	class CFSecSecGroupFormByFormIdxKey;
	class CFSecSecGroupFormByUFormIdxKey;
	class CFSecSecGrpIncByClusterIdxKey;
	class CFSecSecGrpIncByGroupIdxKey;
	class CFSecSecGrpIncByIncludeIdxKey;
	class CFSecSecGrpIncByUIncludeIdxKey;
	class CFSecSecGrpMembByClusterIdxKey;
	class CFSecSecGrpMembByGroupIdxKey;
	class CFSecSecGrpMembByUserIdxKey;
	class CFSecSecGrpMembByUUserIdxKey;
	class CFSecSecSessionBySecUserIdxKey;
	class CFSecSecSessionBySecDevIdxKey;
	class CFSecSecSessionByStartIdxKey;
	class CFSecSecSessionByFinishIdxKey;
	class CFSecSecSessionBySecProxyIdxKey;
	class CFSecSecUserByULoginIdxKey;
	class CFSecSecUserByEMConfIdxKey;
	class CFSecSecUserByPwdResetIdxKey;
	class CFSecSecUserByDefDevIdxKey;
	class CFSecServiceByClusterIdxKey;
	class CFSecServiceByHostIdxKey;
	class CFSecServiceByTypeIdxKey;
	class CFSecServiceByUTypeIdxKey;
	class CFSecServiceByUHostPortIdxKey;
	class CFSecServiceTypeByUDescrIdxKey;
	class CFSecSysClusterByClusterIdxKey;
	class CFSecTSecGroupByTenantIdxKey;
	class CFSecTSecGroupByTenantVisIdxKey;
	class CFSecTSecGroupByUNameIdxKey;
	class CFSecTSecGrpIncByTenantIdxKey;
	class CFSecTSecGrpIncByGroupIdxKey;
	class CFSecTSecGrpIncByIncludeIdxKey;
	class CFSecTSecGrpIncByUIncludeIdxKey;
	class CFSecTSecGrpMembByTenantIdxKey;
	class CFSecTSecGrpMembByGroupIdxKey;
	class CFSecTSecGrpMembByUserIdxKey;
	class CFSecTSecGrpMembByUUserIdxKey;
	class CFSecTenantByClusterIdxKey;
	class CFSecTenantByUNameIdxKey;

	class ICFSecClusterTable;
	class ICFSecHostNodeTable;
	class ICFSecISOCcyTable;
	class ICFSecISOCtryTable;
	class ICFSecISOCtryCcyTable;
	class ICFSecISOCtryLangTable;
	class ICFSecISOLangTable;
	class ICFSecISOTZoneTable;
	class ICFSecSecAppTable;
	class ICFSecSecDeviceTable;
	class ICFSecSecFormTable;
	class ICFSecSecGroupTable;
	class ICFSecSecGroupFormTable;
	class ICFSecSecGrpIncTable;
	class ICFSecSecGrpMembTable;
	class ICFSecSecSessionTable;
	class ICFSecSecUserTable;
	class ICFSecServiceTable;
	class ICFSecServiceTypeTable;
	class ICFSecSysClusterTable;
	class ICFSecTSecGroupTable;
	class ICFSecTSecGrpIncTable;
	class ICFSecTSecGrpMembTable;
	class ICFSecTenantTable;
}
#include <cfsec/ICFSecSchema.hpp>
#include <cfsec/CFSecAuthorization.hpp>
#include <cfsec/CFSecConfigurationFile.hpp>
#include <cfsec/ICFSecTablePerms.hpp>

#include <cfsec/CFSecClusterPKey.hpp>
#include <cfsec/CFSecHostNodePKey.hpp>
#include <cfsec/CFSecISOCcyPKey.hpp>
#include <cfsec/CFSecISOCtryPKey.hpp>
#include <cfsec/CFSecISOCtryCcyPKey.hpp>
#include <cfsec/CFSecISOCtryLangPKey.hpp>
#include <cfsec/CFSecISOLangPKey.hpp>
#include <cfsec/CFSecISOTZonePKey.hpp>
#include <cfsec/CFSecSecAppPKey.hpp>
#include <cfsec/CFSecSecDevicePKey.hpp>
#include <cfsec/CFSecSecFormPKey.hpp>
#include <cfsec/CFSecSecGroupPKey.hpp>
#include <cfsec/CFSecSecGroupFormPKey.hpp>
#include <cfsec/CFSecSecGrpIncPKey.hpp>
#include <cfsec/CFSecSecGrpMembPKey.hpp>
#include <cfsec/CFSecSecSessionPKey.hpp>
#include <cfsec/CFSecSecUserPKey.hpp>
#include <cfsec/CFSecServicePKey.hpp>
#include <cfsec/CFSecServiceTypePKey.hpp>
#include <cfsec/CFSecSysClusterPKey.hpp>
#include <cfsec/CFSecTSecGroupPKey.hpp>
#include <cfsec/CFSecTSecGrpIncPKey.hpp>
#include <cfsec/CFSecTSecGrpMembPKey.hpp>
#include <cfsec/CFSecTenantPKey.hpp>

#include <cfsec/CFSecClusterHPKey.hpp>
#include <cfsec/CFSecHostNodeHPKey.hpp>
#include <cfsec/CFSecISOCcyHPKey.hpp>
#include <cfsec/CFSecISOCtryHPKey.hpp>
#include <cfsec/CFSecISOCtryCcyHPKey.hpp>
#include <cfsec/CFSecISOCtryLangHPKey.hpp>
#include <cfsec/CFSecISOLangHPKey.hpp>
#include <cfsec/CFSecISOTZoneHPKey.hpp>
#include <cfsec/CFSecSecAppHPKey.hpp>
#include <cfsec/CFSecSecDeviceHPKey.hpp>
#include <cfsec/CFSecSecFormHPKey.hpp>
#include <cfsec/CFSecSecGroupHPKey.hpp>
#include <cfsec/CFSecSecGroupFormHPKey.hpp>
#include <cfsec/CFSecSecGrpIncHPKey.hpp>
#include <cfsec/CFSecSecGrpMembHPKey.hpp>
#include <cfsec/CFSecSecUserHPKey.hpp>
#include <cfsec/CFSecServiceHPKey.hpp>
#include <cfsec/CFSecServiceTypeHPKey.hpp>
#include <cfsec/CFSecTSecGroupHPKey.hpp>
#include <cfsec/CFSecTSecGrpIncHPKey.hpp>
#include <cfsec/CFSecTSecGrpMembHPKey.hpp>
#include <cfsec/CFSecTenantHPKey.hpp>

#include <cfsec/CFSecClusterBuff.hpp>
#include <cfsec/CFSecHostNodeBuff.hpp>
#include <cfsec/CFSecISOCcyBuff.hpp>
#include <cfsec/CFSecISOCtryBuff.hpp>
#include <cfsec/CFSecISOCtryCcyBuff.hpp>
#include <cfsec/CFSecISOCtryLangBuff.hpp>
#include <cfsec/CFSecISOLangBuff.hpp>
#include <cfsec/CFSecISOTZoneBuff.hpp>
#include <cfsec/CFSecSecAppBuff.hpp>
#include <cfsec/CFSecSecDeviceBuff.hpp>
#include <cfsec/CFSecSecFormBuff.hpp>
#include <cfsec/CFSecSecGroupBuff.hpp>
#include <cfsec/CFSecSecGroupFormBuff.hpp>
#include <cfsec/CFSecSecGrpIncBuff.hpp>
#include <cfsec/CFSecSecGrpMembBuff.hpp>
#include <cfsec/CFSecSecSessionBuff.hpp>
#include <cfsec/CFSecSecUserBuff.hpp>
#include <cfsec/CFSecServiceBuff.hpp>
#include <cfsec/CFSecServiceTypeBuff.hpp>
#include <cfsec/CFSecSysClusterBuff.hpp>
#include <cfsec/CFSecTSecGroupBuff.hpp>
#include <cfsec/CFSecTSecGrpIncBuff.hpp>
#include <cfsec/CFSecTSecGrpMembBuff.hpp>
#include <cfsec/CFSecTenantBuff.hpp>

#include <cfsec/CFSecClusterHBuff.hpp>
#include <cfsec/CFSecHostNodeHBuff.hpp>
#include <cfsec/CFSecISOCcyHBuff.hpp>
#include <cfsec/CFSecISOCtryHBuff.hpp>
#include <cfsec/CFSecISOCtryCcyHBuff.hpp>
#include <cfsec/CFSecISOCtryLangHBuff.hpp>
#include <cfsec/CFSecISOLangHBuff.hpp>
#include <cfsec/CFSecISOTZoneHBuff.hpp>
#include <cfsec/CFSecSecAppHBuff.hpp>
#include <cfsec/CFSecSecDeviceHBuff.hpp>
#include <cfsec/CFSecSecFormHBuff.hpp>
#include <cfsec/CFSecSecGroupHBuff.hpp>
#include <cfsec/CFSecSecGroupFormHBuff.hpp>
#include <cfsec/CFSecSecGrpIncHBuff.hpp>
#include <cfsec/CFSecSecGrpMembHBuff.hpp>
#include <cfsec/CFSecSecUserHBuff.hpp>
#include <cfsec/CFSecServiceHBuff.hpp>
#include <cfsec/CFSecServiceTypeHBuff.hpp>
#include <cfsec/CFSecTSecGroupHBuff.hpp>
#include <cfsec/CFSecTSecGrpIncHBuff.hpp>
#include <cfsec/CFSecTSecGrpMembHBuff.hpp>
#include <cfsec/CFSecTenantHBuff.hpp>

#include <cfsec/CFSecClusterByUDomNameIdxKey.hpp>
#include <cfsec/CFSecClusterByUDescrIdxKey.hpp>
#include <cfsec/CFSecHostNodeByClusterIdxKey.hpp>
#include <cfsec/CFSecHostNodeByUDescrIdxKey.hpp>
#include <cfsec/CFSecHostNodeByHostNameIdxKey.hpp>
#include <cfsec/CFSecISOCcyByCcyCdIdxKey.hpp>
#include <cfsec/CFSecISOCcyByCcyNmIdxKey.hpp>
#include <cfsec/CFSecISOCtryByISOCodeIdxKey.hpp>
#include <cfsec/CFSecISOCtryByNameIdxKey.hpp>
#include <cfsec/CFSecISOCtryCcyByCtryIdxKey.hpp>
#include <cfsec/CFSecISOCtryCcyByCcyIdxKey.hpp>
#include <cfsec/CFSecISOCtryLangByCtryIdxKey.hpp>
#include <cfsec/CFSecISOCtryLangByLangIdxKey.hpp>
#include <cfsec/CFSecISOLangByCode3IdxKey.hpp>
#include <cfsec/CFSecISOLangByCode2IdxKey.hpp>
#include <cfsec/CFSecISOTZoneByOffsetIdxKey.hpp>
#include <cfsec/CFSecISOTZoneByUTZNameIdxKey.hpp>
#include <cfsec/CFSecISOTZoneByIso8601IdxKey.hpp>
#include <cfsec/CFSecSecAppByClusterIdxKey.hpp>
#include <cfsec/CFSecSecAppByUJEEMountIdxKey.hpp>
#include <cfsec/CFSecSecDeviceByNameIdxKey.hpp>
#include <cfsec/CFSecSecDeviceByUserIdxKey.hpp>
#include <cfsec/CFSecSecFormByClusterIdxKey.hpp>
#include <cfsec/CFSecSecFormBySecAppIdxKey.hpp>
#include <cfsec/CFSecSecFormByUJEEServletIdxKey.hpp>
#include <cfsec/CFSecSecGroupByClusterIdxKey.hpp>
#include <cfsec/CFSecSecGroupByClusterVisIdxKey.hpp>
#include <cfsec/CFSecSecGroupByUNameIdxKey.hpp>
#include <cfsec/CFSecSecGroupFormByClusterIdxKey.hpp>
#include <cfsec/CFSecSecGroupFormByGroupIdxKey.hpp>
#include <cfsec/CFSecSecGroupFormByAppIdxKey.hpp>
#include <cfsec/CFSecSecGroupFormByFormIdxKey.hpp>
#include <cfsec/CFSecSecGroupFormByUFormIdxKey.hpp>
#include <cfsec/CFSecSecGrpIncByClusterIdxKey.hpp>
#include <cfsec/CFSecSecGrpIncByGroupIdxKey.hpp>
#include <cfsec/CFSecSecGrpIncByIncludeIdxKey.hpp>
#include <cfsec/CFSecSecGrpIncByUIncludeIdxKey.hpp>
#include <cfsec/CFSecSecGrpMembByClusterIdxKey.hpp>
#include <cfsec/CFSecSecGrpMembByGroupIdxKey.hpp>
#include <cfsec/CFSecSecGrpMembByUserIdxKey.hpp>
#include <cfsec/CFSecSecGrpMembByUUserIdxKey.hpp>
#include <cfsec/CFSecSecSessionBySecUserIdxKey.hpp>
#include <cfsec/CFSecSecSessionBySecDevIdxKey.hpp>
#include <cfsec/CFSecSecSessionByStartIdxKey.hpp>
#include <cfsec/CFSecSecSessionByFinishIdxKey.hpp>
#include <cfsec/CFSecSecSessionBySecProxyIdxKey.hpp>
#include <cfsec/CFSecSecUserByULoginIdxKey.hpp>
#include <cfsec/CFSecSecUserByEMConfIdxKey.hpp>
#include <cfsec/CFSecSecUserByPwdResetIdxKey.hpp>
#include <cfsec/CFSecSecUserByDefDevIdxKey.hpp>
#include <cfsec/CFSecServiceByClusterIdxKey.hpp>
#include <cfsec/CFSecServiceByHostIdxKey.hpp>
#include <cfsec/CFSecServiceByTypeIdxKey.hpp>
#include <cfsec/CFSecServiceByUTypeIdxKey.hpp>
#include <cfsec/CFSecServiceByUHostPortIdxKey.hpp>
#include <cfsec/CFSecServiceTypeByUDescrIdxKey.hpp>
#include <cfsec/CFSecSysClusterByClusterIdxKey.hpp>
#include <cfsec/CFSecTSecGroupByTenantIdxKey.hpp>
#include <cfsec/CFSecTSecGroupByTenantVisIdxKey.hpp>
#include <cfsec/CFSecTSecGroupByUNameIdxKey.hpp>
#include <cfsec/CFSecTSecGrpIncByTenantIdxKey.hpp>
#include <cfsec/CFSecTSecGrpIncByGroupIdxKey.hpp>
#include <cfsec/CFSecTSecGrpIncByIncludeIdxKey.hpp>
#include <cfsec/CFSecTSecGrpIncByUIncludeIdxKey.hpp>
#include <cfsec/CFSecTSecGrpMembByTenantIdxKey.hpp>
#include <cfsec/CFSecTSecGrpMembByGroupIdxKey.hpp>
#include <cfsec/CFSecTSecGrpMembByUserIdxKey.hpp>
#include <cfsec/CFSecTSecGrpMembByUUserIdxKey.hpp>
#include <cfsec/CFSecTenantByClusterIdxKey.hpp>
#include <cfsec/CFSecTenantByUNameIdxKey.hpp>

#include <cfsec/ICFSecClusterTable.hpp>
#include <cfsec/ICFSecHostNodeTable.hpp>
#include <cfsec/ICFSecISOCcyTable.hpp>
#include <cfsec/ICFSecISOCtryTable.hpp>
#include <cfsec/ICFSecISOCtryCcyTable.hpp>
#include <cfsec/ICFSecISOCtryLangTable.hpp>
#include <cfsec/ICFSecISOLangTable.hpp>
#include <cfsec/ICFSecISOTZoneTable.hpp>
#include <cfsec/ICFSecSecAppTable.hpp>
#include <cfsec/ICFSecSecDeviceTable.hpp>
#include <cfsec/ICFSecSecFormTable.hpp>
#include <cfsec/ICFSecSecGroupTable.hpp>
#include <cfsec/ICFSecSecGroupFormTable.hpp>
#include <cfsec/ICFSecSecGrpIncTable.hpp>
#include <cfsec/ICFSecSecGrpMembTable.hpp>
#include <cfsec/ICFSecSecSessionTable.hpp>
#include <cfsec/ICFSecSecUserTable.hpp>
#include <cfsec/ICFSecServiceTable.hpp>
#include <cfsec/ICFSecServiceTypeTable.hpp>
#include <cfsec/ICFSecSysClusterTable.hpp>
#include <cfsec/ICFSecTSecGroupTable.hpp>
#include <cfsec/ICFSecTSecGrpIncTable.hpp>
#include <cfsec/ICFSecTSecGrpMembTable.hpp>
#include <cfsec/ICFSecTenantTable.hpp>
