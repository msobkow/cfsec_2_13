#pragma once

// Description: C++18 specification of a SecApp history buffer object.

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

	class CFSecSecAppBuff;
	class CFSecSecAppPKey;
	class CFSecSecAppHPKey;
	class CFSecSecAppByClusterIdxKey;
	class CFSecSecAppByUJEEMountIdxKey;

	class CFSecSecAppHBuff : public CFSecHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int64_t requiredClusterId;
		int32_t requiredSecAppId;
		std::string* requiredJEEMountName;		classcode_t classCode;

	public:
		CFSecSecAppHBuff();
		CFSecSecAppHBuff( const CFSecSecAppHBuff& src );
		virtual ~CFSecSecAppHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const int32_t getRequiredSecAppId() const;
		virtual const int32_t* getRequiredSecAppIdReference() const;
		virtual void setRequiredSecAppId( const int32_t value );

		virtual const std::string& getRequiredJEEMountName() const;
		virtual const std::string* getRequiredJEEMountNameReference() const;
		virtual void setRequiredJEEMountName( const std::string& value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecSecAppByClusterIdxKey& rhs );
		bool operator <( const CFSecSecAppByUJEEMountIdxKey& rhs );
		bool operator <( const CFSecSecAppPKey& rhs );
		bool operator <( const CFSecSecAppHPKey& rhs );
		bool operator <( const CFSecSecAppHBuff& rhs );
		bool operator <( const CFSecSecAppBuff& rhs );

		bool operator <=( const CFSecSecAppByClusterIdxKey& rhs );
		bool operator <=( const CFSecSecAppByUJEEMountIdxKey& rhs );
		bool operator <=( const CFSecSecAppPKey& rhs );
		bool operator <=( const CFSecSecAppHPKey& rhs );
		bool operator <=( const CFSecSecAppHBuff& rhs );
		bool operator <=( const CFSecSecAppBuff& rhs );

		bool operator ==( const CFSecSecAppByClusterIdxKey& rhs );
		bool operator ==( const CFSecSecAppByUJEEMountIdxKey& rhs );
		bool operator ==( const CFSecSecAppPKey& rhs );
		bool operator ==( const CFSecSecAppHPKey& rhs );
		bool operator ==( const CFSecSecAppHBuff& rhs );
		bool operator ==( const CFSecSecAppBuff& rhs );

		bool operator !=( const CFSecSecAppByClusterIdxKey& rhs );
		bool operator !=( const CFSecSecAppByUJEEMountIdxKey& rhs );
		bool operator !=( const CFSecSecAppPKey& rhs );
		bool operator !=( const CFSecSecAppHPKey& rhs );
		bool operator !=( const CFSecSecAppHBuff& rhs );
		bool operator !=( const CFSecSecAppBuff& rhs );

		bool operator >=( const CFSecSecAppByClusterIdxKey& rhs );
		bool operator >=( const CFSecSecAppByUJEEMountIdxKey& rhs );
		bool operator >=( const CFSecSecAppPKey& rhs );
		bool operator >=( const CFSecSecAppHPKey& rhs );
		bool operator >=( const CFSecSecAppHBuff& rhs );
		bool operator >=( const CFSecSecAppBuff& rhs );

		bool operator >( const CFSecSecAppByClusterIdxKey& rhs );
		bool operator >( const CFSecSecAppByUJEEMountIdxKey& rhs );
		bool operator >( const CFSecSecAppPKey& rhs );
		bool operator >( const CFSecSecAppHPKey& rhs );
		bool operator >( const CFSecSecAppHBuff& rhs );
		bool operator >( const CFSecSecAppBuff& rhs );
		cfsec::CFSecSecAppHBuff operator =( cfsec::CFSecSecAppBuff& src );
		cfsec::CFSecSecAppHBuff operator =( cfsec::CFSecSecAppHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppByClusterIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppPKey& rhs );
	bool operator <(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppHPKey& rhs );
	bool operator <(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppByClusterIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppByClusterIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppByClusterIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppByClusterIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppBuff& rhs );

	bool operator >(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppByClusterIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppPKey& rhs );
	bool operator >(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppHPKey& rhs );
	bool operator >(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecAppHBuff& lhs, const cfsec::CFSecSecAppBuff& rhs );

	template<> struct hash<cfsec::CFSecSecAppHBuff> {
		typedef cfsec::CFSecSecAppHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

