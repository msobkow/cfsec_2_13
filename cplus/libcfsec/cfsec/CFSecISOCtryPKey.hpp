#pragma once

// Description: C++18 specification of a ISOCtry primary key object.

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

	class CFSecISOCtryBuff;
	class CFSecISOCtryHPKey;
	class CFSecISOCtryHBuff;

	class CFSecISOCtryPKey
	{
	protected:

		int16_t requiredISOCtryId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;

		CFSecISOCtryPKey();
		CFSecISOCtryPKey( const CFSecISOCtryPKey& src );
		virtual ~CFSecISOCtryPKey();

		virtual const int16_t getRequiredISOCtryId() const;
		virtual const int16_t* getRequiredISOCtryIdReference() const;
		virtual void setRequiredISOCtryId( const int16_t value );

		bool operator <( const CFSecISOCtryHPKey& rhs );
		bool operator <( const CFSecISOCtryPKey& rhs );
		bool operator <( const CFSecISOCtryHBuff& rhs );
		bool operator <( const CFSecISOCtryBuff& rhs );

		bool operator <=( const CFSecISOCtryHPKey& rhs );
		bool operator <=( const CFSecISOCtryPKey& rhs );
		bool operator <=( const CFSecISOCtryHBuff& rhs );
		bool operator <=( const CFSecISOCtryBuff& rhs );

		bool operator ==( const CFSecISOCtryHPKey& rhs );
		bool operator ==( const CFSecISOCtryPKey& rhs );
		bool operator ==( const CFSecISOCtryHBuff& rhs );
		bool operator ==( const CFSecISOCtryBuff& rhs );

		bool operator !=( const CFSecISOCtryHPKey& rhs );
		bool operator !=( const CFSecISOCtryPKey& rhs );
		bool operator !=( const CFSecISOCtryHBuff& rhs );
		bool operator !=( const CFSecISOCtryBuff& rhs );

		bool operator >=( const CFSecISOCtryHPKey& rhs );
		bool operator >=( const CFSecISOCtryPKey& rhs );
		bool operator >=( const CFSecISOCtryHBuff& rhs );
		bool operator >=( const CFSecISOCtryBuff& rhs );

		bool operator >( const CFSecISOCtryHPKey& rhs );
		bool operator >( const CFSecISOCtryPKey& rhs );
		bool operator >( const CFSecISOCtryHBuff& rhs );
		bool operator >( const CFSecISOCtryBuff& rhs );
		virtual size_t hashCode() const;

		virtual std::string toString();

		cfsec::CFSecISOCtryPKey operator =( cfsec::CFSecISOCtryPKey& src );
		cfsec::CFSecISOCtryPKey operator =( cfsec::CFSecISOCtryHPKey& src );
		cfsec::CFSecISOCtryPKey operator =( cfsec::CFSecISOCtryBuff& src );
		cfsec::CFSecISOCtryPKey operator =( cfsec::CFSecISOCtryHBuff& src );
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryHPKey& rhs );
	bool operator <(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryPKey& rhs );
	bool operator <(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryBuff& rhs );

	bool operator <=(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryHPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryBuff& rhs );

	bool operator ==(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryHPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryBuff& rhs );

	bool operator !=(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryHPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryBuff& rhs );

	bool operator >=(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryHPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryBuff& rhs );

	bool operator >(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryHPKey& rhs );
	bool operator >(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryPKey& rhs );
	bool operator >(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOCtryPKey& lhs, const cfsec::CFSecISOCtryBuff& rhs );

	template<> struct hash<cfsec::CFSecISOCtryPKey> {
		typedef cfsec::CFSecISOCtryPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}
