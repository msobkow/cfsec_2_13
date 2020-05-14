#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for SecForm.

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

	class CFSecRamSecFormTable
	: public virtual cfsec::ICFSecSecFormTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecSecFormPKey,
			cfsec::CFSecSecFormBuff*>* dictByPKey;
		std::map<cfsec::CFSecSecFormByClusterIdxKey,
			std::map<cfsec::CFSecSecFormPKey,
				cfsec::CFSecSecFormBuff*>*>* dictByClusterIdx;
		std::map<cfsec::CFSecSecFormBySecAppIdxKey,
			std::map<cfsec::CFSecSecFormPKey,
				cfsec::CFSecSecFormBuff*>*>* dictBySecAppIdx;
		std::map<cfsec::CFSecSecFormByUJEEServletIdxKey,
			cfsec::CFSecSecFormBuff*>* dictByUJEEServletIdx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamSecFormTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamSecFormTable();

		virtual cfsec::CFSecSecFormBuff* createSecForm( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecFormBuff* Buff );

		virtual cfsec::CFSecSecFormBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormPKey* PKey );

		virtual cfsec::CFSecSecFormBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> readDerivedBySecAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId );

		virtual cfsec::CFSecSecFormBuff* readDerivedByUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName );

		virtual cfsec::CFSecSecFormBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecFormId );

		virtual cfsec::CFSecSecFormBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormPKey* PKey );

		virtual cfsec::CFSecSecFormBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorClusterId,
			const int32_t* priorSecFormId );

		virtual cfsec::CFSecSecFormBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecFormId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> readBuffBySecAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId );

		virtual cfsec::CFSecSecFormBuff* readBuffByUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName );

		virtual cfsec::CFSecSecFormBuff* readBuffByLookupUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId, const std::string& JEEServletMapName,
			bool forceRead = false );

		virtual cfsec::CFSecSecFormBuff* readDerivedByLookupUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId, const std::string& JEEServletMapName,
			bool forceRead = false );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int32_t* priorSecFormId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> pageBuffBySecAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId,
			const int64_t* priorClusterId,
			const int32_t* priorSecFormId );

		virtual cfsec::CFSecSecFormBuff* updateSecForm( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecFormBuff* Buff );

		virtual void deleteSecForm( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSecFormBuff* Buff );
		virtual void deleteSecFormByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecFormId );

		virtual void deleteSecFormByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormPKey* argKey );

		virtual void deleteSecFormByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId );

		virtual void deleteSecFormByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormByClusterIdxKey* argKey );

		virtual void deleteSecFormBySecAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecAppId );

		virtual void deleteSecFormBySecAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormBySecAppIdxKey* argKey );

		virtual void deleteSecFormByUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecAppId,
			const std::string& argJEEServletMapName );

		virtual void deleteSecFormByUJEEServletIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSecFormByUJEEServletIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
