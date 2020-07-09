// Description: C++18 implementation of a ISOCtryCcy history primary key object.

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
#include <cfsec/CFSecISOCtryCcyPKey.hpp>
#include <cfsec/CFSecISOCtryCcyHPKey.hpp>
#include <cfsec/CFSecISOCtryCcyBuff.hpp>
#include <cfsec/CFSecISOCtryCcyHBuff.hpp>

namespace cfsec {

	const std::string CFSecISOCtryCcyHPKey::CLASS_NAME( "CFSecISOCtryCcyHPKey" );
	const std::string CFSecISOCtryCcyHPKey::S_VALUE( "value" );

	CFSecISOCtryCcyHPKey::CFSecISOCtryCcyHPKey()
	: CFSecHPKey()
	{
		requiredISOCtryId = cfsec::CFSecISOCtryCcyBuff::ISOCTRYID_INIT_VALUE;
		requiredISOCcyId = cfsec::CFSecISOCtryCcyBuff::ISOCCYID_INIT_VALUE;
	}

	CFSecISOCtryCcyHPKey::CFSecISOCtryCcyHPKey( const CFSecISOCtryCcyHPKey& src )
	: CFSecHPKey()
	{
		requiredISOCtryId = cfsec::CFSecISOCtryCcyBuff::ISOCTRYID_INIT_VALUE;
		requiredISOCcyId = cfsec::CFSecISOCtryCcyBuff::ISOCCYID_INIT_VALUE;
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setRequiredISOCcyId( src.getRequiredISOCcyId() );
	}

	CFSecISOCtryCcyHPKey::~CFSecISOCtryCcyHPKey() {
	}

	const int16_t CFSecISOCtryCcyHPKey::getRequiredISOCtryId() const {
		return( requiredISOCtryId );
	}

	const int16_t* CFSecISOCtryCcyHPKey::getRequiredISOCtryIdReference() const {
		return( &requiredISOCtryId );
	}

	void CFSecISOCtryCcyHPKey::setRequiredISOCtryId( const int16_t value ) {
		static const std::string S_ProcName( "setRequiredISOCtryId" );
		if( value < cfsec::CFSecISOCtryCcyBuff::ISOCTRYID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOCtryCcyBuff::ISOCTRYID_MIN_VALUE );
		}
		requiredISOCtryId = value;
	}

	const int16_t CFSecISOCtryCcyHPKey::getRequiredISOCcyId() const {
		return( requiredISOCcyId );
	}

	const int16_t* CFSecISOCtryCcyHPKey::getRequiredISOCcyIdReference() const {
		return( &requiredISOCcyId );
	}

	void CFSecISOCtryCcyHPKey::setRequiredISOCcyId( const int16_t value ) {
		static const std::string S_ProcName( "setRequiredISOCcyId" );
		if( value < cfsec::CFSecISOCtryCcyBuff::ISOCCYID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOCtryCcyBuff::ISOCCYID_MIN_VALUE );
		}
		requiredISOCcyId = value;
	}

	size_t CFSecISOCtryCcyHPKey::hashCode() const {
		size_t hashCode = CFSecHPKey::hashCode();
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOCtryId();
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOCcyId();
		return( hashCode );
	}

	std::string CFSecISOCtryCcyHPKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecHPKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_AuditClusterId( "AuditClusterId" );
		static const std::string S_AuditStamp( "AuditStamp" );
		static const std::string S_AuditActionId( "AuditActionId" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_AuditSessionId( "AuditSessionId" );
		static const std::string S_ISOCtryId( "ISOCtryId" );
		static const std::string S_ISOCcyId( "ISOCcyId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_AuditClusterId, auditClusterId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_AuditClusterId, auditStamp ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_AuditActionId, auditActionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, requiredRevision ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_AuditSessionId, auditSessionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCtryId, getRequiredISOCtryId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCcyId, getRequiredISOCcyId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecISOCtryCcyHPKey::operator <( const CFSecISOCtryCcyPKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyHPKey::operator <( const CFSecISOCtryCcyHPKey& rhs ) {
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
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyHPKey::operator <( const CFSecISOCtryCcyHBuff& rhs ) {
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
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyHPKey::operator <( const CFSecISOCtryCcyBuff& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyHPKey::operator <=( const CFSecISOCtryCcyPKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyHPKey::operator <=( const CFSecISOCtryCcyHPKey& rhs ) {
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
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyHPKey::operator <=( const CFSecISOCtryCcyHBuff& rhs ) {
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
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyHPKey::operator <=( const CFSecISOCtryCcyBuff& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyHPKey::operator ==( const CFSecISOCtryCcyPKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyHPKey::operator ==( const CFSecISOCtryCcyHPKey& rhs ) {
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
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyHPKey::operator ==( const CFSecISOCtryCcyHBuff& rhs ) {
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
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyHPKey::operator ==( const CFSecISOCtryCcyBuff& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyHPKey::operator !=( const CFSecISOCtryCcyPKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyHPKey::operator !=( const CFSecISOCtryCcyHPKey& rhs ) {
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
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyHPKey::operator !=( const CFSecISOCtryCcyHBuff& rhs ) {
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
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyHPKey::operator !=( const CFSecISOCtryCcyBuff& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyHPKey::operator >=( const CFSecISOCtryCcyPKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyHPKey::operator >=( const CFSecISOCtryCcyHPKey& rhs ) {
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
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyHPKey::operator >=( const CFSecISOCtryCcyHBuff& rhs ) {
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
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyHPKey::operator >=( const CFSecISOCtryCcyBuff& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyHPKey::operator >( const CFSecISOCtryCcyPKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyHPKey::operator >( const CFSecISOCtryCcyHPKey& rhs ) {
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
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyHPKey::operator >( const CFSecISOCtryCcyHBuff& rhs ) {
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
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyHPKey::operator >( const CFSecISOCtryCcyBuff& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	CFSecISOCtryCcyHPKey CFSecISOCtryCcyHPKey::operator =( cfsec::CFSecISOCtryCcyPKey& src ) {
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setRequiredISOCcyId( src.getRequiredISOCcyId() );
		return( *this );
	}

	CFSecISOCtryCcyHPKey CFSecISOCtryCcyHPKey::operator =( cfsec::CFSecISOCtryCcyHPKey& src ) {
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setRequiredISOCcyId( src.getRequiredISOCcyId() );
		return( *this );
	}

	CFSecISOCtryCcyHPKey CFSecISOCtryCcyHPKey::operator =( cfsec::CFSecISOCtryCcyBuff& src ) {
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setRequiredISOCcyId( src.getRequiredISOCcyId() );
		return( *this );
	}

	CFSecISOCtryCcyHPKey CFSecISOCtryCcyHPKey::operator =( cfsec::CFSecISOCtryCcyHBuff& src ) {
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setRequiredISOCcyId( src.getRequiredISOCcyId() );
		return( *this );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs ) {
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
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
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
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs ) {
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
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
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
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs ) {
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
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
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
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs ) {
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
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
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
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs ) {
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
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
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
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs ) {
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
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
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
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryCcyHPKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}
}

