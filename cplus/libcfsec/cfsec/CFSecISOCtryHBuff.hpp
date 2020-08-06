#pragma once

// Description: C++18 specification of a ISOCtry history buffer object.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
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

