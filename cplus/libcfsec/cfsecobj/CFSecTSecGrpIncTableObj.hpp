#pragma once

// Description: C++18 Table Object specification for CFSec.

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

#include <cfsecobj/ICFSecTSecGrpIncObj.hpp>
#include <cfsecobj/ICFSecTSecGrpIncEditObj.hpp>
#include <cfsecobj/ICFSecTSecGrpIncTableObj.hpp>

namespace cfsec {

	class CFSecTSecGrpIncTableObj
	: public virtual ICFSecTSecGrpIncTableObj
	{
	protected:
		cfsec::ICFSecSchemaObj* schema;
		std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* members;
		std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>* allTSecGrpInc;
		std::map< cfsec::CFSecTSecGrpIncByTenantIdxKey,
			std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>*>* indexByTenantIdx;
		std::map< cfsec::CFSecTSecGrpIncByGroupIdxKey,
			std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>*>* indexByGroupIdx;
		std::map< cfsec::CFSecTSecGrpIncByIncludeIdxKey,
			std::map<cfsec::CFSecTSecGrpIncPKey, cfsec::ICFSecTSecGrpIncObj*>*>* indexByIncludeIdx;
		std::map< cfsec::CFSecTSecGrpIncByUIncludeIdxKey,
			cfsec::ICFSecTSecGrpIncObj*>* indexByUIncludeIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFSecTSecGrpIncTableObj();
		CFSecTSecGrpIncTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFSecTSecGrpIncTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecTSecGrpIncObj* newInstance();

		virtual cfsec::ICFSecTSecGrpIncEditObj* newEditInstance( cfsec::ICFSecTSecGrpIncObj* orig );

		virtual cfsec::ICFSecTSecGrpIncObj* realizeTSecGrpInc( cfsec::ICFSecTSecGrpIncObj* Obj );

		virtual void deepDisposeByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpIncId );
		virtual void deepDisposeByTenantIdx( const int64_t TenantId );
		virtual void deepDisposeByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId );
		virtual void deepDisposeByIncludeIdx( const int64_t TenantId,
			const int32_t IncludeGroupId );
		virtual void deepDisposeByUIncludeIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const int32_t IncludeGroupId );
		virtual void reallyDeepDisposeTSecGrpInc( cfsec::ICFSecTSecGrpIncObj* Obj );
		virtual cfsec::ICFSecTSecGrpIncObj* createTSecGrpInc( cfsec::ICFSecTSecGrpIncEditObj* Obj );

		virtual cfsec::ICFSecTSecGrpIncObj* readTSecGrpInc( cfsec::CFSecTSecGrpIncPKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecTSecGrpIncObj* lockTSecGrpInc( cfsec::CFSecTSecGrpIncPKey* pkey );

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> readAllTSecGrpInc( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> pageAllTSecGrpInc(const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId );

		virtual cfsec::ICFSecTSecGrpIncObj* readTSecGrpIncByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpIncId, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> readTSecGrpIncByTenantIdx( const int64_t TenantId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> readTSecGrpIncByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> readTSecGrpIncByIncludeIdx( const int64_t TenantId,
			const int32_t IncludeGroupId,
			bool forceRead = false );

		virtual cfsec::ICFSecTSecGrpIncObj* readTSecGrpIncByUIncludeIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const int32_t IncludeGroupId, bool forceRead = false );

		virtual cfsec::ICFSecTSecGrpIncObj* readCachedTSecGrpInc( cfsec::CFSecTSecGrpIncPKey* pkey );

		virtual cfsec::ICFSecTSecGrpIncObj* readCachedTSecGrpIncByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpIncId );

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> readCachedTSecGrpIncByTenantIdx( const int64_t TenantId );

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> readCachedTSecGrpIncByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId );

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> readCachedTSecGrpIncByIncludeIdx( const int64_t TenantId,
			const int32_t IncludeGroupId );

		virtual cfsec::ICFSecTSecGrpIncObj* readCachedTSecGrpIncByUIncludeIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const int32_t IncludeGroupId );

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> pageTSecGrpIncByTenantIdx( const int64_t TenantId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId );

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> pageTSecGrpIncByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId );

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> pageTSecGrpIncByIncludeIdx( const int64_t TenantId,
			const int32_t IncludeGroupId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId );

		virtual cfsec::ICFSecTSecGrpIncObj* updateTSecGrpInc( cfsec::ICFSecTSecGrpIncEditObj* Obj );

		virtual void deleteTSecGrpInc( cfsec::ICFSecTSecGrpIncEditObj* Obj );

		virtual void deleteTSecGrpIncByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpIncId );

		virtual void deleteTSecGrpIncByTenantIdx( const int64_t TenantId );

		virtual void deleteTSecGrpIncByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId );

		virtual void deleteTSecGrpIncByIncludeIdx( const int64_t TenantId,
			const int32_t IncludeGroupId );

		virtual void deleteTSecGrpIncByUIncludeIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const int32_t IncludeGroupId );

		virtual void reallyDetachFromIndexesTSecGrpInc( cfsec::ICFSecTSecGrpIncObj* Obj );

	};

}
