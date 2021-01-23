#pragma once

// Description: C++18 specification for a ISOTZone by Iso8601Idx index key object.

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
#include <cfsec/ICFSecSchema.hpp>

namespace cfsec {

	class CFSecISOTZoneBuff;
	class CFSecISOTZoneHBuff;

	class CFSecISOTZoneByIso8601IdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		std::string* requiredIso8601;
	public:
		CFSecISOTZoneByIso8601IdxKey();
		CFSecISOTZoneByIso8601IdxKey( const CFSecISOTZoneByIso8601IdxKey& src );
		virtual ~CFSecISOTZoneByIso8601IdxKey();

		virtual const std::string& getRequiredIso8601() const;
		virtual const std::string* getRequiredIso8601Reference() const;
		virtual void setRequiredIso8601( const std::string& value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecISOTZoneByIso8601IdxKey& rhs );
		bool operator <( const CFSecISOTZoneHBuff& rhs );
		bool operator <( const CFSecISOTZoneBuff& rhs );

		bool operator <=( const CFSecISOTZoneByIso8601IdxKey& rhs );
		bool operator <=( const CFSecISOTZoneHBuff& rhs );
		bool operator <=( const CFSecISOTZoneBuff& rhs );

		bool operator ==( const CFSecISOTZoneByIso8601IdxKey& rhs );
		bool operator ==( const CFSecISOTZoneHBuff& rhs );
		bool operator ==( const CFSecISOTZoneBuff& rhs );

		bool operator !=( const CFSecISOTZoneByIso8601IdxKey& rhs );
		bool operator !=( const CFSecISOTZoneHBuff& rhs );
		bool operator !=( const CFSecISOTZoneBuff& rhs );

		bool operator >=( const CFSecISOTZoneByIso8601IdxKey& rhs );
		bool operator >=( const CFSecISOTZoneHBuff& rhs );
		bool operator >=( const CFSecISOTZoneBuff& rhs );

		bool operator >( const CFSecISOTZoneByIso8601IdxKey& rhs );
		bool operator >( const CFSecISOTZoneHBuff& rhs );
		bool operator >( const CFSecISOTZoneBuff& rhs );
		cfsec::CFSecISOTZoneByIso8601IdxKey operator =( cfsec::CFSecISOTZoneByIso8601IdxKey& src );
		cfsec::CFSecISOTZoneByIso8601IdxKey operator =( cfsec::CFSecISOTZoneBuff& src );
		cfsec::CFSecISOTZoneByIso8601IdxKey operator =( cfsec::CFSecISOTZoneHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator <=(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator ==(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator !=(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator >=(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator >(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs );
	bool operator >(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	template<> struct hash<cfsec::CFSecISOTZoneByIso8601IdxKey> {
		typedef cfsec::CFSecISOTZoneByIso8601IdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

