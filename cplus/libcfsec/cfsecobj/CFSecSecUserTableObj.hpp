#pragma once

// Description: C++18 Table Object specification for CFSec.

/*
 *	com.github.msobkow.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	This file is part of MSS Code Factory.
 *	
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *	    http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
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

#include <cfsecobj/ICFSecSecUserObj.hpp>
#include <cfsecobj/ICFSecSecUserEditObj.hpp>
#include <cfsecobj/ICFSecSecUserTableObj.hpp>

namespace cfsec {

	class CFSecSecUserTableObj
	: public virtual ICFSecSecUserTableObj
	{
	protected:
		cfsec::ICFSecSchemaObj* schema;
		std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* members;
		std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>* allSecUser;
		std::map< cfsec::CFSecSecUserByULoginIdxKey,
			cfsec::ICFSecSecUserObj*>* indexByULoginIdx;
		std::map< cfsec::CFSecSecUserByEMConfIdxKey,
			std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>*>* indexByEMConfIdx;
		std::map< cfsec::CFSecSecUserByPwdResetIdxKey,
			std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>*>* indexByPwdResetIdx;
		std::map< cfsec::CFSecSecUserByDefDevIdxKey,
			std::map<cfsec::CFSecSecUserPKey, cfsec::ICFSecSecUserObj*>*>* indexByDefDevIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFSecSecUserTableObj();
		CFSecSecUserTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFSecSecUserTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecSecUserObj* newInstance();

		virtual cfsec::ICFSecSecUserEditObj* newEditInstance( cfsec::ICFSecSecUserObj* orig );

		virtual cfsec::ICFSecSecUserObj* realizeSecUser( cfsec::ICFSecSecUserObj* Obj );

		virtual void deepDisposeByIdIdx( const uuid_ptr_t SecUserId );
		virtual void deepDisposeByULoginIdx( const std::string& LoginId );
		virtual void deepDisposeByEMConfIdx( const uuid_ptr_t EMailConfirmUuid );
		virtual void deepDisposeByPwdResetIdx( const uuid_ptr_t PasswordResetUuid );
		virtual void deepDisposeByDefDevIdx( const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName );
		virtual void reallyDeepDisposeSecUser( cfsec::ICFSecSecUserObj* Obj );
		virtual cfsec::ICFSecSecUserObj* createSecUser( cfsec::ICFSecSecUserEditObj* Obj );

		virtual cfsec::ICFSecSecUserObj* readSecUser( cfsec::CFSecSecUserPKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecSecUserObj* lockSecUser( cfsec::CFSecSecUserPKey* pkey );

		virtual std::vector<cfsec::ICFSecSecUserObj*> readAllSecUser( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecUserObj*> pageAllSecUser(const uuid_ptr_t priorSecUserId );

		virtual cfsec::ICFSecSecUserObj* readSecUserByIdIdx( const uuid_ptr_t SecUserId, bool forceRead = false );

		virtual cfsec::ICFSecSecUserObj* readSecUserByULoginIdx( const std::string& LoginId, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecUserObj*> readSecUserByEMConfIdx( const uuid_ptr_t EMailConfirmUuid,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecUserObj*> readSecUserByPwdResetIdx( const uuid_ptr_t PasswordResetUuid,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecUserObj*> readSecUserByDefDevIdx( const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName,
			bool forceRead = false );

		virtual cfsec::ICFSecSecUserObj* readCachedSecUser( cfsec::CFSecSecUserPKey* pkey );

		virtual cfsec::ICFSecSecUserObj* readCachedSecUserByIdIdx( const uuid_ptr_t SecUserId );

		virtual cfsec::ICFSecSecUserObj* readCachedSecUserByULoginIdx( const std::string& LoginId );

		virtual std::vector<cfsec::ICFSecSecUserObj*> readCachedSecUserByEMConfIdx( const uuid_ptr_t EMailConfirmUuid );

		virtual std::vector<cfsec::ICFSecSecUserObj*> readCachedSecUserByPwdResetIdx( const uuid_ptr_t PasswordResetUuid );

		virtual std::vector<cfsec::ICFSecSecUserObj*> readCachedSecUserByDefDevIdx( const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName );

		virtual cfsec::ICFSecSecUserObj* readSecUserByLookupULoginIdx( const std::string& LoginId, bool forceRead = false );

		virtual cfsec::ICFSecSecUserObj* readCachedSecUserByLookupULoginIdx( const std::string& LoginId );

		virtual std::vector<cfsec::ICFSecSecUserObj*> pageSecUserByEMConfIdx( const uuid_ptr_t EMailConfirmUuid,
			const uuid_ptr_t priorSecUserId );

		virtual std::vector<cfsec::ICFSecSecUserObj*> pageSecUserByPwdResetIdx( const uuid_ptr_t PasswordResetUuid,
			const uuid_ptr_t priorSecUserId );

		virtual std::vector<cfsec::ICFSecSecUserObj*> pageSecUserByDefDevIdx( const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName,
			const uuid_ptr_t priorSecUserId );

		virtual cfsec::ICFSecSecUserObj* updateSecUser( cfsec::ICFSecSecUserEditObj* Obj );

		virtual void deleteSecUser( cfsec::ICFSecSecUserEditObj* Obj );

		virtual void deleteSecUserByIdIdx( const uuid_ptr_t SecUserId );

		virtual void deleteSecUserByULoginIdx( const std::string& LoginId );

		virtual void deleteSecUserByEMConfIdx( const uuid_ptr_t EMailConfirmUuid );

		virtual void deleteSecUserByPwdResetIdx( const uuid_ptr_t PasswordResetUuid );

		virtual void deleteSecUserByDefDevIdx( const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName );

		virtual void reallyDetachFromIndexesSecUser( cfsec::ICFSecSecUserObj* Obj );

	virtual cfsec::ICFSecSecUserObj* getSystemUser();

	};

}
