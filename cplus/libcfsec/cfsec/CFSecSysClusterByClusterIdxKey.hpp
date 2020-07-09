#pragma once

// Description: C++18 specification for a SysCluster by ClusterIdx index key object.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	This file is part of MSS Code Factory.
 *	
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *	    http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
 *
 *	Manufactured by MSS Code Factory 2.12
 */
#include <cflib/ICFLibPublic.hpp>
#include <cfsec/ICFSecSchema.hpp>

namespace cfsec {

	class CFSecSysClusterBuff;
	class CFSecSysClusterHBuff;

	class CFSecSysClusterByClusterIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int64_t requiredClusterId;
	public:
		CFSecSysClusterByClusterIdxKey();
		CFSecSysClusterByClusterIdxKey( const CFSecSysClusterByClusterIdxKey& src );
		virtual ~CFSecSysClusterByClusterIdxKey();

		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecSysClusterByClusterIdxKey& rhs );
		bool operator <( const CFSecSysClusterHBuff& rhs );
		bool operator <( const CFSecSysClusterBuff& rhs );

		bool operator <=( const CFSecSysClusterByClusterIdxKey& rhs );
		bool operator <=( const CFSecSysClusterHBuff& rhs );
		bool operator <=( const CFSecSysClusterBuff& rhs );

		bool operator ==( const CFSecSysClusterByClusterIdxKey& rhs );
		bool operator ==( const CFSecSysClusterHBuff& rhs );
		bool operator ==( const CFSecSysClusterBuff& rhs );

		bool operator !=( const CFSecSysClusterByClusterIdxKey& rhs );
		bool operator !=( const CFSecSysClusterHBuff& rhs );
		bool operator !=( const CFSecSysClusterBuff& rhs );

		bool operator >=( const CFSecSysClusterByClusterIdxKey& rhs );
		bool operator >=( const CFSecSysClusterHBuff& rhs );
		bool operator >=( const CFSecSysClusterBuff& rhs );

		bool operator >( const CFSecSysClusterByClusterIdxKey& rhs );
		bool operator >( const CFSecSysClusterHBuff& rhs );
		bool operator >( const CFSecSysClusterBuff& rhs );
		cfsec::CFSecSysClusterByClusterIdxKey operator =( cfsec::CFSecSysClusterByClusterIdxKey& src );
		cfsec::CFSecSysClusterByClusterIdxKey operator =( cfsec::CFSecSysClusterBuff& src );
		cfsec::CFSecSysClusterByClusterIdxKey operator =( cfsec::CFSecSysClusterHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator <(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	bool operator <=(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	bool operator ==(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	bool operator !=(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	bool operator >=(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	bool operator >(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs );
	bool operator >(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterBuff& rhs );

	template<> struct hash<cfsec::CFSecSysClusterByClusterIdxKey> {
		typedef cfsec::CFSecSysClusterByClusterIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

