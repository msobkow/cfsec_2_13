#pragma once

// Description: C++18 specification of a TSecGroup primary key object.

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

	class CFSecTSecGroupBuff;
	class CFSecTSecGroupHPKey;
	class CFSecTSecGroupHBuff;

	class CFSecTSecGroupPKey
	{
	protected:

		int64_t requiredTenantId;
		int32_t requiredTSecGroupId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;

		CFSecTSecGroupPKey();
		CFSecTSecGroupPKey( const CFSecTSecGroupPKey& src );
		virtual ~CFSecTSecGroupPKey();

		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const int32_t getRequiredTSecGroupId() const;
		virtual const int32_t* getRequiredTSecGroupIdReference() const;
		virtual void setRequiredTSecGroupId( const int32_t value );

		bool operator <( const CFSecTSecGroupHPKey& rhs );
		bool operator <( const CFSecTSecGroupPKey& rhs );
		bool operator <( const CFSecTSecGroupHBuff& rhs );
		bool operator <( const CFSecTSecGroupBuff& rhs );

		bool operator <=( const CFSecTSecGroupHPKey& rhs );
		bool operator <=( const CFSecTSecGroupPKey& rhs );
		bool operator <=( const CFSecTSecGroupHBuff& rhs );
		bool operator <=( const CFSecTSecGroupBuff& rhs );

		bool operator ==( const CFSecTSecGroupHPKey& rhs );
		bool operator ==( const CFSecTSecGroupPKey& rhs );
		bool operator ==( const CFSecTSecGroupHBuff& rhs );
		bool operator ==( const CFSecTSecGroupBuff& rhs );

		bool operator !=( const CFSecTSecGroupHPKey& rhs );
		bool operator !=( const CFSecTSecGroupPKey& rhs );
		bool operator !=( const CFSecTSecGroupHBuff& rhs );
		bool operator !=( const CFSecTSecGroupBuff& rhs );

		bool operator >=( const CFSecTSecGroupHPKey& rhs );
		bool operator >=( const CFSecTSecGroupPKey& rhs );
		bool operator >=( const CFSecTSecGroupHBuff& rhs );
		bool operator >=( const CFSecTSecGroupBuff& rhs );

		bool operator >( const CFSecTSecGroupHPKey& rhs );
		bool operator >( const CFSecTSecGroupPKey& rhs );
		bool operator >( const CFSecTSecGroupHBuff& rhs );
		bool operator >( const CFSecTSecGroupBuff& rhs );
		virtual size_t hashCode() const;

		virtual std::string toString();

		cfsec::CFSecTSecGroupPKey operator =( cfsec::CFSecTSecGroupPKey& src );
		cfsec::CFSecTSecGroupPKey operator =( cfsec::CFSecTSecGroupHPKey& src );
		cfsec::CFSecTSecGroupPKey operator =( cfsec::CFSecTSecGroupBuff& src );
		cfsec::CFSecTSecGroupPKey operator =( cfsec::CFSecTSecGroupHBuff& src );
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHPKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupPKey& rhs );
	bool operator <(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator <(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	bool operator <=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHPKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupPKey& rhs );
	bool operator <=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator <=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	bool operator ==(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHPKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupPKey& rhs );
	bool operator ==(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator ==(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	bool operator !=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHPKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupPKey& rhs );
	bool operator !=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator !=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	bool operator >=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHPKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupPKey& rhs );
	bool operator >=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator >=(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	bool operator >(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHPKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupPKey& rhs );
	bool operator >(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs );
	bool operator >(const  cfsec::CFSecTSecGroupPKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs );

	template<> struct hash<cfsec::CFSecTSecGroupPKey> {
		typedef cfsec::CFSecTSecGroupPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

