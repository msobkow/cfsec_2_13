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

#include <cfsecobj/ICFSecSecDeviceObj.hpp>
#include <cfsecobj/ICFSecSecDeviceEditObj.hpp>
#include <cfsecobj/ICFSecSecDeviceTableObj.hpp>

namespace cfsec {

	class CFSecSecDeviceTableObj
	: public virtual ICFSecSecDeviceTableObj
	{
	protected:
		cfsec::ICFSecSchemaObj* schema;
		std::map<cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>* members;
		std::map<cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>* allSecDevice;
		std::map< cfsec::CFSecSecDeviceByNameIdxKey,
			cfsec::ICFSecSecDeviceObj*>* indexByNameIdx;
		std::map< cfsec::CFSecSecDeviceByUserIdxKey,
			std::map<cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>*>* indexByUserIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFSecSecDeviceTableObj();
		CFSecSecDeviceTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFSecSecDeviceTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecSecDeviceObj* newInstance();

		virtual cfsec::ICFSecSecDeviceEditObj* newEditInstance( cfsec::ICFSecSecDeviceObj* orig );

		virtual cfsec::ICFSecSecDeviceObj* realizeSecDevice( cfsec::ICFSecSecDeviceObj* Obj );

		virtual void deepDisposeByIdIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName );
		virtual void deepDisposeByNameIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName );
		virtual void deepDisposeByUserIdx( const uuid_ptr_t SecUserId );
		virtual void reallyDeepDisposeSecDevice( cfsec::ICFSecSecDeviceObj* Obj );
		virtual cfsec::ICFSecSecDeviceObj* createSecDevice( cfsec::ICFSecSecDeviceEditObj* Obj );

		virtual cfsec::ICFSecSecDeviceObj* readSecDevice( cfsec::CFSecSecDevicePKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecSecDeviceObj* lockSecDevice( cfsec::CFSecSecDevicePKey* pkey );

		virtual std::vector<cfsec::ICFSecSecDeviceObj*> readAllSecDevice( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecDeviceObj*> pageAllSecDevice(const uuid_ptr_t priorSecUserId,
			const std::string* priorDevName );

		virtual cfsec::ICFSecSecDeviceObj* readSecDeviceByIdIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName, bool forceRead = false );

		virtual cfsec::ICFSecSecDeviceObj* readSecDeviceByNameIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecDeviceObj*> readSecDeviceByUserIdx( const uuid_ptr_t SecUserId,
			bool forceRead = false );

		virtual cfsec::ICFSecSecDeviceObj* readCachedSecDevice( cfsec::CFSecSecDevicePKey* pkey );

		virtual cfsec::ICFSecSecDeviceObj* readCachedSecDeviceByIdIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName );

		virtual cfsec::ICFSecSecDeviceObj* readCachedSecDeviceByNameIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName );

		virtual std::vector<cfsec::ICFSecSecDeviceObj*> readCachedSecDeviceByUserIdx( const uuid_ptr_t SecUserId );

		virtual cfsec::ICFSecSecDeviceObj* readSecDeviceByLookupNameIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName, bool forceRead = false );

		virtual cfsec::ICFSecSecDeviceObj* readCachedSecDeviceByLookupNameIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName );

		virtual std::vector<cfsec::ICFSecSecDeviceObj*> pageSecDeviceByUserIdx( const uuid_ptr_t SecUserId,
			const uuid_ptr_t priorSecUserId,
			const std::string* priorDevName );

		virtual cfsec::ICFSecSecDeviceObj* updateSecDevice( cfsec::ICFSecSecDeviceEditObj* Obj );

		virtual void deleteSecDevice( cfsec::ICFSecSecDeviceEditObj* Obj );

		virtual void deleteSecDeviceByIdIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName );

		virtual void deleteSecDeviceByNameIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName );

		virtual void deleteSecDeviceByUserIdx( const uuid_ptr_t SecUserId );

		virtual void reallyDetachFromIndexesSecDevice( cfsec::ICFSecSecDeviceObj* Obj );

	};

}
