// Description: C++18 implementation for a SecSession buffer object.

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

#include <cfsec/CFSecSecSessionBySecUserIdxKey.hpp>
#include <cfsec/CFSecSecSessionBySecDevIdxKey.hpp>
#include <cfsec/CFSecSecSessionByStartIdxKey.hpp>
#include <cfsec/CFSecSecSessionByFinishIdxKey.hpp>
#include <cfsec/CFSecSecSessionBySecProxyIdxKey.hpp>
#include <cfsec/CFSecSchema.hpp>

namespace cfsec {

	const std::string CFSecSecSessionBuff::S_VALUE( "value" );
	const std::string CFSecSecSessionBuff::S_VALUE_LENGTH( "value.length()" );

	const std::string CFSecSecSessionBuff::GENDEFNAME( "SecSession" );
	const classcode_t CFSecSecSessionBuff::CLASS_CODE = 0xa010L;
	const std::string CFSecSecSessionBuff::CLASS_NAME( "CFSecSecSessionBuff" );
		const std::string CFSecSecSessionBuff::COLNAME_SECSESSIONID( "SecSessionId" );
		const std::string CFSecSecSessionBuff::COLNAME_SECUSERID( "SecUserId" );
		const std::string CFSecSecSessionBuff::COLNAME_SECDEVNAME( "SecDevName" );
		const std::string CFSecSecSessionBuff::COLNAME_START( "Start" );
		const std::string CFSecSecSessionBuff::COLNAME_FINISH( "Finish" );
		const std::string CFSecSecSessionBuff::COLNAME_SECPROXYID( "SecProxyId" );
	const std::string CFSecSecSessionBuff::SECDEVNAME_INIT_VALUE( "" );
	std::chrono::system_clock::time_point CFSecSecSessionBuff::START_INIT_VALUE = cflib::CFLib::getUTCGregorianCalendarInstance( 2020, 0, 1, 0, 0, 0 );
	const std::string::size_type CFSecSecSessionBuff::SECDEVNAME_MAX_LEN = 127;

	CFSecSecSessionBuff::CFSecSecSessionBuff()
	: cflib::ICFLibCloneableObj()
	{
		requiredRevision = 1;
		for( int i = 0; i < 16; i ++ ) {
			requiredSecSessionId[i] = 0;
		}
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
		optionalSecDevName = NULL;
		requiredStart = cflib::CFLib::getUTCGregorianCalendarInstance( 2020, 0, 1, 0, 0, 0 );
		optionalFinish = NULL;
		for( int i = 0; i < 16; i ++ ) {
			optionalSecProxyId[i] = 0;
		}
	}

	CFSecSecSessionBuff::CFSecSecSessionBuff( const CFSecSecSessionBuff& src )
	: cflib::ICFLibCloneableObj()
	{
		requiredRevision = 1;
		for( int i = 0; i < 16; i ++ ) {
			requiredSecSessionId[i] = 0;
		}
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
		optionalSecDevName = NULL;
		requiredStart = cflib::CFLib::getUTCGregorianCalendarInstance( 2020, 0, 1, 0, 0, 0 );
		optionalFinish = NULL;
		for( int i = 0; i < 16; i ++ ) {
			optionalSecProxyId[i] = 0;
		}
		setRequiredSecSessionId( src.getRequiredSecSessionId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredSecUserId( src.getRequiredSecUserId() );
		if( src.isOptionalSecDevNameNull() ) {
			setOptionalSecDevNameNull();
		}
		else {
			setOptionalSecDevNameValue( src.getOptionalSecDevNameValue() );
		}
		setRequiredStart( src.getRequiredStart() );
		if( src.isOptionalFinishNull() ) {
			setOptionalFinishNull();
		}
		else {
			setOptionalFinishValue( src.getOptionalFinishValue() );
		}
		if( src.isOptionalSecProxyIdNull() ) {
			setOptionalSecProxyIdNull();
		}
		else {
			setOptionalSecProxyIdValue( src.getOptionalSecProxyIdValue() );
		}
	}

	CFSecSecSessionBuff::~CFSecSecSessionBuff() {
		for( int i = 0; i < 16; i ++ ) {
			requiredSecSessionId[i] = 0;
		}
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
		if( optionalSecDevName != NULL ) {
			delete optionalSecDevName;
			optionalSecDevName = NULL;
		}
		if( optionalFinish != NULL ) {
			delete optionalFinish;
			optionalFinish = NULL;
		}
		for( int i = 0; i < 16; i ++ ) {
			optionalSecProxyId[i] = 0;
		}
	}

	cflib::ICFLibCloneableObj* CFSecSecSessionBuff::clone() {
		CFSecSecSessionBuff* copy = new CFSecSecSessionBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const std::string& CFSecSecSessionBuff::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecSecSessionBuff::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecSecSessionBuff::implementsClassCode( const classcode_t argClassCode ) {
		if( argClassCode == CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	const uuid_ptr_t CFSecSecSessionBuff::getRequiredSecSessionId() const {
		return( requiredSecSessionId );
	}

	const uuid_ptr_t CFSecSecSessionBuff::getRequiredSecSessionIdReference() const {
		return( requiredSecSessionId );
	}

	void CFSecSecSessionBuff::setRequiredSecSessionId( const uuid_ptr_t value ) {
		uuid_copy( requiredSecSessionId, value );
	}

	void CFSecSecSessionBuff::generateRequiredSecSessionId() {
		uuid_generate_random( requiredSecSessionId );
	}

	const uuid_ptr_t CFSecSecSessionBuff::getRequiredSecUserId() const {
		return( requiredSecUserId );
	}

	const uuid_ptr_t CFSecSecSessionBuff::getRequiredSecUserIdReference() const {
		return( requiredSecUserId );
	}

	void CFSecSecSessionBuff::setRequiredSecUserId( const uuid_ptr_t value ) {
		uuid_copy( requiredSecUserId, value );
	}

	void CFSecSecSessionBuff::generateRequiredSecUserId() {
		uuid_generate_random( requiredSecUserId );
	}

	const bool CFSecSecSessionBuff::isOptionalSecDevNameNull() const {
		return( optionalSecDevName == NULL );
	}

	const std::string& CFSecSecSessionBuff::getOptionalSecDevNameValue() const {
		static const std::string S_ProcName( "getOptionalSecDevNameValue" );
		if( optionalSecDevName == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( *optionalSecDevName );
	}

	const std::string* CFSecSecSessionBuff::getOptionalSecDevNameReference() const {
		return( optionalSecDevName );
	}

	void CFSecSecSessionBuff::setOptionalSecDevNameNull() {
		if( optionalSecDevName != NULL ) {
			delete optionalSecDevName;
			optionalSecDevName = NULL;
		}
	}

	void CFSecSecSessionBuff::setOptionalSecDevNameValue( const std::string& value ) {
		static const std::string S_ProcName( "setOptionalSecDevNameValue" );
		if( value.length() > CFSecSecSessionBuff::SECDEVNAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecSecSessionBuff::SECDEVNAME_MAX_LEN );
		}
		if( optionalSecDevName != NULL ) {
			delete optionalSecDevName;
			optionalSecDevName = NULL;
		}
		optionalSecDevName = new std::string( value );
	}

	const std::chrono::system_clock::time_point& CFSecSecSessionBuff::getRequiredStart() const {
		return( requiredStart );
	}

	const std::chrono::system_clock::time_point* CFSecSecSessionBuff::getRequiredStartReference() const {
		return( &requiredStart );
	}

	void CFSecSecSessionBuff::setRequiredStart( const std::chrono::system_clock::time_point& value ) {
		static const std::string S_ProcName( "setRequiredStart" );
		requiredStart = value;
	}

	const bool CFSecSecSessionBuff::isOptionalFinishNull() const {
		return( optionalFinish == NULL );
	}

	const std::chrono::system_clock::time_point& CFSecSecSessionBuff::getOptionalFinishValue() const {
		static const std::string S_ProcName( "getOptionalFinishValue" );
		if( optionalFinish == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( *optionalFinish );
	}

	const std::chrono::system_clock::time_point* CFSecSecSessionBuff::getOptionalFinishReference() const {
		return( optionalFinish );
	}

	void CFSecSecSessionBuff::setOptionalFinishNull() {
		if( optionalFinish != NULL ) {
			delete optionalFinish;
			optionalFinish = NULL;
		}
	}

	void CFSecSecSessionBuff::setOptionalFinishValue( const std::chrono::system_clock::time_point& value ) {
		static const std::string S_ProcName( "setOptionalFinishValue" );
		static const std::string S_ColumnName( ".Finish" );
		if( optionalFinish != NULL ) {
			delete optionalFinish;
			optionalFinish = NULL;
		}
		optionalFinish = new std::chrono::system_clock::time_point( value );
	}

	const bool CFSecSecSessionBuff::isOptionalSecProxyIdNull() const {
		for( int i = 0; i < 16; i ++ ) {
			if( optionalSecProxyId[ i ] != 0 ) {
				return( false );
			}
		}
		return( true );
	}

	const uuid_ptr_t CFSecSecSessionBuff::getOptionalSecProxyIdValue() const {
		static const std::string S_ProcName( "getOptionalSecProxyIdValue" );
		if( isOptionalSecProxyIdNull() ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( optionalSecProxyId );
	}

	const uuid_ptr_t CFSecSecSessionBuff::getOptionalSecProxyIdReference() const {
		if( isOptionalSecProxyIdNull() ) {
			return( NULL );
		}
		else {
			return( optionalSecProxyId );
		}
	}

	void CFSecSecSessionBuff::setOptionalSecProxyIdNull() {
		for( int i = 0; i < 16; i ++ ) {
			optionalSecProxyId[i] = 0;
		}
	}

	void CFSecSecSessionBuff::setOptionalSecProxyIdValue( const uuid_ptr_t value ) {
		uuid_copy( optionalSecProxyId, value );
	}

	void CFSecSecSessionBuff::generateOptionalSecProxyId() {
		uuid_generate_random( optionalSecProxyId );
	}

	int32_t CFSecSecSessionBuff::getRequiredRevision() const {
		return( requiredRevision );
	}

	void CFSecSecSessionBuff::setRequiredRevision( int32_t value ) {
		requiredRevision = value;
	}

	size_t CFSecSecSessionBuff::hashCode() const {
		size_t hashCode = 0L;
		hashCode = hashCode + cflib::CFLib::hash( getRequiredSecSessionId() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredSecUserId() );
		if( ! isOptionalSecDevNameNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalSecDevNameValue() );
		}
		hashCode = hashCode + cflib::CFLib::hash( getRequiredStart() );
		if( ! isOptionalFinishNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalFinishValue() );
		}
		if( ! isOptionalSecProxyIdNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalSecProxyIdValue() );
		}
		return( hashCode );
	}

	CFSecSecSessionBuff CFSecSecSessionBuff::operator =( cfsec::CFSecSecSessionBuff& src ) {
		setRequiredSecSessionId( src.getRequiredSecSessionId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredSecUserId( src.getRequiredSecUserId() );
		if( src.isOptionalSecDevNameNull() ) {
			setOptionalSecDevNameNull();
		}
		else {
			setOptionalSecDevNameValue( src.getOptionalSecDevNameValue() );
		}
		setRequiredStart( src.getRequiredStart() );
		if( src.isOptionalFinishNull() ) {
			setOptionalFinishNull();
		}
		else {
			setOptionalFinishValue( src.getOptionalFinishValue() );
		}
		if( src.isOptionalSecProxyIdNull() ) {
			setOptionalSecProxyIdNull();
		}
		else {
			setOptionalSecProxyIdValue( src.getOptionalSecProxyIdValue() );
		}
		return( *this );
	}

	CFSecSecSessionBuff CFSecSecSessionBuff::operator =( cfsec::CFSecSecSessionHBuff& src ) {
		setRequiredSecSessionId( src.getRequiredSecSessionId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredSecUserId( src.getRequiredSecUserId() );
		if( src.isOptionalSecDevNameNull() ) {
			setOptionalSecDevNameNull();
		}
		else {
			setOptionalSecDevNameValue( src.getOptionalSecDevNameValue() );
		}
		setRequiredStart( src.getRequiredStart() );
		if( src.isOptionalFinishNull() ) {
			setOptionalFinishNull();
		}
		else {
			setOptionalFinishValue( src.getOptionalFinishValue() );
		}
		if( src.isOptionalSecProxyIdNull() ) {
			setOptionalSecProxyIdNull();
		}
		else {
			setOptionalSecProxyIdValue( src.getOptionalSecProxyIdValue() );
		}
		return( *this );
	}

	bool CFSecSecSessionBuff::operator <( const CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator <( const CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator <( const CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator <( const CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator <( const CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator <( const CFSecSecSessionPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator <( const CFSecSecSessionHPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator <( const CFSecSecSessionHBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator <( const CFSecSecSessionBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator <=( const CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator <=( const CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator <=( const CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator <=( const CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator <=( const CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator <=( const CFSecSecSessionPKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator <=( const CFSecSecSessionHPKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator <=( const CFSecSecSessionHBuff& rhs ) {
		if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator <=( const CFSecSecSessionBuff& rhs ) {
		if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator ==( const CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator ==( const CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				if( getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator ==( const CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( getRequiredStart() != rhs.getRequiredStart() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator ==( const CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( ! isOptionalFinishNull() ) {
			if( ! rhs.isOptionalFinishNull() ) {
				if( getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator ==( const CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				if( 0 != uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator ==( const CFSecSecSessionPKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator ==( const CFSecSecSessionHPKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator ==( const CFSecSecSessionHBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				if( getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		if( getRequiredStart() != rhs.getRequiredStart() ) {
			return( false );
		}
		if( ! isOptionalFinishNull() ) {
			if( ! rhs.isOptionalFinishNull() ) {
				if( getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		if( ! isOptionalSecProxyIdNull() ) {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				if( 0 != uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator ==( const CFSecSecSessionBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				if( getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		if( getRequiredStart() != rhs.getRequiredStart() ) {
			return( false );
		}
		if( ! isOptionalFinishNull() ) {
			if( ! rhs.isOptionalFinishNull() ) {
				if( getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		if( ! isOptionalSecProxyIdNull() ) {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				if( 0 != uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator !=( const CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator !=( const CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator !=( const CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredStart() != rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator !=( const CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator !=( const CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator !=( const CFSecSecSessionPKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator !=( const CFSecSecSessionHPKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator !=( const CFSecSecSessionHBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		if( getRequiredStart() != rhs.getRequiredStart() ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator !=( const CFSecSecSessionBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		if( getRequiredStart() != rhs.getRequiredStart() ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator >=( const CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator >=( const CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator >=( const CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator >=( const CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator >=( const CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator >=( const CFSecSecSessionPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator >=( const CFSecSecSessionHPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator >=( const CFSecSecSessionHBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator >=( const CFSecSecSessionBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBuff::operator >( const CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator >( const CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator >( const CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator >( const CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator >( const CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator >( const CFSecSecSessionPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator >( const CFSecSecSessionHPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator >( const CFSecSecSessionHBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFSecSecSessionBuff::operator >( const CFSecSecSessionBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	std::string CFSecSecSessionBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecSessionBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_SecSessionId( "SecSessionId" );
		static const std::string S_SecUserId( "SecUserId" );
		static const std::string S_SecDevName( "SecDevName" );
		static const std::string S_Start( "Start" );
		static const std::string S_Finish( "Finish" );
		static const std::string S_SecProxyId( "SecProxyId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecSessionId, getRequiredSecSessionId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, getRequiredSecUserId() ) );
		if( ! isOptionalSecDevNameNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_SecDevName, getOptionalSecDevNameValue() ) );
		}
		ret.append( cflib::CFLibXmlUtil::formatRequiredTimestamp( &S_Space, S_Start, getRequiredStart() ) );
		if( ! isOptionalFinishNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredTimestamp( &S_Space, S_Finish, getOptionalFinishValue() ) );
		}
		if( ! isOptionalSecProxyIdNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecProxyId, getOptionalSecProxyIdValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				if( lhs.getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( lhs.getRequiredStart() != rhs.getRequiredStart() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( ! rhs.isOptionalFinishNull() ) {
				if( lhs.getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
					return( false );
				}
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				if( 0 != uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				if( lhs.getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredStart() != rhs.getRequiredStart() ) {
			return( false );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( ! rhs.isOptionalFinishNull() ) {
				if( lhs.getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
					return( false );
				}
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				if( 0 != uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				if( lhs.getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredStart() != rhs.getRequiredStart() ) {
			return( false );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( ! rhs.isOptionalFinishNull() ) {
				if( lhs.getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
					return( false );
				}
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				if( 0 != uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredStart() != rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( lhs.getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredStart() != rhs.getRequiredStart() ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( lhs.getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredStart() != rhs.getRequiredStart() ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( lhs.getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecSessionBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( false );
	}
}

