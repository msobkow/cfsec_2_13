#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for TSecGroup.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at mark.sobkow@gmail.com for commercial licensing.
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
