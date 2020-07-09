#pragma once

// Description: C++18 DbIO interface for SecGroupForm.

/*
 *	org.msscf.msscf.CFSec
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
#include <cfsec/CFSecAuthorization.hpp>
#include <cfsec/CFSecHPKey.hpp>
#include <cfsec/CFSecSecGroupFormBuff.hpp>
#include <cfsec/CFSecSecGroupFormPKey.hpp>
#include <cfsec/CFSecSecGroupFormHBuff.hpp>
#include <cfsec/CFSecSecGroupFormHPKey.hpp>
#include <cfsec/CFSecSecGroupFormByClusterIdxKey.hpp>
#include <cfsec/CFSecSecGroupFormByGroupIdxKey.hpp>
#include <cfsec/CFSecSecGroupFormByAppIdxKey.hpp>
#include <cfsec/CFSecSecGroupFormByFormIdxKey.hpp>
#include <cfsec/CFSecSecGroupFormByUFormIdxKey.hpp>

namespace cfsec {
	class ICFSecSchemaObj;
}

namespace cfsec {
	class ICFSecSecGroupFormObj;

	class ICFSecSecGroupFormTable
	{
	public:
		ICFSecSecGroupFormTable();
		virtual ~ICFSecSecGroupFormTable();

		virtual cfsec::CFSecSecGroupFormBuff* createSecGroupForm( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGroupFormBuff* Buff ) = 0;

		virtual cfsec::CFSecSecGroupFormBuff* updateSecGroupForm( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGroupFormBuff* Buff ) = 0;

		virtual void deleteSecGroupForm( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGroupFormBuff* Buff ) = 0;
		virtual void deleteSecGroupFormByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int64_t argSecGroupFormId ) = 0;

		virtual void deleteSecGroupFormByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupFormPKey* argKey ) = 0;
		virtual void deleteSecGroupFormByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId ) = 0;

		virtual void deleteSecGroupFormByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupFormByClusterIdxKey* argKey ) = 0;
		virtual void deleteSecGroupFormByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecGroupId ) = 0;

		virtual void deleteSecGroupFormByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupFormByGroupIdxKey* argKey ) = 0;
		virtual void deleteSecGroupFormByAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecAppId ) = 0;

		virtual void deleteSecGroupFormByAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupFormByAppIdxKey* argKey ) = 0;
		virtual void deleteSecGroupFormByFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecFormId ) = 0;

		virtual void deleteSecGroupFormByFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupFormByFormIdxKey* argKey ) = 0;
		virtual void deleteSecGroupFormByUFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecGroupId,
			const int32_t argSecFormId ) = 0;

		virtual void deleteSecGroupFormByUFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupFormByUFormIdxKey* argKey ) = 0;

		virtual cfsec::CFSecSecGroupFormBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupFormPKey* PKey ) = 0;

		virtual cfsec::CFSecSecGroupFormBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupFormPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfsec::CFSecSecGroupFormBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t SecGroupFormId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> readDerivedByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> readDerivedByAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> readDerivedByFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecFormId ) = 0;

		virtual cfsec::CFSecSecGroupFormBuff* readDerivedByUFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId ) = 0;

		virtual cfsec::CFSecSecGroupFormBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupFormPKey* PKey ) = 0;

		virtual cfsec::CFSecSecGroupFormBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupFormPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId ) = 0;

		virtual cfsec::CFSecSecGroupFormBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t SecGroupFormId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> readBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> readBuffByAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> readBuffByFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecFormId ) = 0;

		virtual cfsec::CFSecSecGroupFormBuff* readBuffByUFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> pageBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> pageBuffByAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId ) = 0;

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> pageBuffByFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecFormId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
