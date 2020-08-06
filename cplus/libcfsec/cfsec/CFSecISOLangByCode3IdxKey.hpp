#pragma once

// Description: C++18 specification for a ISOLang by Code3Idx index key object.

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

