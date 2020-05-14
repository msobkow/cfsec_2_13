#pragma once

// Description: C++18 DbIO interface for TSecGrpInc.

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
#include <cfsec/CFSecTSecGrpIncBuff.hpp>
#include <cfsec/CFSecTSecGrpIncPKey.hpp>
#include <cfsec/CFSecTSecGrpIncHBuff.hpp>
#include <cfsec/CFSecTSecGrpIncHPKey.hpp>
#include <cfsec/CFSecTSecGrpIncByTenantIdxKey.hpp>
#include <cfsec/CFSecTSecGrpIncByGroupIdxKey.hpp>
#include <cfsec/CFSecTSecGrpIncByIncludeIdxKey.hpp>
#include <cfsec/CFSecTSecGrpIncByUIncludeIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecTSecGrpIncObj;

	class ICFSecTSecGrpIncTable
	{
	public:
		ICFSecTSecGrpIncTable();
		virtual ~ICFSecTSecGrpIncTable();

		virtual cfsec::CFSecTSecGrpIncBuff* createTSecGrpInc( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTSecGrpIncBuff* Buff ) = 0;

		virtual cfsec::CFSecTSecGrpIncBuff* updateTSecGrpInc( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTSecGrpIncBuff* Buff ) = 0;

		virtual void deleteTSecGrpInc( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTSecGrpIncBuff* Buff ) = 0;
		virtual void deleteTSecGrpIncByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTSecGrpIncId ) = 0;

		virtual void deleteTSecGrpIncByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncPKey* argKey ) = 0;
		virtual void deleteTSecGrpIncByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId ) = 0;

		virtual void deleteTSecGrpIncByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncByTenantIdxKey* argKey ) = 0;
		virtual void deleteTSecGrpIncByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int32_t argTSecGroupId ) = 0;

		virtual void deleteTSecGrpIncByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncByGroupIdxKey* argKey ) = 0;
		virtual void deleteTSecGrpIncByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int32_t argIncludeGroupId ) = 0;

		virtual void deleteTSecGrpIncByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncByIncludeIdxKey* argKey ) = 0;
		virtual void deleteTSecGrpIncByUIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int32_t argTSecGroupId,
			const int32_t argIncludeGroupId ) = 0;

		virtual void deleteTSecGrpIncByUIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncByUIncludeIdxKey* argKey ) = 0;

		virtual cfsec::CFSecTSecGrpIncBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncPKey* PKey ) = 0;

		virtual cfsec::CFSecTSecGrpIncBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecTSecGrpIncBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TSecGrpIncId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readDerivedByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readDerivedByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t IncludeGroupId ) = 0;

		virtual cfsec::CFSecTSecGrpIncBuff* readDerivedByUIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId,
			const int32_t IncludeGroupId ) = 0;

		virtual cfsec::CFSecTSecGrpIncBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncPKey* PKey ) = 0;

		virtual cfsec::CFSecTSecGrpIncBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId ) = 0;

		virtual cfsec::CFSecTSecGrpIncBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TSecGrpIncId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readBuffByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t IncludeGroupId ) = 0;

		virtual cfsec::CFSecTSecGrpIncBuff* readBuffByUIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId,
			const int32_t IncludeGroupId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> pageBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> pageBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> pageBuffByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t IncludeGroupId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
