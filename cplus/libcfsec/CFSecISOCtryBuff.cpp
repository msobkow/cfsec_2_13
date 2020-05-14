// Description: C++18 implementation for a ISOCtry buffer object.

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

#include <cfsec/CFSecISOCtryByISOCodeIdxKey.hpp>
#include <cfsec/CFSecISOCtryByNameIdxKey.hpp>
#include <cfsec/CFSecSchema.hpp>

namespace cfsec {

	const std::string CFSecISOCtryBuff::S_VALUE( "value" );
	const std::string CFSecISOCtryBuff::S_VALUE_LENGTH( "value.length()" );

	const std::string CFSecISOCtryBuff::GENDEFNAME( "ISOCtry" );
	const classcode_t CFSecISOCtryBuff::CLASS_CODE = 0xa004L;
	const std::string CFSecISOCtryBuff::CLASS_NAME( "CFSecISOCtryBuff" );
		const std::string CFSecISOCtryBuff::COLNAME_ISOCTRYID( "ISOCtryId" );
		const std::string CFSecISOCtryBuff::COLNAME_ISOCODE( "ISOCode" );
		const std::string CFSecISOCtryBuff::COLNAME_NAME( "Name" );
	const char* CFSecISOCtryBuff::S_INIT_CREATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const char* CFSecISOCtryBuff::S_INIT_UPDATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const int16_t CFSecISOCtryBuff::ISOCTRYID_INIT_VALUE = (int16_t)0;
	const std::string CFSecISOCtryBuff::ISOCODE_INIT_VALUE( "" );
	const std::string CFSecISOCtryBuff::NAME_INIT_VALUE( "" );
	const int16_t CFSecISOCtryBuff::ISOCTRYID_MIN_VALUE = (int16_t)0;
	const std::string::size_type CFSecISOCtryBuff::ISOCODE_MAX_LEN = 2;
	const std::string::size_type CFSecISOCtryBuff::NAME_MAX_LEN = 64;

	CFSecISOCtryBuff::CFSecISOCtryBuff()
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
		requiredISOCtryId = cfsec::CFSecISOCtryBuff::ISOCTRYID_INIT_VALUE;
		requiredISOCode = new std::string( cfsec::CFSecISOCtryBuff::ISOCODE_INIT_VALUE );
		requiredName = new std::string( cfsec::CFSecISOCtryBuff::NAME_INIT_VALUE );
	}

	CFSecISOCtryBuff::CFSecISOCtryBuff( const CFSecISOCtryBuff& src )
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
		requiredISOCtryId = cfsec::CFSecISOCtryBuff::ISOCTRYID_INIT_VALUE;
		requiredISOCode = new std::string( cfsec::CFSecISOCtryBuff::ISOCODE_INIT_VALUE );
		requiredName = new std::string( cfsec::CFSecISOCtryBuff::NAME_INIT_VALUE );
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredISOCode( src.getRequiredISOCode() );
		setRequiredName( src.getRequiredName() );
	}

	CFSecISOCtryBuff::~CFSecISOCtryBuff() {
		if( requiredISOCode != NULL ) {
			delete requiredISOCode;
			requiredISOCode = NULL;
		}
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
		for( int i = 0; i < 16; i++ ) {
			createdByUserId[i] = 0;
		}
		for( int i = 0; i < 16; i++ ) {
			updatedByUserId[i] = 0;
		}
	}

	cflib::ICFLibCloneableObj* CFSecISOCtryBuff::clone() {
		CFSecISOCtryBuff* copy = new CFSecISOCtryBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const std::string& CFSecISOCtryBuff::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecISOCtryBuff::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecISOCtryBuff::implementsClassCode( const classcode_t argClassCode ) {
		if( argClassCode == CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	const uuid_ptr_t CFSecISOCtryBuff::getCreatedByUserId() const {
		return( createdByUserId );
	}

	void CFSecISOCtryBuff::setCreatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( createdByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecISOCtryBuff::getCreatedAt() const {
		return( createdAt );
	}

	void CFSecISOCtryBuff::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		createdAt = value;
	}

	const uuid_ptr_t CFSecISOCtryBuff::getUpdatedByUserId() const {
		return( updatedByUserId );
	}

	void CFSecISOCtryBuff::setUpdatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( updatedByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecISOCtryBuff::getUpdatedAt() const {
		return( updatedAt );
	}

	void CFSecISOCtryBuff::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		updatedAt = value;
	}
	const int16_t CFSecISOCtryBuff::getRequiredISOCtryId() const {
		return( requiredISOCtryId );
	}

	const int16_t* CFSecISOCtryBuff::getRequiredISOCtryIdReference() const {
		return( &requiredISOCtryId );
	}

	void CFSecISOCtryBuff::setRequiredISOCtryId( const int16_t value ) {
		static const std::string S_ProcName( "setRequiredISOCtryId" );
		if( value < cfsec::CFSecISOCtryBuff::ISOCTRYID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOCtryBuff::ISOCTRYID_MIN_VALUE );
		}
		requiredISOCtryId = value;
	}

	const std::string& CFSecISOCtryBuff::getRequiredISOCode() const {
		return( *requiredISOCode );
	}

	const std::string* CFSecISOCtryBuff::getRequiredISOCodeReference() const {
		return( requiredISOCode );
	}

	void CFSecISOCtryBuff::setRequiredISOCode( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredISOCode" );
		if( value.length() > CFSecISOCtryBuff::ISOCODE_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecISOCtryBuff::ISOCODE_MAX_LEN );
		}
		if( requiredISOCode != NULL ) {
			delete requiredISOCode;
			requiredISOCode = NULL;
		}
		requiredISOCode = new std::string( value );
	}

	const std::string& CFSecISOCtryBuff::getRequiredName() const {
		return( *requiredName );
	}

	const std::string* CFSecISOCtryBuff::getRequiredNameReference() const {
		return( requiredName );
	}

	void CFSecISOCtryBuff::setRequiredName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredName" );
		if( value.length() > CFSecISOCtryBuff::NAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecISOCtryBuff::NAME_MAX_LEN );
		}
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
		requiredName = new std::string( value );
	}

	int32_t CFSecISOCtryBuff::getRequiredRevision() const {
		return( requiredRevision );
	}

	void CFSecISOCtryBuff::setRequiredRevision( int32_t value ) {
		requiredRevision = value;
	}

	size_t CFSecISOCtryBuff::hashCode() const {
		size_t hashCode = 0L;
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOCtryId();
		hashCode = hashCode + cflib::CFLib::hash( getRequiredISOCode() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredName() );
		return( hashCode );
	}

	CFSecISOCtryBuff CFSecISOCtryBuff::operator =( cfsec::CFSecISOCtryBuff& src ) {
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredISOCode( src.getRequiredISOCode() );
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

	CFSecISOCtryBuff CFSecISOCtryBuff::operator =( cfsec::CFSecISOCtryHBuff& src ) {
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredISOCode( src.getRequiredISOCode() );
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

	bool CFSecISOCtryBuff::operator <( const CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryBuff::operator <( const CFSecISOCtryByNameIdxKey& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryBuff::operator <( const CFSecISOCtryPKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryBuff::operator <( const CFSecISOCtryHPKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryBuff::operator <( const CFSecISOCtryHBuff& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryBuff::operator <( const CFSecISOCtryBuff& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryBuff::operator <=( const CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryBuff::operator <=( const CFSecISOCtryByNameIdxKey& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryBuff::operator <=( const CFSecISOCtryPKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryBuff::operator <=( const CFSecISOCtryHPKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryBuff::operator <=( const CFSecISOCtryHBuff& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryBuff::operator <=( const CFSecISOCtryBuff& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryBuff::operator ==( const CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryBuff::operator ==( const CFSecISOCtryByNameIdxKey& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryBuff::operator ==( const CFSecISOCtryPKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryBuff::operator ==( const CFSecISOCtryHPKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryBuff::operator ==( const CFSecISOCtryHBuff& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryBuff::operator ==( const CFSecISOCtryBuff& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryBuff::operator !=( const CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryBuff::operator !=( const CFSecISOCtryByNameIdxKey& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryBuff::operator !=( const CFSecISOCtryPKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryBuff::operator !=( const CFSecISOCtryHPKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryBuff::operator !=( const CFSecISOCtryHBuff& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryBuff::operator !=( const CFSecISOCtryBuff& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryBuff::operator >=( const CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryBuff::operator >=( const CFSecISOCtryByNameIdxKey& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryBuff::operator >=( const CFSecISOCtryPKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryBuff::operator >=( const CFSecISOCtryHPKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryBuff::operator >=( const CFSecISOCtryHBuff& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryBuff::operator >=( const CFSecISOCtryBuff& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryBuff::operator >( const CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryBuff::operator >( const CFSecISOCtryByNameIdxKey& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryBuff::operator >( const CFSecISOCtryPKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryBuff::operator >( const CFSecISOCtryHPKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryBuff::operator >( const CFSecISOCtryHBuff& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryBuff::operator >( const CFSecISOCtryBuff& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	std::string CFSecISOCtryBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOCtryBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ISOCtryId( "ISOCtryId" );
		static const std::string S_ISOCode( "ISOCode" );
		static const std::string S_Name( "Name" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCtryId, getRequiredISOCtryId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_CreatedBy, getCreatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_UpdatedBy, getUpdatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_ISOCode, getRequiredISOCode() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, getRequiredName() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryByNameIdxKey& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryByNameIdxKey& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryByNameIdxKey& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryByNameIdxKey& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryByNameIdxKey& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryByNameIdxKey& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryBuff& lhs, const cfsec::CFSecISOCtryBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}
}

