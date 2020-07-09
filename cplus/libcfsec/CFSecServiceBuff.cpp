// Description: C++18 implementation for a Service buffer object.

/*
 *	org.msscf.msscf.CFSec
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

#include <cfsec/CFSecServiceByClusterIdxKey.hpp>
#include <cfsec/CFSecServiceByHostIdxKey.hpp>
#include <cfsec/CFSecServiceByTypeIdxKey.hpp>
#include <cfsec/CFSecServiceByUTypeIdxKey.hpp>
#include <cfsec/CFSecServiceByUHostPortIdxKey.hpp>
#include <cfsec/CFSecSchema.hpp>

namespace cfsec {

	const std::string CFSecServiceBuff::S_VALUE( "value" );
	const std::string CFSecServiceBuff::S_VALUE_LENGTH( "value.length()" );

	const std::string CFSecServiceBuff::GENDEFNAME( "Service" );
	const classcode_t CFSecServiceBuff::CLASS_CODE = 0xa012L;
	const std::string CFSecServiceBuff::CLASS_NAME( "CFSecServiceBuff" );
		const std::string CFSecServiceBuff::COLNAME_CLUSTERID( "ClusterId" );
		const std::string CFSecServiceBuff::COLNAME_SERVICEID( "ServiceId" );
		const std::string CFSecServiceBuff::COLNAME_HOSTNODEID( "HostNodeId" );
		const std::string CFSecServiceBuff::COLNAME_SERVICETYPEID( "ServiceTypeId" );
		const std::string CFSecServiceBuff::COLNAME_HOSTPORT( "HostPort" );
	const char* CFSecServiceBuff::S_INIT_CREATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const char* CFSecServiceBuff::S_INIT_UPDATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const int64_t CFSecServiceBuff::CLUSTERID_INIT_VALUE = 0LL;
	const int64_t CFSecServiceBuff::SERVICEID_INIT_VALUE = 0LL;
	const int64_t CFSecServiceBuff::HOSTNODEID_INIT_VALUE = 0LL;
	const int CFSecServiceBuff::SERVICETYPEID_INIT_VALUE = 0L;
	const int16_t CFSecServiceBuff::HOSTPORT_INIT_VALUE = (int16_t)0;
	const int64_t CFSecServiceBuff::CLUSTERID_MIN_VALUE = 0LL;
	const int64_t CFSecServiceBuff::SERVICEID_MIN_VALUE = 0LL;
	const int64_t CFSecServiceBuff::HOSTNODEID_MIN_VALUE = 0LL;
	const int CFSecServiceBuff::SERVICETYPEID_MIN_VALUE = 0L;
	const int16_t CFSecServiceBuff::HOSTPORT_MIN_VALUE = (int16_t)0;

	CFSecServiceBuff::CFSecServiceBuff()
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
		requiredClusterId = cfsec::CFSecServiceBuff::CLUSTERID_INIT_VALUE;
		requiredServiceId = cfsec::CFSecServiceBuff::SERVICEID_INIT_VALUE;
		requiredHostNodeId = cfsec::CFSecServiceBuff::HOSTNODEID_INIT_VALUE;
		requiredServiceTypeId = cfsec::CFSecServiceBuff::SERVICETYPEID_INIT_VALUE;
		requiredHostPort = cfsec::CFSecServiceBuff::HOSTPORT_INIT_VALUE;
	}

	CFSecServiceBuff::CFSecServiceBuff( const CFSecServiceBuff& src )
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
		requiredClusterId = cfsec::CFSecServiceBuff::CLUSTERID_INIT_VALUE;
		requiredServiceId = cfsec::CFSecServiceBuff::SERVICEID_INIT_VALUE;
		requiredHostNodeId = cfsec::CFSecServiceBuff::HOSTNODEID_INIT_VALUE;
		requiredServiceTypeId = cfsec::CFSecServiceBuff::SERVICETYPEID_INIT_VALUE;
		requiredHostPort = cfsec::CFSecServiceBuff::HOSTPORT_INIT_VALUE;
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredServiceId( src.getRequiredServiceId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredHostNodeId( src.getRequiredHostNodeId() );
		setRequiredServiceTypeId( src.getRequiredServiceTypeId() );
		setRequiredHostPort( src.getRequiredHostPort() );
	}

	CFSecServiceBuff::~CFSecServiceBuff() {
		for( int i = 0; i < 16; i++ ) {
			createdByUserId[i] = 0;
		}
		for( int i = 0; i < 16; i++ ) {
			updatedByUserId[i] = 0;
		}
	}

	cflib::ICFLibCloneableObj* CFSecServiceBuff::clone() {
		CFSecServiceBuff* copy = new CFSecServiceBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const std::string& CFSecServiceBuff::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecServiceBuff::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecServiceBuff::implementsClassCode( const classcode_t argClassCode ) {
		if( argClassCode == CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	const uuid_ptr_t CFSecServiceBuff::getCreatedByUserId() const {
		return( createdByUserId );
	}

	void CFSecServiceBuff::setCreatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( createdByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecServiceBuff::getCreatedAt() const {
		return( createdAt );
	}

	void CFSecServiceBuff::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		createdAt = value;
	}

	const uuid_ptr_t CFSecServiceBuff::getUpdatedByUserId() const {
		return( updatedByUserId );
	}

	void CFSecServiceBuff::setUpdatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( updatedByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecServiceBuff::getUpdatedAt() const {
		return( updatedAt );
	}

	void CFSecServiceBuff::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		updatedAt = value;
	}
	const int64_t CFSecServiceBuff::getRequiredClusterId() const {
		return( requiredClusterId );
	}

	const int64_t* CFSecServiceBuff::getRequiredClusterIdReference() const {
		return( &requiredClusterId );
	}

	void CFSecServiceBuff::setRequiredClusterId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredClusterId" );
		if( value < cfsec::CFSecServiceBuff::CLUSTERID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecServiceBuff::CLUSTERID_MIN_VALUE );
		}
		requiredClusterId = value;
	}

	const int64_t CFSecServiceBuff::getRequiredServiceId() const {
		return( requiredServiceId );
	}

	const int64_t* CFSecServiceBuff::getRequiredServiceIdReference() const {
		return( &requiredServiceId );
	}

	void CFSecServiceBuff::setRequiredServiceId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredServiceId" );
		if( value < cfsec::CFSecServiceBuff::SERVICEID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecServiceBuff::SERVICEID_MIN_VALUE );
		}
		requiredServiceId = value;
	}

	const int64_t CFSecServiceBuff::getRequiredHostNodeId() const {
		return( requiredHostNodeId );
	}

	const int64_t* CFSecServiceBuff::getRequiredHostNodeIdReference() const {
		return( &requiredHostNodeId );
	}

	void CFSecServiceBuff::setRequiredHostNodeId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredHostNodeId" );
		if( value < cfsec::CFSecServiceBuff::HOSTNODEID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecServiceBuff::HOSTNODEID_MIN_VALUE );
		}
		requiredHostNodeId = value;
	}

	const int32_t CFSecServiceBuff::getRequiredServiceTypeId() const {
		return( requiredServiceTypeId );
	}

	const int32_t* CFSecServiceBuff::getRequiredServiceTypeIdReference() const {
		return( &requiredServiceTypeId );
	}

	void CFSecServiceBuff::setRequiredServiceTypeId( const int32_t value ) {
		static const std::string S_ProcName( "setRequiredServiceTypeId" );
		if( value < cfsec::CFSecServiceBuff::SERVICETYPEID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecServiceBuff::SERVICETYPEID_MIN_VALUE );
		}
		requiredServiceTypeId = value;
	}

	const int16_t CFSecServiceBuff::getRequiredHostPort() const {
		return( requiredHostPort );
	}

	const int16_t* CFSecServiceBuff::getRequiredHostPortReference() const {
		return( &requiredHostPort );
	}

	void CFSecServiceBuff::setRequiredHostPort( const int16_t value ) {
		static const std::string S_ProcName( "setRequiredHostPort" );
		if( value < cfsec::CFSecServiceBuff::HOSTPORT_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecServiceBuff::HOSTPORT_MIN_VALUE );
		}
		requiredHostPort = value;
	}

	int32_t CFSecServiceBuff::getRequiredRevision() const {
		return( requiredRevision );
	}

	void CFSecServiceBuff::setRequiredRevision( int32_t value ) {
		requiredRevision = value;
	}

	size_t CFSecServiceBuff::hashCode() const {
		size_t hashCode = 0L;
		hashCode = hashCode + (int)( getRequiredClusterId() );
		hashCode = hashCode + (int)( getRequiredServiceId() );
		hashCode = hashCode + (int)( getRequiredHostNodeId() );
		hashCode = hashCode + getRequiredServiceTypeId();
		hashCode = ( hashCode * 0x10000 ) + getRequiredHostPort();
		return( hashCode );
	}

	CFSecServiceBuff CFSecServiceBuff::operator =( cfsec::CFSecServiceBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredServiceId( src.getRequiredServiceId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredHostNodeId( src.getRequiredHostNodeId() );
		setRequiredServiceTypeId( src.getRequiredServiceTypeId() );
		setRequiredHostPort( src.getRequiredHostPort() );
		return( *this );
	}

	CFSecServiceBuff CFSecServiceBuff::operator =( cfsec::CFSecServiceHBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredServiceId( src.getRequiredServiceId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredHostNodeId( src.getRequiredHostNodeId() );
		setRequiredServiceTypeId( src.getRequiredServiceTypeId() );
		setRequiredHostPort( src.getRequiredHostPort() );
		return( *this );
	}

	bool CFSecServiceBuff::operator <( const CFSecServiceByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator <( const CFSecServiceByHostIdxKey& rhs ) {
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

	bool CFSecServiceBuff::operator <( const CFSecServiceByTypeIdxKey& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator <( const CFSecServiceByUTypeIdxKey& rhs ) {
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
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator <( const CFSecServiceByUHostPortIdxKey& rhs ) {
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
		if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator <( const CFSecServicePKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator <( const CFSecServiceHPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator <( const CFSecServiceHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator <( const CFSecServiceBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator <=( const CFSecServiceByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator <=( const CFSecServiceByHostIdxKey& rhs ) {
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

	bool CFSecServiceBuff::operator <=( const CFSecServiceByTypeIdxKey& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator <=( const CFSecServiceByUTypeIdxKey& rhs ) {
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
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator <=( const CFSecServiceByUHostPortIdxKey& rhs ) {
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
		if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator <=( const CFSecServicePKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator <=( const CFSecServiceHPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator <=( const CFSecServiceHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator <=( const CFSecServiceBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator ==( const CFSecServiceByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator ==( const CFSecServiceByHostIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator ==( const CFSecServiceByTypeIdxKey& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator ==( const CFSecServiceByUTypeIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator ==( const CFSecServiceByUHostPortIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		if( getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator ==( const CFSecServicePKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator ==( const CFSecServiceHPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator ==( const CFSecServiceHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( false );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		if( getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator ==( const CFSecServiceBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( false );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		if( getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator !=( const CFSecServiceByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator !=( const CFSecServiceByHostIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator !=( const CFSecServiceByTypeIdxKey& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator !=( const CFSecServiceByUTypeIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator !=( const CFSecServiceByUHostPortIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator !=( const CFSecServicePKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator !=( const CFSecServiceHPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator !=( const CFSecServiceHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator !=( const CFSecServiceBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator >=( const CFSecServiceByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator >=( const CFSecServiceByHostIdxKey& rhs ) {
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

	bool CFSecServiceBuff::operator >=( const CFSecServiceByTypeIdxKey& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator >=( const CFSecServiceByUTypeIdxKey& rhs ) {
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
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator >=( const CFSecServiceByUHostPortIdxKey& rhs ) {
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
		if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator >=( const CFSecServicePKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator >=( const CFSecServiceHPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator >=( const CFSecServiceHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator >=( const CFSecServiceBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceBuff::operator >( const CFSecServiceByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator >( const CFSecServiceByHostIdxKey& rhs ) {
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

	bool CFSecServiceBuff::operator >( const CFSecServiceByTypeIdxKey& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator >( const CFSecServiceByUTypeIdxKey& rhs ) {
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
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator >( const CFSecServiceByUHostPortIdxKey& rhs ) {
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
		if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator >( const CFSecServicePKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator >( const CFSecServiceHPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator >( const CFSecServiceHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceBuff::operator >( const CFSecServiceBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	std::string CFSecServiceBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecServiceBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_ServiceId( "ServiceId" );
		static const std::string S_HostNodeId( "HostNodeId" );
		static const std::string S_ServiceTypeId( "ServiceTypeId" );
		static const std::string S_HostPort( "HostPort" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ServiceId, getRequiredServiceId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_CreatedBy, getCreatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_UpdatedBy, getUpdatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_HostNodeId, getRequiredHostNodeId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_ServiceTypeId, getRequiredServiceTypeId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_HostPort, getRequiredHostPort() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByHostIdxKey& rhs ) {
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

	bool operator <(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUTypeIdxKey& rhs ) {
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
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs ) {
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
		if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServicePKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByHostIdxKey& rhs ) {
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

	bool operator <=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUTypeIdxKey& rhs ) {
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
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs ) {
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
		if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServicePKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByHostIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUTypeIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		if( lhs.getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServicePKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( false );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		if( lhs.getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( false );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		if( lhs.getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByHostIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUTypeIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServicePKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByHostIdxKey& rhs ) {
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

	bool operator >=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUTypeIdxKey& rhs ) {
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
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs ) {
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
		if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServicePKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByHostIdxKey& rhs ) {
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

	bool operator >(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUTypeIdxKey& rhs ) {
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
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs ) {
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
		if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServicePKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecServiceBuff& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}
}

