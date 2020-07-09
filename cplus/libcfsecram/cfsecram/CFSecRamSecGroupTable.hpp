#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for SecGroup.

/*
 *	org.msscf.msscf.CFSec
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

	class CFSecRamSecGroupTable
	: public virtual cfsec::ICFSecSecGroupTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecSecGroupPKey,
			cfsec::CFSecSecGroupBuff*>* dictByPKey;
		std::map<cfsec::CFSecSecGroupByClusterIdxKey,
			std::map<cfsec::CFSecSecGroupPKey,
				cfsec::CFSecSecGroupBuff*>*>* dictByClusterIdx;
		std::map<cfsec::CFSecSecGroupByClusterVisIdxKey,
			std::map<cfsec::CFSecSecGroupPKey,
				cfsec::CFSecSecGroupBuff*>*>* dictByClusterVisIdx;
		std::map<cfsec::CFSecSecGroupByUNameIdxKey,
			cfsec::CFSecSecGroupBuff*>* dictByUNameIdx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamSecGroupTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamSecGroupTable();

		virtual cfsec::CFSecSecGroupBuff* createSecGroup( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGroupBuff* Buff );

		virtual cfsec::CFSecSecGroupBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupPKey* PKey );

		virtual cfsec::CFSecSecGroupBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> readDerivedByClusterVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const bool IsVisible );

		virtual cfsec::CFSecSecGroupBuff* readDerivedByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& Name );

		virtual cfsec::CFSecSecGroupBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId );

		virtual cfsec::CFSecSecGroupBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupPKey* PKey );

		virtual cfsec::CFSecSecGroupBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual cfsec::CFSecSecGroupBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> readBuffByClusterVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const bool IsVisible );

		virtual cfsec::CFSecSecGroupBuff* readBuffByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& Name );

		virtual cfsec::CFSecSecGroupBuff* readBuffByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& Name,
			bool forceRead = false );

		virtual cfsec::CFSecSecGroupBuff* readDerivedByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& Name,
			bool forceRead = false );

		virtual cfsec::CFSecSecGroupBuff* updateSecGroup( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGroupBuff* Buff );

		virtual void deleteSecGroup( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGroupBuff* Buff );
		virtual void deleteSecGroupByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecGroupId );

		virtual void deleteSecGroupByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupPKey* argKey );

		virtual void deleteSecGroupByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId );

		virtual void deleteSecGroupByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupByClusterIdxKey* argKey );

		virtual void deleteSecGroupByClusterVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const bool argIsVisible );

		virtual void deleteSecGroupByClusterVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupByClusterVisIdxKey* argKey );

		virtual void deleteSecGroupByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const std::string& argName );

		virtual void deleteSecGroupByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupByUNameIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
