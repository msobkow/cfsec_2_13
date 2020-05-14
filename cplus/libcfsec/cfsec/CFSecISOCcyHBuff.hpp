#pragma once

// Description: C++18 specification of a ISOCcy history buffer object.

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

	class CFSecISOCcyBuff;
	class CFSecISOCcyPKey;
	class CFSecISOCcyHPKey;
	class CFSecISOCcyByCcyCdIdxKey;
	class CFSecISOCcyByCcyNmIdxKey;

	class CFSecISOCcyHBuff : public CFSecHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int16_t requiredISOCcyId;
		std::string* requiredISOCode;
		std::string* requiredName;
		std::string* optionalUnitSymbol;
		int16_t requiredPrecis;		classcode_t classCode;

	public:
		CFSecISOCcyHBuff();
		CFSecISOCcyHBuff( const CFSecISOCcyHBuff& src );
		virtual ~CFSecISOCcyHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const int16_t getRequiredISOCcyId() const;
		virtual const int16_t* getRequiredISOCcyIdReference() const;
		virtual void setRequiredISOCcyId( const int16_t value );

		virtual const std::string& getRequiredISOCode() const;
		virtual const std::string* getRequiredISOCodeReference() const;
		virtual void setRequiredISOCode( const std::string& value );

		virtual const std::string& getRequiredName() const;
		virtual const std::string* getRequiredNameReference() const;
		virtual void setRequiredName( const std::string& value );

		virtual const std::string& getOptionalUnitSymbolValue() const;
		virtual const std::string* getOptionalUnitSymbolReference() const;
		virtual const bool isOptionalUnitSymbolNull() const;
		virtual void setOptionalUnitSymbolNull();
		virtual void setOptionalUnitSymbolValue( const std::string& value );

		virtual const int16_t getRequiredPrecis() const;
		virtual const int16_t* getRequiredPrecisReference() const;
		virtual void setRequiredPrecis( const int16_t value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecISOCcyByCcyCdIdxKey& rhs );
		bool operator <( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator <( const CFSecISOCcyPKey& rhs );
		bool operator <( const CFSecISOCcyHPKey& rhs );
		bool operator <( const CFSecISOCcyHBuff& rhs );
		bool operator <( const CFSecISOCcyBuff& rhs );

		bool operator <=( const CFSecISOCcyByCcyCdIdxKey& rhs );
		bool operator <=( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator <=( const CFSecISOCcyPKey& rhs );
		bool operator <=( const CFSecISOCcyHPKey& rhs );
		bool operator <=( const CFSecISOCcyHBuff& rhs );
		bool operator <=( const CFSecISOCcyBuff& rhs );

		bool operator ==( const CFSecISOCcyByCcyCdIdxKey& rhs );
		bool operator ==( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator ==( const CFSecISOCcyPKey& rhs );
		bool operator ==( const CFSecISOCcyHPKey& rhs );
		bool operator ==( const CFSecISOCcyHBuff& rhs );
		bool operator ==( const CFSecISOCcyBuff& rhs );

		bool operator !=( const CFSecISOCcyByCcyCdIdxKey& rhs );
		bool operator !=( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator !=( const CFSecISOCcyPKey& rhs );
		bool operator !=( const CFSecISOCcyHPKey& rhs );
		bool operator !=( const CFSecISOCcyHBuff& rhs );
		bool operator !=( const CFSecISOCcyBuff& rhs );

		bool operator >=( const CFSecISOCcyByCcyCdIdxKey& rhs );
		bool operator >=( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator >=( const CFSecISOCcyPKey& rhs );
		bool operator >=( const CFSecISOCcyHPKey& rhs );
		bool operator >=( const CFSecISOCcyHBuff& rhs );
		bool operator >=( const CFSecISOCcyBuff& rhs );

		bool operator >( const CFSecISOCcyByCcyCdIdxKey& rhs );
		bool operator >( const CFSecISOCcyByCcyNmIdxKey& rhs );
		bool operator >( const CFSecISOCcyPKey& rhs );
		bool operator >( const CFSecISOCcyHPKey& rhs );
		bool operator >( const CFSecISOCcyHBuff& rhs );
		bool operator >( const CFSecISOCcyBuff& rhs );
		cfsec::CFSecISOCcyHBuff operator =( cfsec::CFSecISOCcyBuff& src );
		cfsec::CFSecISOCcyHBuff operator =( cfsec::CFSecISOCcyHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs );
	bool operator <(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs );
	bool operator <(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator <=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator ==(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator !=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator >=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	bool operator >(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs );
	bool operator >(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs );
	bool operator >(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs );
	bool operator >(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs );
	bool operator >(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs );

	template<> struct hash<cfsec::CFSecISOCcyHBuff> {
		typedef cfsec::CFSecISOCcyHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

