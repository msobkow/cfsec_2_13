#pragma once

// Description: C++18 DbIO interface for Tenant.

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
#include <cfsec/CFSecTenantBuff.hpp>
#include <cfsec/CFSecTenantPKey.hpp>
#include <cfsec/CFSecTenantHBuff.hpp>
#include <cfsec/CFSecTenantHPKey.hpp>
#include <cfsec/CFSecTenantByClusterIdxKey.hpp>
#include <cfsec/CFSecTenantByUNameIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecTenantObj;

	class ICFSecTenantTable
	{
	public:
		ICFSecTenantTable();
		virtual ~ICFSecTenantTable();

		virtual int32_t nextTSecGroupIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* PKey ) = 0;

		virtual int32_t nextTSecGroupIdGen( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argId ) = 0;

		virtual int64_t nextTSecGrpIncIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* PKey ) = 0;

		virtual int64_t nextTSecGrpIncIdGen( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argId ) = 0;

		virtual int64_t nextTSecGrpMembIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* PKey ) = 0;

		virtual int64_t nextTSecGrpMembIdGen( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argId ) = 0;

		virtual cfsec::CFSecTenantBuff* createTenant( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTenantBuff* Buff ) = 0;

		virtual cfsec::CFSecTenantBuff* updateTenant( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTenantBuff* Buff ) = 0;

		virtual void deleteTenant( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTenantBuff* Buff ) = 0;
		virtual void deleteTenantByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argId ) = 0;

		virtual void deleteTenantByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* argKey ) = 0;
		virtual void deleteTenantByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId ) = 0;

		virtual void deleteTenantByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantByClusterIdxKey* argKey ) = 0;
		virtual void deleteTenantByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const std::string& argTenantName ) = 0;

		virtual void deleteTenantByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantByUNameIdxKey* argKey ) = 0;

		virtual cfsec::CFSecTenantBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* PKey ) = 0;

		virtual cfsec::CFSecTenantBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecTenantBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t Id ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual cfsec::CFSecTenantBuff* readDerivedByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& TenantName ) = 0;

		virtual cfsec::CFSecTenantBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* PKey ) = 0;

		virtual cfsec::CFSecTenantBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorId ) = 0;

		virtual cfsec::CFSecTenantBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t Id ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual cfsec::CFSecTenantBuff* readBuffByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& TenantName ) = 0;

		virtual cfsec::CFSecTenantBuff* readBuffByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& TenantName,
			bool forceRead = false ) = 0;

		virtual cfsec::CFSecTenantBuff* readDerivedByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& TenantName,
			bool forceRead = false ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorId ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
