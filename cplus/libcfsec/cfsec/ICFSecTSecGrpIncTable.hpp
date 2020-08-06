#pragma once

// Description: C++18 DbIO interface for TSecGrpInc.

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
#include <cfsec/CFSecTSecGrpIncBuff.hpp>
#include <cfsec/CFSecTSecGrpIncPKey.hpp>
#include <cfsec/CFSecTSecGrpIncHBuff.hpp>
#include <cfsec/CFSecTSecGrpIncHPKey.hpp>
#include <cfsec/CFSecTSecGrpIncByTenantIdxKey.hpp>
#include <cfsec/CFSecTSecGrpIncByGroupIdxKey.hpp>
#include <cfsec/CFSecTSecGrpIncByIncludeIdxKey.hpp>
#include <cfsec/CFSecTSecGrpIncByUIncludeIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecTSecGrpIncObj;

	class ICFSecTSecGrpIncTable
	{
	public:
		ICFSecTSecGrpIncTable();
		virtual ~ICFSecTSecGrpIncTable();

		virtual cfsec::CFSecTSecGrpIncBuff* createTSecGrpInc( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTSecGrpIncBuff* Buff ) = 0;

		virtual cfsec::CFSecTSecGrpIncBuff* updateTSecGrpInc( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTSecGrpIncBuff* Buff ) = 0;

		virtual void deleteTSecGrpInc( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTSecGrpIncBuff* Buff ) = 0;
		virtual void deleteTSecGrpIncByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTSecGrpIncId ) = 0;

		virtual void deleteTSecGrpIncByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncPKey* argKey ) = 0;
		virtual void deleteTSecGrpIncByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId ) = 0;

		virtual void deleteTSecGrpIncByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncByTenantIdxKey* argKey ) = 0;
		virtual void deleteTSecGrpIncByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int32_t argTSecGroupId ) = 0;

		virtual void deleteTSecGrpIncByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncByGroupIdxKey* argKey ) = 0;
		virtual void deleteTSecGrpIncByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int32_t argIncludeGroupId ) = 0;

		virtual void deleteTSecGrpIncByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncByIncludeIdxKey* argKey ) = 0;
		virtual void deleteTSecGrpIncByUIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int32_t argTSecGroupId,
			const int32_t argIncludeGroupId ) = 0;

		virtual void deleteTSecGrpIncByUIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncByUIncludeIdxKey* argKey ) = 0;

		virtual cfsec::CFSecTSecGrpIncBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncPKey* PKey ) = 0;

		virtual cfsec::CFSecTSecGrpIncBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecTSecGrpIncBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TSecGrpIncId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readDerivedByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readDerivedByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t IncludeGroupId ) = 0;

		virtual cfsec::CFSecTSecGrpIncBuff* readDerivedByUIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId,
			const int32_t IncludeGroupId ) = 0;

		virtual cfsec::CFSecTSecGrpIncBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncPKey* PKey ) = 0;

		virtual cfsec::CFSecTSecGrpIncBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId ) = 0;

		virtual cfsec::CFSecTSecGrpIncBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TSecGrpIncId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readBuffByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t IncludeGroupId ) = 0;

		virtual cfsec::CFSecTSecGrpIncBuff* readBuffByUIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId,
			const int32_t IncludeGroupId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> pageBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> pageBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> pageBuffByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t IncludeGroupId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
