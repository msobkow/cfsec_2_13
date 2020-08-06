#pragma once

// Description: C++18 specification of a ISOCtryLang primary key object.

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

