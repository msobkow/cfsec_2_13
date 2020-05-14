#pragma once

// Description: C++18 specification of a SecGroup history primary key object.

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

#include <cfsec/CFSecHPKey.hpp>
#include <cfsec/ICFSecSchema.hpp>

namespace cfsec {

	class CFSecSecGroupPKey;
	class CFSecSecGroupBuff;
	class CFSecSecGroupHBuff;

	class CFSecSecGroupHPKey : public CFSecHPKey
	{
	protected:

		int64_t requiredClusterId;
		int32_t requiredSecGroupId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;

		CFSecSecGroupHPKey();
		CFSecSecGroupHPKey( const CFSecSecGroupHPKey& src );
		virtual ~CFSecSecGroupHPKey();

		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const int32_t getRequiredSecGroupId() const;
		virtual const int32_t* getRequiredSecGroupIdReference() const;
		virtual void setRequiredSecGroupId( const int32_t value );

		virtual size_t hashCode() const;

		virtual std::string toString();

		bool operator <( const CFSecSecGroupPKey& rhs );
		bool operator <( const CFSecSecGroupHPKey& rhs );
		bool operator <( const CFSecSecGroupHBuff& rhs );
		bool operator <( const CFSecSecGroupBuff& rhs );


		bool operator <=( const CFSecSecGroupPKey& rhs );
		bool operator <=( const CFSecSecGroupHPKey& rhs );
		bool operator <=( const CFSecSecGroupHBuff& rhs );
		bool operator <=( const CFSecSecGroupBuff& rhs );


		bool operator ==( const CFSecSecGroupPKey& rhs );
		bool operator ==( const CFSecSecGroupHPKey& rhs );
		bool operator ==( const CFSecSecGroupHBuff& rhs );
		bool operator ==( const CFSecSecGroupBuff& rhs );


		bool operator !=( const CFSecSecGroupPKey& rhs );
		bool operator !=( const CFSecSecGroupHPKey& rhs );
		bool operator !=( const CFSecSecGroupHBuff& rhs );
		bool operator !=( const CFSecSecGroupBuff& rhs );


		bool operator >=( const CFSecSecGroupPKey& rhs );
		bool operator >=( const CFSecSecGroupHPKey& rhs );
		bool operator >=( const CFSecSecGroupHBuff& rhs );
		bool operator >=( const CFSecSecGroupBuff& rhs );


		bool operator >( const CFSecSecGroupPKey& rhs );
		bool operator >( const CFSecSecGroupHPKey& rhs );
		bool operator >( const CFSecSecGroupHBuff& rhs );
		bool operator >( const CFSecSecGroupBuff& rhs );

		cfsec::CFSecSecGroupHPKey operator =( cfsec::CFSecSecGroupPKey& src );
		cfsec::CFSecSecGroupHPKey operator =( cfsec::CFSecSecGroupHPKey& src );
		cfsec::CFSecSecGroupHPKey operator =( cfsec::CFSecSecGroupBuff& src );
		cfsec::CFSecSecGroupHPKey operator =( cfsec::CFSecSecGroupHBuff& src );

	};
}


namespace std {

	bool operator <(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupPKey& rhs );
	bool operator <(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupHPKey& rhs );
	bool operator <(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupBuff& rhs );


	bool operator <=(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupBuff& rhs );


	bool operator ==(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupBuff& rhs );


	bool operator !=(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupBuff& rhs );


	bool operator >=(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupBuff& rhs );


	bool operator >(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupPKey& rhs );
	bool operator >(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupHPKey& rhs );
	bool operator >(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecGroupHPKey& lhs, const cfsec::CFSecSecGroupBuff& rhs );


	template<> struct hash<cfsec::CFSecSecGroupHPKey> {
		typedef cfsec::CFSecSecGroupHPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

