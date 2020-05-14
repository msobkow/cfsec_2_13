#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for SecGrpMemb.

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

	class CFSecRamSecGrpMembTable
	: public virtual cfsec::ICFSecSecGrpMembTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecSecGrpMembPKey,
			cfsec::CFSecSecGrpMembBuff*>* dictByPKey;
		std::map<cfsec::CFSecSecGrpMembByClusterIdxKey,
			std::map<cfsec::CFSecSecGrpMembPKey,
				cfsec::CFSecSecGrpMembBuff*>*>* dictByClusterIdx;
		std::map<cfsec::CFSecSecGrpMembByGroupIdxKey,
			std::map<cfsec::CFSecSecGrpMembPKey,
				cfsec::CFSecSecGrpMembBuff*>*>* dictByGroupIdx;
		std::map<cfsec::CFSecSecGrpMembByUserIdxKey,
			std::map<cfsec::CFSecSecGrpMembPKey,
				cfsec::CFSecSecGrpMembBuff*>*>* dictByUserIdx;
		std::map<cfsec::CFSecSecGrpMembByUUserIdxKey,
			cfsec::CFSecSecGrpMembBuff*>* dictByUUserIdx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamSecGrpMembTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamSecGrpMembTable();

		virtual cfsec::CFSecSecGrpMembBuff* createSecGrpMemb( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGrpMembBuff* Buff );

		virtual cfsec::CFSecSecGrpMembBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpMembPKey* PKey );

		virtual cfsec::CFSecSecGrpMembBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpMembPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> readDerivedByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> readDerivedByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId );

		virtual cfsec::CFSecSecGrpMembBuff* readDerivedByUUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const uuid_ptr_t SecUserId );

		virtual cfsec::CFSecSecGrpMembBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t SecGrpMembId );

		virtual cfsec::CFSecSecGrpMembBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpMembPKey* PKey );

		virtual cfsec::CFSecSecGrpMembBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpMembPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId );

		virtual cfsec::CFSecSecGrpMembBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t SecGrpMembId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> readBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> readBuffByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId );

		virtual cfsec::CFSecSecGrpMembBuff* readBuffByUUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const uuid_ptr_t SecUserId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> pageBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGrpMembBuff*> pageBuffByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId );

		virtual cfsec::CFSecSecGrpMembBuff* updateSecGrpMemb( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGrpMembBuff* Buff );

		virtual void deleteSecGrpMemb( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGrpMembBuff* Buff );
		virtual void deleteSecGrpMembByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int64_t argSecGrpMembId );

		virtual void deleteSecGrpMembByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpMembPKey* argKey );

		virtual void deleteSecGrpMembByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId );

		virtual void deleteSecGrpMembByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpMembByClusterIdxKey* argKey );

		virtual void deleteSecGrpMembByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecGroupId );

		virtual void deleteSecGrpMembByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpMembByGroupIdxKey* argKey );

		virtual void deleteSecGrpMembByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId );

		virtual void deleteSecGrpMembByUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpMembByUserIdxKey* argKey );

		virtual void deleteSecGrpMembByUUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecGroupId,
			const uuid_ptr_t argSecUserId );

		virtual void deleteSecGrpMembByUUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGrpMembByUUserIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
