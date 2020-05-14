#pragma once

// Description: C++18 specification of a ServiceType history buffer object.

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

	class CFSecServiceTypeBuff;
	class CFSecServiceTypePKey;
	class CFSecServiceTypeHPKey;
	class CFSecServiceTypeByUDescrIdxKey;

	class CFSecServiceTypeHBuff : public CFSecHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int32_t requiredServiceTypeId;
		std::string* requiredDescription;		classcode_t classCode;

	public:
		CFSecServiceTypeHBuff();
		CFSecServiceTypeHBuff( const CFSecServiceTypeHBuff& src );
		virtual ~CFSecServiceTypeHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const int32_t getRequiredServiceTypeId() const;
		virtual const int32_t* getRequiredServiceTypeIdReference() const;
		virtual void setRequiredServiceTypeId( const int32_t value );

		virtual const std::string& getRequiredDescription() const;
		virtual const std::string* getRequiredDescriptionReference() const;
		virtual void setRequiredDescription( const std::string& value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecServiceTypeByUDescrIdxKey& rhs );
		bool operator <( const CFSecServiceTypePKey& rhs );
		bool operator <( const CFSecServiceTypeHPKey& rhs );
		bool operator <( const CFSecServiceTypeHBuff& rhs );
		bool operator <( const CFSecServiceTypeBuff& rhs );

		bool operator <=( const CFSecServiceTypeByUDescrIdxKey& rhs );
		bool operator <=( const CFSecServiceTypePKey& rhs );
		bool operator <=( const CFSecServiceTypeHPKey& rhs );
		bool operator <=( const CFSecServiceTypeHBuff& rhs );
		bool operator <=( const CFSecServiceTypeBuff& rhs );

		bool operator ==( const CFSecServiceTypeByUDescrIdxKey& rhs );
		bool operator ==( const CFSecServiceTypePKey& rhs );
		bool operator ==( const CFSecServiceTypeHPKey& rhs );
		bool operator ==( const CFSecServiceTypeHBuff& rhs );
		bool operator ==( const CFSecServiceTypeBuff& rhs );

		bool operator !=( const CFSecServiceTypeByUDescrIdxKey& rhs );
		bool operator !=( const CFSecServiceTypePKey& rhs );
		bool operator !=( const CFSecServiceTypeHPKey& rhs );
		bool operator !=( const CFSecServiceTypeHBuff& rhs );
		bool operator !=( const CFSecServiceTypeBuff& rhs );

		bool operator >=( const CFSecServiceTypeByUDescrIdxKey& rhs );
		bool operator >=( const CFSecServiceTypePKey& rhs );
		bool operator >=( const CFSecServiceTypeHPKey& rhs );
		bool operator >=( const CFSecServiceTypeHBuff& rhs );
		bool operator >=( const CFSecServiceTypeBuff& rhs );

		bool operator >( const CFSecServiceTypeByUDescrIdxKey& rhs );
		bool operator >( const CFSecServiceTypePKey& rhs );
		bool operator >( const CFSecServiceTypeHPKey& rhs );
		bool operator >( const CFSecServiceTypeHBuff& rhs );
		bool operator >( const CFSecServiceTypeBuff& rhs );
		cfsec::CFSecServiceTypeHBuff operator =( cfsec::CFSecServiceTypeBuff& src );
		cfsec::CFSecServiceTypeHBuff operator =( cfsec::CFSecServiceTypeHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs );
	bool operator <(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypePKey& rhs );
	bool operator <(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeHPKey& rhs );
	bool operator <(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator <(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeBuff& rhs );

	bool operator <=(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypePKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeHPKey& rhs );
	bool operator <=(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator <=(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeBuff& rhs );

	bool operator ==(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypePKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeHPKey& rhs );
	bool operator ==(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator ==(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeBuff& rhs );

	bool operator !=(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypePKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeHPKey& rhs );
	bool operator !=(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator !=(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeBuff& rhs );

	bool operator >=(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypePKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeHPKey& rhs );
	bool operator >=(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator >=(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeBuff& rhs );

	bool operator >(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs );
	bool operator >(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypePKey& rhs );
	bool operator >(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeHPKey& rhs );
	bool operator >(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeHBuff& rhs );
	bool operator >(const  cfsec::CFSecServiceTypeHBuff& lhs, const cfsec::CFSecServiceTypeBuff& rhs );

	template<> struct hash<cfsec::CFSecServiceTypeHBuff> {
		typedef cfsec::CFSecServiceTypeHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

