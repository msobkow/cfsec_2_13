#pragma once

// Description: C++18 specification of a SecGrpMemb history buffer object.

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

#include <cfsec/CFSecHPKey.hpp>

#include <cfsec/ICFSecSchema.hpp>
namespace cfsec {

	class CFSecSecGrpMembBuff;
	class CFSecSecGrpMembPKey;
	class CFSecSecGrpMembHPKey;
	class CFSecSecGrpMembByClusterIdxKey;
	class CFSecSecGrpMembByGroupIdxKey;
	class CFSecSecGrpMembByUserIdxKey;
	class CFSecSecGrpMembByUUserIdxKey;

	class CFSecSecGrpMembHBuff : public CFSecHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int64_t requiredClusterId;
		int64_t requiredSecGrpMembId;
		int32_t requiredSecGroupId;
		uuid_t requiredSecUserId;		classcode_t classCode;

	public:
		CFSecSecGrpMembHBuff();
		CFSecSecGrpMembHBuff( const CFSecSecGrpMembHBuff& src );
		virtual ~CFSecSecGrpMembHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const int64_t getRequiredSecGrpMembId() const;
		virtual const int64_t* getRequiredSecGrpMembIdReference() const;
		virtual void setRequiredSecGrpMembId( const int64_t value );

		virtual const int32_t getRequiredSecGroupId() const;
		virtual const int32_t* getRequiredSecGroupIdReference() const;
		virtual void setRequiredSecGroupId( const int32_t value );

		virtual const uuid_ptr_t getRequiredSecUserId() const;
		virtual const uuid_ptr_t getRequiredSecUserIdReference() const;
		virtual void setRequiredSecUserId( const uuid_ptr_t value );
		virtual void generateRequiredSecUserId();

		virtual size_t hashCode() const;

		bool operator <( const CFSecSecGrpMembByClusterIdxKey& rhs );
		bool operator <( const CFSecSecGrpMembByGroupIdxKey& rhs );
		bool operator <( const CFSecSecGrpMembByUserIdxKey& rhs );
		bool operator <( const CFSecSecGrpMembByUUserIdxKey& rhs );
		bool operator <( const CFSecSecGrpMembPKey& rhs );
		bool operator <( const CFSecSecGrpMembHPKey& rhs );
		bool operator <( const CFSecSecGrpMembHBuff& rhs );
		bool operator <( const CFSecSecGrpMembBuff& rhs );

		bool operator <=( const CFSecSecGrpMembByClusterIdxKey& rhs );
		bool operator <=( const CFSecSecGrpMembByGroupIdxKey& rhs );
		bool operator <=( const CFSecSecGrpMembByUserIdxKey& rhs );
		bool operator <=( const CFSecSecGrpMembByUUserIdxKey& rhs );
		bool operator <=( const CFSecSecGrpMembPKey& rhs );
		bool operator <=( const CFSecSecGrpMembHPKey& rhs );
		bool operator <=( const CFSecSecGrpMembHBuff& rhs );
		bool operator <=( const CFSecSecGrpMembBuff& rhs );

		bool operator ==( const CFSecSecGrpMembByClusterIdxKey& rhs );
		bool operator ==( const CFSecSecGrpMembByGroupIdxKey& rhs );
		bool operator ==( const CFSecSecGrpMembByUserIdxKey& rhs );
		bool operator ==( const CFSecSecGrpMembByUUserIdxKey& rhs );
		bool operator ==( const CFSecSecGrpMembPKey& rhs );
		bool operator ==( const CFSecSecGrpMembHPKey& rhs );
		bool operator ==( const CFSecSecGrpMembHBuff& rhs );
		bool operator ==( const CFSecSecGrpMembBuff& rhs );

		bool operator !=( const CFSecSecGrpMembByClusterIdxKey& rhs );
		bool operator !=( const CFSecSecGrpMembByGroupIdxKey& rhs );
		bool operator !=( const CFSecSecGrpMembByUserIdxKey& rhs );
		bool operator !=( const CFSecSecGrpMembByUUserIdxKey& rhs );
		bool operator !=( const CFSecSecGrpMembPKey& rhs );
		bool operator !=( const CFSecSecGrpMembHPKey& rhs );
		bool operator !=( const CFSecSecGrpMembHBuff& rhs );
		bool operator !=( const CFSecSecGrpMembBuff& rhs );

		bool operator >=( const CFSecSecGrpMembByClusterIdxKey& rhs );
		bool operator >=( const CFSecSecGrpMembByGroupIdxKey& rhs );
		bool operator >=( const CFSecSecGrpMembByUserIdxKey& rhs );
		bool operator >=( const CFSecSecGrpMembByUUserIdxKey& rhs );
		bool operator >=( const CFSecSecGrpMembPKey& rhs );
		bool operator >=( const CFSecSecGrpMembHPKey& rhs );
		bool operator >=( const CFSecSecGrpMembHBuff& rhs );
		bool operator >=( const CFSecSecGrpMembBuff& rhs );

		bool operator >( const CFSecSecGrpMembByClusterIdxKey& rhs );
		bool operator >( const CFSecSecGrpMembByGroupIdxKey& rhs );
		bool operator >( const CFSecSecGrpMembByUserIdxKey& rhs );
		bool operator >( const CFSecSecGrpMembByUUserIdxKey& rhs );
		bool operator >( const CFSecSecGrpMembPKey& rhs );
		bool operator >( const CFSecSecGrpMembHPKey& rhs );
		bool operator >( const CFSecSecGrpMembHBuff& rhs );
		bool operator >( const CFSecSecGrpMembBuff& rhs );
		cfsec::CFSecSecGrpMembHBuff operator =( cfsec::CFSecSecGrpMembBuff& src );
		cfsec::CFSecSecGrpMembHBuff operator =( cfsec::CFSecSecGrpMembHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByClusterIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByGroupIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByUserIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByUUserIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByClusterIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByGroupIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByUserIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByUUserIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByClusterIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByGroupIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByUserIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByUUserIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByClusterIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByGroupIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByUserIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByUUserIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByClusterIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByGroupIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByUserIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByUUserIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	bool operator >(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByClusterIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByGroupIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByUserIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembByUUserIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator >(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator >(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecGrpMembHBuff& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );

	template<> struct hash<cfsec::CFSecSecGrpMembHBuff> {
		typedef cfsec::CFSecSecGrpMembHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

