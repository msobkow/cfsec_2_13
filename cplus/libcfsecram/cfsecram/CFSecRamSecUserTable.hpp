#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for SecUser.

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
#include <cfsec/ICFSecPublic.hpp>
#include <cfsecobj/ICFSecObjPublic.hpp>
#include <cfsecsaxloader/CFSecSaxLoader.hpp>

namespace cfsec {

	class CFSecRamSecUserTable
	: public virtual cfsec::ICFSecSecUserTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecSecUserPKey,
			cfsec::CFSecSecUserBuff*>* dictByPKey;
		std::map<cfsec::CFSecSecUserByULoginIdxKey,
			cfsec::CFSecSecUserBuff*>* dictByULoginIdx;
		std::map<cfsec::CFSecSecUserByEMConfIdxKey,
			std::map<cfsec::CFSecSecUserPKey,
				cfsec::CFSecSecUserBuff*>*>* dictByEMConfIdx;
		std::map<cfsec::CFSecSecUserByPwdResetIdxKey,
			std::map<cfsec::CFSecSecUserPKey,
				cfsec::CFSecSecUserBuff*>*>* dictByPwdResetIdx;
		std::map<cfsec::CFSecSecUserByDefDevIdxKey,
			std::map<cfsec::CFSecSecUserPKey,
				cfsec::CFSecSecUserBuff*>*>* dictByDefDevIdx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamSecUserTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamSecUserTable();

		virtual cfsec::CFSecSecUserBuff* createSecUser( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecUserBuff* Buff );

		virtual cfsec::CFSecSecUserBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecUserPKey* PKey );

		virtual cfsec::CFSecSecUserBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecUserPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual cfsec::CFSecSecUserBuff* readDerivedByULoginIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& LoginId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> readDerivedByEMConfIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t EMailConfirmUuid );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> readDerivedByPwdResetIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t PasswordResetUuid );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> readDerivedByDefDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName );

		virtual cfsec::CFSecSecUserBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId );

		virtual cfsec::CFSecSecUserBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecUserPKey* PKey );

		virtual cfsec::CFSecSecUserBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecUserPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t priorSecUserId );

		virtual cfsec::CFSecSecUserBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId );

		virtual cfsec::CFSecSecUserBuff* readBuffByULoginIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& LoginId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> readBuffByEMConfIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t EMailConfirmUuid );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> readBuffByPwdResetIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t PasswordResetUuid );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> readBuffByDefDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName );

		virtual cfsec::CFSecSecUserBuff* readBuffByLookupULoginIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& LoginId,
			bool forceRead = false );

		virtual cfsec::CFSecSecUserBuff* readDerivedByLookupULoginIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& LoginId,
			bool forceRead = false );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> pageBuffByEMConfIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t EMailConfirmUuid,
			const uuid_ptr_t priorSecUserId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> pageBuffByPwdResetIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t PasswordResetUuid,
			const uuid_ptr_t priorSecUserId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecUserBuff*> pageBuffByDefDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName,
			const uuid_ptr_t priorSecUserId );

		virtual cfsec::CFSecSecUserBuff* updateSecUser( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecUserBuff* Buff );

		virtual void deleteSecUser( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecUserBuff* Buff );
		virtual void deleteSecUserByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId );

		virtual void deleteSecUserByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecUserPKey* argKey );

		virtual void deleteSecUserByULoginIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argLoginId );

		virtual void deleteSecUserByULoginIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecUserByULoginIdxKey* argKey );

		virtual void deleteSecUserByEMConfIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argEMailConfirmUuid );

		virtual void deleteSecUserByEMConfIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecUserByEMConfIdxKey* argKey );

		virtual void deleteSecUserByPwdResetIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argPasswordResetUuid );

		virtual void deleteSecUserByPwdResetIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecUserByPwdResetIdxKey* argKey );

		virtual void deleteSecUserByDefDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argDfltDevUserId,
			const std::string* argDfltDevName );

		virtual void deleteSecUserByDefDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecUserByDefDevIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
