#pragma once

// Description: C++18 specification of a SecApp history primary key object.

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

	class CFSecSecAppPKey;
	class CFSecSecAppBuff;
	class CFSecSecAppHBuff;

	class CFSecSecAppHPKey : public CFSecHPKey
	{
	protected:

		int64_t requiredClusterId;
		int32_t requiredSecAppId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;

		CFSecSecAppHPKey();
		CFSecSecAppHPKey( const CFSecSecAppHPKey& src );
		virtual ~CFSecSecAppHPKey();

		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const int32_t getRequiredSecAppId() const;
		virtual const int32_t* getRequiredSecAppIdReference() const;
		virtual void setRequiredSecAppId( const int32_t value );

		virtual size_t hashCode() const;

		virtual std::string toString();

		bool operator <( const CFSecSecAppPKey& rhs );
		bool operator <( const CFSecSecAppHPKey& rhs );
		bool operator <( const CFSecSecAppHBuff& rhs );
		bool operator <( const CFSecSecAppBuff& rhs );


		bool operator <=( const CFSecSecAppPKey& rhs );
		bool operator <=( const CFSecSecAppHPKey& rhs );
		bool operator <=( const CFSecSecAppHBuff& rhs );
		bool operator <=( const CFSecSecAppBuff& rhs );


		bool operator ==( const CFSecSecAppPKey& rhs );
		bool operator ==( const CFSecSecAppHPKey& rhs );
		bool operator ==( const CFSecSecAppHBuff& rhs );
		bool operator ==( const CFSecSecAppBuff& rhs );


		bool operator !=( const CFSecSecAppPKey& rhs );
		bool operator !=( const CFSecSecAppHPKey& rhs );
		bool operator !=( const CFSecSecAppHBuff& rhs );
		bool operator !=( const CFSecSecAppBuff& rhs );


		bool operator >=( const CFSecSecAppPKey& rhs );
		bool operator >=( const CFSecSecAppHPKey& rhs );
		bool operator >=( const CFSecSecAppHBuff& rhs );
		bool operator >=( const CFSecSecAppBuff& rhs );


		bool operator >( const CFSecSecAppPKey& rhs );
		bool operator >( const CFSecSecAppHPKey& rhs );
		bool operator >( const CFSecSecAppHBuff& rhs );
		bool operator >( const CFSecSecAppBuff& rhs );

		cfsec::CFSecSecAppHPKey operator =( cfsec::CFSecSecAppPKey& src );
		cfsec::CFSecSecAppHPKey operator =( cfsec::CFSecSecAppHPKey& src );
		cfsec::CFSecSecAppHPKey operator =( cfsec::CFSecSecAppBuff& src );
		cfsec::CFSecSecAppHPKey operator =( cfsec::CFSecSecAppHBuff& src );

	};
}


namespace std {

	bool operator <(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppPKey& rhs );
	bool operator <(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppHPKey& rhs );
	bool operator <(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppBuff& rhs );


	bool operator <=(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppBuff& rhs );


	bool operator ==(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppBuff& rhs );


	bool operator !=(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppBuff& rhs );


	bool operator >=(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppBuff& rhs );


	bool operator >(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppPKey& rhs );
	bool operator >(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppHPKey& rhs );
	bool operator >(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecAppHPKey& lhs, const cfsec::CFSecSecAppBuff& rhs );


	template<> struct hash<cfsec::CFSecSecAppHPKey> {
		typedef cfsec::CFSecSecAppHPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

