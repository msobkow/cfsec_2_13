#pragma once

// Description: C++18 Table Object specification for CFSec.

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

#include <cfsecobj/ICFSecTSecGroupObj.hpp>
#include <cfsecobj/ICFSecTSecGroupEditObj.hpp>
#include <cfsecobj/ICFSecTSecGroupTableObj.hpp>

namespace cfsec {

	class CFSecTSecGroupTableObj
	: public virtual ICFSecTSecGroupTableObj
	{
	protected:
		cfsec::ICFSecSchemaObj* schema;
		std::map<cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>* members;
		std::map<cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>* allTSecGroup;
		std::map< cfsec::CFSecTSecGroupByTenantIdxKey,
			std::map<cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>*>* indexByTenantIdx;
		std::map< cfsec::CFSecTSecGroupByTenantVisIdxKey,
			std::map<cfsec::CFSecTSecGroupPKey, cfsec::ICFSecTSecGroupObj*>*>* indexByTenantVisIdx;
		std::map< cfsec::CFSecTSecGroupByUNameIdxKey,
			cfsec::ICFSecTSecGroupObj*>* indexByUNameIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFSecTSecGroupTableObj();
		CFSecTSecGroupTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFSecTSecGroupTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecTSecGroupObj* newInstance();

		virtual cfsec::ICFSecTSecGroupEditObj* newEditInstance( cfsec::ICFSecTSecGroupObj* orig );

		virtual cfsec::ICFSecTSecGroupObj* realizeTSecGroup( cfsec::ICFSecTSecGroupObj* Obj );

		virtual void deepDisposeByIdIdx( const int64_t TenantId,
			const int32_t TSecGroupId );
		virtual void deepDisposeByTenantIdx( const int64_t TenantId );
		virtual void deepDisposeByTenantVisIdx( const int64_t TenantId,
			const bool IsVisible );
		virtual void deepDisposeByUNameIdx( const int64_t TenantId,
			const std::string& Name );
		virtual void reallyDeepDisposeTSecGroup( cfsec::ICFSecTSecGroupObj* Obj );
		virtual cfsec::ICFSecTSecGroupObj* createTSecGroup( cfsec::ICFSecTSecGroupEditObj* Obj );

		virtual cfsec::ICFSecTSecGroupObj* readTSecGroup( cfsec::CFSecTSecGroupPKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecTSecGroupObj* lockTSecGroup( cfsec::CFSecTSecGroupPKey* pkey );

		virtual std::vector<cfsec::ICFSecTSecGroupObj*> readAllTSecGroup( bool forceRead = false );

		virtual cfsec::ICFSecTSecGroupObj* readTSecGroupByIdIdx( const int64_t TenantId,
			const int32_t TSecGroupId, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecTSecGroupObj*> readTSecGroupByTenantIdx( const int64_t TenantId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecTSecGroupObj*> readTSecGroupByTenantVisIdx( const int64_t TenantId,
			const bool IsVisible,
			bool forceRead = false );

		virtual cfsec::ICFSecTSecGroupObj* readTSecGroupByUNameIdx( const int64_t TenantId,
			const std::string& Name, bool forceRead = false );

		virtual cfsec::ICFSecTSecGroupObj* readCachedTSecGroup( cfsec::CFSecTSecGroupPKey* pkey );

		virtual cfsec::ICFSecTSecGroupObj* readCachedTSecGroupByIdIdx( const int64_t TenantId,
			const int32_t TSecGroupId );

		virtual std::vector<cfsec::ICFSecTSecGroupObj*> readCachedTSecGroupByTenantIdx( const int64_t TenantId );

		virtual std::vector<cfsec::ICFSecTSecGroupObj*> readCachedTSecGroupByTenantVisIdx( const int64_t TenantId,
			const bool IsVisible );

		virtual cfsec::ICFSecTSecGroupObj* readCachedTSecGroupByUNameIdx( const int64_t TenantId,
			const std::string& Name );

		virtual cfsec::ICFSecTSecGroupObj* readTSecGroupByLookupUNameIdx( const int64_t TenantId,
			const std::string& Name, bool forceRead = false );

		virtual cfsec::ICFSecTSecGroupObj* readCachedTSecGroupByLookupUNameIdx( const int64_t TenantId,
			const std::string& Name );

		virtual cfsec::ICFSecTSecGroupObj* updateTSecGroup( cfsec::ICFSecTSecGroupEditObj* Obj );

		virtual void deleteTSecGroup( cfsec::ICFSecTSecGroupEditObj* Obj );

		virtual void deleteTSecGroupByIdIdx( const int64_t TenantId,
			const int32_t TSecGroupId );

		virtual void deleteTSecGroupByTenantIdx( const int64_t TenantId );

		virtual void deleteTSecGroupByTenantVisIdx( const int64_t TenantId,
			const bool IsVisible );

		virtual void deleteTSecGroupByUNameIdx( const int64_t TenantId,
			const std::string& Name );

		virtual void reallyDetachFromIndexesTSecGroup( cfsec::ICFSecTSecGroupObj* Obj );

	};

}
