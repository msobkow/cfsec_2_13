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

#include <cfsecobj/ICFSecClusterObj.hpp>
#include <cfsecobj/ICFSecClusterEditObj.hpp>
#include <cfsecobj/ICFSecClusterTableObj.hpp>

namespace cfsec {

	class CFSecClusterTableObj
	: public virtual ICFSecClusterTableObj
	{
	protected:
		cfsec::ICFSecSchemaObj* schema;
		std::map<cfsec::CFSecClusterPKey, cfsec::ICFSecClusterObj*>* members;
		std::map<cfsec::CFSecClusterPKey, cfsec::ICFSecClusterObj*>* allCluster;
		std::map< cfsec::CFSecClusterByUDomNameIdxKey,
			cfsec::ICFSecClusterObj*>* indexByUDomNameIdx;
		std::map< cfsec::CFSecClusterByUDescrIdxKey,
			cfsec::ICFSecClusterObj*>* indexByUDescrIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFSecClusterTableObj();
		CFSecClusterTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFSecClusterTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecClusterObj* newInstance();

		virtual cfsec::ICFSecClusterEditObj* newEditInstance( cfsec::ICFSecClusterObj* orig );

		virtual cfsec::ICFSecClusterObj* realizeCluster( cfsec::ICFSecClusterObj* Obj );

		virtual void deepDisposeByIdIdx( const int64_t Id );
		virtual void deepDisposeByUDomNameIdx( const std::string& FullDomName );
		virtual void deepDisposeByUDescrIdx( const std::string& Description );
		virtual void reallyDeepDisposeCluster( cfsec::ICFSecClusterObj* Obj );
		virtual cfsec::ICFSecClusterObj* createCluster( cfsec::ICFSecClusterEditObj* Obj );

		virtual cfsec::ICFSecClusterObj* readCluster( cfsec::CFSecClusterPKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecClusterObj* lockCluster( cfsec::CFSecClusterPKey* pkey );

		virtual std::vector<cfsec::ICFSecClusterObj*> readAllCluster( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecClusterObj*> pageAllCluster(const int64_t* priorId );

		virtual cfsec::ICFSecClusterObj* readClusterByIdIdx( const int64_t Id, bool forceRead = false );

		virtual cfsec::ICFSecClusterObj* readClusterByUDomNameIdx( const std::string& FullDomName, bool forceRead = false );

		virtual cfsec::ICFSecClusterObj* readClusterByUDescrIdx( const std::string& Description, bool forceRead = false );

		virtual cfsec::ICFSecClusterObj* readCachedCluster( cfsec::CFSecClusterPKey* pkey );

		virtual cfsec::ICFSecClusterObj* readCachedClusterByIdIdx( const int64_t Id );

		virtual cfsec::ICFSecClusterObj* readCachedClusterByUDomNameIdx( const std::string& FullDomName );

		virtual cfsec::ICFSecClusterObj* readCachedClusterByUDescrIdx( const std::string& Description );

		virtual cfsec::ICFSecClusterObj* readClusterByLookupUDomNameIdx( const std::string& FullDomName, bool forceRead = false );

		virtual cfsec::ICFSecClusterObj* readCachedClusterByLookupUDomNameIdx( const std::string& FullDomName );

		virtual cfsec::ICFSecClusterObj* updateCluster( cfsec::ICFSecClusterEditObj* Obj );

		virtual void deleteCluster( cfsec::ICFSecClusterEditObj* Obj );

		virtual void deleteClusterByIdIdx( const int64_t Id );

		virtual void deleteClusterByUDomNameIdx( const std::string& FullDomName );

		virtual void deleteClusterByUDescrIdx( const std::string& Description );

		virtual void reallyDetachFromIndexesCluster( cfsec::ICFSecClusterObj* Obj );

	virtual cfsec::ICFSecClusterObj* getSystemCluster();

	};

}
