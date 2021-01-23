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

#include <cfsecobj/ICFSecSecGrpIncObj.hpp>
#include <cfsecobj/ICFSecSecGrpIncEditObj.hpp>

namespace cfsec {

	class ICFSecSecGrpIncTableObj
	{
	public:
		ICFSecSecGrpIncTableObj();
		virtual ~ICFSecSecGrpIncTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema() = 0;
		virtual void setSchema( cfsec::ICFSecSchemaObj* value ) = 0;

		virtual void minimizeMemory() = 0;

		virtual const std::string getTableName() = 0;
		virtual const std::string getTableDbName() = 0;
		virtual const classcode_t* getObjQualifyingClassCode() = 0;

		virtual cfsec::ICFSecSecGrpIncObj* newInstance() = 0;

		virtual cfsec::ICFSecSecGrpIncEditObj* newEditInstance( cfsec::ICFSecSecGrpIncObj* orig ) = 0;

		virtual cfsec::ICFSecSecGrpIncObj* realizeSecGrpInc( cfsec::ICFSecSecGrpIncObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpIncId ) = 0;
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId ) = 0;
		virtual void deepDisposeByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;
		virtual void deepDisposeByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId ) = 0;
		virtual void deepDisposeByUIncludeIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId ) = 0;
		virtual void reallyDeepDisposeSecGrpInc( cfsec::ICFSecSecGrpIncObj* Obj ) = 0;
		virtual cfsec::ICFSecSecGrpIncObj* createSecGrpInc( cfsec::ICFSecSecGrpIncEditObj* Obj ) = 0;

		virtual cfsec::ICFSecSecGrpIncObj* readSecGrpInc( cfsec::CFSecSecGrpIncPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecGrpIncObj* lockSecGrpInc( cfsec::CFSecSecGrpIncPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> readAllSecGrpInc( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> pageAllSecGrpInc(const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId ) = 0;

		virtual cfsec::ICFSecSecGrpIncObj* readSecGrpIncByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpIncId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> readSecGrpIncByClusterIdx( const int64_t ClusterId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> readSecGrpIncByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> readSecGrpIncByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecGrpIncObj* readSecGrpIncByUIncludeIdx(const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecGrpIncObj* readCachedSecGrpInc( cfsec::CFSecSecGrpIncPKey* pkey ) = 0;

		virtual cfsec::ICFSecSecGrpIncObj* readCachedSecGrpIncByIdIdx(const int64_t ClusterId,
			const int64_t SecGrpIncId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> readCachedSecGrpIncByClusterIdx( const int64_t ClusterId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> readCachedSecGrpIncByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> readCachedSecGrpIncByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId ) = 0;

		virtual cfsec::ICFSecSecGrpIncObj* readCachedSecGrpIncByUIncludeIdx(const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> pageSecGrpIncByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> pageSecGrpIncByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> pageSecGrpIncByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId ) = 0;

		virtual cfsec::ICFSecSecGrpIncObj* updateSecGrpInc( cfsec::ICFSecSecGrpIncEditObj* Obj ) = 0;

		virtual void deleteSecGrpInc( cfsec::ICFSecSecGrpIncEditObj* Obj ) = 0;

		virtual void deleteSecGrpIncByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpIncId ) = 0;

		virtual void deleteSecGrpIncByClusterIdx( const int64_t ClusterId ) = 0;

		virtual void deleteSecGrpIncByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;

		virtual void deleteSecGrpIncByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId ) = 0;

		virtual void deleteSecGrpIncByUIncludeIdx(const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId ) = 0;

		virtual void reallyDetachFromIndexesSecGrpInc( cfsec::ICFSecSecGrpIncObj* Obj ) = 0;

	};
}
