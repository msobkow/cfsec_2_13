#pragma once

// Description: C++18 specification of a ISOLang primary key object.

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
	class CFSecISOLangHPKey;
	class CFSecISOLangHBuff;

	class CFSecISOLangPKey
	{
	protected:

		int16_t requiredISOLangId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;

		CFSecISOLangPKey();
		CFSecISOLangPKey( const CFSecISOLangPKey& src );
		virtual ~CFSecISOLangPKey();

		virtual const int16_t getRequiredISOLangId() const;
		virtual const int16_t* getRequiredISOLangIdReference() const;
		virtual void setRequiredISOLangId( const int16_t value );

		bool operator <( const CFSecISOLangHPKey& rhs );
		bool operator <( const CFSecISOLangPKey& rhs );
		bool operator <( const CFSecISOLangHBuff& rhs );
		bool operator <( const CFSecISOLangBuff& rhs );

		bool operator <=( const CFSecISOLangHPKey& rhs );
		bool operator <=( const CFSecISOLangPKey& rhs );
		bool operator <=( const CFSecISOLangHBuff& rhs );
		bool operator <=( const CFSecISOLangBuff& rhs );

		bool operator ==( const CFSecISOLangHPKey& rhs );
		bool operator ==( const CFSecISOLangPKey& rhs );
		bool operator ==( const CFSecISOLangHBuff& rhs );
		bool operator ==( const CFSecISOLangBuff& rhs );

		bool operator !=( const CFSecISOLangHPKey& rhs );
		bool operator !=( const CFSecISOLangPKey& rhs );
		bool operator !=( const CFSecISOLangHBuff& rhs );
		bool operator !=( const CFSecISOLangBuff& rhs );

		bool operator >=( const CFSecISOLangHPKey& rhs );
		bool operator >=( const CFSecISOLangPKey& rhs );
		bool operator >=( const CFSecISOLangHBuff& rhs );
		bool operator >=( const CFSecISOLangBuff& rhs );

		bool operator >( const CFSecISOLangHPKey& rhs );
		bool operator >( const CFSecISOLangPKey& rhs );
		bool operator >( const CFSecISOLangHBuff& rhs );
		bool operator >( const CFSecISOLangBuff& rhs );
		virtual size_t hashCode() const;

		virtual std::string toString();

		cfsec::CFSecISOLangPKey operator =( cfsec::CFSecISOLangPKey& src );
		cfsec::CFSecISOLangPKey operator =( cfsec::CFSecISOLangHPKey& src );
		cfsec::CFSecISOLangPKey operator =( cfsec::CFSecISOLangBuff& src );
		cfsec::CFSecISOLangPKey operator =( cfsec::CFSecISOLangHBuff& src );
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHPKey& rhs );
	bool operator <(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangPKey& rhs );
	bool operator <(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator <=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator ==(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator !=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator >=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator >(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHPKey& rhs );
	bool operator >(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangPKey& rhs );
	bool operator >(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangBuff& rhs );

	template<> struct hash<cfsec::CFSecISOLangPKey> {
		typedef cfsec::CFSecISOLangPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

