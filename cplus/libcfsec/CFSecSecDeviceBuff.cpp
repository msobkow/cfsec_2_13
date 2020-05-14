// Description: C++18 implementation for a SecDevice buffer object.

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

#include <cfsec/CFSecSecDeviceByNameIdxKey.hpp>
#include <cfsec/CFSecSecDeviceByUserIdxKey.hpp>
#include <cfsec/CFSecSchema.hpp>

namespace cfsec {

	const std::string CFSecSecDeviceBuff::S_VALUE( "value" );
	const std::string CFSecSecDeviceBuff::S_VALUE_LENGTH( "value.length()" );

	const std::string CFSecSecDeviceBuff::GENDEFNAME( "SecDevice" );
	const classcode_t CFSecSecDeviceBuff::CLASS_CODE = 0xa00aL;
	const std::string CFSecSecDeviceBuff::CLASS_NAME( "CFSecSecDeviceBuff" );
		const std::string CFSecSecDeviceBuff::COLNAME_SECUSERID( "SecUserId" );
		const std::string CFSecSecDeviceBuff::COLNAME_DEVNAME( "DevName" );
		const std::string CFSecSecDeviceBuff::COLNAME_PUBKEY( "PubKey" );
	const char* CFSecSecDeviceBuff::S_INIT_CREATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const char* CFSecSecDeviceBuff::S_INIT_UPDATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const std::string CFSecSecDeviceBuff::DEVNAME_INIT_VALUE( "" );
	const std::string::size_type CFSecSecDeviceBuff::DEVNAME_MAX_LEN = 127;
	const std::string::size_type CFSecSecDeviceBuff::PUBKEY_MAX_LEN = 10000;

	CFSecSecDeviceBuff::CFSecSecDeviceBuff()
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
		requiredDevName = new std::string( cfsec::CFSecSecDeviceBuff::DEVNAME_INIT_VALUE );
		optionalPubKey = NULL;
	}

	CFSecSecDeviceBuff::CFSecSecDeviceBuff( const CFSecSecDeviceBuff& src )
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
		requiredDevName = new std::string( cfsec::CFSecSecDeviceBuff::DEVNAME_INIT_VALUE );
		optionalPubKey = NULL;
		setRequiredSecUserId( src.getRequiredSecUserId() );
		setRequiredDevName( src.getRequiredDevName() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		if( src.isOptionalPubKeyNull() ) {
			setOptionalPubKeyNull();
		}
		else {
			setOptionalPubKeyValue( src.getOptionalPubKeyValue() );
		}
	}

	CFSecSecDeviceBuff::~CFSecSecDeviceBuff() {
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
		if( requiredDevName != NULL ) {
			delete requiredDevName;
			requiredDevName = NULL;
		}
		if( optionalPubKey != NULL ) {
			delete optionalPubKey;
			optionalPubKey = NULL;
		}
		for( int i = 0; i < 16; i++ ) {
			createdByUserId[i] = 0;
		}
		for( int i = 0; i < 16; i++ ) {
			updatedByUserId[i] = 0;
		}
	}

	cflib::ICFLibCloneableObj* CFSecSecDeviceBuff::clone() {
		CFSecSecDeviceBuff* copy = new CFSecSecDeviceBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const std::string& CFSecSecDeviceBuff::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecSecDeviceBuff::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecSecDeviceBuff::implementsClassCode( const classcode_t argClassCode ) {
		if( argClassCode == CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	const uuid_ptr_t CFSecSecDeviceBuff::getCreatedByUserId() const {
		return( createdByUserId );
	}

	void CFSecSecDeviceBuff::setCreatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( createdByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecSecDeviceBuff::getCreatedAt() const {
		return( createdAt );
	}

	void CFSecSecDeviceBuff::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		createdAt = value;
	}

	const uuid_ptr_t CFSecSecDeviceBuff::getUpdatedByUserId() const {
		return( updatedByUserId );
	}

	void CFSecSecDeviceBuff::setUpdatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( updatedByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecSecDeviceBuff::getUpdatedAt() const {
		return( updatedAt );
	}

	void CFSecSecDeviceBuff::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		updatedAt = value;
	}
	const uuid_ptr_t CFSecSecDeviceBuff::getRequiredSecUserId() const {
		return( requiredSecUserId );
	}

	const uuid_ptr_t CFSecSecDeviceBuff::getRequiredSecUserIdReference() const {
		return( requiredSecUserId );
	}

	void CFSecSecDeviceBuff::setRequiredSecUserId( const uuid_ptr_t value ) {
		uuid_copy( requiredSecUserId, value );
	}

	void CFSecSecDeviceBuff::generateRequiredSecUserId() {
		uuid_generate_random( requiredSecUserId );
	}

	const std::string& CFSecSecDeviceBuff::getRequiredDevName() const {
		return( *requiredDevName );
	}

	const std::string* CFSecSecDeviceBuff::getRequiredDevNameReference() const {
		return( requiredDevName );
	}

	void CFSecSecDeviceBuff::setRequiredDevName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredDevName" );
		if( value.length() > CFSecSecDeviceBuff::DEVNAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecSecDeviceBuff::DEVNAME_MAX_LEN );
		}
		if( requiredDevName != NULL ) {
			delete requiredDevName;
			requiredDevName = NULL;
		}
		requiredDevName = new std::string( value );
	}

	const bool CFSecSecDeviceBuff::isOptionalPubKeyNull() const {
		return( optionalPubKey == NULL );
	}

	const std::string& CFSecSecDeviceBuff::getOptionalPubKeyValue() const {
		static const std::string S_ProcName( "getOptionalPubKeyValue" );
		if( optionalPubKey == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( *optionalPubKey );
	}

	const std::string* CFSecSecDeviceBuff::getOptionalPubKeyReference() const {
		return( optionalPubKey );
	}

	void CFSecSecDeviceBuff::setOptionalPubKeyNull() {
		if( optionalPubKey != NULL ) {
			delete optionalPubKey;
			optionalPubKey = NULL;
		}
	}

	void CFSecSecDeviceBuff::setOptionalPubKeyValue( const std::string& value ) {
		static const std::string S_ProcName( "setOptionalPubKeyValue" );
		if( value.length() > CFSecSecDeviceBuff::PUBKEY_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecSecDeviceBuff::PUBKEY_MAX_LEN );
		}
		if( optionalPubKey != NULL ) {
			delete optionalPubKey;
			optionalPubKey = NULL;
		}
		optionalPubKey = new std::string( value );
	}

	int32_t CFSecSecDeviceBuff::getRequiredRevision() const {
		return( requiredRevision );
	}

	void CFSecSecDeviceBuff::setRequiredRevision( int32_t value ) {
		requiredRevision = value;
	}

	size_t CFSecSecDeviceBuff::hashCode() const {
		size_t hashCode = 0L;
		hashCode = hashCode + cflib::CFLib::hash( getRequiredSecUserId() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredDevName() );
		if( ! isOptionalPubKeyNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalPubKeyValue() );
		}
		return( hashCode );
	}

	CFSecSecDeviceBuff CFSecSecDeviceBuff::operator =( cfsec::CFSecSecDeviceBuff& src ) {
		setRequiredSecUserId( src.getRequiredSecUserId() );
		setRequiredDevName( src.getRequiredDevName() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		if( src.isOptionalPubKeyNull() ) {
			setOptionalPubKeyNull();
		}
		else {
			setOptionalPubKeyValue( src.getOptionalPubKeyValue() );
		}
		return( *this );
	}

	CFSecSecDeviceBuff CFSecSecDeviceBuff::operator =( cfsec::CFSecSecDeviceHBuff& src ) {
		setRequiredSecUserId( src.getRequiredSecUserId() );
		setRequiredDevName( src.getRequiredDevName() );
		setRequiredRevision( src.getRequiredRevision() );
		if( src.isOptionalPubKeyNull() ) {
			setOptionalPubKeyNull();
		}
		else {
			setOptionalPubKeyValue( src.getOptionalPubKeyValue() );
		}
		return( *this );
	}

	bool CFSecSecDeviceBuff::operator <( const CFSecSecDeviceByNameIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecDeviceBuff::operator <( const CFSecSecDeviceByUserIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecDeviceBuff::operator <( const CFSecSecDevicePKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecDeviceBuff::operator <( const CFSecSecDeviceHPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecDeviceBuff::operator <( const CFSecSecDeviceHBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		if( ! isOptionalPubKeyNull() ) {
			if( rhs.isOptionalPubKeyNull() ) {
				return( false );
			}
			if( getOptionalPubKeyValue() > rhs.getOptionalPubKeyValue() ) {
				return( false );
			}
			else if( getOptionalPubKeyValue() < rhs.getOptionalPubKeyValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPubKeyNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecDeviceBuff::operator <( const CFSecSecDeviceBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		if( ! isOptionalPubKeyNull() ) {
			if( rhs.isOptionalPubKeyNull() ) {
				return( false );
			}
			if( getOptionalPubKeyValue() > rhs.getOptionalPubKeyValue() ) {
				return( false );
			}
			else if( getOptionalPubKeyValue() < rhs.getOptionalPubKeyValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPubKeyNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecDeviceBuff::operator <=( const CFSecSecDeviceByNameIdxKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecDeviceBuff::operator <=( const CFSecSecDeviceByUserIdxKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecDeviceBuff::operator <=( const CFSecSecDevicePKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecDeviceBuff::operator <=( const CFSecSecDeviceHPKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecDeviceBuff::operator <=( const CFSecSecDeviceHBuff& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		if( ! isOptionalPubKeyNull() ) {
			if( rhs.isOptionalPubKeyNull() ) {
				return( false );
			}
			if( getOptionalPubKeyValue() > rhs.getOptionalPubKeyValue() ) {
				return( false );
			}
			else if( getOptionalPubKeyValue() < rhs.getOptionalPubKeyValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPubKeyNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecDeviceBuff::operator <=( const CFSecSecDeviceBuff& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		if( ! isOptionalPubKeyNull() ) {
			if( rhs.isOptionalPubKeyNull() ) {
				return( false );
			}
			if( getOptionalPubKeyValue() > rhs.getOptionalPubKeyValue() ) {
				return( false );
			}
			else if( getOptionalPubKeyValue() < rhs.getOptionalPubKeyValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPubKeyNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecDeviceBuff::operator ==( const CFSecSecDeviceByNameIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecDeviceBuff::operator ==( const CFSecSecDeviceByUserIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecDeviceBuff::operator ==( const CFSecSecDevicePKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecDeviceBuff::operator ==( const CFSecSecDeviceHPKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecDeviceBuff::operator ==( const CFSecSecDeviceHBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( false );
		}
		if( ! isOptionalPubKeyNull() ) {
			if( ! rhs.isOptionalPubKeyNull() ) {
				if( getOptionalPubKeyValue() != rhs.getOptionalPubKeyValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalPubKeyNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecDeviceBuff::operator ==( const CFSecSecDeviceBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( false );
		}
		if( ! isOptionalPubKeyNull() ) {
			if( ! rhs.isOptionalPubKeyNull() ) {
				if( getOptionalPubKeyValue() != rhs.getOptionalPubKeyValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalPubKeyNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecDeviceBuff::operator !=( const CFSecSecDeviceByNameIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecDeviceBuff::operator !=( const CFSecSecDeviceByUserIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecDeviceBuff::operator !=( const CFSecSecDevicePKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecDeviceBuff::operator !=( const CFSecSecDeviceHPKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecDeviceBuff::operator !=( const CFSecSecDeviceHBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( true );
		}
		if( ! isOptionalPubKeyNull() ) {
			if( rhs.isOptionalPubKeyNull() ) {
				return( true );
			}
			if( getOptionalPubKeyValue() != rhs.getOptionalPubKeyValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPubKeyNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecDeviceBuff::operator !=( const CFSecSecDeviceBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( true );
		}
		if( ! isOptionalPubKeyNull() ) {
			if( rhs.isOptionalPubKeyNull() ) {
				return( true );
			}
			if( getOptionalPubKeyValue() != rhs.getOptionalPubKeyValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPubKeyNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecDeviceBuff::operator >=( const CFSecSecDeviceByNameIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecDeviceBuff::operator >=( const CFSecSecDeviceByUserIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecDeviceBuff::operator >=( const CFSecSecDevicePKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecDeviceBuff::operator >=( const CFSecSecDeviceHPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecDeviceBuff::operator >=( const CFSecSecDeviceHBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		if( ! isOptionalPubKeyNull() ) {
			if( rhs.isOptionalPubKeyNull() ) {
				return( true );
			}
			if( getOptionalPubKeyValue() < rhs.getOptionalPubKeyValue() ) {
				return( false );
			}
			else if( getOptionalPubKeyValue() > rhs.getOptionalPubKeyValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPubKeyNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecDeviceBuff::operator >=( const CFSecSecDeviceBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		if( ! isOptionalPubKeyNull() ) {
			if( rhs.isOptionalPubKeyNull() ) {
				return( true );
			}
			if( getOptionalPubKeyValue() < rhs.getOptionalPubKeyValue() ) {
				return( false );
			}
			else if( getOptionalPubKeyValue() > rhs.getOptionalPubKeyValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPubKeyNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecDeviceBuff::operator >( const CFSecSecDeviceByNameIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecDeviceBuff::operator >( const CFSecSecDeviceByUserIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecDeviceBuff::operator >( const CFSecSecDevicePKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecDeviceBuff::operator >( const CFSecSecDeviceHPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecDeviceBuff::operator >( const CFSecSecDeviceHBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		if( ! isOptionalPubKeyNull() ) {
			if( rhs.isOptionalPubKeyNull() ) {
				return( true );
			}
			if( getOptionalPubKeyValue() < rhs.getOptionalPubKeyValue() ) {
				return( false );
			}
			else if( getOptionalPubKeyValue() > rhs.getOptionalPubKeyValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFSecSecDeviceBuff::operator >( const CFSecSecDeviceBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		if( ! isOptionalPubKeyNull() ) {
			if( rhs.isOptionalPubKeyNull() ) {
				return( true );
			}
			if( getOptionalPubKeyValue() < rhs.getOptionalPubKeyValue() ) {
				return( false );
			}
			else if( getOptionalPubKeyValue() > rhs.getOptionalPubKeyValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	std::string CFSecSecDeviceBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecDeviceBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_SecUserId( "SecUserId" );
		static const std::string S_DevName( "DevName" );
		static const std::string S_PubKey( "PubKey" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, getRequiredSecUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_DevName, getRequiredDevName() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_CreatedBy, getCreatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_UpdatedBy, getUpdatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, getRequiredRevision() ) );
		if( ! isOptionalPubKeyNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_PubKey, getOptionalPubKeyValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByNameIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByUserIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDevicePKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		if( ! lhs.isOptionalPubKeyNull() ) {
			if( rhs.isOptionalPubKeyNull() ) {
				return( false );
			}
			if( lhs.getOptionalPubKeyValue() > rhs.getOptionalPubKeyValue() ) {
				return( false );
			}
			else if( lhs.getOptionalPubKeyValue() < rhs.getOptionalPubKeyValue() ) {
				return( true );
			}
		}
		else {
			if( rhs.isOptionalPubKeyNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		if( ! lhs.isOptionalPubKeyNull() ) {
			if( rhs.isOptionalPubKeyNull() ) {
				return( false );
			}
			if( lhs.getOptionalPubKeyValue() > rhs.getOptionalPubKeyValue() ) {
				return( false );
			}
			else if( lhs.getOptionalPubKeyValue() < rhs.getOptionalPubKeyValue() ) {
				return( true );
			}
		}
		else {
			if( rhs.isOptionalPubKeyNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByNameIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByUserIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDevicePKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		if( ! lhs.isOptionalPubKeyNull() ) {
			if( rhs.isOptionalPubKeyNull() ) {
				return( false );
			}
			if( lhs.getOptionalPubKeyValue() > rhs.getOptionalPubKeyValue() ) {
				return( false );
			}
			else if( lhs.getOptionalPubKeyValue() < rhs.getOptionalPubKeyValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPubKeyNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		if( ! lhs.isOptionalPubKeyNull() ) {
			if( rhs.isOptionalPubKeyNull() ) {
				return( false );
			}
			if( lhs.getOptionalPubKeyValue() > rhs.getOptionalPubKeyValue() ) {
				return( false );
			}
			else if( lhs.getOptionalPubKeyValue() < rhs.getOptionalPubKeyValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPubKeyNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByNameIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( lhs.getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByUserIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDevicePKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( lhs.getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHPKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( lhs.getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( lhs.getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( false );
		}
		if( ! lhs.isOptionalPubKeyNull() ) {
			if( ! rhs.isOptionalPubKeyNull() ) {
				if( lhs.getOptionalPubKeyValue() != rhs.getOptionalPubKeyValue() ) {
					return( false );
				}
			}
		}
		else {
			if( ! rhs.isOptionalPubKeyNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( lhs.getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( false );
		}
		if( ! lhs.isOptionalPubKeyNull() ) {
			if( ! rhs.isOptionalPubKeyNull() ) {
				if( lhs.getOptionalPubKeyValue() != rhs.getOptionalPubKeyValue() ) {
					return( false );
				}
			}
		}
		else {
			if( ! rhs.isOptionalPubKeyNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByNameIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByUserIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDevicePKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHPKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( true );
		}
		if( ! lhs.isOptionalPubKeyNull() ) {
			if( rhs.isOptionalPubKeyNull() ) {
				return( true );
			}
			if( lhs.getOptionalPubKeyValue() != rhs.getOptionalPubKeyValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPubKeyNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( true );
		}
		if( ! lhs.isOptionalPubKeyNull() ) {
			if( rhs.isOptionalPubKeyNull() ) {
				return( true );
			}
			if( lhs.getOptionalPubKeyValue() != rhs.getOptionalPubKeyValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPubKeyNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByNameIdxKey& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByUserIdxKey& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDevicePKey& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHPKey& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHBuff& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		if( ! lhs.isOptionalPubKeyNull() ) {
			if( rhs.isOptionalPubKeyNull() ) {
				return( true );
			}
			if( lhs.getOptionalPubKeyValue() < rhs.getOptionalPubKeyValue() ) {
				return( false );
			}
			else if( lhs.getOptionalPubKeyValue() > rhs.getOptionalPubKeyValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPubKeyNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceBuff& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		if( ! lhs.isOptionalPubKeyNull() ) {
			if( rhs.isOptionalPubKeyNull() ) {
				return( true );
			}
			if( lhs.getOptionalPubKeyValue() < rhs.getOptionalPubKeyValue() ) {
				return( false );
			}
			else if( lhs.getOptionalPubKeyValue() > rhs.getOptionalPubKeyValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPubKeyNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByNameIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceByUserIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDevicePKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceHBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		if( ! lhs.isOptionalPubKeyNull() ) {
			if( rhs.isOptionalPubKeyNull() ) {
				return( true );
			}
			if( lhs.getOptionalPubKeyValue() < rhs.getOptionalPubKeyValue() ) {
				return( false );
			}
			else if( lhs.getOptionalPubKeyValue() > rhs.getOptionalPubKeyValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPubKeyNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecDeviceBuff& lhs, const cfsec::CFSecSecDeviceBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		if( ! lhs.isOptionalPubKeyNull() ) {
			if( rhs.isOptionalPubKeyNull() ) {
				return( true );
			}
			if( lhs.getOptionalPubKeyValue() < rhs.getOptionalPubKeyValue() ) {
				return( false );
			}
			else if( lhs.getOptionalPubKeyValue() > rhs.getOptionalPubKeyValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPubKeyNull() ) {
				return( false );
			}
		}
		return( false );
	}
}

