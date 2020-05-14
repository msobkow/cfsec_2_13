#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for HostNode.

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

	class CFSecRamHostNodeTable
	: public virtual cfsec::ICFSecHostNodeTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecHostNodePKey,
			cfsec::CFSecHostNodeBuff*>* dictByPKey;
		std::map<cfsec::CFSecHostNodeByClusterIdxKey,
			std::map<cfsec::CFSecHostNodePKey,
				cfsec::CFSecHostNodeBuff*>*>* dictByClusterIdx;
		std::map<cfsec::CFSecHostNodeByUDescrIdxKey,
			cfsec::CFSecHostNodeBuff*>* dictByUDescrIdx;
		std::map<cfsec::CFSecHostNodeByHostNameIdxKey,
			cfsec::CFSecHostNodeBuff*>* dictByHostNameIdx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamHostNodeTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamHostNodeTable();

		virtual cfsec::CFSecHostNodeBuff* createHostNode( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecHostNodeBuff* Buff );

		virtual cfsec::CFSecHostNodeBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecHostNodePKey* PKey );

		virtual cfsec::CFSecHostNodeBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecHostNodePKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual cfsec::CFSecHostNodeBuff* readDerivedByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& Description );

		virtual cfsec::CFSecHostNodeBuff* readDerivedByHostNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& HostName );

		virtual cfsec::CFSecHostNodeBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId );

		virtual cfsec::CFSecHostNodeBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecHostNodePKey* PKey );

		virtual cfsec::CFSecHostNodeBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecHostNodePKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorClusterId,
			const int64_t* priorHostNodeId );

		virtual cfsec::CFSecHostNodeBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId );

		virtual std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual cfsec::CFSecHostNodeBuff* readBuffByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& Description );

		virtual cfsec::CFSecHostNodeBuff* readBuffByHostNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& HostName );

		virtual cfsec::CFSecHostNodeBuff* readBuffByLookupHostNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& HostName,
			bool forceRead = false );

		virtual cfsec::CFSecHostNodeBuff* readDerivedByLookupHostNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& HostName,
			bool forceRead = false );

		virtual std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorHostNodeId );

		virtual cfsec::CFSecHostNodeBuff* updateHostNode( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecHostNodeBuff* Buff );

		virtual void deleteHostNode( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecHostNodeBuff* Buff );
		virtual void deleteHostNodeByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int64_t argHostNodeId );

		virtual void deleteHostNodeByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecHostNodePKey* argKey );

		virtual void deleteHostNodeByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId );

		virtual void deleteHostNodeByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecHostNodeByClusterIdxKey* argKey );

		virtual void deleteHostNodeByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const std::string& argDescription );

		virtual void deleteHostNodeByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecHostNodeByUDescrIdxKey* argKey );

		virtual void deleteHostNodeByHostNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const std::string& argHostName );

		virtual void deleteHostNodeByHostNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecHostNodeByHostNameIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
