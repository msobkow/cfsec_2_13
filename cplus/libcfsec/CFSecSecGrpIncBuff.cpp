// Description: C++18 implementation for a SecGrpInc buffer object.

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

#include <cfsec/CFSecSecGrpIncByClusterIdxKey.hpp>
#include <cfsec/CFSecSecGrpIncByGroupIdxKey.hpp>
#include <cfsec/CFSecSecGrpIncByIncludeIdxKey.hpp>
#include <cfsec/CFSecSecGrpIncByUIncludeIdxKey.hpp>
#include <cfsec/CFSecSchema.hpp>

namespace cfsec {

	const std::string CFSecSecGrpIncBuff::S_VALUE( "value" );
	const std::string CFSecSecGrpIncBuff::S_VALUE_LENGTH( "value.length()" );

	const std::string CFSecSecGrpIncBuff::GENDEFNAME( "SecGrpInc" );
	const classcode_t CFSecSecGrpIncBuff::CLASS_CODE = 0xa00eL;
	const std::string CFSecSecGrpIncBuff::CLASS_NAME( "CFSecSecGrpIncBuff" );
		const std::string CFSecSecGrpIncBuff::COLNAME_CLUSTERID( "ClusterId" );
		const std::string CFSecSecGrpIncBuff::COLNAME_SECGRPINCID( "SecGrpIncId" );
		const std::string CFSecSecGrpIncBuff::COLNAME_SECGROUPID( "SecGroupId" );
		const std::string CFSecSecGrpIncBuff::COLNAME_INCLUDEGROUPID( "IncludeGroupId" );
	const char* CFSecSecGrpIncBuff::S_INIT_CREATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const char* CFSecSecGrpIncBuff::S_INIT_UPDATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const int64_t CFSecSecGrpIncBuff::CLUSTERID_INIT_VALUE = 0LL;
	const int64_t CFSecSecGrpIncBuff::SECGRPINCID_INIT_VALUE = 0LL;
	const int CFSecSecGrpIncBuff::SECGROUPID_INIT_VALUE = 0L;
	const int CFSecSecGrpIncBuff::INCLUDEGROUPID_INIT_VALUE = 0L;
	const int64_t CFSecSecGrpIncBuff::CLUSTERID_MIN_VALUE = 0LL;
	const int64_t CFSecSecGrpIncBuff::SECGRPINCID_MIN_VALUE = 0LL;
	const int CFSecSecGrpIncBuff::SECGROUPID_MIN_VALUE = 0L;
	const int CFSecSecGrpIncBuff::INCLUDEGROUPID_MIN_VALUE = 0L;

	CFSecSecGrpIncBuff::CFSecSecGrpIncBuff()
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
		requiredClusterId = cfsec::CFSecSecGrpIncBuff::CLUSTERID_INIT_VALUE;
		requiredSecGrpIncId = cfsec::CFSecSecGrpIncBuff::SECGRPINCID_INIT_VALUE;
		requiredSecGroupId = cfsec::CFSecSecGrpIncBuff::SECGROUPID_INIT_VALUE;
		requiredIncludeGroupId = cfsec::CFSecSecGrpIncBuff::INCLUDEGROUPID_INIT_VALUE;
	}

	CFSecSecGrpIncBuff::CFSecSecGrpIncBuff( const CFSecSecGrpIncBuff& src )
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
		requiredClusterId = cfsec::CFSecSecGrpIncBuff::CLUSTERID_INIT_VALUE;
		requiredSecGrpIncId = cfsec::CFSecSecGrpIncBuff::SECGRPINCID_INIT_VALUE;
		requiredSecGroupId = cfsec::CFSecSecGrpIncBuff::SECGROUPID_INIT_VALUE;
		requiredIncludeGroupId = cfsec::CFSecSecGrpIncBuff::INCLUDEGROUPID_INIT_VALUE;
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecGrpIncId( src.getRequiredSecGrpIncId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredSecGroupId( src.getRequiredSecGroupId() );
		setRequiredIncludeGroupId( src.getRequiredIncludeGroupId() );
	}

	CFSecSecGrpIncBuff::~CFSecSecGrpIncBuff() {
		for( int i = 0; i < 16; i++ ) {
			createdByUserId[i] = 0;
		}
		for( int i = 0; i < 16; i++ ) {
			updatedByUserId[i] = 0;
		}
	}

	cflib::ICFLibCloneableObj* CFSecSecGrpIncBuff::clone() {
		CFSecSecGrpIncBuff* copy = new CFSecSecGrpIncBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const std::string& CFSecSecGrpIncBuff::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecSecGrpIncBuff::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecSecGrpIncBuff::implementsClassCode( const classcode_t argClassCode ) {
		if( argClassCode == CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	const uuid_ptr_t CFSecSecGrpIncBuff::getCreatedByUserId() const {
		return( createdByUserId );
	}

	void CFSecSecGrpIncBuff::setCreatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( createdByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecSecGrpIncBuff::getCreatedAt() const {
		return( createdAt );
	}

	void CFSecSecGrpIncBuff::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		createdAt = value;
	}

	const uuid_ptr_t CFSecSecGrpIncBuff::getUpdatedByUserId() const {
		return( updatedByUserId );
	}

	void CFSecSecGrpIncBuff::setUpdatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( updatedByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecSecGrpIncBuff::getUpdatedAt() const {
		return( updatedAt );
	}

	void CFSecSecGrpIncBuff::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		updatedAt = value;
	}
	const int64_t CFSecSecGrpIncBuff::getRequiredClusterId() const {
		return( requiredClusterId );
	}

	const int64_t* CFSecSecGrpIncBuff::getRequiredClusterIdReference() const {
		return( &requiredClusterId );
	}

	void CFSecSecGrpIncBuff::setRequiredClusterId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredClusterId" );
		if( value < cfsec::CFSecSecGrpIncBuff::CLUSTERID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecSecGrpIncBuff::CLUSTERID_MIN_VALUE );
		}
		requiredClusterId = value;
	}

	const int64_t CFSecSecGrpIncBuff::getRequiredSecGrpIncId() const {
		return( requiredSecGrpIncId );
	}

	const int64_t* CFSecSecGrpIncBuff::getRequiredSecGrpIncIdReference() const {
		return( &requiredSecGrpIncId );
	}

	void CFSecSecGrpIncBuff::setRequiredSecGrpIncId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredSecGrpIncId" );
		if( value < cfsec::CFSecSecGrpIncBuff::SECGRPINCID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecSecGrpIncBuff::SECGRPINCID_MIN_VALUE );
		}
		requiredSecGrpIncId = value;
	}

	const int32_t CFSecSecGrpIncBuff::getRequiredSecGroupId() const {
		return( requiredSecGroupId );
	}

	const int32_t* CFSecSecGrpIncBuff::getRequiredSecGroupIdReference() const {
		return( &requiredSecGroupId );
	}

	void CFSecSecGrpIncBuff::setRequiredSecGroupId( const int32_t value ) {
		static const std::string S_ProcName( "setRequiredSecGroupId" );
		if( value < cfsec::CFSecSecGrpIncBuff::SECGROUPID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecSecGrpIncBuff::SECGROUPID_MIN_VALUE );
		}
		requiredSecGroupId = value;
	}

	const int32_t CFSecSecGrpIncBuff::getRequiredIncludeGroupId() const {
		return( requiredIncludeGroupId );
	}

	const int32_t* CFSecSecGrpIncBuff::getRequiredIncludeGroupIdReference() const {
		return( &requiredIncludeGroupId );
	}

	void CFSecSecGrpIncBuff::setRequiredIncludeGroupId( const int32_t value ) {
		static const std::string S_ProcName( "setRequiredIncludeGroupId" );
		if( value < cfsec::CFSecSecGrpIncBuff::INCLUDEGROUPID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecSecGrpIncBuff::INCLUDEGROUPID_MIN_VALUE );
		}
		requiredIncludeGroupId = value;
	}

	int32_t CFSecSecGrpIncBuff::getRequiredRevision() const {
		return( requiredRevision );
	}

	void CFSecSecGrpIncBuff::setRequiredRevision( int32_t value ) {
		requiredRevision = value;
	}

	size_t CFSecSecGrpIncBuff::hashCode() const {
		size_t hashCode = 0L;
		hashCode = hashCode + (int)( getRequiredClusterId() );
		hashCode = hashCode + (int)( getRequiredSecGrpIncId() );
		hashCode = hashCode + getRequiredSecGroupId();
		hashCode = hashCode + getRequiredIncludeGroupId();
		return( hashCode );
	}

	CFSecSecGrpIncBuff CFSecSecGrpIncBuff::operator =( cfsec::CFSecSecGrpIncBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecGrpIncId( src.getRequiredSecGrpIncId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredSecGroupId( src.getRequiredSecGroupId() );
		setRequiredIncludeGroupId( src.getRequiredIncludeGroupId() );
		return( *this );
	}

	CFSecSecGrpIncBuff CFSecSecGrpIncBuff::operator =( cfsec::CFSecSecGrpIncHBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecGrpIncId( src.getRequiredSecGrpIncId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredSecGroupId( src.getRequiredSecGroupId() );
		setRequiredIncludeGroupId( src.getRequiredIncludeGroupId() );
		return( *this );
	}

	bool CFSecSecGrpIncBuff::operator <( const CFSecSecGrpIncByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpIncBuff::operator <( const CFSecSecGrpIncByGroupIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpIncBuff::operator <( const CFSecSecGrpIncByIncludeIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpIncBuff::operator <( const CFSecSecGrpIncByUIncludeIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpIncBuff::operator <( const CFSecSecGrpIncPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpIncBuff::operator <( const CFSecSecGrpIncHPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpIncBuff::operator <( const CFSecSecGrpIncHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpIncBuff::operator <( const CFSecSecGrpIncBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpIncBuff::operator <=( const CFSecSecGrpIncByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator <=( const CFSecSecGrpIncByGroupIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator <=( const CFSecSecGrpIncByIncludeIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator <=( const CFSecSecGrpIncByUIncludeIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator <=( const CFSecSecGrpIncPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator <=( const CFSecSecGrpIncHPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator <=( const CFSecSecGrpIncHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator <=( const CFSecSecGrpIncBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator ==( const CFSecSecGrpIncByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator ==( const CFSecSecGrpIncByGroupIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator ==( const CFSecSecGrpIncByIncludeIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator ==( const CFSecSecGrpIncByUIncludeIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		if( getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator ==( const CFSecSecGrpIncPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecGrpIncId() != rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator ==( const CFSecSecGrpIncHPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecGrpIncId() != rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator ==( const CFSecSecGrpIncHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecGrpIncId() != rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		if( getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		if( getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator ==( const CFSecSecGrpIncBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecGrpIncId() != rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		if( getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		if( getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator !=( const CFSecSecGrpIncByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpIncBuff::operator !=( const CFSecSecGrpIncByGroupIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpIncBuff::operator !=( const CFSecSecGrpIncByIncludeIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpIncBuff::operator !=( const CFSecSecGrpIncByUIncludeIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpIncBuff::operator !=( const CFSecSecGrpIncPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpIncId() != rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpIncBuff::operator !=( const CFSecSecGrpIncHPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpIncId() != rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpIncBuff::operator !=( const CFSecSecGrpIncHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpIncId() != rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpIncBuff::operator !=( const CFSecSecGrpIncBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpIncId() != rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpIncBuff::operator >=( const CFSecSecGrpIncByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator >=( const CFSecSecGrpIncByGroupIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator >=( const CFSecSecGrpIncByIncludeIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator >=( const CFSecSecGrpIncByUIncludeIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator >=( const CFSecSecGrpIncPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator >=( const CFSecSecGrpIncHPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator >=( const CFSecSecGrpIncHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator >=( const CFSecSecGrpIncBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpIncBuff::operator >( const CFSecSecGrpIncByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpIncBuff::operator >( const CFSecSecGrpIncByGroupIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpIncBuff::operator >( const CFSecSecGrpIncByIncludeIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpIncBuff::operator >( const CFSecSecGrpIncByUIncludeIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpIncBuff::operator >( const CFSecSecGrpIncPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpIncBuff::operator >( const CFSecSecGrpIncHPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpIncBuff::operator >( const CFSecSecGrpIncHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpIncBuff::operator >( const CFSecSecGrpIncBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	std::string CFSecSecGrpIncBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecGrpIncBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecGrpIncId( "SecGrpIncId" );
		static const std::string S_SecGroupId( "SecGroupId" );
		static const std::string S_IncludeGroupId( "IncludeGroupId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_SecGrpIncId, getRequiredSecGrpIncId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_CreatedBy, getCreatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_UpdatedBy, getUpdatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecGroupId, getRequiredSecGroupId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_IncludeGroupId, getRequiredIncludeGroupId() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByGroupIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByUIncludeIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncHPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByGroupIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByUIncludeIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncHPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByGroupIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByUIncludeIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		if( lhs.getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecGrpIncId() != rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncHPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecGrpIncId() != rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecGrpIncId() != rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		if( lhs.getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		if( lhs.getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecGrpIncId() != rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		if( lhs.getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		if( lhs.getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByGroupIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByUIncludeIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpIncId() != rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncHPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpIncId() != rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpIncId() != rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpIncId() != rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByGroupIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByUIncludeIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncHPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByGroupIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByIncludeIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncByUIncludeIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncHPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecGrpIncBuff& lhs, const cfsec::CFSecSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpIncId() < rhs.getRequiredSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpIncId() > rhs.getRequiredSecGrpIncId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}
}

