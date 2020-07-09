#pragma once

// Description: C++18 specification for a ISOCcy by CcyCdIdx index key object.

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

	class CFSecISOCcyBuff;
	class CFSecISOCcyHBuff;

	class CFSecISOCcyByCcyCdIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		std::string* requiredISOCode;
	public:
		CFSecISOCcyByCcyCdIdxKey();
		CFSecISOCcyByCcyCdIdxKey( const CFSecISOCcyByCcyCdIdxKey& src );
		virtual ~CFSecISOCcyByCcyCdIdxKey();

		virtual const std::string& getRequiredISOCode() const;
		virtual const std::string* getRequiredISOCodeReference() const;
		virtual void setRequiredISOCode( const std::string& value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecISOCcyByCcyCdIdxKey& rhs );
		bool operator <( const CFSecISOCcyHBuff& rhs );
		bool operator <( const CFSecISOCcyBuff& rhs );

		bool operator <=( const CFSecISOCcyByCcyCdIdxKey& rhs );
		bool operator <=( const CFSecISOCcyHBuff& rhs );
		bool operator <=( const CFSecISOCcyBuff& rhs );

		bool operator ==( const CFSecISOCcyByCcyCdIdxKey& rhs );
		bool operator ==( const CFSecISOCcyHBuff& rhs );
		bool operator ==( const CFSecISOCcyBuff& rhs );

		bool operator !=( const CFSecISOCcyByCcyCdIdxKey& rhs );
		bool operator !=( const CFSecISOCcyHBuff& rhs );
		bool operator !=( const CFSecISOCcyBuff& rhs );

		bool operator >=( const CFSecISOCcyByCcyCdIdxKey& rhs );
		bool operator >=( const CFSecISOCcyHBuff& rhs );
		bool operator >=( const CFSecISOCcyBuff& rhs );

		bool operator >( const CFSecISOCcyByCcyCdIdxKey& rhs );
		bool operator >( const CFSecISOCcyHBuff& rhs );
		bool operator >( const CFSecISOCcyBuff& rhs );
		cfsec::CFSecISOCcyByCcyCdIdxKey operator =( cfsec::CFSecISOCcyByCcyCdIdxKey& src );
		cfsec::CFSecISOCcyByCcyCdIdxKey operator =( cfsec::CFSecISOCcyBuff& src );
		cfsec::CFSecISOCcyByCcyCdIdxKey operator =( cfsec::CFSecISOCcyHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator <=(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator ==(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator !=(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator >=(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator >(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs );
	bool operator >(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	template<> struct hash<cfsec::CFSecISOCcyByCcyCdIdxKey> {
		typedef cfsec::CFSecISOCcyByCcyCdIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

