#pragma once

// Description: C++18 Public object interface for CFSec.

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

#include <cfsec/ICFSecPublic.hpp>


namespace cfsec {
	class ICFSecSchemaObj;
	class ICFSecClusterObj;
	class ICFSecClusterEditObj;
	class ICFSecClusterTableObj;
	class ICFSecHostNodeObj;
	class ICFSecHostNodeEditObj;
	class ICFSecHostNodeTableObj;
	class ICFSecISOCcyObj;
	class ICFSecISOCcyEditObj;
	class ICFSecISOCcyTableObj;
	class ICFSecISOCtryObj;
	class ICFSecISOCtryEditObj;
	class ICFSecISOCtryTableObj;
	class ICFSecISOCtryCcyObj;
	class ICFSecISOCtryCcyEditObj;
	class ICFSecISOCtryCcyTableObj;
	class ICFSecISOCtryLangObj;
	class ICFSecISOCtryLangEditObj;
	class ICFSecISOCtryLangTableObj;
	class ICFSecISOLangObj;
	class ICFSecISOLangEditObj;
	class ICFSecISOLangTableObj;
	class ICFSecISOTZoneObj;
	class ICFSecISOTZoneEditObj;
	class ICFSecISOTZoneTableObj;
	class ICFSecSecAppObj;
	class ICFSecSecAppEditObj;
	class ICFSecSecAppTableObj;
	class ICFSecSecDeviceObj;
	class ICFSecSecDeviceEditObj;
	class ICFSecSecDeviceTableObj;
	class ICFSecSecFormObj;
	class ICFSecSecFormEditObj;
	class ICFSecSecFormTableObj;
	class ICFSecSecGroupObj;
	class ICFSecSecGroupEditObj;
	class ICFSecSecGroupTableObj;
	class ICFSecSecGroupFormObj;
	class ICFSecSecGroupFormEditObj;
	class ICFSecSecGroupFormTableObj;
	class ICFSecSecGrpIncObj;
	class ICFSecSecGrpIncEditObj;
	class ICFSecSecGrpIncTableObj;
	class ICFSecSecGrpMembObj;
	class ICFSecSecGrpMembEditObj;
	class ICFSecSecGrpMembTableObj;
	class ICFSecSecSessionObj;
	class ICFSecSecSessionEditObj;
	class ICFSecSecSessionTableObj;
	class ICFSecSecUserObj;
	class ICFSecSecUserEditObj;
	class ICFSecSecUserTableObj;
	class ICFSecServiceObj;
	class ICFSecServiceEditObj;
	class ICFSecServiceTableObj;
	class ICFSecServiceTypeObj;
	class ICFSecServiceTypeEditObj;
	class ICFSecServiceTypeTableObj;
	class ICFSecSysClusterObj;
	class ICFSecSysClusterEditObj;
	class ICFSecSysClusterTableObj;
	class ICFSecTSecGroupObj;
	class ICFSecTSecGroupEditObj;
	class ICFSecTSecGroupTableObj;
	class ICFSecTSecGrpIncObj;
	class ICFSecTSecGrpIncEditObj;
	class ICFSecTSecGrpIncTableObj;
	class ICFSecTSecGrpMembObj;
	class ICFSecTSecGrpMembEditObj;
	class ICFSecTSecGrpMembTableObj;
	class ICFSecTenantObj;
	class ICFSecTenantEditObj;
	class ICFSecTenantTableObj;
}

#include <cfsecobj/ICFSecSchemaObj.hpp>

#include <cfsecobj/ICFSecClusterObj.hpp>
#include <cfsecobj/ICFSecHostNodeObj.hpp>
#include <cfsecobj/ICFSecISOCcyObj.hpp>
#include <cfsecobj/ICFSecISOCtryObj.hpp>
#include <cfsecobj/ICFSecISOCtryCcyObj.hpp>
#include <cfsecobj/ICFSecISOCtryLangObj.hpp>
#include <cfsecobj/ICFSecISOLangObj.hpp>
#include <cfsecobj/ICFSecISOTZoneObj.hpp>
#include <cfsecobj/ICFSecSecAppObj.hpp>
#include <cfsecobj/ICFSecSecDeviceObj.hpp>
#include <cfsecobj/ICFSecSecFormObj.hpp>
#include <cfsecobj/ICFSecSecGroupObj.hpp>
#include <cfsecobj/ICFSecSecGroupFormObj.hpp>
#include <cfsecobj/ICFSecSecGrpIncObj.hpp>
#include <cfsecobj/ICFSecSecGrpMembObj.hpp>
#include <cfsecobj/ICFSecSecSessionObj.hpp>
#include <cfsecobj/ICFSecSecUserObj.hpp>
#include <cfsecobj/ICFSecServiceObj.hpp>
#include <cfsecobj/ICFSecServiceTypeObj.hpp>
#include <cfsecobj/ICFSecSysClusterObj.hpp>
#include <cfsecobj/ICFSecTSecGroupObj.hpp>
#include <cfsecobj/ICFSecTSecGrpIncObj.hpp>
#include <cfsecobj/ICFSecTSecGrpMembObj.hpp>
#include <cfsecobj/ICFSecTenantObj.hpp>

#include <cfsecobj/ICFSecClusterEditObj.hpp>
#include <cfsecobj/ICFSecHostNodeEditObj.hpp>
#include <cfsecobj/ICFSecISOCcyEditObj.hpp>
#include <cfsecobj/ICFSecISOCtryEditObj.hpp>
#include <cfsecobj/ICFSecISOCtryCcyEditObj.hpp>
#include <cfsecobj/ICFSecISOCtryLangEditObj.hpp>
#include <cfsecobj/ICFSecISOLangEditObj.hpp>
#include <cfsecobj/ICFSecISOTZoneEditObj.hpp>
#include <cfsecobj/ICFSecSecAppEditObj.hpp>
#include <cfsecobj/ICFSecSecDeviceEditObj.hpp>
#include <cfsecobj/ICFSecSecFormEditObj.hpp>
#include <cfsecobj/ICFSecSecGroupEditObj.hpp>
#include <cfsecobj/ICFSecSecGroupFormEditObj.hpp>
#include <cfsecobj/ICFSecSecGrpIncEditObj.hpp>
#include <cfsecobj/ICFSecSecGrpMembEditObj.hpp>
#include <cfsecobj/ICFSecSecSessionEditObj.hpp>
#include <cfsecobj/ICFSecSecUserEditObj.hpp>
#include <cfsecobj/ICFSecServiceEditObj.hpp>
#include <cfsecobj/ICFSecServiceTypeEditObj.hpp>
#include <cfsecobj/ICFSecSysClusterEditObj.hpp>
#include <cfsecobj/ICFSecTSecGroupEditObj.hpp>
#include <cfsecobj/ICFSecTSecGrpIncEditObj.hpp>
#include <cfsecobj/ICFSecTSecGrpMembEditObj.hpp>
#include <cfsecobj/ICFSecTenantEditObj.hpp>

#include <cfsecobj/ICFSecClusterTableObj.hpp>
#include <cfsecobj/ICFSecHostNodeTableObj.hpp>
#include <cfsecobj/ICFSecISOCcyTableObj.hpp>
#include <cfsecobj/ICFSecISOCtryTableObj.hpp>
#include <cfsecobj/ICFSecISOCtryCcyTableObj.hpp>
#include <cfsecobj/ICFSecISOCtryLangTableObj.hpp>
#include <cfsecobj/ICFSecISOLangTableObj.hpp>
#include <cfsecobj/ICFSecISOTZoneTableObj.hpp>
#include <cfsecobj/ICFSecSecAppTableObj.hpp>
#include <cfsecobj/ICFSecSecDeviceTableObj.hpp>
#include <cfsecobj/ICFSecSecFormTableObj.hpp>
#include <cfsecobj/ICFSecSecGroupTableObj.hpp>
#include <cfsecobj/ICFSecSecGroupFormTableObj.hpp>
#include <cfsecobj/ICFSecSecGrpIncTableObj.hpp>
#include <cfsecobj/ICFSecSecGrpMembTableObj.hpp>
#include <cfsecobj/ICFSecSecSessionTableObj.hpp>
#include <cfsecobj/ICFSecSecUserTableObj.hpp>
#include <cfsecobj/ICFSecServiceTableObj.hpp>
#include <cfsecobj/ICFSecServiceTypeTableObj.hpp>
#include <cfsecobj/ICFSecSysClusterTableObj.hpp>
#include <cfsecobj/ICFSecTSecGroupTableObj.hpp>
#include <cfsecobj/ICFSecTSecGrpIncTableObj.hpp>
#include <cfsecobj/ICFSecTSecGrpMembTableObj.hpp>
#include <cfsecobj/ICFSecTenantTableObj.hpp>
