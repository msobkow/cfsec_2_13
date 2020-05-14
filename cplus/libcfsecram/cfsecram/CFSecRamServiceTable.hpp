#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for Service.

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

	class CFSecRamServiceTable
	: public virtual cfsec::ICFSecServiceTable
	{
	protected:
		cfsec::ICFSecSchema* schema;
		std::map<cfsec::CFSecServicePKey,
			cfsec::CFSecServiceBuff*>* dictByPKey;
		std::map<cfsec::CFSecServiceByClusterIdxKey,
			std::map<cfsec::CFSecServicePKey,
				cfsec::CFSecServiceBuff*>*>* dictByClusterIdx;
		std::map<cfsec::CFSecServiceByHostIdxKey,
			std::map<cfsec::CFSecServicePKey,
				cfsec::CFSecServiceBuff*>*>* dictByHostIdx;
		std::map<cfsec::CFSecServiceByTypeIdxKey,
			std::map<cfsec::CFSecServicePKey,
				cfsec::CFSecServiceBuff*>*>* dictByTypeIdx;
		std::map<cfsec::CFSecServiceByUTypeIdxKey,
			cfsec::CFSecServiceBuff*>* dictByUTypeIdx;
		std::map<cfsec::CFSecServiceByUHostPortIdxKey,
			cfsec::CFSecServiceBuff*>* dictByUHostPortIdx;
	public:
		static const std::string CLASS_NAME;
		CFSecRamServiceTable( cfsec::ICFSecSchema* argSchema );

		virtual ~CFSecRamServiceTable();

		virtual cfsec::CFSecServiceBuff* createService( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecServiceBuff* Buff );

		virtual cfsec::CFSecServiceBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServicePKey* PKey );

		virtual cfsec::CFSecServiceBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServicePKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> readDerivedByHostIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId );

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> readDerivedByTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t ServiceTypeId );

		virtual cfsec::CFSecServiceBuff* readDerivedByUTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId );

		virtual cfsec::CFSecServiceBuff* readDerivedByUHostPortIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort );

		virtual cfsec::CFSecServiceBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t ServiceId );

		virtual cfsec::CFSecServiceBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServicePKey* PKey );

		virtual cfsec::CFSecServiceBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServicePKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId );

		virtual cfsec::CFSecServiceBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t ServiceId );

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> readBuffByHostIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId );

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> readBuffByTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t ServiceTypeId );

		virtual cfsec::CFSecServiceBuff* readBuffByUTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId );

		virtual cfsec::CFSecServiceBuff* readBuffByUHostPortIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort );

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId );

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> pageBuffByHostIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t HostNodeId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId );

		virtual std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> pageBuffByTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t ServiceTypeId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId );

		virtual cfsec::CFSecServiceBuff* updateService( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecServiceBuff* Buff );

		virtual void deleteService( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecServiceBuff* Buff );
		virtual void deleteServiceByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int64_t argServiceId );

		virtual void deleteServiceByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServicePKey* argKey );

		virtual void deleteServiceByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId );

		virtual void deleteServiceByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServiceByClusterIdxKey* argKey );

		virtual void deleteServiceByHostIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int64_t argHostNodeId );

		virtual void deleteServiceByHostIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServiceByHostIdxKey* argKey );

		virtual void deleteServiceByTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t argServiceTypeId );

		virtual void deleteServiceByTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServiceByTypeIdxKey* argKey );

		virtual void deleteServiceByUTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int64_t argHostNodeId,
			const int32_t argServiceTypeId );

		virtual void deleteServiceByUTypeIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServiceByUTypeIdxKey* argKey );

		virtual void deleteServiceByUHostPortIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int64_t argHostNodeId,
			const int16_t argHostPort );

		virtual void deleteServiceByUHostPortIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecServiceByUHostPortIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
