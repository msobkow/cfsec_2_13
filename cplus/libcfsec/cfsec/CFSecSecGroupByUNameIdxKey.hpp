#pragma once

// Description: C++18 specification for a SecGroup by UNameIdx index key object.

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

	class CFSecSecGroupBuff;
	class CFSecSecGroupHBuff;

	class CFSecSecGroupByUNameIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int64_t requiredClusterId;
		std::string* requiredName;
	public:
		CFSecSecGroupByUNameIdxKey();
		CFSecSecGroupByUNameIdxKey( const CFSecSecGroupByUNameIdxKey& src );
		virtual ~CFSecSecGroupByUNameIdxKey();

		virtual const int64_t getRequiredClusterId() const;
		virtual const int64_t* getRequiredClusterIdReference() const;
		virtual void setRequiredClusterId( const int64_t value );

		virtual const std::string& getRequiredName() const;
		virtual const std::string* getRequiredNameReference() const;
		virtual void setRequiredName( const std::string& value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecSecGroupByUNameIdxKey& rhs );
		bool operator <( const CFSecSecGroupHBuff& rhs );
		bool operator <( const CFSecSecGroupBuff& rhs );

		bool operator <=( const CFSecSecGroupByUNameIdxKey& rhs );
		bool operator <=( const CFSecSecGroupHBuff& rhs );
		bool operator <=( const CFSecSecGroupBuff& rhs );

		bool operator ==( const CFSecSecGroupByUNameIdxKey& rhs );
		bool operator ==( const CFSecSecGroupHBuff& rhs );
		bool operator ==( const CFSecSecGroupBuff& rhs );

		bool operator !=( const CFSecSecGroupByUNameIdxKey& rhs );
		bool operator !=( const CFSecSecGroupHBuff& rhs );
		bool operator !=( const CFSecSecGroupBuff& rhs );

		bool operator >=( const CFSecSecGroupByUNameIdxKey& rhs );
		bool operator >=( const CFSecSecGroupHBuff& rhs );
		bool operator >=( const CFSecSecGroupBuff& rhs );

		bool operator >( const CFSecSecGroupByUNameIdxKey& rhs );
		bool operator >( const CFSecSecGroupHBuff& rhs );
		bool operator >( const CFSecSecGroupBuff& rhs );
		cfsec::CFSecSecGroupByUNameIdxKey operator =( cfsec::CFSecSecGroupByUNameIdxKey& src );
		cfsec::CFSecSecGroupByUNameIdxKey operator =( cfsec::CFSecSecGroupBuff& src );
		cfsec::CFSecSecGroupByUNameIdxKey operator =( cfsec::CFSecSecGroupHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecSecGroupByUNameIdxKey& lhs, const cfsec::CFSecSecGroupByUNameIdxKey& rhs );
	bool operator <(const  cfsec::CFSecSecGroupByUNameIdxKey& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator <(const  cfsec::CFSecSecGroupByUNameIdxKey& lhs, const cfsec::CFSecSecGroupBuff& rhs );

	bool operator <=(const  cfsec::CFSecSecGroupByUNameIdxKey& lhs, const cfsec::CFSecSecGroupByUNameIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupByUNameIdxKey& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator <=(const  cfsec::CFSecSecGroupByUNameIdxKey& lhs, const cfsec::CFSecSecGroupBuff& rhs );

	bool operator ==(const  cfsec::CFSecSecGroupByUNameIdxKey& lhs, const cfsec::CFSecSecGroupByUNameIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupByUNameIdxKey& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator ==(const  cfsec::CFSecSecGroupByUNameIdxKey& lhs, const cfsec::CFSecSecGroupBuff& rhs );

	bool operator !=(const  cfsec::CFSecSecGroupByUNameIdxKey& lhs, const cfsec::CFSecSecGroupByUNameIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupByUNameIdxKey& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator !=(const  cfsec::CFSecSecGroupByUNameIdxKey& lhs, const cfsec::CFSecSecGroupBuff& rhs );

	bool operator >=(const  cfsec::CFSecSecGroupByUNameIdxKey& lhs, const cfsec::CFSecSecGroupByUNameIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupByUNameIdxKey& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator >=(const  cfsec::CFSecSecGroupByUNameIdxKey& lhs, const cfsec::CFSecSecGroupBuff& rhs );

	bool operator >(const  cfsec::CFSecSecGroupByUNameIdxKey& lhs, const cfsec::CFSecSecGroupByUNameIdxKey& rhs );
	bool operator >(const  cfsec::CFSecSecGroupByUNameIdxKey& lhs, const cfsec::CFSecSecGroupHBuff& rhs );
	bool operator >(const  cfsec::CFSecSecGroupByUNameIdxKey& lhs, const cfsec::CFSecSecGroupBuff& rhs );

	template<> struct hash<cfsec::CFSecSecGroupByUNameIdxKey> {
		typedef cfsec::CFSecSecGroupByUNameIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

