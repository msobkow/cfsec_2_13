#pragma once

// Description: C++18 specification of a ISOTZone history primary key object.

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

	class CFSecISOTZonePKey;
	class CFSecISOTZoneBuff;
	class CFSecISOTZoneHBuff;

	class CFSecISOTZoneHPKey : public CFSecHPKey
	{
	protected:

		int16_t requiredISOTZoneId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;

		CFSecISOTZoneHPKey();
		CFSecISOTZoneHPKey( const CFSecISOTZoneHPKey& src );
		virtual ~CFSecISOTZoneHPKey();

		virtual const int16_t getRequiredISOTZoneId() const;
		virtual const int16_t* getRequiredISOTZoneIdReference() const;
		virtual void setRequiredISOTZoneId( const int16_t value );

		virtual size_t hashCode() const;

		virtual std::string toString();

		bool operator <( const CFSecISOTZonePKey& rhs );
		bool operator <( const CFSecISOTZoneHPKey& rhs );
		bool operator <( const CFSecISOTZoneHBuff& rhs );
		bool operator <( const CFSecISOTZoneBuff& rhs );


		bool operator <=( const CFSecISOTZonePKey& rhs );
		bool operator <=( const CFSecISOTZoneHPKey& rhs );
		bool operator <=( const CFSecISOTZoneHBuff& rhs );
		bool operator <=( const CFSecISOTZoneBuff& rhs );


		bool operator ==( const CFSecISOTZonePKey& rhs );
		bool operator ==( const CFSecISOTZoneHPKey& rhs );
		bool operator ==( const CFSecISOTZoneHBuff& rhs );
		bool operator ==( const CFSecISOTZoneBuff& rhs );


		bool operator !=( const CFSecISOTZonePKey& rhs );
		bool operator !=( const CFSecISOTZoneHPKey& rhs );
		bool operator !=( const CFSecISOTZoneHBuff& rhs );
		bool operator !=( const CFSecISOTZoneBuff& rhs );


		bool operator >=( const CFSecISOTZonePKey& rhs );
		bool operator >=( const CFSecISOTZoneHPKey& rhs );
		bool operator >=( const CFSecISOTZoneHBuff& rhs );
		bool operator >=( const CFSecISOTZoneBuff& rhs );


		bool operator >( const CFSecISOTZonePKey& rhs );
		bool operator >( const CFSecISOTZoneHPKey& rhs );
		bool operator >( const CFSecISOTZoneHBuff& rhs );
		bool operator >( const CFSecISOTZoneBuff& rhs );

		cfsec::CFSecISOTZoneHPKey operator =( cfsec::CFSecISOTZonePKey& src );
		cfsec::CFSecISOTZoneHPKey operator =( cfsec::CFSecISOTZoneHPKey& src );
		cfsec::CFSecISOTZoneHPKey operator =( cfsec::CFSecISOTZoneBuff& src );
		cfsec::CFSecISOTZoneHPKey operator =( cfsec::CFSecISOTZoneHBuff& src );

	};
}


namespace std {

	bool operator <(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator <(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator <(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );


	bool operator <=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator <=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );


	bool operator ==(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator ==(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );


	bool operator !=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator !=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );


	bool operator >=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator >=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );


	bool operator >(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator >(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator >(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs );


	template<> struct hash<cfsec::CFSecISOTZoneHPKey> {
		typedef cfsec::CFSecISOTZoneHPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

