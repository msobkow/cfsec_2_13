#pragma once

// Description: C++18 DbIO interface for Tenant.

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
#include <cfsec/CFSecAuthorization.hpp>
#include <cfsec/CFSecHPKey.hpp>
#include <cfsec/CFSecTenantBuff.hpp>
#include <cfsec/CFSecTenantPKey.hpp>
#include <cfsec/CFSecTenantHBuff.hpp>
#include <cfsec/CFSecTenantHPKey.hpp>
#include <cfsec/CFSecTenantByClusterIdxKey.hpp>
#include <cfsec/CFSecTenantByUNameIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecTenantObj;

	class ICFSecTenantTable
	{
	public:
		ICFSecTenantTable();
		virtual ~ICFSecTenantTable();

		virtual int32_t nextTSecGroupIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* PKey ) = 0;

		virtual int32_t nextTSecGroupIdGen( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argId ) = 0;

		virtual int64_t nextTSecGrpIncIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* PKey ) = 0;

		virtual int64_t nextTSecGrpIncIdGen( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argId ) = 0;

		virtual int64_t nextTSecGrpMembIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* PKey ) = 0;

		virtual int64_t nextTSecGrpMembIdGen( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argId ) = 0;

		virtual cfsec::CFSecTenantBuff* createTenant( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTenantBuff* Buff ) = 0;

		virtual cfsec::CFSecTenantBuff* updateTenant( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTenantBuff* Buff ) = 0;

		virtual void deleteTenant( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTenantBuff* Buff ) = 0;
		virtual void deleteTenantByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argId ) = 0;

		virtual void deleteTenantByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* argKey ) = 0;
		virtual void deleteTenantByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId ) = 0;

		virtual void deleteTenantByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantByClusterIdxKey* argKey ) = 0;
		virtual void deleteTenantByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const std::string& argTenantName ) = 0;

		virtual void deleteTenantByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantByUNameIdxKey* argKey ) = 0;

		virtual cfsec::CFSecTenantBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* PKey ) = 0;

		virtual cfsec::CFSecTenantBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecTenantBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t Id ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual cfsec::CFSecTenantBuff* readDerivedByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& TenantName ) = 0;

		virtual cfsec::CFSecTenantBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* PKey ) = 0;

		virtual cfsec::CFSecTenantBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorId ) = 0;

		virtual cfsec::CFSecTenantBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t Id ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual cfsec::CFSecTenantBuff* readBuffByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& TenantName ) = 0;

		virtual cfsec::CFSecTenantBuff* readBuffByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& TenantName,
			bool forceRead = false ) = 0;

		virtual cfsec::CFSecTenantBuff* readDerivedByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& TenantName,
			bool forceRead = false ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorId ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
