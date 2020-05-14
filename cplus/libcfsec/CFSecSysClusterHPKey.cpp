// Description: C++18 implementation of a SysCluster history primary key object.

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
#include <cfsec/CFSecSysClusterPKey.hpp>
#include <cfsec/CFSecSysClusterHPKey.hpp>
#include <cfsec/CFSecSysClusterBuff.hpp>
#include <cfsec/CFSecSysClusterHBuff.hpp>

namespace cfsec {

	const std::string CFSecSysClusterHPKey::CLASS_NAME( "CFSecSysClusterHPKey" );
	const std::string CFSecSysClusterHPKey::S_VALUE( "value" );

	CFSecSysClusterHPKey::CFSecSysClusterHPKey()
	: CFSecHPKey()
	{
		requiredSingletonId = cfsec::CFSecSysClusterBuff::SINGLETONID_INIT_VALUE;
	}

	CFSecSysClusterHPKey::CFSecSysClusterHPKey( const CFSecSysClusterHPKey& src )
	: CFSecHPKey()
	{
		requiredSingletonId = cfsec::CFSecSysClusterBuff::SINGLETONID_INIT_VALUE;
		setRequiredSingletonId( src.getRequiredSingletonId() );
	}

	CFSecSysClusterHPKey::~CFSecSysClusterHPKey() {
	}

	const int32_t CFSecSysClusterHPKey::getRequiredSingletonId() const {
		return( requiredSingletonId );
	}

	const int32_t* CFSecSysClusterHPKey::getRequiredSingletonIdReference() const {
		return( &requiredSingletonId );
	}

	void CFSecSysClusterHPKey::setRequiredSingletonId( const int32_t value ) {
		static const std::string S_ProcName( "setRequiredSingletonId" );
		if( value < cfsec::CFSecSysClusterBuff::SINGLETONID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecSysClusterBuff::SINGLETONID_MIN_VALUE );
		}
		if( value > cfsec::CFSecSysClusterBuff::SINGLETONID_MAX_VALUE ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecSysClusterBuff::SINGLETONID_MAX_VALUE );
		}
		requiredSingletonId = value;
	}

	size_t CFSecSysClusterHPKey::hashCode() const {
		size_t hashCode = CFSecHPKey::hashCode();
		hashCode = hashCode + getRequiredSingletonId();
		return( hashCode );
	}

	std::string CFSecSysClusterHPKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecHPKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_AuditClusterId( "AuditClusterId" );
		static const std::string S_AuditStamp( "AuditStamp" );
		static const std::string S_AuditActionId( "AuditActionId" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_AuditSessionId( "AuditSessionId" );
		static const std::string S_SingletonId( "SingletonId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_AuditClusterId, auditClusterId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_AuditClusterId, auditStamp ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_AuditActionId, auditActionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, requiredRevision ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_AuditSessionId, auditSessionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SingletonId, getRequiredSingletonId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecSysClusterHPKey::operator <( const CFSecSysClusterPKey& rhs ) {
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterHPKey::operator <( const CFSecSysClusterHPKey& rhs ) {
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
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterHPKey::operator <( const CFSecSysClusterHBuff& rhs ) {
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
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterHPKey::operator <( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterHPKey::operator <=( const CFSecSysClusterPKey& rhs ) {
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterHPKey::operator <=( const CFSecSysClusterHPKey& rhs ) {
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
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterHPKey::operator <=( const CFSecSysClusterHBuff& rhs ) {
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
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterHPKey::operator <=( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterHPKey::operator ==( const CFSecSysClusterPKey& rhs ) {
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterHPKey::operator ==( const CFSecSysClusterHPKey& rhs ) {
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
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterHPKey::operator ==( const CFSecSysClusterHBuff& rhs ) {
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
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterHPKey::operator ==( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterHPKey::operator !=( const CFSecSysClusterPKey& rhs ) {
		if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterHPKey::operator !=( const CFSecSysClusterHPKey& rhs ) {
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
		if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterHPKey::operator !=( const CFSecSysClusterHBuff& rhs ) {
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
		if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterHPKey::operator !=( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterHPKey::operator >=( const CFSecSysClusterPKey& rhs ) {
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterHPKey::operator >=( const CFSecSysClusterHPKey& rhs ) {
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
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterHPKey::operator >=( const CFSecSysClusterHBuff& rhs ) {
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
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterHPKey::operator >=( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterHPKey::operator >( const CFSecSysClusterPKey& rhs ) {
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterHPKey::operator >( const CFSecSysClusterHPKey& rhs ) {
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
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterHPKey::operator >( const CFSecSysClusterHBuff& rhs ) {
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
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterHPKey::operator >( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	CFSecSysClusterHPKey CFSecSysClusterHPKey::operator =( cfsec::CFSecSysClusterPKey& src ) {
		setRequiredSingletonId( src.getRequiredSingletonId() );
		return( *this );
	}

	CFSecSysClusterHPKey CFSecSysClusterHPKey::operator =( cfsec::CFSecSysClusterHPKey& src ) {
		setRequiredSingletonId( src.getRequiredSingletonId() );
		return( *this );
	}

	CFSecSysClusterHPKey CFSecSysClusterHPKey::operator =( cfsec::CFSecSysClusterBuff& src ) {
		setRequiredSingletonId( src.getRequiredSingletonId() );
		return( *this );
	}

	CFSecSysClusterHPKey CFSecSysClusterHPKey::operator =( cfsec::CFSecSysClusterHBuff& src ) {
		setRequiredSingletonId( src.getRequiredSingletonId() );
		return( *this );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterPKey& rhs ) {
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterHPKey& rhs ) {
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
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
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
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterPKey& rhs ) {
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterHPKey& rhs ) {
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
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
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
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterPKey& rhs ) {
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterHPKey& rhs ) {
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
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
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
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterPKey& rhs ) {
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterHPKey& rhs ) {
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
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
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
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterPKey& rhs ) {
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterHPKey& rhs ) {
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
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
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
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterPKey& rhs ) {
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterHPKey& rhs ) {
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
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
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
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSysClusterHPKey& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}
}

