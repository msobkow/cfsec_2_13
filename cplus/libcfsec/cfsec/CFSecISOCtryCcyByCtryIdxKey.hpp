#pragma once

// Description: C++18 specification for a ISOCtryCcy by CtryIdx index key object.

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

	class CFSecISOCtryCcyBuff;
	class CFSecISOCtryCcyHBuff;

	class CFSecISOCtryCcyByCtryIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int16_t requiredISOCtryId;
	public:
		CFSecISOCtryCcyByCtryIdxKey();
		CFSecISOCtryCcyByCtryIdxKey( const CFSecISOCtryCcyByCtryIdxKey& src );
		virtual ~CFSecISOCtryCcyByCtryIdxKey();

		virtual const int16_t getRequiredISOCtryId() const;
		virtual const int16_t* getRequiredISOCtryIdReference() const;
		virtual void setRequiredISOCtryId( const int16_t value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecISOCtryCcyByCtryIdxKey& rhs );
		bool operator <( const CFSecISOCtryCcyHBuff& rhs );
		bool operator <( const CFSecISOCtryCcyBuff& rhs );

		bool operator <=( const CFSecISOCtryCcyByCtryIdxKey& rhs );
		bool operator <=( const CFSecISOCtryCcyHBuff& rhs );
		bool operator <=( const CFSecISOCtryCcyBuff& rhs );

		bool operator ==( const CFSecISOCtryCcyByCtryIdxKey& rhs );
		bool operator ==( const CFSecISOCtryCcyHBuff& rhs );
		bool operator ==( const CFSecISOCtryCcyBuff& rhs );

		bool operator !=( const CFSecISOCtryCcyByCtryIdxKey& rhs );
		bool operator !=( const CFSecISOCtryCcyHBuff& rhs );
		bool operator !=( const CFSecISOCtryCcyBuff& rhs );

		bool operator >=( const CFSecISOCtryCcyByCtryIdxKey& rhs );
		bool operator >=( const CFSecISOCtryCcyHBuff& rhs );
		bool operator >=( const CFSecISOCtryCcyBuff& rhs );

		bool operator >( const CFSecISOCtryCcyByCtryIdxKey& rhs );
		bool operator >( const CFSecISOCtryCcyHBuff& rhs );
		bool operator >( const CFSecISOCtryCcyBuff& rhs );
		cfsec::CFSecISOCtryCcyByCtryIdxKey operator =( cfsec::CFSecISOCtryCcyByCtryIdxKey& src );
		cfsec::CFSecISOCtryCcyByCtryIdxKey operator =( cfsec::CFSecISOCtryCcyBuff& src );
		cfsec::CFSecISOCtryCcyByCtryIdxKey operator =( cfsec::CFSecISOCtryCcyHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecISOCtryCcyByCtryIdxKey& lhs, const cfsec::CFSecISOCtryCcyByCtryIdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOCtryCcyByCtryIdxKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOCtryCcyByCtryIdxKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs );

	bool operator <=(const  cfsec::CFSecISOCtryCcyByCtryIdxKey& lhs, const cfsec::CFSecISOCtryCcyByCtryIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryCcyByCtryIdxKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryCcyByCtryIdxKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs );

	bool operator ==(const  cfsec::CFSecISOCtryCcyByCtryIdxKey& lhs, const cfsec::CFSecISOCtryCcyByCtryIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryCcyByCtryIdxKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryCcyByCtryIdxKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs );

	bool operator !=(const  cfsec::CFSecISOCtryCcyByCtryIdxKey& lhs, const cfsec::CFSecISOCtryCcyByCtryIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryCcyByCtryIdxKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryCcyByCtryIdxKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs );

	bool operator >=(const  cfsec::CFSecISOCtryCcyByCtryIdxKey& lhs, const cfsec::CFSecISOCtryCcyByCtryIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryCcyByCtryIdxKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryCcyByCtryIdxKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs );

	bool operator >(const  cfsec::CFSecISOCtryCcyByCtryIdxKey& lhs, const cfsec::CFSecISOCtryCcyByCtryIdxKey& rhs );
	bool operator >(const  cfsec::CFSecISOCtryCcyByCtryIdxKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOCtryCcyByCtryIdxKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs );

	template<> struct hash<cfsec::CFSecISOCtryCcyByCtryIdxKey> {
		typedef cfsec::CFSecISOCtryCcyByCtryIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

