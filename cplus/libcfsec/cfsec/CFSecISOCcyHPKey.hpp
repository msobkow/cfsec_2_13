#pragma once

// Description: C++18 specification of a ISOCcy history primary key object.

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

	class CFSecISOCcyPKey;
	class CFSecISOCcyBuff;
	class CFSecISOCcyHBuff;

	class CFSecISOCcyHPKey : public CFSecHPKey
	{
	protected:

		int16_t requiredISOCcyId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;

		CFSecISOCcyHPKey();
		CFSecISOCcyHPKey( const CFSecISOCcyHPKey& src );
		virtual ~CFSecISOCcyHPKey();

		virtual const int16_t getRequiredISOCcyId() const;
		virtual const int16_t* getRequiredISOCcyIdReference() const;
		virtual void setRequiredISOCcyId( const int16_t value );

		virtual size_t hashCode() const;

		virtual std::string toString();

		bool operator <( const CFSecISOCcyPKey& rhs );
		bool operator <( const CFSecISOCcyHPKey& rhs );
		bool operator <( const CFSecISOCcyHBuff& rhs );
		bool operator <( const CFSecISOCcyBuff& rhs );


		bool operator <=( const CFSecISOCcyPKey& rhs );
		bool operator <=( const CFSecISOCcyHPKey& rhs );
		bool operator <=( const CFSecISOCcyHBuff& rhs );
		bool operator <=( const CFSecISOCcyBuff& rhs );


		bool operator ==( const CFSecISOCcyPKey& rhs );
		bool operator ==( const CFSecISOCcyHPKey& rhs );
		bool operator ==( const CFSecISOCcyHBuff& rhs );
		bool operator ==( const CFSecISOCcyBuff& rhs );


		bool operator !=( const CFSecISOCcyPKey& rhs );
		bool operator !=( const CFSecISOCcyHPKey& rhs );
		bool operator !=( const CFSecISOCcyHBuff& rhs );
		bool operator !=( const CFSecISOCcyBuff& rhs );


		bool operator >=( const CFSecISOCcyPKey& rhs );
		bool operator >=( const CFSecISOCcyHPKey& rhs );
		bool operator >=( const CFSecISOCcyHBuff& rhs );
		bool operator >=( const CFSecISOCcyBuff& rhs );


		bool operator >( const CFSecISOCcyPKey& rhs );
		bool operator >( const CFSecISOCcyHPKey& rhs );
		bool operator >( const CFSecISOCcyHBuff& rhs );
		bool operator >( const CFSecISOCcyBuff& rhs );

		cfsec::CFSecISOCcyHPKey operator =( cfsec::CFSecISOCcyPKey& src );
		cfsec::CFSecISOCcyHPKey operator =( cfsec::CFSecISOCcyHPKey& src );
		cfsec::CFSecISOCcyHPKey operator =( cfsec::CFSecISOCcyBuff& src );
		cfsec::CFSecISOCcyHPKey operator =( cfsec::CFSecISOCcyHBuff& src );

	};
}


namespace std {

	bool operator <(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyPKey& rhs );
	bool operator <(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyHPKey& rhs );
	bool operator <(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );


	bool operator <=(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyHPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );


	bool operator ==(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyHPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );


	bool operator !=(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyHPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );


	bool operator >=(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyHPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );


	bool operator >(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyPKey& rhs );
	bool operator >(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyHPKey& rhs );
	bool operator >(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOCcyHPKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );


	template<> struct hash<cfsec::CFSecISOCcyHPKey> {
		typedef cfsec::CFSecISOCcyHPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

