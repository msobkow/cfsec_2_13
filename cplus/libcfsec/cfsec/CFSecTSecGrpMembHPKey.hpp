#pragma once

// Description: C++18 specification of a TSecGrpMemb history primary key object.

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

#include <cfsec/CFSecHPKey.hpp>
#include <cfsec/ICFSecSchema.hpp>

namespace cfsec {

	class CFSecTSecGrpMembPKey;
	class CFSecTSecGrpMembBuff;
	class CFSecTSecGrpMembHBuff;

	class CFSecTSecGrpMembHPKey : public CFSecHPKey
	{
	protected:

		int64_t requiredTenantId;
		int64_t requiredTSecGrpMembId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;

		CFSecTSecGrpMembHPKey();
		CFSecTSecGrpMembHPKey( const CFSecTSecGrpMembHPKey& src );
		virtual ~CFSecTSecGrpMembHPKey();

		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const int64_t getRequiredTSecGrpMembId() const;
		virtual const int64_t* getRequiredTSecGrpMembIdReference() const;
		virtual void setRequiredTSecGrpMembId( const int64_t value );

		virtual size_t hashCode() const;

		virtual std::string toString();

		bool operator <( const CFSecTSecGrpMembPKey& rhs );
		bool operator <( const CFSecTSecGrpMembHPKey& rhs );
		bool operator <( const CFSecTSecGrpMembHBuff& rhs );
		bool operator <( const CFSecTSecGrpMembBuff& rhs );


		bool operator <=( const CFSecTSecGrpMembPKey& rhs );
		bool operator <=( const CFSecTSecGrpMembHPKey& rhs );
		bool operator <=( const CFSecTSecGrpMembHBuff& rhs );
		bool operator <=( const CFSecTSecGrpMembBuff& rhs );


		bool operator ==( const CFSecTSecGrpMembPKey& rhs );
		bool operator ==( const CFSecTSecGrpMembHPKey& rhs );
		bool operator ==( const CFSecTSecGrpMembHBuff& rhs );
		bool operator ==( const CFSecTSecGrpMembBuff& rhs );


		bool operator !=( const CFSecTSecGrpMembPKey& rhs );
		bool operator !=( const CFSecTSecGrpMembHPKey& rhs );
		bool operator !=( const CFSecTSecGrpMembHBuff& rhs );
		bool operator !=( const CFSecTSecGrpMembBuff& rhs );


		bool operator >=( const CFSecTSecGrpMembPKey& rhs );
		bool operator >=( const CFSecTSecGrpMembHPKey& rhs );
		bool operator >=( const CFSecTSecGrpMembHBuff& rhs );
		bool operator >=( const CFSecTSecGrpMembBuff& rhs );


		bool operator >( const CFSecTSecGrpMembPKey& rhs );
		bool operator >( const CFSecTSecGrpMembHPKey& rhs );
		bool operator >( const CFSecTSecGrpMembHBuff& rhs );
		bool operator >( const CFSecTSecGrpMembBuff& rhs );

		cfsec::CFSecTSecGrpMembHPKey operator =( cfsec::CFSecTSecGrpMembPKey& src );
		cfsec::CFSecTSecGrpMembHPKey operator =( cfsec::CFSecTSecGrpMembHPKey& src );
		cfsec::CFSecTSecGrpMembHPKey operator =( cfsec::CFSecTSecGrpMembBuff& src );
		cfsec::CFSecTSecGrpMembHPKey operator =( cfsec::CFSecTSecGrpMembHBuff& src );

	};
}


namespace std {

	bool operator <(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs );


	bool operator <=(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs );


	bool operator ==(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs );


	bool operator !=(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs );


	bool operator >=(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs );


	bool operator >(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs );
	bool operator >(const  cfsec::CFSecTSecGrpMembHPKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs );


	template<> struct hash<cfsec::CFSecTSecGrpMembHPKey> {
		typedef cfsec::CFSecTSecGrpMembHPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

