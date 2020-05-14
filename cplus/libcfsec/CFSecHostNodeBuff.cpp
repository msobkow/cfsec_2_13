// Description: C++18 implementation for a HostNode buffer object.

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

#include <cfsec/CFSecHostNodeByClusterIdxKey.hpp>
#include <cfsec/CFSecHostNodeByUDescrIdxKey.hpp>
#include <cfsec/CFSecHostNodeByHostNameIdxKey.hpp>
#include <cfsec/CFSecSchema.hpp>

namespace cfsec {

	const std::string CFSecHostNodeBuff::S_VALUE( "value" );
	const std::string CFSecHostNodeBuff::S_VALUE_LENGTH( "value.length()" );

	const std::string CFSecHostNodeBuff::GENDEFNAME( "HostNode" );
	const classcode_t CFSecHostNodeBuff::CLASS_CODE = 0xa002L;
	const std::string CFSecHostNodeBuff::CLASS_NAME( "CFSecHostNodeBuff" );
		const std::string CFSecHostNodeBuff::COLNAME_CLUSTERID( "ClusterId" );
		const std::string CFSecHostNodeBuff::COLNAME_HOSTNODEID( "HostNodeId" );
		const std::string CFSecHostNodeBuff::COLNAME_DESCRIPTION( "Description" );
		const std::string CFSecHostNodeBuff::COLNAME_HOSTNAME( "HostName" );
	const char* CFSecHostNodeBuff::S_INIT_CREATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const char* CFSecHostNodeBuff::S_INIT_UPDATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const int64_t CFSecHostNodeBuff::CLUSTERID_INIT_VALUE = 0LL;
	const int64_t CFSecHostNodeBuff::HOSTNODEID_INIT_VALUE = 0LL;
	const std::string CFSecHostNodeBuff::DESCRIPTION_INIT_VALUE( "" );
	const std::string CFSecHostNodeBuff::HOSTNAME_INIT_VALUE( "" );
	const int64_t CFSecHostNodeBuff::CLUSTERID_MIN_VALUE = 0LL;
	const int64_t CFSecHostNodeBuff::HOSTNODEID_MIN_VALUE = 0LL;
	const std::string::size_type CFSecHostNodeBuff::DESCRIPTION_MAX_LEN = 255;
	const std::string::size_type CFSecHostNodeBuff::HOSTNAME_MAX_LEN = 192;

	CFSecHostNodeBuff::CFSecHostNodeBuff()
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
		requiredClusterId = cfsec::CFSecHostNodeBuff::CLUSTERID_INIT_VALUE;
		requiredHostNodeId = cfsec::CFSecHostNodeBuff::HOSTNODEID_INIT_VALUE;
		requiredDescription = new std::string( cfsec::CFSecHostNodeBuff::DESCRIPTION_INIT_VALUE );
		requiredHostName = new std::string( cfsec::CFSecHostNodeBuff::HOSTNAME_INIT_VALUE );
	}

	CFSecHostNodeBuff::CFSecHostNodeBuff( const CFSecHostNodeBuff& src )
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
		requiredClusterId = cfsec::CFSecHostNodeBuff::CLUSTERID_INIT_VALUE;
		requiredHostNodeId = cfsec::CFSecHostNodeBuff::HOSTNODEID_INIT_VALUE;
		requiredDescription = new std::string( cfsec::CFSecHostNodeBuff::DESCRIPTION_INIT_VALUE );
		requiredHostName = new std::string( cfsec::CFSecHostNodeBuff::HOSTNAME_INIT_VALUE );
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredHostNodeId( src.getRequiredHostNodeId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredDescription( src.getRequiredDescription() );
		setRequiredHostName( src.getRequiredHostName() );
	}

	CFSecHostNodeBuff::~CFSecHostNodeBuff() {
		if( requiredDescription != NULL ) {
			delete requiredDescription;
			requiredDescription = NULL;
		}
		if( requiredHostName != NULL ) {
			delete requiredHostName;
			requiredHostName = NULL;
		}
		for( int i = 0; i < 16; i++ ) {
			createdByUserId[i] = 0;
		}
		for( int i = 0; i < 16; i++ ) {
			updatedByUserId[i] = 0;
		}
	}

	cflib::ICFLibCloneableObj* CFSecHostNodeBuff::clone() {
		CFSecHostNodeBuff* copy = new CFSecHostNodeBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const std::string& CFSecHostNodeBuff::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecHostNodeBuff::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecHostNodeBuff::implementsClassCode( const classcode_t argClassCode ) {
		if( argClassCode == CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	const uuid_ptr_t CFSecHostNodeBuff::getCreatedByUserId() const {
		return( createdByUserId );
	}

	void CFSecHostNodeBuff::setCreatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( createdByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecHostNodeBuff::getCreatedAt() const {
		return( createdAt );
	}

	void CFSecHostNodeBuff::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		createdAt = value;
	}

	const uuid_ptr_t CFSecHostNodeBuff::getUpdatedByUserId() const {
		return( updatedByUserId );
	}

	void CFSecHostNodeBuff::setUpdatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( updatedByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecHostNodeBuff::getUpdatedAt() const {
		return( updatedAt );
	}

	void CFSecHostNodeBuff::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		updatedAt = value;
	}
	const int64_t CFSecHostNodeBuff::getRequiredClusterId() const {
		return( requiredClusterId );
	}

	const int64_t* CFSecHostNodeBuff::getRequiredClusterIdReference() const {
		return( &requiredClusterId );
	}

	void CFSecHostNodeBuff::setRequiredClusterId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredClusterId" );
		if( value < cfsec::CFSecHostNodeBuff::CLUSTERID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecHostNodeBuff::CLUSTERID_MIN_VALUE );
		}
		requiredClusterId = value;
	}

	const int64_t CFSecHostNodeBuff::getRequiredHostNodeId() const {
		return( requiredHostNodeId );
	}

	const int64_t* CFSecHostNodeBuff::getRequiredHostNodeIdReference() const {
		return( &requiredHostNodeId );
	}

	void CFSecHostNodeBuff::setRequiredHostNodeId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredHostNodeId" );
		if( value < cfsec::CFSecHostNodeBuff::HOSTNODEID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecHostNodeBuff::HOSTNODEID_MIN_VALUE );
		}
		requiredHostNodeId = value;
	}

	const std::string& CFSecHostNodeBuff::getRequiredDescription() const {
		return( *requiredDescription );
	}

	const std::string* CFSecHostNodeBuff::getRequiredDescriptionReference() const {
		return( requiredDescription );
	}

	void CFSecHostNodeBuff::setRequiredDescription( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredDescription" );
		if( value.length() > CFSecHostNodeBuff::DESCRIPTION_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecHostNodeBuff::DESCRIPTION_MAX_LEN );
		}
		if( requiredDescription != NULL ) {
			delete requiredDescription;
			requiredDescription = NULL;
		}
		requiredDescription = new std::string( value );
	}

	const std::string& CFSecHostNodeBuff::getRequiredHostName() const {
		return( *requiredHostName );
	}

	const std::string* CFSecHostNodeBuff::getRequiredHostNameReference() const {
		return( requiredHostName );
	}

	void CFSecHostNodeBuff::setRequiredHostName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredHostName" );
		if( value.length() > CFSecHostNodeBuff::HOSTNAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecHostNodeBuff::HOSTNAME_MAX_LEN );
		}
		if( requiredHostName != NULL ) {
			delete requiredHostName;
			requiredHostName = NULL;
		}
		requiredHostName = new std::string( value );
	}

	int32_t CFSecHostNodeBuff::getRequiredRevision() const {
		return( requiredRevision );
	}

	void CFSecHostNodeBuff::setRequiredRevision( int32_t value ) {
		requiredRevision = value;
	}

	size_t CFSecHostNodeBuff::hashCode() const {
		size_t hashCode = 0L;
		hashCode = hashCode + (int)( getRequiredClusterId() );
		hashCode = hashCode + (int)( getRequiredHostNodeId() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredDescription() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredHostName() );
		return( hashCode );
	}

	CFSecHostNodeBuff CFSecHostNodeBuff::operator =( cfsec::CFSecHostNodeBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredHostNodeId( src.getRequiredHostNodeId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredDescription( src.getRequiredDescription() );
		setRequiredHostName( src.getRequiredHostName() );
		return( *this );
	}

	CFSecHostNodeBuff CFSecHostNodeBuff::operator =( cfsec::CFSecHostNodeHBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredHostNodeId( src.getRequiredHostNodeId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredDescription( src.getRequiredDescription() );
		setRequiredHostName( src.getRequiredHostName() );
		return( *this );
	}

	bool CFSecHostNodeBuff::operator <( const CFSecHostNodeByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeBuff::operator <( const CFSecHostNodeByUDescrIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeBuff::operator <( const CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeBuff::operator <( const CFSecHostNodePKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeBuff::operator <( const CFSecHostNodeHPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeBuff::operator <( const CFSecHostNodeHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeBuff::operator <( const CFSecHostNodeBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeBuff::operator <=( const CFSecHostNodeByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecHostNodeBuff::operator <=( const CFSecHostNodeByUDescrIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecHostNodeBuff::operator <=( const CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecHostNodeBuff::operator <=( const CFSecHostNodePKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecHostNodeBuff::operator <=( const CFSecHostNodeHPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecHostNodeBuff::operator <=( const CFSecHostNodeHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecHostNodeBuff::operator <=( const CFSecHostNodeBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecHostNodeBuff::operator ==( const CFSecHostNodeByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecHostNodeBuff::operator ==( const CFSecHostNodeByUDescrIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecHostNodeBuff::operator ==( const CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecHostNodeBuff::operator ==( const CFSecHostNodePKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecHostNodeBuff::operator ==( const CFSecHostNodeHPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecHostNodeBuff::operator ==( const CFSecHostNodeHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		if( getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecHostNodeBuff::operator ==( const CFSecHostNodeBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		if( getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecHostNodeBuff::operator !=( const CFSecHostNodeByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeBuff::operator !=( const CFSecHostNodeByUDescrIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeBuff::operator !=( const CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeBuff::operator !=( const CFSecHostNodePKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeBuff::operator !=( const CFSecHostNodeHPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeBuff::operator !=( const CFSecHostNodeHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeBuff::operator !=( const CFSecHostNodeBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeBuff::operator >=( const CFSecHostNodeByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecHostNodeBuff::operator >=( const CFSecHostNodeByUDescrIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecHostNodeBuff::operator >=( const CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecHostNodeBuff::operator >=( const CFSecHostNodePKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecHostNodeBuff::operator >=( const CFSecHostNodeHPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecHostNodeBuff::operator >=( const CFSecHostNodeHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecHostNodeBuff::operator >=( const CFSecHostNodeBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecHostNodeBuff::operator >( const CFSecHostNodeByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeBuff::operator >( const CFSecHostNodeByUDescrIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeBuff::operator >( const CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeBuff::operator >( const CFSecHostNodePKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeBuff::operator >( const CFSecHostNodeHPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeBuff::operator >( const CFSecHostNodeHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeBuff::operator >( const CFSecHostNodeBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	std::string CFSecHostNodeBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecHostNodeBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_HostNodeId( "HostNodeId" );
		static const std::string S_Description( "Description" );
		static const std::string S_HostName( "HostName" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_HostNodeId, getRequiredHostNodeId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_CreatedBy, getCreatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_UpdatedBy, getUpdatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, getRequiredDescription() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_HostName, getRequiredHostName() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodePKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeHPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodePKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeHPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodePKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeHPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		if( lhs.getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		if( lhs.getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodePKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeHPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodePKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeHPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodePKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeHPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecHostNodeBuff& lhs, const cfsec::CFSecHostNodeBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}
}

