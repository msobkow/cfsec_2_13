#pragma once

// Description: C++18 specification for a TSecGrpInc by IncludeIdx index key object.

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

	class CFSecTSecGrpIncBuff;
	class CFSecTSecGrpIncHBuff;

	class CFSecTSecGrpIncByIncludeIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int64_t requiredTenantId;
		int32_t requiredIncludeGroupId;
	public:
		CFSecTSecGrpIncByIncludeIdxKey();
		CFSecTSecGrpIncByIncludeIdxKey( const CFSecTSecGrpIncByIncludeIdxKey& src );
		virtual ~CFSecTSecGrpIncByIncludeIdxKey();

		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const int32_t getRequiredIncludeGroupId() const;
		virtual const int32_t* getRequiredIncludeGroupIdReference() const;
		virtual void setRequiredIncludeGroupId( const int32_t value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecTSecGrpIncByIncludeIdxKey& rhs );
		bool operator <( const CFSecTSecGrpIncHBuff& rhs );
		bool operator <( const CFSecTSecGrpIncBuff& rhs );

		bool operator <=( const CFSecTSecGrpIncByIncludeIdxKey& rhs );
		bool operator <=( const CFSecTSecGrpIncHBuff& rhs );
		bool operator <=( const CFSecTSecGrpIncBuff& rhs );

		bool operator ==( const CFSecTSecGrpIncByIncludeIdxKey& rhs );
		bool operator ==( const CFSecTSecGrpIncHBuff& rhs );
		bool operator ==( const CFSecTSecGrpIncBuff& rhs );

		bool operator !=( const CFSecTSecGrpIncByIncludeIdxKey& rhs );
		bool operator !=( const CFSecTSecGrpIncHBuff& rhs );
		bool operator !=( const CFSecTSecGrpIncBuff& rhs );

		bool operator >=( const CFSecTSecGrpIncByIncludeIdxKey& rhs );
		bool operator >=( const CFSecTSecGrpIncHBuff& rhs );
		bool operator >=( const CFSecTSecGrpIncBuff& rhs );

		bool operator >( const CFSecTSecGrpIncByIncludeIdxKey& rhs );
		bool operator >( const CFSecTSecGrpIncHBuff& rhs );
		bool operator >( const CFSecTSecGrpIncBuff& rhs );
		cfsec::CFSecTSecGrpIncByIncludeIdxKey operator =( cfsec::CFSecTSecGrpIncByIncludeIdxKey& src );
		cfsec::CFSecTSecGrpIncByIncludeIdxKey operator =( cfsec::CFSecTSecGrpIncBuff& src );
		cfsec::CFSecTSecGrpIncByIncludeIdxKey operator =( cfsec::CFSecTSecGrpIncHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncByIncludeIdxKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	bool operator <=(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncByIncludeIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	bool operator ==(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncByIncludeIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	bool operator !=(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncByIncludeIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	bool operator >=(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncByIncludeIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	bool operator >(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncByIncludeIdxKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator >(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	template<> struct hash<cfsec::CFSecTSecGrpIncByIncludeIdxKey> {
		typedef cfsec::CFSecTSecGrpIncByIncludeIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

