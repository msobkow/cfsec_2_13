#pragma once

// Description: C++18 specification for a ISOCcy by CcyNmIdx index key object.

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

	class CFSecISOCcyBuff;
	class CFSecISOCcyHBuff;

	class CFSecISOCcyByCcyNmIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		std::string* requiredName;
	public:
		CFSecISOCcyByCcyNmIdxKey();
		CFSecISOCcyByCcyNmIdxKey( const CFSecISOCcyByCcyNmIdxKey& src );
		virtual ~CFSecISOCcyByCcyNmIdxKey();

		virtual const std::string& getRequiredName() const;
		virtual const std::string* getRequiredNameReference() const;
		virtual void setRequiredName( const std::string& value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator <( const CFSecISOCcyHBuff& rhs );
		bool operator <( const CFSecISOCcyBuff& rhs );

		bool operator <=( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator <=( const CFSecISOCcyHBuff& rhs );
		bool operator <=( const CFSecISOCcyBuff& rhs );

		bool operator ==( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator ==( const CFSecISOCcyHBuff& rhs );
		bool operator ==( const CFSecISOCcyBuff& rhs );

		bool operator !=( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator !=( const CFSecISOCcyHBuff& rhs );
		bool operator !=( const CFSecISOCcyBuff& rhs );

		bool operator >=( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator >=( const CFSecISOCcyHBuff& rhs );
		bool operator >=( const CFSecISOCcyBuff& rhs );

		bool operator >( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator >( const CFSecISOCcyHBuff& rhs );
		bool operator >( const CFSecISOCcyBuff& rhs );
		cfsec::CFSecISOCcyByCcyNmIdxKey operator =( cfsec::CFSecISOCcyByCcyNmIdxKey& src );
		cfsec::CFSecISOCcyByCcyNmIdxKey operator =( cfsec::CFSecISOCcyBuff& src );
		cfsec::CFSecISOCcyByCcyNmIdxKey operator =( cfsec::CFSecISOCcyHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator <=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator ==(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator !=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator >=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator >(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );
	bool operator >(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	template<> struct hash<cfsec::CFSecISOCcyByCcyNmIdxKey> {
		typedef cfsec::CFSecISOCcyByCcyNmIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

