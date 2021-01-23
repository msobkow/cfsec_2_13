#pragma once

// Description: C++18 specification of a ISOTZone history buffer object.

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

	class CFSecISOTZoneBuff;
	class CFSecISOTZonePKey;
	class CFSecISOTZoneHPKey;
	class CFSecISOTZoneByOffsetIdxKey;
	class CFSecISOTZoneByUTZNameIdxKey;
	class CFSecISOTZoneByIso8601IdxKey;

	class CFSecISOTZoneHBuff : public CFSecHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int16_t requiredISOTZoneId;
		std::string* requiredIso8601;
		std::string* requiredTZName;
		int16_t requiredTZHourOffset;
		int16_t requiredTZMinOffset;
		std::string* requiredDescription;
		bool requiredVisible;		classcode_t classCode;

	public:
		CFSecISOTZoneHBuff();
		CFSecISOTZoneHBuff( const CFSecISOTZoneHBuff& src );
		virtual ~CFSecISOTZoneHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const int16_t getRequiredISOTZoneId() const;
		virtual const int16_t* getRequiredISOTZoneIdReference() const;
		virtual void setRequiredISOTZoneId( const int16_t value );

		virtual const std::string& getRequiredIso8601() const;
		virtual const std::string* getRequiredIso8601Reference() const;
		virtual void setRequiredIso8601( const std::string& value );

		virtual const std::string& getRequiredTZName() const;
		virtual const std::string* getRequiredTZNameReference() const;
		virtual void setRequiredTZName( const std::string& value );

		virtual const int16_t getRequiredTZHourOffset() const;
		virtual const int16_t* getRequiredTZHourOffsetReference() const;
		virtual void setRequiredTZHourOffset( const int16_t value );

		virtual const int16_t getRequiredTZMinOffset() const;
		virtual const int16_t* getRequiredTZMinOffsetReference() const;
		virtual void setRequiredTZMinOffset( const int16_t value );

		virtual const std::string& getRequiredDescription() const;
		virtual const std::string* getRequiredDescriptionReference() const;
		virtual void setRequiredDescription( const std::string& value );

		virtual const bool getRequiredVisible() const;
		virtual const bool* getRequiredVisibleReference() const;
		virtual void setRequiredVisible( const bool value );

		virtual size_t hashCode() const;

		bool operator <( const CFSecISOTZoneByOffsetIdxKey& rhs );
		bool operator <( const CFSecISOTZoneByUTZNameIdxKey& rhs );
		bool operator <( const CFSecISOTZoneByIso8601IdxKey& rhs );
		bool operator <( const CFSecISOTZonePKey& rhs );
		bool operator <( const CFSecISOTZoneHPKey& rhs );
		bool operator <( const CFSecISOTZoneHBuff& rhs );
		bool operator <( const CFSecISOTZoneBuff& rhs );

		bool operator <=( const CFSecISOTZoneByOffsetIdxKey& rhs );
		bool operator <=( const CFSecISOTZoneByUTZNameIdxKey& rhs );
		bool operator <=( const CFSecISOTZoneByIso8601IdxKey& rhs );
		bool operator <=( const CFSecISOTZonePKey& rhs );
		bool operator <=( const CFSecISOTZoneHPKey& rhs );
		bool operator <=( const CFSecISOTZoneHBuff& rhs );
		bool operator <=( const CFSecISOTZoneBuff& rhs );

		bool operator ==( const CFSecISOTZoneByOffsetIdxKey& rhs );
		bool operator ==( const CFSecISOTZoneByUTZNameIdxKey& rhs );
		bool operator ==( const CFSecISOTZoneByIso8601IdxKey& rhs );
		bool operator ==( const CFSecISOTZonePKey& rhs );
		bool operator ==( const CFSecISOTZoneHPKey& rhs );
		bool operator ==( const CFSecISOTZoneHBuff& rhs );
		bool operator ==( const CFSecISOTZoneBuff& rhs );

		bool operator !=( const CFSecISOTZoneByOffsetIdxKey& rhs );
		bool operator !=( const CFSecISOTZoneByUTZNameIdxKey& rhs );
		bool operator !=( const CFSecISOTZoneByIso8601IdxKey& rhs );
		bool operator !=( const CFSecISOTZonePKey& rhs );
		bool operator !=( const CFSecISOTZoneHPKey& rhs );
		bool operator !=( const CFSecISOTZoneHBuff& rhs );
		bool operator !=( const CFSecISOTZoneBuff& rhs );

		bool operator >=( const CFSecISOTZoneByOffsetIdxKey& rhs );
		bool operator >=( const CFSecISOTZoneByUTZNameIdxKey& rhs );
		bool operator >=( const CFSecISOTZoneByIso8601IdxKey& rhs );
		bool operator >=( const CFSecISOTZonePKey& rhs );
		bool operator >=( const CFSecISOTZoneHPKey& rhs );
		bool operator >=( const CFSecISOTZoneHBuff& rhs );
		bool operator >=( const CFSecISOTZoneBuff& rhs );

		bool operator >( const CFSecISOTZoneByOffsetIdxKey& rhs );
		bool operator >( const CFSecISOTZoneByUTZNameIdxKey& rhs );
		bool operator >( const CFSecISOTZoneByIso8601IdxKey& rhs );
		bool operator >( const CFSecISOTZonePKey& rhs );
		bool operator >( const CFSecISOTZoneHPKey& rhs );
		bool operator >( const CFSecISOTZoneHBuff& rhs );
		bool operator >( const CFSecISOTZoneBuff& rhs );
		cfsec::CFSecISOTZoneHBuff operator =( cfsec::CFSecISOTZoneBuff& src );
		cfsec::CFSecISOTZoneHBuff operator =( cfsec::CFSecISOTZoneHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator <(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator <(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator <=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator <=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator ==(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator ==(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator !=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator !=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator >=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator >=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator >(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs );
	bool operator >(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs );
	bool operator >(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs );
	bool operator >(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator >(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator >(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	template<> struct hash<cfsec::CFSecISOTZoneHBuff> {
		typedef cfsec::CFSecISOTZoneHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

