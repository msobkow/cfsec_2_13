#pragma once

// Description: C++18 Table Object specification for CFSec.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
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

#include <cfsecobj/ICFSecTSecGrpMembObj.hpp>
#include <cfsecobj/ICFSecTSecGrpMembEditObj.hpp>
#include <cfsecobj/ICFSecTSecGrpMembTableObj.hpp>

namespace cfsec {

	class CFSecTSecGrpMembTableObj
	: public virtual ICFSecTSecGrpMembTableObj
	{
	protected:
		cfsec::ICFSecSchemaObj* schema;
		std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* members;
		std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* allTSecGrpMemb;
		std::map< cfsec::CFSecTSecGrpMembByTenantIdxKey,
			std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>*>* indexByTenantIdx;
		std::map< cfsec::CFSecTSecGrpMembByGroupIdxKey,
			std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>*>* indexByGroupIdx;
		std::map< cfsec::CFSecTSecGrpMembByUserIdxKey,
			std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>*>* indexByUserIdx;
		std::map< cfsec::CFSecTSecGrpMembByUUserIdxKey,
			cfsec::ICFSecTSecGrpMembObj*>* indexByUUserIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFSecTSecGrpMembTableObj();
		CFSecTSecGrpMembTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFSecTSecGrpMembTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecTSecGrpMembObj* newInstance();

		virtual cfsec::ICFSecTSecGrpMembEditObj* newEditInstance( cfsec::ICFSecTSecGrpMembObj* orig );

		virtual cfsec::ICFSecTSecGrpMembObj* realizeTSecGrpMemb( cfsec::ICFSecTSecGrpMembObj* Obj );

		virtual void deepDisposeByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpMembId );
		virtual void deepDisposeByTenantIdx( const int64_t TenantId );
		virtual void deepDisposeByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId );
		virtual void deepDisposeByUserIdx( const uuid_ptr_t SecUserId );
		virtual void deepDisposeByUUserIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const uuid_ptr_t SecUserId );
		virtual void reallyDeepDisposeTSecGrpMemb( cfsec::ICFSecTSecGrpMembObj* Obj );
		virtual cfsec::ICFSecTSecGrpMembObj* createTSecGrpMemb( cfsec::ICFSecTSecGrpMembEditObj* Obj );

		virtual cfsec::ICFSecTSecGrpMembObj* readTSecGrpMemb( cfsec::CFSecTSecGrpMembPKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecTSecGrpMembObj* lockTSecGrpMemb( cfsec::CFSecTSecGrpMembPKey* pkey );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readAllTSecGrpMemb( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> pageAllTSecGrpMemb(const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId );

		virtual cfsec::ICFSecTSecGrpMembObj* readTSecGrpMembByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpMembId, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readTSecGrpMembByTenantIdx( const int64_t TenantId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readTSecGrpMembByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readTSecGrpMembByUserIdx( const uuid_ptr_t SecUserId,
			bool forceRead = false );

		virtual cfsec::ICFSecTSecGrpMembObj* readTSecGrpMembByUUserIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const uuid_ptr_t SecUserId, bool forceRead = false );

		virtual cfsec::ICFSecTSecGrpMembObj* readCachedTSecGrpMemb( cfsec::CFSecTSecGrpMembPKey* pkey );

		virtual cfsec::ICFSecTSecGrpMembObj* readCachedTSecGrpMembByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpMembId );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readCachedTSecGrpMembByTenantIdx( const int64_t TenantId );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readCachedTSecGrpMembByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readCachedTSecGrpMembByUserIdx( const uuid_ptr_t SecUserId );

		virtual cfsec::ICFSecTSecGrpMembObj* readCachedTSecGrpMembByUUserIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const uuid_ptr_t SecUserId );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> pageTSecGrpMembByTenantIdx( const int64_t TenantId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> pageTSecGrpMembByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> pageTSecGrpMembByUserIdx( const uuid_ptr_t SecUserId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId );

		virtual cfsec::ICFSecTSecGrpMembObj* updateTSecGrpMemb( cfsec::ICFSecTSecGrpMembEditObj* Obj );

		virtual void deleteTSecGrpMemb( cfsec::ICFSecTSecGrpMembEditObj* Obj );

		virtual void deleteTSecGrpMembByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpMembId );

		virtual void deleteTSecGrpMembByTenantIdx( const int64_t TenantId );

		virtual void deleteTSecGrpMembByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId );

		virtual void deleteTSecGrpMembByUserIdx( const uuid_ptr_t SecUserId );

		virtual void deleteTSecGrpMembByUUserIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const uuid_ptr_t SecUserId );

		virtual void reallyDetachFromIndexesTSecGrpMemb( cfsec::ICFSecTSecGrpMembObj* Obj );

	};

}
