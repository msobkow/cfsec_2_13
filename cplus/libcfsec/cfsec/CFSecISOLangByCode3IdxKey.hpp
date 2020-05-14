#pragma once

// Description: C++18 specification for a ISOLang by Code3Idx index key object.

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

	class CFSecISOLangBuff;
	class CFSecISOLangHBuff;

	class CFSecISOLangByCode3IdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		std::string* requiredISO6392Code;
	public:
		CFSecISOLangByCode3IdxKey();
		CFSecISOLangByCode3IdxKey( const CFSecISOLangByCode3IdxKey& src );
		virtual ~CFSecISOLangByCode3IdxKey();

		virtual const std::string& getRequiredISO6392Code() const;
		virtual const std::string* getRequiredISO6392CodeReference() const;
		virtual void setRequiredISO6392Code( const std::string& value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecISOLangByCode3IdxKey& rhs );
		bool operator <( const CFSecISOLangHBuff& rhs );
		bool operator <( const CFSecISOLangBuff& rhs );

		bool operator <=( const CFSecISOLangByCode3IdxKey& rhs );
		bool operator <=( const CFSecISOLangHBuff& rhs );
		bool operator <=( const CFSecISOLangBuff& rhs );

		bool operator ==( const CFSecISOLangByCode3IdxKey& rhs );
		bool operator ==( const CFSecISOLangHBuff& rhs );
		bool operator ==( const CFSecISOLangBuff& rhs );

		bool operator !=( const CFSecISOLangByCode3IdxKey& rhs );
		bool operator !=( const CFSecISOLangHBuff& rhs );
		bool operator !=( const CFSecISOLangBuff& rhs );

		bool operator >=( const CFSecISOLangByCode3IdxKey& rhs );
		bool operator >=( const CFSecISOLangHBuff& rhs );
		bool operator >=( const CFSecISOLangBuff& rhs );

		bool operator >( const CFSecISOLangByCode3IdxKey& rhs );
		bool operator >( const CFSecISOLangHBuff& rhs );
		bool operator >( const CFSecISOLangBuff& rhs );
		cfsec::CFSecISOLangByCode3IdxKey operator =( cfsec::CFSecISOLangByCode3IdxKey& src );
		cfsec::CFSecISOLangByCode3IdxKey operator =( cfsec::CFSecISOLangBuff& src );
		cfsec::CFSecISOLangByCode3IdxKey operator =( cfsec::CFSecISOLangHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator <=(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator ==(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator !=(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator >=(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator >(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs );
	bool operator >(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs );

	template<> struct hash<cfsec::CFSecISOLangByCode3IdxKey> {
		typedef cfsec::CFSecISOLangByCode3IdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

