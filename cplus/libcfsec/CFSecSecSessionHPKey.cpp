// Description: C++18 implementation of a SecSession history primary key object.

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

#include <cfsec/CFSecHPKey.hpp>
#include <cfsec/CFSecSecSessionPKey.hpp>
#include <cfsec/CFSecSecSessionHPKey.hpp>
#include <cfsec/CFSecSecSessionBuff.hpp>
#include <cfsec/CFSecSecSessionHBuff.hpp>

namespace cfsec {

	const std::string CFSecSecSessionHPKey::CLASS_NAME( "CFSecSecSessionHPKey" );
	const std::string CFSecSecSessionHPKey::S_VALUE( "value" );

	CFSecSecSessionHPKey::CFSecSecSessionHPKey()
	: CFSecHPKey()
	{
		for( int i = 0; i < 16; i ++ ) {
			requiredSecSessionId[i] = 0;
		}
	}

	CFSecSecSessionHPKey::CFSecSecSessionHPKey( const CFSecSecSessionHPKey& src )
	: CFSecHPKey()
	{
		for( int i = 0; i < 16; i ++ ) {
			requiredSecSessionId[i] = 0;
		}
		setRequiredSecSessionId( src.getRequiredSecSessionId() );
	}

	CFSecSecSessionHPKey::~CFSecSecSessionHPKey() {
		for( int i = 0; i < 16; i ++ ) {
			requiredSecSessionId[i] = 0;
		}
	}

	const uuid_ptr_t CFSecSecSessionHPKey::getRequiredSecSessionId() const {
		return( requiredSecSessionId );
	}

	const uuid_ptr_t CFSecSecSessionHPKey::getRequiredSecSessionIdReference() const {
		return( requiredSecSessionId );
	}

	void CFSecSecSessionHPKey::setRequiredSecSessionId( const uuid_ptr_t value ) {
		uuid_copy( requiredSecSessionId, value );
	}

	void CFSecSecSessionHPKey::generateRequiredSecSessionId() {
		uuid_generate_random( requiredSecSessionId );
	}

	size_t CFSecSecSessionHPKey::hashCode() const {
		size_t hashCode = CFSecHPKey::hashCode();
		hashCode = hashCode + cflib::CFLib::hash( getRequiredSecSessionId() );
		return( hashCode );
	}

	std::string CFSecSecSessionHPKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecHPKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_AuditClusterId( "AuditClusterId" );
		static const std::string S_AuditStamp( "AuditStamp" );
		static const std::string S_AuditActionId( "AuditActionId" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_AuditSessionId( "AuditSessionId" );
		static const std::string S_SecSessionId( "SecSessionId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_AuditClusterId, auditClusterId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_AuditClusterId, auditStamp ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_AuditActionId, auditActionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, requiredRevision ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_AuditSessionId, auditSessionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecSessionId, getRequiredSecSessionId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecSecSessionHPKey::operator <( const CFSecSecSessionPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionHPKey::operator <( const CFSecSecSessionHPKey& rhs ) {
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
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionHPKey::operator <( const CFSecSecSessionHBuff& rhs ) {
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
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionHPKey::operator <( const CFSecSecSessionBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionHPKey::operator <=( const CFSecSecSessionPKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionHPKey::operator <=( const CFSecSecSessionHPKey& rhs ) {
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
		if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionHPKey::operator <=( const CFSecSecSessionHBuff& rhs ) {
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
		if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionHPKey::operator <=( const CFSecSecSessionBuff& rhs ) {
		if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionHPKey::operator ==( const CFSecSecSessionPKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionHPKey::operator ==( const CFSecSecSessionHPKey& rhs ) {
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
		if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionHPKey::operator ==( const CFSecSecSessionHBuff& rhs ) {
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
		if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionHPKey::operator ==( const CFSecSecSessionBuff& rhs ) {
		if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionHPKey::operator !=( const CFSecSecSessionPKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionHPKey::operator !=( const CFSecSecSessionHPKey& rhs ) {
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
		if( 0 != uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionHPKey::operator !=( const CFSecSecSessionHBuff& rhs ) {
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
		if( 0 != uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionHPKey::operator !=( const CFSecSecSessionBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionHPKey::operator >=( const CFSecSecSessionPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionHPKey::operator >=( const CFSecSecSessionHPKey& rhs ) {
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
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionHPKey::operator >=( const CFSecSecSessionHBuff& rhs ) {
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
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionHPKey::operator >=( const CFSecSecSessionBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionHPKey::operator >( const CFSecSecSessionPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionHPKey::operator >( const CFSecSecSessionHPKey& rhs ) {
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
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionHPKey::operator >( const CFSecSecSessionHBuff& rhs ) {
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
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionHPKey::operator >( const CFSecSecSessionBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	CFSecSecSessionHPKey CFSecSecSessionHPKey::operator =( cfsec::CFSecSecSessionPKey& src ) {
		setRequiredSecSessionId( src.getRequiredSecSessionId() );
		return( *this );
	}

	CFSecSecSessionHPKey CFSecSecSessionHPKey::operator =( cfsec::CFSecSecSessionHPKey& src ) {
		setRequiredSecSessionId( src.getRequiredSecSessionId() );
		return( *this );
	}

	CFSecSecSessionHPKey CFSecSecSessionHPKey::operator =( cfsec::CFSecSecSessionBuff& src ) {
		setRequiredSecSessionId( src.getRequiredSecSessionId() );
		return( *this );
	}

	CFSecSecSessionHPKey CFSecSecSessionHPKey::operator =( cfsec::CFSecSecSessionHBuff& src ) {
		setRequiredSecSessionId( src.getRequiredSecSessionId() );
		return( *this );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionHPKey& rhs ) {
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
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
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
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionHPKey& rhs ) {
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
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
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
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionPKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionHPKey& rhs ) {
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
		if( 0 != uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
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
		if( 0 != uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionPKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionHPKey& rhs ) {
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
		if( 0 != uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
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
		if( 0 != uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionPKey& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionHPKey& rhs ) {
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
		if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
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
		if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionHPKey& rhs ) {
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
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
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
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecSessionHPKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecSessionId(), rhs.getRequiredSecSessionId() ) ) {
			return( true );
		}
		return( false );
	}
}

