// Description: C++18 implementation of a SecSession history buffer object.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <cflib/ICFLibPublic.hpp>

using namespace std;

#include <cfsec/CFSecHPKey.hpp>
#include <cfsec/CFSecSecSessionPKey.hpp>
#include <cfsec/CFSecSecSessionBuff.hpp>
#include <cfsec/CFSecSecSessionHPKey.hpp>
#include <cfsec/CFSecSecSessionHBuff.hpp>
#include <cfsec/CFSecSecSessionBySecUserIdxKey.hpp>
#include <cfsec/CFSecSecSessionBySecDevIdxKey.hpp>
#include <cfsec/CFSecSecSessionByStartIdxKey.hpp>
#include <cfsec/CFSecSecSessionByFinishIdxKey.hpp>
#include <cfsec/CFSecSecSessionBySecProxyIdxKey.hpp>

namespace cfsec {

	const std::string CFSecSecSessionHBuff::CLASS_NAME( "CFSecSecSessionHBuff" );
	CFSecSecSessionHBuff::CFSecSecSessionHBuff()
	: CFSecHPKey(), cflib::ICFLibCloneableObj() {
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

	CFSecSecSessionHBuff::CFSecSecSessionHBuff( const CFSecSecSessionHBuff& src )
	: CFSecHPKey(), cflib::ICFLibCloneableObj() {
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

	CFSecSecSessionHBuff::~CFSecSecSessionHBuff() {
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

	cflib::ICFLibCloneableObj* CFSecSecSessionHBuff::clone() {
		CFSecSecSessionHBuff* copy = new CFSecSecSessionHBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const uuid_ptr_t CFSecSecSessionHBuff::getRequiredSecSessionId() const {
		return( requiredSecSessionId );
	}

	const uuid_ptr_t CFSecSecSessionHBuff::getRequiredSecSessionIdReference() const {
		return( requiredSecSessionId );
	}

	void CFSecSecSessionHBuff::setRequiredSecSessionId( const uuid_ptr_t value ) {
		uuid_copy( requiredSecSessionId, value );
	}

	void CFSecSecSessionHBuff::generateRequiredSecSessionId() {
		uuid_generate_random( requiredSecSessionId );
	}

	const uuid_ptr_t CFSecSecSessionHBuff::getRequiredSecUserId() const {
		return( requiredSecUserId );
	}

	const uuid_ptr_t CFSecSecSessionHBuff::getRequiredSecUserIdReference() const {
		return( requiredSecUserId );
	}

	void CFSecSecSessionHBuff::setRequiredSecUserId( const uuid_ptr_t value ) {
		uuid_copy( requiredSecUserId, value );
	}

	void CFSecSecSessionHBuff::generateRequiredSecUserId() {
		uuid_generate_random( requiredSecUserId );
	}

	const std::string& CFSecSecSessionHBuff::getOptionalSecDevNameValue() const {
		static const std::string S_ProcName( "getOptionalSecDevNameValue" );
		if( optionalSecDevName == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( *optionalSecDevName );
	}

	const std::string* CFSecSecSessionHBuff::getOptionalSecDevNameReference() const {
		return( optionalSecDevName );
	}

	const bool CFSecSecSessionHBuff::isOptionalSecDevNameNull() const {
		return( optionalSecDevName == NULL );
	}

	void CFSecSecSessionHBuff::setOptionalSecDevNameNull() {
		if( optionalSecDevName != NULL ) {
			delete optionalSecDevName;
			optionalSecDevName = NULL;
		}
	}

	void CFSecSecSessionHBuff::setOptionalSecDevNameValue( const std::string& value ) {
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

	const std::chrono::system_clock::time_point& CFSecSecSessionHBuff::getRequiredStart() const {
		return( requiredStart );
	}

	const std::chrono::system_clock::time_point* CFSecSecSessionHBuff::getRequiredStartReference() const {
		return( &requiredStart );
	}

	void CFSecSecSessionHBuff::setRequiredStart( const std::chrono::system_clock::time_point& value ) {
		static const std::string S_ProcName( "setRequiredStart" );
		requiredStart = value;
	}

	const std::chrono::system_clock::time_point& CFSecSecSessionHBuff::getOptionalFinishValue() const {
		static const std::string S_ProcName( "getOptionalFinishValue" );
		if( optionalFinish == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( *optionalFinish );
	}

	const std::chrono::system_clock::time_point* CFSecSecSessionHBuff::getOptionalFinishReference() const {
		return( optionalFinish );
	}

	const bool CFSecSecSessionHBuff::isOptionalFinishNull() const {
		return( optionalFinish == NULL );
	}

	void CFSecSecSessionHBuff::setOptionalFinishNull() {
		if( optionalFinish != NULL ) {
			delete optionalFinish;
			optionalFinish = NULL;
		}
	}

	void CFSecSecSessionHBuff::setOptionalFinishValue( const std::chrono::system_clock::time_point& value ) {
		static const std::string S_ProcName( "setOptionalFinishValue" );
		static const std::string S_ColumnName( ".Finish" );
		if( optionalFinish != NULL ) {
			delete optionalFinish;
			optionalFinish = NULL;
		}
		optionalFinish = new std::chrono::system_clock::time_point( value );
	}

	const uuid_ptr_t CFSecSecSessionHBuff::getOptionalSecProxyIdValue() const {
		static const std::string S_ProcName( "getOptionalSecProxyIdValue" );
		if( isOptionalSecProxyIdNull() ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( optionalSecProxyId );
	}

	const uuid_ptr_t CFSecSecSessionHBuff::getOptionalSecProxyIdReference() const {
		if( isOptionalSecProxyIdNull() ) {
			return( NULL );
		}
		else {
			return( optionalSecProxyId );
		}
	}

	const bool CFSecSecSessionHBuff::isOptionalSecProxyIdNull() const {
		for( int i = 0; i < 16; i ++ ) {
			if( optionalSecProxyId[ i ] != 0 ) {
				return( false );
			}
		}
		return( true );
	}

	void CFSecSecSessionHBuff::setOptionalSecProxyIdNull() {
		for( int i = 0; i < 16; i ++ ) {
			optionalSecProxyId[i] = 0;
		}
	}

	void CFSecSecSessionHBuff::setOptionalSecProxyIdValue( const uuid_ptr_t value ) {
		uuid_copy( optionalSecProxyId, value );
	}

	void CFSecSecSessionHBuff::generateOptionalSecProxyId() {
		uuid_generate_random( optionalSecProxyId );
	}

	size_t CFSecSecSessionHBuff::hashCode() const {
		size_t hashCode = CFSecHPKey::hashCode();
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

	CFSecSecSessionHBuff CFSecSecSessionHBuff::operator =( cfsec::CFSecSecSessionBuff& src ) {
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

	CFSecSecSessionHBuff CFSecSecSessionHBuff::operator =( cfsec::CFSecSecSessionHBuff& src ) {
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

	bool CFSecSecSessionHBuff::operator <( const CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionHBuff::operator <( const CFSecSecSessionBySecDevIdxKey& rhs ) {
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

	bool CFSecSecSessionHBuff::operator <( const CFSecSecSessionByStartIdxKey& rhs ) {
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

	bool CFSecSecSessionHBuff::operator <( const CFSecSecSessionByFinishIdxKey& rhs ) {
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

	bool CFSecSecSessionHBuff::operator <( const CFSecSecSessionBySecProxyIdxKey& rhs ) {
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

	bool CFSecSecSessionHBuff::operator <( const CFSecSecSessionPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionHBuff::operator <( const CFSecSecSessionHPKey& rhs ) {
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
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionHBuff::operator <( const CFSecSecSessionHBuff& rhs ) {
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

	bool CFSecSecSessionHBuff::operator <( const CFSecSecSessionBuff& rhs ) {
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

	bool CFSecSecSessionHBuff::operator <=( const CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionHBuff::operator <=( const CFSecSecSessionBySecDevIdxKey& rhs ) {
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

	bool CFSecSecSessionHBuff::operator <=( const CFSecSecSessionByStartIdxKey& rhs ) {
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

	bool CFSecSecSessionHBuff::operator <=( const CFSecSecSessionByFinishIdxKey& rhs ) {
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

	bool CFSecSecSessionHBuff::operator <=( const CFSecSecSessionBySecProxyIdxKey& rhs ) {
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

	bool CFSecSecSessionHBuff::operator <=( const CFSecSecSessionPKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionHBuff::operator <=( const CFSecSecSessionHPKey& rhs ) {
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
		if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionHBuff::operator <=( const CFSecSecSessionHBuff& rhs ) {
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

	bool CFSecSecSessionHBuff::operator <=( const CFSecSecSessionBuff& rhs ) {
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

	bool CFSecSecSessionHBuff::operator ==( const CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecSessionHBuff::operator ==( const CFSecSecSessionBySecDevIdxKey& rhs ) {
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

	bool CFSecSecSessionHBuff::operator ==( const CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( getRequiredStart() != rhs.getRequiredStart() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecSessionHBuff::operator ==( const CFSecSecSessionByFinishIdxKey& rhs ) {
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

	bool CFSecSecSessionHBuff::operator ==( const CFSecSecSessionBySecProxyIdxKey& rhs ) {
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

	bool CFSecSecSessionHBuff::operator ==( const CFSecSecSessionPKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecSessionHBuff::operator ==( const CFSecSecSessionHPKey& rhs ) {
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
		if( 0 != uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecSessionHBuff::operator ==( const CFSecSecSessionHBuff& rhs ) {
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

	bool CFSecSecSessionHBuff::operator ==( const CFSecSecSessionBuff& rhs ) {
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

	bool CFSecSecSessionHBuff::operator !=( const CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionHBuff::operator !=( const CFSecSecSessionBySecDevIdxKey& rhs ) {
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

	bool CFSecSecSessionHBuff::operator !=( const CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredStart() != rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionHBuff::operator !=( const CFSecSecSessionByFinishIdxKey& rhs ) {
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

	bool CFSecSecSessionHBuff::operator !=( const CFSecSecSessionBySecProxyIdxKey& rhs ) {
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

	bool CFSecSecSessionHBuff::operator !=( const CFSecSecSessionPKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionHBuff::operator !=( const CFSecSecSessionHPKey& rhs ) {
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
		if( 0 != uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionHBuff::operator !=( const CFSecSecSessionHBuff& rhs ) {
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

	bool CFSecSecSessionHBuff::operator !=( const CFSecSecSessionBuff& rhs ) {
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

	bool CFSecSecSessionHBuff::operator >=( const CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionHBuff::operator >=( const CFSecSecSessionBySecDevIdxKey& rhs ) {
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

	bool CFSecSecSessionHBuff::operator >=( const CFSecSecSessionByStartIdxKey& rhs ) {
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

	bool CFSecSecSessionHBuff::operator >=( const CFSecSecSessionByFinishIdxKey& rhs ) {
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

	bool CFSecSecSessionHBuff::operator >=( const CFSecSecSessionBySecProxyIdxKey& rhs ) {
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

	bool CFSecSecSessionHBuff::operator >=( const CFSecSecSessionPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionHBuff::operator >=( const CFSecSecSessionHPKey& rhs ) {
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
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionHBuff::operator >=( const CFSecSecSessionHBuff& rhs ) {
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

	bool CFSecSecSessionHBuff::operator >=( const CFSecSecSessionBuff& rhs ) {
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

	bool CFSecSecSessionHBuff::operator >( const CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionHBuff::operator >( const CFSecSecSessionBySecDevIdxKey& rhs ) {
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

	bool CFSecSecSessionHBuff::operator >( const CFSecSecSessionByStartIdxKey& rhs ) {
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

	bool CFSecSecSessionHBuff::operator >( const CFSecSecSessionByFinishIdxKey& rhs ) {
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

	bool CFSecSecSessionHBuff::operator >( const CFSecSecSessionBySecProxyIdxKey& rhs ) {
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

	bool CFSecSecSessionHBuff::operator >( const CFSecSecSessionPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionHBuff::operator >( const CFSecSecSessionHPKey& rhs ) {
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
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionHBuff::operator >( const CFSecSecSessionHBuff& rhs ) {
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

	bool CFSecSecSessionHBuff::operator >( const CFSecSecSessionBuff& rhs ) {
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

	std::string CFSecSecSessionHBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecSessionHBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_AuditClusterId( "AuditClusterId" );
		static const std::string S_AuditStamp( "AuditStamp" );
		static const std::string S_AuditActionId( "AuditActionId" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_AuditSessionId( "AuditSessionId" );
		static const std::string S_SecSessionId( "SecSessionId" );
		static const std::string S_SecUserId( "SecUserId" );
		static const std::string S_SecDevName( "SecDevName" );
		static const std::string S_Start( "Start" );
		static const std::string S_Finish( "Finish" );
		static const std::string S_SecProxyId( "SecProxyId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_AuditClusterId, auditClusterId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_AuditClusterId, auditStamp ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_AuditActionId, auditActionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_AuditSessionId, auditSessionId ) );
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

	bool operator <(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs ) {
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
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs ) {
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
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs ) {
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
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs ) {
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

	bool operator <(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs ) {
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
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
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

	bool operator <(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
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

	bool operator <=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs ) {
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

	bool operator <=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs ) {
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

	bool operator <=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs ) {
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

	bool operator <=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs ) {
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

	bool operator <=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs ) {
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
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
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

	bool operator <=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
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

	bool operator ==(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs ) {
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

	bool operator ==(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( lhs.getRequiredStart() != rhs.getRequiredStart() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs ) {
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

	bool operator ==(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs ) {
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

	bool operator ==(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs ) {
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
		if( 0 != uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
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

	bool operator ==(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
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

	bool operator !=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs ) {
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

	bool operator !=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredStart() != rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs ) {
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

	bool operator !=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs ) {
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

	bool operator !=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs ) {
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
		if( 0 != uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
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

	bool operator !=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
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

	bool operator >=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs ) {
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

	bool operator >=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs ) {
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

	bool operator >=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs ) {
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

	bool operator >=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs ) {
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

	bool operator >=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs ) {
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
		if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
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

	bool operator >=(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
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

	bool operator >(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecUserIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs ) {
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

	bool operator >(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs ) {
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

	bool operator >(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs ) {
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

	bool operator >(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs ) {
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

	bool operator >(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHPKey& rhs ) {
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
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
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

	bool operator >(const  cfsec::CFSecSecSessionHBuff& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
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

