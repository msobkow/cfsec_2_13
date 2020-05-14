#pragma once

// Description: C++18 DbIO interface for TSecGroup.

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
#include <cfsec/CFSecTSecGroupBuff.hpp>
#include <cfsec/CFSecTSecGroupPKey.hpp>
#include <cfsec/CFSecTSecGroupHBuff.hpp>
#include <cfsec/CFSecTSecGroupHPKey.hpp>
#include <cfsec/CFSecTSecGroupByTenantIdxKey.hpp>
#include <cfsec/CFSecTSecGroupByTenantVisIdxKey.hpp>
#include <cfsec/CFSecTSecGroupByUNameIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecTSecGroupObj;

	class ICFSecTSecGroupTable
	{
	public:
		ICFSecTSecGroupTable();
		virtual ~ICFSecTSecGroupTable();

		virtual cfsec::CFSecTSecGroupBuff* createTSecGroup( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTSecGroupBuff* Buff ) = 0;

		virtual cfsec::CFSecTSecGroupBuff* updateTSecGroup( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTSecGroupBuff* Buff ) = 0;

		virtual void deleteTSecGroup( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTSecGroupBuff* Buff ) = 0;
		virtual void deleteTSecGroupByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int32_t argTSecGroupId ) = 0;

		virtual void deleteTSecGroupByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupPKey* argKey ) = 0;
		virtual void deleteTSecGroupByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId ) = 0;

		virtual void deleteTSecGroupByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupByTenantIdxKey* argKey ) = 0;
		virtual void deleteTSecGroupByTenantVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const bool argIsVisible ) = 0;

		virtual void deleteTSecGroupByTenantVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupByTenantVisIdxKey* argKey ) = 0;
		virtual void deleteTSecGroupByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const std::string& argName ) = 0;

		virtual void deleteTSecGroupByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupByUNameIdxKey* argKey ) = 0;

		virtual cfsec::CFSecTSecGroupBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupPKey* PKey ) = 0;

		virtual cfsec::CFSecTSecGroupBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecTSecGroupBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> readDerivedByTenantVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const bool IsVisible ) = 0;

		virtual cfsec::CFSecTSecGroupBuff* readDerivedByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const std::string& Name ) = 0;

		virtual cfsec::CFSecTSecGroupBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupPKey* PKey ) = 0;

		virtual cfsec::CFSecTSecGroupBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecTSecGroupBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> readBuffByTenantVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const bool IsVisible ) = 0;

		virtual cfsec::CFSecTSecGroupBuff* readBuffByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const std::string& Name ) = 0;

		virtual cfsec::CFSecTSecGroupBuff* readBuffByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfsec::CFSecTSecGroupBuff* readDerivedByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
