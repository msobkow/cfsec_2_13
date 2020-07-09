#pragma once

// Description: C++18 Table Object interface for CFSec.

/*
 *	org.msscf.msscf.CFSec
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

#include <cfsecobj/ICFSecISOCcyObj.hpp>
#include <cfsecobj/ICFSecISOCcyEditObj.hpp>

namespace cfsec {

	class ICFSecISOCcyTableObj
	{
	public:
		ICFSecISOCcyTableObj();
		virtual ~ICFSecISOCcyTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema() = 0;
		virtual void setSchema( cfsec::ICFSecSchemaObj* value ) = 0;

		virtual void minimizeMemory() = 0;

		virtual const std::string getTableName() = 0;
		virtual const std::string getTableDbName() = 0;
		virtual const classcode_t* getObjQualifyingClassCode() = 0;

		virtual cfsec::ICFSecISOCcyObj* newInstance() = 0;

		virtual cfsec::ICFSecISOCcyEditObj* newEditInstance( cfsec::ICFSecISOCcyObj* orig ) = 0;

		virtual cfsec::ICFSecISOCcyObj* realizeISOCcy( cfsec::ICFSecISOCcyObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int16_t ISOCcyId ) = 0;
		virtual void deepDisposeByCcyCdIdx( const std::string& ISOCode ) = 0;
		virtual void deepDisposeByCcyNmIdx( const std::string& Name ) = 0;
		virtual void reallyDeepDisposeISOCcy( cfsec::ICFSecISOCcyObj* Obj ) = 0;
		virtual cfsec::ICFSecISOCcyObj* createISOCcy( cfsec::ICFSecISOCcyEditObj* Obj ) = 0;

		virtual cfsec::ICFSecISOCcyObj* readISOCcy( cfsec::CFSecISOCcyPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCcyObj* lockISOCcy( cfsec::CFSecISOCcyPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecISOCcyObj*> readAllISOCcy( bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCcyObj* readISOCcyByIdIdx( const int16_t ISOCcyId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCcyObj* readISOCcyByCcyCdIdx(const std::string& ISOCode,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCcyObj* readISOCcyByCcyNmIdx(const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCcyObj* readCachedISOCcy( cfsec::CFSecISOCcyPKey* pkey ) = 0;

		virtual cfsec::ICFSecISOCcyObj* readCachedISOCcyByIdIdx(const int16_t ISOCcyId ) = 0;

		virtual cfsec::ICFSecISOCcyObj* readCachedISOCcyByCcyCdIdx(const std::string& ISOCode ) = 0;

		virtual cfsec::ICFSecISOCcyObj* readCachedISOCcyByCcyNmIdx(const std::string& Name ) = 0;

		virtual cfsec::ICFSecISOCcyObj* readISOCcyByLookupCcyCdIdx(const std::string& ISOCode,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCcyObj* readCachedISOCcyByLookupCcyCdIdx(const std::string& ISOCode ) = 0;

		virtual cfsec::ICFSecISOCcyObj* updateISOCcy( cfsec::ICFSecISOCcyEditObj* Obj ) = 0;

		virtual void deleteISOCcy( cfsec::ICFSecISOCcyEditObj* Obj ) = 0;

		virtual void deleteISOCcyByIdIdx( const int16_t ISOCcyId ) = 0;

		virtual void deleteISOCcyByCcyCdIdx(const std::string& ISOCode ) = 0;

		virtual void deleteISOCcyByCcyNmIdx(const std::string& Name ) = 0;

		virtual void reallyDetachFromIndexesISOCcy( cfsec::ICFSecISOCcyObj* Obj ) = 0;

	};
}
