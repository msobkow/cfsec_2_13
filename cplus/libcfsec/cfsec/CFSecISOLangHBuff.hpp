#pragma once

// Description: C++18 specification of a ISOLang history buffer object.

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

#include <cfsec/CFSecHPKey.hpp>

#include <cfsec/ICFSecSchema.hpp>
namespace cfsec {

	class CFSecISOLangBuff;
	class CFSecISOLangPKey;
	class CFSecISOLangHPKey;
	class CFSecISOLangByCode3IdxKey;
	class CFSecISOLangByCode2IdxKey;

	class CFSecISOLangHBuff : public CFSecHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int16_t requiredISOLangId;
		std::string* requiredISO6392Code;
		std::string* optionalISO6391Code;
		std::string* requiredEnglishName;		classcode_t classCode;

	public:
		CFSecISOLangHBuff();
		CFSecISOLangHBuff( const CFSecISOLangHBuff& src );
		virtual ~CFSecISOLangHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const int16_t getRequiredISOLangId() const;
		virtual const int16_t* getRequiredISOLangIdReference() const;
		virtual void setRequiredISOLangId( const int16_t value );

		virtual const std::string& getRequiredISO6392Code() const;
		virtual const std::string* getRequiredISO6392CodeReference() const;
		virtual void setRequiredISO6392Code( const std::string& value );

		virtual const std::string& getOptionalISO6391CodeValue() const;
		virtual const std::string* getOptionalISO6391CodeReference() const;
		virtual const bool isOptionalISO6391CodeNull() const;
		virtual void setOptionalISO6391CodeNull();
		virtual void setOptionalISO6391CodeValue( const std::string& value );

		virtual const std::string& getRequiredEnglishName() const;
		virtual const std::string* getRequiredEnglishNameReference() const;
		virtual void setRequiredEnglishName( const std::string& value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecISOLangByCode3IdxKey& rhs );
		bool operator <( const CFSecISOLangByCode2IdxKey& rhs );
		bool operator <( const CFSecISOLangPKey& rhs );
		bool operator <( const CFSecISOLangHPKey& rhs );
		bool operator <( const CFSecISOLangHBuff& rhs );
		bool operator <( const CFSecISOLangBuff& rhs );

		bool operator <=( const CFSecISOLangByCode3IdxKey& rhs );
		bool operator <=( const CFSecISOLangByCode2IdxKey& rhs );
		bool operator <=( const CFSecISOLangPKey& rhs );
		bool operator <=( const CFSecISOLangHPKey& rhs );
		bool operator <=( const CFSecISOLangHBuff& rhs );
		bool operator <=( const CFSecISOLangBuff& rhs );

		bool operator ==( const CFSecISOLangByCode3IdxKey& rhs );
		bool operator ==( const CFSecISOLangByCode2IdxKey& rhs );
		bool operator ==( const CFSecISOLangPKey& rhs );
		bool operator ==( const CFSecISOLangHPKey& rhs );
		bool operator ==( const CFSecISOLangHBuff& rhs );
		bool operator ==( const CFSecISOLangBuff& rhs );

		bool operator !=( const CFSecISOLangByCode3IdxKey& rhs );
		bool operator !=( const CFSecISOLangByCode2IdxKey& rhs );
		bool operator !=( const CFSecISOLangPKey& rhs );
		bool operator !=( const CFSecISOLangHPKey& rhs );
		bool operator !=( const CFSecISOLangHBuff& rhs );
		bool operator !=( const CFSecISOLangBuff& rhs );

		bool operator >=( const CFSecISOLangByCode3IdxKey& rhs );
		bool operator >=( const CFSecISOLangByCode2IdxKey& rhs );
		bool operator >=( const CFSecISOLangPKey& rhs );
		bool operator >=( const CFSecISOLangHPKey& rhs );
		bool operator >=( const CFSecISOLangHBuff& rhs );
		bool operator >=( const CFSecISOLangBuff& rhs );

		bool operator >( const CFSecISOLangByCode3IdxKey& rhs );
		bool operator >( const CFSecISOLangByCode2IdxKey& rhs );
		bool operator >( const CFSecISOLangPKey& rhs );
		bool operator >( const CFSecISOLangHPKey& rhs );
		bool operator >( const CFSecISOLangHBuff& rhs );
		bool operator >( const CFSecISOLangBuff& rhs );
		cfsec::CFSecISOLangHBuff operator =( cfsec::CFSecISOLangBuff& src );
		cfsec::CFSecISOLangHBuff operator =( cfsec::CFSecISOLangHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangPKey& rhs );
	bool operator <(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs );
	bool operator <(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator <=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator ==(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator !=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator >=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator >(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs );
	bool operator >(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs );
	bool operator >(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangPKey& rhs );
	bool operator >(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs );
	bool operator >(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangBuff& rhs );

	template<> struct hash<cfsec::CFSecISOLangHBuff> {
		typedef cfsec::CFSecISOLangHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

