#pragma once

// Description: C++18 Table Object interface for CFSec.

/*
 *	com.github.msobkow.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	This file is part of MSS Code Factory.
 *	
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *	    http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <cflib/ICFLibPublic.hpp>
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

#include <cfsecobj/ICFSecTenantObj.hpp>
#include <cfsecobj/ICFSecTenantEditObj.hpp>

namespace cfsec {

	class ICFSecTenantTableObj
	{
	public:
		ICFSecTenantTableObj();
		virtual ~ICFSecTenantTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema() = 0;
		virtual void setSchema( cfsec::ICFSecSchemaObj* value ) = 0;

		virtual void minimizeMemory() = 0;

		virtual const std::string getTableName() = 0;
		virtual const std::string getTableDbName() = 0;
		virtual const classcode_t* getObjQualifyingClassCode() = 0;

		virtual cfsec::ICFSecTenantObj* newInstance() = 0;

		virtual cfsec::ICFSecTenantEditObj* newEditInstance( cfsec::ICFSecTenantObj* orig ) = 0;

		virtual cfsec::ICFSecTenantObj* realizeTenant( cfsec::ICFSecTenantObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int64_t Id ) = 0;
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId ) = 0;
		virtual void deepDisposeByUNameIdx( const int64_t ClusterId,
			const std::string& TenantName ) = 0;
		virtual void reallyDeepDisposeTenant( cfsec::ICFSecTenantObj* Obj ) = 0;
		virtual cfsec::ICFSecTenantObj* createTenant( cfsec::ICFSecTenantEditObj* Obj ) = 0;

		virtual cfsec::ICFSecTenantObj* readTenant( cfsec::CFSecTenantPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecTenantObj* lockTenant( cfsec::CFSecTenantPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecTenantObj*> readAllTenant( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecTenantObj*> pageAllTenant(const int64_t* priorId ) = 0;

		virtual cfsec::ICFSecTenantObj* readTenantByIdIdx( const int64_t Id,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecTenantObj*> readTenantByClusterIdx( const int64_t ClusterId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecTenantObj* readTenantByUNameIdx(const int64_t ClusterId,
			const std::string& TenantName,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecTenantObj* readCachedTenant( cfsec::CFSecTenantPKey* pkey ) = 0;

		virtual cfsec::ICFSecTenantObj* readCachedTenantByIdIdx(const int64_t Id ) = 0;

		virtual std::vector<cfsec::ICFSecTenantObj*> readCachedTenantByClusterIdx( const int64_t ClusterId ) = 0;

		virtual cfsec::ICFSecTenantObj* readCachedTenantByUNameIdx(const int64_t ClusterId,
			const std::string& TenantName ) = 0;

		virtual cfsec::ICFSecTenantObj* readTenantByLookupUNameIdx(const int64_t ClusterId,
			const std::string& TenantName,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecTenantObj* readCachedTenantByLookupUNameIdx(const int64_t ClusterId,
			const std::string& TenantName ) = 0;

		virtual std::vector<cfsec::ICFSecTenantObj*> pageTenantByClusterIdx( const int64_t ClusterId,
			const int64_t* priorId ) = 0;

		virtual cfsec::ICFSecTenantObj* updateTenant( cfsec::ICFSecTenantEditObj* Obj ) = 0;

		virtual void deleteTenant( cfsec::ICFSecTenantEditObj* Obj ) = 0;

		virtual void deleteTenantByIdIdx( const int64_t Id ) = 0;

		virtual void deleteTenantByClusterIdx( const int64_t ClusterId ) = 0;

		virtual void deleteTenantByUNameIdx(const int64_t ClusterId,
			const std::string& TenantName ) = 0;

		virtual void reallyDetachFromIndexesTenant( cfsec::ICFSecTenantObj* Obj ) = 0;

	virtual cfsec::ICFSecTenantObj* getSystemTenant() = 0;

	};
}
