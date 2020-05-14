#pragma once

// Description: C++18 specification for a SecGroupForm by ClusterIdx index key object.

/*
 *	com.github.msobkow.CFSec
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

	class CFSecSecGroupFormBuff;
	class CFSecSecGroupFormHBuff;

	class CFSecSecGroupFormByClusterIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int64_t requiredClusterId;
	public:
		CFSecSecGroupFormByClusterIdxKey();
		CFSecSecGroupFormByClusterIdxKey( const CFSecSecGroupFormByClusterIdxKey& src );
		virtual ~CFSecSecGroupFormByClusterIdxKey();

		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecSecGroupFormByClusterIdxKey& rhs );
		bool operator <( const CFSecSecGroupFormHBuff& rhs );
		bool operator <( const CFSecSecGroupFormBuff& rhs );

		bool operator <=( const CFSecSecGroupFormByClusterIdxKey& rhs );
		bool operator <=( const CFSecSecGroupFormHBuff& rhs );
		bool operator <=( const CFSecSecGroupFormBuff& rhs );

		bool operator ==( const CFSecSecGroupFormByClusterIdxKey& rhs );
		bool operator ==( const CFSecSecGroupFormHBuff& rhs );
		bool operator ==( const CFSecSecGroupFormBuff& rhs );

		bool operator !=( const CFSecSecGroupFormByClusterIdxKey& rhs );
		bool operator !=( const CFSecSecGroupFormHBuff& rhs );
		bool operator !=( const CFSecSecGroupFormBuff& rhs );

		bool operator >=( const CFSecSecGroupFormByClusterIdxKey& rhs );
		bool operator >=( const CFSecSecGroupFormHBuff& rhs );
		bool operator >=( const CFSecSecGroupFormBuff& rhs );

		bool operator >( const CFSecSecGroupFormByClusterIdxKey& rhs );
		bool operator >( const CFSecSecGroupFormHBuff& rhs );
		bool operator >( const CFSecSecGroupFormBuff& rhs );
		cfsec::CFSecSecGroupFormByClusterIdxKey operator =( cfsec::CFSecSecGroupFormByClusterIdxKey& src );
		cfsec::CFSecSecGroupFormByClusterIdxKey operator =( cfsec::CFSecSecGroupFormBuff& src );
		cfsec::CFSecSecGroupFormByClusterIdxKey operator =( cfsec::CFSecSecGroupFormHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecGroupFormByClusterIdxKey& lhs, const cfsec::CFSecSecGroupFormByClusterIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGroupFormByClusterIdxKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecGroupFormByClusterIdxKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecGroupFormByClusterIdxKey& lhs, const cfsec::CFSecSecGroupFormByClusterIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupFormByClusterIdxKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupFormByClusterIdxKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecGroupFormByClusterIdxKey& lhs, const cfsec::CFSecSecGroupFormByClusterIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupFormByClusterIdxKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupFormByClusterIdxKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecGroupFormByClusterIdxKey& lhs, const cfsec::CFSecSecGroupFormByClusterIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupFormByClusterIdxKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupFormByClusterIdxKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecGroupFormByClusterIdxKey& lhs, const cfsec::CFSecSecGroupFormByClusterIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupFormByClusterIdxKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupFormByClusterIdxKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs );

	bool operator >(const  cfsec::CFSecSecGroupFormByClusterIdxKey& lhs, const cfsec::CFSecSecGroupFormByClusterIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecGroupFormByClusterIdxKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecGroupFormByClusterIdxKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs );

	template<> struct hash<cfsec::CFSecSecGroupFormByClusterIdxKey> {
		typedef cfsec::CFSecSecGroupFormByClusterIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

