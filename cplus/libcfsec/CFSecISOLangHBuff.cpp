// Description: C++18 implementation of a ISOLang history buffer object.

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

#include <cfsec/CFSecHPKey.hpp>
#include <cfsec/CFSecISOLangPKey.hpp>
#include <cfsec/CFSecISOLangBuff.hpp>
#include <cfsec/CFSecISOLangHPKey.hpp>
#include <cfsec/CFSecISOLangHBuff.hpp>
#include <cfsec/CFSecISOLangByCode3IdxKey.hpp>
#include <cfsec/CFSecISOLangByCode2IdxKey.hpp>

namespace cfsec {

	const std::string CFSecISOLangHBuff::CLASS_NAME( "CFSecISOLangHBuff" );
	CFSecISOLangHBuff::CFSecISOLangHBuff()
	: CFSecHPKey(), cflib::ICFLibCloneableObj() {
		requiredISOLangId = cfsec::CFSecISOLangBuff::ISOLANGID_INIT_VALUE;
		requiredISO6392Code = new std::string( cfsec::CFSecISOLangBuff::ISO6392CODE_INIT_VALUE );
		optionalISO6391Code = NULL;
		requiredEnglishName = new std::string( cfsec::CFSecISOLangBuff::ENGLISHNAME_INIT_VALUE );
	}

	CFSecISOLangHBuff::CFSecISOLangHBuff( const CFSecISOLangHBuff& src )
	: CFSecHPKey(), cflib::ICFLibCloneableObj() {
		requiredISOLangId = cfsec::CFSecISOLangBuff::ISOLANGID_INIT_VALUE;
		requiredISO6392Code = new std::string( cfsec::CFSecISOLangBuff::ISO6392CODE_INIT_VALUE );
		optionalISO6391Code = NULL;
		requiredEnglishName = new std::string( cfsec::CFSecISOLangBuff::ENGLISHNAME_INIT_VALUE );
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
	}

	CFSecISOLangHBuff::~CFSecISOLangHBuff() {
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
	}

	cflib::ICFLibCloneableObj* CFSecISOLangHBuff::clone() {
		CFSecISOLangHBuff* copy = new CFSecISOLangHBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const int16_t CFSecISOLangHBuff::getRequiredISOLangId() const {
		return( requiredISOLangId );
	}

	const int16_t* CFSecISOLangHBuff::getRequiredISOLangIdReference() const {
		return( &requiredISOLangId );
	}

	void CFSecISOLangHBuff::setRequiredISOLangId( const int16_t value ) {
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

	const std::string& CFSecISOLangHBuff::getRequiredISO6392Code() const {
		return( *requiredISO6392Code );
	}

	const std::string* CFSecISOLangHBuff::getRequiredISO6392CodeReference() const {
		return( requiredISO6392Code );
	}

	void CFSecISOLangHBuff::setRequiredISO6392Code( const std::string& value ) {
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

	const std::string& CFSecISOLangHBuff::getOptionalISO6391CodeValue() const {
		static const std::string S_ProcName( "getOptionalISO6391CodeValue" );
		if( optionalISO6391Code == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( *optionalISO6391Code );
	}

	const std::string* CFSecISOLangHBuff::getOptionalISO6391CodeReference() const {
		return( optionalISO6391Code );
	}

	const bool CFSecISOLangHBuff::isOptionalISO6391CodeNull() const {
		return( optionalISO6391Code == NULL );
	}

	void CFSecISOLangHBuff::setOptionalISO6391CodeNull() {
		if( optionalISO6391Code != NULL ) {
			delete optionalISO6391Code;
			optionalISO6391Code = NULL;
		}
	}

	void CFSecISOLangHBuff::setOptionalISO6391CodeValue( const std::string& value ) {
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

	const std::string& CFSecISOLangHBuff::getRequiredEnglishName() const {
		return( *requiredEnglishName );
	}

	const std::string* CFSecISOLangHBuff::getRequiredEnglishNameReference() const {
		return( requiredEnglishName );
	}

	void CFSecISOLangHBuff::setRequiredEnglishName( const std::string& value ) {
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

	size_t CFSecISOLangHBuff::hashCode() const {
		size_t hashCode = CFSecHPKey::hashCode();
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOLangId();
		hashCode = hashCode + cflib::CFLib::hash( getRequiredISO6392Code() );
		if( ! isOptionalISO6391CodeNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalISO6391CodeValue() );
		}
		hashCode = hashCode + cflib::CFLib::hash( getRequiredEnglishName() );
		return( hashCode );
	}

	CFSecISOLangHBuff CFSecISOLangHBuff::operator =( cfsec::CFSecISOLangBuff& src ) {
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

	CFSecISOLangHBuff CFSecISOLangHBuff::operator =( cfsec::CFSecISOLangHBuff& src ) {
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

	bool CFSecISOLangHBuff::operator <( const CFSecISOLangByCode3IdxKey& rhs ) {
		if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangHBuff::operator <( const CFSecISOLangByCode2IdxKey& rhs ) {
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

	bool CFSecISOLangHBuff::operator <( const CFSecISOLangPKey& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangHBuff::operator <( const CFSecISOLangHPKey& rhs ) {
		if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() >= rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() <= rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() >= rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() <= rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangHBuff::operator <( const CFSecISOLangHBuff& rhs ) {
		if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() >= rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() <= rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() >= rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() <= rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
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

	bool CFSecISOLangHBuff::operator <( const CFSecISOLangBuff& rhs ) {
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

	bool CFSecISOLangHBuff::operator <=( const CFSecISOLangByCode3IdxKey& rhs ) {
		if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangHBuff::operator <=( const CFSecISOLangByCode2IdxKey& rhs ) {
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

	bool CFSecISOLangHBuff::operator <=( const CFSecISOLangPKey& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangHBuff::operator <=( const CFSecISOLangHPKey& rhs ) {
		if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangHBuff::operator <=( const CFSecISOLangHBuff& rhs ) {
		if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
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

	bool CFSecISOLangHBuff::operator <=( const CFSecISOLangBuff& rhs ) {
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

	bool CFSecISOLangHBuff::operator ==( const CFSecISOLangByCode3IdxKey& rhs ) {
		if( getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOLangHBuff::operator ==( const CFSecISOLangByCode2IdxKey& rhs ) {
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

	bool CFSecISOLangHBuff::operator ==( const CFSecISOLangPKey& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOLangHBuff::operator ==( const CFSecISOLangHPKey& rhs ) {
		if( getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOLangHBuff::operator ==( const CFSecISOLangHBuff& rhs ) {
		if( getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
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

	bool CFSecISOLangHBuff::operator ==( const CFSecISOLangBuff& rhs ) {
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

	bool CFSecISOLangHBuff::operator !=( const CFSecISOLangByCode3IdxKey& rhs ) {
		if( getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangHBuff::operator !=( const CFSecISOLangByCode2IdxKey& rhs ) {
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

	bool CFSecISOLangHBuff::operator !=( const CFSecISOLangPKey& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangHBuff::operator !=( const CFSecISOLangHPKey& rhs ) {
		if( getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() != rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() != rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( true );
			}
		}
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangHBuff::operator !=( const CFSecISOLangHBuff& rhs ) {
		if( getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() != rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() != rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( true );
			}
		}
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

	bool CFSecISOLangHBuff::operator !=( const CFSecISOLangBuff& rhs ) {
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

	bool CFSecISOLangHBuff::operator >=( const CFSecISOLangByCode3IdxKey& rhs ) {
		if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangHBuff::operator >=( const CFSecISOLangByCode2IdxKey& rhs ) {
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

	bool CFSecISOLangHBuff::operator >=( const CFSecISOLangPKey& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangHBuff::operator >=( const CFSecISOLangHPKey& rhs ) {
		if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangHBuff::operator >=( const CFSecISOLangHBuff& rhs ) {
		if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
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

	bool CFSecISOLangHBuff::operator >=( const CFSecISOLangBuff& rhs ) {
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

	bool CFSecISOLangHBuff::operator >( const CFSecISOLangByCode3IdxKey& rhs ) {
		if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangHBuff::operator >( const CFSecISOLangByCode2IdxKey& rhs ) {
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

	bool CFSecISOLangHBuff::operator >( const CFSecISOLangPKey& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangHBuff::operator >( const CFSecISOLangHPKey& rhs ) {
		if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangHBuff::operator >( const CFSecISOLangHBuff& rhs ) {
		if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
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

	bool CFSecISOLangHBuff::operator >( const CFSecISOLangBuff& rhs ) {
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

	std::string CFSecISOLangHBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOLangHBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_AuditClusterId( "AuditClusterId" );
		static const std::string S_AuditStamp( "AuditStamp" );
		static const std::string S_AuditActionId( "AuditActionId" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_AuditSessionId( "AuditSessionId" );
		static const std::string S_ISOLangId( "ISOLangId" );
		static const std::string S_ISO6392Code( "ISO6392Code" );
		static const std::string S_ISO6391Code( "ISO6391Code" );
		static const std::string S_EnglishName( "EnglishName" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_AuditClusterId, auditClusterId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_AuditClusterId, auditStamp ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_AuditActionId, auditActionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_AuditSessionId, auditSessionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOLangId, getRequiredISOLangId() ) );
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

	bool operator <(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs ) {
		if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs ) {
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
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangPKey& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs ) {
		if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
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

	bool operator <(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
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

	bool operator <=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs ) {
		if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs ) {
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

	bool operator <=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangPKey& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
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

	bool operator <=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
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

	bool operator ==(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs ) {
		if( lhs.getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs ) {
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

	bool operator ==(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangPKey& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
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

	bool operator ==(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
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

	bool operator !=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs ) {
		if( lhs.getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs ) {
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

	bool operator !=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangPKey& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( true );
			}
		}
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( true );
			}
		}
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

	bool operator !=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
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

	bool operator >=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs ) {
		if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs ) {
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

	bool operator >=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangPKey& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs ) {
		if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
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

	bool operator >=(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
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

	bool operator >(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs ) {
		if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs ) {
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

	bool operator >(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangPKey& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHPKey& rhs ) {
		if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
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

	bool operator >(const  cfsec::CFSecISOLangHBuff& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
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

