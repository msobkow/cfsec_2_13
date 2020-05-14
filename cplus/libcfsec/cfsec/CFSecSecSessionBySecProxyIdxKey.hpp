#pragma once

// Description: C++18 specification for a SecSession by SecProxyIdx index key object.

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

	class CFSecSecSessionBuff;
	class CFSecSecSessionHBuff;

	class CFSecSecSessionBySecProxyIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		uuid_t optionalSecProxyId;
	public:
		CFSecSecSessionBySecProxyIdxKey();
		CFSecSecSessionBySecProxyIdxKey( const CFSecSecSessionBySecProxyIdxKey& src );
		virtual ~CFSecSecSessionBySecProxyIdxKey();

		virtual const uuid_ptr_t getOptionalSecProxyIdValue() const;
		virtual const uuid_ptr_t getOptionalSecProxyIdReference() const;
		virtual const bool isOptionalSecProxyIdNull() const;
		virtual void setOptionalSecProxyIdNull();
		virtual void setOptionalSecProxyIdValue( const uuid_ptr_t value );
		virtual void generateOptionalSecProxyId();

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecSecSessionBySecProxyIdxKey& rhs );
		bool operator <( const CFSecSecSessionHBuff& rhs );
		bool operator <( const CFSecSecSessionBuff& rhs );

		bool operator <=( const CFSecSecSessionBySecProxyIdxKey& rhs );
		bool operator <=( const CFSecSecSessionHBuff& rhs );
		bool operator <=( const CFSecSecSessionBuff& rhs );

		bool operator ==( const CFSecSecSessionBySecProxyIdxKey& rhs );
		bool operator ==( const CFSecSecSessionHBuff& rhs );
		bool operator ==( const CFSecSecSessionBuff& rhs );

		bool operator !=( const CFSecSecSessionBySecProxyIdxKey& rhs );
		bool operator !=( const CFSecSecSessionHBuff& rhs );
		bool operator !=( const CFSecSecSessionBuff& rhs );

		bool operator >=( const CFSecSecSessionBySecProxyIdxKey& rhs );
		bool operator >=( const CFSecSecSessionHBuff& rhs );
		bool operator >=( const CFSecSecSessionBuff& rhs );

		bool operator >( const CFSecSecSessionBySecProxyIdxKey& rhs );
		bool operator >( const CFSecSecSessionHBuff& rhs );
		bool operator >( const CFSecSecSessionBuff& rhs );
		cfsec::CFSecSecSessionBySecProxyIdxKey operator =( cfsec::CFSecSecSessionBySecProxyIdxKey& src );
		cfsec::CFSecSecSessionBySecProxyIdxKey operator =( cfsec::CFSecSecSessionBuff& src );
		cfsec::CFSecSecSessionBySecProxyIdxKey operator =( cfsec::CFSecSecSessionHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator >(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	template<> struct hash<cfsec::CFSecSecSessionBySecProxyIdxKey> {
		typedef cfsec::CFSecSecSessionBySecProxyIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

