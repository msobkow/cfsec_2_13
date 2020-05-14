#pragma once

// Description: C++18 CFSec Authorization Specification

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
#include <cfsecobj/ICFSecClusterObj.hpp>
#include <cfsecobj/ICFSecTenantObj.hpp>
#include <cfsecobj/ICFSecSecSessionObj.hpp>
#include <cfsecobj/ICFSecSecUserObj.hpp>


namespace cfsec {

	class CFSecAuthorization
	{
		protected:
			uuid_t authUUID;
			std::string authUUIDStr;

			int64_t secClusterId;
			int64_t secTenantId;
			uuid_t secSessionId;
			uuid_t secUserId;

		public:
			CFSecAuthorization();
			virtual ~CFSecAuthorization();

			const uuid_ptr_t getAuthUUID() const;
			void setAuthUUID( const uuid_ptr_t value );
			const std::string getAuthUUIDStr();

			int64_t getSecClusterId() const;
			void setSecClusterId( int64_t clusterId );
			void setSecCluster( cfsec::ICFSecClusterObj& value );

			int64_t getSecTenantId() const;
			void setSecTenantId( int64_t tenantId );
			void setSecTenant( cfsec::ICFSecTenantObj& value );

			const uuid_ptr_t getSecSessionId() const;
			void setSecSessionId( const uuid_ptr_t sessionId );
			void setSecSession( cfsec::ICFSecSecSessionObj* value );

			const uuid_ptr_t getSecUserId() const;
			void setSecUserId( const uuid_ptr_t userId );
	};
}
