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

#include <cfsecobj/ICFSecISOLangObj.hpp>
#include <cfsecobj/ICFSecISOLangEditObj.hpp>

namespace cfsec {

	class ICFSecISOLangTableObj
	{
	public:
		ICFSecISOLangTableObj();
		virtual ~ICFSecISOLangTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema() = 0;
		virtual void setSchema( cfsec::ICFSecSchemaObj* value ) = 0;

		virtual void minimizeMemory() = 0;

		virtual const std::string getTableName() = 0;
		virtual const std::string getTableDbName() = 0;
		virtual const classcode_t* getObjQualifyingClassCode() = 0;

		virtual cfsec::ICFSecISOLangObj* newInstance() = 0;

		virtual cfsec::ICFSecISOLangEditObj* newEditInstance( cfsec::ICFSecISOLangObj* orig ) = 0;

		virtual cfsec::ICFSecISOLangObj* realizeISOLang( cfsec::ICFSecISOLangObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int16_t ISOLangId ) = 0;
		virtual void deepDisposeByCode3Idx( const std::string& ISO6392Code ) = 0;
		virtual void deepDisposeByCode2Idx( const std::string* ISO6391Code ) = 0;
		virtual void reallyDeepDisposeISOLang( cfsec::ICFSecISOLangObj* Obj ) = 0;
		virtual cfsec::ICFSecISOLangObj* createISOLang( cfsec::ICFSecISOLangEditObj* Obj ) = 0;

		virtual cfsec::ICFSecISOLangObj* readISOLang( cfsec::CFSecISOLangPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOLangObj* lockISOLang( cfsec::CFSecISOLangPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecISOLangObj*> readAllISOLang( bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOLangObj* readISOLangByIdIdx( const int16_t ISOLangId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOLangObj* readISOLangByCode3Idx(const std::string& ISO6392Code,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecISOLangObj*> readISOLangByCode2Idx( const std::string* ISO6391Code,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOLangObj* readCachedISOLang( cfsec::CFSecISOLangPKey* pkey ) = 0;

		virtual cfsec::ICFSecISOLangObj* readCachedISOLangByIdIdx(const int16_t ISOLangId ) = 0;

		virtual cfsec::ICFSecISOLangObj* readCachedISOLangByCode3Idx(const std::string& ISO6392Code ) = 0;

		virtual std::vector<cfsec::ICFSecISOLangObj*> readCachedISOLangByCode2Idx( const std::string* ISO6391Code ) = 0;

		virtual cfsec::ICFSecISOLangObj* readISOLangByLookupCode3Idx(const std::string& ISO6392Code,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOLangObj* readCachedISOLangByLookupCode3Idx(const std::string& ISO6392Code ) = 0;

		virtual cfsec::ICFSecISOLangObj* updateISOLang( cfsec::ICFSecISOLangEditObj* Obj ) = 0;

		virtual void deleteISOLang( cfsec::ICFSecISOLangEditObj* Obj ) = 0;

		virtual void deleteISOLangByIdIdx( const int16_t ISOLangId ) = 0;

		virtual void deleteISOLangByCode3Idx(const std::string& ISO6392Code ) = 0;

		virtual void deleteISOLangByCode2Idx( const std::string* ISO6391Code ) = 0;

		virtual void reallyDetachFromIndexesISOLang( cfsec::ICFSecISOLangObj* Obj ) = 0;

	};
}
