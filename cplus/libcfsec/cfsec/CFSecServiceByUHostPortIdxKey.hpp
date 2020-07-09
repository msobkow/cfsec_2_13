#pragma once

// Description: C++18 specification for a Service by UHostPortIdx index key object.

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

	class CFSecServiceBuff;
	class CFSecServiceHBuff;

	class CFSecServiceByUHostPortIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int64_t requiredClusterId;
		int64_t requiredHostNodeId;
		int16_t requiredHostPort;
	public:
		CFSecServiceByUHostPortIdxKey();
		CFSecServiceByUHostPortIdxKey( const CFSecServiceByUHostPortIdxKey& src );
		virtual ~CFSecServiceByUHostPortIdxKey();

		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const int64_t getRequiredHostNodeId() const;
		virtual const int64_t* getRequiredHostNodeIdReference() const;
		virtual void setRequiredHostNodeId( const int64_t value );

		virtual const int16_t getRequiredHostPort() const;
		virtual const int16_t* getRequiredHostPortReference() const;
		virtual void setRequiredHostPort( const int16_t value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecServiceByUHostPortIdxKey& rhs );
		bool operator <( const CFSecServiceHBuff& rhs );
		bool operator <( const CFSecServiceBuff& rhs );

		bool operator <=( const CFSecServiceByUHostPortIdxKey& rhs );
		bool operator <=( const CFSecServiceHBuff& rhs );
		bool operator <=( const CFSecServiceBuff& rhs );

		bool operator ==( const CFSecServiceByUHostPortIdxKey& rhs );
		bool operator ==( const CFSecServiceHBuff& rhs );
		bool operator ==( const CFSecServiceBuff& rhs );

		bool operator !=( const CFSecServiceByUHostPortIdxKey& rhs );
		bool operator !=( const CFSecServiceHBuff& rhs );
		bool operator !=( const CFSecServiceBuff& rhs );

		bool operator >=( const CFSecServiceByUHostPortIdxKey& rhs );
		bool operator >=( const CFSecServiceHBuff& rhs );
		bool operator >=( const CFSecServiceBuff& rhs );

		bool operator >( const CFSecServiceByUHostPortIdxKey& rhs );
		bool operator >( const CFSecServiceHBuff& rhs );
		bool operator >( const CFSecServiceBuff& rhs );
		cfsec::CFSecServiceByUHostPortIdxKey operator =( cfsec::CFSecServiceByUHostPortIdxKey& src );
		cfsec::CFSecServiceByUHostPortIdxKey operator =( cfsec::CFSecServiceBuff& src );
		cfsec::CFSecServiceByUHostPortIdxKey operator =( cfsec::CFSecServiceHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );
	bool operator <(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator <(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator <=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator <=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator ==(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator ==(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator !=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator !=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator >=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator >=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs );

	bool operator >(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs );
	bool operator >(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator >(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs );

	template<> struct hash<cfsec::CFSecServiceByUHostPortIdxKey> {
		typedef cfsec::CFSecServiceByUHostPortIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

