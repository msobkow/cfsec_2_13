#pragma once

// Description: C++18 Table Object interface for CFSec.

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

#include <cfsecobj/ICFSecISOCtryObj.hpp>
#include <cfsecobj/ICFSecISOCtryEditObj.hpp>

namespace cfsec {

	class ICFSecISOCtryTableObj
	{
	public:
		ICFSecISOCtryTableObj();
		virtual ~ICFSecISOCtryTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema() = 0;
		virtual void setSchema( cfsec::ICFSecSchemaObj* value ) = 0;

		virtual void minimizeMemory() = 0;

		virtual const std::string getTableName() = 0;
		virtual const std::string getTableDbName() = 0;
		virtual const classcode_t* getObjQualifyingClassCode() = 0;

		virtual cfsec::ICFSecISOCtryObj* newInstance() = 0;

		virtual cfsec::ICFSecISOCtryEditObj* newEditInstance( cfsec::ICFSecISOCtryObj* orig ) = 0;

		virtual cfsec::ICFSecISOCtryObj* realizeISOCtry( cfsec::ICFSecISOCtryObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int16_t ISOCtryId ) = 0;
		virtual void deepDisposeByISOCodeIdx( const std::string& ISOCode ) = 0;
		virtual void deepDisposeByNameIdx( const std::string& Name ) = 0;
		virtual void reallyDeepDisposeISOCtry( cfsec::ICFSecISOCtryObj* Obj ) = 0;
		virtual cfsec::ICFSecISOCtryObj* createISOCtry( cfsec::ICFSecISOCtryEditObj* Obj ) = 0;

		virtual cfsec::ICFSecISOCtryObj* readISOCtry( cfsec::CFSecISOCtryPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryObj* lockISOCtry( cfsec::CFSecISOCtryPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecISOCtryObj*> readAllISOCtry( bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryObj* readISOCtryByIdIdx( const int16_t ISOCtryId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryObj* readISOCtryByISOCodeIdx(const std::string& ISOCode,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryObj* readISOCtryByNameIdx(const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryObj* readCachedISOCtry( cfsec::CFSecISOCtryPKey* pkey ) = 0;

		virtual cfsec::ICFSecISOCtryObj* readCachedISOCtryByIdIdx(const int16_t ISOCtryId ) = 0;

		virtual cfsec::ICFSecISOCtryObj* readCachedISOCtryByISOCodeIdx(const std::string& ISOCode ) = 0;

		virtual cfsec::ICFSecISOCtryObj* readCachedISOCtryByNameIdx(const std::string& Name ) = 0;

		virtual cfsec::ICFSecISOCtryObj* readISOCtryByLookupISOCodeIdx(const std::string& ISOCode,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryObj* readCachedISOCtryByLookupISOCodeIdx(const std::string& ISOCode ) = 0;

		virtual cfsec::ICFSecISOCtryObj* updateISOCtry( cfsec::ICFSecISOCtryEditObj* Obj ) = 0;

		virtual void deleteISOCtry( cfsec::ICFSecISOCtryEditObj* Obj ) = 0;

		virtual void deleteISOCtryByIdIdx( const int16_t ISOCtryId ) = 0;

		virtual void deleteISOCtryByISOCodeIdx(const std::string& ISOCode ) = 0;

		virtual void deleteISOCtryByNameIdx(const std::string& Name ) = 0;

		virtual void reallyDetachFromIndexesISOCtry( cfsec::ICFSecISOCtryObj* Obj ) = 0;

	};
}
