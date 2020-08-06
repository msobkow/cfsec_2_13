// Description: C++18 implementation for a SecApp buffer object.

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

#include <cfsec/ICFSecPublic.hpp>

#include <cfsec/CFSecSecAppByClusterIdxKey.hpp>
#include <cfsec/CFSecSecAppByUJEEMountIdxKey.hpp>
#include <cfsec/CFSecSchema.hpp>

namespace cfsec {

	const std::string CFSecSecAppBuff::S_VALUE( "value" );
	const std::string CFSecSecAppBuff::S_VALUE_LENGTH( "value.length()" );

	const std::string CFSecSecAppBuff::GENDEFNAME( "SecApp" );
	const classcode_t CFSecSecAppBuff::CLASS_CODE = 0xa009L;
	const std::string CFSecSecAppBuff::CLASS_NAME( "CFSecSecAppBuff" );
		const std::string CFSecSecAppBuff::COLNAME_CLUSTERID( "ClusterId" );
		const std::string CFSecSecAppBuff::COLNAME_SECAPPID( "SecAppId" );
		const std::string CFSecSecAppBuff::COLNAME_JEEMOUNTNAME( "JEEMountName" );
	const char* CFSecSecAppBuff::S_INIT_CREATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const char* CFSecSecAppBuff::S_INIT_UPDATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const int64_t CFSecSecAppBuff::CLUSTERID_INIT_VALUE = 0LL;
	const int CFSecSecAppBuff::SECAPPID_INIT_VALUE = 0L;
	const std::string CFSecSecAppBuff::JEEMOUNTNAME_INIT_VALUE( "" );
	const int64_t CFSecSecAppBuff::CLUSTERID_MIN_VALUE = 0LL;
	const int CFSecSecAppBuff::SECAPPID_MIN_VALUE = 0L;
	const std::string::size_type CFSecSecAppBuff::JEEMOUNTNAME_MAX_LEN = 192;

	CFSecSecAppBuff::CFSecSecAppBuff()
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
		requiredClusterId = cfsec::CFSecSecAppBuff::CLUSTERID_INIT_VALUE;
		requiredSecAppId = cfsec::CFSecSecAppBuff::SECAPPID_INIT_VALUE;
		requiredJEEMountName = new std::string( cfsec::CFSecSecAppBuff::JEEMOUNTNAME_INIT_VALUE );
	}

	CFSecSecAppBuff::CFSecSecAppBuff( const CFSecSecAppBuff& src )
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
		requiredClusterId = cfsec::CFSecSecAppBuff::CLUSTERID_INIT_VALUE;
		requiredSecAppId = cfsec::CFSecSecAppBuff::SECAPPID_INIT_VALUE;
		requiredJEEMountName = new std::string( cfsec::CFSecSecAppBuff::JEEMOUNTNAME_INIT_VALUE );
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecAppId( src.getRequiredSecAppId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredJEEMountName( src.getRequiredJEEMountName() );
	}

	CFSecSecAppBuff::~CFSecSecAppBuff() {
		if( requiredJEEMountName != NULL ) {
			delete requiredJEEMountName;
			requiredJEEMountName = NULL;
		}
		for( int i = 0; i < 16; i++ ) {
			createdByUserId[i] = 0;
		}
		for( int i = 0; i < 16; i++ ) {
			updatedByUserId[i] = 0;
		}
	}

	cflib::ICFLibCloneableObj* CFSecSecAppBuff::clone() {
		CFSecSecAppBuff* copy = new CFSecSecAppBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const std::string& CFSecSecAppBuff::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecSecAppBuff::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecSecAppBuff::implementsClassCode( const classcode_t argClassCode ) {
		if( argClassCode == CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	const uuid_ptr_t CFSecSecAppBuff::getCreatedByUserId() const {
		return( createdByUserId );
	}

	void CFSecSecAppBuff::setCreatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( createdByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecSecAppBuff::getCreatedAt() const {
		return( createdAt );
	}

	void CFSecSecAppBuff::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		createdAt = value;
	}

	const uuid_ptr_t CFSecSecAppBuff::getUpdatedByUserId() const {
		return( updatedByUserId );
	}

	void CFSecSecAppBuff::setUpdatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( updatedByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecSecAppBuff::getUpdatedAt() const {
		return( updatedAt );
	}

	void CFSecSecAppBuff::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		updatedAt = value;
	}
	const int64_t CFSecSecAppBuff::getRequiredClusterId() const {
		return( requiredClusterId );
	}

	const int64_t* CFSecSecAppBuff::getRequiredClusterIdReference() const {
		return( &requiredClusterId );
	}

	void CFSecSecAppBuff::setRequiredClusterId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredClusterId" );
		if( value < cfsec::CFSecSecAppBuff::CLUSTERID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecSecAppBuff::CLUSTERID_MIN_VALUE );
		}
		requiredClusterId = value;
	}

	const int32_t CFSecSecAppBuff::getRequiredSecAppId() const {
		return( requiredSecAppId );
	}

	const int32_t* CFSecSecAppBuff::getRequiredSecAppIdReference() const {
		return( &requiredSecAppId );
	}

	void CFSecSecAppBuff::setRequiredSecAppId( const int32_t value ) {
		static const std::string S_ProcName( "setRequiredSecAppId" );
		if( value < cfsec::CFSecSecAppBuff::SECAPPID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecSecAppBuff::SECAPPID_MIN_VALUE );
		}
		requiredSecAppId = value;
	}

	const std::string& CFSecSecAppBuff::getRequiredJEEMountName() const {
		return( *requiredJEEMountName );
	}

	const std::string* CFSecSecAppBuff::getRequiredJEEMountNameReference() const {
		return( requiredJEEMountName );
	}

	void CFSecSecAppBuff::setRequiredJEEMountName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredJEEMountName" );
		if( value.length() > CFSecSecAppBuff::JEEMOUNTNAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecSecAppBuff::JEEMOUNTNAME_MAX_LEN );
		}
		if( requiredJEEMountName != NULL ) {
			delete requiredJEEMountName;
			requiredJEEMountName = NULL;
		}
		requiredJEEMountName = new std::string( value );
	}

	int32_t CFSecSecAppBuff::getRequiredRevision() const {
		return( requiredRevision );
	}

	void CFSecSecAppBuff::setRequiredRevision( int32_t value ) {
		requiredRevision = value;
	}

	size_t CFSecSecAppBuff::hashCode() const {
		size_t hashCode = 0L;
		hashCode = hashCode + (int)( getRequiredClusterId() );
		hashCode = hashCode + getRequiredSecAppId();
		hashCode = hashCode + cflib::CFLib::hash( getRequiredJEEMountName() );
		return( hashCode );
	}

	CFSecSecAppBuff CFSecSecAppBuff::operator =( cfsec::CFSecSecAppBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecAppId( src.getRequiredSecAppId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredJEEMountName( src.getRequiredJEEMountName() );
		return( *this );
	}

	CFSecSecAppBuff CFSecSecAppBuff::operator =( cfsec::CFSecSecAppHBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecAppId( src.getRequiredSecAppId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredJEEMountName( src.getRequiredJEEMountName() );
		return( *this );
	}

	bool CFSecSecAppBuff::operator <( const CFSecSecAppByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppBuff::operator <( const CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppBuff::operator <( const CFSecSecAppPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppBuff::operator <( const CFSecSecAppHPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppBuff::operator <( const CFSecSecAppHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppBuff::operator <( const CFSecSecAppBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppBuff::operator <=( const CFSecSecAppByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppBuff::operator <=( const CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppBuff::operator <=( const CFSecSecAppPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppBuff::operator <=( const CFSecSecAppHPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppBuff::operator <=( const CFSecSecAppHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppBuff::operator <=( const CFSecSecAppBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppBuff::operator ==( const CFSecSecAppByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecAppBuff::operator ==( const CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecAppBuff::operator ==( const CFSecSecAppPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecAppBuff::operator ==( const CFSecSecAppHPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecAppBuff::operator ==( const CFSecSecAppHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		if( getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecAppBuff::operator ==( const CFSecSecAppBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		if( getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecAppBuff::operator !=( const CFSecSecAppByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppBuff::operator !=( const CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppBuff::operator !=( const CFSecSecAppPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppBuff::operator !=( const CFSecSecAppHPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppBuff::operator !=( const CFSecSecAppHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppBuff::operator !=( const CFSecSecAppBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppBuff::operator >=( const CFSecSecAppByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppBuff::operator >=( const CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppBuff::operator >=( const CFSecSecAppPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppBuff::operator >=( const CFSecSecAppHPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppBuff::operator >=( const CFSecSecAppHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppBuff::operator >=( const CFSecSecAppBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppBuff::operator >( const CFSecSecAppByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppBuff::operator >( const CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppBuff::operator >( const CFSecSecAppPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppBuff::operator >( const CFSecSecAppHPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppBuff::operator >( const CFSecSecAppHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppBuff::operator >( const CFSecSecAppBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	std::string CFSecSecAppBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecAppBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecAppId( "SecAppId" );
		static const std::string S_JEEMountName( "JEEMountName" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecAppId, getRequiredSecAppId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_CreatedBy, getCreatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_UpdatedBy, getUpdatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_JEEMountName, getRequiredJEEMountName() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		if( lhs.getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		if( lhs.getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecAppBuff& lhs, const cfsec::CFSecSecAppBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}
}

