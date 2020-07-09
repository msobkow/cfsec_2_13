#pragma once

// Description: C++18 specification of a ISOTZone primary key object.

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

