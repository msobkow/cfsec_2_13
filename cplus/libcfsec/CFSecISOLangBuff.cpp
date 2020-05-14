// Description: C++18 implementation for a ISOLang buffer object.

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

#include <cfsec/CFSecISOLangByCode3IdxKey.hpp>
#include <cfsec/CFSecISOLangByCode2IdxKey.hpp>
#include <cfsec/CFSecSchema.hpp>

namespace cfsec {

	const std::string CFSecISOLangBuff::S_VALUE( "value" );
	const std::string CFSecISOLangBuff::S_VALUE_LENGTH( "value.length()" );

	const std::string CFSecISOLangBuff::GENDEFNAME( "ISOLang" );
	const classcode_t CFSecISOLangBuff::CLASS_CODE = 0xa007L;
	const std::string CFSecISOLangBuff::CLASS_NAME( "CFSecISOLangBuff" );
		const std::string CFSecISOLangBuff::COLNAME_ISOLANGID( "ISOLangId" );
		const std::string CFSecISOLangBuff::COLNAME_ISO6392CODE( "ISO6392Code" );
		const std::string CFSecISOLangBuff::COLNAME_ISO6391CODE( "ISO6391Code" );
		const std::string CFSecISOLangBuff::COLNAME_ENGLISHNAME( "EnglishName" );
	const char* CFSecISOLangBuff::S_INIT_CREATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const char* CFSecISOLangBuff::S_INIT_UPDATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const int16_t CFSecISOLangBuff::ISOLANGID_INIT_VALUE = (int16_t)0;
	const std::string CFSecISOLangBuff::ISO6392CODE_INIT_VALUE( "" );
	const std::string CFSecISOLangBuff::ISO6391CODE_INIT_VALUE( "" );
	const std::string CFSecISOLangBuff::ENGLISHNAME_INIT_VALUE( "" );
	const int16_t CFSecISOLangBuff::ISOLANGID_MIN_VALUE = (int16_t)0;
	const std::string::size_type CFSecISOLangBuff::ISO6392CODE_MAX_LEN = 3;
	const std::string::size_type CFSecISOLangBuff::ISO6391CODE_MAX_LEN = 2;
	const std::string::size_type CFSecISOLangBuff::ENGLISHNAME_MAX_LEN = 64;

	CFSecISOLangBuff::CFSecISOLangBuff()
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
		requiredISOLangId = cfsec::CFSecISOLangBuff::ISOLANGID_INIT_VALUE;
		requiredISO6392Code = new std::string( cfsec::CFSecISOLangBuff::ISO6392CODE_INIT_VALUE );
		optionalISO6391Code = NULL;
		requiredEnglishName = new std::string( cfsec::CFSecISOLangBuff::ENGLISHNAME_INIT_VALUE );
	}

	CFSecISOLangBuff::CFSecISOLangBuff( const CFSecISOLangBuff& src )
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
		requiredISOLangId = cfsec::CFSecISOLangBuff::ISOLANGID_INIT_VALUE;
		requiredISO6392Code = new std::string( cfsec::CFSecISOLangBuff::ISO6392CODE_INIT_VALUE );
		optionalISO6391Code = NULL;
		requiredEnglishName = new std::string( cfsec::CFSecISOLangBuff::ENGLISHNAME_INIT_VALUE );
		setRequiredISOLangId( src.getRequiredISOLangId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredISO6392Code( src.getRequiredISO6392Code() );
		if( src.isOptionalISO6391CodeNull() ) {
			setOptionalISO6391CodeNull();
		}
		else {
			setOptionalISO6391CodeValue( src.getOptionalISO6391CodeValue() );
		}
		setRequiredEnglishName( src.getRequiredEnglishName() );
	}

	CFSecISOLangBuff::~CFSecISOLangBuff() {
		if( requiredISO6392Code != NULL ) {
			delete requiredISO6392Code;
			requiredISO6392Code = NULL;
		}
		if( optionalISO6391Code != NULL ) {
			delete optionalISO6391Code;
			optionalISO6391Code = NULL;
		}
		if( requiredEnglishName != NULL ) {
			delete requiredEnglishName;
			requiredEnglishName = NULL;
		}
		for( int i = 0; i < 16; i++ ) {
			createdByUserId[i] = 0;
		}
		for( int i = 0; i < 16; i++ ) {
			updatedByUserId[i] = 0;
		}
	}

	cflib::ICFLibCloneableObj* CFSecISOLangBuff::clone() {
		CFSecISOLangBuff* copy = new CFSecISOLangBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const std::string& CFSecISOLangBuff::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecISOLangBuff::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecISOLangBuff::implementsClassCode( const classcode_t argClassCode ) {
		if( argClassCode == CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	const uuid_ptr_t CFSecISOLangBuff::getCreatedByUserId() const {
		return( createdByUserId );
	}

	void CFSecISOLangBuff::setCreatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( createdByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecISOLangBuff::getCreatedAt() const {
		return( createdAt );
	}

	void CFSecISOLangBuff::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		createdAt = value;
	}

	const uuid_ptr_t CFSecISOLangBuff::getUpdatedByUserId() const {
		return( updatedByUserId );
	}

	void CFSecISOLangBuff::setUpdatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( updatedByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecISOLangBuff::getUpdatedAt() const {
		return( updatedAt );
	}

	void CFSecISOLangBuff::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		updatedAt = value;
	}
	const int16_t CFSecISOLangBuff::getRequiredISOLangId() const {
		return( requiredISOLangId );
	}

	const int16_t* CFSecISOLangBuff::getRequiredISOLangIdReference() const {
		return( &requiredISOLangId );
	}

	void CFSecISOLangBuff::setRequiredISOLangId( const int16_t value ) {
		static const std::string S_ProcName( "setRequiredISOLangId" );
		if( value < cfsec::CFSecISOLangBuff::ISOLANGID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOLangBuff::ISOLANGID_MIN_VALUE );
		}
		requiredISOLangId = value;
	}

	const std::string& CFSecISOLangBuff::getRequiredISO6392Code() const {
		return( *requiredISO6392Code );
	}

	const std::string* CFSecISOLangBuff::getRequiredISO6392CodeReference() const {
		return( requiredISO6392Code );
	}

	void CFSecISOLangBuff::setRequiredISO6392Code( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredISO6392Code" );
		if( value.length() > CFSecISOLangBuff::ISO6392CODE_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecISOLangBuff::ISO6392CODE_MAX_LEN );
		}
		if( requiredISO6392Code != NULL ) {
			delete requiredISO6392Code;
			requiredISO6392Code = NULL;
		}
		requiredISO6392Code = new std::string( value );
	}

	const bool CFSecISOLangBuff::isOptionalISO6391CodeNull() const {
		return( optionalISO6391Code == NULL );
	}

	const std::string& CFSecISOLangBuff::getOptionalISO6391CodeValue() const {
		static const std::string S_ProcName( "getOptionalISO6391CodeValue" );
		if( optionalISO6391Code == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( *optionalISO6391Code );
	}

	const std::string* CFSecISOLangBuff::getOptionalISO6391CodeReference() const {
		return( optionalISO6391Code );
	}

	void CFSecISOLangBuff::setOptionalISO6391CodeNull() {
		if( optionalISO6391Code != NULL ) {
			delete optionalISO6391Code;
			optionalISO6391Code = NULL;
		}
	}

	void CFSecISOLangBuff::setOptionalISO6391CodeValue( const std::string& value ) {
		static const std::string S_ProcName( "setOptionalISO6391CodeValue" );
		if( value.length() > CFSecISOLangBuff::ISO6391CODE_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecISOLangBuff::ISO6391CODE_MAX_LEN );
		}
		if( optionalISO6391Code != NULL ) {
			delete optionalISO6391Code;
			optionalISO6391Code = NULL;
		}
		optionalISO6391Code = new std::string( value );
	}

	const std::string& CFSecISOLangBuff::getRequiredEnglishName() const {
		return( *requiredEnglishName );
	}

	const std::string* CFSecISOLangBuff::getRequiredEnglishNameReference() const {
		return( requiredEnglishName );
	}

	void CFSecISOLangBuff::setRequiredEnglishName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredEnglishName" );
		if( value.length() > CFSecISOLangBuff::ENGLISHNAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecISOLangBuff::ENGLISHNAME_MAX_LEN );
		}
		if( requiredEnglishName != NULL ) {
			delete requiredEnglishName;
			requiredEnglishName = NULL;
		}
		requiredEnglishName = new std::string( value );
	}

	int32_t CFSecISOLangBuff::getRequiredRevision() const {
		return( requiredRevision );
	}

	void CFSecISOLangBuff::setRequiredRevision( int32_t value ) {
		requiredRevision = value;
	}

	size_t CFSecISOLangBuff::hashCode() const {
		size_t hashCode = 0L;
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOLangId();
		hashCode = hashCode + cflib::CFLib::hash( getRequiredISO6392Code() );
		if( ! isOptionalISO6391CodeNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalISO6391CodeValue() );
		}
		hashCode = hashCode + cflib::CFLib::hash( getRequiredEnglishName() );
		return( hashCode );
	}

	CFSecISOLangBuff CFSecISOLangBuff::operator =( cfsec::CFSecISOLangBuff& src ) {
		setRequiredISOLangId( src.getRequiredISOLangId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredISO6392Code( src.getRequiredISO6392Code() );
		if( src.isOptionalISO6391CodeNull() ) {
			setOptionalISO6391CodeNull();
		}
		else {
			setOptionalISO6391CodeValue( src.getOptionalISO6391CodeValue() );
		}
		setRequiredEnglishName( src.getRequiredEnglishName() );
		return( *this );
	}

	CFSecISOLangBuff CFSecISOLangBuff::operator =( cfsec::CFSecISOLangHBuff& src ) {
		setRequiredISOLangId( src.getRequiredISOLangId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredISO6392Code( src.getRequiredISO6392Code() );
		if( src.isOptionalISO6391CodeNull() ) {
			setOptionalISO6391CodeNull();
		}
		else {
			setOptionalISO6391CodeValue( src.getOptionalISO6391CodeValue() );
		}
		setRequiredEnglishName( src.getRequiredEnglishName() );
		return( *this );
	}

	bool CFSecISOLangBuff::operator <( const CFSecISOLangByCode3IdxKey& rhs ) {
		if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangBuff::operator <( const CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecISOLangBuff::operator <( const CFSecISOLangPKey& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangBuff::operator <( const CFSecISOLangHPKey& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangBuff::operator <( const CFSecISOLangHBuff& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		if( getRequiredEnglishName() > rhs.getRequiredEnglishName() ) {
			return( false );
		}
		else if( getRequiredEnglishName() < rhs.getRequiredEnglishName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangBuff::operator <( const CFSecISOLangBuff& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		if( getRequiredEnglishName() > rhs.getRequiredEnglishName() ) {
			return( false );
		}
		else if( getRequiredEnglishName() < rhs.getRequiredEnglishName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangBuff::operator <=( const CFSecISOLangByCode3IdxKey& rhs ) {
		if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangBuff::operator <=( const CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecISOLangBuff::operator <=( const CFSecISOLangPKey& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangBuff::operator <=( const CFSecISOLangHPKey& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangBuff::operator <=( const CFSecISOLangHBuff& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		if( getRequiredEnglishName() > rhs.getRequiredEnglishName() ) {
			return( false );
		}
		else if( getRequiredEnglishName() < rhs.getRequiredEnglishName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangBuff::operator <=( const CFSecISOLangBuff& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		if( getRequiredEnglishName() > rhs.getRequiredEnglishName() ) {
			return( false );
		}
		else if( getRequiredEnglishName() < rhs.getRequiredEnglishName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangBuff::operator ==( const CFSecISOLangByCode3IdxKey& rhs ) {
		if( getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOLangBuff::operator ==( const CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				if( getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecISOLangBuff::operator ==( const CFSecISOLangPKey& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOLangBuff::operator ==( const CFSecISOLangHPKey& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOLangBuff::operator ==( const CFSecISOLangHBuff& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		if( getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		if( ! isOptionalISO6391CodeNull() ) {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				if( getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		if( getRequiredEnglishName() != rhs.getRequiredEnglishName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOLangBuff::operator ==( const CFSecISOLangBuff& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		if( getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		if( ! isOptionalISO6391CodeNull() ) {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				if( getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		if( getRequiredEnglishName() != rhs.getRequiredEnglishName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOLangBuff::operator !=( const CFSecISOLangByCode3IdxKey& rhs ) {
		if( getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangBuff::operator !=( const CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecISOLangBuff::operator !=( const CFSecISOLangPKey& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangBuff::operator !=( const CFSecISOLangHPKey& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangBuff::operator !=( const CFSecISOLangHBuff& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		if( getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		if( getRequiredEnglishName() != rhs.getRequiredEnglishName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangBuff::operator !=( const CFSecISOLangBuff& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		if( getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		if( getRequiredEnglishName() != rhs.getRequiredEnglishName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangBuff::operator >=( const CFSecISOLangByCode3IdxKey& rhs ) {
		if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangBuff::operator >=( const CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecISOLangBuff::operator >=( const CFSecISOLangPKey& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangBuff::operator >=( const CFSecISOLangHPKey& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangBuff::operator >=( const CFSecISOLangHBuff& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		if( getRequiredEnglishName() < rhs.getRequiredEnglishName() ) {
			return( false );
		}
		else if( getRequiredEnglishName() > rhs.getRequiredEnglishName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangBuff::operator >=( const CFSecISOLangBuff& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		if( getRequiredEnglishName() < rhs.getRequiredEnglishName() ) {
			return( false );
		}
		else if( getRequiredEnglishName() > rhs.getRequiredEnglishName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangBuff::operator >( const CFSecISOLangByCode3IdxKey& rhs ) {
		if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangBuff::operator >( const CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFSecISOLangBuff::operator >( const CFSecISOLangPKey& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangBuff::operator >( const CFSecISOLangHPKey& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangBuff::operator >( const CFSecISOLangHBuff& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		if( getRequiredEnglishName() < rhs.getRequiredEnglishName() ) {
			return( false );
		}
		else if( getRequiredEnglishName() > rhs.getRequiredEnglishName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangBuff::operator >( const CFSecISOLangBuff& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		if( getRequiredEnglishName() < rhs.getRequiredEnglishName() ) {
			return( false );
		}
		else if( getRequiredEnglishName() > rhs.getRequiredEnglishName() ) {
			return( true );
		}
		return( false );
	}

	std::string CFSecISOLangBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOLangBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ISOLangId( "ISOLangId" );
		static const std::string S_ISO6392Code( "ISO6392Code" );
		static const std::string S_ISO6391Code( "ISO6391Code" );
		static const std::string S_EnglishName( "EnglishName" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOLangId, getRequiredISOLangId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_CreatedBy, getCreatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_UpdatedBy, getUpdatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_ISO6392Code, getRequiredISO6392Code() ) );
		if( ! isOptionalISO6391CodeNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_ISO6391Code, getOptionalISO6391CodeValue() ) );
		}
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_EnglishName, getRequiredEnglishName() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs ) {
		if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangPKey& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredEnglishName() > rhs.getRequiredEnglishName() ) {
			return( false );
		}
		else if( lhs.getRequiredEnglishName() < rhs.getRequiredEnglishName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredEnglishName() > rhs.getRequiredEnglishName() ) {
			return( false );
		}
		else if( lhs.getRequiredEnglishName() < rhs.getRequiredEnglishName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs ) {
		if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangPKey& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredEnglishName() > rhs.getRequiredEnglishName() ) {
			return( false );
		}
		else if( lhs.getRequiredEnglishName() < rhs.getRequiredEnglishName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredEnglishName() > rhs.getRequiredEnglishName() ) {
			return( false );
		}
		else if( lhs.getRequiredEnglishName() < rhs.getRequiredEnglishName() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs ) {
		if( lhs.getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				if( lhs.getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangPKey& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		if( lhs.getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				if( lhs.getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredEnglishName() != rhs.getRequiredEnglishName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		if( lhs.getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				if( lhs.getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredEnglishName() != rhs.getRequiredEnglishName() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs ) {
		if( lhs.getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( lhs.getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangPKey& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		if( lhs.getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( lhs.getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredEnglishName() != rhs.getRequiredEnglishName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		if( lhs.getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( lhs.getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredEnglishName() != rhs.getRequiredEnglishName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs ) {
		if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangPKey& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredEnglishName() < rhs.getRequiredEnglishName() ) {
			return( false );
		}
		else if( lhs.getRequiredEnglishName() > rhs.getRequiredEnglishName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredEnglishName() < rhs.getRequiredEnglishName() ) {
			return( false );
		}
		else if( lhs.getRequiredEnglishName() > rhs.getRequiredEnglishName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs ) {
		if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangPKey& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredEnglishName() < rhs.getRequiredEnglishName() ) {
			return( false );
		}
		else if( lhs.getRequiredEnglishName() > rhs.getRequiredEnglishName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOLangBuff& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredEnglishName() < rhs.getRequiredEnglishName() ) {
			return( false );
		}
		else if( lhs.getRequiredEnglishName() > rhs.getRequiredEnglishName() ) {
			return( true );
		}
		return( false );
	}
}

