#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for SecGroupForm.

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
#include <cfsec/ICFSecPublic.hpp>
#include <cfsecobj/ICFSecObjPublic.hpp>
#include <cfsecsaxloader/CFSecSaxLoader.hpp>

namespace cfsec {

	class CFSecRamSecGroupFormTable
	: public virtual cfsec::ICFSecSecGroupFormTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecSecGroupFormPKey,
			cfsec::CFSecSecGroupFormBuff*>* dictByPKey;
		std::map<cfsec::CFSecSecGroupFormByClusterIdxKey,
			std::map<cfsec::CFSecSecGroupFormPKey,
				cfsec::CFSecSecGroupFormBuff*>*>* dictByClusterIdx;
		std::map<cfsec::CFSecSecGroupFormByGroupIdxKey,
			std::map<cfsec::CFSecSecGroupFormPKey,
				cfsec::CFSecSecGroupFormBuff*>*>* dictByGroupIdx;
		std::map<cfsec::CFSecSecGroupFormByAppIdxKey,
			std::map<cfsec::CFSecSecGroupFormPKey,
				cfsec::CFSecSecGroupFormBuff*>*>* dictByAppIdx;
		std::map<cfsec::CFSecSecGroupFormByFormIdxKey,
			std::map<cfsec::CFSecSecGroupFormPKey,
				cfsec::CFSecSecGroupFormBuff*>*>* dictByFormIdx;
		std::map<cfsec::CFSecSecGroupFormByUFormIdxKey,
			cfsec::CFSecSecGroupFormBuff*>* dictByUFormIdx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamSecGroupFormTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamSecGroupFormTable();

		virtual cfsec::CFSecSecGroupFormBuff* createSecGroupForm( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGroupFormBuff* Buff );

		virtual cfsec::CFSecSecGroupFormBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupFormPKey* PKey );

		virtual cfsec::CFSecSecGroupFormBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupFormPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> readDerivedByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> readDerivedByAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> readDerivedByFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecFormId );

		virtual cfsec::CFSecSecGroupFormBuff* readDerivedByUFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId );

		virtual cfsec::CFSecSecGroupFormBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t SecGroupFormId );

		virtual cfsec::CFSecSecGroupFormBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupFormPKey* PKey );

		virtual cfsec::CFSecSecGroupFormBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupFormPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId );

		virtual cfsec::CFSecSecGroupFormBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t SecGroupFormId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> readBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> readBuffByAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> readBuffByFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecFormId );

		virtual cfsec::CFSecSecGroupFormBuff* readBuffByUFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> pageBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> pageBuffByAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> pageBuffByFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecFormId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId );

		virtual cfsec::CFSecSecGroupFormBuff* updateSecGroupForm( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGroupFormBuff* Buff );

		virtual void deleteSecGroupForm( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecGroupFormBuff* Buff );
		virtual void deleteSecGroupFormByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int64_t argSecGroupFormId );

		virtual void deleteSecGroupFormByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupFormPKey* argKey );

		virtual void deleteSecGroupFormByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId );

		virtual void deleteSecGroupFormByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupFormByClusterIdxKey* argKey );

		virtual void deleteSecGroupFormByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecGroupId );

		virtual void deleteSecGroupFormByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupFormByGroupIdxKey* argKey );

		virtual void deleteSecGroupFormByAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecAppId );

		virtual void deleteSecGroupFormByAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupFormByAppIdxKey* argKey );

		virtual void deleteSecGroupFormByFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecFormId );

		virtual void deleteSecGroupFormByFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupFormByFormIdxKey* argKey );

		virtual void deleteSecGroupFormByUFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecGroupId,
			const int32_t argSecFormId );

		virtual void deleteSecGroupFormByUFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecGroupFormByUFormIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
