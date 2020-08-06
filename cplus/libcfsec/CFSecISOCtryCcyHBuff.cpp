// Description: C++18 implementation of a ISOCtryCcy history buffer object.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <cflib/ICFLibPublic.hpp>

using namespace std;

#include <cfsec/CFSecHPKey.hpp>
#include <cfsec/CFSecISOCtryCcyPKey.hpp>
#include <cfsec/CFSecISOCtryCcyBuff.hpp>
#include <cfsec/CFSecISOCtryCcyHPKey.hpp>
#include <cfsec/CFSecISOCtryCcyHBuff.hpp>
#include <cfsec/CFSecISOCtryCcyByCtryIdxKey.hpp>
#include <cfsec/CFSecISOCtryCcyByCcyIdxKey.hpp>

namespace cfsec {

	const std::string CFSecISOCtryCcyHBuff::CLASS_NAME( "CFSecISOCtryCcyHBuff" );
	CFSecISOCtryCcyHBuff::CFSecISOCtryCcyHBuff()
	: CFSecHPKey(), cflib::ICFLibCloneableObj() {
		requiredISOCtryId = cfsec::CFSecISOCtryCcyBuff::ISOCTRYID_INIT_VALUE;
		requiredISOCcyId = cfsec::CFSecISOCtryCcyBuff::ISOCCYID_INIT_VALUE;
	}

	CFSecISOCtryCcyHBuff::CFSecISOCtryCcyHBuff( const CFSecISOCtryCcyHBuff& src )
	: CFSecHPKey(), cflib::ICFLibCloneableObj() {
		requiredISOCtryId = cfsec::CFSecISOCtryCcyBuff::ISOCTRYID_INIT_VALUE;
		requiredISOCcyId = cfsec::CFSecISOCtryCcyBuff::ISOCCYID_INIT_VALUE;
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setRequiredISOCcyId( src.getRequiredISOCcyId() );
		setRequiredRevision( src.getRequiredRevision() );
	}

	CFSecISOCtryCcyHBuff::~CFSecISOCtryCcyHBuff() {
	}

	cflib::ICFLibCloneableObj* CFSecISOCtryCcyHBuff::clone() {
		CFSecISOCtryCcyHBuff* copy = new CFSecISOCtryCcyHBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const int16_t CFSecISOCtryCcyHBuff::getRequiredISOCtryId() const {
		return( requiredISOCtryId );
	}

	const int16_t* CFSecISOCtryCcyHBuff::getRequiredISOCtryIdReference() const {
		return( &requiredISOCtryId );
	}

	void CFSecISOCtryCcyHBuff::setRequiredISOCtryId( const int16_t value ) {
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

	const int16_t CFSecISOCtryCcyHBuff::getRequiredISOCcyId() const {
		return( requiredISOCcyId );
	}

	const int16_t* CFSecISOCtryCcyHBuff::getRequiredISOCcyIdReference() const {
		return( &requiredISOCcyId );
	}

	void CFSecISOCtryCcyHBuff::setRequiredISOCcyId( const int16_t value ) {
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

	size_t CFSecISOCtryCcyHBuff::hashCode() const {
		size_t hashCode = CFSecHPKey::hashCode();
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOCtryId();
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOCcyId();
		return( hashCode );
	}

	CFSecISOCtryCcyHBuff CFSecISOCtryCcyHBuff::operator =( cfsec::CFSecISOCtryCcyBuff& src ) {
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setRequiredISOCcyId( src.getRequiredISOCcyId() );
		setRequiredRevision( src.getRequiredRevision() );
		return( *this );
	}

	CFSecISOCtryCcyHBuff CFSecISOCtryCcyHBuff::operator =( cfsec::CFSecISOCtryCcyHBuff& src ) {
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setRequiredISOCcyId( src.getRequiredISOCcyId() );
		setRequiredRevision( src.getRequiredRevision() );
		return( *this );
	}

	bool CFSecISOCtryCcyHBuff::operator <( const CFSecISOCtryCcyByCtryIdxKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyHBuff::operator <( const CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyHBuff::operator <( const CFSecISOCtryCcyPKey& rhs ) {
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

	bool CFSecISOCtryCcyHBuff::operator <( const CFSecISOCtryCcyHPKey& rhs ) {
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

	bool CFSecISOCtryCcyHBuff::operator <( const CFSecISOCtryCcyHBuff& rhs ) {
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

	bool CFSecISOCtryCcyHBuff::operator <( const CFSecISOCtryCcyBuff& rhs ) {
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

	bool CFSecISOCtryCcyHBuff::operator <=( const CFSecISOCtryCcyByCtryIdxKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyHBuff::operator <=( const CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyHBuff::operator <=( const CFSecISOCtryCcyPKey& rhs ) {
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

	bool CFSecISOCtryCcyHBuff::operator <=( const CFSecISOCtryCcyHPKey& rhs ) {
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

	bool CFSecISOCtryCcyHBuff::operator <=( const CFSecISOCtryCcyHBuff& rhs ) {
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

	bool CFSecISOCtryCcyHBuff::operator <=( const CFSecISOCtryCcyBuff& rhs ) {
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

	bool CFSecISOCtryCcyHBuff::operator ==( const CFSecISOCtryCcyByCtryIdxKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryCcyHBuff::operator ==( const CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryCcyHBuff::operator ==( const CFSecISOCtryCcyPKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryCcyHBuff::operator ==( const CFSecISOCtryCcyHPKey& rhs ) {
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
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryCcyHBuff::operator ==( const CFSecISOCtryCcyHBuff& rhs ) {
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
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryCcyHBuff::operator ==( const CFSecISOCtryCcyBuff& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryCcyHBuff::operator !=( const CFSecISOCtryCcyByCtryIdxKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyHBuff::operator !=( const CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyHBuff::operator !=( const CFSecISOCtryCcyPKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyHBuff::operator !=( const CFSecISOCtryCcyHPKey& rhs ) {
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

	bool CFSecISOCtryCcyHBuff::operator !=( const CFSecISOCtryCcyHBuff& rhs ) {
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

	bool CFSecISOCtryCcyHBuff::operator !=( const CFSecISOCtryCcyBuff& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyHBuff::operator >=( const CFSecISOCtryCcyByCtryIdxKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyHBuff::operator >=( const CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyHBuff::operator >=( const CFSecISOCtryCcyPKey& rhs ) {
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

	bool CFSecISOCtryCcyHBuff::operator >=( const CFSecISOCtryCcyHPKey& rhs ) {
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

	bool CFSecISOCtryCcyHBuff::operator >=( const CFSecISOCtryCcyHBuff& rhs ) {
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

	bool CFSecISOCtryCcyHBuff::operator >=( const CFSecISOCtryCcyBuff& rhs ) {
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

	bool CFSecISOCtryCcyHBuff::operator >( const CFSecISOCtryCcyByCtryIdxKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyHBuff::operator >( const CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyHBuff::operator >( const CFSecISOCtryCcyPKey& rhs ) {
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

	bool CFSecISOCtryCcyHBuff::operator >( const CFSecISOCtryCcyHPKey& rhs ) {
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

	bool CFSecISOCtryCcyHBuff::operator >( const CFSecISOCtryCcyHBuff& rhs ) {
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

	bool CFSecISOCtryCcyHBuff::operator >( const CFSecISOCtryCcyBuff& rhs ) {
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

	std::string CFSecISOCtryCcyHBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOCtryCcyHBuff" );
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
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_AuditSessionId, auditSessionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCtryId, getRequiredISOCtryId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCcyId, getRequiredISOCcyId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, getRequiredRevision() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCtryIdxKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs ) {
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

	bool operator <(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs ) {
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

	bool operator <(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
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

	bool operator <(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
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

	bool operator <=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCtryIdxKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs ) {
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

	bool operator <=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs ) {
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

	bool operator <=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
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

	bool operator <=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
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

	bool operator ==(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCtryIdxKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs ) {
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

	bool operator ==(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
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

	bool operator ==(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCtryIdxKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs ) {
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

	bool operator !=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
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

	bool operator !=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCtryIdxKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs ) {
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

	bool operator >=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs ) {
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

	bool operator >=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
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

	bool operator >=(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
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

	bool operator >(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCtryIdxKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs ) {
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

	bool operator >(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs ) {
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

	bool operator >(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
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

	bool operator >(const  cfsec::CFSecISOCtryCcyHBuff& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
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

