#pragma once

// Description: C++18 specification of a SysCluster history buffer object.

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

	class CFSecSysClusterBuff;
	class CFSecSysClusterPKey;
	class CFSecSysClusterHPKey;
	class CFSecSysClusterByClusterIdxKey;

	class CFSecSysClusterHBuff : public CFSecHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int32_t requiredSingletonId;
		int64_t requiredClusterId;		classcode_t classCode;

	public:
		CFSecSysClusterHBuff();
		CFSecSysClusterHBuff( const CFSecSysClusterHBuff& src );
		virtual ~CFSecSysClusterHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const int32_t getRequiredSingletonId() const;
		virtual const int32_t* getRequiredSingletonIdReference() const;
		virtual void setRequiredSingletonId( const int32_t value );

		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecSysClusterByClusterIdxKey& rhs );
		bool operator <( const CFSecSysClusterPKey& rhs );
		bool operator <( const CFSecSysClusterHPKey& rhs );
		bool operator <( const CFSecSysClusterHBuff& rhs );
		bool operator <( const CFSecSysClusterBuff& rhs );

		bool operator <=( const CFSecSysClusterByClusterIdxKey& rhs );
		bool operator <=( const CFSecSysClusterPKey& rhs );
		bool operator <=( const CFSecSysClusterHPKey& rhs );
		bool operator <=( const CFSecSysClusterHBuff& rhs );
		bool operator <=( const CFSecSysClusterBuff& rhs );

		bool operator ==( const CFSecSysClusterByClusterIdxKey& rhs );
		bool operator ==( const CFSecSysClusterPKey& rhs );
		bool operator ==( const CFSecSysClusterHPKey& rhs );
		bool operator ==( const CFSecSysClusterHBuff& rhs );
		bool operator ==( const CFSecSysClusterBuff& rhs );

		bool operator !=( const CFSecSysClusterByClusterIdxKey& rhs );
		bool operator !=( const CFSecSysClusterPKey& rhs );
		bool operator !=( const CFSecSysClusterHPKey& rhs );
		bool operator !=( const CFSecSysClusterHBuff& rhs );
		bool operator !=( const CFSecSysClusterBuff& rhs );

		bool operator >=( const CFSecSysClusterByClusterIdxKey& rhs );
		bool operator >=( const CFSecSysClusterPKey& rhs );
		bool operator >=( const CFSecSysClusterHPKey& rhs );
		bool operator >=( const CFSecSysClusterHBuff& rhs );
		bool operator >=( const CFSecSysClusterBuff& rhs );

		bool operator >( const CFSecSysClusterByClusterIdxKey& rhs );
		bool operator >( const CFSecSysClusterPKey& rhs );
		bool operator >( const CFSecSysClusterHPKey& rhs );
		bool operator >( const CFSecSysClusterHBuff& rhs );
		bool operator >( const CFSecSysClusterBuff& rhs );
		cfsec::CFSecSysClusterHBuff operator =( cfsec::CFSecSysClusterBuff& src );
		cfsec::CFSecSysClusterHBuff operator =( cfsec::CFSecSysClusterHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterPKey& rhs );
	bool operator <(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterHPKey& rhs );
	bool operator <(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator <(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	bool operator <=(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterPKey& rhs );
	bool operator <=(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	bool operator ==(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterPKey& rhs );
	bool operator ==(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	bool operator !=(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterPKey& rhs );
	bool operator !=(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	bool operator >=(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterPKey& rhs );
	bool operator >=(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	bool operator >(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterPKey& rhs );
	bool operator >(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterHPKey& rhs );
	bool operator >(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator >(const  cfsec::CFSecSysClusterHBuff& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	template<> struct hash<cfsec::CFSecSysClusterHBuff> {
		typedef cfsec::CFSecSysClusterHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

