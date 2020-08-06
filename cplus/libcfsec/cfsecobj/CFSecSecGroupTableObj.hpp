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

#include <cfsecobj/ICFSecSecGroupObj.hpp>
#include <cfsecobj/ICFSecSecGroupEditObj.hpp>
#include <cfsecobj/ICFSecSecGroupTableObj.hpp>

namespace cfsec {

	class CFSecSecGroupTableObj
	: public virtual ICFSecSecGroupTableObj
	{
	protected:
		cfsec::ICFSecSchemaObj* schema;
		std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* members;
		std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* allSecGroup;
		std::map< cfsec::CFSecSecGroupByClusterIdxKey,
			std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>*>* indexByClusterIdx;
		std::map< cfsec::CFSecSecGroupByClusterVisIdxKey,
			std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>*>* indexByClusterVisIdx;
		std::map< cfsec::CFSecSecGroupByUNameIdxKey,
			cfsec::ICFSecSecGroupObj*>* indexByUNameIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFSecSecGroupTableObj();
		CFSecSecGroupTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFSecSecGroupTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecSecGroupObj* newInstance();

		virtual cfsec::ICFSecSecGroupEditObj* newEditInstance( cfsec::ICFSecSecGroupObj* orig );

		virtual cfsec::ICFSecSecGroupObj* realizeSecGroup( cfsec::ICFSecSecGroupObj* Obj );

		virtual void deepDisposeByIdIdx( const int64_t ClusterId,
			const int32_t SecGroupId );
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId );
		virtual void deepDisposeByClusterVisIdx( const int64_t ClusterId,
			const bool IsVisible );
		virtual void deepDisposeByUNameIdx( const int64_t ClusterId,
			const std::string& Name );
		virtual void reallyDeepDisposeSecGroup( cfsec::ICFSecSecGroupObj* Obj );
		virtual cfsec::ICFSecSecGroupObj* createSecGroup( cfsec::ICFSecSecGroupEditObj* Obj );

		virtual cfsec::ICFSecSecGroupObj* readSecGroup( cfsec::CFSecSecGroupPKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecSecGroupObj* lockSecGroup( cfsec::CFSecSecGroupPKey* pkey );

		virtual std::vector<cfsec::ICFSecSecGroupObj*> readAllSecGroup( bool forceRead = false );

		virtual cfsec::ICFSecSecGroupObj* readSecGroupByIdIdx( const int64_t ClusterId,
			const int32_t SecGroupId, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGroupObj*> readSecGroupByClusterIdx( const int64_t ClusterId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGroupObj*> readSecGroupByClusterVisIdx( const int64_t ClusterId,
			const bool IsVisible,
			bool forceRead = false );

		virtual cfsec::ICFSecSecGroupObj* readSecGroupByUNameIdx( const int64_t ClusterId,
			const std::string& Name, bool forceRead = false );

		virtual cfsec::ICFSecSecGroupObj* readCachedSecGroup( cfsec::CFSecSecGroupPKey* pkey );

		virtual cfsec::ICFSecSecGroupObj* readCachedSecGroupByIdIdx( const int64_t ClusterId,
			const int32_t SecGroupId );

		virtual std::vector<cfsec::ICFSecSecGroupObj*> readCachedSecGroupByClusterIdx( const int64_t ClusterId );

		virtual std::vector<cfsec::ICFSecSecGroupObj*> readCachedSecGroupByClusterVisIdx( const int64_t ClusterId,
			const bool IsVisible );

		virtual cfsec::ICFSecSecGroupObj* readCachedSecGroupByUNameIdx( const int64_t ClusterId,
			const std::string& Name );

		virtual cfsec::ICFSecSecGroupObj* readSecGroupByLookupUNameIdx( const int64_t ClusterId,
			const std::string& Name, bool forceRead = false );

		virtual cfsec::ICFSecSecGroupObj* readCachedSecGroupByLookupUNameIdx( const int64_t ClusterId,
			const std::string& Name );

		virtual cfsec::ICFSecSecGroupObj* updateSecGroup( cfsec::ICFSecSecGroupEditObj* Obj );

		virtual void deleteSecGroup( cfsec::ICFSecSecGroupEditObj* Obj );

		virtual void deleteSecGroupByIdIdx( const int64_t ClusterId,
			const int32_t SecGroupId );

		virtual void deleteSecGroupByClusterIdx( const int64_t ClusterId );

		virtual void deleteSecGroupByClusterVisIdx( const int64_t ClusterId,
			const bool IsVisible );

		virtual void deleteSecGroupByUNameIdx( const int64_t ClusterId,
			const std::string& Name );

		virtual void reallyDetachFromIndexesSecGroup( cfsec::ICFSecSecGroupObj* Obj );

	};

}
