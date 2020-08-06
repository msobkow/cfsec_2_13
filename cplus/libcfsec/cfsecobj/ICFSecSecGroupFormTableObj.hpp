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

#include <cfsecobj/ICFSecSecGroupFormObj.hpp>
#include <cfsecobj/ICFSecSecGroupFormEditObj.hpp>

namespace cfsec {

	class ICFSecSecGroupFormTableObj
	{
	public:
		ICFSecSecGroupFormTableObj();
		virtual ~ICFSecSecGroupFormTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema() = 0;
		virtual void setSchema( cfsec::ICFSecSchemaObj* value ) = 0;

		virtual void minimizeMemory() = 0;

		virtual const std::string getTableName() = 0;
		virtual const std::string getTableDbName() = 0;
		virtual const classcode_t* getObjQualifyingClassCode() = 0;

		virtual cfsec::ICFSecSecGroupFormObj* newInstance() = 0;

		virtual cfsec::ICFSecSecGroupFormEditObj* newEditInstance( cfsec::ICFSecSecGroupFormObj* orig ) = 0;

		virtual cfsec::ICFSecSecGroupFormObj* realizeSecGroupForm( cfsec::ICFSecSecGroupFormObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int64_t ClusterId,
			const int64_t SecGroupFormId ) = 0;
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId ) = 0;
		virtual void deepDisposeByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;
		virtual void deepDisposeByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId ) = 0;
		virtual void deepDisposeByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId ) = 0;
		virtual void deepDisposeByUFormIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId ) = 0;
		virtual void reallyDeepDisposeSecGroupForm( cfsec::ICFSecSecGroupFormObj* Obj ) = 0;
		virtual cfsec::ICFSecSecGroupFormObj* createSecGroupForm( cfsec::ICFSecSecGroupFormEditObj* Obj ) = 0;

		virtual cfsec::ICFSecSecGroupFormObj* readSecGroupForm( cfsec::CFSecSecGroupFormPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecGroupFormObj* lockSecGroupForm( cfsec::CFSecSecGroupFormPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readAllSecGroupForm( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> pageAllSecGroupForm(const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId ) = 0;

		virtual cfsec::ICFSecSecGroupFormObj* readSecGroupFormByIdIdx( const int64_t ClusterId,
			const int64_t SecGroupFormId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readSecGroupFormByClusterIdx( const int64_t ClusterId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readSecGroupFormByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readSecGroupFormByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readSecGroupFormByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecGroupFormObj* readSecGroupFormByUFormIdx(const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecGroupFormObj* readCachedSecGroupForm( cfsec::CFSecSecGroupFormPKey* pkey ) = 0;

		virtual cfsec::ICFSecSecGroupFormObj* readCachedSecGroupFormByIdIdx(const int64_t ClusterId,
			const int64_t SecGroupFormId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readCachedSecGroupFormByClusterIdx( const int64_t ClusterId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readCachedSecGroupFormByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readCachedSecGroupFormByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readCachedSecGroupFormByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId ) = 0;

		virtual cfsec::ICFSecSecGroupFormObj* readCachedSecGroupFormByUFormIdx(const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> pageSecGroupFormByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> pageSecGroupFormByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> pageSecGroupFormByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> pageSecGroupFormByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId ) = 0;

		virtual cfsec::ICFSecSecGroupFormObj* updateSecGroupForm( cfsec::ICFSecSecGroupFormEditObj* Obj ) = 0;

		virtual void deleteSecGroupForm( cfsec::ICFSecSecGroupFormEditObj* Obj ) = 0;

		virtual void deleteSecGroupFormByIdIdx( const int64_t ClusterId,
			const int64_t SecGroupFormId ) = 0;

		virtual void deleteSecGroupFormByClusterIdx( const int64_t ClusterId ) = 0;

		virtual void deleteSecGroupFormByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;

		virtual void deleteSecGroupFormByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId ) = 0;

		virtual void deleteSecGroupFormByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId ) = 0;

		virtual void deleteSecGroupFormByUFormIdx(const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId ) = 0;

		virtual void reallyDetachFromIndexesSecGroupForm( cfsec::ICFSecSecGroupFormObj* Obj ) = 0;

	};
}
