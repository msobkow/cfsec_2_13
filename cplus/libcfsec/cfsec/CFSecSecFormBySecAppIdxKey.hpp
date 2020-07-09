#pragma once

// Description: C++18 specification for a SecForm by SecAppIdx index key object.

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

	class CFSecSecFormBuff;
	class CFSecSecFormHBuff;

	class CFSecSecFormBySecAppIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int64_t requiredClusterId;
		int32_t requiredSecAppId;
	public:
		CFSecSecFormBySecAppIdxKey();
		CFSecSecFormBySecAppIdxKey( const CFSecSecFormBySecAppIdxKey& src );
		virtual ~CFSecSecFormBySecAppIdxKey();

		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const int32_t getRequiredSecAppId() const;
		virtual const int32_t* getRequiredSecAppIdReference() const;
		virtual void setRequiredSecAppId( const int32_t value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecSecFormBySecAppIdxKey& rhs );
		bool operator <( const CFSecSecFormHBuff& rhs );
		bool operator <( const CFSecSecFormBuff& rhs );

		bool operator <=( const CFSecSecFormBySecAppIdxKey& rhs );
		bool operator <=( const CFSecSecFormHBuff& rhs );
		bool operator <=( const CFSecSecFormBuff& rhs );

		bool operator ==( const CFSecSecFormBySecAppIdxKey& rhs );
		bool operator ==( const CFSecSecFormHBuff& rhs );
		bool operator ==( const CFSecSecFormBuff& rhs );

		bool operator !=( const CFSecSecFormBySecAppIdxKey& rhs );
		bool operator !=( const CFSecSecFormHBuff& rhs );
		bool operator !=( const CFSecSecFormBuff& rhs );

		bool operator >=( const CFSecSecFormBySecAppIdxKey& rhs );
		bool operator >=( const CFSecSecFormHBuff& rhs );
		bool operator >=( const CFSecSecFormBuff& rhs );

		bool operator >( const CFSecSecFormBySecAppIdxKey& rhs );
		bool operator >( const CFSecSecFormHBuff& rhs );
		bool operator >( const CFSecSecFormBuff& rhs );
		cfsec::CFSecSecFormBySecAppIdxKey operator =( cfsec::CFSecSecFormBySecAppIdxKey& src );
		cfsec::CFSecSecFormBySecAppIdxKey operator =( cfsec::CFSecSecFormBuff& src );
		cfsec::CFSecSecFormBySecAppIdxKey operator =( cfsec::CFSecSecFormHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBySecAppIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBySecAppIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBySecAppIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBySecAppIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBySecAppIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBuff& rhs );

	bool operator >(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBySecAppIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBuff& rhs );

	template<> struct hash<cfsec::CFSecSecFormBySecAppIdxKey> {
		typedef cfsec::CFSecSecFormBySecAppIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

