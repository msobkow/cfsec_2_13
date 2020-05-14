#pragma once

// Description: C++18 specification of a SecUser primary key object.

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

	class CFSecSecUserBuff;
	class CFSecSecUserHPKey;
	class CFSecSecUserHBuff;

	class CFSecSecUserPKey
	{
	protected:

		uuid_t requiredSecUserId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;

		CFSecSecUserPKey();
		CFSecSecUserPKey( const CFSecSecUserPKey& src );
		virtual ~CFSecSecUserPKey();

		virtual const uuid_ptr_t getRequiredSecUserId() const;
		virtual const uuid_ptr_t getRequiredSecUserIdReference() const;
		virtual void setRequiredSecUserId( const uuid_ptr_t value );
		virtual void generateRequiredSecUserId();

		bool operator <( const CFSecSecUserHPKey& rhs );
		bool operator <( const CFSecSecUserPKey& rhs );
		bool operator <( const CFSecSecUserHBuff& rhs );
		bool operator <( const CFSecSecUserBuff& rhs );

		bool operator <=( const CFSecSecUserHPKey& rhs );
		bool operator <=( const CFSecSecUserPKey& rhs );
		bool operator <=( const CFSecSecUserHBuff& rhs );
		bool operator <=( const CFSecSecUserBuff& rhs );

		bool operator ==( const CFSecSecUserHPKey& rhs );
		bool operator ==( const CFSecSecUserPKey& rhs );
		bool operator ==( const CFSecSecUserHBuff& rhs );
		bool operator ==( const CFSecSecUserBuff& rhs );

		bool operator !=( const CFSecSecUserHPKey& rhs );
		bool operator !=( const CFSecSecUserPKey& rhs );
		bool operator !=( const CFSecSecUserHBuff& rhs );
		bool operator !=( const CFSecSecUserBuff& rhs );

		bool operator >=( const CFSecSecUserHPKey& rhs );
		bool operator >=( const CFSecSecUserPKey& rhs );
		bool operator >=( const CFSecSecUserHBuff& rhs );
		bool operator >=( const CFSecSecUserBuff& rhs );

		bool operator >( const CFSecSecUserHPKey& rhs );
		bool operator >( const CFSecSecUserPKey& rhs );
		bool operator >( const CFSecSecUserHBuff& rhs );
		bool operator >( const CFSecSecUserBuff& rhs );
		virtual size_t hashCode() const;

		virtual std::string toString();

		cfsec::CFSecSecUserPKey operator =( cfsec::CFSecSecUserPKey& src );
		cfsec::CFSecSecUserPKey operator =( cfsec::CFSecSecUserHPKey& src );
		cfsec::CFSecSecUserPKey operator =( cfsec::CFSecSecUserBuff& src );
		cfsec::CFSecSecUserPKey operator =( cfsec::CFSecSecUserHBuff& src );
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserHPKey& rhs );
	bool operator <(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserPKey& rhs );
	bool operator <(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator >(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserHPKey& rhs );
	bool operator >(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserPKey& rhs );
	bool operator >(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecUserPKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	template<> struct hash<cfsec::CFSecSecUserPKey> {
		typedef cfsec::CFSecSecUserPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

