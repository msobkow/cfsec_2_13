#pragma once

// Description: C++18 specification of a SecGrpMemb history primary key object.

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

	class CFSecSecGrpMembPKey;
	class CFSecSecGrpMembBuff;
	class CFSecSecGrpMembHBuff;

	class CFSecSecGrpMembHPKey : public CFSecHPKey
	{
	protected:

		int64_t requiredClusterId;
		int64_t requiredSecGrpMembId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;

		CFSecSecGrpMembHPKey();
		CFSecSecGrpMembHPKey( const CFSecSecGrpMembHPKey& src );
		virtual ~CFSecSecGrpMembHPKey();

		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const int64_t getRequiredSecGrpMembId() const;
		virtual const int64_t* getRequiredSecGrpMembIdReference() const;
		virtual void setRequiredSecGrpMembId( const int64_t value );

		virtual size_t hashCode() const;

		virtual std::string toString();

		bool operator <( const CFSecSecGrpMembPKey& rhs );
		bool operator <( const CFSecSecGrpMembHPKey& rhs );
		bool operator <( const CFSecSecGrpMembHBuff& rhs );
		bool operator <( const CFSecSecGrpMembBuff& rhs );


		bool operator <=( const CFSecSecGrpMembPKey& rhs );
		bool operator <=( const CFSecSecGrpMembHPKey& rhs );
		bool operator <=( const CFSecSecGrpMembHBuff& rhs );
		bool operator <=( const CFSecSecGrpMembBuff& rhs );


		bool operator ==( const CFSecSecGrpMembPKey& rhs );
		bool operator ==( const CFSecSecGrpMembHPKey& rhs );
		bool operator ==( const CFSecSecGrpMembHBuff& rhs );
		bool operator ==( const CFSecSecGrpMembBuff& rhs );


		bool operator !=( const CFSecSecGrpMembPKey& rhs );
		bool operator !=( const CFSecSecGrpMembHPKey& rhs );
		bool operator !=( const CFSecSecGrpMembHBuff& rhs );
		bool operator !=( const CFSecSecGrpMembBuff& rhs );


		bool operator >=( const CFSecSecGrpMembPKey& rhs );
		bool operator >=( const CFSecSecGrpMembHPKey& rhs );
		bool operator >=( const CFSecSecGrpMembHBuff& rhs );
		bool operator >=( const CFSecSecGrpMembBuff& rhs );


		bool operator >( const CFSecSecGrpMembPKey& rhs );
		bool operator >( const CFSecSecGrpMembHPKey& rhs );
		bool operator >( const CFSecSecGrpMembHBuff& rhs );
		bool operator >( const CFSecSecGrpMembBuff& rhs );

		cfsec::CFSecSecGrpMembHPKey operator =( cfsec::CFSecSecGrpMembPKey& src );
		cfsec::CFSecSecGrpMembHPKey operator =( cfsec::CFSecSecGrpMembHPKey& src );
		cfsec::CFSecSecGrpMembHPKey operator =( cfsec::CFSecSecGrpMembBuff& src );
		cfsec::CFSecSecGrpMembHPKey operator =( cfsec::CFSecSecGrpMembHBuff& src );

	};
}


namespace std {

	bool operator <(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );


	bool operator <=(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );


	bool operator ==(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );


	bool operator !=(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );


	bool operator >=(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );


	bool operator >(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembPKey& rhs );
	bool operator >(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs );
	bool operator >(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecGrpMembHPKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs );


	template<> struct hash<cfsec::CFSecSecGrpMembHPKey> {
		typedef cfsec::CFSecSecGrpMembHPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

