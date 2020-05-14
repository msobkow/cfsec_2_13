#pragma once

// Description: C++18 specification for a SecUser by ULoginIdx index key object.

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
	class CFSecSecUserHBuff;

	class CFSecSecUserByULoginIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		std::string* requiredLoginId;
	public:
		CFSecSecUserByULoginIdxKey();
		CFSecSecUserByULoginIdxKey( const CFSecSecUserByULoginIdxKey& src );
		virtual ~CFSecSecUserByULoginIdxKey();

		virtual const std::string& getRequiredLoginId() const;
		virtual const std::string* getRequiredLoginIdReference() const;
		virtual void setRequiredLoginId( const std::string& value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecSecUserByULoginIdxKey& rhs );
		bool operator <( const CFSecSecUserHBuff& rhs );
		bool operator <( const CFSecSecUserBuff& rhs );

		bool operator <=( const CFSecSecUserByULoginIdxKey& rhs );
		bool operator <=( const CFSecSecUserHBuff& rhs );
		bool operator <=( const CFSecSecUserBuff& rhs );

		bool operator ==( const CFSecSecUserByULoginIdxKey& rhs );
		bool operator ==( const CFSecSecUserHBuff& rhs );
		bool operator ==( const CFSecSecUserBuff& rhs );

		bool operator !=( const CFSecSecUserByULoginIdxKey& rhs );
		bool operator !=( const CFSecSecUserHBuff& rhs );
		bool operator !=( const CFSecSecUserBuff& rhs );

		bool operator >=( const CFSecSecUserByULoginIdxKey& rhs );
		bool operator >=( const CFSecSecUserHBuff& rhs );
		bool operator >=( const CFSecSecUserBuff& rhs );

		bool operator >( const CFSecSecUserByULoginIdxKey& rhs );
		bool operator >( const CFSecSecUserHBuff& rhs );
		bool operator >( const CFSecSecUserBuff& rhs );
		cfsec::CFSecSecUserByULoginIdxKey operator =( cfsec::CFSecSecUserByULoginIdxKey& src );
		cfsec::CFSecSecUserByULoginIdxKey operator =( cfsec::CFSecSecUserBuff& src );
		cfsec::CFSecSecUserByULoginIdxKey operator =( cfsec::CFSecSecUserHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator >(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	template<> struct hash<cfsec::CFSecSecUserByULoginIdxKey> {
		typedef cfsec::CFSecSecUserByULoginIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

