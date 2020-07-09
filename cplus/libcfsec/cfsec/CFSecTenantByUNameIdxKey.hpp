#pragma once

// Description: C++18 specification for a Tenant by UNameIdx index key object.

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
#include <cfsec/ICFSecSchema.hpp>

namespace cfsec {

	class CFSecTenantBuff;
	class CFSecTenantHBuff;

	class CFSecTenantByUNameIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int64_t requiredClusterId;
		std::string* requiredTenantName;
	public:
		CFSecTenantByUNameIdxKey();
		CFSecTenantByUNameIdxKey( const CFSecTenantByUNameIdxKey& src );
		virtual ~CFSecTenantByUNameIdxKey();

		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const std::string& getRequiredTenantName() const;
		virtual const std::string* getRequiredTenantNameReference() const;
		virtual void setRequiredTenantName( const std::string& value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecTenantByUNameIdxKey& rhs );
		bool operator <( const CFSecTenantHBuff& rhs );
		bool operator <( const CFSecTenantBuff& rhs );

		bool operator <=( const CFSecTenantByUNameIdxKey& rhs );
		bool operator <=( const CFSecTenantHBuff& rhs );
		bool operator <=( const CFSecTenantBuff& rhs );

		bool operator ==( const CFSecTenantByUNameIdxKey& rhs );
		bool operator ==( const CFSecTenantHBuff& rhs );
		bool operator ==( const CFSecTenantBuff& rhs );

		bool operator !=( const CFSecTenantByUNameIdxKey& rhs );
		bool operator !=( const CFSecTenantHBuff& rhs );
		bool operator !=( const CFSecTenantBuff& rhs );

		bool operator >=( const CFSecTenantByUNameIdxKey& rhs );
		bool operator >=( const CFSecTenantHBuff& rhs );
		bool operator >=( const CFSecTenantBuff& rhs );

		bool operator >( const CFSecTenantByUNameIdxKey& rhs );
		bool operator >( const CFSecTenantHBuff& rhs );
		bool operator >( const CFSecTenantBuff& rhs );
		cfsec::CFSecTenantByUNameIdxKey operator =( cfsec::CFSecTenantByUNameIdxKey& src );
		cfsec::CFSecTenantByUNameIdxKey operator =( cfsec::CFSecTenantBuff& src );
		cfsec::CFSecTenantByUNameIdxKey operator =( cfsec::CFSecTenantHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs );
	bool operator <(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator <(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantBuff& rhs );

	bool operator <=(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator <=(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantBuff& rhs );

	bool operator ==(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator ==(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantBuff& rhs );

	bool operator !=(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator !=(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantBuff& rhs );

	bool operator >=(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator >=(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantBuff& rhs );

	bool operator >(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs );
	bool operator >(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator >(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantBuff& rhs );

	template<> struct hash<cfsec::CFSecTenantByUNameIdxKey> {
		typedef cfsec::CFSecTenantByUNameIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

