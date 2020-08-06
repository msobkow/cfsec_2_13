#pragma once

// Description: C++18 DbIO interface for TSecGrpMemb.

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
#include <cfsec/CFSecTSecGrpMembBuff.hpp>
#include <cfsec/CFSecTSecGrpMembPKey.hpp>
#include <cfsec/CFSecTSecGrpMembHBuff.hpp>
#include <cfsec/CFSecTSecGrpMembHPKey.hpp>
#include <cfsec/CFSecTSecGrpMembByTenantIdxKey.hpp>
#include <cfsec/CFSecTSecGrpMembByGroupIdxKey.hpp>
#include <cfsec/CFSecTSecGrpMembByUserIdxKey.hpp>
#include <cfsec/CFSecTSecGrpMembByUUserIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecTSecGrpMembObj;

	class ICFSecTSecGrpMembTable
	{
	public:
		ICFSecTSecGrpMembTable();
		virtual ~ICFSecTSecGrpMembTable();

		virtual cfsec::CFSecTSecGrpMembBuff* createTSecGrpMemb( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTSecGrpMembBuff* Buff ) = 0;

		virtual cfsec::CFSecTSecGrpMembBuff* updateTSecGrpMemb( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTSecGrpMembBuff* Buff ) = 0;

		virtual void deleteTSecGrpMemb( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTSecGrpMembBuff* Buff ) = 0;
		virtual void deleteTSecGrpMembByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTSecGrpMembId ) = 0;

		virtual void deleteTSecGrpMembByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpMembPKey* argKey ) = 0;
		virtual void deleteTSecGrpMembByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId ) = 0;

		virtual void deleteTSecGrpMembByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpMembByTenantIdxKey* argKey ) = 0;
		virtual void deleteTSecGrpMembByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int32_t argTSecGroupId ) = 0;

		virtual void deleteTSecGrpMembByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpMembByGroupIdxKey* argKey ) = 0;
		virtual void deleteTSecGrpMembByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId ) = 0;

		virtual void deleteTSecGrpMembByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpMembByUserIdxKey* argKey ) = 0;
		virtual void deleteTSecGrpMembByUUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int32_t argTSecGroupId,
			const uuid_ptr_t argSecUserId ) = 0;

		virtual void deleteTSecGrpMembByUUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpMembByUUserIdxKey* argKey ) = 0;

		virtual cfsec::CFSecTSecGrpMembBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpMembPKey* PKey ) = 0;

		virtual cfsec::CFSecTSecGrpMembBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpMembPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpMembBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecTSecGrpMembBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TSecGrpMembId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpMembBuff*> readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpMembBuff*> readDerivedByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpMembBuff*> readDerivedByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId ) = 0;

		virtual cfsec::CFSecTSecGrpMembBuff* readDerivedByUUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId,
			const uuid_ptr_t SecUserId ) = 0;

		virtual cfsec::CFSecTSecGrpMembBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpMembPKey* PKey ) = 0;

		virtual cfsec::CFSecTSecGrpMembBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpMembPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpMembBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpMembBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId ) = 0;

		virtual cfsec::CFSecTSecGrpMembBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TSecGrpMembId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpMembBuff*> readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpMembBuff*> readBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpMembBuff*> readBuffByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId ) = 0;

		virtual cfsec::CFSecTSecGrpMembBuff* readBuffByUUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId,
			const uuid_ptr_t SecUserId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpMembBuff*> pageBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpMembBuff*> pageBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpMembBuff*> pageBuffByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
