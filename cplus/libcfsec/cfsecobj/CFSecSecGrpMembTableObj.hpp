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

#include <cfsecobj/ICFSecSecGrpMembObj.hpp>
#include <cfsecobj/ICFSecSecGrpMembEditObj.hpp>
#include <cfsecobj/ICFSecSecGrpMembTableObj.hpp>

namespace cfsec {

	class CFSecSecGrpMembTableObj
	: public virtual ICFSecSecGrpMembTableObj
	{
	protected:
		cfsec::ICFSecSchemaObj* schema;
		std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* members;
		std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>* allSecGrpMemb;
		std::map< cfsec::CFSecSecGrpMembByClusterIdxKey,
			std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>*>* indexByClusterIdx;
		std::map< cfsec::CFSecSecGrpMembByGroupIdxKey,
			std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>*>* indexByGroupIdx;
		std::map< cfsec::CFSecSecGrpMembByUserIdxKey,
			std::map<cfsec::CFSecSecGrpMembPKey, cfsec::ICFSecSecGrpMembObj*>*>* indexByUserIdx;
		std::map< cfsec::CFSecSecGrpMembByUUserIdxKey,
			cfsec::ICFSecSecGrpMembObj*>* indexByUUserIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFSecSecGrpMembTableObj();
		CFSecSecGrpMembTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFSecSecGrpMembTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecSecGrpMembObj* newInstance();

		virtual cfsec::ICFSecSecGrpMembEditObj* newEditInstance( cfsec::ICFSecSecGrpMembObj* orig );

		virtual cfsec::ICFSecSecGrpMembObj* realizeSecGrpMemb( cfsec::ICFSecSecGrpMembObj* Obj );

		virtual void deepDisposeByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpMembId );
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId );
		virtual void deepDisposeByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId );
		virtual void deepDisposeByUserIdx( const uuid_ptr_t SecUserId );
		virtual void deepDisposeByUUserIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const uuid_ptr_t SecUserId );
		virtual void reallyDeepDisposeSecGrpMemb( cfsec::ICFSecSecGrpMembObj* Obj );
		virtual cfsec::ICFSecSecGrpMembObj* createSecGrpMemb( cfsec::ICFSecSecGrpMembEditObj* Obj );

		virtual cfsec::ICFSecSecGrpMembObj* readSecGrpMemb( cfsec::CFSecSecGrpMembPKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecSecGrpMembObj* lockSecGrpMemb( cfsec::CFSecSecGrpMembPKey* pkey );

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> readAllSecGrpMemb( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> pageAllSecGrpMemb(const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId );

		virtual cfsec::ICFSecSecGrpMembObj* readSecGrpMembByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpMembId, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> readSecGrpMembByClusterIdx( const int64_t ClusterId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> readSecGrpMembByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> readSecGrpMembByUserIdx( const uuid_ptr_t SecUserId,
			bool forceRead = false );

		virtual cfsec::ICFSecSecGrpMembObj* readSecGrpMembByUUserIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const uuid_ptr_t SecUserId, bool forceRead = false );

		virtual cfsec::ICFSecSecGrpMembObj* readCachedSecGrpMemb( cfsec::CFSecSecGrpMembPKey* pkey );

		virtual cfsec::ICFSecSecGrpMembObj* readCachedSecGrpMembByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpMembId );

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> readCachedSecGrpMembByClusterIdx( const int64_t ClusterId );

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> readCachedSecGrpMembByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId );

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> readCachedSecGrpMembByUserIdx( const uuid_ptr_t SecUserId );

		virtual cfsec::ICFSecSecGrpMembObj* readCachedSecGrpMembByUUserIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const uuid_ptr_t SecUserId );

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> pageSecGrpMembByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId );

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> pageSecGrpMembByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId );

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> pageSecGrpMembByUserIdx( const uuid_ptr_t SecUserId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId );

		virtual cfsec::ICFSecSecGrpMembObj* updateSecGrpMemb( cfsec::ICFSecSecGrpMembEditObj* Obj );

		virtual void deleteSecGrpMemb( cfsec::ICFSecSecGrpMembEditObj* Obj );

		virtual void deleteSecGrpMembByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpMembId );

		virtual void deleteSecGrpMembByClusterIdx( const int64_t ClusterId );

		virtual void deleteSecGrpMembByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId );

		virtual void deleteSecGrpMembByUserIdx( const uuid_ptr_t SecUserId );

		virtual void deleteSecGrpMembByUUserIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const uuid_ptr_t SecUserId );

		virtual void reallyDetachFromIndexesSecGrpMemb( cfsec::ICFSecSecGrpMembObj* Obj );

	};

}
