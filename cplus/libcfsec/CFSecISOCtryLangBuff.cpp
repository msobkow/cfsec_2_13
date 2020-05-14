// Description: C++18 implementation for a ISOCtryLang buffer object.

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

#include <cfsec/CFSecISOCtryLangByCtryIdxKey.hpp>
#include <cfsec/CFSecISOCtryLangByLangIdxKey.hpp>
#include <cfsec/CFSecSchema.hpp>

namespace cfsec {

	const std::string CFSecISOCtryLangBuff::S_VALUE( "value" );
	const std::string CFSecISOCtryLangBuff::S_VALUE_LENGTH( "value.length()" );

	const std::string CFSecISOCtryLangBuff::GENDEFNAME( "ISOCtryLang" );
	const classcode_t CFSecISOCtryLangBuff::CLASS_CODE = 0xa006L;
	const std::string CFSecISOCtryLangBuff::CLASS_NAME( "CFSecISOCtryLangBuff" );
		const std::string CFSecISOCtryLangBuff::COLNAME_ISOCTRYID( "ISOCtryId" );
		const std::string CFSecISOCtryLangBuff::COLNAME_ISOLANGID( "ISOLangId" );
	const char* CFSecISOCtryLangBuff::S_INIT_CREATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const char* CFSecISOCtryLangBuff::S_INIT_UPDATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const int16_t CFSecISOCtryLangBuff::ISOCTRYID_INIT_VALUE = (int16_t)0;
	const int16_t CFSecISOCtryLangBuff::ISOLANGID_INIT_VALUE = (int16_t)0;
	const int16_t CFSecISOCtryLangBuff::ISOCTRYID_MIN_VALUE = (int16_t)0;
	const int16_t CFSecISOCtryLangBuff::ISOLANGID_MIN_VALUE = (int16_t)0;

	CFSecISOCtryLangBuff::CFSecISOCtryLangBuff()
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
		requiredISOCtryId = cfsec::CFSecISOCtryLangBuff::ISOCTRYID_INIT_VALUE;
		requiredISOLangId = cfsec::CFSecISOCtryLangBuff::ISOLANGID_INIT_VALUE;
	}

	CFSecISOCtryLangBuff::CFSecISOCtryLangBuff( const CFSecISOCtryLangBuff& src )
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
		requiredISOCtryId = cfsec::CFSecISOCtryLangBuff::ISOCTRYID_INIT_VALUE;
		requiredISOLangId = cfsec::CFSecISOCtryLangBuff::ISOLANGID_INIT_VALUE;
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setRequiredISOLangId( src.getRequiredISOLangId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
	}

	CFSecISOCtryLangBuff::~CFSecISOCtryLangBuff() {
		for( int i = 0; i < 16; i++ ) {
			createdByUserId[i] = 0;
		}
		for( int i = 0; i < 16; i++ ) {
			updatedByUserId[i] = 0;
		}
	}

	cflib::ICFLibCloneableObj* CFSecISOCtryLangBuff::clone() {
		CFSecISOCtryLangBuff* copy = new CFSecISOCtryLangBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const std::string& CFSecISOCtryLangBuff::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecISOCtryLangBuff::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecISOCtryLangBuff::implementsClassCode( const classcode_t argClassCode ) {
		if( argClassCode == CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	const uuid_ptr_t CFSecISOCtryLangBuff::getCreatedByUserId() const {
		return( createdByUserId );
	}

	void CFSecISOCtryLangBuff::setCreatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( createdByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecISOCtryLangBuff::getCreatedAt() const {
		return( createdAt );
	}

	void CFSecISOCtryLangBuff::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		createdAt = value;
	}

	const uuid_ptr_t CFSecISOCtryLangBuff::getUpdatedByUserId() const {
		return( updatedByUserId );
	}

	void CFSecISOCtryLangBuff::setUpdatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( updatedByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecISOCtryLangBuff::getUpdatedAt() const {
		return( updatedAt );
	}

	void CFSecISOCtryLangBuff::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		updatedAt = value;
	}
	const int16_t CFSecISOCtryLangBuff::getRequiredISOCtryId() const {
		return( requiredISOCtryId );
	}

	const int16_t* CFSecISOCtryLangBuff::getRequiredISOCtryIdReference() const {
		return( &requiredISOCtryId );
	}

	void CFSecISOCtryLangBuff::setRequiredISOCtryId( const int16_t value ) {
		static const std::string S_ProcName( "setRequiredISOCtryId" );
		if( value < cfsec::CFSecISOCtryLangBuff::ISOCTRYID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOCtryLangBuff::ISOCTRYID_MIN_VALUE );
		}
		requiredISOCtryId = value;
	}

	const int16_t CFSecISOCtryLangBuff::getRequiredISOLangId() const {
		return( requiredISOLangId );
	}

	const int16_t* CFSecISOCtryLangBuff::getRequiredISOLangIdReference() const {
		return( &requiredISOLangId );
	}

	void CFSecISOCtryLangBuff::setRequiredISOLangId( const int16_t value ) {
		static const std::string S_ProcName( "setRequiredISOLangId" );
		if( value < cfsec::CFSecISOCtryLangBuff::ISOLANGID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOCtryLangBuff::ISOLANGID_MIN_VALUE );
		}
		requiredISOLangId = value;
	}

	int32_t CFSecISOCtryLangBuff::getRequiredRevision() const {
		return( requiredRevision );
	}

	void CFSecISOCtryLangBuff::setRequiredRevision( int32_t value ) {
		requiredRevision = value;
	}

	size_t CFSecISOCtryLangBuff::hashCode() const {
		size_t hashCode = 0L;
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOCtryId();
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOLangId();
		return( hashCode );
	}

	CFSecISOCtryLangBuff CFSecISOCtryLangBuff::operator =( cfsec::CFSecISOCtryLangBuff& src ) {
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setRequiredISOLangId( src.getRequiredISOLangId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		return( *this );
	}

	CFSecISOCtryLangBuff CFSecISOCtryLangBuff::operator =( cfsec::CFSecISOCtryLangHBuff& src ) {
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setRequiredISOLangId( src.getRequiredISOLangId() );
		setRequiredRevision( src.getRequiredRevision() );
		return( *this );
	}

	bool CFSecISOCtryLangBuff::operator <( const CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangBuff::operator <( const CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangBuff::operator <( const CFSecISOCtryLangPKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangBuff::operator <( const CFSecISOCtryLangHPKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangBuff::operator <( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangBuff::operator <( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangBuff::operator <=( const CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangBuff::operator <=( const CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangBuff::operator <=( const CFSecISOCtryLangPKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangBuff::operator <=( const CFSecISOCtryLangHPKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangBuff::operator <=( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangBuff::operator <=( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangBuff::operator ==( const CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryLangBuff::operator ==( const CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryLangBuff::operator ==( const CFSecISOCtryLangPKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryLangBuff::operator ==( const CFSecISOCtryLangHPKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryLangBuff::operator ==( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryLangBuff::operator ==( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryLangBuff::operator !=( const CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangBuff::operator !=( const CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangBuff::operator !=( const CFSecISOCtryLangPKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangBuff::operator !=( const CFSecISOCtryLangHPKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangBuff::operator !=( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangBuff::operator !=( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangBuff::operator >=( const CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangBuff::operator >=( const CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangBuff::operator >=( const CFSecISOCtryLangPKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangBuff::operator >=( const CFSecISOCtryLangHPKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangBuff::operator >=( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangBuff::operator >=( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangBuff::operator >( const CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangBuff::operator >( const CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangBuff::operator >( const CFSecISOCtryLangPKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangBuff::operator >( const CFSecISOCtryLangHPKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangBuff::operator >( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangBuff::operator >( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	std::string CFSecISOCtryLangBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOCtryLangBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ISOCtryId( "ISOCtryId" );
		static const std::string S_ISOLangId( "ISOLangId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCtryId, getRequiredISOCtryId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOLangId, getRequiredISOLangId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_CreatedBy, getCreatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_UpdatedBy, getUpdatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, getRequiredRevision() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryLangBuff& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}
}

