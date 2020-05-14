#pragma once

// Description: C++18 specification for a ISOLang by Code2Idx index key object.

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

	class CFSecISOLangByCode2IdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		std::string* optionalISO6391Code;
	public:
		CFSecISOLangByCode2IdxKey();
		CFSecISOLangByCode2IdxKey( const CFSecISOLangByCode2IdxKey& src );
		virtual ~CFSecISOLangByCode2IdxKey();

		virtual const std::string& getOptionalISO6391CodeValue() const;
		virtual const std::string* getOptionalISO6391CodeReference() const;
		virtual const bool isOptionalISO6391CodeNull() const;
		virtual void setOptionalISO6391CodeNull();
		virtual void setOptionalISO6391CodeValue( const std::string& value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecISOLangByCode2IdxKey& rhs );
		bool operator <( const CFSecISOLangHBuff& rhs );
		bool operator <( const CFSecISOLangBuff& rhs );

		bool operator <=( const CFSecISOLangByCode2IdxKey& rhs );
		bool operator <=( const CFSecISOLangHBuff& rhs );
		bool operator <=( const CFSecISOLangBuff& rhs );

		bool operator ==( const CFSecISOLangByCode2IdxKey& rhs );
		bool operator ==( const CFSecISOLangHBuff& rhs );
		bool operator ==( const CFSecISOLangBuff& rhs );

		bool operator !=( const CFSecISOLangByCode2IdxKey& rhs );
		bool operator !=( const CFSecISOLangHBuff& rhs );
		bool operator !=( const CFSecISOLangBuff& rhs );

		bool operator >=( const CFSecISOLangByCode2IdxKey& rhs );
		bool operator >=( const CFSecISOLangHBuff& rhs );
		bool operator >=( const CFSecISOLangBuff& rhs );

		bool operator >( const CFSecISOLangByCode2IdxKey& rhs );
		bool operator >( const CFSecISOLangHBuff& rhs );
		bool operator >( const CFSecISOLangBuff& rhs );
		cfsec::CFSecISOLangByCode2IdxKey operator =( cfsec::CFSecISOLangByCode2IdxKey& src );
		cfsec::CFSecISOLangByCode2IdxKey operator =( cfsec::CFSecISOLangBuff& src );
		cfsec::CFSecISOLangByCode2IdxKey operator =( cfsec::CFSecISOLangHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator <=(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator ==(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator !=(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator >=(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator >(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs );
	bool operator >(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs );

	template<> struct hash<cfsec::CFSecISOLangByCode2IdxKey> {
		typedef cfsec::CFSecISOLangByCode2IdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

