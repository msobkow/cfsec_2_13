#pragma once

// Description: C++18 specification for a ISOCtryCcy by CcyIdx index key object.

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

	class CFSecISOCtryCcyBuff;
	class CFSecISOCtryCcyHBuff;

	class CFSecISOCtryCcyByCcyIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int16_t requiredISOCcyId;
	public:
		CFSecISOCtryCcyByCcyIdxKey();
		CFSecISOCtryCcyByCcyIdxKey( const CFSecISOCtryCcyByCcyIdxKey& src );
		virtual ~CFSecISOCtryCcyByCcyIdxKey();

		virtual const int16_t getRequiredISOCcyId() const;
		virtual const int16_t* getRequiredISOCcyIdReference() const;
		virtual void setRequiredISOCcyId( const int16_t value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecISOCtryCcyByCcyIdxKey& rhs );
		bool operator <( const CFSecISOCtryCcyHBuff& rhs );
		bool operator <( const CFSecISOCtryCcyBuff& rhs );

		bool operator <=( const CFSecISOCtryCcyByCcyIdxKey& rhs );
		bool operator <=( const CFSecISOCtryCcyHBuff& rhs );
		bool operator <=( const CFSecISOCtryCcyBuff& rhs );

		bool operator ==( const CFSecISOCtryCcyByCcyIdxKey& rhs );
		bool operator ==( const CFSecISOCtryCcyHBuff& rhs );
		bool operator ==( const CFSecISOCtryCcyBuff& rhs );

		bool operator !=( const CFSecISOCtryCcyByCcyIdxKey& rhs );
		bool operator !=( const CFSecISOCtryCcyHBuff& rhs );
		bool operator !=( const CFSecISOCtryCcyBuff& rhs );

		bool operator >=( const CFSecISOCtryCcyByCcyIdxKey& rhs );
		bool operator >=( const CFSecISOCtryCcyHBuff& rhs );
		bool operator >=( const CFSecISOCtryCcyBuff& rhs );

		bool operator >( const CFSecISOCtryCcyByCcyIdxKey& rhs );
		bool operator >( const CFSecISOCtryCcyHBuff& rhs );
		bool operator >( const CFSecISOCtryCcyBuff& rhs );
		cfsec::CFSecISOCtryCcyByCcyIdxKey operator =( cfsec::CFSecISOCtryCcyByCcyIdxKey& src );
		cfsec::CFSecISOCtryCcyByCcyIdxKey operator =( cfsec::CFSecISOCtryCcyBuff& src );
		cfsec::CFSecISOCtryCcyByCcyIdxKey operator =( cfsec::CFSecISOCtryCcyHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs );

	bool operator <=(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs );

	bool operator ==(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs );

	bool operator !=(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs );

	bool operator >=(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs );

	bool operator >(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs );
	bool operator >(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs );

	template<> struct hash<cfsec::CFSecISOCtryCcyByCcyIdxKey> {
		typedef cfsec::CFSecISOCtryCcyByCcyIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

