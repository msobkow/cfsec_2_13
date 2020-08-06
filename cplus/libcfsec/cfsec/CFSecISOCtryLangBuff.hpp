#pragma once

// Description: C++18 specification for a ISOCtryLang buffer object.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
 *	
 *		This file is part of MSS Code Factory.
 *	
 *		MSS Code Factory is available under dual commercial license from Mark Stephen
 *		Sobkow, or under the terms of the GNU General Public License, Version 3
 *		or later.
 *	
 *	    MSS Code Factory is free software: you can redistribute it and/or modify
 *	    it under the terms of the GNU General Public License as published by
 *	    the Free Software Foundation, either version 3 of the License, or
 *	    (at your option) any later version.
 *	
 *	    MSS Code Factory is distributed in the hope that it will be useful,
 *	    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	    GNU General Public License for more details.
 *	
 *	    You should have received a copy of the GNU General Public License
 *	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
 *	
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */
#include <cflib/ICFLibPublic.hpp>

#include <cfsec/ICFSecSchema.hpp>

namespace cfsec {

	class CFSecISOCtryLangPKey;
	class CFSecISOCtryLangHPKey;
	class CFSecISOCtryLangHBuff;
	class CFSecISOCtryLangByCtryIdxKey;
	class CFSecISOCtryLangByLangIdxKey;

	class CFSecISOCtryLangBuff : public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string GENDEFNAME;
		static const classcode_t CLASS_CODE;
		static const std::string CLASS_NAME;
		static const std::string COLNAME_ISOCTRYID;
		static const std::string COLNAME_ISOLANGID;
		static const char* S_INIT_CREATEDBY;
		static const char* S_INIT_UPDATEDBY;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
		static const int16_t ISOCTRYID_INIT_VALUE;
		static const int16_t ISOLANGID_INIT_VALUE;
		static const int16_t ISOCTRYID_MIN_VALUE;
		static const int16_t ISOLANGID_MIN_VALUE;
	protected:
		uuid_t createdByUserId;
		std::chrono::system_clock::time_point createdAt;
		uuid_t updatedByUserId;
		std::chrono::system_clock::time_point updatedAt;
		int16_t requiredISOCtryId;
		int16_t requiredISOLangId;
		int32_t requiredRevision;
	public:
		CFSecISOCtryLangBuff();

		CFSecISOCtryLangBuff( const CFSecISOCtryLangBuff& src );

		virtual ~CFSecISOCtryLangBuff();

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
		virtual const int16_t getRequiredISOCtryId() const;
		virtual const int16_t* getRequiredISOCtryIdReference() const;
		virtual void setRequiredISOCtryId( const int16_t value );

		virtual const int16_t getRequiredISOLangId() const;
		virtual const int16_t* getRequiredISOLangIdReference() const;
		virtual void setRequiredISOLangId( const int16_t value );

		virtual int32_t getRequiredRevision() const;
		virtual void setRequiredRevision( int32_t value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecISOCtryLangByCtryIdxKey& rhs );
		bool operator <( const CFSecISOCtryLangByLangIdxKey& rhs );
		bool operator <( const CFSecISOCtryLangPKey& rhs );
		bool operator <( const CFSecISOCtryLangHPKey& rhs );
		bool operator <( const CFSecISOCtryLangHBuff& rhs );
		bool operator <( const CFSecISOCtryLangBuff& rhs );

		bool operator <=( const CFSecISOCtryLangByCtryIdxKey& rhs );
		bool operator <=( const CFSecISOCtryLangByLangIdxKey& rhs );
		bool operator <=( const CFSecISOCtryLangPKey& rhs );
		bool operator <=( const CFSecISOCtryLangHPKey& rhs );
		bool operator <=( const CFSecISOCtryLangHBuff& rhs );
		bool operator <=( const CFSecISOCtryLangBuff& rhs );

		bool operator ==( const CFSecISOCtryLangByCtryIdxKey& rhs );
		bool operator ==( const CFSecISOCtryLangByLangIdxKey& rhs );
		bool operator ==( const CFSecISOCtryLangPKey& rhs );
		bool operator ==( const CFSecISOCtryLangHPKey& rhs );
		bool operator ==( const CFSecISOCtryLangHBuff& rhs );
		bool operator ==( const CFSecISOCtryLangBuff& rhs );

		bool operator !=( const CFSecISOCtryLangByCtryIdxKey& rhs );
		bool operator !=( const CFSecISOCtryLangByLangIdxKey& rhs );
		bool operator !=( const CFSecISOCtryLangPKey& rhs );
		bool operator !=( const CFSecISOCtryLangHPKey& rhs );
		bool operator !=( const CFSecISOCtryLangHBuff& rhs );
		bool operator !=( const CFSecISOCtryLangBuff& rhs );

		bool operator >=( const CFSecISOCtryLangByCtryIdxKey& rhs );
		bool operator >=( const CFSecISOCtryLangByLangIdxKey& rhs );
		bool operator >=( const CFSecISOCtryLangPKey& rhs );
		bool operator >=( const CFSecISOCtryLangHPKey& rhs );
		bool operator >=( const CFSecISOCtryLangHBuff& rhs );
		bool operator >=( const CFSecISOCtryLangBuff& rhs );

		bool operator >( const CFSecISOCtryLangByCtryIdxKey& rhs );
		bool operator >( const CFSecISOCtryLangByLangIdxKey& rhs );
		bool operator >( const CFSecISOCtryLangPKey& rhs );
		bool operator >( const CFSecISOCtryLangHPKey& rhs );
		bool operator >( const CFSecISOCtryLangHBuff& rhs );
		bool operator >( const CFSecISOCtryLangBuff& rhs );
		cfsec::CFSecISOCtryLangBuff operator =( cfsec::CFSecISOCtryLangBuff& src );
		cfsec::CFSecISOCtryLangBuff operator =( cfsec::CFSecISOCtryLangHBuff& src );

		virtual std::string toString();
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByCtryIdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByLangIdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangPKey& rhs );
	bool operator <(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs );
	bool operator <(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangBuff& rhs );

	bool operator <=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByCtryIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByLangIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangBuff& rhs );

	bool operator ==(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByCtryIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByLangIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangBuff& rhs );

	bool operator !=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByCtryIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByLangIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangBuff& rhs );

	bool operator >=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByCtryIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByLangIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangBuff& rhs );

	bool operator >(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByCtryIdxKey& rhs );

	bool operator >(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByLangIdxKey& rhs );

	bool operator >(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangPKey& rhs );
	bool operator >(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs );
	bool operator >(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangBuff& rhs );

	template<> struct hash<cfsec::CFSecISOCtryLangBuff> {
		typedef cfsec::CFSecISOCtryLangBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

