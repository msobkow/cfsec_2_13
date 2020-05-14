#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for TSecGroup.

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

	class CFSecRamTSecGroupTable
	: public virtual cfsec::ICFSecTSecGroupTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecTSecGroupPKey,
			cfsec::CFSecTSecGroupBuff*>* dictByPKey;
		std::map<cfsec::CFSecTSecGroupByTenantIdxKey,
			std::map<cfsec::CFSecTSecGroupPKey,
				cfsec::CFSecTSecGroupBuff*>*>* dictByTenantIdx;
		std::map<cfsec::CFSecTSecGroupByTenantVisIdxKey,
			std::map<cfsec::CFSecTSecGroupPKey,
				cfsec::CFSecTSecGroupBuff*>*>* dictByTenantVisIdx;
		std::map<cfsec::CFSecTSecGroupByUNameIdxKey,
			cfsec::CFSecTSecGroupBuff*>* dictByUNameIdx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamTSecGroupTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamTSecGroupTable();

		virtual cfsec::CFSecTSecGroupBuff* createTSecGroup( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTSecGroupBuff* Buff );

		virtual cfsec::CFSecTSecGroupBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupPKey* PKey );

		virtual cfsec::CFSecTSecGroupBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId );

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> readDerivedByTenantVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const bool IsVisible );

		virtual cfsec::CFSecTSecGroupBuff* readDerivedByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const std::string& Name );

		virtual cfsec::CFSecTSecGroupBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId );

		virtual cfsec::CFSecTSecGroupBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupPKey* PKey );

		virtual cfsec::CFSecTSecGroupBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual cfsec::CFSecTSecGroupBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId );

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId );

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> readBuffByTenantVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const bool IsVisible );

		virtual cfsec::CFSecTSecGroupBuff* readBuffByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const std::string& Name );

		virtual cfsec::CFSecTSecGroupBuff* readBuffByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId, const std::string& Name,
			bool forceRead = false );

		virtual cfsec::CFSecTSecGroupBuff* readDerivedByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId, const std::string& Name,
			bool forceRead = false );

		virtual cfsec::CFSecTSecGroupBuff* updateTSecGroup( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTSecGroupBuff* Buff );

		virtual void deleteTSecGroup( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTSecGroupBuff* Buff );
		virtual void deleteTSecGroupByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int32_t argTSecGroupId );

		virtual void deleteTSecGroupByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupPKey* argKey );

		virtual void deleteTSecGroupByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId );

		virtual void deleteTSecGroupByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupByTenantIdxKey* argKey );

		virtual void deleteTSecGroupByTenantVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const bool argIsVisible );

		virtual void deleteTSecGroupByTenantVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupByTenantVisIdxKey* argKey );

		virtual void deleteTSecGroupByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const std::string& argName );

		virtual void deleteTSecGroupByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupByUNameIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
