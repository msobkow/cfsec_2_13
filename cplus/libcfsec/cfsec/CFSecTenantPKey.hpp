#pragma once

// Description: C++18 specification of a Tenant primary key object.

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
#include <cfsec/ICFSecSchema.hpp>

namespace cfsec {

	class CFSecTenantBuff;
	class CFSecTenantHPKey;
	class CFSecTenantHBuff;

	class CFSecTenantPKey
	{
	protected:

		int64_t requiredId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;

		CFSecTenantPKey();
		CFSecTenantPKey( const CFSecTenantPKey& src );
		virtual ~CFSecTenantPKey();

		virtual const int64_t getRequiredId() const;
		virtual const int64_t* getRequiredIdReference() const;
		virtual void setRequiredId( const int64_t value );

		bool operator <( const CFSecTenantHPKey& rhs );
		bool operator <( const CFSecTenantPKey& rhs );
		bool operator <( const CFSecTenantHBuff& rhs );
		bool operator <( const CFSecTenantBuff& rhs );

		bool operator <=( const CFSecTenantHPKey& rhs );
		bool operator <=( const CFSecTenantPKey& rhs );
		bool operator <=( const CFSecTenantHBuff& rhs );
		bool operator <=( const CFSecTenantBuff& rhs );

		bool operator ==( const CFSecTenantHPKey& rhs );
		bool operator ==( const CFSecTenantPKey& rhs );
		bool operator ==( const CFSecTenantHBuff& rhs );
		bool operator ==( const CFSecTenantBuff& rhs );

		bool operator !=( const CFSecTenantHPKey& rhs );
		bool operator !=( const CFSecTenantPKey& rhs );
		bool operator !=( const CFSecTenantHBuff& rhs );
		bool operator !=( const CFSecTenantBuff& rhs );

		bool operator >=( const CFSecTenantHPKey& rhs );
		bool operator >=( const CFSecTenantPKey& rhs );
		bool operator >=( const CFSecTenantHBuff& rhs );
		bool operator >=( const CFSecTenantBuff& rhs );

		bool operator >( const CFSecTenantHPKey& rhs );
		bool operator >( const CFSecTenantPKey& rhs );
		bool operator >( const CFSecTenantHBuff& rhs );
		bool operator >( const CFSecTenantBuff& rhs );
		virtual size_t hashCode() const;

		virtual std::string toString();

		cfsec::CFSecTenantPKey operator =( cfsec::CFSecTenantPKey& src );
		cfsec::CFSecTenantPKey operator =( cfsec::CFSecTenantHPKey& src );
		cfsec::CFSecTenantPKey operator =( cfsec::CFSecTenantBuff& src );
		cfsec::CFSecTenantPKey operator =( cfsec::CFSecTenantHBuff& src );
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantHPKey& rhs );
	bool operator <(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantPKey& rhs );
	bool operator <(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator <(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantBuff& rhs );

	bool operator <=(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantHPKey& rhs );
	bool operator <=(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantPKey& rhs );
	bool operator <=(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator <=(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantBuff& rhs );

	bool operator ==(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantHPKey& rhs );
	bool operator ==(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantPKey& rhs );
	bool operator ==(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator ==(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantBuff& rhs );

	bool operator !=(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantHPKey& rhs );
	bool operator !=(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantPKey& rhs );
	bool operator !=(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator !=(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantBuff& rhs );

	bool operator >=(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantHPKey& rhs );
	bool operator >=(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantPKey& rhs );
	bool operator >=(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator >=(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantBuff& rhs );

	bool operator >(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantHPKey& rhs );
	bool operator >(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantPKey& rhs );
	bool operator >(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator >(const  cfsec::CFSecTenantPKey& lhs, const cfsec::CFSecTenantBuff& rhs );

	template<> struct hash<cfsec::CFSecTenantPKey> {
		typedef cfsec::CFSecTenantPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

