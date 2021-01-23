// Description: C++18 implementation for a ISOCcy buffer object.

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

using namespace std;

#include <cfsec/ICFSecPublic.hpp>

#include <cfsec/CFSecISOCcyByCcyCdIdxKey.hpp>
#include <cfsec/CFSecISOCcyByCcyNmIdxKey.hpp>
#include <cfsec/CFSecSchema.hpp>

namespace cfsec {

	const std::string CFSecISOCcyBuff::S_VALUE( "value" );
	const std::string CFSecISOCcyBuff::S_VALUE_LENGTH( "value.length()" );

	const std::string CFSecISOCcyBuff::GENDEFNAME( "ISOCcy" );
	const classcode_t CFSecISOCcyBuff::CLASS_CODE = 0xa003L;
	const std::string CFSecISOCcyBuff::CLASS_NAME( "CFSecISOCcyBuff" );
		const std::string CFSecISOCcyBuff::COLNAME_ISOCCYID( "ISOCcyId" );
		const std::string CFSecISOCcyBuff::COLNAME_ISOCODE( "ISOCode" );
		const std::string CFSecISOCcyBuff::COLNAME_NAME( "Name" );
		const std::string CFSecISOCcyBuff::COLNAME_UNITSYMBOL( "UnitSymbol" );
		const std::string CFSecISOCcyBuff::COLNAME_PRECIS( "Precis" );
	const char* CFSecISOCcyBuff::S_INIT_CREATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const char* CFSecISOCcyBuff::S_INIT_UPDATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const int16_t CFSecISOCcyBuff::ISOCCYID_INIT_VALUE = (int16_t)0;
	const std::string CFSecISOCcyBuff::ISOCODE_INIT_VALUE( "" );
	const std::string CFSecISOCcyBuff::NAME_INIT_VALUE( "" );
	const int16_t CFSecISOCcyBuff::PRECIS_INIT_VALUE = (int16_t)0;
	const int16_t CFSecISOCcyBuff::ISOCCYID_MIN_VALUE = (int16_t)0;
	const int16_t CFSecISOCcyBuff::PRECIS_MIN_VALUE = (int16_t)0;
	const int16_t CFSecISOCcyBuff::PRECIS_MAX_VALUE = (int16_t)5;
	const std::string::size_type CFSecISOCcyBuff::ISOCODE_MAX_LEN = 3;
	const std::string::size_type CFSecISOCcyBuff::NAME_MAX_LEN = 64;
	const std::string::size_type CFSecISOCcyBuff::UNITSYMBOL_MAX_LEN = 4;

	CFSecISOCcyBuff::CFSecISOCcyBuff()
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
		requiredISOCcyId = cfsec::CFSecISOCcyBuff::ISOCCYID_INIT_VALUE;
		requiredISOCode = new std::string( cfsec::CFSecISOCcyBuff::ISOCODE_INIT_VALUE );
		requiredName = new std::string( cfsec::CFSecISOCcyBuff::NAME_INIT_VALUE );
		optionalUnitSymbol = NULL;
		requiredPrecis = cfsec::CFSecISOCcyBuff::PRECIS_INIT_VALUE;
	}

	CFSecISOCcyBuff::CFSecISOCcyBuff( const CFSecISOCcyBuff& src )
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
		requiredISOCcyId = cfsec::CFSecISOCcyBuff::ISOCCYID_INIT_VALUE;
		requiredISOCode = new std::string( cfsec::CFSecISOCcyBuff::ISOCODE_INIT_VALUE );
		requiredName = new std::string( cfsec::CFSecISOCcyBuff::NAME_INIT_VALUE );
		optionalUnitSymbol = NULL;
		requiredPrecis = cfsec::CFSecISOCcyBuff::PRECIS_INIT_VALUE;
		setRequiredISOCcyId( src.getRequiredISOCcyId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
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

	CFSecISOCcyBuff::~CFSecISOCcyBuff() {
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
		for( int i = 0; i < 16; i++ ) {
			createdByUserId[i] = 0;
		}
		for( int i = 0; i < 16; i++ ) {
			updatedByUserId[i] = 0;
		}
	}

	cflib::ICFLibCloneableObj* CFSecISOCcyBuff::clone() {
		CFSecISOCcyBuff* copy = new CFSecISOCcyBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const std::string& CFSecISOCcyBuff::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecISOCcyBuff::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecISOCcyBuff::implementsClassCode( const classcode_t argClassCode ) {
		if( argClassCode == CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	const uuid_ptr_t CFSecISOCcyBuff::getCreatedByUserId() const {
		return( createdByUserId );
	}

	void CFSecISOCcyBuff::setCreatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( createdByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecISOCcyBuff::getCreatedAt() const {
		return( createdAt );
	}

	void CFSecISOCcyBuff::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		createdAt = value;
	}

	const uuid_ptr_t CFSecISOCcyBuff::getUpdatedByUserId() const {
		return( updatedByUserId );
	}

	void CFSecISOCcyBuff::setUpdatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( updatedByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecISOCcyBuff::getUpdatedAt() const {
		return( updatedAt );
	}

	void CFSecISOCcyBuff::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		updatedAt = value;
	}
	const int16_t CFSecISOCcyBuff::getRequiredISOCcyId() const {
		return( requiredISOCcyId );
	}

	const int16_t* CFSecISOCcyBuff::getRequiredISOCcyIdReference() const {
		return( &requiredISOCcyId );
	}

	void CFSecISOCcyBuff::setRequiredISOCcyId( const int16_t value ) {
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

	const std::string& CFSecISOCcyBuff::getRequiredISOCode() const {
		return( *requiredISOCode );
	}

	const std::string* CFSecISOCcyBuff::getRequiredISOCodeReference() const {
		return( requiredISOCode );
	}

	void CFSecISOCcyBuff::setRequiredISOCode( const std::string& value ) {
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

	const std::string& CFSecISOCcyBuff::getRequiredName() const {
		return( *requiredName );
	}

	const std::string* CFSecISOCcyBuff::getRequiredNameReference() const {
		return( requiredName );
	}

	void CFSecISOCcyBuff::setRequiredName( const std::string& value ) {
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

	const bool CFSecISOCcyBuff::isOptionalUnitSymbolNull() const {
		return( optionalUnitSymbol == NULL );
	}

	const std::string& CFSecISOCcyBuff::getOptionalUnitSymbolValue() const {
		static const std::string S_ProcName( "getOptionalUnitSymbolValue" );
		if( optionalUnitSymbol == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( *optionalUnitSymbol );
	}

	const std::string* CFSecISOCcyBuff::getOptionalUnitSymbolReference() const {
		return( optionalUnitSymbol );
	}

	void CFSecISOCcyBuff::setOptionalUnitSymbolNull() {
		if( optionalUnitSymbol != NULL ) {
			delete optionalUnitSymbol;
			optionalUnitSymbol = NULL;
		}
	}

	void CFSecISOCcyBuff::setOptionalUnitSymbolValue( const std::string& value ) {
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

	const int16_t CFSecISOCcyBuff::getRequiredPrecis() const {
		return( requiredPrecis );
	}

	const int16_t* CFSecISOCcyBuff::getRequiredPrecisReference() const {
		return( &requiredPrecis );
	}

	void CFSecISOCcyBuff::setRequiredPrecis( const int16_t value ) {
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

	int32_t CFSecISOCcyBuff::getRequiredRevision() const {
		return( requiredRevision );
	}

	void CFSecISOCcyBuff::setRequiredRevision( int32_t value ) {
		requiredRevision = value;
	}

	size_t CFSecISOCcyBuff::hashCode() const {
		size_t hashCode = 0L;
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOCcyId();
		hashCode = hashCode + cflib::CFLib::hash( getRequiredISOCode() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredName() );
		if( ! isOptionalUnitSymbolNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalUnitSymbolValue() );
		}
		hashCode = ( hashCode * 0x10000 ) + getRequiredPrecis();
		return( hashCode );
	}

	CFSecISOCcyBuff CFSecISOCcyBuff::operator =( cfsec::CFSecISOCcyBuff& src ) {
		setRequiredISOCcyId( src.getRequiredISOCcyId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
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

	CFSecISOCcyBuff CFSecISOCcyBuff::operator =( cfsec::CFSecISOCcyHBuff& src ) {
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

	bool CFSecISOCcyBuff::operator <( const CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyBuff::operator <( const CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyBuff::operator <( const CFSecISOCcyPKey& rhs ) {
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyBuff::operator <( const CFSecISOCcyHPKey& rhs ) {
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyBuff::operator <( const CFSecISOCcyHBuff& rhs ) {
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

	bool CFSecISOCcyBuff::operator <( const CFSecISOCcyBuff& rhs ) {
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

	bool CFSecISOCcyBuff::operator <=( const CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyBuff::operator <=( const CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyBuff::operator <=( const CFSecISOCcyPKey& rhs ) {
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyBuff::operator <=( const CFSecISOCcyHPKey& rhs ) {
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyBuff::operator <=( const CFSecISOCcyHBuff& rhs ) {
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

	bool CFSecISOCcyBuff::operator <=( const CFSecISOCcyBuff& rhs ) {
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

	bool CFSecISOCcyBuff::operator ==( const CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCcyBuff::operator ==( const CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCcyBuff::operator ==( const CFSecISOCcyPKey& rhs ) {
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCcyBuff::operator ==( const CFSecISOCcyHPKey& rhs ) {
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCcyBuff::operator ==( const CFSecISOCcyHBuff& rhs ) {
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

	bool CFSecISOCcyBuff::operator ==( const CFSecISOCcyBuff& rhs ) {
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

	bool CFSecISOCcyBuff::operator !=( const CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyBuff::operator !=( const CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyBuff::operator !=( const CFSecISOCcyPKey& rhs ) {
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyBuff::operator !=( const CFSecISOCcyHPKey& rhs ) {
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyBuff::operator !=( const CFSecISOCcyHBuff& rhs ) {
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

	bool CFSecISOCcyBuff::operator !=( const CFSecISOCcyBuff& rhs ) {
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

	bool CFSecISOCcyBuff::operator >=( const CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyBuff::operator >=( const CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyBuff::operator >=( const CFSecISOCcyPKey& rhs ) {
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyBuff::operator >=( const CFSecISOCcyHPKey& rhs ) {
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyBuff::operator >=( const CFSecISOCcyHBuff& rhs ) {
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

	bool CFSecISOCcyBuff::operator >=( const CFSecISOCcyBuff& rhs ) {
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

	bool CFSecISOCcyBuff::operator >( const CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyBuff::operator >( const CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyBuff::operator >( const CFSecISOCcyPKey& rhs ) {
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyBuff::operator >( const CFSecISOCcyHPKey& rhs ) {
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyBuff::operator >( const CFSecISOCcyHBuff& rhs ) {
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

	bool CFSecISOCcyBuff::operator >( const CFSecISOCcyBuff& rhs ) {
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

	std::string CFSecISOCcyBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOCcyBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ISOCcyId( "ISOCcyId" );
		static const std::string S_ISOCode( "ISOCode" );
		static const std::string S_Name( "Name" );
		static const std::string S_UnitSymbol( "UnitSymbol" );
		static const std::string S_Precis( "Precis" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCcyId, getRequiredISOCcyId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_CreatedBy, getCreatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_UpdatedBy, getUpdatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, getUpdatedAt() ) );
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

	bool operator <(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs ) {
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs ) {
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
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

	bool operator <(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
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

	bool operator <=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs ) {
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs ) {
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
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

	bool operator <=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
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

	bool operator ==(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs ) {
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs ) {
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
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

	bool operator ==(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
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

	bool operator !=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs ) {
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs ) {
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
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

	bool operator !=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
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

	bool operator >=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs ) {
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs ) {
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
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

	bool operator >=(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
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

	bool operator >(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyPKey& rhs ) {
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHPKey& rhs ) {
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
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

	bool operator >(const  cfsec::CFSecISOCcyBuff& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
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

