#pragma once

// Description: C++18 Table Object specification for CFSec.

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

#include <cfsecobj/ICFSecSysClusterObj.hpp>
#include <cfsecobj/ICFSecSysClusterEditObj.hpp>
#include <cfsecobj/ICFSecSysClusterTableObj.hpp>

namespace cfsec {

	class CFSecSysClusterTableObj
	: public virtual ICFSecSysClusterTableObj
	{
	protected:
		cfsec::ICFSecSchemaObj* schema;
		std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* members;
		std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* allSysCluster;
		std::map< cfsec::CFSecSysClusterByClusterIdxKey,
			std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>*>* indexByClusterIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFSecSysClusterTableObj();
		CFSecSysClusterTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFSecSysClusterTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecSysClusterObj* newInstance();

		virtual cfsec::ICFSecSysClusterEditObj* newEditInstance( cfsec::ICFSecSysClusterObj* orig );

		virtual cfsec::ICFSecSysClusterObj* realizeSysCluster( cfsec::ICFSecSysClusterObj* Obj );

		virtual void deepDisposeByIdIdx( const int32_t SingletonId );
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId );
		virtual void reallyDeepDisposeSysCluster( cfsec::ICFSecSysClusterObj* Obj );
		virtual cfsec::ICFSecSysClusterObj* createSysCluster( cfsec::ICFSecSysClusterEditObj* Obj );

		virtual cfsec::ICFSecSysClusterObj* readSysCluster( cfsec::CFSecSysClusterPKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecSysClusterObj* lockSysCluster( cfsec::CFSecSysClusterPKey* pkey );

		virtual std::vector<cfsec::ICFSecSysClusterObj*> readAllSysCluster( bool forceRead = false );

		virtual cfsec::ICFSecSysClusterObj* readSysClusterByIdIdx( const int32_t SingletonId, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSysClusterObj*> readSysClusterByClusterIdx( const int64_t ClusterId,
			bool forceRead = false );

		virtual cfsec::ICFSecSysClusterObj* readCachedSysCluster( cfsec::CFSecSysClusterPKey* pkey );

		virtual cfsec::ICFSecSysClusterObj* readCachedSysClusterByIdIdx( const int32_t SingletonId );

		virtual std::vector<cfsec::ICFSecSysClusterObj*> readCachedSysClusterByClusterIdx( const int64_t ClusterId );

		virtual cfsec::ICFSecSysClusterObj* updateSysCluster( cfsec::ICFSecSysClusterEditObj* Obj );

		virtual void deleteSysCluster( cfsec::ICFSecSysClusterEditObj* Obj );

		virtual void deleteSysClusterByIdIdx( const int32_t SingletonId );

		virtual void deleteSysClusterByClusterIdx( const int64_t ClusterId );

		virtual void reallyDetachFromIndexesSysCluster( cfsec::ICFSecSysClusterObj* Obj );

	};

}
