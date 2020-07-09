// Description: C++18 implementation of a ISOTZone history primary key object.

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
#include <cfsec/CFSecISOTZonePKey.hpp>
#include <cfsec/CFSecISOTZoneHPKey.hpp>
#include <cfsec/CFSecISOTZoneBuff.hpp>
#include <cfsec/CFSecISOTZoneHBuff.hpp>

namespace cfsec {

	const std::string CFSecISOTZoneHPKey::CLASS_NAME( "CFSecISOTZoneHPKey" );
	const std::string CFSecISOTZoneHPKey::S_VALUE( "value" );

	CFSecISOTZoneHPKey::CFSecISOTZoneHPKey()
	: CFSecHPKey()
	{
		requiredISOTZoneId = cfsec::CFSecISOTZoneBuff::ISOTZONEID_INIT_VALUE;
	}

	CFSecISOTZoneHPKey::CFSecISOTZoneHPKey( const CFSecISOTZoneHPKey& src )
	: CFSecHPKey()
	{
		requiredISOTZoneId = cfsec::CFSecISOTZoneBuff::ISOTZONEID_INIT_VALUE;
		setRequiredISOTZoneId( src.getRequiredISOTZoneId() );
	}

	CFSecISOTZoneHPKey::~CFSecISOTZoneHPKey() {
	}

	const int16_t CFSecISOTZoneHPKey::getRequiredISOTZoneId() const {
		return( requiredISOTZoneId );
	}

	const int16_t* CFSecISOTZoneHPKey::getRequiredISOTZoneIdReference() const {
		return( &requiredISOTZoneId );
	}

	void CFSecISOTZoneHPKey::setRequiredISOTZoneId( const int16_t value ) {
		static const std::string S_ProcName( "setRequiredISOTZoneId" );
		if( value < cfsec::CFSecISOTZoneBuff::ISOTZONEID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOTZoneBuff::ISOTZONEID_MIN_VALUE );
		}
		requiredISOTZoneId = value;
	}

	size_t CFSecISOTZoneHPKey::hashCode() const {
		size_t hashCode = CFSecHPKey::hashCode();
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOTZoneId();
		return( hashCode );
	}

	std::string CFSecISOTZoneHPKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecHPKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_AuditClusterId( "AuditClusterId" );
		static const std::string S_AuditStamp( "AuditStamp" );
		static const std::string S_AuditActionId( "AuditActionId" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_AuditSessionId( "AuditSessionId" );
		static const std::string S_ISOTZoneId( "ISOTZoneId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_AuditClusterId, auditClusterId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_AuditClusterId, auditStamp ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_AuditActionId, auditActionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, requiredRevision ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_AuditSessionId, auditSessionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOTZoneId, getRequiredISOTZoneId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecISOTZoneHPKey::operator <( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHPKey::operator <( const CFSecISOTZoneHPKey& rhs ) {
		if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() >= rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() <= rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() >= rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() <= rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHPKey::operator <( const CFSecISOTZoneHBuff& rhs ) {
		if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() >= rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() <= rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() >= rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() <= rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHPKey::operator <( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHPKey::operator <=( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHPKey::operator <=( const CFSecISOTZoneHPKey& rhs ) {
		if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHPKey::operator <=( const CFSecISOTZoneHBuff& rhs ) {
		if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHPKey::operator <=( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHPKey::operator ==( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHPKey::operator ==( const CFSecISOTZoneHPKey& rhs ) {
		if( getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHPKey::operator ==( const CFSecISOTZoneHBuff& rhs ) {
		if( getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHPKey::operator ==( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHPKey::operator !=( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHPKey::operator !=( const CFSecISOTZoneHPKey& rhs ) {
		if( getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() != rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() != rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( true );
			}
		}
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHPKey::operator !=( const CFSecISOTZoneHBuff& rhs ) {
		if( getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() != rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() != rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( true );
			}
		}
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHPKey::operator !=( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHPKey::operator >=( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHPKey::operator >=( const CFSecISOTZoneHPKey& rhs ) {
		if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHPKey::operator >=( const CFSecISOTZoneHBuff& rhs ) {
		if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHPKey::operator >=( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHPKey::operator >( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHPKey::operator >( const CFSecISOTZoneHPKey& rhs ) {
		if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHPKey::operator >( const CFSecISOTZoneHBuff& rhs ) {
		if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHPKey::operator >( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	CFSecISOTZoneHPKey CFSecISOTZoneHPKey::operator =( cfsec::CFSecISOTZonePKey& src ) {
		setRequiredISOTZoneId( src.getRequiredISOTZoneId() );
		return( *this );
	}

	CFSecISOTZoneHPKey CFSecISOTZoneHPKey::operator =( cfsec::CFSecISOTZoneHPKey& src ) {
		setRequiredISOTZoneId( src.getRequiredISOTZoneId() );
		return( *this );
	}

	CFSecISOTZoneHPKey CFSecISOTZoneHPKey::operator =( cfsec::CFSecISOTZoneBuff& src ) {
		setRequiredISOTZoneId( src.getRequiredISOTZoneId() );
		return( *this );
	}

	CFSecISOTZoneHPKey CFSecISOTZoneHPKey::operator =( cfsec::CFSecISOTZoneHBuff& src ) {
		setRequiredISOTZoneId( src.getRequiredISOTZoneId() );
		return( *this );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
		if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( true );
			}
		}
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( true );
			}
		}
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
		if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
		if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOTZoneHPKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}
}

