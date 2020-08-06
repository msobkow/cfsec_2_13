// Description: C++18 CFSec Authorization Implementation

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
