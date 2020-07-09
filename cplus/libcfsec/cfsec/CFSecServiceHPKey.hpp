#pragma once

// Description: C++18 specification of a Service history primary key object.

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

#include <cfsec/CFSecHPKey.hpp>
#include <cfsec/ICFSecSchema.hpp>

namespace cfsec {

	class CFSecServicePKey;
	class CFSecServiceBuff;
	class CFSecServiceHBuff;

	class CFSecServiceHPKey : public CFSecHPKey
	{
	protected:

		int64_t requiredClusterId;
		int64_t requiredServiceId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;

		CFSecServiceHPKey();
		CFSecServiceHPKey( const CFSecServiceHPKey& src );
		virtual ~CFSecServiceHPKey();

		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const int64_t getRequiredServiceId() const;
		virtual const int64_t* getRequiredServiceIdReference() const;
		virtual void setRequiredServiceId( const int64_t value );

		virtual size_t hashCode() const;

		virtual std::string toString();

		bool operator <( const CFSecServicePKey& rhs );
		bool operator <( const CFSecServiceHPKey& rhs );
		bool operator <( const CFSecServiceHBuff& rhs );
		bool operator <( const CFSecServiceBuff& rhs );


		bool operator <=( const CFSecServicePKey& rhs );
		bool operator <=( const CFSecServiceHPKey& rhs );
		bool operator <=( const CFSecServiceHBuff& rhs );
		bool operator <=( const CFSecServiceBuff& rhs );


		bool operator ==( const CFSecServicePKey& rhs );
		bool operator ==( const CFSecServiceHPKey& rhs );
		bool operator ==( const CFSecServiceHBuff& rhs );
		bool operator ==( const CFSecServiceBuff& rhs );


		bool operator !=( const CFSecServicePKey& rhs );
		bool operator !=( const CFSecServiceHPKey& rhs );
		bool operator !=( const CFSecServiceHBuff& rhs );
		bool operator !=( const CFSecServiceBuff& rhs );


		bool operator >=( const CFSecServicePKey& rhs );
		bool operator >=( const CFSecServiceHPKey& rhs );
		bool operator >=( const CFSecServiceHBuff& rhs );
		bool operator >=( const CFSecServiceBuff& rhs );


		bool operator >( const CFSecServicePKey& rhs );
		bool operator >( const CFSecServiceHPKey& rhs );
		bool operator >( const CFSecServiceHBuff& rhs );
		bool operator >( const CFSecServiceBuff& rhs );

		cfsec::CFSecServiceHPKey operator =( cfsec::CFSecServicePKey& src );
		cfsec::CFSecServiceHPKey operator =( cfsec::CFSecServiceHPKey& src );
		cfsec::CFSecServiceHPKey operator =( cfsec::CFSecServiceBuff& src );
		cfsec::CFSecServiceHPKey operator =( cfsec::CFSecServiceHBuff& src );

	};
}


namespace std {

	bool operator <(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator <(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator <(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator <(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceBuff& rhs );


	bool operator <=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator <=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceBuff& rhs );


	bool operator ==(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator ==(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceBuff& rhs );


	bool operator !=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator !=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceBuff& rhs );


	bool operator >=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator >=(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceBuff& rhs );


	bool operator >(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServicePKey& rhs );
	bool operator >(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHPKey& rhs );
	bool operator >(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceHBuff& rhs );
	bool operator >(const  cfsec::CFSecServiceHPKey& lhs, const cfsec::CFSecServiceBuff& rhs );


	template<> struct hash<cfsec::CFSecServiceHPKey> {
		typedef cfsec::CFSecServiceHPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

