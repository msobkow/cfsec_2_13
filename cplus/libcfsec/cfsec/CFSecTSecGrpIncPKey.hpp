#pragma once

// Description: C++18 specification of a TSecGrpInc primary key object.

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

	class CFSecTSecGrpIncBuff;
	class CFSecTSecGrpIncHPKey;
	class CFSecTSecGrpIncHBuff;

	class CFSecTSecGrpIncPKey
	{
	protected:

		int64_t requiredTenantId;
		int64_t requiredTSecGrpIncId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;

		CFSecTSecGrpIncPKey();
		CFSecTSecGrpIncPKey( const CFSecTSecGrpIncPKey& src );
		virtual ~CFSecTSecGrpIncPKey();

		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const int64_t getRequiredTSecGrpIncId() const;
		virtual const int64_t* getRequiredTSecGrpIncIdReference() const;
		virtual void setRequiredTSecGrpIncId( const int64_t value );

		bool operator <( const CFSecTSecGrpIncHPKey& rhs );
		bool operator <( const CFSecTSecGrpIncPKey& rhs );
		bool operator <( const CFSecTSecGrpIncHBuff& rhs );
		bool operator <( const CFSecTSecGrpIncBuff& rhs );

		bool operator <=( const CFSecTSecGrpIncHPKey& rhs );
		bool operator <=( const CFSecTSecGrpIncPKey& rhs );
		bool operator <=( const CFSecTSecGrpIncHBuff& rhs );
		bool operator <=( const CFSecTSecGrpIncBuff& rhs );

		bool operator ==( const CFSecTSecGrpIncHPKey& rhs );
		bool operator ==( const CFSecTSecGrpIncPKey& rhs );
		bool operator ==( const CFSecTSecGrpIncHBuff& rhs );
		bool operator ==( const CFSecTSecGrpIncBuff& rhs );

		bool operator !=( const CFSecTSecGrpIncHPKey& rhs );
		bool operator !=( const CFSecTSecGrpIncPKey& rhs );
		bool operator !=( const CFSecTSecGrpIncHBuff& rhs );
		bool operator !=( const CFSecTSecGrpIncBuff& rhs );

		bool operator >=( const CFSecTSecGrpIncHPKey& rhs );
		bool operator >=( const CFSecTSecGrpIncPKey& rhs );
		bool operator >=( const CFSecTSecGrpIncHBuff& rhs );
		bool operator >=( const CFSecTSecGrpIncBuff& rhs );

		bool operator >( const CFSecTSecGrpIncHPKey& rhs );
		bool operator >( const CFSecTSecGrpIncPKey& rhs );
		bool operator >( const CFSecTSecGrpIncHBuff& rhs );
		bool operator >( const CFSecTSecGrpIncBuff& rhs );
		virtual size_t hashCode() const;

		virtual std::string toString();

		cfsec::CFSecTSecGrpIncPKey operator =( cfsec::CFSecTSecGrpIncPKey& src );
		cfsec::CFSecTSecGrpIncPKey operator =( cfsec::CFSecTSecGrpIncHPKey& src );
		cfsec::CFSecTSecGrpIncPKey operator =( cfsec::CFSecTSecGrpIncBuff& src );
		cfsec::CFSecTSecGrpIncPKey operator =( cfsec::CFSecTSecGrpIncHBuff& src );
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator <(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	bool operator <=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator <=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	bool operator ==(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator ==(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	bool operator !=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator !=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	bool operator >=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator >=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	bool operator >(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs );
	bool operator >(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs );

	template<> struct hash<cfsec::CFSecTSecGrpIncPKey> {
		typedef cfsec::CFSecTSecGrpIncPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

