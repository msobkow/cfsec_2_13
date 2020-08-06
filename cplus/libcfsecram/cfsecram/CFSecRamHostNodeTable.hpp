#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for HostNode.

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
