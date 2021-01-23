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

#include <cfsecobj/ICFSecSecUserObj.hpp>
#include <cfsecobj/ICFSecSecUserEditObj.hpp>

namespace cfsec {

	class ICFSecSecUserTableObj
	{
	public:
		ICFSecSecUserTableObj();
		virtual ~ICFSecSecUserTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema() = 0;
		virtual void setSchema( cfsec::ICFSecSchemaObj* value ) = 0;

		virtual void minimizeMemory() = 0;

		virtual const std::string getTableName() = 0;
		virtual const std::string getTableDbName() = 0;
		virtual const classcode_t* getObjQualifyingClassCode() = 0;

		virtual cfsec::ICFSecSecUserObj* newInstance() = 0;

		virtual cfsec::ICFSecSecUserEditObj* newEditInstance( cfsec::ICFSecSecUserObj* orig ) = 0;

		virtual cfsec::ICFSecSecUserObj* realizeSecUser( cfsec::ICFSecSecUserObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const uuid_ptr_t SecUserId ) = 0;
		virtual void deepDisposeByULoginIdx( const std::string& LoginId ) = 0;
		virtual void deepDisposeByEMConfIdx( const uuid_ptr_t EMailConfirmUuid ) = 0;
		virtual void deepDisposeByPwdResetIdx( const uuid_ptr_t PasswordResetUuid ) = 0;
		virtual void deepDisposeByDefDevIdx( const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName ) = 0;
		virtual void reallyDeepDisposeSecUser( cfsec::ICFSecSecUserObj* Obj ) = 0;
		virtual cfsec::ICFSecSecUserObj* createSecUser( cfsec::ICFSecSecUserEditObj* Obj ) = 0;

		virtual cfsec::ICFSecSecUserObj* readSecUser( cfsec::CFSecSecUserPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecUserObj* lockSecUser( cfsec::CFSecSecUserPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecSecUserObj*> readAllSecUser( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecUserObj*> pageAllSecUser(const uuid_ptr_t priorSecUserId ) = 0;

		virtual cfsec::ICFSecSecUserObj* readSecUserByIdIdx( const uuid_ptr_t SecUserId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecUserObj* readSecUserByULoginIdx(const std::string& LoginId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecUserObj*> readSecUserByEMConfIdx( const uuid_ptr_t EMailConfirmUuid,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecUserObj*> readSecUserByPwdResetIdx( const uuid_ptr_t PasswordResetUuid,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecUserObj*> readSecUserByDefDevIdx( const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecUserObj* readCachedSecUser( cfsec::CFSecSecUserPKey* pkey ) = 0;

		virtual cfsec::ICFSecSecUserObj* readCachedSecUserByIdIdx(const uuid_ptr_t SecUserId ) = 0;

		virtual cfsec::ICFSecSecUserObj* readCachedSecUserByULoginIdx(const std::string& LoginId ) = 0;

		virtual std::vector<cfsec::ICFSecSecUserObj*> readCachedSecUserByEMConfIdx( const uuid_ptr_t EMailConfirmUuid ) = 0;

		virtual std::vector<cfsec::ICFSecSecUserObj*> readCachedSecUserByPwdResetIdx( const uuid_ptr_t PasswordResetUuid ) = 0;

		virtual std::vector<cfsec::ICFSecSecUserObj*> readCachedSecUserByDefDevIdx( const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName ) = 0;

		virtual cfsec::ICFSecSecUserObj* readSecUserByLookupULoginIdx(const std::string& LoginId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecUserObj* readCachedSecUserByLookupULoginIdx(const std::string& LoginId ) = 0;

		virtual std::vector<cfsec::ICFSecSecUserObj*> pageSecUserByEMConfIdx( const uuid_ptr_t EMailConfirmUuid,
			const uuid_ptr_t priorSecUserId ) = 0;

		virtual std::vector<cfsec::ICFSecSecUserObj*> pageSecUserByPwdResetIdx( const uuid_ptr_t PasswordResetUuid,
			const uuid_ptr_t priorSecUserId ) = 0;

		virtual std::vector<cfsec::ICFSecSecUserObj*> pageSecUserByDefDevIdx( const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName,
			const uuid_ptr_t priorSecUserId ) = 0;

		virtual cfsec::ICFSecSecUserObj* updateSecUser( cfsec::ICFSecSecUserEditObj* Obj ) = 0;

		virtual void deleteSecUser( cfsec::ICFSecSecUserEditObj* Obj ) = 0;

		virtual void deleteSecUserByIdIdx( const uuid_ptr_t SecUserId ) = 0;

		virtual void deleteSecUserByULoginIdx(const std::string& LoginId ) = 0;

		virtual void deleteSecUserByEMConfIdx( const uuid_ptr_t EMailConfirmUuid ) = 0;

		virtual void deleteSecUserByPwdResetIdx( const uuid_ptr_t PasswordResetUuid ) = 0;

		virtual void deleteSecUserByDefDevIdx( const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName ) = 0;

		virtual void reallyDetachFromIndexesSecUser( cfsec::ICFSecSecUserObj* Obj ) = 0;

	virtual cfsec::ICFSecSecUserObj* getSystemUser() = 0;

	};
}
