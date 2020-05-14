#pragma once

// Description: C++18 specification for a ServiceType by UDescrIdx index key object.

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

	class CFSecServiceTypeBuff;
	class CFSecServiceTypeHBuff;

	class CFSecServiceTypeByUDescrIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		std::string* requiredDescription;
	public:
		CFSecServiceTypeByUDescrIdxKey();
		CFSecServiceTypeByUDescrIdxKey( const CFSecServiceTypeByUDescrIdxKey& src );
		virtual ~CFSecServiceTypeByUDescrIdxKey();

		virtual const std::string& getRequiredDescription() const;
		virtual const std::string* getRequiredDescriptionReference() const;
		virtual void setRequiredDescription( const std::string& value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecServiceTypeByUDescrIdxKey& rhs );
		bool operator <( const CFSecServiceTypeHBuff& rhs );
		bool operator <( const CFSecServiceTypeBuff& rhs );

		bool operator <=( const CFSecServiceTypeByUDescrIdxKey& rhs );
		bool operator <=( const CFSecServiceTypeHBuff& rhs );
		bool operator <=( const CFSecServiceTypeBuff& rhs );

		bool operator ==( const CFSecServiceTypeByUDescrIdxKey& rhs );
		bool operator ==( const CFSecServiceTypeHBuff& rhs );
		bool operator ==( const CFSecServiceTypeBuff& rhs );

		bool operator !=( const CFSecServiceTypeByUDescrIdxKey& rhs );
		bool operator !=( const CFSecServiceTypeHBuff& rhs );
		bool operator !=( const CFSecServiceTypeBuff& rhs );

		bool operator >=( const CFSecServiceTypeByUDescrIdxKey& rhs );
		bool operator >=( const CFSecServiceTypeHBuff& rhs );
		bool operator >=( const CFSecServiceTypeBuff& rhs );

		bool operator >( const CFSecServiceTypeByUDescrIdxKey& rhs );
		bool operator >( const CFSecServiceTypeHBuff& rhs );
		bool operator >( const CFSecServiceTypeBuff& rhs );
		cfsec::CFSecServiceTypeByUDescrIdxKey operator =( cfsec::CFSecServiceTypeByUDescrIdxKey& src );
		cfsec::CFSecServiceTypeByUDescrIdxKey operator =( cfsec::CFSecServiceTypeBuff& src );
		cfsec::CFSecServiceTypeByUDescrIdxKey operator =( cfsec::CFSecServiceTypeHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs );
	bool operator <(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator <(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs );

	bool operator <=(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator <=(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs );

	bool operator ==(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator ==(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs );

	bool operator !=(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator !=(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs );

	bool operator >=(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator >=(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs );

	bool operator >(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs );
	bool operator >(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator >(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs );

	template<> struct hash<cfsec::CFSecServiceTypeByUDescrIdxKey> {
		typedef cfsec::CFSecServiceTypeByUDescrIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

