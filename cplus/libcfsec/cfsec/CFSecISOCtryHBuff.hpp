#pragma once

// Description: C++18 specification of a ISOCtry history buffer object.

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

#include <cfsec/CFSecHPKey.hpp>

#include <cfsec/ICFSecSchema.hpp>
namespace cfsec {

	class CFSecISOCtryBuff;
	class CFSecISOCtryPKey;
	class CFSecISOCtryHPKey;
	class CFSecISOCtryByISOCodeIdxKey;
	class CFSecISOCtryByNameIdxKey;

	class CFSecISOCtryHBuff : public CFSecHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int16_t requiredISOCtryId;
		std::string* requiredISOCode;
		std::string* requiredName;		classcode_t classCode;

	public:
		CFSecISOCtryHBuff();
		CFSecISOCtryHBuff( const CFSecISOCtryHBuff& src );
		virtual ~CFSecISOCtryHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const int16_t getRequiredISOCtryId() const;
		virtual const int16_t* getRequiredISOCtryIdReference() const;
		virtual void setRequiredISOCtryId( const int16_t value );

		virtual const std::string& getRequiredISOCode() const;
		virtual const std::string* getRequiredISOCodeReference() const;
		virtual void setRequiredISOCode( const std::string& value );

		virtual const std::string& getRequiredName() const;
		virtual const std::string* getRequiredNameReference() const;
		virtual void setRequiredName( const std::string& value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecISOCtryByISOCodeIdxKey& rhs );
		bool operator <( const CFSecISOCtryByNameIdxKey& rhs );
		bool operator <( const CFSecISOCtryPKey& rhs );
		bool operator <( const CFSecISOCtryHPKey& rhs );
		bool operator <( const CFSecISOCtryHBuff& rhs );
		bool operator <( const CFSecISOCtryBuff& rhs );

		bool operator <=( const CFSecISOCtryByISOCodeIdxKey& rhs );
		bool operator <=( const CFSecISOCtryByNameIdxKey& rhs );
		bool operator <=( const CFSecISOCtryPKey& rhs );
		bool operator <=( const CFSecISOCtryHPKey& rhs );
		bool operator <=( const CFSecISOCtryHBuff& rhs );
		bool operator <=( const CFSecISOCtryBuff& rhs );

		bool operator ==( const CFSecISOCtryByISOCodeIdxKey& rhs );
		bool operator ==( const CFSecISOCtryByNameIdxKey& rhs );
		bool operator ==( const CFSecISOCtryPKey& rhs );
		bool operator ==( const CFSecISOCtryHPKey& rhs );
		bool operator ==( const CFSecISOCtryHBuff& rhs );
		bool operator ==( const CFSecISOCtryBuff& rhs );

		bool operator !=( const CFSecISOCtryByISOCodeIdxKey& rhs );
		bool operator !=( const CFSecISOCtryByNameIdxKey& rhs );
		bool operator !=( const CFSecISOCtryPKey& rhs );
		bool operator !=( const CFSecISOCtryHPKey& rhs );
		bool operator !=( const CFSecISOCtryHBuff& rhs );
		bool operator !=( const CFSecISOCtryBuff& rhs );

		bool operator >=( const CFSecISOCtryByISOCodeIdxKey& rhs );
		bool operator >=( const CFSecISOCtryByNameIdxKey& rhs );
		bool operator >=( const CFSecISOCtryPKey& rhs );
		bool operator >=( const CFSecISOCtryHPKey& rhs );
		bool operator >=( const CFSecISOCtryHBuff& rhs );
		bool operator >=( const CFSecISOCtryBuff& rhs );

		bool operator >( const CFSecISOCtryByISOCodeIdxKey& rhs );
		bool operator >( const CFSecISOCtryByNameIdxKey& rhs );
		bool operator >( const CFSecISOCtryPKey& rhs );
		bool operator >( const CFSecISOCtryHPKey& rhs );
		bool operator >( const CFSecISOCtryHBuff& rhs );
		bool operator >( const CFSecISOCtryBuff& rhs );
		cfsec::CFSecISOCtryHBuff operator =( cfsec::CFSecISOCtryBuff& src );
		cfsec::CFSecISOCtryHBuff operator =( cfsec::CFSecISOCtryHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryByISOCodeIdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryByNameIdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryPKey& rhs );
	bool operator <(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryHPKey& rhs );
	bool operator <(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryBuff& rhs );

	bool operator <=(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryByISOCodeIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryByNameIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryHPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryBuff& rhs );

	bool operator ==(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryByISOCodeIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryByNameIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryHPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryBuff& rhs );

	bool operator !=(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryByISOCodeIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryByNameIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryHPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryBuff& rhs );

	bool operator >=(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryByISOCodeIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryByNameIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryHPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryBuff& rhs );

	bool operator >(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryByISOCodeIdxKey& rhs );
	bool operator >(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryByNameIdxKey& rhs );
	bool operator >(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryPKey& rhs );
	bool operator >(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryHPKey& rhs );
	bool operator >(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOCtryHBuff& lhs, const cfsec::CFSecISOCtryBuff& rhs );

	template<> struct hash<cfsec::CFSecISOCtryHBuff> {
		typedef cfsec::CFSecISOCtryHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

