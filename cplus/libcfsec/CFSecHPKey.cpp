// Description: C++18 implementation of a generic CFSec history primary key base object.

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
