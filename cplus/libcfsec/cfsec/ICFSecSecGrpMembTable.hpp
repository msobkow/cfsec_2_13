#pragma once

// Description: C++18 DbIO interface for SecGrpMemb.

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
#include <cfsec/CFSecAuthorization.hpp>
#include <cfsec/CFSecHPKey.hpp>
#include <cfsec/CFSecSecGrpMembBuff.hpp>
#include <cfsec/CFSecSecGrpMembPKey.hpp>
#include <cfsec/CFSecSecGrpMembHBuff.hpp>
#include <cfsec/CFSecSecGrpMembHPKey.hpp>
#include <cfsec/CFSecSecGrpMembByClusterIdxKey.hpp>
#include <cfsec/CFSecSecGrpMembByGroupIdxKey.hpp>
#include <cfsec/CFSecSecGrpMembByUserIdxKey.hpp>
#include <cfsec/CFSecSecGrpMembByUUserIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecSecGrpMembObj;

	class ICFSecSecGrpMembTable
	{
	public:
		ICFSecSecGrpMembTable();
		virtual ~ICFSecSecGrpMembTable();

		virtual cfsec::CFSecSecGrpMembBuff* createSecGrpMemb( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGrpMembBuff* Buff ) = 0;

		virtual cfsec::CFSecSecGrpMembBuff* updateSecGrpMemb( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGrpMembBuff* Buff ) = 0;

		virtual void deleteSecGrpMemb( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGrpMembBuff* Buff ) = 0;
		virtual void deleteSecGrpMembByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int64_t argSecGrpMembId ) = 0;

		virtual void deleteSecGrpMembByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpMembPKey* argKey ) = 0;
		virtual void deleteSecGrpMembByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId ) = 0;

		virtual void deleteSecGrpMembByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpMembByClusterIdxKey* argKey ) = 0;
		virtual void deleteSecGrpMembByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecGroupId ) = 0;

		virtual void deleteSecGrpMembByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpMembByGroupIdxKey* argKey ) = 0;
		virtual void deleteSecGrpMembByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId ) = 0;

		virtual void deleteSecGrpMembByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpMembByUserIdxKey* argKey ) = 0;
		virtual void deleteSecGrpMembByUUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecGroupId,
			const uuid_ptr_t argSecUserId ) = 0;

		virtual void deleteSecGrpMembByUUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpMembByUUserIdxKey* argKey ) = 0;

		virtual cfsec::CFSecSecGrpMembBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpMembPKey* PKey ) = 0;

		virtual cfsec::CFSecSecGrpMembBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpMembPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecSecGrpMembBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t SecGrpMembId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> readDerivedByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> readDerivedByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId ) = 0;

		virtual cfsec::CFSecSecGrpMembBuff* readDerivedByUUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const uuid_ptr_t SecUserId ) = 0;

		virtual cfsec::CFSecSecGrpMembBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpMembPKey* PKey ) = 0;

		virtual cfsec::CFSecSecGrpMembBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpMembPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId ) = 0;

		virtual cfsec::CFSecSecGrpMembBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t SecGrpMembId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> readBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> readBuffByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId ) = 0;

		virtual cfsec::CFSecSecGrpMembBuff* readBuffByUUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const uuid_ptr_t SecUserId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> pageBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> pageBuffByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
