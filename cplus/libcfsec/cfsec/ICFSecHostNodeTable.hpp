#pragma once

// Description: C++18 DbIO interface for HostNode.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
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
