// Description: C++18 implementation for a TSecGrpMemb buffer object.

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

#include <cfsec/CFSecTSecGrpMembByTenantIdxKey.hpp>
#include <cfsec/CFSecTSecGrpMembByGroupIdxKey.hpp>
#include <cfsec/CFSecTSecGrpMembByUserIdxKey.hpp>
#include <cfsec/CFSecTSecGrpMembByUUserIdxKey.hpp>
#include <cfsec/CFSecSchema.hpp>

namespace cfsec {

	const std::string CFSecTSecGrpMembBuff::S_VALUE( "value" );
	const std::string CFSecTSecGrpMembBuff::S_VALUE_LENGTH( "value.length()" );

	const std::string CFSecTSecGrpMembBuff::GENDEFNAME( "TSecGrpMemb" );
	const classcode_t CFSecTSecGrpMembBuff::CLASS_CODE = 0xa018L;
	const std::string CFSecTSecGrpMembBuff::CLASS_NAME( "CFSecTSecGrpMembBuff" );
		const std::string CFSecTSecGrpMembBuff::COLNAME_TENANTID( "TenantId" );
		const std::string CFSecTSecGrpMembBuff::COLNAME_TSECGRPMEMBID( "TSecGrpMembId" );
		const std::string CFSecTSecGrpMembBuff::COLNAME_TSECGROUPID( "TSecGroupId" );
		const std::string CFSecTSecGrpMembBuff::COLNAME_SECUSERID( "SecUserId" );
	const char* CFSecTSecGrpMembBuff::S_INIT_CREATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const char* CFSecTSecGrpMembBuff::S_INIT_UPDATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const int64_t CFSecTSecGrpMembBuff::TENANTID_INIT_VALUE = 0LL;
	const int64_t CFSecTSecGrpMembBuff::TSECGRPMEMBID_INIT_VALUE = 0LL;
	const int CFSecTSecGrpMembBuff::TSECGROUPID_INIT_VALUE = 0L;
	const int64_t CFSecTSecGrpMembBuff::TENANTID_MIN_VALUE = 0LL;
	const int64_t CFSecTSecGrpMembBuff::TSECGRPMEMBID_MIN_VALUE = 0LL;
	const int CFSecTSecGrpMembBuff::TSECGROUPID_MIN_VALUE = 0L;

	CFSecTSecGrpMembBuff::CFSecTSecGrpMembBuff()
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
		requiredTenantId = cfsec::CFSecTSecGrpMembBuff::TENANTID_INIT_VALUE;
		requiredTSecGrpMembId = cfsec::CFSecTSecGrpMembBuff::TSECGRPMEMBID_INIT_VALUE;
		requiredTSecGroupId = cfsec::CFSecTSecGrpMembBuff::TSECGROUPID_INIT_VALUE;
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
	}

	CFSecTSecGrpMembBuff::CFSecTSecGrpMembBuff( const CFSecTSecGrpMembBuff& src )
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
		requiredTenantId = cfsec::CFSecTSecGrpMembBuff::TENANTID_INIT_VALUE;
		requiredTSecGrpMembId = cfsec::CFSecTSecGrpMembBuff::TSECGRPMEMBID_INIT_VALUE;
		requiredTSecGroupId = cfsec::CFSecTSecGrpMembBuff::TSECGROUPID_INIT_VALUE;
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTSecGrpMembId( src.getRequiredTSecGrpMembId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredTSecGroupId( src.getRequiredTSecGroupId() );
		setRequiredSecUserId( src.getRequiredSecUserId() );
	}

	CFSecTSecGrpMembBuff::~CFSecTSecGrpMembBuff() {
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
		for( int i = 0; i < 16; i++ ) {
			createdByUserId[i] = 0;
		}
		for( int i = 0; i < 16; i++ ) {
			updatedByUserId[i] = 0;
		}
	}

	cflib::ICFLibCloneableObj* CFSecTSecGrpMembBuff::clone() {
		CFSecTSecGrpMembBuff* copy = new CFSecTSecGrpMembBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const std::string& CFSecTSecGrpMembBuff::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecTSecGrpMembBuff::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecTSecGrpMembBuff::implementsClassCode( const classcode_t argClassCode ) {
		if( argClassCode == CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	const uuid_ptr_t CFSecTSecGrpMembBuff::getCreatedByUserId() const {
		return( createdByUserId );
	}

	void CFSecTSecGrpMembBuff::setCreatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( createdByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecTSecGrpMembBuff::getCreatedAt() const {
		return( createdAt );
	}

	void CFSecTSecGrpMembBuff::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		createdAt = value;
	}

	const uuid_ptr_t CFSecTSecGrpMembBuff::getUpdatedByUserId() const {
		return( updatedByUserId );
	}

	void CFSecTSecGrpMembBuff::setUpdatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( updatedByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecTSecGrpMembBuff::getUpdatedAt() const {
		return( updatedAt );
	}

	void CFSecTSecGrpMembBuff::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		updatedAt = value;
	}
	const int64_t CFSecTSecGrpMembBuff::getRequiredTenantId() const {
		return( requiredTenantId );
	}

	const int64_t* CFSecTSecGrpMembBuff::getRequiredTenantIdReference() const {
		return( &requiredTenantId );
	}

	void CFSecTSecGrpMembBuff::setRequiredTenantId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredTenantId" );
		if( value < cfsec::CFSecTSecGrpMembBuff::TENANTID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecTSecGrpMembBuff::TENANTID_MIN_VALUE );
		}
		requiredTenantId = value;
	}

	const int64_t CFSecTSecGrpMembBuff::getRequiredTSecGrpMembId() const {
		return( requiredTSecGrpMembId );
	}

	const int64_t* CFSecTSecGrpMembBuff::getRequiredTSecGrpMembIdReference() const {
		return( &requiredTSecGrpMembId );
	}

	void CFSecTSecGrpMembBuff::setRequiredTSecGrpMembId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredTSecGrpMembId" );
		if( value < cfsec::CFSecTSecGrpMembBuff::TSECGRPMEMBID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecTSecGrpMembBuff::TSECGRPMEMBID_MIN_VALUE );
		}
		requiredTSecGrpMembId = value;
	}

	const int32_t CFSecTSecGrpMembBuff::getRequiredTSecGroupId() const {
		return( requiredTSecGroupId );
	}

	const int32_t* CFSecTSecGrpMembBuff::getRequiredTSecGroupIdReference() const {
		return( &requiredTSecGroupId );
	}

	void CFSecTSecGrpMembBuff::setRequiredTSecGroupId( const int32_t value ) {
		static const std::string S_ProcName( "setRequiredTSecGroupId" );
		if( value < cfsec::CFSecTSecGrpMembBuff::TSECGROUPID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecTSecGrpMembBuff::TSECGROUPID_MIN_VALUE );
		}
		requiredTSecGroupId = value;
	}

	const uuid_ptr_t CFSecTSecGrpMembBuff::getRequiredSecUserId() const {
		return( requiredSecUserId );
	}

	const uuid_ptr_t CFSecTSecGrpMembBuff::getRequiredSecUserIdReference() const {
		return( requiredSecUserId );
	}

	void CFSecTSecGrpMembBuff::setRequiredSecUserId( const uuid_ptr_t value ) {
		uuid_copy( requiredSecUserId, value );
	}

	void CFSecTSecGrpMembBuff::generateRequiredSecUserId() {
		uuid_generate_random( requiredSecUserId );
	}

	int32_t CFSecTSecGrpMembBuff::getRequiredRevision() const {
		return( requiredRevision );
	}

	void CFSecTSecGrpMembBuff::setRequiredRevision( int32_t value ) {
		requiredRevision = value;
	}

	size_t CFSecTSecGrpMembBuff::hashCode() const {
		size_t hashCode = 0L;
		hashCode = hashCode + (int)( getRequiredTenantId() );
		hashCode = hashCode + (int)( getRequiredTSecGrpMembId() );
		hashCode = hashCode + getRequiredTSecGroupId();
		hashCode = hashCode + cflib::CFLib::hash( getRequiredSecUserId() );
		return( hashCode );
	}

	CFSecTSecGrpMembBuff CFSecTSecGrpMembBuff::operator =( cfsec::CFSecTSecGrpMembBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTSecGrpMembId( src.getRequiredTSecGrpMembId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredTSecGroupId( src.getRequiredTSecGroupId() );
		setRequiredSecUserId( src.getRequiredSecUserId() );
		return( *this );
	}

	CFSecTSecGrpMembBuff CFSecTSecGrpMembBuff::operator =( cfsec::CFSecTSecGrpMembHBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTSecGrpMembId( src.getRequiredTSecGrpMembId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredTSecGroupId( src.getRequiredTSecGroupId() );
		setRequiredSecUserId( src.getRequiredSecUserId() );
		return( *this );
	}

	bool CFSecTSecGrpMembBuff::operator <( const CFSecTSecGrpMembByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembBuff::operator <( const CFSecTSecGrpMembByGroupIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembBuff::operator <( const CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembBuff::operator <( const CFSecTSecGrpMembByUUserIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembBuff::operator <( const CFSecTSecGrpMembPKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembBuff::operator <( const CFSecTSecGrpMembHPKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembBuff::operator <( const CFSecTSecGrpMembHBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembBuff::operator <( const CFSecTSecGrpMembBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembBuff::operator <=( const CFSecTSecGrpMembByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator <=( const CFSecTSecGrpMembByGroupIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator <=( const CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator <=( const CFSecTSecGrpMembByUUserIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator <=( const CFSecTSecGrpMembPKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator <=( const CFSecTSecGrpMembHPKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator <=( const CFSecTSecGrpMembHBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator <=( const CFSecTSecGrpMembBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator ==( const CFSecTSecGrpMembByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator ==( const CFSecTSecGrpMembByGroupIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator ==( const CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator ==( const CFSecTSecGrpMembByUUserIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator ==( const CFSecTSecGrpMembPKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator ==( const CFSecTSecGrpMembHPKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator ==( const CFSecTSecGrpMembHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		if( getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator ==( const CFSecTSecGrpMembBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		if( getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator !=( const CFSecTSecGrpMembByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembBuff::operator !=( const CFSecTSecGrpMembByGroupIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembBuff::operator !=( const CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembBuff::operator !=( const CFSecTSecGrpMembByUUserIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembBuff::operator !=( const CFSecTSecGrpMembPKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembBuff::operator !=( const CFSecTSecGrpMembHPKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembBuff::operator !=( const CFSecTSecGrpMembHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembBuff::operator !=( const CFSecTSecGrpMembBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembBuff::operator >=( const CFSecTSecGrpMembByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator >=( const CFSecTSecGrpMembByGroupIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator >=( const CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator >=( const CFSecTSecGrpMembByUUserIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator >=( const CFSecTSecGrpMembPKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator >=( const CFSecTSecGrpMembHPKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator >=( const CFSecTSecGrpMembHBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator >=( const CFSecTSecGrpMembBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembBuff::operator >( const CFSecTSecGrpMembByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembBuff::operator >( const CFSecTSecGrpMembByGroupIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembBuff::operator >( const CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembBuff::operator >( const CFSecTSecGrpMembByUUserIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembBuff::operator >( const CFSecTSecGrpMembPKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembBuff::operator >( const CFSecTSecGrpMembHPKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembBuff::operator >( const CFSecTSecGrpMembHBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembBuff::operator >( const CFSecTSecGrpMembBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	std::string CFSecTSecGrpMembBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecTSecGrpMembBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_TSecGrpMembId( "TSecGrpMembId" );
		static const std::string S_TSecGroupId( "TSecGroupId" );
		static const std::string S_SecUserId( "SecUserId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TSecGrpMembId, getRequiredTSecGrpMembId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_CreatedBy, getCreatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_UpdatedBy, getUpdatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_TSecGroupId, getRequiredTSecGroupId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, getRequiredSecUserId() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByGroupIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUUserIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByGroupIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUUserIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByGroupIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUUserIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		if( lhs.getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		if( lhs.getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByGroupIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUUserIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByGroupIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUUserIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByGroupIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembByUUserIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTSecGrpMembBuff& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}
}

