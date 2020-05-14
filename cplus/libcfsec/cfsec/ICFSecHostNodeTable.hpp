#pragma once

// Description: C++18 DbIO interface for HostNode.

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
#include <cfsec/CFSecHostNodeBuff.hpp>
#include <cfsec/CFSecHostNodePKey.hpp>
#include <cfsec/CFSecHostNodeHBuff.hpp>
#include <cfsec/CFSecHostNodeHPKey.hpp>
#include <cfsec/CFSecHostNodeByClusterIdxKey.hpp>
#include <cfsec/CFSecHostNodeByUDescrIdxKey.hpp>
#include <cfsec/CFSecHostNodeByHostNameIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecHostNodeObj;

	class ICFSecHostNodeTable
	{
	public:
		ICFSecHostNodeTable();
		virtual ~ICFSecHostNodeTable();

		virtual cfsec::CFSecHostNodeBuff* createHostNode( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecHostNodeBuff* Buff ) = 0;

		virtual cfsec::CFSecHostNodeBuff* updateHostNode( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecHostNodeBuff* Buff ) = 0;

		virtual void deleteHostNode( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecHostNodeBuff* Buff ) = 0;
		virtual void deleteHostNodeByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int64_t argHostNodeId ) = 0;

		virtual void deleteHostNodeByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecHostNodePKey* argKey ) = 0;
		virtual void deleteHostNodeByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId ) = 0;

		virtual void deleteHostNodeByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecHostNodeByClusterIdxKey* argKey ) = 0;
		virtual void deleteHostNodeByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const std::string& argDescription ) = 0;

		virtual void deleteHostNodeByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecHostNodeByUDescrIdxKey* argKey ) = 0;
		virtual void deleteHostNodeByHostNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const std::string& argHostName ) = 0;

		virtual void deleteHostNodeByHostNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecHostNodeByHostNameIdxKey* argKey ) = 0;

		virtual cfsec::CFSecHostNodeBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecHostNodePKey* PKey ) = 0;

		virtual cfsec::CFSecHostNodeBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecHostNodePKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecHostNodeBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual cfsec::CFSecHostNodeBuff* readDerivedByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& Description ) = 0;

		virtual cfsec::CFSecHostNodeBuff* readDerivedByHostNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& HostName ) = 0;

		virtual cfsec::CFSecHostNodeBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecHostNodePKey* PKey ) = 0;

		virtual cfsec::CFSecHostNodeBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecHostNodePKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorClusterId,
			const int64_t* priorHostNodeId ) = 0;

		virtual cfsec::CFSecHostNodeBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual cfsec::CFSecHostNodeBuff* readBuffByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& Description ) = 0;

		virtual cfsec::CFSecHostNodeBuff* readBuffByHostNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& HostName ) = 0;

		virtual cfsec::CFSecHostNodeBuff* readBuffByLookupHostNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& HostName,
			bool forceRead = false ) = 0;

		virtual cfsec::CFSecHostNodeBuff* readDerivedByLookupHostNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& HostName,
			bool forceRead = false ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorHostNodeId ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
