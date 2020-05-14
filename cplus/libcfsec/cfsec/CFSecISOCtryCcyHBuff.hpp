#pragma once

// Description: C++18 specification of a ISOCtryCcy history buffer object.

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

	class CFSecISOCtryCcyBuff;
	class CFSecISOCtryCcyPKey;
	class CFSecISOCtryCcyHPKey;
	class CFSecISOCtryCcyByCtryIdxKey;
	class CFSecISOCtryCcyByCcyIdxKey;

	class CFSecISOCtryCcyHBuff : public CFSecHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int16_t requiredISOCtryId;
		int16_t requiredISOCcyId;		classcode_t classCode;

	public:
		CFSecISOCtryCcyHBuff();
		CFSecISOCtryCcyHBuff( const CFSecISOCtryCcyHBuff& src );
		virtual ~CFSecISOCtryCcyHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const int16_t getRequiredISOCtryId() const;
		virtual const int16_t* getRequiredISOCtryIdReference() const;
		virtual void setRequiredISOCtryId( const int16_t value );

		virtual const int16_t getRequiredISOCcyId() const;
		virtual const int16_t* getRequiredISOCcyIdReference() const;
		virtual void setRequiredISOCcyId( const int16_t value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecISOCtryCcyByCtryIdxKey& rhs );
		bool operator <( const CFSecISOCtryCcyByCcyIdxKey& rhs );
		bool operator <( const CFSecISOCtryCcyPKey& rhs );
		bool operator <( const CFSecISOCtryCcyHPKey& rhs );
		bool operator <( const CFSecISOCtryCcyHBuff& rhs );
		bool operator <( const CFSecISOCtryCcyBuff& rhs );

		bool operator <=( const CFSecISOCtryCcyByCtryIdxKey& rhs );
		bool operator <=( const CFSecISOCtryCcyByCcyIdxKey& rhs );
		bool operator <=( const CFSecISOCtryCcyPKey& rhs );
		bool operator <=( const CFSecISOCtryCcyHPKey& rhs );
		bool operator <=( const CFSecISOCtryCcyHBuff& rhs );
		bool operator <=( const CFSecISOCtryCcyBuff& rhs );

		bool operator ==( const CFSecISOCtryCcyByCtryIdxKey& rhs );
		bool operator ==( const CFSecISOCtryCcyByCcyIdxKey& rhs );
		bool operator ==( const CFSecISOCtryCcyPKey& rhs );
		bool operator ==( const CFSecISOCtryCcyHPKey& rhs );
		bool operator ==( const CFSecISOCtryCcyHBuff& rhs );
		bool operator ==( const CFSecISOCtryCcyBuff& rhs );

		bool operator !=( const CFSecISOCtryCcyByCtryIdxKey& rhs );
		bool operator !=( const CFSecISOCtryCcyByCcyIdxKey& rhs );
		bool operator !=( const CFSecISOCtryCcyPKey& rhs );
		bool operator !=( const CFSecISOCtryCcyHPKey& rhs );
		bool operator !=( const CFSecISOCtryCcyHBuff& rhs );
		bool operator !=( const CFSecISOCtryCcyBuff& rhs );

		bool operator >=( const CFSecISOCtryCcyByCtryIdxKey& rhs );
		bool operator >=( const CFSecISOCtryCcyByCcyIdxKey& rhs );
		bool operator >=( const CFSecISOCtryCcyPKey& rhs );
		bool operator >=( const CFSecISOCtryCcyHPKey& rhs );
		bool operator >=( const CFSecISOCtryCcyHBuff& rhs );
		bool operator >=( const CFSecISOCtryCcyBuff& rhs );

		bool operator >( const CFSecISOCtryCcyByCtryIdxKey& rhs );
		bool operator >( const CFSecISOCtryCcyByCcyIdxKey& rhs );
		bool operator >( const CFSecISOCtryCcyPKey& rhs );
		bool operator >( const CFSecISOCtryCcyHPKey& rhs );
		bool operator >( const CFSecISOCtryCcyHBuff& rhs );
		bool operator >( const CFSecISOCtryCcyBuff& rhs );
		cfsec::CFSecISOCtryCcyHBuff operator =( cfsec::CFSecISOCtryCcyBuff& src );
		cfsec::CFSecISOCtryCcyHBuff operator =( cfsec::CFSecISOCtryCcyHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCtryIdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs );
	bool operator <(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs );
	bool operator <(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs );

	bool operator <=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCtryIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs );

	bool operator ==(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCtryIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs );

	bool operator !=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCtryIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs );

	bool operator >=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCtryIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs );

	bool operator >(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCtryIdxKey& rhs );
	bool operator >(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs );
	bool operator >(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs );
	bool operator >(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs );
	bool operator >(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs );

	template<> struct hash<cfsec::CFSecISOCtryCcyHBuff> {
		typedef cfsec::CFSecISOCtryCcyHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

