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

#include <cfsecobj/ICFSecSecSessionObj.hpp>
#include <cfsecobj/ICFSecSecSessionEditObj.hpp>
#include <cfsecobj/ICFSecSecSessionTableObj.hpp>

namespace cfsec {

	class CFSecSecSessionTableObj
	: public virtual ICFSecSecSessionTableObj
	{
	protected:
		cfsec::ICFSecSchemaObj* schema;
		std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* members;
		std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>* allSecSession;
		std::map< cfsec::CFSecSecSessionBySecUserIdxKey,
			std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>*>* indexBySecUserIdx;
		std::map< cfsec::CFSecSecSessionBySecDevIdxKey,
			std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>*>* indexBySecDevIdx;
		std::map< cfsec::CFSecSecSessionByStartIdxKey,
			cfsec::ICFSecSecSessionObj*>* indexByStartIdx;
		std::map< cfsec::CFSecSecSessionByFinishIdxKey,
			std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>*>* indexByFinishIdx;
		std::map< cfsec::CFSecSecSessionBySecProxyIdxKey,
			std::map<cfsec::CFSecSecSessionPKey, cfsec::ICFSecSecSessionObj*>*>* indexBySecProxyIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFSecSecSessionTableObj();
		CFSecSecSessionTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFSecSecSessionTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecSecSessionObj* newInstance();

		virtual cfsec::ICFSecSecSessionEditObj* newEditInstance( cfsec::ICFSecSecSessionObj* orig );

		virtual cfsec::ICFSecSecSessionObj* realizeSecSession( cfsec::ICFSecSecSessionObj* Obj );

		virtual void deepDisposeByIdIdx( const uuid_ptr_t SecSessionId );
		virtual void deepDisposeBySecUserIdx( const uuid_ptr_t SecUserId );
		virtual void deepDisposeBySecDevIdx( const uuid_ptr_t SecUserId,
			const std::string* SecDevName );
		virtual void deepDisposeByStartIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start );
		virtual void deepDisposeByFinishIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish );
		virtual void deepDisposeBySecProxyIdx( const uuid_ptr_t SecProxyId );
		virtual void reallyDeepDisposeSecSession( cfsec::ICFSecSecSessionObj* Obj );
		virtual cfsec::ICFSecSecSessionObj* createSecSession( cfsec::ICFSecSecSessionEditObj* Obj );

		virtual cfsec::ICFSecSecSessionObj* readSecSession( cfsec::CFSecSecSessionPKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecSecSessionObj* lockSecSession( cfsec::CFSecSecSessionPKey* pkey );

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readAllSecSession( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecSessionObj*> pageAllSecSession(const uuid_ptr_t priorSecSessionId );

		virtual cfsec::ICFSecSecSessionObj* readSecSessionByIdIdx( const uuid_ptr_t SecSessionId, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readSecSessionBySecUserIdx( const uuid_ptr_t SecUserId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readSecSessionBySecDevIdx( const uuid_ptr_t SecUserId,
			const std::string* SecDevName,
			bool forceRead = false );

		virtual cfsec::ICFSecSecSessionObj* readSecSessionByStartIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readSecSessionByFinishIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readSecSessionBySecProxyIdx( const uuid_ptr_t SecProxyId,
			bool forceRead = false );

		virtual cfsec::ICFSecSecSessionObj* readCachedSecSession( cfsec::CFSecSecSessionPKey* pkey );

		virtual cfsec::ICFSecSecSessionObj* readCachedSecSessionByIdIdx( const uuid_ptr_t SecSessionId );

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readCachedSecSessionBySecUserIdx( const uuid_ptr_t SecUserId );

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readCachedSecSessionBySecDevIdx( const uuid_ptr_t SecUserId,
			const std::string* SecDevName );

		virtual cfsec::ICFSecSecSessionObj* readCachedSecSessionByStartIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start );

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readCachedSecSessionByFinishIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish );

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readCachedSecSessionBySecProxyIdx( const uuid_ptr_t SecProxyId );

		virtual std::vector<cfsec::ICFSecSecSessionObj*> pageSecSessionBySecUserIdx( const uuid_ptr_t SecUserId,
			const uuid_ptr_t priorSecSessionId );

		virtual std::vector<cfsec::ICFSecSecSessionObj*> pageSecSessionBySecDevIdx( const uuid_ptr_t SecUserId,
			const std::string* SecDevName,
			const uuid_ptr_t priorSecSessionId );

		virtual std::vector<cfsec::ICFSecSecSessionObj*> pageSecSessionByFinishIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish,
			const uuid_ptr_t priorSecSessionId );

		virtual std::vector<cfsec::ICFSecSecSessionObj*> pageSecSessionBySecProxyIdx( const uuid_ptr_t SecProxyId,
			const uuid_ptr_t priorSecSessionId );

		virtual cfsec::ICFSecSecSessionObj* updateSecSession( cfsec::ICFSecSecSessionEditObj* Obj );

		virtual void deleteSecSession( cfsec::ICFSecSecSessionEditObj* Obj );

		virtual void deleteSecSessionByIdIdx( const uuid_ptr_t SecSessionId );

		virtual void deleteSecSessionBySecUserIdx( const uuid_ptr_t SecUserId );

		virtual void deleteSecSessionBySecDevIdx( const uuid_ptr_t SecUserId,
			const std::string* SecDevName );

		virtual void deleteSecSessionByStartIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start );

		virtual void deleteSecSessionByFinishIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish );

		virtual void deleteSecSessionBySecProxyIdx( const uuid_ptr_t SecProxyId );

		virtual void reallyDetachFromIndexesSecSession( cfsec::ICFSecSecSessionObj* Obj );

	virtual cfsec::ICFSecSecSessionObj* getSystemSession();

	};

}
