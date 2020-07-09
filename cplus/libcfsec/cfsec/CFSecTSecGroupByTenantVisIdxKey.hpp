#pragma once

// Description: C++18 specification for a TSecGroup by TenantVisIdx index key object.

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

	class CFSecTSecGroupBuff;
	class CFSecTSecGroupHBuff;

	class CFSecTSecGroupByTenantVisIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int64_t requiredTenantId;
		bool requiredIsVisible;
	public:
		CFSecTSecGroupByTenantVisIdxKey();
		CFSecTSecGroupByTenantVisIdxKey( const CFSecTSecGroupByTenantVisIdxKey& src );
		virtual ~CFSecTSecGroupByTenantVisIdxKey();

		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const bool getRequiredIsVisible() const;
		virtual const bool* getRequiredIsVisibleReference() const;
		virtual void setRequiredIsVisible( const bool value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecTSecGroupByTenantVisIdxKey& rhs );
		bool operator <( const CFSecTSecGroupHBuff& rhs );
		bool operator <( const CFSecTSecGroupBuff& rhs );

		bool operator <=( const CFSecTSecGroupByTenantVisIdxKey& rhs );
		bool operator <=( const CFSecTSecGroupHBuff& rhs );
		bool operator <=( const CFSecTSecGroupBuff& rhs );

		bool operator ==( const CFSecTSecGroupByTenantVisIdxKey& rhs );
		bool operator ==( const CFSecTSecGroupHBuff& rhs );
		bool operator ==( const CFSecTSecGroupBuff& rhs );

		bool operator !=( const CFSecTSecGroupByTenantVisIdxKey& rhs );
		bool operator !=( const CFSecTSecGroupHBuff& rhs );
		bool operator !=( const CFSecTSecGroupBuff& rhs );

		bool operator >=( const CFSecTSecGroupByTenantVisIdxKey& rhs );
		bool operator >=( const CFSecTSecGroupHBuff& rhs );
		bool operator >=( const CFSecTSecGroupBuff& rhs );

		bool operator >( const CFSecTSecGroupByTenantVisIdxKey& rhs );
		bool operator >( const CFSecTSecGroupHBuff& rhs );
		bool operator >( const CFSecTSecGroupBuff& rhs );
		cfsec::CFSecTSecGroupByTenantVisIdxKey operator =( cfsec::CFSecTSecGroupByTenantVisIdxKey& src );
		cfsec::CFSecTSecGroupByTenantVisIdxKey operator =( cfsec::CFSecTSecGroupBuff& src );
		cfsec::CFSecTSecGroupByTenantVisIdxKey operator =( cfsec::CFSecTSecGroupHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupByTenantVisIdxKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator <(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	bool operator <=(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupByTenantVisIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator <=(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	bool operator ==(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupByTenantVisIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator ==(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	bool operator !=(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupByTenantVisIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator !=(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	bool operator >=(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupByTenantVisIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator >=(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	bool operator >(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupByTenantVisIdxKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator >(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	template<> struct hash<cfsec::CFSecTSecGroupByTenantVisIdxKey> {
		typedef cfsec::CFSecTSecGroupByTenantVisIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

