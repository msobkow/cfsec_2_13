#pragma once

// Description: C++18 Table Object specification for CFSec.

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
#include <cfsecobj/ICFSecSecGroupFormTableObj.hpp>

namespace cfsec {

	class CFSecSecGroupFormTableObj
	: public virtual ICFSecSecGroupFormTableObj
	{
	protected:
		cfsec::ICFSecSchemaObj* schema;
		std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* members;
		std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* allSecGroupForm;
		std::map< cfsec::CFSecSecGroupFormByClusterIdxKey,
			std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>*>* indexByClusterIdx;
		std::map< cfsec::CFSecSecGroupFormByGroupIdxKey,
			std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>*>* indexByGroupIdx;
		std::map< cfsec::CFSecSecGroupFormByAppIdxKey,
			std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>*>* indexByAppIdx;
		std::map< cfsec::CFSecSecGroupFormByFormIdxKey,
			std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>*>* indexByFormIdx;
		std::map< cfsec::CFSecSecGroupFormByUFormIdxKey,
			cfsec::ICFSecSecGroupFormObj*>* indexByUFormIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFSecSecGroupFormTableObj();
		CFSecSecGroupFormTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFSecSecGroupFormTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecSecGroupFormObj* newInstance();

		virtual cfsec::ICFSecSecGroupFormEditObj* newEditInstance( cfsec::ICFSecSecGroupFormObj* orig );

		virtual cfsec::ICFSecSecGroupFormObj* realizeSecGroupForm( cfsec::ICFSecSecGroupFormObj* Obj );

		virtual void deepDisposeByIdIdx( const int64_t ClusterId,
			const int64_t SecGroupFormId );
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId );
		virtual void deepDisposeByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId );
		virtual void deepDisposeByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId );
		virtual void deepDisposeByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId );
		virtual void deepDisposeByUFormIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId );
		virtual void reallyDeepDisposeSecGroupForm( cfsec::ICFSecSecGroupFormObj* Obj );
		virtual cfsec::ICFSecSecGroupFormObj* createSecGroupForm( cfsec::ICFSecSecGroupFormEditObj* Obj );

		virtual cfsec::ICFSecSecGroupFormObj* readSecGroupForm( cfsec::CFSecSecGroupFormPKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecSecGroupFormObj* lockSecGroupForm( cfsec::CFSecSecGroupFormPKey* pkey );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readAllSecGroupForm( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> pageAllSecGroupForm(const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId );

		virtual cfsec::ICFSecSecGroupFormObj* readSecGroupFormByIdIdx( const int64_t ClusterId,
			const int64_t SecGroupFormId, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readSecGroupFormByClusterIdx( const int64_t ClusterId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readSecGroupFormByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readSecGroupFormByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readSecGroupFormByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId,
			bool forceRead = false );

		virtual cfsec::ICFSecSecGroupFormObj* readSecGroupFormByUFormIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId, bool forceRead = false );

		virtual cfsec::ICFSecSecGroupFormObj* readCachedSecGroupForm( cfsec::CFSecSecGroupFormPKey* pkey );

		virtual cfsec::ICFSecSecGroupFormObj* readCachedSecGroupFormByIdIdx( const int64_t ClusterId,
			const int64_t SecGroupFormId );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readCachedSecGroupFormByClusterIdx( const int64_t ClusterId );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readCachedSecGroupFormByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readCachedSecGroupFormByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readCachedSecGroupFormByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId );

		virtual cfsec::ICFSecSecGroupFormObj* readCachedSecGroupFormByUFormIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> pageSecGroupFormByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> pageSecGroupFormByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> pageSecGroupFormByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> pageSecGroupFormByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId );

		virtual cfsec::ICFSecSecGroupFormObj* updateSecGroupForm( cfsec::ICFSecSecGroupFormEditObj* Obj );

		virtual void deleteSecGroupForm( cfsec::ICFSecSecGroupFormEditObj* Obj );

		virtual void deleteSecGroupFormByIdIdx( const int64_t ClusterId,
			const int64_t SecGroupFormId );

		virtual void deleteSecGroupFormByClusterIdx( const int64_t ClusterId );

		virtual void deleteSecGroupFormByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId );

		virtual void deleteSecGroupFormByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId );

		virtual void deleteSecGroupFormByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId );

		virtual void deleteSecGroupFormByUFormIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId );

		virtual void reallyDetachFromIndexesSecGroupForm( cfsec::ICFSecSecGroupFormObj* Obj );

	};

}
