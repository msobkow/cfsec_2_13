#pragma once

// Description: C++18 specification of a HostNode history primary key object.

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

	class CFSecHostNodePKey;
	class CFSecHostNodeBuff;
	class CFSecHostNodeHBuff;

	class CFSecHostNodeHPKey : public CFSecHPKey
	{
	protected:

		int64_t requiredClusterId;
		int64_t requiredHostNodeId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;

		CFSecHostNodeHPKey();
		CFSecHostNodeHPKey( const CFSecHostNodeHPKey& src );
		virtual ~CFSecHostNodeHPKey();

		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const int64_t getRequiredHostNodeId() const;
		virtual const int64_t* getRequiredHostNodeIdReference() const;
		virtual void setRequiredHostNodeId( const int64_t value );

		virtual size_t hashCode() const;

		virtual std::string toString();

		bool operator <( const CFSecHostNodePKey& rhs );
		bool operator <( const CFSecHostNodeHPKey& rhs );
		bool operator <( const CFSecHostNodeHBuff& rhs );
		bool operator <( const CFSecHostNodeBuff& rhs );


		bool operator <=( const CFSecHostNodePKey& rhs );
		bool operator <=( const CFSecHostNodeHPKey& rhs );
		bool operator <=( const CFSecHostNodeHBuff& rhs );
		bool operator <=( const CFSecHostNodeBuff& rhs );


		bool operator ==( const CFSecHostNodePKey& rhs );
		bool operator ==( const CFSecHostNodeHPKey& rhs );
		bool operator ==( const CFSecHostNodeHBuff& rhs );
		bool operator ==( const CFSecHostNodeBuff& rhs );


		bool operator !=( const CFSecHostNodePKey& rhs );
		bool operator !=( const CFSecHostNodeHPKey& rhs );
		bool operator !=( const CFSecHostNodeHBuff& rhs );
		bool operator !=( const CFSecHostNodeBuff& rhs );


		bool operator >=( const CFSecHostNodePKey& rhs );
		bool operator >=( const CFSecHostNodeHPKey& rhs );
		bool operator >=( const CFSecHostNodeHBuff& rhs );
		bool operator >=( const CFSecHostNodeBuff& rhs );


		bool operator >( const CFSecHostNodePKey& rhs );
		bool operator >( const CFSecHostNodeHPKey& rhs );
		bool operator >( const CFSecHostNodeHBuff& rhs );
		bool operator >( const CFSecHostNodeBuff& rhs );

		cfsec::CFSecHostNodeHPKey operator =( cfsec::CFSecHostNodePKey& src );
		cfsec::CFSecHostNodeHPKey operator =( cfsec::CFSecHostNodeHPKey& src );
		cfsec::CFSecHostNodeHPKey operator =( cfsec::CFSecHostNodeBuff& src );
		cfsec::CFSecHostNodeHPKey operator =( cfsec::CFSecHostNodeHBuff& src );

	};
}


namespace std {

	bool operator <(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodePKey& rhs );
	bool operator <(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodeHPKey& rhs );
	bool operator <(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodeHBuff& rhs );
	bool operator <(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodeBuff& rhs );


	bool operator <=(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodePKey& rhs );
	bool operator <=(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodeHPKey& rhs );
	bool operator <=(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodeHBuff& rhs );
	bool operator <=(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodeBuff& rhs );


	bool operator ==(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodePKey& rhs );
	bool operator ==(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodeHPKey& rhs );
	bool operator ==(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodeHBuff& rhs );
	bool operator ==(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodeBuff& rhs );


	bool operator !=(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodePKey& rhs );
	bool operator !=(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodeHPKey& rhs );
	bool operator !=(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodeHBuff& rhs );
	bool operator !=(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodeBuff& rhs );


	bool operator >=(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodePKey& rhs );
	bool operator >=(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodeHPKey& rhs );
	bool operator >=(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodeHBuff& rhs );
	bool operator >=(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodeBuff& rhs );


	bool operator >(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodePKey& rhs );
	bool operator >(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodeHPKey& rhs );
	bool operator >(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodeHBuff& rhs );
	bool operator >(const  cfsec::CFSecHostNodeHPKey& lhs, const cfsec::CFSecHostNodeBuff& rhs );


	template<> struct hash<cfsec::CFSecHostNodeHPKey> {
		typedef cfsec::CFSecHostNodeHPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

