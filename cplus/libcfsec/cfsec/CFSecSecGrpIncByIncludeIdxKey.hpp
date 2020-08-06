#pragma once

// Description: C++18 specification for a SecGrpInc by IncludeIdx index key object.

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

	class CFSecSecGrpIncBuff;
	class CFSecSecGrpIncHBuff;

	class CFSecSecGrpIncByIncludeIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int64_t requiredClusterId;
		int32_t requiredIncludeGroupId;
	public:
		CFSecSecGrpIncByIncludeIdxKey();
		CFSecSecGrpIncByIncludeIdxKey( const CFSecSecGrpIncByIncludeIdxKey& src );
		virtual ~CFSecSecGrpIncByIncludeIdxKey();

		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const int32_t getRequiredIncludeGroupId() const;
		virtual const int32_t* getRequiredIncludeGroupIdReference() const;
		virtual void setRequiredIncludeGroupId( const int32_t value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecSecGrpIncByIncludeIdxKey& rhs );
		bool operator <( const CFSecSecGrpIncHBuff& rhs );
		bool operator <( const CFSecSecGrpIncBuff& rhs );

		bool operator <=( const CFSecSecGrpIncByIncludeIdxKey& rhs );
		bool operator <=( const CFSecSecGrpIncHBuff& rhs );
		bool operator <=( const CFSecSecGrpIncBuff& rhs );

		bool operator ==( const CFSecSecGrpIncByIncludeIdxKey& rhs );
		bool operator ==( const CFSecSecGrpIncHBuff& rhs );
		bool operator ==( const CFSecSecGrpIncBuff& rhs );

		bool operator !=( const CFSecSecGrpIncByIncludeIdxKey& rhs );
		bool operator !=( const CFSecSecGrpIncHBuff& rhs );
		bool operator !=( const CFSecSecGrpIncBuff& rhs );

		bool operator >=( const CFSecSecGrpIncByIncludeIdxKey& rhs );
		bool operator >=( const CFSecSecGrpIncHBuff& rhs );
		bool operator >=( const CFSecSecGrpIncBuff& rhs );

		bool operator >( const CFSecSecGrpIncByIncludeIdxKey& rhs );
		bool operator >( const CFSecSecGrpIncHBuff& rhs );
		bool operator >( const CFSecSecGrpIncBuff& rhs );
		cfsec::CFSecSecGrpIncByIncludeIdxKey operator =( cfsec::CFSecSecGrpIncByIncludeIdxKey& src );
		cfsec::CFSecSecGrpIncByIncludeIdxKey operator =( cfsec::CFSecSecGrpIncBuff& src );
		cfsec::CFSecSecGrpIncByIncludeIdxKey operator =( cfsec::CFSecSecGrpIncHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	bool operator >(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	template<> struct hash<cfsec::CFSecSecGrpIncByIncludeIdxKey> {
		typedef cfsec::CFSecSecGrpIncByIncludeIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

