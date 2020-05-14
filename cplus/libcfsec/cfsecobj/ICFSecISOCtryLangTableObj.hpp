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

#include <cfsecobj/ICFSecISOCtryLangObj.hpp>
#include <cfsecobj/ICFSecISOCtryLangEditObj.hpp>

namespace cfsec {

	class ICFSecISOCtryLangTableObj
	{
	public:
		ICFSecISOCtryLangTableObj();
		virtual ~ICFSecISOCtryLangTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema() = 0;
		virtual void setSchema( cfsec::ICFSecSchemaObj* value ) = 0;

		virtual void minimizeMemory() = 0;

		virtual const std::string getTableName() = 0;
		virtual const std::string getTableDbName() = 0;
		virtual const classcode_t* getObjQualifyingClassCode() = 0;

		virtual cfsec::ICFSecISOCtryLangObj* newInstance() = 0;

		virtual cfsec::ICFSecISOCtryLangEditObj* newEditInstance( cfsec::ICFSecISOCtryLangObj* orig ) = 0;

		virtual cfsec::ICFSecISOCtryLangObj* realizeISOCtryLang( cfsec::ICFSecISOCtryLangObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOLangId ) = 0;
		virtual void deepDisposeByCtryIdx( const int16_t ISOCtryId ) = 0;
		virtual void deepDisposeByLangIdx( const int16_t ISOLangId ) = 0;
		virtual void reallyDeepDisposeISOCtryLang( cfsec::ICFSecISOCtryLangObj* Obj ) = 0;
		virtual cfsec::ICFSecISOCtryLangObj* createISOCtryLang( cfsec::ICFSecISOCtryLangEditObj* Obj ) = 0;

		virtual cfsec::ICFSecISOCtryLangObj* readISOCtryLang( cfsec::CFSecISOCtryLangPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryLangObj* lockISOCtryLang( cfsec::CFSecISOCtryLangPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecISOCtryLangObj*> readAllISOCtryLang( bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryLangObj* readISOCtryLangByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOLangId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecISOCtryLangObj*> readISOCtryLangByCtryIdx( const int16_t ISOCtryId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecISOCtryLangObj*> readISOCtryLangByLangIdx( const int16_t ISOLangId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryLangObj* readCachedISOCtryLang( cfsec::CFSecISOCtryLangPKey* pkey ) = 0;

		virtual cfsec::ICFSecISOCtryLangObj* readCachedISOCtryLangByIdIdx(const int16_t ISOCtryId,
			const int16_t ISOLangId ) = 0;

		virtual std::vector<cfsec::ICFSecISOCtryLangObj*> readCachedISOCtryLangByCtryIdx( const int16_t ISOCtryId ) = 0;

		virtual std::vector<cfsec::ICFSecISOCtryLangObj*> readCachedISOCtryLangByLangIdx( const int16_t ISOLangId ) = 0;

		virtual cfsec::ICFSecISOCtryLangObj* updateISOCtryLang( cfsec::ICFSecISOCtryLangEditObj* Obj ) = 0;

		virtual void deleteISOCtryLang( cfsec::ICFSecISOCtryLangEditObj* Obj ) = 0;

		virtual void deleteISOCtryLangByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOLangId ) = 0;

		virtual void deleteISOCtryLangByCtryIdx( const int16_t ISOCtryId ) = 0;

		virtual void deleteISOCtryLangByLangIdx( const int16_t ISOLangId ) = 0;

		virtual void reallyDetachFromIndexesISOCtryLang( cfsec::ICFSecISOCtryLangObj* Obj ) = 0;

	};
}
