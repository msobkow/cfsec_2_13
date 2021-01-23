#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for SecSession.

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
