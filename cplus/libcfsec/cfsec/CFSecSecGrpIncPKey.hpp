#pragma once

// Description: C++18 specification of a SecGrpInc primary key object.

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

	class CFSecSecGrpIncBuff;
	class CFSecSecGrpIncHPKey;
	class CFSecSecGrpIncHBuff;

	class CFSecSecGrpIncPKey
	{
	protected:

		int64_t requiredClusterId;
		int64_t requiredSecGrpIncId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;

		CFSecSecGrpIncPKey();
		CFSecSecGrpIncPKey( const CFSecSecGrpIncPKey& src );
		virtual ~CFSecSecGrpIncPKey();

		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const int64_t getRequiredSecGrpIncId() const;
		virtual const int64_t* getRequiredSecGrpIncIdReference() const;
		virtual void setRequiredSecGrpIncId( const int64_t value );

		bool operator <( const CFSecSecGrpIncHPKey& rhs );
		bool operator <( const CFSecSecGrpIncPKey& rhs );
		bool operator <( const CFSecSecGrpIncHBuff& rhs );
		bool operator <( const CFSecSecGrpIncBuff& rhs );

		bool operator <=( const CFSecSecGrpIncHPKey& rhs );
		bool operator <=( const CFSecSecGrpIncPKey& rhs );
		bool operator <=( const CFSecSecGrpIncHBuff& rhs );
		bool operator <=( const CFSecSecGrpIncBuff& rhs );

		bool operator ==( const CFSecSecGrpIncHPKey& rhs );
		bool operator ==( const CFSecSecGrpIncPKey& rhs );
		bool operator ==( const CFSecSecGrpIncHBuff& rhs );
		bool operator ==( const CFSecSecGrpIncBuff& rhs );

		bool operator !=( const CFSecSecGrpIncHPKey& rhs );
		bool operator !=( const CFSecSecGrpIncPKey& rhs );
		bool operator !=( const CFSecSecGrpIncHBuff& rhs );
		bool operator !=( const CFSecSecGrpIncBuff& rhs );

		bool operator >=( const CFSecSecGrpIncHPKey& rhs );
		bool operator >=( const CFSecSecGrpIncPKey& rhs );
		bool operator >=( const CFSecSecGrpIncHBuff& rhs );
		bool operator >=( const CFSecSecGrpIncBuff& rhs );

		bool operator >( const CFSecSecGrpIncHPKey& rhs );
		bool operator >( const CFSecSecGrpIncPKey& rhs );
		bool operator >( const CFSecSecGrpIncHBuff& rhs );
		bool operator >( const CFSecSecGrpIncBuff& rhs );
		virtual size_t hashCode() const;

		virtual std::string toString();

		cfsec::CFSecSecGrpIncPKey operator =( cfsec::CFSecSecGrpIncPKey& src );
		cfsec::CFSecSecGrpIncPKey operator =( cfsec::CFSecSecGrpIncHPKey& src );
		cfsec::CFSecSecGrpIncPKey operator =( cfsec::CFSecSecGrpIncBuff& src );
		cfsec::CFSecSecGrpIncPKey operator =( cfsec::CFSecSecGrpIncHBuff& src );
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncHPKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncPKey& rhs );
	bool operator <(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncHPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncPKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncHPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncPKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncHPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncPKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncHPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncPKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	bool operator >(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncHPKey& rhs );
	bool operator >(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncPKey& rhs );
	bool operator >(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecGrpIncPKey& lhs, const cfsec::CFSecSecGrpIncBuff& rhs );

	template<> struct hash<cfsec::CFSecSecGrpIncPKey> {
		typedef cfsec::CFSecSecGrpIncPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}
