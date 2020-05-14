#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for SecSession.

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
#include <cfsecobj/ICFSecObjPublic.hpp>
#include <cfsecsaxloader/CFSecSaxLoader.hpp>

namespace cfsec {

	class CFSecRamSecSessionTable
	: public virtual cfsec::ICFSecSecSessionTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>* dictByPKey;
		std::map<cfsec::CFSecSecSessionBySecUserIdxKey,
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>*>* dictBySecUserIdx;
		std::map<cfsec::CFSecSecSessionBySecDevIdxKey,
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>*>* dictBySecDevIdx;
		std::map<cfsec::CFSecSecSessionByStartIdxKey,
			cfsec::CFSecSecSessionBuff*>* dictByStartIdx;
		std::map<cfsec::CFSecSecSessionByFinishIdxKey,
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>*>* dictByFinishIdx;
		std::map<cfsec::CFSecSecSessionBySecProxyIdxKey,
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>*>* dictBySecProxyIdx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamSecSessionTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamSecSessionTable();

		virtual cfsec::CFSecSecSessionBuff* createSecSession( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecSessionBuff* Buff );

		virtual cfsec::CFSecSecSessionBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecSessionPKey* PKey );

		virtual cfsec::CFSecSecSessionBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecSessionPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> readDerivedBySecUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> readDerivedBySecDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string* SecDevName );

		virtual cfsec::CFSecSecSessionBuff* readDerivedByStartIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> readDerivedByFinishIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> readDerivedBySecProxyIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecProxyId );

		virtual cfsec::CFSecSecSessionBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecSessionId );

		virtual cfsec::CFSecSecSessionBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecSessionPKey* PKey );

		virtual cfsec::CFSecSecSessionBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecSessionPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t priorSecSessionId );

		virtual cfsec::CFSecSecSessionBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecSessionId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> readBuffBySecUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> readBuffBySecDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string* SecDevName );

		virtual cfsec::CFSecSecSessionBuff* readBuffByStartIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> readBuffByFinishIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> readBuffBySecProxyIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecProxyId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> pageBuffBySecUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const uuid_ptr_t priorSecSessionId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> pageBuffBySecDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string* SecDevName,
			const uuid_ptr_t priorSecSessionId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> pageBuffByFinishIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish,
			const uuid_ptr_t priorSecSessionId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> pageBuffBySecProxyIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecProxyId,
			const uuid_ptr_t priorSecSessionId );

		virtual cfsec::CFSecSecSessionBuff* updateSecSession( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecSessionBuff* Buff );

		virtual void deleteSecSession( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecSessionBuff* Buff );
		virtual void deleteSecSessionByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecSessionId );

		virtual void deleteSecSessionByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecSessionPKey* argKey );

		virtual void deleteSecSessionBySecUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId );

		virtual void deleteSecSessionBySecUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecSessionBySecUserIdxKey* argKey );

		virtual void deleteSecSessionBySecDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId,
			const std::string* argSecDevName );

		virtual void deleteSecSessionBySecDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecSessionBySecDevIdxKey* argKey );

		virtual void deleteSecSessionByStartIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId,
			const std::chrono::system_clock::time_point& argStart );

		virtual void deleteSecSessionByStartIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecSessionByStartIdxKey* argKey );

		virtual void deleteSecSessionByFinishIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId,
			const std::chrono::system_clock::time_point* argFinish );

		virtual void deleteSecSessionByFinishIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecSessionByFinishIdxKey* argKey );

		virtual void deleteSecSessionBySecProxyIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecProxyId );

		virtual void deleteSecSessionBySecProxyIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecSessionBySecProxyIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
