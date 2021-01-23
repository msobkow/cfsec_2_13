#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for Tenant.

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
#include <cfsecram/CFSecRamTenantId32Gen.hpp>
#include <cfsecram/CFSecRamTenantId64Gen.hpp>

namespace cfsec {

	class CFSecRamTenantTable
	: public virtual cfsec::ICFSecTenantTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecTenantPKey,
			cfsec::CFSecTenantBuff*>* dictByPKey;
		std::map<cfsec::CFSecTenantByClusterIdxKey,
			std::map<cfsec::CFSecTenantPKey,
				cfsec::CFSecTenantBuff*>*>* dictByClusterIdx;
		std::map<cfsec::CFSecTenantByUNameIdxKey,
			cfsec::CFSecTenantBuff*>* dictByUNameIdx;
		std::map<cfsec::CFSecRamTenantId32Gen, cfsec::CFSecRamTenantId32Gen*>* id32Generator;
		std::map<cfsec::CFSecRamTenantId64Gen, cfsec::CFSecRamTenantId64Gen*>* id64Generator;
		virtual int32_t generateNextId32( int64_t argId,
			int16_t argSliceId );

		virtual int64_t generateNextId64( int64_t argId,
			int16_t argSliceId );

	public:
		static const std::string CLASS_NAME;
		CFSecRamTenantTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamTenantTable();

		virtual int32_t nextTSecGroupIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* pkey );

		virtual int32_t nextTSecGroupIdGen( const cfsec::CFSecAuthorization* Authorization,
			int64_t argId );

		virtual int64_t nextTSecGrpIncIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* pkey );

		virtual int64_t nextTSecGrpIncIdGen( const cfsec::CFSecAuthorization* Authorization,
			int64_t argId );

		virtual int64_t nextTSecGrpMembIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* pkey );

		virtual int64_t nextTSecGrpMembIdGen( const cfsec::CFSecAuthorization* Authorization,
			int64_t argId );

		virtual cfsec::CFSecTenantBuff* createTenant( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTenantBuff* Buff );

		virtual cfsec::CFSecTenantBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* PKey );

		virtual cfsec::CFSecTenantBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual cfsec::CFSecTenantBuff* readDerivedByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& TenantName );

		virtual cfsec::CFSecTenantBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t Id );

		virtual cfsec::CFSecTenantBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* PKey );

		virtual cfsec::CFSecTenantBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorId );

		virtual cfsec::CFSecTenantBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t Id );

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual cfsec::CFSecTenantBuff* readBuffByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& TenantName );

		virtual cfsec::CFSecTenantBuff* readBuffByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& TenantName,
			bool forceRead = false );

		virtual cfsec::CFSecTenantBuff* readDerivedByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& TenantName,
			bool forceRead = false );

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorId );

		virtual cfsec::CFSecTenantBuff* updateTenant( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTenantBuff* Buff );

		virtual void deleteTenant( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTenantBuff* Buff );
		virtual void deleteTenantByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argId );

		virtual void deleteTenantByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* argKey );

		virtual void deleteTenantByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId );

		virtual void deleteTenantByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantByClusterIdxKey* argKey );

		virtual void deleteTenantByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const std::string& argTenantName );

		virtual void deleteTenantByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantByUNameIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
