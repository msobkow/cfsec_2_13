#pragma once

// Description: C++18 DbIO interface for SecGrpInc.

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
#include <cfsec/CFSecSecGrpIncBuff.hpp>
#include <cfsec/CFSecSecGrpIncPKey.hpp>
#include <cfsec/CFSecSecGrpIncHBuff.hpp>
#include <cfsec/CFSecSecGrpIncHPKey.hpp>
#include <cfsec/CFSecSecGrpIncByClusterIdxKey.hpp>
#include <cfsec/CFSecSecGrpIncByGroupIdxKey.hpp>
#include <cfsec/CFSecSecGrpIncByIncludeIdxKey.hpp>
#include <cfsec/CFSecSecGrpIncByUIncludeIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecSecGrpIncObj;

	class ICFSecSecGrpIncTable
	{
	public:
		ICFSecSecGrpIncTable();
		virtual ~ICFSecSecGrpIncTable();

		virtual cfsec::CFSecSecGrpIncBuff* createSecGrpInc( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGrpIncBuff* Buff ) = 0;

		virtual cfsec::CFSecSecGrpIncBuff* updateSecGrpInc( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGrpIncBuff* Buff ) = 0;

		virtual void deleteSecGrpInc( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGrpIncBuff* Buff ) = 0;
		virtual void deleteSecGrpIncByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int64_t argSecGrpIncId ) = 0;

		virtual void deleteSecGrpIncByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpIncPKey* argKey ) = 0;
		virtual void deleteSecGrpIncByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId ) = 0;

		virtual void deleteSecGrpIncByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpIncByClusterIdxKey* argKey ) = 0;
		virtual void deleteSecGrpIncByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecGroupId ) = 0;

		virtual void deleteSecGrpIncByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpIncByGroupIdxKey* argKey ) = 0;
		virtual void deleteSecGrpIncByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argIncludeGroupId ) = 0;

		virtual void deleteSecGrpIncByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpIncByIncludeIdxKey* argKey ) = 0;
		virtual void deleteSecGrpIncByUIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecGroupId,
			const int32_t argIncludeGroupId ) = 0;

		virtual void deleteSecGrpIncByUIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpIncByUIncludeIdxKey* argKey ) = 0;

		virtual cfsec::CFSecSecGrpIncBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpIncPKey* PKey ) = 0;

		virtual cfsec::CFSecSecGrpIncBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpIncPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecSecGrpIncBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t SecGrpIncId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> readDerivedByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> readDerivedByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t IncludeGroupId ) = 0;

		virtual cfsec::CFSecSecGrpIncBuff* readDerivedByUIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId ) = 0;

		virtual cfsec::CFSecSecGrpIncBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpIncPKey* PKey ) = 0;

		virtual cfsec::CFSecSecGrpIncBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpIncPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId ) = 0;

		virtual cfsec::CFSecSecGrpIncBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t SecGrpIncId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> readBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> readBuffByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t IncludeGroupId ) = 0;

		virtual cfsec::CFSecSecGrpIncBuff* readBuffByUIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> pageBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> pageBuffByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t IncludeGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
