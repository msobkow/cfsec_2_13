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

#include <cfsecobj/ICFSecISOLangObj.hpp>
#include <cfsecobj/ICFSecISOLangEditObj.hpp>
#include <cfsecobj/ICFSecISOLangTableObj.hpp>

namespace cfsec {

	class CFSecISOLangTableObj
	: public virtual ICFSecISOLangTableObj
	{
	protected:
		cfsec::ICFSecSchemaObj* schema;
		std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* members;
		std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* allISOLang;
		std::map< cfsec::CFSecISOLangByCode3IdxKey,
			cfsec::ICFSecISOLangObj*>* indexByCode3Idx;
		std::map< cfsec::CFSecISOLangByCode2IdxKey,
			std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>*>* indexByCode2Idx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFSecISOLangTableObj();
		CFSecISOLangTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFSecISOLangTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecISOLangObj* newInstance();

		virtual cfsec::ICFSecISOLangEditObj* newEditInstance( cfsec::ICFSecISOLangObj* orig );

		virtual cfsec::ICFSecISOLangObj* realizeISOLang( cfsec::ICFSecISOLangObj* Obj );

		virtual void deepDisposeByIdIdx( const int16_t ISOLangId );
		virtual void deepDisposeByCode3Idx( const std::string& ISO6392Code );
		virtual void deepDisposeByCode2Idx( const std::string* ISO6391Code );
		virtual void reallyDeepDisposeISOLang( cfsec::ICFSecISOLangObj* Obj );
		virtual cfsec::ICFSecISOLangObj* createISOLang( cfsec::ICFSecISOLangEditObj* Obj );

		virtual cfsec::ICFSecISOLangObj* readISOLang( cfsec::CFSecISOLangPKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecISOLangObj* lockISOLang( cfsec::CFSecISOLangPKey* pkey );

		virtual std::vector<cfsec::ICFSecISOLangObj*> readAllISOLang( bool forceRead = false );

		virtual cfsec::ICFSecISOLangObj* readISOLangByIdIdx( const int16_t ISOLangId, bool forceRead = false );

		virtual cfsec::ICFSecISOLangObj* readISOLangByCode3Idx( const std::string& ISO6392Code, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecISOLangObj*> readISOLangByCode2Idx( const std::string* ISO6391Code,
			bool forceRead = false );

		virtual cfsec::ICFSecISOLangObj* readCachedISOLang( cfsec::CFSecISOLangPKey* pkey );

		virtual cfsec::ICFSecISOLangObj* readCachedISOLangByIdIdx( const int16_t ISOLangId );

		virtual cfsec::ICFSecISOLangObj* readCachedISOLangByCode3Idx( const std::string& ISO6392Code );

		virtual std::vector<cfsec::ICFSecISOLangObj*> readCachedISOLangByCode2Idx( const std::string* ISO6391Code );

		virtual cfsec::ICFSecISOLangObj* readISOLangByLookupCode3Idx( const std::string& ISO6392Code, bool forceRead = false );

		virtual cfsec::ICFSecISOLangObj* readCachedISOLangByLookupCode3Idx( const std::string& ISO6392Code );

		virtual cfsec::ICFSecISOLangObj* updateISOLang( cfsec::ICFSecISOLangEditObj* Obj );

		virtual void deleteISOLang( cfsec::ICFSecISOLangEditObj* Obj );

		virtual void deleteISOLangByIdIdx( const int16_t ISOLangId );

		virtual void deleteISOLangByCode3Idx( const std::string& ISO6392Code );

		virtual void deleteISOLangByCode2Idx( const std::string* ISO6391Code );

		virtual void reallyDetachFromIndexesISOLang( cfsec::ICFSecISOLangObj* Obj );

	};

}
