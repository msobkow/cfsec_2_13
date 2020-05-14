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

#include <cfsecobj/ICFSecSecSessionObj.hpp>
#include <cfsecobj/ICFSecSecSessionEditObj.hpp>

namespace cfsec {

	class ICFSecSecSessionTableObj
	{
	public:
		ICFSecSecSessionTableObj();
		virtual ~ICFSecSecSessionTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema() = 0;
		virtual void setSchema( cfsec::ICFSecSchemaObj* value ) = 0;

		virtual void minimizeMemory() = 0;

		virtual const std::string getTableName() = 0;
		virtual const std::string getTableDbName() = 0;
		virtual const classcode_t* getObjQualifyingClassCode() = 0;

		virtual cfsec::ICFSecSecSessionObj* newInstance() = 0;

		virtual cfsec::ICFSecSecSessionEditObj* newEditInstance( cfsec::ICFSecSecSessionObj* orig ) = 0;

		virtual cfsec::ICFSecSecSessionObj* realizeSecSession( cfsec::ICFSecSecSessionObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const uuid_ptr_t SecSessionId ) = 0;
		virtual void deepDisposeBySecUserIdx( const uuid_ptr_t SecUserId ) = 0;
		virtual void deepDisposeBySecDevIdx( const uuid_ptr_t SecUserId,
			const std::string* SecDevName ) = 0;
		virtual void deepDisposeByStartIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start ) = 0;
		virtual void deepDisposeByFinishIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish ) = 0;
		virtual void deepDisposeBySecProxyIdx( const uuid_ptr_t SecProxyId ) = 0;
		virtual void reallyDeepDisposeSecSession( cfsec::ICFSecSecSessionObj* Obj ) = 0;
		virtual cfsec::ICFSecSecSessionObj* createSecSession( cfsec::ICFSecSecSessionEditObj* Obj ) = 0;

		virtual cfsec::ICFSecSecSessionObj* readSecSession( cfsec::CFSecSecSessionPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecSessionObj* lockSecSession( cfsec::CFSecSecSessionPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readAllSecSession( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> pageAllSecSession(const uuid_ptr_t priorSecSessionId ) = 0;

		virtual cfsec::ICFSecSecSessionObj* readSecSessionByIdIdx( const uuid_ptr_t SecSessionId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readSecSessionBySecUserIdx( const uuid_ptr_t SecUserId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readSecSessionBySecDevIdx( const uuid_ptr_t SecUserId,
			const std::string* SecDevName,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecSessionObj* readSecSessionByStartIdx(const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readSecSessionByFinishIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readSecSessionBySecProxyIdx( const uuid_ptr_t SecProxyId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecSessionObj* readCachedSecSession( cfsec::CFSecSecSessionPKey* pkey ) = 0;

		virtual cfsec::ICFSecSecSessionObj* readCachedSecSessionByIdIdx(const uuid_ptr_t SecSessionId ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readCachedSecSessionBySecUserIdx( const uuid_ptr_t SecUserId ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readCachedSecSessionBySecDevIdx( const uuid_ptr_t SecUserId,
			const std::string* SecDevName ) = 0;

		virtual cfsec::ICFSecSecSessionObj* readCachedSecSessionByStartIdx(const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readCachedSecSessionByFinishIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readCachedSecSessionBySecProxyIdx( const uuid_ptr_t SecProxyId ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> pageSecSessionBySecUserIdx( const uuid_ptr_t SecUserId,
			const uuid_ptr_t priorSecSessionId ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> pageSecSessionBySecDevIdx( const uuid_ptr_t SecUserId,
			const std::string* SecDevName,
			const uuid_ptr_t priorSecSessionId ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> pageSecSessionByFinishIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish,
			const uuid_ptr_t priorSecSessionId ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> pageSecSessionBySecProxyIdx( const uuid_ptr_t SecProxyId,
			const uuid_ptr_t priorSecSessionId ) = 0;

		virtual cfsec::ICFSecSecSessionObj* updateSecSession( cfsec::ICFSecSecSessionEditObj* Obj ) = 0;

		virtual void deleteSecSession( cfsec::ICFSecSecSessionEditObj* Obj ) = 0;

		virtual void deleteSecSessionByIdIdx( const uuid_ptr_t SecSessionId ) = 0;

		virtual void deleteSecSessionBySecUserIdx( const uuid_ptr_t SecUserId ) = 0;

		virtual void deleteSecSessionBySecDevIdx( const uuid_ptr_t SecUserId,
			const std::string* SecDevName ) = 0;

		virtual void deleteSecSessionByStartIdx(const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start ) = 0;

		virtual void deleteSecSessionByFinishIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish ) = 0;

		virtual void deleteSecSessionBySecProxyIdx( const uuid_ptr_t SecProxyId ) = 0;

		virtual void reallyDetachFromIndexesSecSession( cfsec::ICFSecSecSessionObj* Obj ) = 0;

	virtual cfsec::ICFSecSecSessionObj* getSystemSession() = 0;

	};
}
