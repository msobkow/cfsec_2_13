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

#include <cfsecobj/ICFSecISOTZoneObj.hpp>
#include <cfsecobj/ICFSecISOTZoneEditObj.hpp>

namespace cfsec {

	class ICFSecISOTZoneTableObj
	{
	public:
		ICFSecISOTZoneTableObj();
		virtual ~ICFSecISOTZoneTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema() = 0;
		virtual void setSchema( cfsec::ICFSecSchemaObj* value ) = 0;

		virtual void minimizeMemory() = 0;

		virtual const std::string getTableName() = 0;
		virtual const std::string getTableDbName() = 0;
		virtual const classcode_t* getObjQualifyingClassCode() = 0;

		virtual cfsec::ICFSecISOTZoneObj* newInstance() = 0;

		virtual cfsec::ICFSecISOTZoneEditObj* newEditInstance( cfsec::ICFSecISOTZoneObj* orig ) = 0;

		virtual cfsec::ICFSecISOTZoneObj* realizeISOTZone( cfsec::ICFSecISOTZoneObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int16_t ISOTZoneId ) = 0;
		virtual void deepDisposeByOffsetIdx( const int16_t TZHourOffset,
			const int16_t TZMinOffset ) = 0;
		virtual void deepDisposeByUTZNameIdx( const std::string& TZName ) = 0;
		virtual void deepDisposeByIso8601Idx( const std::string& Iso8601 ) = 0;
		virtual void reallyDeepDisposeISOTZone( cfsec::ICFSecISOTZoneObj* Obj ) = 0;
		virtual cfsec::ICFSecISOTZoneObj* createISOTZone( cfsec::ICFSecISOTZoneEditObj* Obj ) = 0;

		virtual cfsec::ICFSecISOTZoneObj* readISOTZone( cfsec::CFSecISOTZonePKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOTZoneObj* lockISOTZone( cfsec::CFSecISOTZonePKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecISOTZoneObj*> readAllISOTZone( bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOTZoneObj* readISOTZoneByIdIdx( const int16_t ISOTZoneId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecISOTZoneObj*> readISOTZoneByOffsetIdx( const int16_t TZHourOffset,
			const int16_t TZMinOffset,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOTZoneObj* readISOTZoneByUTZNameIdx(const std::string& TZName,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecISOTZoneObj*> readISOTZoneByIso8601Idx( const std::string& Iso8601,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOTZoneObj* readCachedISOTZone( cfsec::CFSecISOTZonePKey* pkey ) = 0;

		virtual cfsec::ICFSecISOTZoneObj* readCachedISOTZoneByIdIdx(const int16_t ISOTZoneId ) = 0;

		virtual std::vector<cfsec::ICFSecISOTZoneObj*> readCachedISOTZoneByOffsetIdx( const int16_t TZHourOffset,
			const int16_t TZMinOffset ) = 0;

		virtual cfsec::ICFSecISOTZoneObj* readCachedISOTZoneByUTZNameIdx(const std::string& TZName ) = 0;

		virtual std::vector<cfsec::ICFSecISOTZoneObj*> readCachedISOTZoneByIso8601Idx( const std::string& Iso8601 ) = 0;

		virtual cfsec::ICFSecISOTZoneObj* readISOTZoneByLookupUTZNameIdx(const std::string& TZName,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOTZoneObj* readCachedISOTZoneByLookupUTZNameIdx(const std::string& TZName ) = 0;

		virtual cfsec::ICFSecISOTZoneObj* updateISOTZone( cfsec::ICFSecISOTZoneEditObj* Obj ) = 0;

		virtual void deleteISOTZone( cfsec::ICFSecISOTZoneEditObj* Obj ) = 0;

		virtual void deleteISOTZoneByIdIdx( const int16_t ISOTZoneId ) = 0;

		virtual void deleteISOTZoneByOffsetIdx( const int16_t TZHourOffset,
			const int16_t TZMinOffset ) = 0;

		virtual void deleteISOTZoneByUTZNameIdx(const std::string& TZName ) = 0;

		virtual void deleteISOTZoneByIso8601Idx( const std::string& Iso8601 ) = 0;

		virtual void reallyDetachFromIndexesISOTZone( cfsec::ICFSecISOTZoneObj* Obj ) = 0;

	};
}
