// Description: C++18 implementation for a ISOTZone buffer object.

/*
 *	com.github.msobkow.CFSec
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

using namespace std;

#include <cfsec/ICFSecPublic.hpp>

#include <cfsec/CFSecISOTZoneByOffsetIdxKey.hpp>
#include <cfsec/CFSecISOTZoneByUTZNameIdxKey.hpp>
#include <cfsec/CFSecISOTZoneByIso8601IdxKey.hpp>
#include <cfsec/CFSecSchema.hpp>

namespace cfsec {

	const std::string CFSecISOTZoneBuff::S_VALUE( "value" );
	const std::string CFSecISOTZoneBuff::S_VALUE_LENGTH( "value.length()" );

	const std::string CFSecISOTZoneBuff::GENDEFNAME( "ISOTZone" );
	const classcode_t CFSecISOTZoneBuff::CLASS_CODE = 0xa008L;
	const std::string CFSecISOTZoneBuff::CLASS_NAME( "CFSecISOTZoneBuff" );
		const std::string CFSecISOTZoneBuff::COLNAME_ISOTZONEID( "ISOTZoneId" );
		const std::string CFSecISOTZoneBuff::COLNAME_ISO8601( "Iso8601" );
		const std::string CFSecISOTZoneBuff::COLNAME_TZNAME( "TZName" );
		const std::string CFSecISOTZoneBuff::COLNAME_TZHOUROFFSET( "TZHourOffset" );
		const std::string CFSecISOTZoneBuff::COLNAME_TZMINOFFSET( "TZMinOffset" );
		const std::string CFSecISOTZoneBuff::COLNAME_DESCRIPTION( "Description" );
		const std::string CFSecISOTZoneBuff::COLNAME_VISIBLE( "Visible" );
	const char* CFSecISOTZoneBuff::S_INIT_CREATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const char* CFSecISOTZoneBuff::S_INIT_UPDATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const int16_t CFSecISOTZoneBuff::ISOTZONEID_INIT_VALUE = (int16_t)0;
	const std::string CFSecISOTZoneBuff::ISO8601_INIT_VALUE( "" );
	const std::string CFSecISOTZoneBuff::TZNAME_INIT_VALUE( "" );
	const int16_t CFSecISOTZoneBuff::TZHOUROFFSET_INIT_VALUE = (int16_t)0;
	const int16_t CFSecISOTZoneBuff::TZMINOFFSET_INIT_VALUE = (int16_t)0;
	const std::string CFSecISOTZoneBuff::DESCRIPTION_INIT_VALUE( "" );
	const bool CFSecISOTZoneBuff::VISIBLE_INIT_VALUE = true;
	const int16_t CFSecISOTZoneBuff::ISOTZONEID_MIN_VALUE = (int16_t)0;
	const int16_t CFSecISOTZoneBuff::TZHOUROFFSET_MIN_VALUE = (int16_t)-12;
	const int16_t CFSecISOTZoneBuff::TZMINOFFSET_MIN_VALUE = (int16_t)-59;
	const int16_t CFSecISOTZoneBuff::TZHOUROFFSET_MAX_VALUE = (int16_t)12;
	const int16_t CFSecISOTZoneBuff::TZMINOFFSET_MAX_VALUE = (int16_t)59;
	const std::string::size_type CFSecISOTZoneBuff::ISO8601_MAX_LEN = 6;
	const std::string::size_type CFSecISOTZoneBuff::TZNAME_MAX_LEN = 64;
	const std::string::size_type CFSecISOTZoneBuff::DESCRIPTION_MAX_LEN = 128;

	CFSecISOTZoneBuff::CFSecISOTZoneBuff()
	: cflib::ICFLibCloneableObj()
	{
		requiredRevision = 1;
		for( int i = 0; i < 16; i++ ) {
			createdByUserId[i] = 0;
		}
		createdAt = cflib::CFLib::getUTCTimestampInstance();
		for( int i = 0; i < 16; i++ ) {
			updatedByUserId[i] = 0;
		}
		updatedAt = cflib::CFLib::getUTCTimestampInstance();
		requiredISOTZoneId = cfsec::CFSecISOTZoneBuff::ISOTZONEID_INIT_VALUE;
		requiredIso8601 = new std::string( cfsec::CFSecISOTZoneBuff::ISO8601_INIT_VALUE );
		requiredTZName = new std::string( cfsec::CFSecISOTZoneBuff::TZNAME_INIT_VALUE );
		requiredTZHourOffset = cfsec::CFSecISOTZoneBuff::TZHOUROFFSET_INIT_VALUE;
		requiredTZMinOffset = cfsec::CFSecISOTZoneBuff::TZMINOFFSET_INIT_VALUE;
		requiredDescription = new std::string( cfsec::CFSecISOTZoneBuff::DESCRIPTION_INIT_VALUE );
		requiredVisible = cfsec::CFSecISOTZoneBuff::VISIBLE_INIT_VALUE;
	}

	CFSecISOTZoneBuff::CFSecISOTZoneBuff( const CFSecISOTZoneBuff& src )
	: cflib::ICFLibCloneableObj()
	{
		requiredRevision = 1;
		for( int i = 0; i < 16; i++ ) {
			createdByUserId[i] = 0;
		}
		createdAt = cflib::CFLib::getUTCTimestampInstance();
		for( int i = 0; i < 16; i++ ) {
			updatedByUserId[i] = 0;
		}
		updatedAt = cflib::CFLib::getUTCTimestampInstance();
		requiredISOTZoneId = cfsec::CFSecISOTZoneBuff::ISOTZONEID_INIT_VALUE;
		requiredIso8601 = new std::string( cfsec::CFSecISOTZoneBuff::ISO8601_INIT_VALUE );
		requiredTZName = new std::string( cfsec::CFSecISOTZoneBuff::TZNAME_INIT_VALUE );
		requiredTZHourOffset = cfsec::CFSecISOTZoneBuff::TZHOUROFFSET_INIT_VALUE;
		requiredTZMinOffset = cfsec::CFSecISOTZoneBuff::TZMINOFFSET_INIT_VALUE;
		requiredDescription = new std::string( cfsec::CFSecISOTZoneBuff::DESCRIPTION_INIT_VALUE );
		requiredVisible = cfsec::CFSecISOTZoneBuff::VISIBLE_INIT_VALUE;
		setRequiredISOTZoneId( src.getRequiredISOTZoneId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredIso8601( src.getRequiredIso8601() );
		setRequiredTZName( src.getRequiredTZName() );
		setRequiredTZHourOffset( src.getRequiredTZHourOffset() );
		setRequiredTZMinOffset( src.getRequiredTZMinOffset() );
		setRequiredDescription( src.getRequiredDescription() );
		setRequiredVisible( src.getRequiredVisible() );
	}

	CFSecISOTZoneBuff::~CFSecISOTZoneBuff() {
		if( requiredIso8601 != NULL ) {
			delete requiredIso8601;
			requiredIso8601 = NULL;
		}
		if( requiredTZName != NULL ) {
			delete requiredTZName;
			requiredTZName = NULL;
		}
		if( requiredDescription != NULL ) {
			delete requiredDescription;
			requiredDescription = NULL;
		}
		for( int i = 0; i < 16; i++ ) {
			createdByUserId[i] = 0;
		}
		for( int i = 0; i < 16; i++ ) {
			updatedByUserId[i] = 0;
		}
	}

	cflib::ICFLibCloneableObj* CFSecISOTZoneBuff::clone() {
		CFSecISOTZoneBuff* copy = new CFSecISOTZoneBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const std::string& CFSecISOTZoneBuff::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecISOTZoneBuff::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecISOTZoneBuff::implementsClassCode( const classcode_t argClassCode ) {
		if( argClassCode == CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	const uuid_ptr_t CFSecISOTZoneBuff::getCreatedByUserId() const {
		return( createdByUserId );
	}

	void CFSecISOTZoneBuff::setCreatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( createdByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecISOTZoneBuff::getCreatedAt() const {
		return( createdAt );
	}

	void CFSecISOTZoneBuff::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		createdAt = value;
	}

	const uuid_ptr_t CFSecISOTZoneBuff::getUpdatedByUserId() const {
		return( updatedByUserId );
	}

	void CFSecISOTZoneBuff::setUpdatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( updatedByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecISOTZoneBuff::getUpdatedAt() const {
		return( updatedAt );
	}

	void CFSecISOTZoneBuff::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		updatedAt = value;
	}
	const int16_t CFSecISOTZoneBuff::getRequiredISOTZoneId() const {
		return( requiredISOTZoneId );
	}

	const int16_t* CFSecISOTZoneBuff::getRequiredISOTZoneIdReference() const {
		return( &requiredISOTZoneId );
	}

	void CFSecISOTZoneBuff::setRequiredISOTZoneId( const int16_t value ) {
		static const std::string S_ProcName( "setRequiredISOTZoneId" );
		if( value < cfsec::CFSecISOTZoneBuff::ISOTZONEID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOTZoneBuff::ISOTZONEID_MIN_VALUE );
		}
		requiredISOTZoneId = value;
	}

	const std::string& CFSecISOTZoneBuff::getRequiredIso8601() const {
		return( *requiredIso8601 );
	}

	const std::string* CFSecISOTZoneBuff::getRequiredIso8601Reference() const {
		return( requiredIso8601 );
	}

	void CFSecISOTZoneBuff::setRequiredIso8601( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredIso8601" );
		if( value.length() > CFSecISOTZoneBuff::ISO8601_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecISOTZoneBuff::ISO8601_MAX_LEN );
		}
		if( requiredIso8601 != NULL ) {
			delete requiredIso8601;
			requiredIso8601 = NULL;
		}
		requiredIso8601 = new std::string( value );
	}

	const std::string& CFSecISOTZoneBuff::getRequiredTZName() const {
		return( *requiredTZName );
	}

	const std::string* CFSecISOTZoneBuff::getRequiredTZNameReference() const {
		return( requiredTZName );
	}

	void CFSecISOTZoneBuff::setRequiredTZName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredTZName" );
		if( value.length() > CFSecISOTZoneBuff::TZNAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecISOTZoneBuff::TZNAME_MAX_LEN );
		}
		if( requiredTZName != NULL ) {
			delete requiredTZName;
			requiredTZName = NULL;
		}
		requiredTZName = new std::string( value );
	}

	const int16_t CFSecISOTZoneBuff::getRequiredTZHourOffset() const {
		return( requiredTZHourOffset );
	}

	const int16_t* CFSecISOTZoneBuff::getRequiredTZHourOffsetReference() const {
		return( &requiredTZHourOffset );
	}

	void CFSecISOTZoneBuff::setRequiredTZHourOffset( const int16_t value ) {
		static const std::string S_ProcName( "setRequiredTZHourOffset" );
		if( value < cfsec::CFSecISOTZoneBuff::TZHOUROFFSET_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOTZoneBuff::TZHOUROFFSET_MIN_VALUE );
		}
		if( value > cfsec::CFSecISOTZoneBuff::TZHOUROFFSET_MAX_VALUE ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOTZoneBuff::TZHOUROFFSET_MAX_VALUE );
		}
		requiredTZHourOffset = value;
	}

	const int16_t CFSecISOTZoneBuff::getRequiredTZMinOffset() const {
		return( requiredTZMinOffset );
	}

	const int16_t* CFSecISOTZoneBuff::getRequiredTZMinOffsetReference() const {
		return( &requiredTZMinOffset );
	}

	void CFSecISOTZoneBuff::setRequiredTZMinOffset( const int16_t value ) {
		static const std::string S_ProcName( "setRequiredTZMinOffset" );
		if( value < cfsec::CFSecISOTZoneBuff::TZMINOFFSET_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOTZoneBuff::TZMINOFFSET_MIN_VALUE );
		}
		if( value > cfsec::CFSecISOTZoneBuff::TZMINOFFSET_MAX_VALUE ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOTZoneBuff::TZMINOFFSET_MAX_VALUE );
		}
		requiredTZMinOffset = value;
	}

	const std::string& CFSecISOTZoneBuff::getRequiredDescription() const {
		return( *requiredDescription );
	}

	const std::string* CFSecISOTZoneBuff::getRequiredDescriptionReference() const {
		return( requiredDescription );
	}

	void CFSecISOTZoneBuff::setRequiredDescription( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredDescription" );
		if( value.length() > CFSecISOTZoneBuff::DESCRIPTION_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecISOTZoneBuff::DESCRIPTION_MAX_LEN );
		}
		if( requiredDescription != NULL ) {
			delete requiredDescription;
			requiredDescription = NULL;
		}
		requiredDescription = new std::string( value );
	}

	const bool CFSecISOTZoneBuff::getRequiredVisible() const {
		return( requiredVisible );
	}

	const bool* CFSecISOTZoneBuff::getRequiredVisibleReference() const {
		return( &requiredVisible );
	}

	void CFSecISOTZoneBuff::setRequiredVisible( const bool value ) {
		requiredVisible = value;
	}

	int32_t CFSecISOTZoneBuff::getRequiredRevision() const {
		return( requiredRevision );
	}

	void CFSecISOTZoneBuff::setRequiredRevision( int32_t value ) {
		requiredRevision = value;
	}

	size_t CFSecISOTZoneBuff::hashCode() const {
		size_t hashCode = 0L;
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOTZoneId();
		hashCode = hashCode + cflib::CFLib::hash( getRequiredIso8601() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredTZName() );
		hashCode = ( hashCode * 0x10000 ) + getRequiredTZHourOffset();
		hashCode = ( hashCode * 0x10000 ) + getRequiredTZMinOffset();
		hashCode = hashCode + cflib::CFLib::hash( getRequiredDescription() );
		if( getRequiredVisible() ) {
			hashCode = ( hashCode * 2 ) + 1;
		}
		else {
			hashCode = hashCode * 2;
		}
		return( hashCode );
	}

	CFSecISOTZoneBuff CFSecISOTZoneBuff::operator =( cfsec::CFSecISOTZoneBuff& src ) {
		setRequiredISOTZoneId( src.getRequiredISOTZoneId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredIso8601( src.getRequiredIso8601() );
		setRequiredTZName( src.getRequiredTZName() );
		setRequiredTZHourOffset( src.getRequiredTZHourOffset() );
		setRequiredTZMinOffset( src.getRequiredTZMinOffset() );
		setRequiredDescription( src.getRequiredDescription() );
		setRequiredVisible( src.getRequiredVisible() );
		return( *this );
	}

	CFSecISOTZoneBuff CFSecISOTZoneBuff::operator =( cfsec::CFSecISOTZoneHBuff& src ) {
		setRequiredISOTZoneId( src.getRequiredISOTZoneId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredIso8601( src.getRequiredIso8601() );
		setRequiredTZName( src.getRequiredTZName() );
		setRequiredTZHourOffset( src.getRequiredTZHourOffset() );
		setRequiredTZMinOffset( src.getRequiredTZMinOffset() );
		setRequiredDescription( src.getRequiredDescription() );
		setRequiredVisible( src.getRequiredVisible() );
		return( *this );
	}

	bool CFSecISOTZoneBuff::operator <( const CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneBuff::operator <( const CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneBuff::operator <( const CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneBuff::operator <( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneBuff::operator <( const CFSecISOTZoneHPKey& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneBuff::operator <( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneBuff::operator <( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneBuff::operator <=( const CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneBuff::operator <=( const CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneBuff::operator <=( const CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneBuff::operator <=( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneBuff::operator <=( const CFSecISOTZoneHPKey& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneBuff::operator <=( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneBuff::operator <=( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneBuff::operator ==( const CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		if( getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZoneBuff::operator ==( const CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZoneBuff::operator ==( const CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZoneBuff::operator ==( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZoneBuff::operator ==( const CFSecISOTZoneHPKey& rhs ) {
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZoneBuff::operator ==( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		if( getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( false );
		}
		if( getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( false );
		}
		if( getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		if( getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		if( getRequiredVisible() != rhs.getRequiredVisible() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZoneBuff::operator ==( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		if( getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( false );
		}
		if( getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( false );
		}
		if( getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		if( getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		if( getRequiredVisible() != rhs.getRequiredVisible() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZoneBuff::operator !=( const CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneBuff::operator !=( const CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneBuff::operator !=( const CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneBuff::operator !=( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneBuff::operator !=( const CFSecISOTZoneHPKey& rhs ) {
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneBuff::operator !=( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( true );
		}
		if( getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredVisible() != rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneBuff::operator !=( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( true );
		}
		if( getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredVisible() != rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneBuff::operator >=( const CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneBuff::operator >=( const CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneBuff::operator >=( const CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneBuff::operator >=( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneBuff::operator >=( const CFSecISOTZoneHPKey& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneBuff::operator >=( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneBuff::operator >=( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneBuff::operator >( const CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneBuff::operator >( const CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneBuff::operator >( const CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneBuff::operator >( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneBuff::operator >( const CFSecISOTZoneHPKey& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneBuff::operator >( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneBuff::operator >( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}

	std::string CFSecISOTZoneBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOTZoneBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ISOTZoneId( "ISOTZoneId" );
		static const std::string S_Iso8601( "Iso8601" );
		static const std::string S_TZName( "TZName" );
		static const std::string S_TZHourOffset( "TZHourOffset" );
		static const std::string S_TZMinOffset( "TZMinOffset" );
		static const std::string S_Description( "Description" );
		static const std::string S_Visible( "Visible" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOTZoneId, getRequiredISOTZoneId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_CreatedBy, getCreatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_UpdatedBy, getUpdatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Iso8601, getRequiredIso8601() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_TZName, getRequiredTZName() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_TZHourOffset, getRequiredTZHourOffset() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_TZMinOffset, getRequiredTZMinOffset() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, getRequiredDescription() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredBoolean( &S_Space, S_Visible, getRequiredVisible() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( lhs.getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		if( lhs.getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( lhs.getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( lhs.getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		if( lhs.getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( false );
		}
		if( lhs.getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( false );
		}
		if( lhs.getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		if( lhs.getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		if( lhs.getRequiredVisible() != rhs.getRequiredVisible() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		if( lhs.getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( false );
		}
		if( lhs.getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( false );
		}
		if( lhs.getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		if( lhs.getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		if( lhs.getRequiredVisible() != rhs.getRequiredVisible() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( lhs.getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( lhs.getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( lhs.getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( lhs.getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( lhs.getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( true );
		}
		if( lhs.getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredVisible() != rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( lhs.getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( lhs.getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( true );
		}
		if( lhs.getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredVisible() != rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOTZoneBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}
}

