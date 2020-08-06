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

#include <cfsecobj/ICFSecISOTZoneObj.hpp>
#include <cfsecobj/ICFSecISOTZoneEditObj.hpp>
#include <cfsecobj/ICFSecISOTZoneTableObj.hpp>

namespace cfsec {

	class CFSecISOTZoneTableObj
	: public virtual ICFSecISOTZoneTableObj
	{
	protected:
		cfsec::ICFSecSchemaObj* schema;
		std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* members;
		std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* allISOTZone;
		std::map< cfsec::CFSecISOTZoneByOffsetIdxKey,
			std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>*>* indexByOffsetIdx;
		std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey,
			cfsec::ICFSecISOTZoneObj*>* indexByUTZNameIdx;
		std::map< cfsec::CFSecISOTZoneByIso8601IdxKey,
			std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>*>* indexByIso8601Idx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFSecISOTZoneTableObj();
		CFSecISOTZoneTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFSecISOTZoneTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecISOTZoneObj* newInstance();

		virtual cfsec::ICFSecISOTZoneEditObj* newEditInstance( cfsec::ICFSecISOTZoneObj* orig );

		virtual cfsec::ICFSecISOTZoneObj* realizeISOTZone( cfsec::ICFSecISOTZoneObj* Obj );

		virtual void deepDisposeByIdIdx( const int16_t ISOTZoneId );
		virtual void deepDisposeByOffsetIdx( const int16_t TZHourOffset,
			const int16_t TZMinOffset );
		virtual void deepDisposeByUTZNameIdx( const std::string& TZName );
		virtual void deepDisposeByIso8601Idx( const std::string& Iso8601 );
		virtual void reallyDeepDisposeISOTZone( cfsec::ICFSecISOTZoneObj* Obj );
		virtual cfsec::ICFSecISOTZoneObj* createISOTZone( cfsec::ICFSecISOTZoneEditObj* Obj );

		virtual cfsec::ICFSecISOTZoneObj* readISOTZone( cfsec::CFSecISOTZonePKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecISOTZoneObj* lockISOTZone( cfsec::CFSecISOTZonePKey* pkey );

		virtual std::vector<cfsec::ICFSecISOTZoneObj*> readAllISOTZone( bool forceRead = false );

		virtual cfsec::ICFSecISOTZoneObj* readISOTZoneByIdIdx( const int16_t ISOTZoneId, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecISOTZoneObj*> readISOTZoneByOffsetIdx( const int16_t TZHourOffset,
			const int16_t TZMinOffset,
			bool forceRead = false );

		virtual cfsec::ICFSecISOTZoneObj* readISOTZoneByUTZNameIdx( const std::string& TZName, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecISOTZoneObj*> readISOTZoneByIso8601Idx( const std::string& Iso8601,
			bool forceRead = false );

		virtual cfsec::ICFSecISOTZoneObj* readCachedISOTZone( cfsec::CFSecISOTZonePKey* pkey );

		virtual cfsec::ICFSecISOTZoneObj* readCachedISOTZoneByIdIdx( const int16_t ISOTZoneId );

		virtual std::vector<cfsec::ICFSecISOTZoneObj*> readCachedISOTZoneByOffsetIdx( const int16_t TZHourOffset,
			const int16_t TZMinOffset );

		virtual cfsec::ICFSecISOTZoneObj* readCachedISOTZoneByUTZNameIdx( const std::string& TZName );

		virtual std::vector<cfsec::ICFSecISOTZoneObj*> readCachedISOTZoneByIso8601Idx( const std::string& Iso8601 );

		virtual cfsec::ICFSecISOTZoneObj* readISOTZoneByLookupUTZNameIdx( const std::string& TZName, bool forceRead = false );

		virtual cfsec::ICFSecISOTZoneObj* readCachedISOTZoneByLookupUTZNameIdx( const std::string& TZName );

		virtual cfsec::ICFSecISOTZoneObj* updateISOTZone( cfsec::ICFSecISOTZoneEditObj* Obj );

		virtual void deleteISOTZone( cfsec::ICFSecISOTZoneEditObj* Obj );

		virtual void deleteISOTZoneByIdIdx( const int16_t ISOTZoneId );

		virtual void deleteISOTZoneByOffsetIdx( const int16_t TZHourOffset,
			const int16_t TZMinOffset );

		virtual void deleteISOTZoneByUTZNameIdx( const std::string& TZName );

		virtual void deleteISOTZoneByIso8601Idx( const std::string& Iso8601 );

		virtual void reallyDetachFromIndexesISOTZone( cfsec::ICFSecISOTZoneObj* Obj );

	};

}
