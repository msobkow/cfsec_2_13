#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for TSecGrpInc.

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

	class CFSecRamTSecGrpIncTable
	: public virtual cfsec::ICFSecTSecGrpIncTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecTSecGrpIncPKey,
			cfsec::CFSecTSecGrpIncBuff*>* dictByPKey;
		std::map<cfsec::CFSecTSecGrpIncByTenantIdxKey,
			std::map<cfsec::CFSecTSecGrpIncPKey,
				cfsec::CFSecTSecGrpIncBuff*>*>* dictByTenantIdx;
		std::map<cfsec::CFSecTSecGrpIncByGroupIdxKey,
			std::map<cfsec::CFSecTSecGrpIncPKey,
				cfsec::CFSecTSecGrpIncBuff*>*>* dictByGroupIdx;
		std::map<cfsec::CFSecTSecGrpIncByIncludeIdxKey,
			std::map<cfsec::CFSecTSecGrpIncPKey,
				cfsec::CFSecTSecGrpIncBuff*>*>* dictByIncludeIdx;
		std::map<cfsec::CFSecTSecGrpIncByUIncludeIdxKey,
			cfsec::CFSecTSecGrpIncBuff*>* dictByUIncludeIdx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamTSecGrpIncTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamTSecGrpIncTable();

		virtual cfsec::CFSecTSecGrpIncBuff* createTSecGrpInc( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTSecGrpIncBuff* Buff );

		virtual cfsec::CFSecTSecGrpIncBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncPKey* PKey );

		virtual cfsec::CFSecTSecGrpIncBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId );

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readDerivedByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId );

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readDerivedByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t IncludeGroupId );

		virtual cfsec::CFSecTSecGrpIncBuff* readDerivedByUIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId,
			const int32_t IncludeGroupId );

		virtual cfsec::CFSecTSecGrpIncBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TSecGrpIncId );

		virtual cfsec::CFSecTSecGrpIncBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncPKey* PKey );

		virtual cfsec::CFSecTSecGrpIncBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId );

		virtual cfsec::CFSecTSecGrpIncBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TSecGrpIncId );

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId );

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId );

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> readBuffByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t IncludeGroupId );

		virtual cfsec::CFSecTSecGrpIncBuff* readBuffByUIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId,
			const int32_t IncludeGroupId );

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> pageBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId );

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> pageBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t TSecGroupId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId );

		virtual std::TCFLibOwningVector<cfsec::CFSecTSecGrpIncBuff*> pageBuffByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int32_t IncludeGroupId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId );

		virtual cfsec::CFSecTSecGrpIncBuff* updateTSecGrpInc( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTSecGrpIncBuff* Buff );

		virtual void deleteTSecGrpInc( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTSecGrpIncBuff* Buff );
		virtual void deleteTSecGrpIncByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTSecGrpIncId );

		virtual void deleteTSecGrpIncByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncPKey* argKey );

		virtual void deleteTSecGrpIncByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId );

		virtual void deleteTSecGrpIncByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncByTenantIdxKey* argKey );

		virtual void deleteTSecGrpIncByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int32_t argTSecGroupId );

		virtual void deleteTSecGrpIncByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncByGroupIdxKey* argKey );

		virtual void deleteTSecGrpIncByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int32_t argIncludeGroupId );

		virtual void deleteTSecGrpIncByIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncByIncludeIdxKey* argKey );

		virtual void deleteTSecGrpIncByUIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int32_t argTSecGroupId,
			const int32_t argIncludeGroupId );

		virtual void deleteTSecGrpIncByUIncludeIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTSecGrpIncByUIncludeIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
