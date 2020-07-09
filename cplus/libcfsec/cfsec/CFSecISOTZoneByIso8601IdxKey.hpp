#pragma once

// Description: C++18 specification for a ISOTZone by Iso8601Idx index key object.

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

