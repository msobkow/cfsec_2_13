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

#include <cfsecobj/ICFSecTSecGrpMembObj.hpp>
#include <cfsecobj/ICFSecTSecGrpMembEditObj.hpp>

namespace cfsec {

	class ICFSecTSecGrpMembTableObj
	{
	public:
		ICFSecTSecGrpMembTableObj();
		virtual ~ICFSecTSecGrpMembTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema() = 0;
		virtual void setSchema( cfsec::ICFSecSchemaObj* value ) = 0;

		virtual void minimizeMemory() = 0;

		virtual const std::string getTableName() = 0;
		virtual const std::string getTableDbName() = 0;
		virtual const classcode_t* getObjQualifyingClassCode() = 0;

		virtual cfsec::ICFSecTSecGrpMembObj* newInstance() = 0;

		virtual cfsec::ICFSecTSecGrpMembEditObj* newEditInstance( cfsec::ICFSecTSecGrpMembObj* orig ) = 0;

		virtual cfsec::ICFSecTSecGrpMembObj* realizeTSecGrpMemb( cfsec::ICFSecTSecGrpMembObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpMembId ) = 0;
		virtual void deepDisposeByTenantIdx( const int64_t TenantId ) = 0;
		virtual void deepDisposeByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId ) = 0;
		virtual void deepDisposeByUserIdx( const uuid_ptr_t SecUserId ) = 0;
		virtual void deepDisposeByUUserIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const uuid_ptr_t SecUserId ) = 0;
		virtual void reallyDeepDisposeTSecGrpMemb( cfsec::ICFSecTSecGrpMembObj* Obj ) = 0;
		virtual cfsec::ICFSecTSecGrpMembObj* createTSecGrpMemb( cfsec::ICFSecTSecGrpMembEditObj* Obj ) = 0;

		virtual cfsec::ICFSecTSecGrpMembObj* readTSecGrpMemb( cfsec::CFSecTSecGrpMembPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecTSecGrpMembObj* lockTSecGrpMemb( cfsec::CFSecTSecGrpMembPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readAllTSecGrpMemb( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> pageAllTSecGrpMemb(const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId ) = 0;

		virtual cfsec::ICFSecTSecGrpMembObj* readTSecGrpMembByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpMembId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readTSecGrpMembByTenantIdx( const int64_t TenantId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readTSecGrpMembByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readTSecGrpMembByUserIdx( const uuid_ptr_t SecUserId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecTSecGrpMembObj* readTSecGrpMembByUUserIdx(const int64_t TenantId,
			const int32_t TSecGroupId,
			const uuid_ptr_t SecUserId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecTSecGrpMembObj* readCachedTSecGrpMemb( cfsec::CFSecTSecGrpMembPKey* pkey ) = 0;

		virtual cfsec::ICFSecTSecGrpMembObj* readCachedTSecGrpMembByIdIdx(const int64_t TenantId,
			const int64_t TSecGrpMembId ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readCachedTSecGrpMembByTenantIdx( const int64_t TenantId ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readCachedTSecGrpMembByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readCachedTSecGrpMembByUserIdx( const uuid_ptr_t SecUserId ) = 0;

		virtual cfsec::ICFSecTSecGrpMembObj* readCachedTSecGrpMembByUUserIdx(const int64_t TenantId,
			const int32_t TSecGroupId,
			const uuid_ptr_t SecUserId ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> pageTSecGrpMembByTenantIdx( const int64_t TenantId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> pageTSecGrpMembByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> pageTSecGrpMembByUserIdx( const uuid_ptr_t SecUserId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId ) = 0;

		virtual cfsec::ICFSecTSecGrpMembObj* updateTSecGrpMemb( cfsec::ICFSecTSecGrpMembEditObj* Obj ) = 0;

		virtual void deleteTSecGrpMemb( cfsec::ICFSecTSecGrpMembEditObj* Obj ) = 0;

		virtual void deleteTSecGrpMembByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpMembId ) = 0;

		virtual void deleteTSecGrpMembByTenantIdx( const int64_t TenantId ) = 0;

		virtual void deleteTSecGrpMembByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId ) = 0;

		virtual void deleteTSecGrpMembByUserIdx( const uuid_ptr_t SecUserId ) = 0;

		virtual void deleteTSecGrpMembByUUserIdx(const int64_t TenantId,
			const int32_t TSecGroupId,
			const uuid_ptr_t SecUserId ) = 0;

		virtual void reallyDetachFromIndexesTSecGrpMemb( cfsec::ICFSecTSecGrpMembObj* Obj ) = 0;

	};
}
