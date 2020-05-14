#pragma once

// Description: C++18 specification for a TSecGrpMemb by UserIdx index key object.

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

	class CFSecTSecGrpMembBuff;
	class CFSecTSecGrpMembHBuff;

	class CFSecTSecGrpMembByUserIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		uuid_t requiredSecUserId;
	public:
		CFSecTSecGrpMembByUserIdxKey();
		CFSecTSecGrpMembByUserIdxKey( const CFSecTSecGrpMembByUserIdxKey& src );
		virtual ~CFSecTSecGrpMembByUserIdxKey();

		virtual const uuid_ptr_t getRequiredSecUserId() const;
		virtual const uuid_ptr_t getRequiredSecUserIdReference() const;
		virtual void setRequiredSecUserId( const uuid_ptr_t value );
		virtual void generateRequiredSecUserId();

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecTSecGrpMembByUserIdxKey& rhs );
		bool operator <( const CFSecTSecGrpMembHBuff& rhs );
		bool operator <( const CFSecTSecGrpMembBuff& rhs );

		bool operator <=( const CFSecTSecGrpMembByUserIdxKey& rhs );
		bool operator <=( const CFSecTSecGrpMembHBuff& rhs );
		bool operator <=( const CFSecTSecGrpMembBuff& rhs );

		bool operator ==( const CFSecTSecGrpMembByUserIdxKey& rhs );
		bool operator ==( const CFSecTSecGrpMembHBuff& rhs );
		bool operator ==( const CFSecTSecGrpMembBuff& rhs );

		bool operator !=( const CFSecTSecGrpMembByUserIdxKey& rhs );
		bool operator !=( const CFSecTSecGrpMembHBuff& rhs );
		bool operator !=( const CFSecTSecGrpMembBuff& rhs );

		bool operator >=( const CFSecTSecGrpMembByUserIdxKey& rhs );
		bool operator >=( const CFSecTSecGrpMembHBuff& rhs );
		bool operator >=( const CFSecTSecGrpMembBuff& rhs );

		bool operator >( const CFSecTSecGrpMembByUserIdxKey& rhs );
		bool operator >( const CFSecTSecGrpMembHBuff& rhs );
		bool operator >( const CFSecTSecGrpMembBuff& rhs );
		cfsec::CFSecTSecGrpMembByUserIdxKey operator =( cfsec::CFSecTSecGrpMembByUserIdxKey& src );
		cfsec::CFSecTSecGrpMembByUserIdxKey operator =( cfsec::CFSecTSecGrpMembBuff& src );
		cfsec::CFSecTSecGrpMembByUserIdxKey operator =( cfsec::CFSecTSecGrpMembHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs );

	bool operator <=(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs );

	bool operator ==(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs );

	bool operator !=(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs );

	bool operator >=(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs );

	bool operator >(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs );
	bool operator >(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs );

	template<> struct hash<cfsec::CFSecTSecGrpMembByUserIdxKey> {
		typedef cfsec::CFSecTSecGrpMembByUserIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

