#pragma once

// Description: C++18 specification of a Cluster history primary key object.

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

	class CFSecClusterPKey;
	class CFSecClusterBuff;
	class CFSecClusterHBuff;

	class CFSecClusterHPKey : public CFSecHPKey
	{
	protected:

		int64_t requiredId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;

		CFSecClusterHPKey();
		CFSecClusterHPKey( const CFSecClusterHPKey& src );
		virtual ~CFSecClusterHPKey();

		virtual const int64_t getRequiredId() const;
		virtual const int64_t* getRequiredIdReference() const;
		virtual void setRequiredId( const int64_t value );

		virtual size_t hashCode() const;

		virtual std::string toString();

		bool operator <( const CFSecClusterPKey& rhs );
		bool operator <( const CFSecClusterHPKey& rhs );
		bool operator <( const CFSecClusterHBuff& rhs );
		bool operator <( const CFSecClusterBuff& rhs );


		bool operator <=( const CFSecClusterPKey& rhs );
		bool operator <=( const CFSecClusterHPKey& rhs );
		bool operator <=( const CFSecClusterHBuff& rhs );
		bool operator <=( const CFSecClusterBuff& rhs );


		bool operator ==( const CFSecClusterPKey& rhs );
		bool operator ==( const CFSecClusterHPKey& rhs );
		bool operator ==( const CFSecClusterHBuff& rhs );
		bool operator ==( const CFSecClusterBuff& rhs );


		bool operator !=( const CFSecClusterPKey& rhs );
		bool operator !=( const CFSecClusterHPKey& rhs );
		bool operator !=( const CFSecClusterHBuff& rhs );
		bool operator !=( const CFSecClusterBuff& rhs );


		bool operator >=( const CFSecClusterPKey& rhs );
		bool operator >=( const CFSecClusterHPKey& rhs );
		bool operator >=( const CFSecClusterHBuff& rhs );
		bool operator >=( const CFSecClusterBuff& rhs );


		bool operator >( const CFSecClusterPKey& rhs );
		bool operator >( const CFSecClusterHPKey& rhs );
		bool operator >( const CFSecClusterHBuff& rhs );
		bool operator >( const CFSecClusterBuff& rhs );

		cfsec::CFSecClusterHPKey operator =( cfsec::CFSecClusterPKey& src );
		cfsec::CFSecClusterHPKey operator =( cfsec::CFSecClusterHPKey& src );
		cfsec::CFSecClusterHPKey operator =( cfsec::CFSecClusterBuff& src );
		cfsec::CFSecClusterHPKey operator =( cfsec::CFSecClusterHBuff& src );

	};
}


namespace std {

	bool operator <(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterPKey& rhs );
	bool operator <(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterHPKey& rhs );
	bool operator <(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator <(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterBuff& rhs );


	bool operator <=(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterPKey& rhs );
	bool operator <=(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterHPKey& rhs );
	bool operator <=(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator <=(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterBuff& rhs );


	bool operator ==(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterPKey& rhs );
	bool operator ==(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterHPKey& rhs );
	bool operator ==(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator ==(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterBuff& rhs );


	bool operator !=(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterPKey& rhs );
	bool operator !=(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterHPKey& rhs );
	bool operator !=(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator !=(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterBuff& rhs );


	bool operator >=(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterPKey& rhs );
	bool operator >=(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterHPKey& rhs );
	bool operator >=(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator >=(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterBuff& rhs );


	bool operator >(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterPKey& rhs );
	bool operator >(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterHPKey& rhs );
	bool operator >(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator >(const  cfsec::CFSecClusterHPKey& lhs, const cfsec::CFSecClusterBuff& rhs );


	template<> struct hash<cfsec::CFSecClusterHPKey> {
		typedef cfsec::CFSecClusterHPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

