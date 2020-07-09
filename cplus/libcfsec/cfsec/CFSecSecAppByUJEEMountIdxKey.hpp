#pragma once

// Description: C++18 specification for a SecApp by UJEEMountIdx index key object.

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

	class CFSecSecAppBuff;
	class CFSecSecAppHBuff;

	class CFSecSecAppByUJEEMountIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int64_t requiredClusterId;
		std::string* requiredJEEMountName;
	public:
		CFSecSecAppByUJEEMountIdxKey();
		CFSecSecAppByUJEEMountIdxKey( const CFSecSecAppByUJEEMountIdxKey& src );
		virtual ~CFSecSecAppByUJEEMountIdxKey();

		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const std::string& getRequiredJEEMountName() const;
		virtual const std::string* getRequiredJEEMountNameReference() const;
		virtual void setRequiredJEEMountName( const std::string& value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecSecAppByUJEEMountIdxKey& rhs );
		bool operator <( const CFSecSecAppHBuff& rhs );
		bool operator <( const CFSecSecAppBuff& rhs );

		bool operator <=( const CFSecSecAppByUJEEMountIdxKey& rhs );
		bool operator <=( const CFSecSecAppHBuff& rhs );
		bool operator <=( const CFSecSecAppBuff& rhs );

		bool operator ==( const CFSecSecAppByUJEEMountIdxKey& rhs );
		bool operator ==( const CFSecSecAppHBuff& rhs );
		bool operator ==( const CFSecSecAppBuff& rhs );

		bool operator !=( const CFSecSecAppByUJEEMountIdxKey& rhs );
		bool operator !=( const CFSecSecAppHBuff& rhs );
		bool operator !=( const CFSecSecAppBuff& rhs );

		bool operator >=( const CFSecSecAppByUJEEMountIdxKey& rhs );
		bool operator >=( const CFSecSecAppHBuff& rhs );
		bool operator >=( const CFSecSecAppBuff& rhs );

		bool operator >( const CFSecSecAppByUJEEMountIdxKey& rhs );
		bool operator >( const CFSecSecAppHBuff& rhs );
		bool operator >( const CFSecSecAppBuff& rhs );
		cfsec::CFSecSecAppByUJEEMountIdxKey operator =( cfsec::CFSecSecAppByUJEEMountIdxKey& src );
		cfsec::CFSecSecAppByUJEEMountIdxKey operator =( cfsec::CFSecSecAppBuff& src );
		cfsec::CFSecSecAppByUJEEMountIdxKey operator =( cfsec::CFSecSecAppHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppBuff& rhs );

	bool operator >(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppBuff& rhs );

	template<> struct hash<cfsec::CFSecSecAppByUJEEMountIdxKey> {
		typedef cfsec::CFSecSecAppByUJEEMountIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

