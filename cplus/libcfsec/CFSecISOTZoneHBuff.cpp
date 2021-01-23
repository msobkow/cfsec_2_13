// Description: C++18 implementation of a ISOTZone history buffer object.

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
#include <cfsec/CFSecISOTZonePKey.hpp>
#include <cfsec/CFSecISOTZoneBuff.hpp>
#include <cfsec/CFSecISOTZoneHPKey.hpp>
#include <cfsec/CFSecISOTZoneHBuff.hpp>
#include <cfsec/CFSecISOTZoneByOffsetIdxKey.hpp>
#include <cfsec/CFSecISOTZoneByUTZNameIdxKey.hpp>
#include <cfsec/CFSecISOTZoneByIso8601IdxKey.hpp>

namespace cfsec {

	const std::string CFSecISOTZoneHBuff::CLASS_NAME( "CFSecISOTZoneHBuff" );
	CFSecISOTZoneHBuff::CFSecISOTZoneHBuff()
	: CFSecHPKey(), cflib::ICFLibCloneableObj() {
		requiredISOTZoneId = cfsec::CFSecISOTZoneBuff::ISOTZONEID_INIT_VALUE;
		requiredIso8601 = new std::string( cfsec::CFSecISOTZoneBuff::ISO8601_INIT_VALUE );
		requiredTZName = new std::string( cfsec::CFSecISOTZoneBuff::TZNAME_INIT_VALUE );
		requiredTZHourOffset = cfsec::CFSecISOTZoneBuff::TZHOUROFFSET_INIT_VALUE;
		requiredTZMinOffset = cfsec::CFSecISOTZoneBuff::TZMINOFFSET_INIT_VALUE;
		requiredDescription = new std::string( cfsec::CFSecISOTZoneBuff::DESCRIPTION_INIT_VALUE );
		requiredVisible = cfsec::CFSecISOTZoneBuff::VISIBLE_INIT_VALUE;
	}

	CFSecISOTZoneHBuff::CFSecISOTZoneHBuff( const CFSecISOTZoneHBuff& src )
	: CFSecHPKey(), cflib::ICFLibCloneableObj() {
		requiredISOTZoneId = cfsec::CFSecISOTZoneBuff::ISOTZONEID_INIT_VALUE;
		requiredIso8601 = new std::string( cfsec::CFSecISOTZoneBuff::ISO8601_INIT_VALUE );
		requiredTZName = new std::string( cfsec::CFSecISOTZoneBuff::TZNAME_INIT_VALUE );
		requiredTZHourOffset = cfsec::CFSecISOTZoneBuff::TZHOUROFFSET_INIT_VALUE;
		requiredTZMinOffset = cfsec::CFSecISOTZoneBuff::TZMINOFFSET_INIT_VALUE;
		requiredDescription = new std::string( cfsec::CFSecISOTZoneBuff::DESCRIPTION_INIT_VALUE );
		requiredVisible = cfsec::CFSecISOTZoneBuff::VISIBLE_INIT_VALUE;
		setRequiredISOTZoneId( src.getRequiredISOTZoneId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredIso8601( src.getRequiredIso8601() );
		setRequiredTZName( src.getRequiredTZName() );
		setRequiredTZHourOffset( src.getRequiredTZHourOffset() );
		setRequiredTZMinOffset( src.getRequiredTZMinOffset() );
		setRequiredDescription( src.getRequiredDescription() );
		setRequiredVisible( src.getRequiredVisible() );
	}

	CFSecISOTZoneHBuff::~CFSecISOTZoneHBuff() {
		if( requiredIso8601 != NULL ) {
			delete requiredIso8601;
			requiredIso8601 = NULL;
		}
		if( requiredTZName != NULL ) {
			delete requiredTZName;
			requiredTZName = NULL;
		}
		if( requiredDescription != NULL ) {
			delete requiredDescription;
			requiredDescription = NULL;
		}
	}

	cflib::ICFLibCloneableObj* CFSecISOTZoneHBuff::clone() {
		CFSecISOTZoneHBuff* copy = new CFSecISOTZoneHBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const int16_t CFSecISOTZoneHBuff::getRequiredISOTZoneId() const {
		return( requiredISOTZoneId );
	}

	const int16_t* CFSecISOTZoneHBuff::getRequiredISOTZoneIdReference() const {
		return( &requiredISOTZoneId );
	}

	void CFSecISOTZoneHBuff::setRequiredISOTZoneId( const int16_t value ) {
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

	const std::string& CFSecISOTZoneHBuff::getRequiredIso8601() const {
		return( *requiredIso8601 );
	}

	const std::string* CFSecISOTZoneHBuff::getRequiredIso8601Reference() const {
		return( requiredIso8601 );
	}

	void CFSecISOTZoneHBuff::setRequiredIso8601( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredIso8601" );
		if( value.length() > CFSecISOTZoneBuff::ISO8601_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecISOTZoneBuff::ISO8601_MAX_LEN );
		}
		if( requiredIso8601 != NULL ) {
			delete requiredIso8601;
			requiredIso8601 = NULL;
		}
		requiredIso8601 = new std::string( value );
	}

	const std::string& CFSecISOTZoneHBuff::getRequiredTZName() const {
		return( *requiredTZName );
	}

	const std::string* CFSecISOTZoneHBuff::getRequiredTZNameReference() const {
		return( requiredTZName );
	}

	void CFSecISOTZoneHBuff::setRequiredTZName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredTZName" );
		if( value.length() > CFSecISOTZoneBuff::TZNAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecISOTZoneBuff::TZNAME_MAX_LEN );
		}
		if( requiredTZName != NULL ) {
			delete requiredTZName;
			requiredTZName = NULL;
		}
		requiredTZName = new std::string( value );
	}

	const int16_t CFSecISOTZoneHBuff::getRequiredTZHourOffset() const {
		return( requiredTZHourOffset );
	}

	const int16_t* CFSecISOTZoneHBuff::getRequiredTZHourOffsetReference() const {
		return( &requiredTZHourOffset );
	}

	void CFSecISOTZoneHBuff::setRequiredTZHourOffset( const int16_t value ) {
		static const std::string S_ProcName( "setRequiredTZHourOffset" );
		if( value < cfsec::CFSecISOTZoneBuff::TZHOUROFFSET_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOTZoneBuff::TZHOUROFFSET_MIN_VALUE );
		}
		if( value > cfsec::CFSecISOTZoneBuff::TZHOUROFFSET_MAX_VALUE ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOTZoneBuff::TZHOUROFFSET_MAX_VALUE );
		}
		requiredTZHourOffset = value;
	}

	const int16_t CFSecISOTZoneHBuff::getRequiredTZMinOffset() const {
		return( requiredTZMinOffset );
	}

	const int16_t* CFSecISOTZoneHBuff::getRequiredTZMinOffsetReference() const {
		return( &requiredTZMinOffset );
	}

	void CFSecISOTZoneHBuff::setRequiredTZMinOffset( const int16_t value ) {
		static const std::string S_ProcName( "setRequiredTZMinOffset" );
		if( value < cfsec::CFSecISOTZoneBuff::TZMINOFFSET_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOTZoneBuff::TZMINOFFSET_MIN_VALUE );
		}
		if( value > cfsec::CFSecISOTZoneBuff::TZMINOFFSET_MAX_VALUE ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOTZoneBuff::TZMINOFFSET_MAX_VALUE );
		}
		requiredTZMinOffset = value;
	}

	const std::string& CFSecISOTZoneHBuff::getRequiredDescription() const {
		return( *requiredDescription );
	}

	const std::string* CFSecISOTZoneHBuff::getRequiredDescriptionReference() const {
		return( requiredDescription );
	}

	void CFSecISOTZoneHBuff::setRequiredDescription( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredDescription" );
		if( value.length() > CFSecISOTZoneBuff::DESCRIPTION_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecISOTZoneBuff::DESCRIPTION_MAX_LEN );
		}
		if( requiredDescription != NULL ) {
			delete requiredDescription;
			requiredDescription = NULL;
		}
		requiredDescription = new std::string( value );
	}

	const bool CFSecISOTZoneHBuff::getRequiredVisible() const {
		return( requiredVisible );
	}

	const bool* CFSecISOTZoneHBuff::getRequiredVisibleReference() const {
		return( &requiredVisible );
	}

	void CFSecISOTZoneHBuff::setRequiredVisible( const bool value ) {
		requiredVisible = value;
	}

	size_t CFSecISOTZoneHBuff::hashCode() const {
		size_t hashCode = CFSecHPKey::hashCode();
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOTZoneId();
		hashCode = hashCode + cflib::CFLib::hash( getRequiredIso8601() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredTZName() );
		hashCode = ( hashCode * 0x10000 ) + getRequiredTZHourOffset();
		hashCode = ( hashCode * 0x10000 ) + getRequiredTZMinOffset();
		hashCode = hashCode + cflib::CFLib::hash( getRequiredDescription() );
		if( getRequiredVisible() ) {
			hashCode = ( hashCode * 2 ) + 1;
		}
		else {
			hashCode = hashCode * 2;
		}
		return( hashCode );
	}

	CFSecISOTZoneHBuff CFSecISOTZoneHBuff::operator =( cfsec::CFSecISOTZoneBuff& src ) {
		setRequiredISOTZoneId( src.getRequiredISOTZoneId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredIso8601( src.getRequiredIso8601() );
		setRequiredTZName( src.getRequiredTZName() );
		setRequiredTZHourOffset( src.getRequiredTZHourOffset() );
		setRequiredTZMinOffset( src.getRequiredTZMinOffset() );
		setRequiredDescription( src.getRequiredDescription() );
		setRequiredVisible( src.getRequiredVisible() );
		return( *this );
	}

	CFSecISOTZoneHBuff CFSecISOTZoneHBuff::operator =( cfsec::CFSecISOTZoneHBuff& src ) {
		setRequiredISOTZoneId( src.getRequiredISOTZoneId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredIso8601( src.getRequiredIso8601() );
		setRequiredTZName( src.getRequiredTZName() );
		setRequiredTZHourOffset( src.getRequiredTZHourOffset() );
		setRequiredTZMinOffset( src.getRequiredTZMinOffset() );
		setRequiredDescription( src.getRequiredDescription() );
		setRequiredVisible( src.getRequiredVisible() );
		return( *this );
	}

	bool CFSecISOTZoneHBuff::operator <( const CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHBuff::operator <( const CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHBuff::operator <( const CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHBuff::operator <( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHBuff::operator <( const CFSecISOTZoneHPKey& rhs ) {
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

	bool CFSecISOTZoneHBuff::operator <( const CFSecISOTZoneHBuff& rhs ) {
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
		if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHBuff::operator <( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHBuff::operator <=( const CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHBuff::operator <=( const CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHBuff::operator <=( const CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHBuff::operator <=( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHBuff::operator <=( const CFSecISOTZoneHPKey& rhs ) {
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

	bool CFSecISOTZoneHBuff::operator <=( const CFSecISOTZoneHBuff& rhs ) {
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
		if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHBuff::operator <=( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHBuff::operator ==( const CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		if( getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZoneHBuff::operator ==( const CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZoneHBuff::operator ==( const CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZoneHBuff::operator ==( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZoneHBuff::operator ==( const CFSecISOTZoneHPKey& rhs ) {
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
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZoneHBuff::operator ==( const CFSecISOTZoneHBuff& rhs ) {
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
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		if( getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( false );
		}
		if( getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( false );
		}
		if( getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		if( getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		if( getRequiredVisible() != rhs.getRequiredVisible() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZoneHBuff::operator ==( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		if( getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( false );
		}
		if( getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( false );
		}
		if( getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		if( getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		if( getRequiredVisible() != rhs.getRequiredVisible() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZoneHBuff::operator !=( const CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHBuff::operator !=( const CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHBuff::operator !=( const CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHBuff::operator !=( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHBuff::operator !=( const CFSecISOTZoneHPKey& rhs ) {
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

	bool CFSecISOTZoneHBuff::operator !=( const CFSecISOTZoneHBuff& rhs ) {
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
		if( getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( true );
		}
		if( getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredVisible() != rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHBuff::operator !=( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( true );
		}
		if( getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredVisible() != rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHBuff::operator >=( const CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHBuff::operator >=( const CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHBuff::operator >=( const CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHBuff::operator >=( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHBuff::operator >=( const CFSecISOTZoneHPKey& rhs ) {
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

	bool CFSecISOTZoneHBuff::operator >=( const CFSecISOTZoneHBuff& rhs ) {
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
		if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHBuff::operator >=( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneHBuff::operator >( const CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHBuff::operator >( const CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHBuff::operator >( const CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHBuff::operator >( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHBuff::operator >( const CFSecISOTZoneHPKey& rhs ) {
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

	bool CFSecISOTZoneHBuff::operator >( const CFSecISOTZoneHBuff& rhs ) {
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
		if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneHBuff::operator >( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		if( getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}

	std::string CFSecISOTZoneHBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOTZoneHBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_AuditClusterId( "AuditClusterId" );
		static const std::string S_AuditStamp( "AuditStamp" );
		static const std::string S_AuditActionId( "AuditActionId" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_AuditSessionId( "AuditSessionId" );
		static const std::string S_ISOTZoneId( "ISOTZoneId" );
		static const std::string S_Iso8601( "Iso8601" );
		static const std::string S_TZName( "TZName" );
		static const std::string S_TZHourOffset( "TZHourOffset" );
		static const std::string S_TZMinOffset( "TZMinOffset" );
		static const std::string S_Description( "Description" );
		static const std::string S_Visible( "Visible" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_AuditClusterId, auditClusterId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_AuditClusterId, auditStamp ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_AuditActionId, auditActionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_AuditSessionId, auditSessionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOTZoneId, getRequiredISOTZoneId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Iso8601, getRequiredIso8601() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_TZName, getRequiredTZName() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_TZHourOffset, getRequiredTZHourOffset() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_TZMinOffset, getRequiredTZMinOffset() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, getRequiredDescription() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredBoolean( &S_Space, S_Visible, getRequiredVisible() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
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

	bool operator <(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
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
		if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
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

	bool operator <=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
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
		if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( lhs.getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		if( lhs.getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( lhs.getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( lhs.getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
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

	bool operator ==(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
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
		if( lhs.getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( false );
		}
		if( lhs.getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( false );
		}
		if( lhs.getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		if( lhs.getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		if( lhs.getRequiredVisible() != rhs.getRequiredVisible() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		if( lhs.getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( false );
		}
		if( lhs.getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( false );
		}
		if( lhs.getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		if( lhs.getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		if( lhs.getRequiredVisible() != rhs.getRequiredVisible() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( lhs.getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( lhs.getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( lhs.getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
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

	bool operator !=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
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
		if( lhs.getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( lhs.getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( true );
		}
		if( lhs.getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredVisible() != rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( lhs.getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( lhs.getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( true );
		}
		if( lhs.getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredVisible() != rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
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

	bool operator >=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
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
		if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
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

	bool operator >(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
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
		if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOTZoneHBuff& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		if( lhs.getRequiredTZHourOffset() < rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZHourOffset() > rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() < rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		else if( lhs.getRequiredTZMinOffset() > rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredVisible() < rhs.getRequiredVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredVisible() > rhs.getRequiredVisible() ) {
			return( true );
		}
		return( false );
	}
}

