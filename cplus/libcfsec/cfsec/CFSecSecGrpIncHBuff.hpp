#pragma once

// Description: C++18 specification of a SecGrpInc history buffer object.

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

	class CFSecSecGrpIncBuff;
	class CFSecSecGrpIncPKey;
	class CFSecSecGrpIncHPKey;
	class CFSecSecGrpIncByClusterIdxKey;
	class CFSecSecGrpIncByGroupIdxKey;
	class CFSecSecGrpIncByIncludeIdxKey;
	class CFSecSecGrpIncByUIncludeIdxKey;

	class CFSecSecGrpIncHBuff : public CFSecHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int64_t requiredClusterId;
		int64_t requiredSecGrpIncId;
		int32_t requiredSecGroupId;
		int32_t requiredIncludeGroupId;		classcode_t classCode;

	public:
		CFSecSecGrpIncHBuff();
		CFSecSecGrpIncHBuff( const CFSecSecGrpIncHBuff& src );
		virtual ~CFSecSecGrpIncHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const int64_t getRequiredSecGrpIncId() const;
		virtual const int64_t* getRequiredSecGrpIncIdReference() const;
		virtual void setRequiredSecGrpIncId( const int64_t value );

		virtual const int32_t getRequiredSecGroupId() const;
		virtual const int32_t* getRequiredSecGroupIdReference() const;
		virtual void setRequiredSecGroupId( const int32_t value );

		virtual const int32_t getRequiredIncludeGroupId() const;
		virtual const int32_t* getRequiredIncludeGroupIdReference() const;
		virtual void setRequiredIncludeGroupId( const int32_t value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecSecGrpIncByClusterIdxKey& rhs );
		bool operator <( const CFSecSecGrpIncByGroupIdxKey& rhs );
		bool operator <( const CFSecSecGrpIncByIncludeIdxKey& rhs );
		bool operator <( const CFSecSecGrpIncByUIncludeIdxKey& rhs );
		bool operator <( const CFSecSecGrpIncPKey& rhs );
		bool operator <( const CFSecSecGrpIncHPKey& rhs );
		bool operator <( const CFSecSecGrpIncHBuff& rhs );
		bool operator <( const CFSecSecGrpIncBuff& rhs );

		bool operator <=( const CFSecSecGrpIncByClusterIdxKey& rhs );
		bool operator <=( const CFSecSecGrpIncByGroupIdxKey& rhs );
		bool operator <=( const CFSecSecGrpIncByIncludeIdxKey& rhs );
		bool operator <=( const CFSecSecGrpIncByUIncludeIdxKey& rhs );
		bool operator <=( const CFSecSecGrpIncPKey& rhs );
		bool operator <=( const CFSecSecGrpIncHPKey& rhs );
		bool operator <=( const CFSecSecGrpIncHBuff& rhs );
		bool operator <=( const CFSecSecGrpIncBuff& rhs );

		bool operator ==( const CFSecSecGrpIncByClusterIdxKey& rhs );
		bool operator ==( const CFSecSecGrpIncByGroupIdxKey& rhs );
		bool operator ==( const CFSecSecGrpIncByIncludeIdxKey& rhs );
		bool operator ==( const CFSecSecGrpIncByUIncludeIdxKey& rhs );
		bool operator ==( const CFSecSecGrpIncPKey& rhs );
		bool operator ==( const CFSecSecGrpIncHPKey& rhs );
		bool operator ==( const CFSecSecGrpIncHBuff& rhs );
		bool operator ==( const CFSecSecGrpIncBuff& rhs );

		bool operator !=( const CFSecSecGrpIncByClusterIdxKey& rhs );
		bool operator !=( const CFSecSecGrpIncByGroupIdxKey& rhs );
		bool operator !=( const CFSecSecGrpIncByIncludeIdxKey& rhs );
		bool operator !=( const CFSecSecGrpIncByUIncludeIdxKey& rhs );
		bool operator !=( const CFSecSecGrpIncPKey& rhs );
		bool operator !=( const CFSecSecGrpIncHPKey& rhs );
		bool operator !=( const CFSecSecGrpIncHBuff& rhs );
		bool operator !=( const CFSecSecGrpIncBuff& rhs );

		bool operator >=( const CFSecSecGrpIncByClusterIdxKey& rhs );
		bool operator >=( const CFSecSecGrpIncByGroupIdxKey& rhs );
		bool operator >=( const CFSecSecGrpIncByIncludeIdxKey& rhs );
		bool operator >=( const CFSecSecGrpIncByUIncludeIdxKey& rhs );
		bool operator >=( const CFSecSecGrpIncPKey& rhs );
		bool operator >=( const CFSecSecGrpIncHPKey& rhs );
		bool operator >=( const CFSecSecGrpIncHBuff& rhs );
		bool operator >=( const CFSecSecGrpIncBuff& rhs );

		bool operator >( const CFSecSecGrpIncByClusterIdxKey& rhs );
		bool operator >( const CFSecSecGrpIncByGroupIdxKey& rhs );
		bool operator >( const CFSecSecGrpIncByIncludeIdxKey& rhs );
		bool operator >( const CFSecSecGrpIncByUIncludeIdxKey& rhs );
		bool operator >( const CFSecSecGrpIncPKey& rhs );
		bool operator >( const CFSecSecGrpIncHPKey& rhs );
		bool operator >( const CFSecSecGrpIncHBuff& rhs );
		bool operator >( const CFSecSecGrpIncBuff& rhs );
		cfsec::CFSecSecGrpIncHBuff operator =( cfsec::CFSecSecGrpIncBuff& src );
		cfsec::CFSecSecGrpIncHBuff operator =( cfsec::CFSecSecGrpIncHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByClusterIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByGroupIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByUIncludeIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncPKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncHPKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByClusterIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByGroupIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByUIncludeIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByClusterIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByGroupIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByUIncludeIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByClusterIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByGroupIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByUIncludeIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByClusterIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByGroupIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByUIncludeIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	bool operator >(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByClusterIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByGroupIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncByUIncludeIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncPKey& rhs );
	bool operator >(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncHPKey& rhs );
	bool operator >(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecGrpIncHBuff& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	template<> struct hash<cfsec::CFSecSecGrpIncHBuff> {
		typedef cfsec::CFSecSecGrpIncHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

