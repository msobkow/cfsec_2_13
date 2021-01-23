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

#include <cfsecobj/ICFSecServiceObj.hpp>
#include <cfsecobj/ICFSecServiceEditObj.hpp>
#include <cfsecobj/ICFSecServiceTableObj.hpp>

namespace cfsec {

	class CFSecServiceTableObj
	: public virtual ICFSecServiceTableObj
	{
	protected:
		cfsec::ICFSecSchemaObj* schema;
		std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* members;
		std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* allService;
		std::map< cfsec::CFSecServiceByClusterIdxKey,
			std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>*>* indexByClusterIdx;
		std::map< cfsec::CFSecServiceByHostIdxKey,
			std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>*>* indexByHostIdx;
		std::map< cfsec::CFSecServiceByTypeIdxKey,
			std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>*>* indexByTypeIdx;
		std::map< cfsec::CFSecServiceByUTypeIdxKey,
			cfsec::ICFSecServiceObj*>* indexByUTypeIdx;
		std::map< cfsec::CFSecServiceByUHostPortIdxKey,
			cfsec::ICFSecServiceObj*>* indexByUHostPortIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFSecServiceTableObj();
		CFSecServiceTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFSecServiceTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecServiceObj* newInstance();

		virtual cfsec::ICFSecServiceEditObj* newEditInstance( cfsec::ICFSecServiceObj* orig );

		virtual cfsec::ICFSecServiceObj* realizeService( cfsec::ICFSecServiceObj* Obj );

		virtual void deepDisposeByIdIdx( const int64_t ClusterId,
			const int64_t ServiceId );
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId );
		virtual void deepDisposeByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId );
		virtual void deepDisposeByTypeIdx( const int32_t ServiceTypeId );
		virtual void deepDisposeByUTypeIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId );
		virtual void deepDisposeByUHostPortIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort );
		virtual void reallyDeepDisposeService( cfsec::ICFSecServiceObj* Obj );
		virtual cfsec::ICFSecServiceObj* createService( cfsec::ICFSecServiceEditObj* Obj );

		virtual cfsec::ICFSecServiceObj* readService( cfsec::CFSecServicePKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecServiceObj* lockService( cfsec::CFSecServicePKey* pkey );

		virtual std::vector<cfsec::ICFSecServiceObj*> readAllService( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecServiceObj*> pageAllService(const int64_t* priorClusterId,
			const int64_t* priorServiceId );

		virtual cfsec::ICFSecServiceObj* readServiceByIdIdx( const int64_t ClusterId,
			const int64_t ServiceId, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecServiceObj*> readServiceByClusterIdx( const int64_t ClusterId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecServiceObj*> readServiceByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecServiceObj*> readServiceByTypeIdx( const int32_t ServiceTypeId,
			bool forceRead = false );

		virtual cfsec::ICFSecServiceObj* readServiceByUTypeIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId, bool forceRead = false );

		virtual cfsec::ICFSecServiceObj* readServiceByUHostPortIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort, bool forceRead = false );

		virtual cfsec::ICFSecServiceObj* readCachedService( cfsec::CFSecServicePKey* pkey );

		virtual cfsec::ICFSecServiceObj* readCachedServiceByIdIdx( const int64_t ClusterId,
			const int64_t ServiceId );

		virtual std::vector<cfsec::ICFSecServiceObj*> readCachedServiceByClusterIdx( const int64_t ClusterId );

		virtual std::vector<cfsec::ICFSecServiceObj*> readCachedServiceByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId );

		virtual std::vector<cfsec::ICFSecServiceObj*> readCachedServiceByTypeIdx( const int32_t ServiceTypeId );

		virtual cfsec::ICFSecServiceObj* readCachedServiceByUTypeIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId );

		virtual cfsec::ICFSecServiceObj* readCachedServiceByUHostPortIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort );

		virtual std::vector<cfsec::ICFSecServiceObj*> pageServiceByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId );

		virtual std::vector<cfsec::ICFSecServiceObj*> pageServiceByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId );

		virtual std::vector<cfsec::ICFSecServiceObj*> pageServiceByTypeIdx( const int32_t ServiceTypeId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId );

		virtual cfsec::ICFSecServiceObj* updateService( cfsec::ICFSecServiceEditObj* Obj );

		virtual void deleteService( cfsec::ICFSecServiceEditObj* Obj );

		virtual void deleteServiceByIdIdx( const int64_t ClusterId,
			const int64_t ServiceId );

		virtual void deleteServiceByClusterIdx( const int64_t ClusterId );

		virtual void deleteServiceByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId );

		virtual void deleteServiceByTypeIdx( const int32_t ServiceTypeId );

		virtual void deleteServiceByUTypeIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId );

		virtual void deleteServiceByUHostPortIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort );

		virtual void reallyDetachFromIndexesService( cfsec::ICFSecServiceObj* Obj );

	};

}
