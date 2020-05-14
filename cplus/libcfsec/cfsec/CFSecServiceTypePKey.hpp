#pragma once

// Description: C++18 specification of a ServiceType primary key object.

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

	class CFSecServiceTypeBuff;
	class CFSecServiceTypeHPKey;
	class CFSecServiceTypeHBuff;

	class CFSecServiceTypePKey
	{
	protected:

		int32_t requiredServiceTypeId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;

		CFSecServiceTypePKey();
		CFSecServiceTypePKey( const CFSecServiceTypePKey& src );
		virtual ~CFSecServiceTypePKey();

		virtual const int32_t getRequiredServiceTypeId() const;
		virtual const int32_t* getRequiredServiceTypeIdReference() const;
		virtual void setRequiredServiceTypeId( const int32_t value );

		bool operator <( const CFSecServiceTypeHPKey& rhs );
		bool operator <( const CFSecServiceTypePKey& rhs );
		bool operator <( const CFSecServiceTypeHBuff& rhs );
		bool operator <( const CFSecServiceTypeBuff& rhs );

		bool operator <=( const CFSecServiceTypeHPKey& rhs );
		bool operator <=( const CFSecServiceTypePKey& rhs );
		bool operator <=( const CFSecServiceTypeHBuff& rhs );
		bool operator <=( const CFSecServiceTypeBuff& rhs );

		bool operator ==( const CFSecServiceTypeHPKey& rhs );
		bool operator ==( const CFSecServiceTypePKey& rhs );
		bool operator ==( const CFSecServiceTypeHBuff& rhs );
		bool operator ==( const CFSecServiceTypeBuff& rhs );

		bool operator !=( const CFSecServiceTypeHPKey& rhs );
		bool operator !=( const CFSecServiceTypePKey& rhs );
		bool operator !=( const CFSecServiceTypeHBuff& rhs );
		bool operator !=( const CFSecServiceTypeBuff& rhs );

		bool operator >=( const CFSecServiceTypeHPKey& rhs );
		bool operator >=( const CFSecServiceTypePKey& rhs );
		bool operator >=( const CFSecServiceTypeHBuff& rhs );
		bool operator >=( const CFSecServiceTypeBuff& rhs );

		bool operator >( const CFSecServiceTypeHPKey& rhs );
		bool operator >( const CFSecServiceTypePKey& rhs );
		bool operator >( const CFSecServiceTypeHBuff& rhs );
		bool operator >( const CFSecServiceTypeBuff& rhs );
		virtual size_t hashCode() const;

		virtual std::string toString();

		cfsec::CFSecServiceTypePKey operator =( cfsec::CFSecServiceTypePKey& src );
		cfsec::CFSecServiceTypePKey operator =( cfsec::CFSecServiceTypeHPKey& src );
		cfsec::CFSecServiceTypePKey operator =( cfsec::CFSecServiceTypeBuff& src );
		cfsec::CFSecServiceTypePKey operator =( cfsec::CFSecServiceTypeHBuff& src );
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHPKey& rhs );
	bool operator <(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypePKey& rhs );
	bool operator <(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator <(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs );

	bool operator <=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHPKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypePKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator <=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs );

	bool operator ==(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHPKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypePKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator ==(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs );

	bool operator !=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHPKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypePKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator !=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs );

	bool operator >=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHPKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypePKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator >=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs );

	bool operator >(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHPKey& rhs );
	bool operator >(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypePKey& rhs );
	bool operator >(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator >(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs );

	template<> struct hash<cfsec::CFSecServiceTypePKey> {
		typedef cfsec::CFSecServiceTypePKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

