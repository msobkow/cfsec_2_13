#pragma once

// Description: C++18 DbIO interface for SecApp.

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
#include <cfsec/CFSecSecAppBuff.hpp>
#include <cfsec/CFSecSecAppPKey.hpp>
#include <cfsec/CFSecSecAppHBuff.hpp>
#include <cfsec/CFSecSecAppHPKey.hpp>
#include <cfsec/CFSecSecAppByClusterIdxKey.hpp>
#include <cfsec/CFSecSecAppByUJEEMountIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecSecAppObj;

	class ICFSecSecAppTable
	{
	public:
		ICFSecSecAppTable();
		virtual ~ICFSecSecAppTable();

		virtual cfsec::CFSecSecAppBuff* createSecApp( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecAppBuff* Buff ) = 0;

		virtual cfsec::CFSecSecAppBuff* updateSecApp( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecAppBuff* Buff ) = 0;

		virtual void deleteSecApp( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecAppBuff* Buff ) = 0;
		virtual void deleteSecAppByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecAppId ) = 0;

		virtual void deleteSecAppByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecAppPKey* argKey ) = 0;
		virtual void deleteSecAppByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId ) = 0;

		virtual void deleteSecAppByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecAppByClusterIdxKey* argKey ) = 0;
		virtual void deleteSecAppByUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const std::string& argJEEMountName ) = 0;

		virtual void deleteSecAppByUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecAppByUJEEMountIdxKey* argKey ) = 0;

		virtual cfsec::CFSecSecAppBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecAppPKey* PKey ) = 0;

		virtual cfsec::CFSecSecAppBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecAppPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecSecAppBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual cfsec::CFSecSecAppBuff* readDerivedByUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& JEEMountName ) = 0;

		virtual cfsec::CFSecSecAppBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecAppPKey* PKey ) = 0;

		virtual cfsec::CFSecSecAppBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecAppPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorClusterId,
			const int32_t* priorSecAppId ) = 0;

		virtual cfsec::CFSecSecAppBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual cfsec::CFSecSecAppBuff* readBuffByUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& JEEMountName ) = 0;

		virtual cfsec::CFSecSecAppBuff* readBuffByLookupUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& JEEMountName,
			bool forceRead = false ) = 0;

		virtual cfsec::CFSecSecAppBuff* readDerivedByLookupUJEEMountIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& JEEMountName,
			bool forceRead = false ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int32_t* priorSecAppId ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
