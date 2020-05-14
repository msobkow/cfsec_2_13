#pragma once

// Description: C++18 specification of a ISOCtryLang primary key object.

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

	class CFSecISOCtryLangBuff;
	class CFSecISOCtryLangHPKey;
	class CFSecISOCtryLangHBuff;

	class CFSecISOCtryLangPKey
	{
	protected:

		int16_t requiredISOCtryId;
		int16_t requiredISOLangId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;

		CFSecISOCtryLangPKey();
		CFSecISOCtryLangPKey( const CFSecISOCtryLangPKey& src );
		virtual ~CFSecISOCtryLangPKey();

		virtual const int16_t getRequiredISOCtryId() const;
		virtual const int16_t* getRequiredISOCtryIdReference() const;
		virtual void setRequiredISOCtryId( const int16_t value );

		virtual const int16_t getRequiredISOLangId() const;
		virtual const int16_t* getRequiredISOLangIdReference() const;
		virtual void setRequiredISOLangId( const int16_t value );

		bool operator <( const CFSecISOCtryLangHPKey& rhs );
		bool operator <( const CFSecISOCtryLangPKey& rhs );
		bool operator <( const CFSecISOCtryLangHBuff& rhs );
		bool operator <( const CFSecISOCtryLangBuff& rhs );

		bool operator <=( const CFSecISOCtryLangHPKey& rhs );
		bool operator <=( const CFSecISOCtryLangPKey& rhs );
		bool operator <=( const CFSecISOCtryLangHBuff& rhs );
		bool operator <=( const CFSecISOCtryLangBuff& rhs );

		bool operator ==( const CFSecISOCtryLangHPKey& rhs );
		bool operator ==( const CFSecISOCtryLangPKey& rhs );
		bool operator ==( const CFSecISOCtryLangHBuff& rhs );
		bool operator ==( const CFSecISOCtryLangBuff& rhs );

		bool operator !=( const CFSecISOCtryLangHPKey& rhs );
		bool operator !=( const CFSecISOCtryLangPKey& rhs );
		bool operator !=( const CFSecISOCtryLangHBuff& rhs );
		bool operator !=( const CFSecISOCtryLangBuff& rhs );

		bool operator >=( const CFSecISOCtryLangHPKey& rhs );
		bool operator >=( const CFSecISOCtryLangPKey& rhs );
		bool operator >=( const CFSecISOCtryLangHBuff& rhs );
		bool operator >=( const CFSecISOCtryLangBuff& rhs );

		bool operator >( const CFSecISOCtryLangHPKey& rhs );
		bool operator >( const CFSecISOCtryLangPKey& rhs );
		bool operator >( const CFSecISOCtryLangHBuff& rhs );
		bool operator >( const CFSecISOCtryLangBuff& rhs );
		virtual size_t hashCode() const;

		virtual std::string toString();

		cfsec::CFSecISOCtryLangPKey operator =( cfsec::CFSecISOCtryLangPKey& src );
		cfsec::CFSecISOCtryLangPKey operator =( cfsec::CFSecISOCtryLangHPKey& src );
		cfsec::CFSecISOCtryLangPKey operator =( cfsec::CFSecISOCtryLangBuff& src );
		cfsec::CFSecISOCtryLangPKey operator =( cfsec::CFSecISOCtryLangHBuff& src );
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs );
	bool operator <(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangPKey& rhs );
	bool operator <(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs );

	bool operator <=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs );

	bool operator ==(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs );

	bool operator !=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs );

	bool operator >=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs );

	bool operator >(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs );
	bool operator >(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangPKey& rhs );
	bool operator >(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs );

	template<> struct hash<cfsec::CFSecISOCtryLangPKey> {
		typedef cfsec::CFSecISOCtryLangPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

