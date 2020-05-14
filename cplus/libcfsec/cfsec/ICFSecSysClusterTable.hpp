#pragma once

// Description: C++18 DbIO interface for SysCluster.

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
#include <cfsec/CFSecSysClusterBuff.hpp>
#include <cfsec/CFSecSysClusterPKey.hpp>
#include <cfsec/CFSecSysClusterHBuff.hpp>
#include <cfsec/CFSecSysClusterHPKey.hpp>
#include <cfsec/CFSecSysClusterByClusterIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecSysClusterObj;

	class ICFSecSysClusterTable
	{
	public:
		ICFSecSysClusterTable();
		virtual ~ICFSecSysClusterTable();

		virtual cfsec::CFSecSysClusterBuff* createSysCluster( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSysClusterBuff* Buff ) = 0;

		virtual cfsec::CFSecSysClusterBuff* updateSysCluster( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSysClusterBuff* Buff ) = 0;

		virtual void deleteSysCluster( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSysClusterBuff* Buff ) = 0;
		virtual void deleteSysClusterByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t argSingletonId ) = 0;

		virtual void deleteSysClusterByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSysClusterPKey* argKey ) = 0;
		virtual void deleteSysClusterByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId ) = 0;

		virtual void deleteSysClusterByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSysClusterByClusterIdxKey* argKey ) = 0;

		virtual cfsec::CFSecSysClusterBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSysClusterPKey* PKey ) = 0;

		virtual cfsec::CFSecSysClusterBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSysClusterPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecSysClusterBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t SingletonId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual cfsec::CFSecSysClusterBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSysClusterPKey* PKey ) = 0;

		virtual cfsec::CFSecSysClusterBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSysClusterPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecSysClusterBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t SingletonId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
