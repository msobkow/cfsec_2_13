// Description: C++18 implementation for a ISOTZone by OffsetIdx index key object.

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

#include <cfsec/CFSecISOTZoneByOffsetIdxKey.hpp>
#include <cfsec/CFSecISOTZoneBuff.hpp>
#include <cfsec/CFSecISOTZoneHBuff.hpp>

namespace cfsec {
	const std::string CFSecISOTZoneByOffsetIdxKey::CLASS_NAME( "CFSecISOTZoneByOffsetIdxKey" );
	const std::string CFSecISOTZoneByOffsetIdxKey::S_VALUE( "value" );
	const std::string CFSecISOTZoneByOffsetIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecISOTZoneByOffsetIdxKey::CFSecISOTZoneByOffsetIdxKey() {
		requiredTZHourOffset = cfsec::CFSecISOTZoneBuff::TZHOUROFFSET_INIT_VALUE;
		requiredTZMinOffset = cfsec::CFSecISOTZoneBuff::TZMINOFFSET_INIT_VALUE;
	}

	CFSecISOTZoneByOffsetIdxKey::CFSecISOTZoneByOffsetIdxKey( const CFSecISOTZoneByOffsetIdxKey& src ) {
		requiredTZHourOffset = cfsec::CFSecISOTZoneBuff::TZHOUROFFSET_INIT_VALUE;
		requiredTZMinOffset = cfsec::CFSecISOTZoneBuff::TZMINOFFSET_INIT_VALUE;
		setRequiredTZHourOffset( src.getRequiredTZHourOffset() );
		setRequiredTZMinOffset( src.getRequiredTZMinOffset() );
	}

	CFSecISOTZoneByOffsetIdxKey::~CFSecISOTZoneByOffsetIdxKey() {
	}

	const int16_t CFSecISOTZoneByOffsetIdxKey::getRequiredTZHourOffset() const {
		return( requiredTZHourOffset );
	}

	const int16_t* CFSecISOTZoneByOffsetIdxKey::getRequiredTZHourOffsetReference() const {
		return( &requiredTZHourOffset );
	}

	void CFSecISOTZoneByOffsetIdxKey::setRequiredTZHourOffset( const int16_t value ) {
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

	const int16_t CFSecISOTZoneByOffsetIdxKey::getRequiredTZMinOffset() const {
		return( requiredTZMinOffset );
	}

	const int16_t* CFSecISOTZoneByOffsetIdxKey::getRequiredTZMinOffsetReference() const {
		return( &requiredTZMinOffset );
	}

	void CFSecISOTZoneByOffsetIdxKey::setRequiredTZMinOffset( const int16_t value ) {
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

	size_t CFSecISOTZoneByOffsetIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = ( hashCode * 0x10000 ) + getRequiredTZHourOffset();
		hashCode = ( hashCode * 0x10000 ) + getRequiredTZMinOffset();
		return( hashCode );
	}

	std::string CFSecISOTZoneByOffsetIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOTZoneByOffsetIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_TZHourOffset( "TZHourOffset" );
		static const std::string S_TZMinOffset( "TZMinOffset" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_TZHourOffset, getRequiredTZHourOffset() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_TZMinOffset, getRequiredTZMinOffset() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecISOTZoneByOffsetIdxKey::operator <( const CFSecISOTZoneByOffsetIdxKey& rhs ) {
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

	bool CFSecISOTZoneByOffsetIdxKey::operator <( const CFSecISOTZoneHBuff& rhs ) {
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

	bool CFSecISOTZoneByOffsetIdxKey::operator <( const CFSecISOTZoneBuff& rhs ) {
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

	bool CFSecISOTZoneByOffsetIdxKey::operator <=( const CFSecISOTZoneByOffsetIdxKey& rhs ) {
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

	bool CFSecISOTZoneByOffsetIdxKey::operator <=( const CFSecISOTZoneHBuff& rhs ) {
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

	bool CFSecISOTZoneByOffsetIdxKey::operator <=( const CFSecISOTZoneBuff& rhs ) {
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

	bool CFSecISOTZoneByOffsetIdxKey::operator ==( const CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		if( getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZoneByOffsetIdxKey::operator ==( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		if( getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZoneByOffsetIdxKey::operator ==( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		if( getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZoneByOffsetIdxKey::operator !=( const CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneByOffsetIdxKey::operator !=( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneByOffsetIdxKey::operator !=( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneByOffsetIdxKey::operator >=( const CFSecISOTZoneByOffsetIdxKey& rhs ) {
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

	bool CFSecISOTZoneByOffsetIdxKey::operator >=( const CFSecISOTZoneHBuff& rhs ) {
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

	bool CFSecISOTZoneByOffsetIdxKey::operator >=( const CFSecISOTZoneBuff& rhs ) {
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

	bool CFSecISOTZoneByOffsetIdxKey::operator >( const CFSecISOTZoneByOffsetIdxKey& rhs ) {
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

	bool CFSecISOTZoneByOffsetIdxKey::operator >( const CFSecISOTZoneHBuff& rhs ) {
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

	bool CFSecISOTZoneByOffsetIdxKey::operator >( const CFSecISOTZoneBuff& rhs ) {
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
	CFSecISOTZoneByOffsetIdxKey CFSecISOTZoneByOffsetIdxKey::operator =( cfsec::CFSecISOTZoneByOffsetIdxKey& src ) {
		setRequiredTZHourOffset( src.getRequiredTZHourOffset() );
		setRequiredTZMinOffset( src.getRequiredTZMinOffset() );
		return( *this );
	}

	CFSecISOTZoneByOffsetIdxKey CFSecISOTZoneByOffsetIdxKey::operator =( cfsec::CFSecISOTZoneBuff& src ) {
		setRequiredTZHourOffset( src.getRequiredTZHourOffset() );
		setRequiredTZMinOffset( src.getRequiredTZMinOffset() );
		return( *this );
	}

	CFSecISOTZoneByOffsetIdxKey CFSecISOTZoneByOffsetIdxKey::operator =( cfsec::CFSecISOTZoneHBuff& src ) {
		setRequiredTZHourOffset( src.getRequiredTZHourOffset() );
		setRequiredTZMinOffset( src.getRequiredTZMinOffset() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs ) {
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

	bool operator <(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
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

	bool operator <(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
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

	bool operator <=(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs ) {
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

	bool operator <=(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
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

	bool operator <=(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
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

	bool operator ==(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( lhs.getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		if( lhs.getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		if( lhs.getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( false );
		}
		if( lhs.getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs ) {
		if( lhs.getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredTZHourOffset() != rhs.getRequiredTZHourOffset() ) {
			return( true );
		}
		if( lhs.getRequiredTZMinOffset() != rhs.getRequiredTZMinOffset() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs ) {
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

	bool operator >=(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
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

	bool operator >=(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
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

	bool operator >(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneByOffsetIdxKey& rhs ) {
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

	bool operator >(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
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

	bool operator >(const  cfsec::CFSecISOTZoneByOffsetIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
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
}

