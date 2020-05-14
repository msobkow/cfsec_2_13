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

#include <cfsecobj/ICFSecISOCtryCcyObj.hpp>
#include <cfsecobj/ICFSecISOCtryCcyEditObj.hpp>
#include <cfsecobj/ICFSecISOCtryCcyTableObj.hpp>

namespace cfsec {

	class CFSecISOCtryCcyTableObj
	: public virtual ICFSecISOCtryCcyTableObj
	{
	protected:
		cfsec::ICFSecSchemaObj* schema;
		std::map<cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>* members;
		std::map<cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>* allISOCtryCcy;
		std::map< cfsec::CFSecISOCtryCcyByCtryIdxKey,
			std::map<cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>*>* indexByCtryIdx;
		std::map< cfsec::CFSecISOCtryCcyByCcyIdxKey,
			std::map<cfsec::CFSecISOCtryCcyPKey, cfsec::ICFSecISOCtryCcyObj*>*>* indexByCcyIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFSecISOCtryCcyTableObj();
		CFSecISOCtryCcyTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFSecISOCtryCcyTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecISOCtryCcyObj* newInstance();

		virtual cfsec::ICFSecISOCtryCcyEditObj* newEditInstance( cfsec::ICFSecISOCtryCcyObj* orig );

		virtual cfsec::ICFSecISOCtryCcyObj* realizeISOCtryCcy( cfsec::ICFSecISOCtryCcyObj* Obj );

		virtual void deepDisposeByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOCcyId );
		virtual void deepDisposeByCtryIdx( const int16_t ISOCtryId );
		virtual void deepDisposeByCcyIdx( const int16_t ISOCcyId );
		virtual void reallyDeepDisposeISOCtryCcy( cfsec::ICFSecISOCtryCcyObj* Obj );
		virtual cfsec::ICFSecISOCtryCcyObj* createISOCtryCcy( cfsec::ICFSecISOCtryCcyEditObj* Obj );

		virtual cfsec::ICFSecISOCtryCcyObj* readISOCtryCcy( cfsec::CFSecISOCtryCcyPKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecISOCtryCcyObj* lockISOCtryCcy( cfsec::CFSecISOCtryCcyPKey* pkey );

		virtual std::vector<cfsec::ICFSecISOCtryCcyObj*> readAllISOCtryCcy( bool forceRead = false );

		virtual cfsec::ICFSecISOCtryCcyObj* readISOCtryCcyByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOCcyId, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecISOCtryCcyObj*> readISOCtryCcyByCtryIdx( const int16_t ISOCtryId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecISOCtryCcyObj*> readISOCtryCcyByCcyIdx( const int16_t ISOCcyId,
			bool forceRead = false );

		virtual cfsec::ICFSecISOCtryCcyObj* readCachedISOCtryCcy( cfsec::CFSecISOCtryCcyPKey* pkey );

		virtual cfsec::ICFSecISOCtryCcyObj* readCachedISOCtryCcyByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOCcyId );

		virtual std::vector<cfsec::ICFSecISOCtryCcyObj*> readCachedISOCtryCcyByCtryIdx( const int16_t ISOCtryId );

		virtual std::vector<cfsec::ICFSecISOCtryCcyObj*> readCachedISOCtryCcyByCcyIdx( const int16_t ISOCcyId );

		virtual cfsec::ICFSecISOCtryCcyObj* updateISOCtryCcy( cfsec::ICFSecISOCtryCcyEditObj* Obj );

		virtual void deleteISOCtryCcy( cfsec::ICFSecISOCtryCcyEditObj* Obj );

		virtual void deleteISOCtryCcyByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOCcyId );

		virtual void deleteISOCtryCcyByCtryIdx( const int16_t ISOCtryId );

		virtual void deleteISOCtryCcyByCcyIdx( const int16_t ISOCcyId );

		virtual void reallyDetachFromIndexesISOCtryCcy( cfsec::ICFSecISOCtryCcyObj* Obj );

	};

}
