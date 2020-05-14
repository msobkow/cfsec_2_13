#pragma once

// Description: C++18 specification of a Cluster primary key object.

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

	class CFSecClusterBuff;
	class CFSecClusterHPKey;
	class CFSecClusterHBuff;

	class CFSecClusterPKey
	{
	protected:

		int64_t requiredId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;

		CFSecClusterPKey();
		CFSecClusterPKey( const CFSecClusterPKey& src );
		virtual ~CFSecClusterPKey();

		virtual const int64_t getRequiredId() const;
		virtual const int64_t* getRequiredIdReference() const;
		virtual void setRequiredId( const int64_t value );

		bool operator <( const CFSecClusterHPKey& rhs );
		bool operator <( const CFSecClusterPKey& rhs );
		bool operator <( const CFSecClusterHBuff& rhs );
		bool operator <( const CFSecClusterBuff& rhs );

		bool operator <=( const CFSecClusterHPKey& rhs );
		bool operator <=( const CFSecClusterPKey& rhs );
		bool operator <=( const CFSecClusterHBuff& rhs );
		bool operator <=( const CFSecClusterBuff& rhs );

		bool operator ==( const CFSecClusterHPKey& rhs );
		bool operator ==( const CFSecClusterPKey& rhs );
		bool operator ==( const CFSecClusterHBuff& rhs );
		bool operator ==( const CFSecClusterBuff& rhs );

		bool operator !=( const CFSecClusterHPKey& rhs );
		bool operator !=( const CFSecClusterPKey& rhs );
		bool operator !=( const CFSecClusterHBuff& rhs );
		bool operator !=( const CFSecClusterBuff& rhs );

		bool operator >=( const CFSecClusterHPKey& rhs );
		bool operator >=( const CFSecClusterPKey& rhs );
		bool operator >=( const CFSecClusterHBuff& rhs );
		bool operator >=( const CFSecClusterBuff& rhs );

		bool operator >( const CFSecClusterHPKey& rhs );
		bool operator >( const CFSecClusterPKey& rhs );
		bool operator >( const CFSecClusterHBuff& rhs );
		bool operator >( const CFSecClusterBuff& rhs );
		virtual size_t hashCode() const;

		virtual std::string toString();

		cfsec::CFSecClusterPKey operator =( cfsec::CFSecClusterPKey& src );
		cfsec::CFSecClusterPKey operator =( cfsec::CFSecClusterHPKey& src );
		cfsec::CFSecClusterPKey operator =( cfsec::CFSecClusterBuff& src );
		cfsec::CFSecClusterPKey operator =( cfsec::CFSecClusterHBuff& src );
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterHPKey& rhs );
	bool operator <(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterPKey& rhs );
	bool operator <(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator <(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterBuff& rhs );

	bool operator <=(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterHPKey& rhs );
	bool operator <=(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterPKey& rhs );
	bool operator <=(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator <=(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterBuff& rhs );

	bool operator ==(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterHPKey& rhs );
	bool operator ==(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterPKey& rhs );
	bool operator ==(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator ==(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterBuff& rhs );

	bool operator !=(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterHPKey& rhs );
	bool operator !=(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterPKey& rhs );
	bool operator !=(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator !=(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterBuff& rhs );

	bool operator >=(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterHPKey& rhs );
	bool operator >=(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterPKey& rhs );
	bool operator >=(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator >=(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterBuff& rhs );

	bool operator >(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterHPKey& rhs );
	bool operator >(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterPKey& rhs );
	bool operator >(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterHBuff& rhs );
	bool operator >(const  cfsec::CFSecClusterPKey& lhs, const cfsec::CFSecClusterBuff& rhs );

	template<> struct hash<cfsec::CFSecClusterPKey> {
		typedef cfsec::CFSecClusterPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

