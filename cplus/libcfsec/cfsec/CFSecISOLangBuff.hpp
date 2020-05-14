#pragma once

// Description: C++18 specification for a ISOLang buffer object.

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

	class CFSecISOLangPKey;
	class CFSecISOLangHPKey;
	class CFSecISOLangHBuff;
	class CFSecISOLangByCode3IdxKey;
	class CFSecISOLangByCode2IdxKey;

	class CFSecISOLangBuff : public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string GENDEFNAME;
		static const classcode_t CLASS_CODE;
		static const std::string CLASS_NAME;
		static const std::string COLNAME_ISOLANGID;
		static const std::string COLNAME_ISO6392CODE;
		static const std::string COLNAME_ISO6391CODE;
		static const std::string COLNAME_ENGLISHNAME;
		static const char* S_INIT_CREATEDBY;
		static const char* S_INIT_UPDATEDBY;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
		static const int16_t ISOLANGID_INIT_VALUE;
		static const std::string ISO6392CODE_INIT_VALUE;
		static const std::string ISO6391CODE_INIT_VALUE;
		static const std::string ENGLISHNAME_INIT_VALUE;
		static const int16_t ISOLANGID_MIN_VALUE;
		static const std::string::size_type ISO6392CODE_MAX_LEN;
		static const std::string::size_type ISO6391CODE_MAX_LEN;
		static const std::string::size_type ENGLISHNAME_MAX_LEN;
	protected:
		uuid_t createdByUserId;
		std::chrono::system_clock::time_point createdAt;
		uuid_t updatedByUserId;
		std::chrono::system_clock::time_point updatedAt;
		int16_t requiredISOLangId;
		std::string* requiredISO6392Code;
		std::string* optionalISO6391Code;
		std::string* requiredEnglishName;
		int32_t requiredRevision;
	public:
		CFSecISOLangBuff();

		CFSecISOLangBuff( const CFSecISOLangBuff& src );

		virtual ~CFSecISOLangBuff();

		virtual const std::string& getClassName() const;
		virtual cflib::ICFLibCloneableObj* clone();
		virtual const classcode_t getClassCode() const;

		virtual bool implementsClassCode( const classcode_t argClassCode );
		virtual const uuid_ptr_t getCreatedByUserId() const;
		virtual void setCreatedByUserId( const uuid_ptr_t value );
		virtual const std::chrono::system_clock::time_point& getCreatedAt() const;
		virtual void setCreatedAt( const std::chrono::system_clock::time_point& value );
		virtual const uuid_ptr_t getUpdatedByUserId() const;
		virtual void setUpdatedByUserId( const uuid_ptr_t value );
		virtual const std::chrono::system_clock::time_point& getUpdatedAt() const;
		virtual void setUpdatedAt( const std::chrono::system_clock::time_point& value );
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

		virtual int32_t getRequiredRevision() const;
		virtual void setRequiredRevision( int32_t value );

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
		cfsec::CFSecISOLangBuff operator =( cfsec::CFSecISOLangBuff& src );
		cfsec::CFSecISOLangBuff operator =( cfsec::CFSecISOLangHBuff& src );

		virtual std::string toString();
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangPKey& rhs );
	bool operator <(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs );
	bool operator <(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator <=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator ==(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator !=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator >=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangBuff& rhs );

	bool operator >(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs );

	bool operator >(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs );

	bool operator >(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangPKey& rhs );
	bool operator >(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs );
	bool operator >(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangBuff& rhs );

	template<> struct hash<cfsec::CFSecISOLangBuff> {
		typedef cfsec::CFSecISOLangBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

