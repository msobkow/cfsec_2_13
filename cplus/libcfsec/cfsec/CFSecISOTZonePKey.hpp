#pragma once

// Description: C++18 specification of a ISOTZone primary key object.

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
	class CFSecISOTZoneHPKey;
	class CFSecISOTZoneHBuff;

	class CFSecISOTZonePKey
	{
	protected:

		int16_t requiredISOTZoneId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;

		CFSecISOTZonePKey();
		CFSecISOTZonePKey( const CFSecISOTZonePKey& src );
		virtual ~CFSecISOTZonePKey();

		virtual const int16_t getRequiredISOTZoneId() const;
		virtual const int16_t* getRequiredISOTZoneIdReference() const;
		virtual void setRequiredISOTZoneId( const int16_t value );

		bool operator <( const CFSecISOTZoneHPKey& rhs );
		bool operator <( const CFSecISOTZonePKey& rhs );
		bool operator <( const CFSecISOTZoneHBuff& rhs );
		bool operator <( const CFSecISOTZoneBuff& rhs );

		bool operator <=( const CFSecISOTZoneHPKey& rhs );
		bool operator <=( const CFSecISOTZonePKey& rhs );
		bool operator <=( const CFSecISOTZoneHBuff& rhs );
		bool operator <=( const CFSecISOTZoneBuff& rhs );

		bool operator ==( const CFSecISOTZoneHPKey& rhs );
		bool operator ==( const CFSecISOTZonePKey& rhs );
		bool operator ==( const CFSecISOTZoneHBuff& rhs );
		bool operator ==( const CFSecISOTZoneBuff& rhs );

		bool operator !=( const CFSecISOTZoneHPKey& rhs );
		bool operator !=( const CFSecISOTZonePKey& rhs );
		bool operator !=( const CFSecISOTZoneHBuff& rhs );
		bool operator !=( const CFSecISOTZoneBuff& rhs );

		bool operator >=( const CFSecISOTZoneHPKey& rhs );
		bool operator >=( const CFSecISOTZonePKey& rhs );
		bool operator >=( const CFSecISOTZoneHBuff& rhs );
		bool operator >=( const CFSecISOTZoneBuff& rhs );

		bool operator >( const CFSecISOTZoneHPKey& rhs );
		bool operator >( const CFSecISOTZonePKey& rhs );
		bool operator >( const CFSecISOTZoneHBuff& rhs );
		bool operator >( const CFSecISOTZoneBuff& rhs );
		virtual size_t hashCode() const;

		virtual std::string toString();

		cfsec::CFSecISOTZonePKey operator =( cfsec::CFSecISOTZonePKey& src );
		cfsec::CFSecISOTZonePKey operator =( cfsec::CFSecISOTZoneHPKey& src );
		cfsec::CFSecISOTZonePKey operator =( cfsec::CFSecISOTZoneBuff& src );
		cfsec::CFSecISOTZonePKey operator =( cfsec::CFSecISOTZoneHBuff& src );
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator <(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator <(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator <=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator <=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator ==(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator ==(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator !=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator !=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator >=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator >=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator >(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator >(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator >(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	template<> struct hash<cfsec::CFSecISOTZonePKey> {
		typedef cfsec::CFSecISOTZonePKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

