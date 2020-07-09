#pragma once

// Description: C++18 specification of a TSecGrpInc primary key object.

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

	class CFSecTSecGrpIncBuff;
	class CFSecTSecGrpIncHPKey;
	class CFSecTSecGrpIncHBuff;

	class CFSecTSecGrpIncPKey
	{
	protected:

		int64_t requiredTenantId;
		int64_t requiredTSecGrpIncId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;

		CFSecTSecGrpIncPKey();
		CFSecTSecGrpIncPKey( const CFSecTSecGrpIncPKey& src );
		virtual ~CFSecTSecGrpIncPKey();

		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const int64_t getRequiredTSecGrpIncId() const;
		virtual const int64_t* getRequiredTSecGrpIncIdReference() const;
		virtual void setRequiredTSecGrpIncId( const int64_t value );

		bool operator <( const CFSecTSecGrpIncHPKey& rhs );
		bool operator <( const CFSecTSecGrpIncPKey& rhs );
		bool operator <( const CFSecTSecGrpIncHBuff& rhs );
		bool operator <( const CFSecTSecGrpIncBuff& rhs );

		bool operator <=( const CFSecTSecGrpIncHPKey& rhs );
		bool operator <=( const CFSecTSecGrpIncPKey& rhs );
		bool operator <=( const CFSecTSecGrpIncHBuff& rhs );
		bool operator <=( const CFSecTSecGrpIncBuff& rhs );

		bool operator ==( const CFSecTSecGrpIncHPKey& rhs );
		bool operator ==( const CFSecTSecGrpIncPKey& rhs );
		bool operator ==( const CFSecTSecGrpIncHBuff& rhs );
		bool operator ==( const CFSecTSecGrpIncBuff& rhs );

		bool operator !=( const CFSecTSecGrpIncHPKey& rhs );
		bool operator !=( const CFSecTSecGrpIncPKey& rhs );
		bool operator !=( const CFSecTSecGrpIncHBuff& rhs );
		bool operator !=( const CFSecTSecGrpIncBuff& rhs );

		bool operator >=( const CFSecTSecGrpIncHPKey& rhs );
		bool operator >=( const CFSecTSecGrpIncPKey& rhs );
		bool operator >=( const CFSecTSecGrpIncHBuff& rhs );
		bool operator >=( const CFSecTSecGrpIncBuff& rhs );

		bool operator >( const CFSecTSecGrpIncHPKey& rhs );
		bool operator >( const CFSecTSecGrpIncPKey& rhs );
		bool operator >( const CFSecTSecGrpIncHBuff& rhs );
		bool operator >( const CFSecTSecGrpIncBuff& rhs );
		virtual size_t hashCode() const;

		virtual std::string toString();

		cfsec::CFSecTSecGrpIncPKey operator =( cfsec::CFSecTSecGrpIncPKey& src );
		cfsec::CFSecTSecGrpIncPKey operator =( cfsec::CFSecTSecGrpIncHPKey& src );
		cfsec::CFSecTSecGrpIncPKey operator =( cfsec::CFSecTSecGrpIncBuff& src );
		cfsec::CFSecTSecGrpIncPKey operator =( cfsec::CFSecTSecGrpIncHBuff& src );
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	bool operator <=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	bool operator ==(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	bool operator !=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	bool operator >=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	bool operator >(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator >(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	template<> struct hash<cfsec::CFSecTSecGrpIncPKey> {
		typedef cfsec::CFSecTSecGrpIncPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

