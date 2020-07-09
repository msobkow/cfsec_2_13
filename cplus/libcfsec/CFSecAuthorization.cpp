// Description: C++18 CFSec Authorization Implementation

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

using namespace std;

#include <cfsec/ICFSecPublic.hpp>
#include <cfsec/CFSecAuthorization.hpp>
#include <cfsecobj/ICFSecClusterObj.hpp>
#include <cfsecobj/ICFSecTenantObj.hpp>
#include <cfsecobj/ICFSecSecSessionObj.hpp>
#include <cfsecobj/ICFSecSecUserObj.hpp>
#include <cfsecobj/ICFSecClusterTableObj.hpp>
#include <cfsecobj/ICFSecTenantTableObj.hpp>
#include <cfsecobj/ICFSecSecSessionTableObj.hpp>
#include <cfsecobj/ICFSecSecUserTableObj.hpp>

namespace cfsec {

	CFSecAuthorization::CFSecAuthorization()
	{
		uuid_generate_random( authUUID );
		authUUIDStr = cflib::CFLibXmlUtil::formatUuid( authUUID );
		secClusterId = 0L;
		secTenantId = 0L;
		for( int i = 0; i < 16; i++ ) {
			secSessionId[i] = 0;
		}
		for( int i = 0; i < 16; i++ ) {
			secUserId[i] = 0;
		}
	}

	CFSecAuthorization::~CFSecAuthorization() {
	}

	const uuid_ptr_t CFSecAuthorization::getAuthUUID() const {
		return( authUUID );
	}

	void CFSecAuthorization::setAuthUUID( const uuid_ptr_t value ) {
		uuid_copy( authUUID, value );
		authUUIDStr = cflib::CFLibXmlUtil::formatUuid( authUUID );
	}

	const std::string CFSecAuthorization::getAuthUUIDStr() {
		return( authUUIDStr );
	}

	int64_t CFSecAuthorization::getSecClusterId() const {
		return( secClusterId );
	}

	void CFSecAuthorization::setSecClusterId( int64_t clusterId ) {
		secClusterId = clusterId;
	}

	void CFSecAuthorization::setSecCluster( cfsec::ICFSecClusterObj& value ) {
		secClusterId = value.getRequiredId();
	}

	int64_t CFSecAuthorization::getSecTenantId() const {
		return( secTenantId );
	}

	void CFSecAuthorization::setSecTenantId( int64_t tenantId ) {
		secTenantId = tenantId;
	}

	void CFSecAuthorization::setSecTenant( cfsec::ICFSecTenantObj& value ) {
		secTenantId = value.getRequiredId();
	}

	const uuid_ptr_t CFSecAuthorization::getSecSessionId() const {
		return( secSessionId );
	}

	void CFSecAuthorization::setSecSessionId( const uuid_ptr_t sessionId ) {
		uuid_copy( secSessionId, sessionId );
	}

	void CFSecAuthorization::setSecSession( cfsec::ICFSecSecSessionObj* value ) {
		if( value == NULL ) {
			for( int i = 0; i < 16; i++ ) {
				secSessionId[i] = 0;
			}
			return;
		}
		else {
			uuid_copy( secSessionId, value->getRequiredSecSessionId() );
		}
	}

	const uuid_ptr_t CFSecAuthorization::getSecUserId() const {
		return( secUserId );
	}

	void CFSecAuthorization::setSecUserId( const uuid_ptr_t userId ) {
		uuid_copy( secUserId, userId );
	}

}
