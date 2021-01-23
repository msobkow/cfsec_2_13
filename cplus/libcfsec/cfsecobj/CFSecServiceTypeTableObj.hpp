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

#include <cfsecobj/ICFSecServiceTypeObj.hpp>
#include <cfsecobj/ICFSecServiceTypeEditObj.hpp>
#include <cfsecobj/ICFSecServiceTypeTableObj.hpp>

namespace cfsec {

	class CFSecServiceTypeTableObj
	: public virtual ICFSecServiceTypeTableObj
	{
	protected:
		cfsec::ICFSecSchemaObj* schema;
		std::map<cfsec::CFSecServiceTypePKey, cfsec::ICFSecServiceTypeObj*>* members;
		std::map<cfsec::CFSecServiceTypePKey, cfsec::ICFSecServiceTypeObj*>* allServiceType;
		std::map< cfsec::CFSecServiceTypeByUDescrIdxKey,
			cfsec::ICFSecServiceTypeObj*>* indexByUDescrIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFSecServiceTypeTableObj();
		CFSecServiceTypeTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFSecServiceTypeTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecServiceTypeObj* newInstance();

		virtual cfsec::ICFSecServiceTypeEditObj* newEditInstance( cfsec::ICFSecServiceTypeObj* orig );

		virtual cfsec::ICFSecServiceTypeObj* realizeServiceType( cfsec::ICFSecServiceTypeObj* Obj );

		virtual void deepDisposeByIdIdx( const int32_t ServiceTypeId );
		virtual void deepDisposeByUDescrIdx( const std::string& Description );
		virtual void reallyDeepDisposeServiceType( cfsec::ICFSecServiceTypeObj* Obj );
		virtual cfsec::ICFSecServiceTypeObj* createServiceType( cfsec::ICFSecServiceTypeEditObj* Obj );

		virtual cfsec::ICFSecServiceTypeObj* readServiceType( cfsec::CFSecServiceTypePKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecServiceTypeObj* lockServiceType( cfsec::CFSecServiceTypePKey* pkey );

		virtual std::vector<cfsec::ICFSecServiceTypeObj*> readAllServiceType( bool forceRead = false );

		virtual cfsec::ICFSecServiceTypeObj* readServiceTypeByIdIdx( const int32_t ServiceTypeId, bool forceRead = false );

		virtual cfsec::ICFSecServiceTypeObj* readServiceTypeByUDescrIdx( const std::string& Description, bool forceRead = false );

		virtual cfsec::ICFSecServiceTypeObj* readCachedServiceType( cfsec::CFSecServiceTypePKey* pkey );

		virtual cfsec::ICFSecServiceTypeObj* readCachedServiceTypeByIdIdx( const int32_t ServiceTypeId );

		virtual cfsec::ICFSecServiceTypeObj* readCachedServiceTypeByUDescrIdx( const std::string& Description );

		virtual cfsec::ICFSecServiceTypeObj* readServiceTypeByLookupUDescrIdx( const std::string& Description, bool forceRead = false );

		virtual cfsec::ICFSecServiceTypeObj* readCachedServiceTypeByLookupUDescrIdx( const std::string& Description );

		virtual cfsec::ICFSecServiceTypeObj* updateServiceType( cfsec::ICFSecServiceTypeEditObj* Obj );

		virtual void deleteServiceType( cfsec::ICFSecServiceTypeEditObj* Obj );

		virtual void deleteServiceTypeByIdIdx( const int32_t ServiceTypeId );

		virtual void deleteServiceTypeByUDescrIdx( const std::string& Description );

		virtual void reallyDetachFromIndexesServiceType( cfsec::ICFSecServiceTypeObj* Obj );

	};

}
