#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for SysCluster.

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

	class CFSecRamSysClusterTable
	: public virtual cfsec::ICFSecSysClusterTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecSysClusterPKey,
			cfsec::CFSecSysClusterBuff*>* dictByPKey;
		std::map<cfsec::CFSecSysClusterByClusterIdxKey,
			std::map<cfsec::CFSecSysClusterPKey,
				cfsec::CFSecSysClusterBuff*>*>* dictByClusterIdx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamSysClusterTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamSysClusterTable();

		virtual cfsec::CFSecSysClusterBuff* createSysCluster( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSysClusterBuff* Buff );

		virtual cfsec::CFSecSysClusterBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSysClusterPKey* PKey );

		virtual cfsec::CFSecSysClusterBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSysClusterPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual cfsec::CFSecSysClusterBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t SingletonId );

		virtual cfsec::CFSecSysClusterBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSysClusterPKey* PKey );

		virtual cfsec::CFSecSysClusterBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSysClusterPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual cfsec::CFSecSysClusterBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t SingletonId );

		virtual std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual cfsec::CFSecSysClusterBuff* updateSysCluster( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSysClusterBuff* Buff );

		virtual void deleteSysCluster( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecSysClusterBuff* Buff );
		virtual void deleteSysClusterByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t argSingletonId );

		virtual void deleteSysClusterByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSysClusterPKey* argKey );

		virtual void deleteSysClusterByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId );

		virtual void deleteSysClusterByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecSysClusterByClusterIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
