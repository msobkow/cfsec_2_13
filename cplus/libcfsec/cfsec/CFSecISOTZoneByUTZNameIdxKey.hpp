#pragma once

// Description: C++18 specification for a ISOTZone by UTZNameIdx index key object.

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
#include <cfsec/ICFSecSchema.hpp>

namespace cfsec {

	class CFSecISOTZoneBuff;
	class CFSecISOTZoneHBuff;

	class CFSecISOTZoneByUTZNameIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		std::string* requiredTZName;
	public:
		CFSecISOTZoneByUTZNameIdxKey();
		CFSecISOTZoneByUTZNameIdxKey( const CFSecISOTZoneByUTZNameIdxKey& src );
		virtual ~CFSecISOTZoneByUTZNameIdxKey();

		virtual const std::string& getRequiredTZName() const;
		virtual const std::string* getRequiredTZNameReference() const;
		virtual void setRequiredTZName( const std::string& value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecISOTZoneByUTZNameIdxKey& rhs );
		bool operator <( const CFSecISOTZoneHBuff& rhs );
		bool operator <( const CFSecISOTZoneBuff& rhs );

		bool operator <=( const CFSecISOTZoneByUTZNameIdxKey& rhs );
		bool operator <=( const CFSecISOTZoneHBuff& rhs );
		bool operator <=( const CFSecISOTZoneBuff& rhs );

		bool operator ==( const CFSecISOTZoneByUTZNameIdxKey& rhs );
		bool operator ==( const CFSecISOTZoneHBuff& rhs );
		bool operator ==( const CFSecISOTZoneBuff& rhs );

		bool operator !=( const CFSecISOTZoneByUTZNameIdxKey& rhs );
		bool operator !=( const CFSecISOTZoneHBuff& rhs );
		bool operator !=( const CFSecISOTZoneBuff& rhs );

		bool operator >=( const CFSecISOTZoneByUTZNameIdxKey& rhs );
		bool operator >=( const CFSecISOTZoneHBuff& rhs );
		bool operator >=( const CFSecISOTZoneBuff& rhs );

		bool operator >( const CFSecISOTZoneByUTZNameIdxKey& rhs );
		bool operator >( const CFSecISOTZoneHBuff& rhs );
		bool operator >( const CFSecISOTZoneBuff& rhs );
		cfsec::CFSecISOTZoneByUTZNameIdxKey operator =( cfsec::CFSecISOTZoneByUTZNameIdxKey& src );
		cfsec::CFSecISOTZoneByUTZNameIdxKey operator =( cfsec::CFSecISOTZoneBuff& src );
		cfsec::CFSecISOTZoneByUTZNameIdxKey operator =( cfsec::CFSecISOTZoneHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator <=(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator ==(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator !=(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator >=(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator >(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs );
	bool operator >(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	template<> struct hash<cfsec::CFSecISOTZoneByUTZNameIdxKey> {
		typedef cfsec::CFSecISOTZoneByUTZNameIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

