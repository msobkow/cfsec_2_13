#pragma once

// Description: C++18 DbIO interface for SecSession.

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
#include <cfsec/CFSecSecSessionBuff.hpp>
#include <cfsec/CFSecSecSessionPKey.hpp>
#include <cfsec/CFSecSecSessionHBuff.hpp>
#include <cfsec/CFSecSecSessionHPKey.hpp>
#include <cfsec/CFSecSecSessionBySecUserIdxKey.hpp>
#include <cfsec/CFSecSecSessionBySecDevIdxKey.hpp>
#include <cfsec/CFSecSecSessionByStartIdxKey.hpp>
#include <cfsec/CFSecSecSessionByFinishIdxKey.hpp>
#include <cfsec/CFSecSecSessionBySecProxyIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecSecSessionObj;

	class ICFSecSecSessionTable
	{
	public:
		ICFSecSecSessionTable();
		virtual ~ICFSecSecSessionTable();

		virtual cfsec::CFSecSecSessionBuff* createSecSession( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecSessionBuff* Buff ) = 0;

		virtual cfsec::CFSecSecSessionBuff* updateSecSession( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecSessionBuff* Buff ) = 0;

		virtual void deleteSecSession( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecSessionBuff* Buff ) = 0;
		virtual void deleteSecSessionByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecSessionId ) = 0;

		virtual void deleteSecSessionByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecSessionPKey* argKey ) = 0;
		virtual void deleteSecSessionBySecUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId ) = 0;

		virtual void deleteSecSessionBySecUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecSessionBySecUserIdxKey* argKey ) = 0;
		virtual void deleteSecSessionBySecDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId,
			const std::string* argSecDevName ) = 0;

		virtual void deleteSecSessionBySecDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecSessionBySecDevIdxKey* argKey ) = 0;
		virtual void deleteSecSessionByStartIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId,
			const std::chrono::system_clock::time_point& argStart ) = 0;

		virtual void deleteSecSessionByStartIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecSessionByStartIdxKey* argKey ) = 0;
		virtual void deleteSecSessionByFinishIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId,
			const std::chrono::system_clock::time_point* argFinish ) = 0;

		virtual void deleteSecSessionByFinishIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecSessionByFinishIdxKey* argKey ) = 0;
		virtual void deleteSecSessionBySecProxyIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecProxyId ) = 0;

		virtual void deleteSecSessionBySecProxyIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecSessionBySecProxyIdxKey* argKey ) = 0;

		virtual cfsec::CFSecSecSessionBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecSessionPKey* PKey ) = 0;

		virtual cfsec::CFSecSecSessionBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecSessionPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecSecSessionBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecSessionId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> readDerivedBySecUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> readDerivedBySecDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string* SecDevName ) = 0;

		virtual cfsec::CFSecSecSessionBuff* readDerivedByStartIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> readDerivedByFinishIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> readDerivedBySecProxyIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecProxyId ) = 0;

		virtual cfsec::CFSecSecSessionBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecSessionPKey* PKey ) = 0;

		virtual cfsec::CFSecSecSessionBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecSessionPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t priorSecSessionId ) = 0;

		virtual cfsec::CFSecSecSessionBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecSessionId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> readBuffBySecUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> readBuffBySecDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string* SecDevName ) = 0;

		virtual cfsec::CFSecSecSessionBuff* readBuffByStartIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> readBuffByFinishIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> readBuffBySecProxyIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecProxyId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> pageBuffBySecUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const uuid_ptr_t priorSecSessionId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> pageBuffBySecDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string* SecDevName,
			const uuid_ptr_t priorSecSessionId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> pageBuffByFinishIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish,
			const uuid_ptr_t priorSecSessionId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> pageBuffBySecProxyIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecProxyId,
			const uuid_ptr_t priorSecSessionId ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
