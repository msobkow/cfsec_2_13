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

#include <cfsecobj/ICFSecHostNodeObj.hpp>
#include <cfsecobj/ICFSecHostNodeEditObj.hpp>
#include <cfsecobj/ICFSecHostNodeTableObj.hpp>

namespace cfsec {

	class CFSecHostNodeTableObj
	: public virtual ICFSecHostNodeTableObj
	{
	protected:
		cfsec::ICFSecSchemaObj* schema;
		std::map<cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj*>* members;
		std::map<cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj*>* allHostNode;
		std::map< cfsec::CFSecHostNodeByClusterIdxKey,
			std::map<cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj*>*>* indexByClusterIdx;
		std::map< cfsec::CFSecHostNodeByUDescrIdxKey,
			cfsec::ICFSecHostNodeObj*>* indexByUDescrIdx;
		std::map< cfsec::CFSecHostNodeByHostNameIdxKey,
			cfsec::ICFSecHostNodeObj*>* indexByHostNameIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFSecHostNodeTableObj();
		CFSecHostNodeTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFSecHostNodeTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecHostNodeObj* newInstance();

		virtual cfsec::ICFSecHostNodeEditObj* newEditInstance( cfsec::ICFSecHostNodeObj* orig );

		virtual cfsec::ICFSecHostNodeObj* realizeHostNode( cfsec::ICFSecHostNodeObj* Obj );

		virtual void deepDisposeByIdIdx( const int64_t ClusterId,
			const int64_t HostNodeId );
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId );
		virtual void deepDisposeByUDescrIdx( const int64_t ClusterId,
			const std::string& Description );
		virtual void deepDisposeByHostNameIdx( const int64_t ClusterId,
			const std::string& HostName );
		virtual void reallyDeepDisposeHostNode( cfsec::ICFSecHostNodeObj* Obj );
		virtual cfsec::ICFSecHostNodeObj* createHostNode( cfsec::ICFSecHostNodeEditObj* Obj );

		virtual cfsec::ICFSecHostNodeObj* readHostNode( cfsec::CFSecHostNodePKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecHostNodeObj* lockHostNode( cfsec::CFSecHostNodePKey* pkey );

		virtual std::vector<cfsec::ICFSecHostNodeObj*> readAllHostNode( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecHostNodeObj*> pageAllHostNode(const int64_t* priorClusterId,
			const int64_t* priorHostNodeId );

		virtual cfsec::ICFSecHostNodeObj* readHostNodeByIdIdx( const int64_t ClusterId,
			const int64_t HostNodeId, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecHostNodeObj*> readHostNodeByClusterIdx( const int64_t ClusterId,
			bool forceRead = false );

		virtual cfsec::ICFSecHostNodeObj* readHostNodeByUDescrIdx( const int64_t ClusterId,
			const std::string& Description, bool forceRead = false );

		virtual cfsec::ICFSecHostNodeObj* readHostNodeByHostNameIdx( const int64_t ClusterId,
			const std::string& HostName, bool forceRead = false );

		virtual cfsec::ICFSecHostNodeObj* readCachedHostNode( cfsec::CFSecHostNodePKey* pkey );

		virtual cfsec::ICFSecHostNodeObj* readCachedHostNodeByIdIdx( const int64_t ClusterId,
			const int64_t HostNodeId );

		virtual std::vector<cfsec::ICFSecHostNodeObj*> readCachedHostNodeByClusterIdx( const int64_t ClusterId );

		virtual cfsec::ICFSecHostNodeObj* readCachedHostNodeByUDescrIdx( const int64_t ClusterId,
			const std::string& Description );

		virtual cfsec::ICFSecHostNodeObj* readCachedHostNodeByHostNameIdx( const int64_t ClusterId,
			const std::string& HostName );

		virtual cfsec::ICFSecHostNodeObj* readHostNodeByLookupHostNameIdx( const int64_t ClusterId,
			const std::string& HostName, bool forceRead = false );

		virtual cfsec::ICFSecHostNodeObj* readCachedHostNodeByLookupHostNameIdx( const int64_t ClusterId,
			const std::string& HostName );

		virtual std::vector<cfsec::ICFSecHostNodeObj*> pageHostNodeByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorHostNodeId );

		virtual cfsec::ICFSecHostNodeObj* updateHostNode( cfsec::ICFSecHostNodeEditObj* Obj );

		virtual void deleteHostNode( cfsec::ICFSecHostNodeEditObj* Obj );

		virtual void deleteHostNodeByIdIdx( const int64_t ClusterId,
			const int64_t HostNodeId );

		virtual void deleteHostNodeByClusterIdx( const int64_t ClusterId );

		virtual void deleteHostNodeByUDescrIdx( const int64_t ClusterId,
			const std::string& Description );

		virtual void deleteHostNodeByHostNameIdx( const int64_t ClusterId,
			const std::string& HostName );

		virtual void reallyDetachFromIndexesHostNode( cfsec::ICFSecHostNodeObj* Obj );

	};

}
