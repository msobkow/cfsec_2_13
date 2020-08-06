#pragma once

// Description: C++18 DbIO interface for TSecGroup.

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
#include <cfsec/CFSecTSecGroupBuff.hpp>
#include <cfsec/CFSecTSecGroupPKey.hpp>
#include <cfsec/CFSecTSecGroupHBuff.hpp>
#include <cfsec/CFSecTSecGroupHPKey.hpp>
#include <cfsec/CFSecTSecGroupByTenantIdxKey.hpp>
#include <cfsec/CFSecTSecGroupByTenantVisIdxKey.hpp>
#include <cfsec/CFSecTSecGroupByUNameIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecTSecGroupObj;

	class ICFSecTSecGroupTable
	{
	public:
		ICFSecTSecGroupTable();
		virtual ~ICFSecTSecGroupTable();

		virtual cfsec::CFSecTSecGroupBuff* createTSecGroup( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTSecGroupBuff* Buff ) = 0;

		virtual cfsec::CFSecTSecGroupBuff* updateTSecGroup( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTSecGroupBuff* Buff ) = 0;

		virtual void deleteTSecGroup( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTSecGroupBuff* Buff ) = 0;
		virtual void deleteTSecGroupByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int32_t argTSecGroupId ) = 0;

		virtual void deleteTSecGroupByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupPKey* argKey ) = 0;
		virtual void deleteTSecGroupByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId ) = 0;

		virtual void deleteTSecGroupByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupByTenantIdxKey* argKey ) = 0;
		virtual void deleteTSecGroupByTenantVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const bool argIsVisible ) = 0;

		virtual void deleteTSecGroupByTenantVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupByTenantVisIdxKey* argKey ) = 0;
		virtual void deleteTSecGroupByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const std::string& argName ) = 0;

		virtual void deleteTSecGroupByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupByUNameIdxKey* argKey ) = 0;

		virtual cfsec::CFSecTSecGroupBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupPKey* PKey ) = 0;

		virtual cfsec::CFSecTSecGroupBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecTSecGroupBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> readDerivedByTenantVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const bool IsVisible ) = 0;

		virtual cfsec::CFSecTSecGroupBuff* readDerivedByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const std::string& Name ) = 0;

		virtual cfsec::CFSecTSecGroupBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupPKey* PKey ) = 0;

		virtual cfsec::CFSecTSecGroupBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGroupPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecTSecGroupBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGroupBuff*> readBuffByTenantVisIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const bool IsVisible ) = 0;

		virtual cfsec::CFSecTSecGroupBuff* readBuffByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const std::string& Name ) = 0;

		virtual cfsec::CFSecTSecGroupBuff* readBuffByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfsec::CFSecTSecGroupBuff* readDerivedByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
