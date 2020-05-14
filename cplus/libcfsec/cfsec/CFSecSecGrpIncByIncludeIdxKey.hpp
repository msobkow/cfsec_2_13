#pragma once

// Description: C++18 specification for a SecGrpInc by IncludeIdx index key object.

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

	class CFSecSecGrpIncBuff;
	class CFSecSecGrpIncHBuff;

	class CFSecSecGrpIncByIncludeIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int64_t requiredClusterId;
		int32_t requiredIncludeGroupId;
	public:
		CFSecSecGrpIncByIncludeIdxKey();
		CFSecSecGrpIncByIncludeIdxKey( const CFSecSecGrpIncByIncludeIdxKey& src );
		virtual ~CFSecSecGrpIncByIncludeIdxKey();

		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const int32_t getRequiredIncludeGroupId() const;
		virtual const int32_t* getRequiredIncludeGroupIdReference() const;
		virtual void setRequiredIncludeGroupId( const int32_t value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecSecGrpIncByIncludeIdxKey& rhs );
		bool operator <( const CFSecSecGrpIncHBuff& rhs );
		bool operator <( const CFSecSecGrpIncBuff& rhs );

		bool operator <=( const CFSecSecGrpIncByIncludeIdxKey& rhs );
		bool operator <=( const CFSecSecGrpIncHBuff& rhs );
		bool operator <=( const CFSecSecGrpIncBuff& rhs );

		bool operator ==( const CFSecSecGrpIncByIncludeIdxKey& rhs );
		bool operator ==( const CFSecSecGrpIncHBuff& rhs );
		bool operator ==( const CFSecSecGrpIncBuff& rhs );

		bool operator !=( const CFSecSecGrpIncByIncludeIdxKey& rhs );
		bool operator !=( const CFSecSecGrpIncHBuff& rhs );
		bool operator !=( const CFSecSecGrpIncBuff& rhs );

		bool operator >=( const CFSecSecGrpIncByIncludeIdxKey& rhs );
		bool operator >=( const CFSecSecGrpIncHBuff& rhs );
		bool operator >=( const CFSecSecGrpIncBuff& rhs );

		bool operator >( const CFSecSecGrpIncByIncludeIdxKey& rhs );
		bool operator >( const CFSecSecGrpIncHBuff& rhs );
		bool operator >( const CFSecSecGrpIncBuff& rhs );
		cfsec::CFSecSecGrpIncByIncludeIdxKey operator =( cfsec::CFSecSecGrpIncByIncludeIdxKey& src );
		cfsec::CFSecSecGrpIncByIncludeIdxKey operator =( cfsec::CFSecSecGrpIncBuff& src );
		cfsec::CFSecSecGrpIncByIncludeIdxKey operator =( cfsec::CFSecSecGrpIncHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	bool operator >(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	template<> struct hash<cfsec::CFSecSecGrpIncByIncludeIdxKey> {
		typedef cfsec::CFSecSecGrpIncByIncludeIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

