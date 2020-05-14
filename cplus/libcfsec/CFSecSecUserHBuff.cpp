// Description: C++18 implementation of a SecUser history buffer object.

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
#include <cfsec/CFSecSecUserPKey.hpp>
#include <cfsec/CFSecSecUserBuff.hpp>
#include <cfsec/CFSecSecUserHPKey.hpp>
#include <cfsec/CFSecSecUserHBuff.hpp>
#include <cfsec/CFSecSecUserByULoginIdxKey.hpp>
#include <cfsec/CFSecSecUserByEMConfIdxKey.hpp>
#include <cfsec/CFSecSecUserByPwdResetIdxKey.hpp>
#include <cfsec/CFSecSecUserByDefDevIdxKey.hpp>

namespace cfsec {

	const std::string CFSecSecUserHBuff::CLASS_NAME( "CFSecSecUserHBuff" );
	CFSecSecUserHBuff::CFSecSecUserHBuff()
	: CFSecHPKey(), cflib::ICFLibCloneableObj() {
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
		requiredLoginId = new std::string( cfsec::CFSecSecUserBuff::LOGINID_INIT_VALUE );
		requiredEMailAddress = new std::string( cfsec::CFSecSecUserBuff::EMAILADDRESS_INIT_VALUE );
		for( int i = 0; i < 16; i ++ ) {
			optionalEMailConfirmUuid[i] = 0;
		}
		for( int i = 0; i < 16; i ++ ) {
			optionalDfltDevUserId[i] = 0;
		}
		optionalDfltDevName = NULL;
		requiredPasswordHash = new std::string( cfsec::CFSecSecUserBuff::PASSWORDHASH_INIT_VALUE );
		for( int i = 0; i < 16; i ++ ) {
			optionalPasswordResetUuid[i] = 0;
		}
	}

	CFSecSecUserHBuff::CFSecSecUserHBuff( const CFSecSecUserHBuff& src )
	: CFSecHPKey(), cflib::ICFLibCloneableObj() {
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
		requiredLoginId = new std::string( cfsec::CFSecSecUserBuff::LOGINID_INIT_VALUE );
		requiredEMailAddress = new std::string( cfsec::CFSecSecUserBuff::EMAILADDRESS_INIT_VALUE );
		for( int i = 0; i < 16; i ++ ) {
			optionalEMailConfirmUuid[i] = 0;
		}
		for( int i = 0; i < 16; i ++ ) {
			optionalDfltDevUserId[i] = 0;
		}
		optionalDfltDevName = NULL;
		requiredPasswordHash = new std::string( cfsec::CFSecSecUserBuff::PASSWORDHASH_INIT_VALUE );
		for( int i = 0; i < 16; i ++ ) {
			optionalPasswordResetUuid[i] = 0;
		}
		setRequiredSecUserId( src.getRequiredSecUserId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredLoginId( src.getRequiredLoginId() );
		setRequiredEMailAddress( src.getRequiredEMailAddress() );
		if( src.isOptionalEMailConfirmUuidNull() ) {
			setOptionalEMailConfirmUuidNull();
		}
		else {
			setOptionalEMailConfirmUuidValue( src.getOptionalEMailConfirmUuidValue() );
		}
		if( src.isOptionalDfltDevUserIdNull() ) {
			setOptionalDfltDevUserIdNull();
		}
		else {
			setOptionalDfltDevUserIdValue( src.getOptionalDfltDevUserIdValue() );
		}
		if( src.isOptionalDfltDevNameNull() ) {
			setOptionalDfltDevNameNull();
		}
		else {
			setOptionalDfltDevNameValue( src.getOptionalDfltDevNameValue() );
		}
		setRequiredPasswordHash( src.getRequiredPasswordHash() );
		if( src.isOptionalPasswordResetUuidNull() ) {
			setOptionalPasswordResetUuidNull();
		}
		else {
			setOptionalPasswordResetUuidValue( src.getOptionalPasswordResetUuidValue() );
		}
	}

	CFSecSecUserHBuff::~CFSecSecUserHBuff() {
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
		if( requiredLoginId != NULL ) {
			delete requiredLoginId;
			requiredLoginId = NULL;
		}
		if( requiredEMailAddress != NULL ) {
			delete requiredEMailAddress;
			requiredEMailAddress = NULL;
		}
		for( int i = 0; i < 16; i ++ ) {
			optionalEMailConfirmUuid[i] = 0;
		}
		for( int i = 0; i < 16; i ++ ) {
			optionalDfltDevUserId[i] = 0;
		}
		if( optionalDfltDevName != NULL ) {
			delete optionalDfltDevName;
			optionalDfltDevName = NULL;
		}
		if( requiredPasswordHash != NULL ) {
			delete requiredPasswordHash;
			requiredPasswordHash = NULL;
		}
		for( int i = 0; i < 16; i ++ ) {
			optionalPasswordResetUuid[i] = 0;
		}
	}

	cflib::ICFLibCloneableObj* CFSecSecUserHBuff::clone() {
		CFSecSecUserHBuff* copy = new CFSecSecUserHBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const uuid_ptr_t CFSecSecUserHBuff::getRequiredSecUserId() const {
		return( requiredSecUserId );
	}

	const uuid_ptr_t CFSecSecUserHBuff::getRequiredSecUserIdReference() const {
		return( requiredSecUserId );
	}

	void CFSecSecUserHBuff::setRequiredSecUserId( const uuid_ptr_t value ) {
		uuid_copy( requiredSecUserId, value );
	}

	void CFSecSecUserHBuff::generateRequiredSecUserId() {
		uuid_generate_random( requiredSecUserId );
	}

	const std::string& CFSecSecUserHBuff::getRequiredLoginId() const {
		return( *requiredLoginId );
	}

	const std::string* CFSecSecUserHBuff::getRequiredLoginIdReference() const {
		return( requiredLoginId );
	}

	void CFSecSecUserHBuff::setRequiredLoginId( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredLoginId" );
		if( value.length() > CFSecSecUserBuff::LOGINID_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecSecUserBuff::LOGINID_MAX_LEN );
		}
		if( requiredLoginId != NULL ) {
			delete requiredLoginId;
			requiredLoginId = NULL;
		}
		requiredLoginId = new std::string( value );
	}

	const std::string& CFSecSecUserHBuff::getRequiredEMailAddress() const {
		return( *requiredEMailAddress );
	}

	const std::string* CFSecSecUserHBuff::getRequiredEMailAddressReference() const {
		return( requiredEMailAddress );
	}

	void CFSecSecUserHBuff::setRequiredEMailAddress( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredEMailAddress" );
		if( value.length() > CFSecSecUserBuff::EMAILADDRESS_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecSecUserBuff::EMAILADDRESS_MAX_LEN );
		}
		if( requiredEMailAddress != NULL ) {
			delete requiredEMailAddress;
			requiredEMailAddress = NULL;
		}
		requiredEMailAddress = new std::string( value );
	}

	const uuid_ptr_t CFSecSecUserHBuff::getOptionalEMailConfirmUuidValue() const {
		static const std::string S_ProcName( "getOptionalEMailConfirmUuidValue" );
		if( isOptionalEMailConfirmUuidNull() ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( optionalEMailConfirmUuid );
	}

	const uuid_ptr_t CFSecSecUserHBuff::getOptionalEMailConfirmUuidReference() const {
		if( isOptionalEMailConfirmUuidNull() ) {
			return( NULL );
		}
		else {
			return( optionalEMailConfirmUuid );
		}
	}

	const bool CFSecSecUserHBuff::isOptionalEMailConfirmUuidNull() const {
		for( int i = 0; i < 16; i ++ ) {
			if( optionalEMailConfirmUuid[ i ] != 0 ) {
				return( false );
			}
		}
		return( true );
	}

	void CFSecSecUserHBuff::setOptionalEMailConfirmUuidNull() {
		for( int i = 0; i < 16; i ++ ) {
			optionalEMailConfirmUuid[i] = 0;
		}
	}

	void CFSecSecUserHBuff::setOptionalEMailConfirmUuidValue( const uuid_ptr_t value ) {
		uuid_copy( optionalEMailConfirmUuid, value );
	}

	void CFSecSecUserHBuff::generateOptionalEMailConfirmUuid() {
		uuid_generate_random( optionalEMailConfirmUuid );
	}

	const uuid_ptr_t CFSecSecUserHBuff::getOptionalDfltDevUserIdValue() const {
		static const std::string S_ProcName( "getOptionalDfltDevUserIdValue" );
		if( isOptionalDfltDevUserIdNull() ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( optionalDfltDevUserId );
	}

	const uuid_ptr_t CFSecSecUserHBuff::getOptionalDfltDevUserIdReference() const {
		if( isOptionalDfltDevUserIdNull() ) {
			return( NULL );
		}
		else {
			return( optionalDfltDevUserId );
		}
	}

	const bool CFSecSecUserHBuff::isOptionalDfltDevUserIdNull() const {
		for( int i = 0; i < 16; i ++ ) {
			if( optionalDfltDevUserId[ i ] != 0 ) {
				return( false );
			}
		}
		return( true );
	}

	void CFSecSecUserHBuff::setOptionalDfltDevUserIdNull() {
		for( int i = 0; i < 16; i ++ ) {
			optionalDfltDevUserId[i] = 0;
		}
	}

	void CFSecSecUserHBuff::setOptionalDfltDevUserIdValue( const uuid_ptr_t value ) {
		uuid_copy( optionalDfltDevUserId, value );
	}

	void CFSecSecUserHBuff::generateOptionalDfltDevUserId() {
		uuid_generate_random( optionalDfltDevUserId );
	}

	const std::string& CFSecSecUserHBuff::getOptionalDfltDevNameValue() const {
		static const std::string S_ProcName( "getOptionalDfltDevNameValue" );
		if( optionalDfltDevName == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( *optionalDfltDevName );
	}

	const std::string* CFSecSecUserHBuff::getOptionalDfltDevNameReference() const {
		return( optionalDfltDevName );
	}

	const bool CFSecSecUserHBuff::isOptionalDfltDevNameNull() const {
		return( optionalDfltDevName == NULL );
	}

	void CFSecSecUserHBuff::setOptionalDfltDevNameNull() {
		if( optionalDfltDevName != NULL ) {
			delete optionalDfltDevName;
			optionalDfltDevName = NULL;
		}
	}

	void CFSecSecUserHBuff::setOptionalDfltDevNameValue( const std::string& value ) {
		static const std::string S_ProcName( "setOptionalDfltDevNameValue" );
		if( value.length() > CFSecSecUserBuff::DFLTDEVNAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecSecUserBuff::DFLTDEVNAME_MAX_LEN );
		}
		if( optionalDfltDevName != NULL ) {
			delete optionalDfltDevName;
			optionalDfltDevName = NULL;
		}
		optionalDfltDevName = new std::string( value );
	}

	const std::string& CFSecSecUserHBuff::getRequiredPasswordHash() const {
		return( *requiredPasswordHash );
	}

	const std::string* CFSecSecUserHBuff::getRequiredPasswordHashReference() const {
		return( requiredPasswordHash );
	}

	void CFSecSecUserHBuff::setRequiredPasswordHash( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredPasswordHash" );
		if( value.length() > CFSecSecUserBuff::PASSWORDHASH_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecSecUserBuff::PASSWORDHASH_MAX_LEN );
		}
		if( requiredPasswordHash != NULL ) {
			delete requiredPasswordHash;
			requiredPasswordHash = NULL;
		}
		requiredPasswordHash = new std::string( value );
	}

	const uuid_ptr_t CFSecSecUserHBuff::getOptionalPasswordResetUuidValue() const {
		static const std::string S_ProcName( "getOptionalPasswordResetUuidValue" );
		if( isOptionalPasswordResetUuidNull() ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( optionalPasswordResetUuid );
	}

	const uuid_ptr_t CFSecSecUserHBuff::getOptionalPasswordResetUuidReference() const {
		if( isOptionalPasswordResetUuidNull() ) {
			return( NULL );
		}
		else {
			return( optionalPasswordResetUuid );
		}
	}

	const bool CFSecSecUserHBuff::isOptionalPasswordResetUuidNull() const {
		for( int i = 0; i < 16; i ++ ) {
			if( optionalPasswordResetUuid[ i ] != 0 ) {
				return( false );
			}
		}
		return( true );
	}

	void CFSecSecUserHBuff::setOptionalPasswordResetUuidNull() {
		for( int i = 0; i < 16; i ++ ) {
			optionalPasswordResetUuid[i] = 0;
		}
	}

	void CFSecSecUserHBuff::setOptionalPasswordResetUuidValue( const uuid_ptr_t value ) {
		uuid_copy( optionalPasswordResetUuid, value );
	}

	void CFSecSecUserHBuff::generateOptionalPasswordResetUuid() {
		uuid_generate_random( optionalPasswordResetUuid );
	}

	size_t CFSecSecUserHBuff::hashCode() const {
		size_t hashCode = CFSecHPKey::hashCode();
		hashCode = hashCode + cflib::CFLib::hash( getRequiredSecUserId() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredLoginId() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredEMailAddress() );
		if( ! isOptionalEMailConfirmUuidNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalEMailConfirmUuidValue() );
		}
		if( ! isOptionalDfltDevUserIdNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalDfltDevUserIdValue() );
		}
		if( ! isOptionalDfltDevNameNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalDfltDevNameValue() );
		}
		hashCode = hashCode + cflib::CFLib::hash( getRequiredPasswordHash() );
		if( ! isOptionalPasswordResetUuidNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalPasswordResetUuidValue() );
		}
		return( hashCode );
	}

	CFSecSecUserHBuff CFSecSecUserHBuff::operator =( cfsec::CFSecSecUserBuff& src ) {
		setRequiredSecUserId( src.getRequiredSecUserId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredLoginId( src.getRequiredLoginId() );
		setRequiredEMailAddress( src.getRequiredEMailAddress() );
		if( src.isOptionalEMailConfirmUuidNull() ) {
			setOptionalEMailConfirmUuidNull();
		}
		else {
			setOptionalEMailConfirmUuidValue( src.getOptionalEMailConfirmUuidValue() );
		}
		if( src.isOptionalDfltDevUserIdNull() ) {
			setOptionalDfltDevUserIdNull();
		}
		else {
			setOptionalDfltDevUserIdValue( src.getOptionalDfltDevUserIdValue() );
		}
		if( src.isOptionalDfltDevNameNull() ) {
			setOptionalDfltDevNameNull();
		}
		else {
			setOptionalDfltDevNameValue( src.getOptionalDfltDevNameValue() );
		}
		setRequiredPasswordHash( src.getRequiredPasswordHash() );
		if( src.isOptionalPasswordResetUuidNull() ) {
			setOptionalPasswordResetUuidNull();
		}
		else {
			setOptionalPasswordResetUuidValue( src.getOptionalPasswordResetUuidValue() );
		}
		return( *this );
	}

	CFSecSecUserHBuff CFSecSecUserHBuff::operator =( cfsec::CFSecSecUserHBuff& src ) {
		setRequiredSecUserId( src.getRequiredSecUserId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredLoginId( src.getRequiredLoginId() );
		setRequiredEMailAddress( src.getRequiredEMailAddress() );
		if( src.isOptionalEMailConfirmUuidNull() ) {
			setOptionalEMailConfirmUuidNull();
		}
		else {
			setOptionalEMailConfirmUuidValue( src.getOptionalEMailConfirmUuidValue() );
		}
		if( src.isOptionalDfltDevUserIdNull() ) {
			setOptionalDfltDevUserIdNull();
		}
		else {
			setOptionalDfltDevUserIdValue( src.getOptionalDfltDevUserIdValue() );
		}
		if( src.isOptionalDfltDevNameNull() ) {
			setOptionalDfltDevNameNull();
		}
		else {
			setOptionalDfltDevNameValue( src.getOptionalDfltDevNameValue() );
		}
		setRequiredPasswordHash( src.getRequiredPasswordHash() );
		if( src.isOptionalPasswordResetUuidNull() ) {
			setOptionalPasswordResetUuidNull();
		}
		else {
			setOptionalPasswordResetUuidValue( src.getOptionalPasswordResetUuidValue() );
		}
		return( *this );
	}

	bool CFSecSecUserHBuff::operator <( const CFSecSecUserByULoginIdxKey& rhs ) {
		if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserHBuff::operator <( const CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecUserHBuff::operator <( const CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecUserHBuff::operator <( const CFSecSecUserByDefDevIdxKey& rhs ) {
		if( ! isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
		}
		if( ! isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
			if( getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecUserHBuff::operator <( const CFSecSecUserPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserHBuff::operator <( const CFSecSecUserHPKey& rhs ) {
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
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserHBuff::operator <( const CFSecSecUserHBuff& rhs ) {
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
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		if( getRequiredEMailAddress() > rhs.getRequiredEMailAddress() ) {
			return( false );
		}
		else if( getRequiredEMailAddress() < rhs.getRequiredEMailAddress() ) {
			return( true );
		}
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		if( ! isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
		}
		if( ! isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
			if( getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
		}
		if( getRequiredPasswordHash() > rhs.getRequiredPasswordHash() ) {
			return( false );
		}
		else if( getRequiredPasswordHash() < rhs.getRequiredPasswordHash() ) {
			return( true );
		}
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecUserHBuff::operator <( const CFSecSecUserBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		if( getRequiredEMailAddress() > rhs.getRequiredEMailAddress() ) {
			return( false );
		}
		else if( getRequiredEMailAddress() < rhs.getRequiredEMailAddress() ) {
			return( true );
		}
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		if( ! isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
		}
		if( ! isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
			if( getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
		}
		if( getRequiredPasswordHash() > rhs.getRequiredPasswordHash() ) {
			return( false );
		}
		else if( getRequiredPasswordHash() < rhs.getRequiredPasswordHash() ) {
			return( true );
		}
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecUserHBuff::operator <=( const CFSecSecUserByULoginIdxKey& rhs ) {
		if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator <=( const CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator <=( const CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator <=( const CFSecSecUserByDefDevIdxKey& rhs ) {
		if( ! isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
		}
		if( ! isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
			if( getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator <=( const CFSecSecUserPKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator <=( const CFSecSecUserHPKey& rhs ) {
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
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator <=( const CFSecSecUserHBuff& rhs ) {
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
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		if( getRequiredEMailAddress() > rhs.getRequiredEMailAddress() ) {
			return( false );
		}
		else if( getRequiredEMailAddress() < rhs.getRequiredEMailAddress() ) {
			return( true );
		}
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		if( ! isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
		}
		if( ! isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
			if( getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
		}
		if( getRequiredPasswordHash() > rhs.getRequiredPasswordHash() ) {
			return( false );
		}
		else if( getRequiredPasswordHash() < rhs.getRequiredPasswordHash() ) {
			return( true );
		}
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator <=( const CFSecSecUserBuff& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		if( getRequiredEMailAddress() > rhs.getRequiredEMailAddress() ) {
			return( false );
		}
		else if( getRequiredEMailAddress() < rhs.getRequiredEMailAddress() ) {
			return( true );
		}
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		if( ! isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
		}
		if( ! isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
			if( getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
		}
		if( getRequiredPasswordHash() > rhs.getRequiredPasswordHash() ) {
			return( false );
		}
		else if( getRequiredPasswordHash() < rhs.getRequiredPasswordHash() ) {
			return( true );
		}
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator ==( const CFSecSecUserByULoginIdxKey& rhs ) {
		if( getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator ==( const CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				if( 0 != uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator ==( const CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				if( 0 != uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator ==( const CFSecSecUserByDefDevIdxKey& rhs ) {
		if( ! isOptionalDfltDevUserIdNull() ) {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				if( 0 != uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
		}
		if( ! isOptionalDfltDevNameNull() ) {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				if( getOptionalDfltDevNameValue() != rhs.getOptionalDfltDevNameValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator ==( const CFSecSecUserPKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator ==( const CFSecSecUserHPKey& rhs ) {
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
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator ==( const CFSecSecUserHBuff& rhs ) {
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
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( false );
		}
		if( getRequiredEMailAddress() != rhs.getRequiredEMailAddress() ) {
			return( false );
		}
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				if( 0 != uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		if( ! isOptionalDfltDevUserIdNull() ) {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				if( 0 != uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
		}
		if( ! isOptionalDfltDevNameNull() ) {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				if( getOptionalDfltDevNameValue() != rhs.getOptionalDfltDevNameValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
		}
		if( getRequiredPasswordHash() != rhs.getRequiredPasswordHash() ) {
			return( false );
		}
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				if( 0 != uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator ==( const CFSecSecUserBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( false );
		}
		if( getRequiredEMailAddress() != rhs.getRequiredEMailAddress() ) {
			return( false );
		}
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				if( 0 != uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		if( ! isOptionalDfltDevUserIdNull() ) {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				if( 0 != uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
		}
		if( ! isOptionalDfltDevNameNull() ) {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				if( getOptionalDfltDevNameValue() != rhs.getOptionalDfltDevNameValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
		}
		if( getRequiredPasswordHash() != rhs.getRequiredPasswordHash() ) {
			return( false );
		}
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				if( 0 != uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator !=( const CFSecSecUserByULoginIdxKey& rhs ) {
		if( getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserHBuff::operator !=( const CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecUserHBuff::operator !=( const CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecUserHBuff::operator !=( const CFSecSecUserByDefDevIdxKey& rhs ) {
		if( ! isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
		}
		if( ! isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
			if( getOptionalDfltDevNameValue() != rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecUserHBuff::operator !=( const CFSecSecUserPKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserHBuff::operator !=( const CFSecSecUserHPKey& rhs ) {
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
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserHBuff::operator !=( const CFSecSecUserHBuff& rhs ) {
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
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( true );
		}
		if( getRequiredEMailAddress() != rhs.getRequiredEMailAddress() ) {
			return( true );
		}
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		if( ! isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
		}
		if( ! isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
			if( getOptionalDfltDevNameValue() != rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
		}
		if( getRequiredPasswordHash() != rhs.getRequiredPasswordHash() ) {
			return( true );
		}
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecUserHBuff::operator !=( const CFSecSecUserBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( true );
		}
		if( getRequiredEMailAddress() != rhs.getRequiredEMailAddress() ) {
			return( true );
		}
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		if( ! isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
		}
		if( ! isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
			if( getOptionalDfltDevNameValue() != rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
		}
		if( getRequiredPasswordHash() != rhs.getRequiredPasswordHash() ) {
			return( true );
		}
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecUserHBuff::operator >=( const CFSecSecUserByULoginIdxKey& rhs ) {
		if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator >=( const CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator >=( const CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator >=( const CFSecSecUserByDefDevIdxKey& rhs ) {
		if( ! isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
		}
		if( ! isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
			if( getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator >=( const CFSecSecUserPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator >=( const CFSecSecUserHPKey& rhs ) {
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
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator >=( const CFSecSecUserHBuff& rhs ) {
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
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		if( getRequiredEMailAddress() < rhs.getRequiredEMailAddress() ) {
			return( false );
		}
		else if( getRequiredEMailAddress() > rhs.getRequiredEMailAddress() ) {
			return( true );
		}
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		if( ! isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
		}
		if( ! isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
			if( getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
		}
		if( getRequiredPasswordHash() < rhs.getRequiredPasswordHash() ) {
			return( false );
		}
		else if( getRequiredPasswordHash() > rhs.getRequiredPasswordHash() ) {
			return( true );
		}
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator >=( const CFSecSecUserBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		if( getRequiredEMailAddress() < rhs.getRequiredEMailAddress() ) {
			return( false );
		}
		else if( getRequiredEMailAddress() > rhs.getRequiredEMailAddress() ) {
			return( true );
		}
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		if( ! isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
		}
		if( ! isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
			if( getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
		}
		if( getRequiredPasswordHash() < rhs.getRequiredPasswordHash() ) {
			return( false );
		}
		else if( getRequiredPasswordHash() > rhs.getRequiredPasswordHash() ) {
			return( true );
		}
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecUserHBuff::operator >( const CFSecSecUserByULoginIdxKey& rhs ) {
		if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserHBuff::operator >( const CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFSecSecUserHBuff::operator >( const CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFSecSecUserHBuff::operator >( const CFSecSecUserByDefDevIdxKey& rhs ) {
		if( ! isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		if( ! isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
			if( getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFSecSecUserHBuff::operator >( const CFSecSecUserPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserHBuff::operator >( const CFSecSecUserHPKey& rhs ) {
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
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserHBuff::operator >( const CFSecSecUserHBuff& rhs ) {
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
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		if( getRequiredEMailAddress() < rhs.getRequiredEMailAddress() ) {
			return( false );
		}
		else if( getRequiredEMailAddress() > rhs.getRequiredEMailAddress() ) {
			return( true );
		}
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		if( ! isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		if( ! isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
			if( getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		if( getRequiredPasswordHash() < rhs.getRequiredPasswordHash() ) {
			return( false );
		}
		else if( getRequiredPasswordHash() > rhs.getRequiredPasswordHash() ) {
			return( true );
		}
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFSecSecUserHBuff::operator >( const CFSecSecUserBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		if( getRequiredEMailAddress() < rhs.getRequiredEMailAddress() ) {
			return( false );
		}
		else if( getRequiredEMailAddress() > rhs.getRequiredEMailAddress() ) {
			return( true );
		}
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		if( ! isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		if( ! isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
			if( getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		if( getRequiredPasswordHash() < rhs.getRequiredPasswordHash() ) {
			return( false );
		}
		else if( getRequiredPasswordHash() > rhs.getRequiredPasswordHash() ) {
			return( true );
		}
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	std::string CFSecSecUserHBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecUserHBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_AuditClusterId( "AuditClusterId" );
		static const std::string S_AuditStamp( "AuditStamp" );
		static const std::string S_AuditActionId( "AuditActionId" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_AuditSessionId( "AuditSessionId" );
		static const std::string S_SecUserId( "SecUserId" );
		static const std::string S_LoginId( "LoginId" );
		static const std::string S_EMailAddress( "EMailAddress" );
		static const std::string S_EMailConfirmUuid( "EMailConfirmUuid" );
		static const std::string S_DfltDevUserId( "DfltDevUserId" );
		static const std::string S_DfltDevName( "DfltDevName" );
		static const std::string S_PasswordHash( "PasswordHash" );
		static const std::string S_PasswordResetUuid( "PasswordResetUuid" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_AuditClusterId, auditClusterId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_AuditClusterId, auditStamp ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_AuditActionId, auditActionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_AuditSessionId, auditSessionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, getRequiredSecUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_LoginId, getRequiredLoginId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_EMailAddress, getRequiredEMailAddress() ) );
		if( ! isOptionalEMailConfirmUuidNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_EMailConfirmUuid, getOptionalEMailConfirmUuidValue() ) );
		}
		if( ! isOptionalDfltDevUserIdNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_DfltDevUserId, getOptionalDfltDevUserIdValue() ) );
		}
		if( ! isOptionalDfltDevNameNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_DfltDevName, getOptionalDfltDevNameValue() ) );
		}
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_PasswordHash, getRequiredPasswordHash() ) );
		if( ! isOptionalPasswordResetUuidNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_PasswordResetUuid, getOptionalPasswordResetUuidValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs ) {
		if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs ) {
		if( ! lhs.isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
			if( lhs.getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs ) {
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
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
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
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		if( lhs.getRequiredEMailAddress() > rhs.getRequiredEMailAddress() ) {
			return( false );
		}
		else if( lhs.getRequiredEMailAddress() < rhs.getRequiredEMailAddress() ) {
			return( true );
		}
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
			if( lhs.getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredPasswordHash() > rhs.getRequiredPasswordHash() ) {
			return( false );
		}
		else if( lhs.getRequiredPasswordHash() < rhs.getRequiredPasswordHash() ) {
			return( true );
		}
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		if( lhs.getRequiredEMailAddress() > rhs.getRequiredEMailAddress() ) {
			return( false );
		}
		else if( lhs.getRequiredEMailAddress() < rhs.getRequiredEMailAddress() ) {
			return( true );
		}
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
			if( lhs.getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredPasswordHash() > rhs.getRequiredPasswordHash() ) {
			return( false );
		}
		else if( lhs.getRequiredPasswordHash() < rhs.getRequiredPasswordHash() ) {
			return( true );
		}
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs ) {
		if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs ) {
		if( ! lhs.isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
			if( lhs.getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs ) {
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
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
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
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		if( lhs.getRequiredEMailAddress() > rhs.getRequiredEMailAddress() ) {
			return( false );
		}
		else if( lhs.getRequiredEMailAddress() < rhs.getRequiredEMailAddress() ) {
			return( true );
		}
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
			if( lhs.getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredPasswordHash() > rhs.getRequiredPasswordHash() ) {
			return( false );
		}
		else if( lhs.getRequiredPasswordHash() < rhs.getRequiredPasswordHash() ) {
			return( true );
		}
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		if( lhs.getRequiredEMailAddress() > rhs.getRequiredEMailAddress() ) {
			return( false );
		}
		else if( lhs.getRequiredEMailAddress() < rhs.getRequiredEMailAddress() ) {
			return( true );
		}
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
			if( lhs.getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredPasswordHash() > rhs.getRequiredPasswordHash() ) {
			return( false );
		}
		else if( lhs.getRequiredPasswordHash() < rhs.getRequiredPasswordHash() ) {
			return( true );
		}
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs ) {
		if( lhs.getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				if( 0 != uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				if( 0 != uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs ) {
		if( ! lhs.isOptionalDfltDevUserIdNull() ) {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				if( 0 != uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalDfltDevNameNull() ) {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				if( lhs.getOptionalDfltDevNameValue() != rhs.getOptionalDfltDevNameValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserPKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs ) {
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
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
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
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( lhs.getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( false );
		}
		if( lhs.getRequiredEMailAddress() != rhs.getRequiredEMailAddress() ) {
			return( false );
		}
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				if( 0 != uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalDfltDevUserIdNull() ) {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				if( 0 != uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalDfltDevNameNull() ) {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				if( lhs.getOptionalDfltDevNameValue() != rhs.getOptionalDfltDevNameValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredPasswordHash() != rhs.getRequiredPasswordHash() ) {
			return( false );
		}
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				if( 0 != uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( lhs.getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( false );
		}
		if( lhs.getRequiredEMailAddress() != rhs.getRequiredEMailAddress() ) {
			return( false );
		}
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				if( 0 != uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalDfltDevUserIdNull() ) {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				if( 0 != uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalDfltDevNameNull() ) {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				if( lhs.getOptionalDfltDevNameValue() != rhs.getOptionalDfltDevNameValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredPasswordHash() != rhs.getRequiredPasswordHash() ) {
			return( false );
		}
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				if( 0 != uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs ) {
		if( lhs.getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs ) {
		if( ! lhs.isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalDfltDevNameValue() != rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserPKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs ) {
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
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
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
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( true );
		}
		if( lhs.getRequiredEMailAddress() != rhs.getRequiredEMailAddress() ) {
			return( true );
		}
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalDfltDevNameValue() != rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredPasswordHash() != rhs.getRequiredPasswordHash() ) {
			return( true );
		}
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( true );
		}
		if( lhs.getRequiredEMailAddress() != rhs.getRequiredEMailAddress() ) {
			return( true );
		}
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalDfltDevNameValue() != rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
		}
		if( lhs.getRequiredPasswordHash() != rhs.getRequiredPasswordHash() ) {
			return( true );
		}
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs ) {
		if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs ) {
		if( ! lhs.isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserPKey& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs ) {
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
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
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
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		if( lhs.getRequiredEMailAddress() < rhs.getRequiredEMailAddress() ) {
			return( false );
		}
		else if( lhs.getRequiredEMailAddress() > rhs.getRequiredEMailAddress() ) {
			return( true );
		}
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredPasswordHash() < rhs.getRequiredPasswordHash() ) {
			return( false );
		}
		else if( lhs.getRequiredPasswordHash() > rhs.getRequiredPasswordHash() ) {
			return( true );
		}
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		if( lhs.getRequiredEMailAddress() < rhs.getRequiredEMailAddress() ) {
			return( false );
		}
		else if( lhs.getRequiredEMailAddress() > rhs.getRequiredEMailAddress() ) {
			return( true );
		}
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredPasswordHash() < rhs.getRequiredPasswordHash() ) {
			return( false );
		}
		else if( lhs.getRequiredPasswordHash() > rhs.getRequiredPasswordHash() ) {
			return( true );
		}
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs ) {
		if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs ) {
		if( ! lhs.isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs ) {
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
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
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
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		if( lhs.getRequiredEMailAddress() < rhs.getRequiredEMailAddress() ) {
			return( false );
		}
		else if( lhs.getRequiredEMailAddress() > rhs.getRequiredEMailAddress() ) {
			return( true );
		}
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredPasswordHash() < rhs.getRequiredPasswordHash() ) {
			return( false );
		}
		else if( lhs.getRequiredPasswordHash() > rhs.getRequiredPasswordHash() ) {
			return( true );
		}
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecUserHBuff& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		if( lhs.getRequiredEMailAddress() < rhs.getRequiredEMailAddress() ) {
			return( false );
		}
		else if( lhs.getRequiredEMailAddress() > rhs.getRequiredEMailAddress() ) {
			return( true );
		}
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalDfltDevUserIdNull() ) {
			if( rhs.isOptionalDfltDevUserIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalDfltDevUserIdValue(), rhs.getOptionalDfltDevUserIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevUserIdNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalDfltDevNameNull() ) {
			if( rhs.isOptionalDfltDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalDfltDevNameValue() < rhs.getOptionalDfltDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalDfltDevNameValue() > rhs.getOptionalDfltDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDfltDevNameNull() ) {
				return( false );
			}
		}
		if( lhs.getRequiredPasswordHash() < rhs.getRequiredPasswordHash() ) {
			return( false );
		}
		else if( lhs.getRequiredPasswordHash() > rhs.getRequiredPasswordHash() ) {
			return( true );
		}
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( false );
	}
}

