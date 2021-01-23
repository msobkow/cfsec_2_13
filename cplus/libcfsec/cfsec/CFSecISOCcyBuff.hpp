#pragma once

// Description: C++18 specification for a ISOCcy buffer object.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at mark.sobkow@gmail.com for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */
#include <cflib/ICFLibPublic.hpp>

#include <cfsec/ICFSecSchema.hpp>

namespace cfsec {

	class CFSecISOCcyPKey;
	class CFSecISOCcyHPKey;
	class CFSecISOCcyHBuff;
	class CFSecISOCcyByCcyCdIdxKey;
	class CFSecISOCcyByCcyNmIdxKey;

	class CFSecISOCcyBuff : public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string GENDEFNAME;
		static const classcode_t CLASS_CODE;
		static const std::string CLASS_NAME;
		static const std::string COLNAME_ISOCCYID;
		static const std::string COLNAME_ISOCODE;
		static const std::string COLNAME_NAME;
		static const std::string COLNAME_UNITSYMBOL;
		static const std::string COLNAME_PRECIS;
		static const char* S_INIT_CREATEDBY;
		static const char* S_INIT_UPDATEDBY;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
		static const int16_t ISOCCYID_INIT_VALUE;
		static const std::string ISOCODE_INIT_VALUE;
		static const std::string NAME_INIT_VALUE;
		static const int16_t PRECIS_INIT_VALUE;
		static const int16_t ISOCCYID_MIN_VALUE;
		static const int16_t PRECIS_MIN_VALUE;
		static const int16_t PRECIS_MAX_VALUE;
		static const std::string::size_type ISOCODE_MAX_LEN;
		static const std::string::size_type NAME_MAX_LEN;
		static const std::string::size_type UNITSYMBOL_MAX_LEN;
	protected:
		uuid_t createdByUserId;
		std::chrono::system_clock::time_point createdAt;
		uuid_t updatedByUserId;
		std::chrono::system_clock::time_point updatedAt;
		int16_t requiredISOCcyId;
		std::string* requiredISOCode;
		std::string* requiredName;
		std::string* optionalUnitSymbol;
		int16_t requiredPrecis;
		int32_t requiredRevision;
	public:
		CFSecISOCcyBuff();

		CFSecISOCcyBuff( const CFSecISOCcyBuff& src );

		virtual ~CFSecISOCcyBuff();

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
		virtual const int16_t getRequiredISOCcyId() const;
		virtual const int16_t* getRequiredISOCcyIdReference() const;
		virtual void setRequiredISOCcyId( const int16_t value );

		virtual const std::string& getRequiredISOCode() const;
		virtual const std::string* getRequiredISOCodeReference() const;
		virtual void setRequiredISOCode( const std::string& value );

		virtual const std::string& getRequiredName() const;
		virtual const std::string* getRequiredNameReference() const;
		virtual void setRequiredName( const std::string& value );

		virtual const std::string& getOptionalUnitSymbolValue() const;
		virtual const std::string* getOptionalUnitSymbolReference() const;
		virtual const bool isOptionalUnitSymbolNull() const;
		virtual void setOptionalUnitSymbolNull();
		virtual void setOptionalUnitSymbolValue( const std::string& value );

		virtual const int16_t getRequiredPrecis() const;
		virtual const int16_t* getRequiredPrecisReference() const;
		virtual void setRequiredPrecis( const int16_t value );

		virtual int32_t getRequiredRevision() const;
		virtual void setRequiredRevision( int32_t value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecISOCcyByCcyCdIdxKey& rhs );
		bool operator <( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator <( const CFSecISOCcyPKey& rhs );
		bool operator <( const CFSecISOCcyHPKey& rhs );
		bool operator <( const CFSecISOCcyHBuff& rhs );
		bool operator <( const CFSecISOCcyBuff& rhs );

		bool operator <=( const CFSecISOCcyByCcyCdIdxKey& rhs );
		bool operator <=( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator <=( const CFSecISOCcyPKey& rhs );
		bool operator <=( const CFSecISOCcyHPKey& rhs );
		bool operator <=( const CFSecISOCcyHBuff& rhs );
		bool operator <=( const CFSecISOCcyBuff& rhs );

		bool operator ==( const CFSecISOCcyByCcyCdIdxKey& rhs );
		bool operator ==( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator ==( const CFSecISOCcyPKey& rhs );
		bool operator ==( const CFSecISOCcyHPKey& rhs );
		bool operator ==( const CFSecISOCcyHBuff& rhs );
		bool operator ==( const CFSecISOCcyBuff& rhs );

		bool operator !=( const CFSecISOCcyByCcyCdIdxKey& rhs );
		bool operator !=( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator !=( const CFSecISOCcyPKey& rhs );
		bool operator !=( const CFSecISOCcyHPKey& rhs );
		bool operator !=( const CFSecISOCcyHBuff& rhs );
		bool operator !=( const CFSecISOCcyBuff& rhs );

		bool operator >=( const CFSecISOCcyByCcyCdIdxKey& rhs );
		bool operator >=( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator >=( const CFSecISOCcyPKey& rhs );
		bool operator >=( const CFSecISOCcyHPKey& rhs );
		bool operator >=( const CFSecISOCcyHBuff& rhs );
		bool operator >=( const CFSecISOCcyBuff& rhs );

		bool operator >( const CFSecISOCcyByCcyCdIdxKey& rhs );
		bool operator >( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator >( const CFSecISOCcyPKey& rhs );
		bool operator >( const CFSecISOCcyHPKey& rhs );
		bool operator >( const CFSecISOCcyHBuff& rhs );
		bool operator >( const CFSecISOCcyBuff& rhs );
		cfsec::CFSecISOCcyBuff operator =( cfsec::CFSecISOCcyBuff& src );
		cfsec::CFSecISOCcyBuff operator =( cfsec::CFSecISOCcyHBuff& src );

		virtual std::string toString();
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs );
	bool operator <(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs );
	bool operator <(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator <=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator ==(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator !=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator >=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator >(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs );

	bool operator >(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );

	bool operator >(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs );
	bool operator >(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs );
	bool operator >(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	template<> struct hash<cfsec::CFSecISOCcyBuff> {
		typedef cfsec::CFSecISOCcyBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

