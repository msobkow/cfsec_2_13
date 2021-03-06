#pragma once

// Description: C++18 specification of a ISOCtryCcy history buffer object.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow
 *	
 *		This file is part of MSS Code Factory.
 *	
 *		MSS Code Factory is available under dual commercial license from Mark Stephen
 *		Sobkow, or under the terms of the GNU General Public License, Version 3
 *		or later.
 *	
 *	    MSS Code Factory is free software: you can redistribute it and/or modify
 *	    it under the terms of the GNU General Public License as published by
 *	    the Free Software Foundation, either version 3 of the License, or
 *	    (at your option) any later version.
 *	
 *	    MSS Code Factory is distributed in the hope that it will be useful,
 *	    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	    GNU General Public License for more details.
 *	
 *	    You should have received a copy of the GNU General Public License
 *	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
 *	
 *	Please contact Mark Stephen Sobkow at mark.sobkow@gmail.com for commercial licensing.
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

