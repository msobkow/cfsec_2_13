#pragma once

// Description: C++18 specification for a Service by TypeIdx index key object.

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

	class CFSecServiceBuff;
	class CFSecServiceHBuff;

	class CFSecServiceByTypeIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int32_t requiredServiceTypeId;
	public:
		CFSecServiceByTypeIdxKey();
		CFSecServiceByTypeIdxKey( const CFSecServiceByTypeIdxKey& src );
		virtual ~CFSecServiceByTypeIdxKey();

		virtual const int32_t getRequiredServiceTypeId() const;
		virtual const int32_t* getRequiredServiceTypeIdReference() const;
		virtual void setRequiredServiceTypeId( const int32_t value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecServiceByTypeIdxKey& rhs );
		bool operator <( const CFSecServiceHBuff& rhs );
		bool operator <( const CFSecServiceBuff& rhs );

		bool operator <=( const CFSecServiceByTypeIdxKey& rhs );
		bool operator <=( const CFSecServiceHBuff& rhs );
		bool operator <=( const CFSecServiceBuff& rhs );

		bool operator ==( const CFSecServiceByTypeIdxKey& rhs );
		bool operator ==( const CFSecServiceHBuff& rhs );
		bool operator ==( const CFSecServiceBuff& rhs );

		bool operator !=( const CFSecServiceByTypeIdxKey& rhs );
		bool operator !=( const CFSecServiceHBuff& rhs );
		bool operator !=( const CFSecServiceBuff& rhs );

		bool operator >=( const CFSecServiceByTypeIdxKey& rhs );
		bool operator >=( const CFSecServiceHBuff& rhs );
		bool operator >=( const CFSecServiceBuff& rhs );

		bool operator >( const CFSecServiceByTypeIdxKey& rhs );
		bool operator >( const CFSecServiceHBuff& rhs );
		bool operator >( const CFSecServiceBuff& rhs );
		cfsec::CFSecServiceByTypeIdxKey operator =( cfsec::CFSecServiceByTypeIdxKey& src );
		cfsec::CFSecServiceByTypeIdxKey operator =( cfsec::CFSecServiceBuff& src );
		cfsec::CFSecServiceByTypeIdxKey operator =( cfsec::CFSecServiceHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs );
	bool operator <(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator <(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator <=(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator <=(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator ==(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator ==(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator !=(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator !=(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator >=(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator >=(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator >(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs );
	bool operator >(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator >(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs );

	template<> struct hash<cfsec::CFSecServiceByTypeIdxKey> {
		typedef cfsec::CFSecServiceByTypeIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}
