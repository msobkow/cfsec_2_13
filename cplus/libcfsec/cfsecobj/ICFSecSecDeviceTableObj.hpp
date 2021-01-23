#pragma once

// Description: C++18 Table Object interface for CFSec.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow
 *	
 *		This file is part of MSS Code Factory.
 *	
 *		MSS Code Factory is available under dual commercial license from Mark Stephen
 *		Sobkow, or under the terms of the GNU General Public License, Version 3
 *		or later.
 *	
 *	    MSS Code Factory is free software: you can redistribute it and/or modify
 *	    it under the terms of the GNU General Public License as published by
 *	    the Free Software Foundation, either version 3 of the License, or
 *	    (at your option) any later version.
 *	
 *	    MSS Code Factory is distributed in the hope that it will be useful,
 *	    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	    GNU General Public License for more details.
 *	
 *	    You should have received a copy of the GNU General Public License
 *	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
 *	
 *	Please contact Mark Stephen Sobkow at mark.sobkow@gmail.com for commercial licensing.
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

namespace cfsec {

	class ICFSecSecDeviceTableObj
	{
	public:
		ICFSecSecDeviceTableObj();
		virtual ~ICFSecSecDeviceTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema() = 0;
		virtual void setSchema( cfsec::ICFSecSchemaObj* value ) = 0;

		virtual void minimizeMemory() = 0;

		virtual const std::string getTableName() = 0;
		virtual const std::string getTableDbName() = 0;
		virtual const classcode_t* getObjQualifyingClassCode() = 0;

		virtual cfsec::ICFSecSecDeviceObj* newInstance() = 0;

		virtual cfsec::ICFSecSecDeviceEditObj* newEditInstance( cfsec::ICFSecSecDeviceObj* orig ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* realizeSecDevice( cfsec::ICFSecSecDeviceObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName ) = 0;
		virtual void deepDisposeByNameIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName ) = 0;
		virtual void deepDisposeByUserIdx( const uuid_ptr_t SecUserId ) = 0;
		virtual void reallyDeepDisposeSecDevice( cfsec::ICFSecSecDeviceObj* Obj ) = 0;
		virtual cfsec::ICFSecSecDeviceObj* createSecDevice( cfsec::ICFSecSecDeviceEditObj* Obj ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* readSecDevice( cfsec::CFSecSecDevicePKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* lockSecDevice( cfsec::CFSecSecDevicePKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecSecDeviceObj*> readAllSecDevice( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecDeviceObj*> pageAllSecDevice(const uuid_ptr_t priorSecUserId,
			const std::string* priorDevName ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* readSecDeviceByIdIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* readSecDeviceByNameIdx(const uuid_ptr_t SecUserId,
			const std::string& DevName,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecDeviceObj*> readSecDeviceByUserIdx( const uuid_ptr_t SecUserId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* readCachedSecDevice( cfsec::CFSecSecDevicePKey* pkey ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* readCachedSecDeviceByIdIdx(const uuid_ptr_t SecUserId,
			const std::string& DevName ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* readCachedSecDeviceByNameIdx(const uuid_ptr_t SecUserId,
			const std::string& DevName ) = 0;

		virtual std::vector<cfsec::ICFSecSecDeviceObj*> readCachedSecDeviceByUserIdx( const uuid_ptr_t SecUserId ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* readSecDeviceByLookupNameIdx(const uuid_ptr_t SecUserId,
			const std::string& DevName,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* readCachedSecDeviceByLookupNameIdx(const uuid_ptr_t SecUserId,
			const std::string& DevName ) = 0;

		virtual std::vector<cfsec::ICFSecSecDeviceObj*> pageSecDeviceByUserIdx( const uuid_ptr_t SecUserId,
			const uuid_ptr_t priorSecUserId,
			const std::string* priorDevName ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* updateSecDevice( cfsec::ICFSecSecDeviceEditObj* Obj ) = 0;

		virtual void deleteSecDevice( cfsec::ICFSecSecDeviceEditObj* Obj ) = 0;

		virtual void deleteSecDeviceByIdIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName ) = 0;

		virtual void deleteSecDeviceByNameIdx(const uuid_ptr_t SecUserId,
			const std::string& DevName ) = 0;

		virtual void deleteSecDeviceByUserIdx( const uuid_ptr_t SecUserId ) = 0;

		virtual void reallyDetachFromIndexesSecDevice( cfsec::ICFSecSecDeviceObj* Obj ) = 0;

	};
}
