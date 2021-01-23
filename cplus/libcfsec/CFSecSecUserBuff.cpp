// Description: C++18 implementation for a SecUser buffer object.

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

#include <cfsec/CFSecSecUserByULoginIdxKey.hpp>
#include <cfsec/CFSecSecUserByEMConfIdxKey.hpp>
#include <cfsec/CFSecSecUserByPwdResetIdxKey.hpp>
#include <cfsec/CFSecSecUserByDefDevIdxKey.hpp>
#include <cfsec/CFSecSchema.hpp>

namespace cfsec {

	const std::string CFSecSecUserBuff::S_VALUE( "value" );
	const std::string CFSecSecUserBuff::S_VALUE_LENGTH( "value.length()" );

	const std::string CFSecSecUserBuff::GENDEFNAME( "SecUser" );
	const classcode_t CFSecSecUserBuff::CLASS_CODE = 0xa011L;
	const std::string CFSecSecUserBuff::CLASS_NAME( "CFSecSecUserBuff" );
		const std::string CFSecSecUserBuff::COLNAME_SECUSERID( "SecUserId" );
		const std::string CFSecSecUserBuff::COLNAME_LOGINID( "LoginId" );
		const std::string CFSecSecUserBuff::COLNAME_EMAILADDRESS( "EMailAddress" );
		const std::string CFSecSecUserBuff::COLNAME_EMAILCONFIRMUUID( "EMailConfirmUuid" );
		const std::string CFSecSecUserBuff::COLNAME_DFLTDEVUSERID( "DfltDevUserId" );
		const std::string CFSecSecUserBuff::COLNAME_DFLTDEVNAME( "DfltDevName" );
		const std::string CFSecSecUserBuff::COLNAME_PASSWORDHASH( "PasswordHash" );
		const std::string CFSecSecUserBuff::COLNAME_PASSWORDRESETUUID( "PasswordResetUuid" );
	const char* CFSecSecUserBuff::S_INIT_CREATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const char* CFSecSecUserBuff::S_INIT_UPDATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const std::string CFSecSecUserBuff::LOGINID_INIT_VALUE( "" );
	const std::string CFSecSecUserBuff::EMAILADDRESS_INIT_VALUE( "" );
	const std::string CFSecSecUserBuff::DFLTDEVNAME_INIT_VALUE( "" );
	const std::string CFSecSecUserBuff::PASSWORDHASH_INIT_VALUE( "" );
	const std::string::size_type CFSecSecUserBuff::LOGINID_MAX_LEN = 32;
	const std::string::size_type CFSecSecUserBuff::EMAILADDRESS_MAX_LEN = 192;
	const std::string::size_type CFSecSecUserBuff::DFLTDEVNAME_MAX_LEN = 127;
	const std::string::size_type CFSecSecUserBuff::PASSWORDHASH_MAX_LEN = 256;

	CFSecSecUserBuff::CFSecSecUserBuff()
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

	CFSecSecUserBuff::CFSecSecUserBuff( const CFSecSecUserBuff& src )
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
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
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

	CFSecSecUserBuff::~CFSecSecUserBuff() {
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
		for( int i = 0; i < 16; i++ ) {
			createdByUserId[i] = 0;
		}
		for( int i = 0; i < 16; i++ ) {
			updatedByUserId[i] = 0;
		}
	}

	cflib::ICFLibCloneableObj* CFSecSecUserBuff::clone() {
		CFSecSecUserBuff* copy = new CFSecSecUserBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const std::string& CFSecSecUserBuff::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecSecUserBuff::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecSecUserBuff::implementsClassCode( const classcode_t argClassCode ) {
		if( argClassCode == CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	const uuid_ptr_t CFSecSecUserBuff::getCreatedByUserId() const {
		return( createdByUserId );
	}

	void CFSecSecUserBuff::setCreatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( createdByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecSecUserBuff::getCreatedAt() const {
		return( createdAt );
	}

	void CFSecSecUserBuff::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		createdAt = value;
	}

	const uuid_ptr_t CFSecSecUserBuff::getUpdatedByUserId() const {
		return( updatedByUserId );
	}

	void CFSecSecUserBuff::setUpdatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( updatedByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecSecUserBuff::getUpdatedAt() const {
		return( updatedAt );
	}

	void CFSecSecUserBuff::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		updatedAt = value;
	}
	const uuid_ptr_t CFSecSecUserBuff::getRequiredSecUserId() const {
		return( requiredSecUserId );
	}

	const uuid_ptr_t CFSecSecUserBuff::getRequiredSecUserIdReference() const {
		return( requiredSecUserId );
	}

	void CFSecSecUserBuff::setRequiredSecUserId( const uuid_ptr_t value ) {
		uuid_copy( requiredSecUserId, value );
	}

	void CFSecSecUserBuff::generateRequiredSecUserId() {
		uuid_generate_random( requiredSecUserId );
	}

	const std::string& CFSecSecUserBuff::getRequiredLoginId() const {
		return( *requiredLoginId );
	}

	const std::string* CFSecSecUserBuff::getRequiredLoginIdReference() const {
		return( requiredLoginId );
	}

	void CFSecSecUserBuff::setRequiredLoginId( const std::string& value ) {
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

	const std::string& CFSecSecUserBuff::getRequiredEMailAddress() const {
		return( *requiredEMailAddress );
	}

	const std::string* CFSecSecUserBuff::getRequiredEMailAddressReference() const {
		return( requiredEMailAddress );
	}

	void CFSecSecUserBuff::setRequiredEMailAddress( const std::string& value ) {
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

	const bool CFSecSecUserBuff::isOptionalEMailConfirmUuidNull() const {
		for( int i = 0; i < 16; i ++ ) {
			if( optionalEMailConfirmUuid[ i ] != 0 ) {
				return( false );
			}
		}
		return( true );
	}

	const uuid_ptr_t CFSecSecUserBuff::getOptionalEMailConfirmUuidValue() const {
		static const std::string S_ProcName( "getOptionalEMailConfirmUuidValue" );
		if( isOptionalEMailConfirmUuidNull() ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( optionalEMailConfirmUuid );
	}

	const uuid_ptr_t CFSecSecUserBuff::getOptionalEMailConfirmUuidReference() const {
		if( isOptionalEMailConfirmUuidNull() ) {
			return( NULL );
		}
		else {
			return( optionalEMailConfirmUuid );
		}
	}

	void CFSecSecUserBuff::setOptionalEMailConfirmUuidNull() {
		for( int i = 0; i < 16; i ++ ) {
			optionalEMailConfirmUuid[i] = 0;
		}
	}

	void CFSecSecUserBuff::setOptionalEMailConfirmUuidValue( const uuid_ptr_t value ) {
		uuid_copy( optionalEMailConfirmUuid, value );
	}

	void CFSecSecUserBuff::generateOptionalEMailConfirmUuid() {
		uuid_generate_random( optionalEMailConfirmUuid );
	}

	const bool CFSecSecUserBuff::isOptionalDfltDevUserIdNull() const {
		for( int i = 0; i < 16; i ++ ) {
			if( optionalDfltDevUserId[ i ] != 0 ) {
				return( false );
			}
		}
		return( true );
	}

	const uuid_ptr_t CFSecSecUserBuff::getOptionalDfltDevUserIdValue() const {
		static const std::string S_ProcName( "getOptionalDfltDevUserIdValue" );
		if( isOptionalDfltDevUserIdNull() ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( optionalDfltDevUserId );
	}

	const uuid_ptr_t CFSecSecUserBuff::getOptionalDfltDevUserIdReference() const {
		if( isOptionalDfltDevUserIdNull() ) {
			return( NULL );
		}
		else {
			return( optionalDfltDevUserId );
		}
	}

	void CFSecSecUserBuff::setOptionalDfltDevUserIdNull() {
		for( int i = 0; i < 16; i ++ ) {
			optionalDfltDevUserId[i] = 0;
		}
	}

	void CFSecSecUserBuff::setOptionalDfltDevUserIdValue( const uuid_ptr_t value ) {
		uuid_copy( optionalDfltDevUserId, value );
	}

	void CFSecSecUserBuff::generateOptionalDfltDevUserId() {
		uuid_generate_random( optionalDfltDevUserId );
	}

	const bool CFSecSecUserBuff::isOptionalDfltDevNameNull() const {
		return( optionalDfltDevName == NULL );
	}

	const std::string& CFSecSecUserBuff::getOptionalDfltDevNameValue() const {
		static const std::string S_ProcName( "getOptionalDfltDevNameValue" );
		if( optionalDfltDevName == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( *optionalDfltDevName );
	}

	const std::string* CFSecSecUserBuff::getOptionalDfltDevNameReference() const {
		return( optionalDfltDevName );
	}

	void CFSecSecUserBuff::setOptionalDfltDevNameNull() {
		if( optionalDfltDevName != NULL ) {
			delete optionalDfltDevName;
			optionalDfltDevName = NULL;
		}
	}

	void CFSecSecUserBuff::setOptionalDfltDevNameValue( const std::string& value ) {
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

	const std::string& CFSecSecUserBuff::getRequiredPasswordHash() const {
		return( *requiredPasswordHash );
	}

	const std::string* CFSecSecUserBuff::getRequiredPasswordHashReference() const {
		return( requiredPasswordHash );
	}

	void CFSecSecUserBuff::setRequiredPasswordHash( const std::string& value ) {
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

	const bool CFSecSecUserBuff::isOptionalPasswordResetUuidNull() const {
		for( int i = 0; i < 16; i ++ ) {
			if( optionalPasswordResetUuid[ i ] != 0 ) {
				return( false );
			}
		}
		return( true );
	}

	const uuid_ptr_t CFSecSecUserBuff::getOptionalPasswordResetUuidValue() const {
		static const std::string S_ProcName( "getOptionalPasswordResetUuidValue" );
		if( isOptionalPasswordResetUuidNull() ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( optionalPasswordResetUuid );
	}

	const uuid_ptr_t CFSecSecUserBuff::getOptionalPasswordResetUuidReference() const {
		if( isOptionalPasswordResetUuidNull() ) {
			return( NULL );
		}
		else {
			return( optionalPasswordResetUuid );
		}
	}

	void CFSecSecUserBuff::setOptionalPasswordResetUuidNull() {
		for( int i = 0; i < 16; i ++ ) {
			optionalPasswordResetUuid[i] = 0;
		}
	}

	void CFSecSecUserBuff::setOptionalPasswordResetUuidValue( const uuid_ptr_t value ) {
		uuid_copy( optionalPasswordResetUuid, value );
	}

	void CFSecSecUserBuff::generateOptionalPasswordResetUuid() {
		uuid_generate_random( optionalPasswordResetUuid );
	}

	int32_t CFSecSecUserBuff::getRequiredRevision() const {
		return( requiredRevision );
	}

	void CFSecSecUserBuff::setRequiredRevision( int32_t value ) {
		requiredRevision = value;
	}

	size_t CFSecSecUserBuff::hashCode() const {
		size_t hashCode = 0L;
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

	CFSecSecUserBuff CFSecSecUserBuff::operator =( cfsec::CFSecSecUserBuff& src ) {
		setRequiredSecUserId( src.getRequiredSecUserId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
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

	CFSecSecUserBuff CFSecSecUserBuff::operator =( cfsec::CFSecSecUserHBuff& src ) {
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

	bool CFSecSecUserBuff::operator <( const CFSecSecUserByULoginIdxKey& rhs ) {
		if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserBuff::operator <( const CFSecSecUserByEMConfIdxKey& rhs ) {
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

	bool CFSecSecUserBuff::operator <( const CFSecSecUserByPwdResetIdxKey& rhs ) {
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

	bool CFSecSecUserBuff::operator <( const CFSecSecUserByDefDevIdxKey& rhs ) {
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

	bool CFSecSecUserBuff::operator <( const CFSecSecUserPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserBuff::operator <( const CFSecSecUserHPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserBuff::operator <( const CFSecSecUserHBuff& rhs ) {
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

	bool CFSecSecUserBuff::operator <( const CFSecSecUserBuff& rhs ) {
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

	bool CFSecSecUserBuff::operator <=( const CFSecSecUserByULoginIdxKey& rhs ) {
		if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecUserBuff::operator <=( const CFSecSecUserByEMConfIdxKey& rhs ) {
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

	bool CFSecSecUserBuff::operator <=( const CFSecSecUserByPwdResetIdxKey& rhs ) {
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

	bool CFSecSecUserBuff::operator <=( const CFSecSecUserByDefDevIdxKey& rhs ) {
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

	bool CFSecSecUserBuff::operator <=( const CFSecSecUserPKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecUserBuff::operator <=( const CFSecSecUserHPKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecUserBuff::operator <=( const CFSecSecUserHBuff& rhs ) {
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

	bool CFSecSecUserBuff::operator <=( const CFSecSecUserBuff& rhs ) {
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

	bool CFSecSecUserBuff::operator ==( const CFSecSecUserByULoginIdxKey& rhs ) {
		if( getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecUserBuff::operator ==( const CFSecSecUserByEMConfIdxKey& rhs ) {
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

	bool CFSecSecUserBuff::operator ==( const CFSecSecUserByPwdResetIdxKey& rhs ) {
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

	bool CFSecSecUserBuff::operator ==( const CFSecSecUserByDefDevIdxKey& rhs ) {
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

	bool CFSecSecUserBuff::operator ==( const CFSecSecUserPKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecUserBuff::operator ==( const CFSecSecUserHPKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecUserBuff::operator ==( const CFSecSecUserHBuff& rhs ) {
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

	bool CFSecSecUserBuff::operator ==( const CFSecSecUserBuff& rhs ) {
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

	bool CFSecSecUserBuff::operator !=( const CFSecSecUserByULoginIdxKey& rhs ) {
		if( getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserBuff::operator !=( const CFSecSecUserByEMConfIdxKey& rhs ) {
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

	bool CFSecSecUserBuff::operator !=( const CFSecSecUserByPwdResetIdxKey& rhs ) {
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

	bool CFSecSecUserBuff::operator !=( const CFSecSecUserByDefDevIdxKey& rhs ) {
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

	bool CFSecSecUserBuff::operator !=( const CFSecSecUserPKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserBuff::operator !=( const CFSecSecUserHPKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserBuff::operator !=( const CFSecSecUserHBuff& rhs ) {
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

	bool CFSecSecUserBuff::operator !=( const CFSecSecUserBuff& rhs ) {
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

	bool CFSecSecUserBuff::operator >=( const CFSecSecUserByULoginIdxKey& rhs ) {
		if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecUserBuff::operator >=( const CFSecSecUserByEMConfIdxKey& rhs ) {
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

	bool CFSecSecUserBuff::operator >=( const CFSecSecUserByPwdResetIdxKey& rhs ) {
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

	bool CFSecSecUserBuff::operator >=( const CFSecSecUserByDefDevIdxKey& rhs ) {
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

	bool CFSecSecUserBuff::operator >=( const CFSecSecUserPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecUserBuff::operator >=( const CFSecSecUserHPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecUserBuff::operator >=( const CFSecSecUserHBuff& rhs ) {
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

	bool CFSecSecUserBuff::operator >=( const CFSecSecUserBuff& rhs ) {
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

	bool CFSecSecUserBuff::operator >( const CFSecSecUserByULoginIdxKey& rhs ) {
		if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserBuff::operator >( const CFSecSecUserByEMConfIdxKey& rhs ) {
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

	bool CFSecSecUserBuff::operator >( const CFSecSecUserByPwdResetIdxKey& rhs ) {
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

	bool CFSecSecUserBuff::operator >( const CFSecSecUserByDefDevIdxKey& rhs ) {
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

	bool CFSecSecUserBuff::operator >( const CFSecSecUserPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserBuff::operator >( const CFSecSecUserHPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserBuff::operator >( const CFSecSecUserHBuff& rhs ) {
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

	bool CFSecSecUserBuff::operator >( const CFSecSecUserBuff& rhs ) {
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

	std::string CFSecSecUserBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecUserBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_SecUserId( "SecUserId" );
		static const std::string S_LoginId( "LoginId" );
		static const std::string S_EMailAddress( "EMailAddress" );
		static const std::string S_EMailConfirmUuid( "EMailConfirmUuid" );
		static const std::string S_DfltDevUserId( "DfltDevUserId" );
		static const std::string S_DfltDevName( "DfltDevName" );
		static const std::string S_PasswordHash( "PasswordHash" );
		static const std::string S_PasswordResetUuid( "PasswordResetUuid" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, getRequiredSecUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_CreatedBy, getCreatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_UpdatedBy, getUpdatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, getUpdatedAt() ) );
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

	bool operator <(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs ) {
		if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs ) {
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
		return( true );
	}

	bool operator <(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs ) {
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
		return( true );
	}

	bool operator <(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs ) {
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
		return( true );
	}

	bool operator <(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
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

	bool operator <(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
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

	bool operator <=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs ) {
		if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs ) {
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

	bool operator <=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs ) {
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

	bool operator <=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs ) {
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

	bool operator <=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
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

	bool operator <=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
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

	bool operator ==(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs ) {
		if( lhs.getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs ) {
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

	bool operator ==(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs ) {
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

	bool operator ==(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs ) {
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

	bool operator ==(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserPKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
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

	bool operator ==(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
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

	bool operator !=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs ) {
		if( lhs.getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs ) {
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

	bool operator !=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs ) {
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

	bool operator !=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs ) {
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

	bool operator !=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserPKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
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

	bool operator !=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
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

	bool operator >=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs ) {
		if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs ) {
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

	bool operator >=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs ) {
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

	bool operator >=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs ) {
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

	bool operator >=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserPKey& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
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

	bool operator >=(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
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

	bool operator >(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs ) {
		if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs ) {
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

	bool operator >(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs ) {
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

	bool operator >(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserByDefDevIdxKey& rhs ) {
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

	bool operator >(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
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

	bool operator >(const  cfsec::CFSecSecUserBuff& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
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

