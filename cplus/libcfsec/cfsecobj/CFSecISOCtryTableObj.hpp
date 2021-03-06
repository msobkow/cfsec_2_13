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

#include <cfsecobj/ICFSecISOCtryObj.hpp>
#include <cfsecobj/ICFSecISOCtryEditObj.hpp>
#include <cfsecobj/ICFSecISOCtryTableObj.hpp>

namespace cfsec {

	class CFSecISOCtryTableObj
	: public virtual ICFSecISOCtryTableObj
	{
	protected:
		cfsec::ICFSecSchemaObj* schema;
		std::map<cfsec::CFSecISOCtryPKey, cfsec::ICFSecISOCtryObj*>* members;
		std::map<cfsec::CFSecISOCtryPKey, cfsec::ICFSecISOCtryObj*>* allISOCtry;
		std::map< cfsec::CFSecISOCtryByISOCodeIdxKey,
			cfsec::ICFSecISOCtryObj*>* indexByISOCodeIdx;
		std::map< cfsec::CFSecISOCtryByNameIdxKey,
			cfsec::ICFSecISOCtryObj*>* indexByNameIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFSecISOCtryTableObj();
		CFSecISOCtryTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFSecISOCtryTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecISOCtryObj* newInstance();

		virtual cfsec::ICFSecISOCtryEditObj* newEditInstance( cfsec::ICFSecISOCtryObj* orig );

		virtual cfsec::ICFSecISOCtryObj* realizeISOCtry( cfsec::ICFSecISOCtryObj* Obj );

		virtual void deepDisposeByIdIdx( const int16_t ISOCtryId );
		virtual void deepDisposeByISOCodeIdx( const std::string& ISOCode );
		virtual void deepDisposeByNameIdx( const std::string& Name );
		virtual void reallyDeepDisposeISOCtry( cfsec::ICFSecISOCtryObj* Obj );
		virtual cfsec::ICFSecISOCtryObj* createISOCtry( cfsec::ICFSecISOCtryEditObj* Obj );

		virtual cfsec::ICFSecISOCtryObj* readISOCtry( cfsec::CFSecISOCtryPKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecISOCtryObj* lockISOCtry( cfsec::CFSecISOCtryPKey* pkey );

		virtual std::vector<cfsec::ICFSecISOCtryObj*> readAllISOCtry( bool forceRead = false );

		virtual cfsec::ICFSecISOCtryObj* readISOCtryByIdIdx( const int16_t ISOCtryId, bool forceRead = false );

		virtual cfsec::ICFSecISOCtryObj* readISOCtryByISOCodeIdx( const std::string& ISOCode, bool forceRead = false );

		virtual cfsec::ICFSecISOCtryObj* readISOCtryByNameIdx( const std::string& Name, bool forceRead = false );

		virtual cfsec::ICFSecISOCtryObj* readCachedISOCtry( cfsec::CFSecISOCtryPKey* pkey );

		virtual cfsec::ICFSecISOCtryObj* readCachedISOCtryByIdIdx( const int16_t ISOCtryId );

		virtual cfsec::ICFSecISOCtryObj* readCachedISOCtryByISOCodeIdx( const std::string& ISOCode );

		virtual cfsec::ICFSecISOCtryObj* readCachedISOCtryByNameIdx( const std::string& Name );

		virtual cfsec::ICFSecISOCtryObj* readISOCtryByLookupISOCodeIdx( const std::string& ISOCode, bool forceRead = false );

		virtual cfsec::ICFSecISOCtryObj* readCachedISOCtryByLookupISOCodeIdx( const std::string& ISOCode );

		virtual cfsec::ICFSecISOCtryObj* updateISOCtry( cfsec::ICFSecISOCtryEditObj* Obj );

		virtual void deleteISOCtry( cfsec::ICFSecISOCtryEditObj* Obj );

		virtual void deleteISOCtryByIdIdx( const int16_t ISOCtryId );

		virtual void deleteISOCtryByISOCodeIdx( const std::string& ISOCode );

		virtual void deleteISOCtryByNameIdx( const std::string& Name );

		virtual void reallyDetachFromIndexesISOCtry( cfsec::ICFSecISOCtryObj* Obj );

	};

}
