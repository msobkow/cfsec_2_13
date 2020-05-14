// Description: C++18 implementation for a ServiceType buffer object.

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

#include <cfsec/CFSecServiceTypeByUDescrIdxKey.hpp>
#include <cfsec/CFSecSchema.hpp>

namespace cfsec {

	const std::string CFSecServiceTypeBuff::S_VALUE( "value" );
	const std::string CFSecServiceTypeBuff::S_VALUE_LENGTH( "value.length()" );

	const std::string CFSecServiceTypeBuff::GENDEFNAME( "ServiceType" );
	const classcode_t CFSecServiceTypeBuff::CLASS_CODE = 0xa013L;
	const std::string CFSecServiceTypeBuff::CLASS_NAME( "CFSecServiceTypeBuff" );
		const std::string CFSecServiceTypeBuff::COLNAME_SERVICETYPEID( "ServiceTypeId" );
		const std::string CFSecServiceTypeBuff::COLNAME_DESCRIPTION( "Description" );
	const char* CFSecServiceTypeBuff::S_INIT_CREATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const char* CFSecServiceTypeBuff::S_INIT_UPDATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const int CFSecServiceTypeBuff::SERVICETYPEID_INIT_VALUE = 0L;
	const std::string CFSecServiceTypeBuff::DESCRIPTION_INIT_VALUE( "" );
	const int CFSecServiceTypeBuff::SERVICETYPEID_MIN_VALUE = 0L;
	const std::string::size_type CFSecServiceTypeBuff::DESCRIPTION_MAX_LEN = 50;

	CFSecServiceTypeBuff::CFSecServiceTypeBuff()
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
		requiredServiceTypeId = cfsec::CFSecServiceTypeBuff::SERVICETYPEID_INIT_VALUE;
		requiredDescription = new std::string( cfsec::CFSecServiceTypeBuff::DESCRIPTION_INIT_VALUE );
	}

	CFSecServiceTypeBuff::CFSecServiceTypeBuff( const CFSecServiceTypeBuff& src )
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
		requiredServiceTypeId = cfsec::CFSecServiceTypeBuff::SERVICETYPEID_INIT_VALUE;
		requiredDescription = new std::string( cfsec::CFSecServiceTypeBuff::DESCRIPTION_INIT_VALUE );
		setRequiredServiceTypeId( src.getRequiredServiceTypeId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredDescription( src.getRequiredDescription() );
	}

	CFSecServiceTypeBuff::~CFSecServiceTypeBuff() {
		if( requiredDescription != NULL ) {
			delete requiredDescription;
			requiredDescription = NULL;
		}
		for( int i = 0; i < 16; i++ ) {
			createdByUserId[i] = 0;
		}
		for( int i = 0; i < 16; i++ ) {
			updatedByUserId[i] = 0;
		}
	}

	cflib::ICFLibCloneableObj* CFSecServiceTypeBuff::clone() {
		CFSecServiceTypeBuff* copy = new CFSecServiceTypeBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const std::string& CFSecServiceTypeBuff::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecServiceTypeBuff::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecServiceTypeBuff::implementsClassCode( const classcode_t argClassCode ) {
		if( argClassCode == CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	const uuid_ptr_t CFSecServiceTypeBuff::getCreatedByUserId() const {
		return( createdByUserId );
	}

	void CFSecServiceTypeBuff::setCreatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( createdByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecServiceTypeBuff::getCreatedAt() const {
		return( createdAt );
	}

	void CFSecServiceTypeBuff::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		createdAt = value;
	}

	const uuid_ptr_t CFSecServiceTypeBuff::getUpdatedByUserId() const {
		return( updatedByUserId );
	}

	void CFSecServiceTypeBuff::setUpdatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( updatedByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFSecServiceTypeBuff::getUpdatedAt() const {
		return( updatedAt );
	}

	void CFSecServiceTypeBuff::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		updatedAt = value;
	}
	const int32_t CFSecServiceTypeBuff::getRequiredServiceTypeId() const {
		return( requiredServiceTypeId );
	}

	const int32_t* CFSecServiceTypeBuff::getRequiredServiceTypeIdReference() const {
		return( &requiredServiceTypeId );
	}

	void CFSecServiceTypeBuff::setRequiredServiceTypeId( const int32_t value ) {
		static const std::string S_ProcName( "setRequiredServiceTypeId" );
		if( value < cfsec::CFSecServiceTypeBuff::SERVICETYPEID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecServiceTypeBuff::SERVICETYPEID_MIN_VALUE );
		}
		requiredServiceTypeId = value;
	}

	const std::string& CFSecServiceTypeBuff::getRequiredDescription() const {
		return( *requiredDescription );
	}

	const std::string* CFSecServiceTypeBuff::getRequiredDescriptionReference() const {
		return( requiredDescription );
	}

	void CFSecServiceTypeBuff::setRequiredDescription( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredDescription" );
		if( value.length() > CFSecServiceTypeBuff::DESCRIPTION_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecServiceTypeBuff::DESCRIPTION_MAX_LEN );
		}
		if( requiredDescription != NULL ) {
			delete requiredDescription;
			requiredDescription = NULL;
		}
		requiredDescription = new std::string( value );
	}

	int32_t CFSecServiceTypeBuff::getRequiredRevision() const {
		return( requiredRevision );
	}

	void CFSecServiceTypeBuff::setRequiredRevision( int32_t value ) {
		requiredRevision = value;
	}

	size_t CFSecServiceTypeBuff::hashCode() const {
		size_t hashCode = 0L;
		hashCode = hashCode + getRequiredServiceTypeId();
		hashCode = hashCode + cflib::CFLib::hash( getRequiredDescription() );
		return( hashCode );
	}

	CFSecServiceTypeBuff CFSecServiceTypeBuff::operator =( cfsec::CFSecServiceTypeBuff& src ) {
		setRequiredServiceTypeId( src.getRequiredServiceTypeId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredDescription( src.getRequiredDescription() );
		return( *this );
	}

	CFSecServiceTypeBuff CFSecServiceTypeBuff::operator =( cfsec::CFSecServiceTypeHBuff& src ) {
		setRequiredServiceTypeId( src.getRequiredServiceTypeId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredDescription( src.getRequiredDescription() );
		return( *this );
	}

	bool CFSecServiceTypeBuff::operator <( const CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypeBuff::operator <( const CFSecServiceTypePKey& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypeBuff::operator <( const CFSecServiceTypeHPKey& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypeBuff::operator <( const CFSecServiceTypeHBuff& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
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

	bool CFSecServiceTypeBuff::operator <( const CFSecServiceTypeBuff& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
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

	bool CFSecServiceTypeBuff::operator <=( const CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceTypeBuff::operator <=( const CFSecServiceTypePKey& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceTypeBuff::operator <=( const CFSecServiceTypeHPKey& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceTypeBuff::operator <=( const CFSecServiceTypeHBuff& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
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

	bool CFSecServiceTypeBuff::operator <=( const CFSecServiceTypeBuff& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
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

	bool CFSecServiceTypeBuff::operator ==( const CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceTypeBuff::operator ==( const CFSecServiceTypePKey& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceTypeBuff::operator ==( const CFSecServiceTypeHPKey& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceTypeBuff::operator ==( const CFSecServiceTypeHBuff& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceTypeBuff::operator ==( const CFSecServiceTypeBuff& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceTypeBuff::operator !=( const CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypeBuff::operator !=( const CFSecServiceTypePKey& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypeBuff::operator !=( const CFSecServiceTypeHPKey& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypeBuff::operator !=( const CFSecServiceTypeHBuff& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypeBuff::operator !=( const CFSecServiceTypeBuff& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypeBuff::operator >=( const CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceTypeBuff::operator >=( const CFSecServiceTypePKey& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceTypeBuff::operator >=( const CFSecServiceTypeHPKey& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceTypeBuff::operator >=( const CFSecServiceTypeHBuff& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
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

	bool CFSecServiceTypeBuff::operator >=( const CFSecServiceTypeBuff& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
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

	bool CFSecServiceTypeBuff::operator >( const CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypeBuff::operator >( const CFSecServiceTypePKey& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypeBuff::operator >( const CFSecServiceTypeHPKey& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypeBuff::operator >( const CFSecServiceTypeHBuff& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
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

	bool CFSecServiceTypeBuff::operator >( const CFSecServiceTypeBuff& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
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

	std::string CFSecServiceTypeBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecServiceTypeBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ServiceTypeId( "ServiceTypeId" );
		static const std::string S_Description( "Description" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_ServiceTypeId, getRequiredServiceTypeId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_CreatedBy, getCreatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_UpdatedBy, getUpdatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, getRequiredDescription() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypePKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeHPKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeHBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypePKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeHPKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeHBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
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

	bool operator <=(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
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

	bool operator ==(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypePKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeHPKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeHBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypePKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeHPKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeHBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypePKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeHPKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeHBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
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

	bool operator >=(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
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

	bool operator >(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypePKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeHPKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeHBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
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

	bool operator >(const  cfsec::CFSecServiceTypeBuff& lhs, const cfsec::CFSecServiceTypeBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
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
}
