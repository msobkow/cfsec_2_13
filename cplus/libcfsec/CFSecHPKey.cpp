// Description: C++18 implementation of a generic CFSec history primary key base object.

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

#include <cfsec/CFSecHPKey.hpp>

namespace cfsec {
		const std::string CFSecHPKey::CLASS_NAME( "CFSecHPKey" );

		const std::string CFSecHPKey::S_VALUE( "value" );
		const std::string CFSecHPKey::S_VALUE_LENGTH( "value.length()" );

		CFSecHPKey::CFSecHPKey() {
			auditClusterId = 0L;
			auditActionId = 0;
			requiredRevision = 1;
			for( int i = 0; i < 16; i++ ) {
				auditSessionId[i] = 0;
			}
		}

		CFSecHPKey::~CFSecHPKey() {
			for( int i = 0; i < 16; i++ ) {
				auditSessionId[i] = 0;
			}
		}

		int64_t CFSecHPKey::getAuditClusterId() const {
			return( auditClusterId );
		}

		void CFSecHPKey::setAuditClusterId( int64_t value ) {
			auditClusterId = value;
		}

		const std::chrono::system_clock::time_point& CFSecHPKey::getAuditStamp() const {
			return( auditStamp );
		}

		void CFSecHPKey::setAuditStamp( const std::chrono::system_clock::time_point& value ) {
			auditStamp = value;
		}

		int16_t CFSecHPKey::getAuditActionId() const {
			return( auditActionId );
		}

		void CFSecHPKey::setAuditActionId( int16_t value ) {
			auditActionId = value;
		}

		int32_t CFSecHPKey::getRequiredRevision() const {
			return( requiredRevision );
		}

		void CFSecHPKey::setRequiredRevision( int32_t value ) {
			requiredRevision = value;
		}

		const uuid_ptr_t CFSecHPKey::getAuditSessionId() const {
			return( auditSessionId );
		}

		void CFSecHPKey::setAuditSessionId( const uuid_ptr_t value ) {
			uuid_copy( auditSessionId, value );
		}

		size_t CFSecHPKey::hashCode() const {
			size_t hashCode = 0;
			hashCode = hashCode + (int)( auditClusterId & 0x7fffffff );
			hashCode = hashCode + cflib::CFLib::hash( auditStamp );
			hashCode = hashCode + auditActionId;
			hashCode = hashCode + requiredRevision;
			hashCode = hashCode + cflib::CFLib::hash( auditSessionId );
			return( hashCode );
		}

		std::string CFSecHPKey::toString() {
			static const std::string S_Space( " " );
			static const std::string S_Preamble( "<CFSecHPKey" );
			static const std::string S_Postamble( "/>" );
			static const std::string S_AuditClusterId( "AuditClusterId" );
			static const std::string S_AuditStamp( "AuditStamp" );
			static const std::string S_AuditActionId( "AuditActionId" );
			static const std::string S_Revision( "Revision" );
			static const std::string S_AuditSessionId( "AuditSessionId" );
			std::string ret( S_Preamble );
			ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_AuditClusterId, auditClusterId ) );
			ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_AuditClusterId, auditStamp ) );
			ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_AuditActionId, auditActionId ) );
			ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, requiredRevision ) );
			ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_AuditSessionId, auditSessionId ) );
			ret.append( S_Postamble );
			return( ret );
		}

		const std::string& CFSecHPKey::getClassName() const {
			return( CLASS_NAME );
		}

		const classcode_t CFSecHPKey::getClassCode() const {
			return( classCode );
		}

		void CFSecHPKey::setClassCode( const classcode_t value ) {
			classCode = value;
		}

}
