#pragma once

// Description: C++18 specification of a Tenant history primary key object.

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

#include <cfsec/CFSecHPKey.hpp>
#include <cfsec/ICFSecSchema.hpp>

namespace cfsec {

	class CFSecTenantPKey;
	class CFSecTenantBuff;
	class CFSecTenantHBuff;

	class CFSecTenantHPKey : public CFSecHPKey
	{
	protected:

		int64_t requiredId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;

		CFSecTenantHPKey();
		CFSecTenantHPKey( const CFSecTenantHPKey& src );
		virtual ~CFSecTenantHPKey();

		virtual const int64_t getRequiredId() const;
		virtual const int64_t* getRequiredIdReference() const;
		virtual void setRequiredId( const int64_t value );

		virtual size_t hashCode() const;

		virtual std::string toString();

		bool operator <( const CFSecTenantPKey& rhs );
		bool operator <( const CFSecTenantHPKey& rhs );
		bool operator <( const CFSecTenantHBuff& rhs );
		bool operator <( const CFSecTenantBuff& rhs );


		bool operator <=( const CFSecTenantPKey& rhs );
		bool operator <=( const CFSecTenantHPKey& rhs );
		bool operator <=( const CFSecTenantHBuff& rhs );
		bool operator <=( const CFSecTenantBuff& rhs );


		bool operator ==( const CFSecTenantPKey& rhs );
		bool operator ==( const CFSecTenantHPKey& rhs );
		bool operator ==( const CFSecTenantHBuff& rhs );
		bool operator ==( const CFSecTenantBuff& rhs );


		bool operator !=( const CFSecTenantPKey& rhs );
		bool operator !=( const CFSecTenantHPKey& rhs );
		bool operator !=( const CFSecTenantHBuff& rhs );
		bool operator !=( const CFSecTenantBuff& rhs );


		bool operator >=( const CFSecTenantPKey& rhs );
		bool operator >=( const CFSecTenantHPKey& rhs );
		bool operator >=( const CFSecTenantHBuff& rhs );
		bool operator >=( const CFSecTenantBuff& rhs );


		bool operator >( const CFSecTenantPKey& rhs );
		bool operator >( const CFSecTenantHPKey& rhs );
		bool operator >( const CFSecTenantHBuff& rhs );
		bool operator >( const CFSecTenantBuff& rhs );

		cfsec::CFSecTenantHPKey operator =( cfsec::CFSecTenantPKey& src );
		cfsec::CFSecTenantHPKey operator =( cfsec::CFSecTenantHPKey& src );
		cfsec::CFSecTenantHPKey operator =( cfsec::CFSecTenantBuff& src );
		cfsec::CFSecTenantHPKey operator =( cfsec::CFSecTenantHBuff& src );

	};
}


namespace std {

	bool operator <(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantPKey& rhs );
	bool operator <(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantHPKey& rhs );
	bool operator <(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator <(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantBuff& rhs );


	bool operator <=(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantPKey& rhs );
	bool operator <=(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantHPKey& rhs );
	bool operator <=(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator <=(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantBuff& rhs );


	bool operator ==(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantPKey& rhs );
	bool operator ==(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantHPKey& rhs );
	bool operator ==(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator ==(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantBuff& rhs );


	bool operator !=(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantPKey& rhs );
	bool operator !=(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantHPKey& rhs );
	bool operator !=(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator !=(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantBuff& rhs );


	bool operator >=(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantPKey& rhs );
	bool operator >=(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantHPKey& rhs );
	bool operator >=(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator >=(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantBuff& rhs );


	bool operator >(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantPKey& rhs );
	bool operator >(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantHPKey& rhs );
	bool operator >(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator >(const  cfsec::CFSecTenantHPKey& lhs, const cfsec::CFSecTenantBuff& rhs );


	template<> struct hash<cfsec::CFSecTenantHPKey> {
		typedef cfsec::CFSecTenantHPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

