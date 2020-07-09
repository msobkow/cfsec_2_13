#pragma once

// Description: C++18 specification for a ISOTZone buffer object.

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

	class CFSecISOTZonePKey;
	class CFSecISOTZoneHPKey;
	class CFSecISOTZoneHBuff;
	class CFSecISOTZoneByOffsetIdxKey;
	class CFSecISOTZoneByUTZNameIdxKey;
	class CFSecISOTZoneByIso8601IdxKey;

	class CFSecISOTZoneBuff : public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string GENDEFNAME;
		static const classcode_t CLASS_CODE;
		static const std::string CLASS_NAME;
		static const std::string COLNAME_ISOTZONEID;
		static const std::string COLNAME_ISO8601;
		static const std::string COLNAME_TZNAME;
		static const std::string COLNAME_TZHOUROFFSET;
		static const std::string COLNAME_TZMINOFFSET;
		static const std::string COLNAME_DESCRIPTION;
		static const std::string COLNAME_VISIBLE;
		static const char* S_INIT_CREATEDBY;
		static const char* S_INIT_UPDATEDBY;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
		static const int16_t ISOTZONEID_INIT_VALUE;
		static const std::string ISO8601_INIT_VALUE;
		static const std::string TZNAME_INIT_VALUE;
		static const int16_t TZHOUROFFSET_INIT_VALUE;
		static const int16_t TZMINOFFSET_INIT_VALUE;
		static const std::string DESCRIPTION_INIT_VALUE;
		static const bool VISIBLE_INIT_VALUE;
		static const int16_t ISOTZONEID_MIN_VALUE;
		static const int16_t TZHOUROFFSET_MIN_VALUE;
		static const int16_t TZMINOFFSET_MIN_VALUE;
		static const int16_t TZHOUROFFSET_MAX_VALUE;
		static const int16_t TZMINOFFSET_MAX_VALUE;
		static const std::string::size_type ISO8601_MAX_LEN;
		static const std::string::size_type TZNAME_MAX_LEN;
		static const std::string::size_type DESCRIPTION_MAX_LEN;
	protected:
		uuid_t createdByUserId;
		std::chrono::system_clock::time_point createdAt;
		uuid_t updatedByUserId;
		std::chrono::system_clock::time_point updatedAt;
		int16_t requiredISOTZoneId;
		std::string* requiredIso8601;
		std::string* requiredTZName;
		int16_t requiredTZHourOffset;
		int16_t requiredTZMinOffset;
		std::string* requiredDescription;
		bool requiredVisible;
		int32_t requiredRevision;
	public:
		CFSecISOTZoneBuff();

		CFSecISOTZoneBuff( const CFSecISOTZoneBuff& src );

		virtual ~CFSecISOTZoneBuff();

		virtual const std::string& getClassName() const;
		virtual cflib::ICFLibCloneableObj* clone();
		virtual const classcode_t getClassCode() const;

		virtual bool implementsClassCode( const classcode_t argClassCode );
		virtual const uuid_ptr_t getCreatedByUserId() const;
		virtual void setCreatedByUserId( const uuid_ptr_t value );
		virtual const std::chrono::system_clock::time_point& getCreatedAt() const;
		virtual void setCreatedAt( const std::chrono::system_clock::time_point& value );
		virtual const uuid_ptr_t getUpdatedByUserId() const;
		virtual void setUpdatedByUserId( const uuid_ptr_t value );
		virtual const std::chrono::system_clock::time_point& getUpdatedAt() const;
		virtual void setUpdatedAt( const std::chrono::system_clock::time_point& value );
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

		virtual int32_t getRequiredRevision() const;
		virtual void setRequiredRevision( int32_t value );

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
		cfsec::CFSecISOTZoneBuff operator =( cfsec::CFSecISOTZoneBuff& src );
		cfsec::CFSecISOTZoneBuff operator =( cfsec::CFSecISOTZoneHBuff& src );

		virtual std::string toString();
	};
}

namespace std {

	bool operator <(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs );
	bool operator <(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator <(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator <(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator <(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator <=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs );
	bool operator <=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator <=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator <=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator <=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator ==(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs );
	bool operator ==(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator ==(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator ==(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator ==(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator !=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs );
	bool operator !=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator !=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator !=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator !=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator >=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs );
	bool operator >=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator >=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator >=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator >=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	bool operator >(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs );

	bool operator >(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs );

	bool operator >(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs );

	bool operator >(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs );
	bool operator >(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs );
	bool operator >(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs );
	bool operator >(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs );

	template<> struct hash<cfsec::CFSecISOTZoneBuff> {
		typedef cfsec::CFSecISOTZoneBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

