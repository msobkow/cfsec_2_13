// Description: C++18 implementation for a Tenant buffer object.

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

#include <cfsec/CFSecTenantByClusterIdxKey.hpp>
#include <cfsec/CFSecTenantByUNameIdxKey.hpp>
#include <cfsec/CFSecSchema.hpp>

namespace cfsec {

	const std::string CFSecTenantBuff::S_VALUE( "value" );
	const std::string CFSecTenantBuff::S_VALUE_LENGTH( "value.length()" );

	const std::string CFSecTenantBuff::GENDEFNAME( "Tenant" );
	const classcode_t CFSecTenantBuff::CLASS_CODE = 0xa015L;
	const std::string CFSecTenantBuff::CLASS_NAME( "CFSecTenantBuff" );
		const std::string CFSecTenantBuff::COLNAME_CLUSTERID( "ClusterId" );
		const std::string CFSecTenantBuff::COLNAME_ID( "Id" );
		const std::string CFSecTenantBuff::COLNAME_TENANTNAME( "TenantName" );
	const char* CFSecTenantBuff::S_INIT_CREATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const char* CFSecTenantBuff::S_INIT_UPDATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const int64_t CFSecTenantBuff::CLUSTERID_INIT_VALUE = 0LL;
	const int64_t CFSecTenantBuff::ID_INIT_VALUE = 0LL;
	const std::string CFSecTenantBuff::TENANTNAME_INIT_VALUE( "" );
	const int64_t CFSecTenantBuff::CLUSTERID_MIN_VALUE = 0LL;
	const int64_t CFSecTenantBuff::ID_MIN_VALUE = 0LL;
	const std::string::size_type CFSecTenantBuff::TENANTNAME_MAX_LEN = 192;

	CFSecTenantBuff::CFSecTenantBuff()
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
		requiredClusterId = cfsec::CFSecTenantBuff::CLUSTERID_INIT_VALUE;
		requiredId = cfsec::CFSecTenantBuff::ID_INIT_VALUE;
		requiredTenantName = new std::string( cfsec::CFSecTenantBuff::TENANTNAME_INIT_VALUE );
	}

	CFSecTenantBuff::CFSecTenantBuff( const CFSecTenantBuff& src )
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
		requiredClusterId = cfsec::CFSecTenantBuff::CLUSTERID_INIT_VALUE;
		requiredId = cfsec::CFSecTenantBuff::ID_INIT_VALUE;
		requiredTenantName = new std::string( cfsec::CFSecTenantBuff::TENANTNAME_INIT_VALUE );
		setRequiredId( src.getRequiredId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredTenantName( src.getRequiredTenantName() );
	}

	CFSecTenantBuff::~CFSecTenantBuff() {
		if( requiredTenantName != NULL ) {
			delete requiredTenantName;
			requiredTenantName = NULL;
		}
		for( int i = 0; i < 16; i++ ) {
			createdByUserId[i] = 0;
		}
		for( int i = 0; i < 16; i++ ) {
			updatedByUserId[i] = 0;
		}
	}

	cflib::ICFLibCloneableObj* CFSecTenantBuff::clone() {
		CFSecTenantBuff* copy = new CFSecTenantBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const std::string& CFSecTenantBuff::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecTenantBuff::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecTenantBuff::implementsClassCode( const classcode_t argClassCode ) {
		if( argClassCode == CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	const uuid_ptr_t CFSecTenantBuff::getCreatedByUserId() const {
		return( createdByUserId );
	}

	void CFSecTenantBuff::setCreatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( createdByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecTenantBuff::getCreatedAt() const {
		return( createdAt );
	}

	void CFSecTenantBuff::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		createdAt = value;
	}

	const uuid_ptr_t CFSecTenantBuff::getUpdatedByUserId() const {
		return( updatedByUserId );
	}

	void CFSecTenantBuff::setUpdatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( updatedByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecTenantBuff::getUpdatedAt() const {
		return( updatedAt );
	}

	void CFSecTenantBuff::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		updatedAt = value;
	}
	const int64_t CFSecTenantBuff::getRequiredClusterId() const {
		return( requiredClusterId );
	}

	const int64_t* CFSecTenantBuff::getRequiredClusterIdReference() const {
		return( &requiredClusterId );
	}

	void CFSecTenantBuff::setRequiredClusterId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredClusterId" );
		if( value < cfsec::CFSecTenantBuff::CLUSTERID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecTenantBuff::CLUSTERID_MIN_VALUE );
		}
		requiredClusterId = value;
	}

	const int64_t CFSecTenantBuff::getRequiredId() const {
		return( requiredId );
	}

	const int64_t* CFSecTenantBuff::getRequiredIdReference() const {
		return( &requiredId );
	}

	void CFSecTenantBuff::setRequiredId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredId" );
		if( value < cfsec::CFSecTenantBuff::ID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecTenantBuff::ID_MIN_VALUE );
		}
		requiredId = value;
	}

	const std::string& CFSecTenantBuff::getRequiredTenantName() const {
		return( *requiredTenantName );
	}

	const std::string* CFSecTenantBuff::getRequiredTenantNameReference() const {
		return( requiredTenantName );
	}

	void CFSecTenantBuff::setRequiredTenantName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredTenantName" );
		if( value.length() > CFSecTenantBuff::TENANTNAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecTenantBuff::TENANTNAME_MAX_LEN );
		}
		if( requiredTenantName != NULL ) {
			delete requiredTenantName;
			requiredTenantName = NULL;
		}
		requiredTenantName = new std::string( value );
	}

	int32_t CFSecTenantBuff::getRequiredRevision() const {
		return( requiredRevision );
	}

	void CFSecTenantBuff::setRequiredRevision( int32_t value ) {
		requiredRevision = value;
	}

	size_t CFSecTenantBuff::hashCode() const {
		size_t hashCode = 0L;
		hashCode = hashCode + (int)( getRequiredClusterId() );
		hashCode = hashCode + (int)( getRequiredId() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredTenantName() );
		return( hashCode );
	}

	CFSecTenantBuff CFSecTenantBuff::operator =( cfsec::CFSecTenantBuff& src ) {
		setRequiredId( src.getRequiredId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredTenantName( src.getRequiredTenantName() );
		return( *this );
	}

	CFSecTenantBuff CFSecTenantBuff::operator =( cfsec::CFSecTenantHBuff& src ) {
		setRequiredId( src.getRequiredId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredTenantName( src.getRequiredTenantName() );
		return( *this );
	}

	bool CFSecTenantBuff::operator <( const CFSecTenantByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantBuff::operator <( const CFSecTenantByUNameIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantBuff::operator <( const CFSecTenantPKey& rhs ) {
		if( getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantBuff::operator <( const CFSecTenantHPKey& rhs ) {
		if( getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantBuff::operator <( const CFSecTenantHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantBuff::operator <( const CFSecTenantBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantBuff::operator <=( const CFSecTenantByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTenantBuff::operator <=( const CFSecTenantByUNameIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTenantBuff::operator <=( const CFSecTenantPKey& rhs ) {
		if( getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTenantBuff::operator <=( const CFSecTenantHPKey& rhs ) {
		if( getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTenantBuff::operator <=( const CFSecTenantHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTenantBuff::operator <=( const CFSecTenantBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTenantBuff::operator ==( const CFSecTenantByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTenantBuff::operator ==( const CFSecTenantByUNameIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTenantBuff::operator ==( const CFSecTenantPKey& rhs ) {
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTenantBuff::operator ==( const CFSecTenantHPKey& rhs ) {
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTenantBuff::operator ==( const CFSecTenantHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		if( getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTenantBuff::operator ==( const CFSecTenantBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		if( getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTenantBuff::operator !=( const CFSecTenantByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantBuff::operator !=( const CFSecTenantByUNameIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantBuff::operator !=( const CFSecTenantPKey& rhs ) {
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantBuff::operator !=( const CFSecTenantHPKey& rhs ) {
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantBuff::operator !=( const CFSecTenantHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		if( getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantBuff::operator !=( const CFSecTenantBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		if( getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantBuff::operator >=( const CFSecTenantByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTenantBuff::operator >=( const CFSecTenantByUNameIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTenantBuff::operator >=( const CFSecTenantPKey& rhs ) {
		if( getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTenantBuff::operator >=( const CFSecTenantHPKey& rhs ) {
		if( getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTenantBuff::operator >=( const CFSecTenantHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTenantBuff::operator >=( const CFSecTenantBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTenantBuff::operator >( const CFSecTenantByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantBuff::operator >( const CFSecTenantByUNameIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantBuff::operator >( const CFSecTenantPKey& rhs ) {
		if( getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantBuff::operator >( const CFSecTenantHPKey& rhs ) {
		if( getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantBuff::operator >( const CFSecTenantHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantBuff::operator >( const CFSecTenantBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	std::string CFSecTenantBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecTenantBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_Id( "Id" );
		static const std::string S_TenantName( "TenantName" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_Id, getRequiredId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_CreatedBy, getCreatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_UpdatedBy, getUpdatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_TenantName, getRequiredTenantName() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantPKey& rhs ) {
		if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantHPKey& rhs ) {
		if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantPKey& rhs ) {
		if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantHPKey& rhs ) {
		if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantPKey& rhs ) {
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantHPKey& rhs ) {
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		if( lhs.getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		if( lhs.getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantPKey& rhs ) {
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantHPKey& rhs ) {
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantPKey& rhs ) {
		if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantHPKey& rhs ) {
		if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantPKey& rhs ) {
		if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantHPKey& rhs ) {
		if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTenantBuff& lhs, const cfsec::CFSecTenantBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}
}

