// Description: C++18 implementation of a ISOCcy history buffer object.

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
#include <cfsec/CFSecISOCcyPKey.hpp>
#include <cfsec/CFSecISOCcyBuff.hpp>
#include <cfsec/CFSecISOCcyHPKey.hpp>
#include <cfsec/CFSecISOCcyHBuff.hpp>
#include <cfsec/CFSecISOCcyByCcyCdIdxKey.hpp>
#include <cfsec/CFSecISOCcyByCcyNmIdxKey.hpp>

namespace cfsec {

	const std::string CFSecISOCcyHBuff::CLASS_NAME( "CFSecISOCcyHBuff" );
	CFSecISOCcyHBuff::CFSecISOCcyHBuff()
	: CFSecHPKey(), cflib::ICFLibCloneableObj() {
		requiredISOCcyId = cfsec::CFSecISOCcyBuff::ISOCCYID_INIT_VALUE;
		requiredISOCode = new std::string( cfsec::CFSecISOCcyBuff::ISOCODE_INIT_VALUE );
		requiredName = new std::string( cfsec::CFSecISOCcyBuff::NAME_INIT_VALUE );
		optionalUnitSymbol = NULL;
		requiredPrecis = cfsec::CFSecISOCcyBuff::PRECIS_INIT_VALUE;
	}

	CFSecISOCcyHBuff::CFSecISOCcyHBuff( const CFSecISOCcyHBuff& src )
	: CFSecHPKey(), cflib::ICFLibCloneableObj() {
		requiredISOCcyId = cfsec::CFSecISOCcyBuff::ISOCCYID_INIT_VALUE;
		requiredISOCode = new std::string( cfsec::CFSecISOCcyBuff::ISOCODE_INIT_VALUE );
		requiredName = new std::string( cfsec::CFSecISOCcyBuff::NAME_INIT_VALUE );
		optionalUnitSymbol = NULL;
		requiredPrecis = cfsec::CFSecISOCcyBuff::PRECIS_INIT_VALUE;
		setRequiredISOCcyId( src.getRequiredISOCcyId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredISOCode( src.getRequiredISOCode() );
		setRequiredName( src.getRequiredName() );
		if( src.isOptionalUnitSymbolNull() ) {
			setOptionalUnitSymbolNull();
		}
		else {
			setOptionalUnitSymbolValue( src.getOptionalUnitSymbolValue() );
		}
		setRequiredPrecis( src.getRequiredPrecis() );
	}

	CFSecISOCcyHBuff::~CFSecISOCcyHBuff() {
		if( requiredISOCode != NULL ) {
			delete requiredISOCode;
			requiredISOCode = NULL;
		}
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
		if( optionalUnitSymbol != NULL ) {
			delete optionalUnitSymbol;
			optionalUnitSymbol = NULL;
		}
	}

	cflib::ICFLibCloneableObj* CFSecISOCcyHBuff::clone() {
		CFSecISOCcyHBuff* copy = new CFSecISOCcyHBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const int16_t CFSecISOCcyHBuff::getRequiredISOCcyId() const {
		return( requiredISOCcyId );
	}

	const int16_t* CFSecISOCcyHBuff::getRequiredISOCcyIdReference() const {
		return( &requiredISOCcyId );
	}

	void CFSecISOCcyHBuff::setRequiredISOCcyId( const int16_t value ) {
		static const std::string S_ProcName( "setRequiredISOCcyId" );
		if( value < cfsec::CFSecISOCcyBuff::ISOCCYID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOCcyBuff::ISOCCYID_MIN_VALUE );
		}
		requiredISOCcyId = value;
	}

	const std::string& CFSecISOCcyHBuff::getRequiredISOCode() const {
		return( *requiredISOCode );
	}

	const std::string* CFSecISOCcyHBuff::getRequiredISOCodeReference() const {
		return( requiredISOCode );
	}

	void CFSecISOCcyHBuff::setRequiredISOCode( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredISOCode" );
		if( value.length() > CFSecISOCcyBuff::ISOCODE_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecISOCcyBuff::ISOCODE_MAX_LEN );
		}
		if( requiredISOCode != NULL ) {
			delete requiredISOCode;
			requiredISOCode = NULL;
		}
		requiredISOCode = new std::string( value );
	}

	const std::string& CFSecISOCcyHBuff::getRequiredName() const {
		return( *requiredName );
	}

	const std::string* CFSecISOCcyHBuff::getRequiredNameReference() const {
		return( requiredName );
	}

	void CFSecISOCcyHBuff::setRequiredName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredName" );
		if( value.length() > CFSecISOCcyBuff::NAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecISOCcyBuff::NAME_MAX_LEN );
		}
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
		requiredName = new std::string( value );
	}

	const std::string& CFSecISOCcyHBuff::getOptionalUnitSymbolValue() const {
		static const std::string S_ProcName( "getOptionalUnitSymbolValue" );
		if( optionalUnitSymbol == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( *optionalUnitSymbol );
	}

	const std::string* CFSecISOCcyHBuff::getOptionalUnitSymbolReference() const {
		return( optionalUnitSymbol );
	}

	const bool CFSecISOCcyHBuff::isOptionalUnitSymbolNull() const {
		return( optionalUnitSymbol == NULL );
	}

	void CFSecISOCcyHBuff::setOptionalUnitSymbolNull() {
		if( optionalUnitSymbol != NULL ) {
			delete optionalUnitSymbol;
			optionalUnitSymbol = NULL;
		}
	}

	void CFSecISOCcyHBuff::setOptionalUnitSymbolValue( const std::string& value ) {
		static const std::string S_ProcName( "setOptionalUnitSymbolValue" );
		if( value.length() > CFSecISOCcyBuff::UNITSYMBOL_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecISOCcyBuff::UNITSYMBOL_MAX_LEN );
		}
		if( optionalUnitSymbol != NULL ) {
			delete optionalUnitSymbol;
			optionalUnitSymbol = NULL;
		}
		optionalUnitSymbol = new std::string( value );
	}

	const int16_t CFSecISOCcyHBuff::getRequiredPrecis() const {
		return( requiredPrecis );
	}

	const int16_t* CFSecISOCcyHBuff::getRequiredPrecisReference() const {
		return( &requiredPrecis );
	}

	void CFSecISOCcyHBuff::setRequiredPrecis( const int16_t value ) {
		static const std::string S_ProcName( "setRequiredPrecis" );
		if( value < cfsec::CFSecISOCcyBuff::PRECIS_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOCcyBuff::PRECIS_MIN_VALUE );
		}
		if( value > cfsec::CFSecISOCcyBuff::PRECIS_MAX_VALUE ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOCcyBuff::PRECIS_MAX_VALUE );
		}
		requiredPrecis = value;
	}

	size_t CFSecISOCcyHBuff::hashCode() const {
		size_t hashCode = CFSecHPKey::hashCode();
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOCcyId();
		hashCode = hashCode + cflib::CFLib::hash( getRequiredISOCode() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredName() );
		if( ! isOptionalUnitSymbolNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalUnitSymbolValue() );
		}
		hashCode = ( hashCode * 0x10000 ) + getRequiredPrecis();
		return( hashCode );
	}

	CFSecISOCcyHBuff CFSecISOCcyHBuff::operator =( cfsec::CFSecISOCcyBuff& src ) {
		setRequiredISOCcyId( src.getRequiredISOCcyId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredISOCode( src.getRequiredISOCode() );
		setRequiredName( src.getRequiredName() );
		if( src.isOptionalUnitSymbolNull() ) {
			setOptionalUnitSymbolNull();
		}
		else {
			setOptionalUnitSymbolValue( src.getOptionalUnitSymbolValue() );
		}
		setRequiredPrecis( src.getRequiredPrecis() );
		return( *this );
	}

	CFSecISOCcyHBuff CFSecISOCcyHBuff::operator =( cfsec::CFSecISOCcyHBuff& src ) {
		setRequiredISOCcyId( src.getRequiredISOCcyId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredISOCode( src.getRequiredISOCode() );
		setRequiredName( src.getRequiredName() );
		if( src.isOptionalUnitSymbolNull() ) {
			setOptionalUnitSymbolNull();
		}
		else {
			setOptionalUnitSymbolValue( src.getOptionalUnitSymbolValue() );
		}
		setRequiredPrecis( src.getRequiredPrecis() );
		return( *this );
	}

	bool CFSecISOCcyHBuff::operator <( const CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyHBuff::operator <( const CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyHBuff::operator <( const CFSecISOCcyPKey& rhs ) {
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyHBuff::operator <( const CFSecISOCcyHPKey& rhs ) {
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
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyHBuff::operator <( const CFSecISOCcyHBuff& rhs ) {
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
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
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
		if( ! isOptionalUnitSymbolNull() ) {
			if( rhs.isOptionalUnitSymbolNull() ) {
				return( false );
			}
			if( getOptionalUnitSymbolValue() > rhs.getOptionalUnitSymbolValue() ) {
				return( false );
			}
			else if( getOptionalUnitSymbolValue() < rhs.getOptionalUnitSymbolValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
		}
		if( getRequiredPrecis() > rhs.getRequiredPrecis() ) {
			return( false );
		}
		else if( getRequiredPrecis() < rhs.getRequiredPrecis() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyHBuff::operator <( const CFSecISOCcyBuff& rhs ) {
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
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
		if( ! isOptionalUnitSymbolNull() ) {
			if( rhs.isOptionalUnitSymbolNull() ) {
				return( false );
			}
			if( getOptionalUnitSymbolValue() > rhs.getOptionalUnitSymbolValue() ) {
				return( false );
			}
			else if( getOptionalUnitSymbolValue() < rhs.getOptionalUnitSymbolValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
		}
		if( getRequiredPrecis() > rhs.getRequiredPrecis() ) {
			return( false );
		}
		else if( getRequiredPrecis() < rhs.getRequiredPrecis() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyHBuff::operator <=( const CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyHBuff::operator <=( const CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyHBuff::operator <=( const CFSecISOCcyPKey& rhs ) {
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyHBuff::operator <=( const CFSecISOCcyHPKey& rhs ) {
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
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyHBuff::operator <=( const CFSecISOCcyHBuff& rhs ) {
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
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
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
		if( ! isOptionalUnitSymbolNull() ) {
			if( rhs.isOptionalUnitSymbolNull() ) {
				return( false );
			}
			if( getOptionalUnitSymbolValue() > rhs.getOptionalUnitSymbolValue() ) {
				return( false );
			}
			else if( getOptionalUnitSymbolValue() < rhs.getOptionalUnitSymbolValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
		}
		if( getRequiredPrecis() > rhs.getRequiredPrecis() ) {
			return( false );
		}
		else if( getRequiredPrecis() < rhs.getRequiredPrecis() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyHBuff::operator <=( const CFSecISOCcyBuff& rhs ) {
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
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
		if( ! isOptionalUnitSymbolNull() ) {
			if( rhs.isOptionalUnitSymbolNull() ) {
				return( false );
			}
			if( getOptionalUnitSymbolValue() > rhs.getOptionalUnitSymbolValue() ) {
				return( false );
			}
			else if( getOptionalUnitSymbolValue() < rhs.getOptionalUnitSymbolValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
		}
		if( getRequiredPrecis() > rhs.getRequiredPrecis() ) {
			return( false );
		}
		else if( getRequiredPrecis() < rhs.getRequiredPrecis() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyHBuff::operator ==( const CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCcyHBuff::operator ==( const CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCcyHBuff::operator ==( const CFSecISOCcyPKey& rhs ) {
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCcyHBuff::operator ==( const CFSecISOCcyHPKey& rhs ) {
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
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCcyHBuff::operator ==( const CFSecISOCcyHBuff& rhs ) {
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
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		if( ! isOptionalUnitSymbolNull() ) {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				if( getOptionalUnitSymbolValue() != rhs.getOptionalUnitSymbolValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalUnitSymbolNull() ) {
				return( false );
			}
		}
		if( getRequiredPrecis() != rhs.getRequiredPrecis() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCcyHBuff::operator ==( const CFSecISOCcyBuff& rhs ) {
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		if( ! isOptionalUnitSymbolNull() ) {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				if( getOptionalUnitSymbolValue() != rhs.getOptionalUnitSymbolValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalUnitSymbolNull() ) {
				return( false );
			}
		}
		if( getRequiredPrecis() != rhs.getRequiredPrecis() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCcyHBuff::operator !=( const CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyHBuff::operator !=( const CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyHBuff::operator !=( const CFSecISOCcyPKey& rhs ) {
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyHBuff::operator !=( const CFSecISOCcyHPKey& rhs ) {
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
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyHBuff::operator !=( const CFSecISOCcyHBuff& rhs ) {
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
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		if( ! isOptionalUnitSymbolNull() ) {
			if( rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
			if( getOptionalUnitSymbolValue() != rhs.getOptionalUnitSymbolValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
		}
		if( getRequiredPrecis() != rhs.getRequiredPrecis() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyHBuff::operator !=( const CFSecISOCcyBuff& rhs ) {
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		if( ! isOptionalUnitSymbolNull() ) {
			if( rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
			if( getOptionalUnitSymbolValue() != rhs.getOptionalUnitSymbolValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
		}
		if( getRequiredPrecis() != rhs.getRequiredPrecis() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyHBuff::operator >=( const CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyHBuff::operator >=( const CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyHBuff::operator >=( const CFSecISOCcyPKey& rhs ) {
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyHBuff::operator >=( const CFSecISOCcyHPKey& rhs ) {
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
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyHBuff::operator >=( const CFSecISOCcyHBuff& rhs ) {
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
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
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
		if( ! isOptionalUnitSymbolNull() ) {
			if( rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
			if( getOptionalUnitSymbolValue() < rhs.getOptionalUnitSymbolValue() ) {
				return( false );
			}
			else if( getOptionalUnitSymbolValue() > rhs.getOptionalUnitSymbolValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				return( false );
			}
		}
		if( getRequiredPrecis() < rhs.getRequiredPrecis() ) {
			return( false );
		}
		else if( getRequiredPrecis() > rhs.getRequiredPrecis() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyHBuff::operator >=( const CFSecISOCcyBuff& rhs ) {
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
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
		if( ! isOptionalUnitSymbolNull() ) {
			if( rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
			if( getOptionalUnitSymbolValue() < rhs.getOptionalUnitSymbolValue() ) {
				return( false );
			}
			else if( getOptionalUnitSymbolValue() > rhs.getOptionalUnitSymbolValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				return( false );
			}
		}
		if( getRequiredPrecis() < rhs.getRequiredPrecis() ) {
			return( false );
		}
		else if( getRequiredPrecis() > rhs.getRequiredPrecis() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyHBuff::operator >( const CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyHBuff::operator >( const CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyHBuff::operator >( const CFSecISOCcyPKey& rhs ) {
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyHBuff::operator >( const CFSecISOCcyHPKey& rhs ) {
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
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyHBuff::operator >( const CFSecISOCcyHBuff& rhs ) {
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
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
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
		if( ! isOptionalUnitSymbolNull() ) {
			if( rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
			if( getOptionalUnitSymbolValue() < rhs.getOptionalUnitSymbolValue() ) {
				return( false );
			}
			else if( getOptionalUnitSymbolValue() > rhs.getOptionalUnitSymbolValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		if( getRequiredPrecis() < rhs.getRequiredPrecis() ) {
			return( false );
		}
		else if( getRequiredPrecis() > rhs.getRequiredPrecis() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyHBuff::operator >( const CFSecISOCcyBuff& rhs ) {
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
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
		if( ! isOptionalUnitSymbolNull() ) {
			if( rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
			if( getOptionalUnitSymbolValue() < rhs.getOptionalUnitSymbolValue() ) {
				return( false );
			}
			else if( getOptionalUnitSymbolValue() > rhs.getOptionalUnitSymbolValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		if( getRequiredPrecis() < rhs.getRequiredPrecis() ) {
			return( false );
		}
		else if( getRequiredPrecis() > rhs.getRequiredPrecis() ) {
			return( true );
		}
		return( false );
	}

	std::string CFSecISOCcyHBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOCcyHBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_AuditClusterId( "AuditClusterId" );
		static const std::string S_AuditStamp( "AuditStamp" );
		static const std::string S_AuditActionId( "AuditActionId" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_AuditSessionId( "AuditSessionId" );
		static const std::string S_ISOCcyId( "ISOCcyId" );
		static const std::string S_ISOCode( "ISOCode" );
		static const std::string S_Name( "Name" );
		static const std::string S_UnitSymbol( "UnitSymbol" );
		static const std::string S_Precis( "Precis" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_AuditClusterId, auditClusterId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_AuditClusterId, auditStamp ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_AuditActionId, auditActionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_AuditSessionId, auditSessionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCcyId, getRequiredISOCcyId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_ISOCode, getRequiredISOCode() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, getRequiredName() ) );
		if( ! isOptionalUnitSymbolNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UnitSymbol, getOptionalUnitSymbolValue() ) );
		}
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_Precis, getRequiredPrecis() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs ) {
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs ) {
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
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
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
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
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
		if( ! lhs.isOptionalUnitSymbolNull() ) {
			if( rhs.isOptionalUnitSymbolNull() ) {
				return( false );
			}
			if( lhs.getOptionalUnitSymbolValue() > rhs.getOptionalUnitSymbolValue() ) {
				return( false );
			}
			else if( lhs.getOptionalUnitSymbolValue() < rhs.getOptionalUnitSymbolValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredPrecis() > rhs.getRequiredPrecis() ) {
			return( false );
		}
		else if( lhs.getRequiredPrecis() < rhs.getRequiredPrecis() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
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
		if( ! lhs.isOptionalUnitSymbolNull() ) {
			if( rhs.isOptionalUnitSymbolNull() ) {
				return( false );
			}
			if( lhs.getOptionalUnitSymbolValue() > rhs.getOptionalUnitSymbolValue() ) {
				return( false );
			}
			else if( lhs.getOptionalUnitSymbolValue() < rhs.getOptionalUnitSymbolValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredPrecis() > rhs.getRequiredPrecis() ) {
			return( false );
		}
		else if( lhs.getRequiredPrecis() < rhs.getRequiredPrecis() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs ) {
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs ) {
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
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
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
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
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
		if( ! lhs.isOptionalUnitSymbolNull() ) {
			if( rhs.isOptionalUnitSymbolNull() ) {
				return( false );
			}
			if( lhs.getOptionalUnitSymbolValue() > rhs.getOptionalUnitSymbolValue() ) {
				return( false );
			}
			else if( lhs.getOptionalUnitSymbolValue() < rhs.getOptionalUnitSymbolValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredPrecis() > rhs.getRequiredPrecis() ) {
			return( false );
		}
		else if( lhs.getRequiredPrecis() < rhs.getRequiredPrecis() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
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
		if( ! lhs.isOptionalUnitSymbolNull() ) {
			if( rhs.isOptionalUnitSymbolNull() ) {
				return( false );
			}
			if( lhs.getOptionalUnitSymbolValue() > rhs.getOptionalUnitSymbolValue() ) {
				return( false );
			}
			else if( lhs.getOptionalUnitSymbolValue() < rhs.getOptionalUnitSymbolValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredPrecis() > rhs.getRequiredPrecis() ) {
			return( false );
		}
		else if( lhs.getRequiredPrecis() < rhs.getRequiredPrecis() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs ) {
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs ) {
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
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
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
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		if( ! lhs.isOptionalUnitSymbolNull() ) {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				if( lhs.getOptionalUnitSymbolValue() != rhs.getOptionalUnitSymbolValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredPrecis() != rhs.getRequiredPrecis() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		if( ! lhs.isOptionalUnitSymbolNull() ) {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				if( lhs.getOptionalUnitSymbolValue() != rhs.getOptionalUnitSymbolValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredPrecis() != rhs.getRequiredPrecis() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs ) {
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs ) {
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
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
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
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		if( ! lhs.isOptionalUnitSymbolNull() ) {
			if( rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
			if( lhs.getOptionalUnitSymbolValue() != rhs.getOptionalUnitSymbolValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredPrecis() != rhs.getRequiredPrecis() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		if( ! lhs.isOptionalUnitSymbolNull() ) {
			if( rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
			if( lhs.getOptionalUnitSymbolValue() != rhs.getOptionalUnitSymbolValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredPrecis() != rhs.getRequiredPrecis() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs ) {
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs ) {
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
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
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
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
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
		if( ! lhs.isOptionalUnitSymbolNull() ) {
			if( rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
			if( lhs.getOptionalUnitSymbolValue() < rhs.getOptionalUnitSymbolValue() ) {
				return( false );
			}
			else if( lhs.getOptionalUnitSymbolValue() > rhs.getOptionalUnitSymbolValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredPrecis() < rhs.getRequiredPrecis() ) {
			return( false );
		}
		else if( lhs.getRequiredPrecis() > rhs.getRequiredPrecis() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
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
		if( ! lhs.isOptionalUnitSymbolNull() ) {
			if( rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
			if( lhs.getOptionalUnitSymbolValue() < rhs.getOptionalUnitSymbolValue() ) {
				return( false );
			}
			else if( lhs.getOptionalUnitSymbolValue() > rhs.getOptionalUnitSymbolValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredPrecis() < rhs.getRequiredPrecis() ) {
			return( false );
		}
		else if( lhs.getRequiredPrecis() > rhs.getRequiredPrecis() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs ) {
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs ) {
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
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
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
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
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
		if( ! lhs.isOptionalUnitSymbolNull() ) {
			if( rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
			if( lhs.getOptionalUnitSymbolValue() < rhs.getOptionalUnitSymbolValue() ) {
				return( false );
			}
			else if( lhs.getOptionalUnitSymbolValue() > rhs.getOptionalUnitSymbolValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredPrecis() < rhs.getRequiredPrecis() ) {
			return( false );
		}
		else if( lhs.getRequiredPrecis() > rhs.getRequiredPrecis() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCcyHBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
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
		if( ! lhs.isOptionalUnitSymbolNull() ) {
			if( rhs.isOptionalUnitSymbolNull() ) {
				return( true );
			}
			if( lhs.getOptionalUnitSymbolValue() < rhs.getOptionalUnitSymbolValue() ) {
				return( false );
			}
			else if( lhs.getOptionalUnitSymbolValue() > rhs.getOptionalUnitSymbolValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalUnitSymbolNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredPrecis() < rhs.getRequiredPrecis() ) {
			return( false );
		}
		else if( lhs.getRequiredPrecis() > rhs.getRequiredPrecis() ) {
			return( true );
		}
		return( false );
	}
}

