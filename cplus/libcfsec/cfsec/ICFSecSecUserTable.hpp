#pragma once

// Description: C++18 DbIO interface for SecUser.

/*
 *	org.msscf.msscf.CFSec
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
#include <cfsec/CFSecAuthorization.hpp>
#include <cfsec/CFSecHPKey.hpp>
#include <cfsec/CFSecSecUserBuff.hpp>
#include <cfsec/CFSecSecUserPKey.hpp>
#include <cfsec/CFSecSecUserHBuff.hpp>
#include <cfsec/CFSecSecUserHPKey.hpp>
#include <cfsec/CFSecSecUserByULoginIdxKey.hpp>
#include <cfsec/CFSecSecUserByEMConfIdxKey.hpp>
#include <cfsec/CFSecSecUserByPwdResetIdxKey.hpp>
#include <cfsec/CFSecSecUserByDefDevIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecSecUserObj;

	class ICFSecSecUserTable
	{
	public:
		ICFSecSecUserTable();
		virtual ~ICFSecSecUserTable();

		virtual cfsec::CFSecSecUserBuff* createSecUser( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecUserBuff* Buff ) = 0;

		virtual cfsec::CFSecSecUserBuff* updateSecUser( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecUserBuff* Buff ) = 0;

		virtual void deleteSecUser( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecUserBuff* Buff ) = 0;
		virtual void deleteSecUserByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId ) = 0;

		virtual void deleteSecUserByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecUserPKey* argKey ) = 0;
		virtual void deleteSecUserByULoginIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argLoginId ) = 0;

		virtual void deleteSecUserByULoginIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecUserByULoginIdxKey* argKey ) = 0;
		virtual void deleteSecUserByEMConfIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argEMailConfirmUuid ) = 0;

		virtual void deleteSecUserByEMConfIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecUserByEMConfIdxKey* argKey ) = 0;
		virtual void deleteSecUserByPwdResetIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argPasswordResetUuid ) = 0;

		virtual void deleteSecUserByPwdResetIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecUserByPwdResetIdxKey* argKey ) = 0;
		virtual void deleteSecUserByDefDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argDfltDevUserId,
			const std::string* argDfltDevName ) = 0;

		virtual void deleteSecUserByDefDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecUserByDefDevIdxKey* argKey ) = 0;

		virtual cfsec::CFSecSecUserBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecUserPKey* PKey ) = 0;

		virtual cfsec::CFSecSecUserBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecUserPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecSecUserBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId ) = 0;

		virtual cfsec::CFSecSecUserBuff* readDerivedByULoginIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& LoginId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> readDerivedByEMConfIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t EMailConfirmUuid ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> readDerivedByPwdResetIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t PasswordResetUuid ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> readDerivedByDefDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName ) = 0;

		virtual cfsec::CFSecSecUserBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecUserPKey* PKey ) = 0;

		virtual cfsec::CFSecSecUserBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecUserPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t priorSecUserId ) = 0;

		virtual cfsec::CFSecSecUserBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId ) = 0;

		virtual cfsec::CFSecSecUserBuff* readBuffByULoginIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& LoginId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> readBuffByEMConfIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t EMailConfirmUuid ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> readBuffByPwdResetIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t PasswordResetUuid ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> readBuffByDefDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName ) = 0;

		virtual cfsec::CFSecSecUserBuff* readBuffByLookupULoginIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& LoginId,
			bool forceRead = false ) = 0;

		virtual cfsec::CFSecSecUserBuff* readDerivedByLookupULoginIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& LoginId,
			bool forceRead = false ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> pageBuffByEMConfIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t EMailConfirmUuid,
			const uuid_ptr_t priorSecUserId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> pageBuffByPwdResetIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t PasswordResetUuid,
			const uuid_ptr_t priorSecUserId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> pageBuffByDefDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName,
			const uuid_ptr_t priorSecUserId ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
