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

#include <cfsecobj/ICFSecSecAppObj.hpp>
#include <cfsecobj/ICFSecSecAppEditObj.hpp>
#include <cfsecobj/ICFSecSecAppTableObj.hpp>

namespace cfsec {

	class CFSecSecAppTableObj
	: public virtual ICFSecSecAppTableObj
	{
	protected:
		cfsec::ICFSecSchemaObj* schema;
		std::map<cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj*>* members;
		std::map<cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj*>* allSecApp;
		std::map< cfsec::CFSecSecAppByClusterIdxKey,
			std::map<cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj*>*>* indexByClusterIdx;
		std::map< cfsec::CFSecSecAppByUJEEMountIdxKey,
			cfsec::ICFSecSecAppObj*>* indexByUJEEMountIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFSecSecAppTableObj();
		CFSecSecAppTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFSecSecAppTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecSecAppObj* newInstance();

		virtual cfsec::ICFSecSecAppEditObj* newEditInstance( cfsec::ICFSecSecAppObj* orig );

		virtual cfsec::ICFSecSecAppObj* realizeSecApp( cfsec::ICFSecSecAppObj* Obj );

		virtual void deepDisposeByIdIdx( const int64_t ClusterId,
			const int32_t SecAppId );
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId );
		virtual void deepDisposeByUJEEMountIdx( const int64_t ClusterId,
			const std::string& JEEMountName );
		virtual void reallyDeepDisposeSecApp( cfsec::ICFSecSecAppObj* Obj );
		virtual cfsec::ICFSecSecAppObj* createSecApp( cfsec::ICFSecSecAppEditObj* Obj );

		virtual cfsec::ICFSecSecAppObj* readSecApp( cfsec::CFSecSecAppPKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecSecAppObj* lockSecApp( cfsec::CFSecSecAppPKey* pkey );

		virtual std::vector<cfsec::ICFSecSecAppObj*> readAllSecApp( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecAppObj*> pageAllSecApp(const int64_t* priorClusterId,
			const int32_t* priorSecAppId );

		virtual cfsec::ICFSecSecAppObj* readSecAppByIdIdx( const int64_t ClusterId,
			const int32_t SecAppId, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecAppObj*> readSecAppByClusterIdx( const int64_t ClusterId,
			bool forceRead = false );

		virtual cfsec::ICFSecSecAppObj* readSecAppByUJEEMountIdx( const int64_t ClusterId,
			const std::string& JEEMountName, bool forceRead = false );

		virtual cfsec::ICFSecSecAppObj* readCachedSecApp( cfsec::CFSecSecAppPKey* pkey );

		virtual cfsec::ICFSecSecAppObj* readCachedSecAppByIdIdx( const int64_t ClusterId,
			const int32_t SecAppId );

		virtual std::vector<cfsec::ICFSecSecAppObj*> readCachedSecAppByClusterIdx( const int64_t ClusterId );

		virtual cfsec::ICFSecSecAppObj* readCachedSecAppByUJEEMountIdx( const int64_t ClusterId,
			const std::string& JEEMountName );

		virtual cfsec::ICFSecSecAppObj* readSecAppByLookupUJEEMountIdx( const int64_t ClusterId,
			const std::string& JEEMountName, bool forceRead = false );

		virtual cfsec::ICFSecSecAppObj* readCachedSecAppByLookupUJEEMountIdx( const int64_t ClusterId,
			const std::string& JEEMountName );

		virtual std::vector<cfsec::ICFSecSecAppObj*> pageSecAppByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int32_t* priorSecAppId );

		virtual cfsec::ICFSecSecAppObj* updateSecApp( cfsec::ICFSecSecAppEditObj* Obj );

		virtual void deleteSecApp( cfsec::ICFSecSecAppEditObj* Obj );

		virtual void deleteSecAppByIdIdx( const int64_t ClusterId,
			const int32_t SecAppId );

		virtual void deleteSecAppByClusterIdx( const int64_t ClusterId );

		virtual void deleteSecAppByUJEEMountIdx( const int64_t ClusterId,
			const std::string& JEEMountName );

		virtual void reallyDetachFromIndexesSecApp( cfsec::ICFSecSecAppObj* Obj );

	};

}
