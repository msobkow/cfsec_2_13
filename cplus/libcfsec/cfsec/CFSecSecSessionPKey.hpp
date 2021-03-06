#pragma once

// Description: C++18 specification of a SecSession primary key object.

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

	class CFSecSecSessionBuff;
	class CFSecSecSessionHPKey;
	class CFSecSecSessionHBuff;

	class CFSecSecSessionPKey
	{
	protected:

		uuid_t requiredSecSessionId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;

		CFSecSecSessionPKey();
		CFSecSecSessionPKey( const CFSecSecSessionPKey& src );
		virtual ~CFSecSecSessionPKey();

		virtual const uuid_ptr_t getRequiredSecSessionId() const;
		virtual const uuid_ptr_t getRequiredSecSessionIdReference() const;
		virtual void setRequiredSecSessionId( const uuid_ptr_t value );
		virtual void generateRequiredSecSessionId();

		bool operator <( const CFSecSecSessionHPKey& rhs );
		bool operator <( const CFSecSecSessionPKey& rhs );
		bool operator <( const CFSecSecSessionHBuff& rhs );
		bool operator <( const CFSecSecSessionBuff& rhs );

		bool operator <=( const CFSecSecSessionHPKey& rhs );
		bool operator <=( const CFSecSecSessionPKey& rhs );
		bool operator <=( const CFSecSecSessionHBuff& rhs );
		bool operator <=( const CFSecSecSessionBuff& rhs );

		bool operator ==( const CFSecSecSessionHPKey& rhs );
		bool operator ==( const CFSecSecSessionPKey& rhs );
		bool operator ==( const CFSecSecSessionHBuff& rhs );
		bool operator ==( const CFSecSecSessionBuff& rhs );

		bool operator !=( const CFSecSecSessionHPKey& rhs );
		bool operator !=( const CFSecSecSessionPKey& rhs );
		bool operator !=( const CFSecSecSessionHBuff& rhs );
		bool operator !=( const CFSecSecSessionBuff& rhs );

		bool operator >=( const CFSecSecSessionHPKey& rhs );
		bool operator >=( const CFSecSecSessionPKey& rhs );
		bool operator >=( const CFSecSecSessionHBuff& rhs );
		bool operator >=( const CFSecSecSessionBuff& rhs );

		bool operator >( const CFSecSecSessionHPKey& rhs );
		bool operator >( const CFSecSecSessionPKey& rhs );
		bool operator >( const CFSecSecSessionHBuff& rhs );
		bool operator >( const CFSecSecSessionBuff& rhs );
		virtual size_t hashCode() const;

		virtual std::string toString();

		cfsec::CFSecSecSessionPKey operator =( cfsec::CFSecSecSessionPKey& src );
		cfsec::CFSecSecSessionPKey operator =( cfsec::CFSecSecSessionHPKey& src );
		cfsec::CFSecSecSessionPKey operator =( cfsec::CFSecSecSessionBuff& src );
		cfsec::CFSecSecSessionPKey operator =( cfsec::CFSecSecSessionHBuff& src );
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionHPKey& rhs );
	bool operator <(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionPKey& rhs );
	bool operator <(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	bool operator >(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionHPKey& rhs );
	bool operator >(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionPKey& rhs );
	bool operator >(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecSessionPKey& lhs, const cfsec::CFSecSecSessionBuff& rhs );

	template<> struct hash<cfsec::CFSecSecSessionPKey> {
		typedef cfsec::CFSecSecSessionPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

