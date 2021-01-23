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

#include <cfsecobj/ICFSecISOCtryCcyObj.hpp>
#include <cfsecobj/ICFSecISOCtryCcyEditObj.hpp>

namespace cfsec {

	class ICFSecISOCtryCcyTableObj
	{
	public:
		ICFSecISOCtryCcyTableObj();
		virtual ~ICFSecISOCtryCcyTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema() = 0;
		virtual void setSchema( cfsec::ICFSecSchemaObj* value ) = 0;

		virtual void minimizeMemory() = 0;

		virtual const std::string getTableName() = 0;
		virtual const std::string getTableDbName() = 0;
		virtual const classcode_t* getObjQualifyingClassCode() = 0;

		virtual cfsec::ICFSecISOCtryCcyObj* newInstance() = 0;

		virtual cfsec::ICFSecISOCtryCcyEditObj* newEditInstance( cfsec::ICFSecISOCtryCcyObj* orig ) = 0;

		virtual cfsec::ICFSecISOCtryCcyObj* realizeISOCtryCcy( cfsec::ICFSecISOCtryCcyObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOCcyId ) = 0;
		virtual void deepDisposeByCtryIdx( const int16_t ISOCtryId ) = 0;
		virtual void deepDisposeByCcyIdx( const int16_t ISOCcyId ) = 0;
		virtual void reallyDeepDisposeISOCtryCcy( cfsec::ICFSecISOCtryCcyObj* Obj ) = 0;
		virtual cfsec::ICFSecISOCtryCcyObj* createISOCtryCcy( cfsec::ICFSecISOCtryCcyEditObj* Obj ) = 0;

		virtual cfsec::ICFSecISOCtryCcyObj* readISOCtryCcy( cfsec::CFSecISOCtryCcyPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryCcyObj* lockISOCtryCcy( cfsec::CFSecISOCtryCcyPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecISOCtryCcyObj*> readAllISOCtryCcy( bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryCcyObj* readISOCtryCcyByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOCcyId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecISOCtryCcyObj*> readISOCtryCcyByCtryIdx( const int16_t ISOCtryId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecISOCtryCcyObj*> readISOCtryCcyByCcyIdx( const int16_t ISOCcyId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryCcyObj* readCachedISOCtryCcy( cfsec::CFSecISOCtryCcyPKey* pkey ) = 0;

		virtual cfsec::ICFSecISOCtryCcyObj* readCachedISOCtryCcyByIdIdx(const int16_t ISOCtryId,
			const int16_t ISOCcyId ) = 0;

		virtual std::vector<cfsec::ICFSecISOCtryCcyObj*> readCachedISOCtryCcyByCtryIdx( const int16_t ISOCtryId ) = 0;

		virtual std::vector<cfsec::ICFSecISOCtryCcyObj*> readCachedISOCtryCcyByCcyIdx( const int16_t ISOCcyId ) = 0;

		virtual cfsec::ICFSecISOCtryCcyObj* updateISOCtryCcy( cfsec::ICFSecISOCtryCcyEditObj* Obj ) = 0;

		virtual void deleteISOCtryCcy( cfsec::ICFSecISOCtryCcyEditObj* Obj ) = 0;

		virtual void deleteISOCtryCcyByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOCcyId ) = 0;

		virtual void deleteISOCtryCcyByCtryIdx( const int16_t ISOCtryId ) = 0;

		virtual void deleteISOCtryCcyByCcyIdx( const int16_t ISOCcyId ) = 0;

		virtual void reallyDetachFromIndexesISOCtryCcy( cfsec::ICFSecISOCtryCcyObj* Obj ) = 0;

	};
}
