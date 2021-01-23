#pragma once

// Description: C++18 specification of a TSecGroup primary key object.

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

	class CFSecTSecGroupBuff;
	class CFSecTSecGroupHPKey;
	class CFSecTSecGroupHBuff;

	class CFSecTSecGroupPKey
	{
	protected:

		int64_t requiredTenantId;
		int32_t requiredTSecGroupId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;

		CFSecTSecGroupPKey();
		CFSecTSecGroupPKey( const CFSecTSecGroupPKey& src );
		virtual ~CFSecTSecGroupPKey();

		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const int32_t getRequiredTSecGroupId() const;
		virtual const int32_t* getRequiredTSecGroupIdReference() const;
		virtual void setRequiredTSecGroupId( const int32_t value );

		bool operator <( const CFSecTSecGroupHPKey& rhs );
		bool operator <( const CFSecTSecGroupPKey& rhs );
		bool operator <( const CFSecTSecGroupHBuff& rhs );
		bool operator <( const CFSecTSecGroupBuff& rhs );

		bool operator <=( const CFSecTSecGroupHPKey& rhs );
		bool operator <=( const CFSecTSecGroupPKey& rhs );
		bool operator <=( const CFSecTSecGroupHBuff& rhs );
		bool operator <=( const CFSecTSecGroupBuff& rhs );

		bool operator ==( const CFSecTSecGroupHPKey& rhs );
		bool operator ==( const CFSecTSecGroupPKey& rhs );
		bool operator ==( const CFSecTSecGroupHBuff& rhs );
		bool operator ==( const CFSecTSecGroupBuff& rhs );

		bool operator !=( const CFSecTSecGroupHPKey& rhs );
		bool operator !=( const CFSecTSecGroupPKey& rhs );
		bool operator !=( const CFSecTSecGroupHBuff& rhs );
		bool operator !=( const CFSecTSecGroupBuff& rhs );

		bool operator >=( const CFSecTSecGroupHPKey& rhs );
		bool operator >=( const CFSecTSecGroupPKey& rhs );
		bool operator >=( const CFSecTSecGroupHBuff& rhs );
		bool operator >=( const CFSecTSecGroupBuff& rhs );

		bool operator >( const CFSecTSecGroupHPKey& rhs );
		bool operator >( const CFSecTSecGroupPKey& rhs );
		bool operator >( const CFSecTSecGroupHBuff& rhs );
		bool operator >( const CFSecTSecGroupBuff& rhs );
		virtual size_t hashCode() const;

		virtual std::string toString();

		cfsec::CFSecTSecGroupPKey operator =( cfsec::CFSecTSecGroupPKey& src );
		cfsec::CFSecTSecGroupPKey operator =( cfsec::CFSecTSecGroupHPKey& src );
		cfsec::CFSecTSecGroupPKey operator =( cfsec::CFSecTSecGroupBuff& src );
		cfsec::CFSecTSecGroupPKey operator =( cfsec::CFSecTSecGroupHBuff& src );
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHPKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupPKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator <(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	bool operator <=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHPKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupPKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator <=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	bool operator ==(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHPKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupPKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator ==(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	bool operator !=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHPKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupPKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator !=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	bool operator >=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHPKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupPKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator >=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	bool operator >(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHPKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupPKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator >(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	template<> struct hash<cfsec::CFSecTSecGroupPKey> {
		typedef cfsec::CFSecTSecGroupPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

