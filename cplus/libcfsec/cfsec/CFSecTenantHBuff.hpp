#pragma once

// Description: C++18 specification of a Tenant history buffer object.

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

	class CFSecTenantBuff;
	class CFSecTenantPKey;
	class CFSecTenantHPKey;
	class CFSecTenantByClusterIdxKey;
	class CFSecTenantByUNameIdxKey;

	class CFSecTenantHBuff : public CFSecHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int64_t requiredClusterId;
		int64_t requiredId;
		std::string* requiredTenantName;		classcode_t classCode;

	public:
		CFSecTenantHBuff();
		CFSecTenantHBuff( const CFSecTenantHBuff& src );
		virtual ~CFSecTenantHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const int64_t getRequiredId() const;
		virtual const int64_t* getRequiredIdReference() const;
		virtual void setRequiredId( const int64_t value );

		virtual const std::string& getRequiredTenantName() const;
		virtual const std::string* getRequiredTenantNameReference() const;
		virtual void setRequiredTenantName( const std::string& value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecTenantByClusterIdxKey& rhs );
		bool operator <( const CFSecTenantByUNameIdxKey& rhs );
		bool operator <( const CFSecTenantPKey& rhs );
		bool operator <( const CFSecTenantHPKey& rhs );
		bool operator <( const CFSecTenantHBuff& rhs );
		bool operator <( const CFSecTenantBuff& rhs );

		bool operator <=( const CFSecTenantByClusterIdxKey& rhs );
		bool operator <=( const CFSecTenantByUNameIdxKey& rhs );
		bool operator <=( const CFSecTenantPKey& rhs );
		bool operator <=( const CFSecTenantHPKey& rhs );
		bool operator <=( const CFSecTenantHBuff& rhs );
		bool operator <=( const CFSecTenantBuff& rhs );

		bool operator ==( const CFSecTenantByClusterIdxKey& rhs );
		bool operator ==( const CFSecTenantByUNameIdxKey& rhs );
		bool operator ==( const CFSecTenantPKey& rhs );
		bool operator ==( const CFSecTenantHPKey& rhs );
		bool operator ==( const CFSecTenantHBuff& rhs );
		bool operator ==( const CFSecTenantBuff& rhs );

		bool operator !=( const CFSecTenantByClusterIdxKey& rhs );
		bool operator !=( const CFSecTenantByUNameIdxKey& rhs );
		bool operator !=( const CFSecTenantPKey& rhs );
		bool operator !=( const CFSecTenantHPKey& rhs );
		bool operator !=( const CFSecTenantHBuff& rhs );
		bool operator !=( const CFSecTenantBuff& rhs );

		bool operator >=( const CFSecTenantByClusterIdxKey& rhs );
		bool operator >=( const CFSecTenantByUNameIdxKey& rhs );
		bool operator >=( const CFSecTenantPKey& rhs );
		bool operator >=( const CFSecTenantHPKey& rhs );
		bool operator >=( const CFSecTenantHBuff& rhs );
		bool operator >=( const CFSecTenantBuff& rhs );

		bool operator >( const CFSecTenantByClusterIdxKey& rhs );
		bool operator >( const CFSecTenantByUNameIdxKey& rhs );
		bool operator >( const CFSecTenantPKey& rhs );
		bool operator >( const CFSecTenantHPKey& rhs );
		bool operator >( const CFSecTenantHBuff& rhs );
		bool operator >( const CFSecTenantBuff& rhs );
		cfsec::CFSecTenantHBuff operator =( cfsec::CFSecTenantBuff& src );
		cfsec::CFSecTenantHBuff operator =( cfsec::CFSecTenantHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantByClusterIdxKey& rhs );
	bool operator <(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs );
	bool operator <(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantPKey& rhs );
	bool operator <(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantHPKey& rhs );
	bool operator <(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator <(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantBuff& rhs );

	bool operator <=(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantByClusterIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantPKey& rhs );
	bool operator <=(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantHPKey& rhs );
	bool operator <=(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator <=(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantBuff& rhs );

	bool operator ==(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantByClusterIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantPKey& rhs );
	bool operator ==(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantHPKey& rhs );
	bool operator ==(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator ==(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantBuff& rhs );

	bool operator !=(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantByClusterIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantPKey& rhs );
	bool operator !=(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantHPKey& rhs );
	bool operator !=(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator !=(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantBuff& rhs );

	bool operator >=(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantByClusterIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantPKey& rhs );
	bool operator >=(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantHPKey& rhs );
	bool operator >=(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator >=(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantBuff& rhs );

	bool operator >(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantByClusterIdxKey& rhs );
	bool operator >(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs );
	bool operator >(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantPKey& rhs );
	bool operator >(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantHPKey& rhs );
	bool operator >(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantHBuff& rhs );
	bool operator >(const  cfsec::CFSecTenantHBuff& lhs, const cfsec::CFSecTenantBuff& rhs );

	template<> struct hash<cfsec::CFSecTenantHBuff> {
		typedef cfsec::CFSecTenantHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

