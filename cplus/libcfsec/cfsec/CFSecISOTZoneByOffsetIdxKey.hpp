#pragma once

// Description: C++18 specification for a ISOTZone by OffsetIdx index key object.

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
	class CFSecISOTZoneHBuff;

	class CFSecISOTZoneByOffsetIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int16_t requiredTZHourOffset;
		int16_t requiredTZMinOffset;
	public:
		CFSecISOTZoneByOffsetIdxKey();
		CFSecISOTZoneByOffsetIdxKey( const CFSecISOTZoneByOffsetIdxKey& src );
		virtual ~CFSecISOTZoneByOffsetIdxKey();

		virtual const int16_t getRequiredTZHourOffset() const;
		virtual const int16_t* getRequiredTZHourOffsetReference() const;
		virtual void setRequiredTZHourOffset( const int16_t value );

		virtual const int16_t getRequiredTZMinOffset() const;
		virtual const int16_t* getRequiredTZMinOffsetReference() const;
		virtual void setRequiredTZMinOffset( const int16_t value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFSecISOTZoneByOffsetIdxKey& rhs );
		bool operator <( const CFSecISOTZoneHBuff& rhs );
		bool operator <( const CFSecISOTZoneBuff& rhs );

		bool operator <=( const CFSecISOTZoneByOffsetIdxKey& rhs );
		bool operator <=( const CFSecISOTZoneHBuff& rhs );
		bool operator <=( const CFSecISOTZoneBuff& rhs );

		bool operator ==( const CFSecISOTZoneByOffsetIdxKey& rhs );
		bool operator ==( const CFSecISOTZoneHBuff& rhs );
		bool operator ==( const CFSecISOTZoneBuff& rhs );

		bool operator !=( const CFSecISOTZoneByOffsetIdxKey& rhs );
		bool operator !=( const CFSecISOTZoneHBuff& rhs );
		bool operator !=( const CFSecISOTZoneBuff& rhs );

		bool operator >=( const CFSecISOTZoneByOffsetIdxKey& rhs );
		bool operator >=( const CFSecISOTZoneHBuff& rhs );
		bool operator >=( const CFSecISOTZoneBuff& rhs );

		bool operator >( const CFSecISOTZoneByOffsetIdxKey& rhs );
		bool operator >( const CFSecISOTZoneHBuff& rhs );
		bool operator >( const CFSecISOTZoneBuff& rhs );
		cfsec::CFSecISOTZoneByOffsetIdxKey operator =( cfsec::CFSecISOTZoneByOffsetIdxKey& src );
		cfsec::CFSecISOTZoneByOffsetIdxKey operator =( cfsec::CFSecISOTZoneBuff& src );
		cfsec::CFSecISOTZoneByOffsetIdxKey operator =( cfsec::CFSecISOTZoneHBuff& src );
};
}

namespace std {

	bool operator <(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator <=(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator ==(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator !=(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator >=(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator >(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs );
	bool operator >(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	template<> struct hash<cfsec::CFSecISOTZoneByOffsetIdxKey> {
		typedef cfsec::CFSecISOTZoneByOffsetIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

