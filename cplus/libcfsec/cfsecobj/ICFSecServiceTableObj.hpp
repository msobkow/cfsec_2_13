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

#include <cfsecobj/ICFSecServiceObj.hpp>
#include <cfsecobj/ICFSecServiceEditObj.hpp>

namespace cfsec {

	class ICFSecServiceTableObj
	{
	public:
		ICFSecServiceTableObj();
		virtual ~ICFSecServiceTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema() = 0;
		virtual void setSchema( cfsec::ICFSecSchemaObj* value ) = 0;

		virtual void minimizeMemory() = 0;

		virtual const std::string getTableName() = 0;
		virtual const std::string getTableDbName() = 0;
		virtual const classcode_t* getObjQualifyingClassCode() = 0;

		virtual cfsec::ICFSecServiceObj* newInstance() = 0;

		virtual cfsec::ICFSecServiceEditObj* newEditInstance( cfsec::ICFSecServiceObj* orig ) = 0;

		virtual cfsec::ICFSecServiceObj* realizeService( cfsec::ICFSecServiceObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int64_t ClusterId,
			const int64_t ServiceId ) = 0;
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId ) = 0;
		virtual void deepDisposeByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId ) = 0;
		virtual void deepDisposeByTypeIdx( const int32_t ServiceTypeId ) = 0;
		virtual void deepDisposeByUTypeIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId ) = 0;
		virtual void deepDisposeByUHostPortIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort ) = 0;
		virtual void reallyDeepDisposeService( cfsec::ICFSecServiceObj* Obj ) = 0;
		virtual cfsec::ICFSecServiceObj* createService( cfsec::ICFSecServiceEditObj* Obj ) = 0;

		virtual cfsec::ICFSecServiceObj* readService( cfsec::CFSecServicePKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecServiceObj* lockService( cfsec::CFSecServicePKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecServiceObj*> readAllService( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecServiceObj*> pageAllService(const int64_t* priorClusterId,
			const int64_t* priorServiceId ) = 0;

		virtual cfsec::ICFSecServiceObj* readServiceByIdIdx( const int64_t ClusterId,
			const int64_t ServiceId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecServiceObj*> readServiceByClusterIdx( const int64_t ClusterId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecServiceObj*> readServiceByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecServiceObj*> readServiceByTypeIdx( const int32_t ServiceTypeId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecServiceObj* readServiceByUTypeIdx(const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecServiceObj* readServiceByUHostPortIdx(const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecServiceObj* readCachedService( cfsec::CFSecServicePKey* pkey ) = 0;

		virtual cfsec::ICFSecServiceObj* readCachedServiceByIdIdx(const int64_t ClusterId,
			const int64_t ServiceId ) = 0;

		virtual std::vector<cfsec::ICFSecServiceObj*> readCachedServiceByClusterIdx( const int64_t ClusterId ) = 0;

		virtual std::vector<cfsec::ICFSecServiceObj*> readCachedServiceByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId ) = 0;

		virtual std::vector<cfsec::ICFSecServiceObj*> readCachedServiceByTypeIdx( const int32_t ServiceTypeId ) = 0;

		virtual cfsec::ICFSecServiceObj* readCachedServiceByUTypeIdx(const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId ) = 0;

		virtual cfsec::ICFSecServiceObj* readCachedServiceByUHostPortIdx(const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort ) = 0;

		virtual std::vector<cfsec::ICFSecServiceObj*> pageServiceByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId ) = 0;

		virtual std::vector<cfsec::ICFSecServiceObj*> pageServiceByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId ) = 0;

		virtual std::vector<cfsec::ICFSecServiceObj*> pageServiceByTypeIdx( const int32_t ServiceTypeId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId ) = 0;

		virtual cfsec::ICFSecServiceObj* updateService( cfsec::ICFSecServiceEditObj* Obj ) = 0;

		virtual void deleteService( cfsec::ICFSecServiceEditObj* Obj ) = 0;

		virtual void deleteServiceByIdIdx( const int64_t ClusterId,
			const int64_t ServiceId ) = 0;

		virtual void deleteServiceByClusterIdx( const int64_t ClusterId ) = 0;

		virtual void deleteServiceByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId ) = 0;

		virtual void deleteServiceByTypeIdx( const int32_t ServiceTypeId ) = 0;

		virtual void deleteServiceByUTypeIdx(const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId ) = 0;

		virtual void deleteServiceByUHostPortIdx(const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort ) = 0;

		virtual void reallyDetachFromIndexesService( cfsec::ICFSecServiceObj* Obj ) = 0;

	};
}
