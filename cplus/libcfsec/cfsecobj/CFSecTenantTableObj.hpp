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

#include <cfsecobj/ICFSecTenantObj.hpp>
#include <cfsecobj/ICFSecTenantEditObj.hpp>
#include <cfsecobj/ICFSecTenantTableObj.hpp>

namespace cfsec {

	class CFSecTenantTableObj
	: public virtual ICFSecTenantTableObj
	{
	protected:
		cfsec::ICFSecSchemaObj* schema;
		std::map<cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj*>* members;
		std::map<cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj*>* allTenant;
		std::map< cfsec::CFSecTenantByClusterIdxKey,
			std::map<cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj*>*>* indexByClusterIdx;
		std::map< cfsec::CFSecTenantByUNameIdxKey,
			cfsec::ICFSecTenantObj*>* indexByUNameIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFSecTenantTableObj();
		CFSecTenantTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFSecTenantTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecTenantObj* newInstance();

		virtual cfsec::ICFSecTenantEditObj* newEditInstance( cfsec::ICFSecTenantObj* orig );

		virtual cfsec::ICFSecTenantObj* realizeTenant( cfsec::ICFSecTenantObj* Obj );

		virtual void deepDisposeByIdIdx( const int64_t Id );
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId );
		virtual void deepDisposeByUNameIdx( const int64_t ClusterId,
			const std::string& TenantName );
		virtual void reallyDeepDisposeTenant( cfsec::ICFSecTenantObj* Obj );
		virtual cfsec::ICFSecTenantObj* createTenant( cfsec::ICFSecTenantEditObj* Obj );

		virtual cfsec::ICFSecTenantObj* readTenant( cfsec::CFSecTenantPKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecTenantObj* lockTenant( cfsec::CFSecTenantPKey* pkey );

		virtual std::vector<cfsec::ICFSecTenantObj*> readAllTenant( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecTenantObj*> pageAllTenant(const int64_t* priorId );

		virtual cfsec::ICFSecTenantObj* readTenantByIdIdx( const int64_t Id, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecTenantObj*> readTenantByClusterIdx( const int64_t ClusterId,
			bool forceRead = false );

		virtual cfsec::ICFSecTenantObj* readTenantByUNameIdx( const int64_t ClusterId,
			const std::string& TenantName, bool forceRead = false );

		virtual cfsec::ICFSecTenantObj* readCachedTenant( cfsec::CFSecTenantPKey* pkey );

		virtual cfsec::ICFSecTenantObj* readCachedTenantByIdIdx( const int64_t Id );

		virtual std::vector<cfsec::ICFSecTenantObj*> readCachedTenantByClusterIdx( const int64_t ClusterId );

		virtual cfsec::ICFSecTenantObj* readCachedTenantByUNameIdx( const int64_t ClusterId,
			const std::string& TenantName );

		virtual cfsec::ICFSecTenantObj* readTenantByLookupUNameIdx( const int64_t ClusterId,
			const std::string& TenantName, bool forceRead = false );

		virtual cfsec::ICFSecTenantObj* readCachedTenantByLookupUNameIdx( const int64_t ClusterId,
			const std::string& TenantName );

		virtual std::vector<cfsec::ICFSecTenantObj*> pageTenantByClusterIdx( const int64_t ClusterId,
			const int64_t* priorId );

		virtual cfsec::ICFSecTenantObj* updateTenant( cfsec::ICFSecTenantEditObj* Obj );

		virtual void deleteTenant( cfsec::ICFSecTenantEditObj* Obj );

		virtual void deleteTenantByIdIdx( const int64_t Id );

		virtual void deleteTenantByClusterIdx( const int64_t ClusterId );

		virtual void deleteTenantByUNameIdx( const int64_t ClusterId,
			const std::string& TenantName );

		virtual void reallyDetachFromIndexesTenant( cfsec::ICFSecTenantObj* Obj );

	virtual cfsec::ICFSecTenantObj* getSystemTenant();

	};

}
