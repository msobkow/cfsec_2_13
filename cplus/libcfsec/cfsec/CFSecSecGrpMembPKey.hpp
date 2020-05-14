#pragma once

// Description: C++18 specification of a SecGrpMemb primary key object.

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
	class CFSecSecGrpMembHPKey;
	class CFSecSecGrpMembHBuff;

	class CFSecSecGrpMembPKey
	{
	protected:

		int64_t requiredClusterId;
		int64_t requiredSecGrpMembId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;

		CFSecSecGrpMembPKey();
		CFSecSecGrpMembPKey( const CFSecSecGrpMembPKey& src );
		virtual ~CFSecSecGrpMembPKey();

		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const int64_t getRequiredSecGrpMembId() const;
		virtual const int64_t* getRequiredSecGrpMembIdReference() const;
		virtual void setRequiredSecGrpMembId( const int64_t value );

		bool operator <( const CFSecSecGrpMembHPKey& rhs );
		bool operator <( const CFSecSecGrpMembPKey& rhs );
		bool operator <( const CFSecSecGrpMembHBuff& rhs );
		bool operator <( const CFSecSecGrpMembBuff& rhs );

		bool operator <=( const CFSecSecGrpMembHPKey& rhs );
		bool operator <=( const CFSecSecGrpMembPKey& rhs );
		bool operator <=( const CFSecSecGrpMembHBuff& rhs );
		bool operator <=( const CFSecSecGrpMembBuff& rhs );

		bool operator ==( const CFSecSecGrpMembHPKey& rhs );
		bool operator ==( const CFSecSecGrpMembPKey& rhs );
		bool operator ==( const CFSecSecGrpMembHBuff& rhs );
		bool operator ==( const CFSecSecGrpMembBuff& rhs );

		bool operator !=( const CFSecSecGrpMembHPKey& rhs );
		bool operator !=( const CFSecSecGrpMembPKey& rhs );
		bool operator !=( const CFSecSecGrpMembHBuff& rhs );
		bool operator !=( const CFSecSecGrpMembBuff& rhs );

		bool operator >=( const CFSecSecGrpMembHPKey& rhs );
		bool operator >=( const CFSecSecGrpMembPKey& rhs );
		bool operator >=( const CFSecSecGrpMembHBuff& rhs );
		bool operator >=( const CFSecSecGrpMembBuff& rhs );

		bool operator >( const CFSecSecGrpMembHPKey& rhs );
		bool operator >( const CFSecSecGrpMembPKey& rhs );
		bool operator >( const CFSecSecGrpMembHBuff& rhs );
		bool operator >( const CFSecSecGrpMembBuff& rhs );
		virtual size_t hashCode() const;

		virtual std::string toString();

		cfsec::CFSecSecGrpMembPKey operator =( cfsec::CFSecSecGrpMembPKey& src );
		cfsec::CFSecSecGrpMembPKey operator =( cfsec::CFSecSecGrpMembHPKey& src );
		cfsec::CFSecSecGrpMembPKey operator =( cfsec::CFSecSecGrpMembBuff& src );
		cfsec::CFSecSecGrpMembPKey operator =( cfsec::CFSecSecGrpMembHBuff& src );
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	bool operator >(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator >(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator >(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	template<> struct hash<cfsec::CFSecSecGrpMembPKey> {
		typedef cfsec::CFSecSecGrpMembPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}
