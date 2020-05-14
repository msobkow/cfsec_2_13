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

#include <cfsecobj/ICFSecSecFormObj.hpp>
#include <cfsecobj/ICFSecSecFormEditObj.hpp>
#include <cfsecobj/ICFSecSecFormTableObj.hpp>

namespace cfsec {

	class CFSecSecFormTableObj
	: public virtual ICFSecSecFormTableObj
	{
	protected:
		cfsec::ICFSecSchemaObj* schema;
		std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* members;
		std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* allSecForm;
		std::map< cfsec::CFSecSecFormByClusterIdxKey,
			std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>*>* indexByClusterIdx;
		std::map< cfsec::CFSecSecFormBySecAppIdxKey,
			std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>*>* indexBySecAppIdx;
		std::map< cfsec::CFSecSecFormByUJEEServletIdxKey,
			cfsec::ICFSecSecFormObj*>* indexByUJEEServletIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFSecSecFormTableObj();
		CFSecSecFormTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFSecSecFormTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecSecFormObj* newInstance();

		virtual cfsec::ICFSecSecFormEditObj* newEditInstance( cfsec::ICFSecSecFormObj* orig );

		virtual cfsec::ICFSecSecFormObj* realizeSecForm( cfsec::ICFSecSecFormObj* Obj );

		virtual void deepDisposeByIdIdx( const int64_t ClusterId,
			const int32_t SecFormId );
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId );
		virtual void deepDisposeBySecAppIdx( const int64_t ClusterId,
			const int32_t SecAppId );
		virtual void deepDisposeByUJEEServletIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName );
		virtual void reallyDeepDisposeSecForm( cfsec::ICFSecSecFormObj* Obj );
		virtual cfsec::ICFSecSecFormObj* createSecForm( cfsec::ICFSecSecFormEditObj* Obj );

		virtual cfsec::ICFSecSecFormObj* readSecForm( cfsec::CFSecSecFormPKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecSecFormObj* lockSecForm( cfsec::CFSecSecFormPKey* pkey );

		virtual std::vector<cfsec::ICFSecSecFormObj*> readAllSecForm( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecFormObj*> pageAllSecForm(const int64_t* priorClusterId,
			const int32_t* priorSecFormId );

		virtual cfsec::ICFSecSecFormObj* readSecFormByIdIdx( const int64_t ClusterId,
			const int32_t SecFormId, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecFormObj*> readSecFormByClusterIdx( const int64_t ClusterId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecFormObj*> readSecFormBySecAppIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			bool forceRead = false );

		virtual cfsec::ICFSecSecFormObj* readSecFormByUJEEServletIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName, bool forceRead = false );

		virtual cfsec::ICFSecSecFormObj* readCachedSecForm( cfsec::CFSecSecFormPKey* pkey );

		virtual cfsec::ICFSecSecFormObj* readCachedSecFormByIdIdx( const int64_t ClusterId,
			const int32_t SecFormId );

		virtual std::vector<cfsec::ICFSecSecFormObj*> readCachedSecFormByClusterIdx( const int64_t ClusterId );

		virtual std::vector<cfsec::ICFSecSecFormObj*> readCachedSecFormBySecAppIdx( const int64_t ClusterId,
			const int32_t SecAppId );

		virtual cfsec::ICFSecSecFormObj* readCachedSecFormByUJEEServletIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName );

		virtual cfsec::ICFSecSecFormObj* readSecFormByLookupUJEEServletIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName, bool forceRead = false );

		virtual cfsec::ICFSecSecFormObj* readCachedSecFormByLookupUJEEServletIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName );

		virtual std::vector<cfsec::ICFSecSecFormObj*> pageSecFormByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int32_t* priorSecFormId );

		virtual std::vector<cfsec::ICFSecSecFormObj*> pageSecFormBySecAppIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			const int64_t* priorClusterId,
			const int32_t* priorSecFormId );

		virtual cfsec::ICFSecSecFormObj* updateSecForm( cfsec::ICFSecSecFormEditObj* Obj );

		virtual void deleteSecForm( cfsec::ICFSecSecFormEditObj* Obj );

		virtual void deleteSecFormByIdIdx( const int64_t ClusterId,
			const int32_t SecFormId );

		virtual void deleteSecFormByClusterIdx( const int64_t ClusterId );

		virtual void deleteSecFormBySecAppIdx( const int64_t ClusterId,
			const int32_t SecAppId );

		virtual void deleteSecFormByUJEEServletIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName );

		virtual void reallyDetachFromIndexesSecForm( cfsec::ICFSecSecFormObj* Obj );

	};

}
