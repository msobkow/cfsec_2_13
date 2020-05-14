#pragma once

// Description: C++18 specification for a ISOCcy by CcyNmIdx index key object.

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

	class CFSecISOCcyBuff;
	class CFSecISOCcyHBuff;

	class CFSecISOCcyByCcyNmIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		std::string* requiredName;
	public:
		CFSecISOCcyByCcyNmIdxKey();
		CFSecISOCcyByCcyNmIdxKey( const CFSecISOCcyByCcyNmIdxKey& src );
		virtual ~CFSecISOCcyByCcyNmIdxKey();

		virtual const std::string& getRequiredName() const;
		virtual const std::string* getRequiredNameReference() const;
		virtual void setRequiredName( const std::string& value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator <( const CFSecISOCcyHBuff& rhs );
		bool operator <( const CFSecISOCcyBuff& rhs );

		bool operator <=( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator <=( const CFSecISOCcyHBuff& rhs );
		bool operator <=( const CFSecISOCcyBuff& rhs );

		bool operator ==( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator ==( const CFSecISOCcyHBuff& rhs );
		bool operator ==( const CFSecISOCcyBuff& rhs );

		bool operator !=( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator !=( const CFSecISOCcyHBuff& rhs );
		bool operator !=( const CFSecISOCcyBuff& rhs );

		bool operator >=( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator >=( const CFSecISOCcyHBuff& rhs );
		bool operator >=( const CFSecISOCcyBuff& rhs );

		bool operator >( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator >( const CFSecISOCcyHBuff& rhs );
		bool operator >( const CFSecISOCcyBuff& rhs );
		cfsec::CFSecISOCcyByCcyNmIdxKey operator =( cfsec::CFSecISOCcyByCcyNmIdxKey& src );
		cfsec::CFSecISOCcyByCcyNmIdxKey operator =( cfsec::CFSecISOCcyBuff& src );
		cfsec::CFSecISOCcyByCcyNmIdxKey operator =( cfsec::CFSecISOCcyHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator <=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator ==(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator !=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator >=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator >(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );
	bool operator >(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	template<> struct hash<cfsec::CFSecISOCcyByCcyNmIdxKey> {
		typedef cfsec::CFSecISOCcyByCcyNmIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

