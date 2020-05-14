#pragma once

// Description: C++18 specification for a SecUser by DefDevIdx index key object.

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

	class CFSecSecUserByDefDevIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		uuid_t optionalDfltDevUserId;
		std::string* optionalDfltDevName;
	public:
		CFSecSecUserByDefDevIdxKey();
		CFSecSecUserByDefDevIdxKey( const CFSecSecUserByDefDevIdxKey& src );
		virtual ~CFSecSecUserByDefDevIdxKey();

		virtual const uuid_ptr_t getOptionalDfltDevUserIdValue() const;
		virtual const uuid_ptr_t getOptionalDfltDevUserIdReference() const;
		virtual const bool isOptionalDfltDevUserIdNull() const;
		virtual void setOptionalDfltDevUserIdNull();
		virtual void setOptionalDfltDevUserIdValue( const uuid_ptr_t value );
		virtual void generateOptionalDfltDevUserId();

		virtual const std::string& getOptionalDfltDevNameValue() const;
		virtual const std::string* getOptionalDfltDevNameReference() const;
		virtual const bool isOptionalDfltDevNameNull() const;
		virtual void setOptionalDfltDevNameNull();
		virtual void setOptionalDfltDevNameValue( const std::string& value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecSecUserByDefDevIdxKey& rhs );
		bool operator <( const CFSecSecUserHBuff& rhs );
		bool operator <( const CFSecSecUserBuff& rhs );

		bool operator <=( const CFSecSecUserByDefDevIdxKey& rhs );
		bool operator <=( const CFSecSecUserHBuff& rhs );
		bool operator <=( const CFSecSecUserBuff& rhs );

		bool operator ==( const CFSecSecUserByDefDevIdxKey& rhs );
		bool operator ==( const CFSecSecUserHBuff& rhs );
		bool operator ==( const CFSecSecUserBuff& rhs );

		bool operator !=( const CFSecSecUserByDefDevIdxKey& rhs );
		bool operator !=( const CFSecSecUserHBuff& rhs );
		bool operator !=( const CFSecSecUserBuff& rhs );

		bool operator >=( const CFSecSecUserByDefDevIdxKey& rhs );
		bool operator >=( const CFSecSecUserHBuff& rhs );
		bool operator >=( const CFSecSecUserBuff& rhs );

		bool operator >( const CFSecSecUserByDefDevIdxKey& rhs );
		bool operator >( const CFSecSecUserHBuff& rhs );
		bool operator >( const CFSecSecUserBuff& rhs );
		cfsec::CFSecSecUserByDefDevIdxKey operator =( cfsec::CFSecSecUserByDefDevIdxKey& src );
		cfsec::CFSecSecUserByDefDevIdxKey operator =( cfsec::CFSecSecUserBuff& src );
		cfsec::CFSecSecUserByDefDevIdxKey operator =( cfsec::CFSecSecUserHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	bool operator >(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecUserByDefDevIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs );

	template<> struct hash<cfsec::CFSecSecUserByDefDevIdxKey> {
		typedef cfsec::CFSecSecUserByDefDevIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

