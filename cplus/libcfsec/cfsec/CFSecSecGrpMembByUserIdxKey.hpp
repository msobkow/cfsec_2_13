#pragma once

// Description: C++18 specification for a SecGrpMemb by UserIdx index key object.

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

	class CFSecSecGrpMembBuff;
	class CFSecSecGrpMembHBuff;

	class CFSecSecGrpMembByUserIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		uuid_t requiredSecUserId;
	public:
		CFSecSecGrpMembByUserIdxKey();
		CFSecSecGrpMembByUserIdxKey( const CFSecSecGrpMembByUserIdxKey& src );
		virtual ~CFSecSecGrpMembByUserIdxKey();

		virtual const uuid_ptr_t getRequiredSecUserId() const;
		virtual const uuid_ptr_t getRequiredSecUserIdReference() const;
		virtual void setRequiredSecUserId( const uuid_ptr_t value );
		virtual void generateRequiredSecUserId();

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecSecGrpMembByUserIdxKey& rhs );
		bool operator <( const CFSecSecGrpMembHBuff& rhs );
		bool operator <( const CFSecSecGrpMembBuff& rhs );

		bool operator <=( const CFSecSecGrpMembByUserIdxKey& rhs );
		bool operator <=( const CFSecSecGrpMembHBuff& rhs );
		bool operator <=( const CFSecSecGrpMembBuff& rhs );

		bool operator ==( const CFSecSecGrpMembByUserIdxKey& rhs );
		bool operator ==( const CFSecSecGrpMembHBuff& rhs );
		bool operator ==( const CFSecSecGrpMembBuff& rhs );

		bool operator !=( const CFSecSecGrpMembByUserIdxKey& rhs );
		bool operator !=( const CFSecSecGrpMembHBuff& rhs );
		bool operator !=( const CFSecSecGrpMembBuff& rhs );

		bool operator >=( const CFSecSecGrpMembByUserIdxKey& rhs );
		bool operator >=( const CFSecSecGrpMembHBuff& rhs );
		bool operator >=( const CFSecSecGrpMembBuff& rhs );

		bool operator >( const CFSecSecGrpMembByUserIdxKey& rhs );
		bool operator >( const CFSecSecGrpMembHBuff& rhs );
		bool operator >( const CFSecSecGrpMembBuff& rhs );
		cfsec::CFSecSecGrpMembByUserIdxKey operator =( cfsec::CFSecSecGrpMembByUserIdxKey& src );
		cfsec::CFSecSecGrpMembByUserIdxKey operator =( cfsec::CFSecSecGrpMembBuff& src );
		cfsec::CFSecSecGrpMembByUserIdxKey operator =( cfsec::CFSecSecGrpMembHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecSecGrpMembByUserIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecSecGrpMembByUserIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecSecGrpMembByUserIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecSecGrpMembByUserIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecSecGrpMembByUserIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	bool operator >(const  cfsec::CFSecSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecSecGrpMembByUserIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	template<> struct hash<cfsec::CFSecSecGrpMembByUserIdxKey> {
		typedef cfsec::CFSecSecGrpMembByUserIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

