#pragma once

// Description: C++18 specification for a HostNode by HostNameIdx index key object.

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

	class CFSecHostNodeBuff;
	class CFSecHostNodeHBuff;

	class CFSecHostNodeByHostNameIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int64_t requiredClusterId;
		std::string* requiredHostName;
	public:
		CFSecHostNodeByHostNameIdxKey();
		CFSecHostNodeByHostNameIdxKey( const CFSecHostNodeByHostNameIdxKey& src );
		virtual ~CFSecHostNodeByHostNameIdxKey();

		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const std::string& getRequiredHostName() const;
		virtual const std::string* getRequiredHostNameReference() const;
		virtual void setRequiredHostName( const std::string& value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecHostNodeByHostNameIdxKey& rhs );
		bool operator <( const CFSecHostNodeHBuff& rhs );
		bool operator <( const CFSecHostNodeBuff& rhs );

		bool operator <=( const CFSecHostNodeByHostNameIdxKey& rhs );
		bool operator <=( const CFSecHostNodeHBuff& rhs );
		bool operator <=( const CFSecHostNodeBuff& rhs );

		bool operator ==( const CFSecHostNodeByHostNameIdxKey& rhs );
		bool operator ==( const CFSecHostNodeHBuff& rhs );
		bool operator ==( const CFSecHostNodeBuff& rhs );

		bool operator !=( const CFSecHostNodeByHostNameIdxKey& rhs );
		bool operator !=( const CFSecHostNodeHBuff& rhs );
		bool operator !=( const CFSecHostNodeBuff& rhs );

		bool operator >=( const CFSecHostNodeByHostNameIdxKey& rhs );
		bool operator >=( const CFSecHostNodeHBuff& rhs );
		bool operator >=( const CFSecHostNodeBuff& rhs );

		bool operator >( const CFSecHostNodeByHostNameIdxKey& rhs );
		bool operator >( const CFSecHostNodeHBuff& rhs );
		bool operator >( const CFSecHostNodeBuff& rhs );
		cfsec::CFSecHostNodeByHostNameIdxKey operator =( cfsec::CFSecHostNodeByHostNameIdxKey& src );
		cfsec::CFSecHostNodeByHostNameIdxKey operator =( cfsec::CFSecHostNodeBuff& src );
		cfsec::CFSecHostNodeByHostNameIdxKey operator =( cfsec::CFSecHostNodeHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeByHostNameIdxKey& rhs );
	bool operator <(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeHBuff& rhs );
	bool operator <(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeBuff& rhs );

	bool operator <=(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeByHostNameIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeHBuff& rhs );
	bool operator <=(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeBuff& rhs );

	bool operator ==(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeByHostNameIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeHBuff& rhs );
	bool operator ==(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeBuff& rhs );

	bool operator !=(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeByHostNameIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeHBuff& rhs );
	bool operator !=(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeBuff& rhs );

	bool operator >=(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeByHostNameIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeHBuff& rhs );
	bool operator >=(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeBuff& rhs );

	bool operator >(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeByHostNameIdxKey& rhs );
	bool operator >(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeHBuff& rhs );
	bool operator >(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeBuff& rhs );

	template<> struct hash<cfsec::CFSecHostNodeByHostNameIdxKey> {
		typedef cfsec::CFSecHostNodeByHostNameIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

