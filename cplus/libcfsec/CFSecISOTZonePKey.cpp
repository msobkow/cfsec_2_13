// Description: C++18 implementation of a ISOTZone primary key object.

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

#include <cfsec/CFSecISOTZonePKey.hpp>
#include <cfsec/CFSecISOTZoneBuff.hpp>
#include <cfsec/CFSecISOTZoneHPKey.hpp>
#include <cfsec/CFSecISOTZoneHBuff.hpp>

namespace cfsec {

	const std::string CFSecISOTZonePKey::CLASS_NAME( "CFSecISOTZonePKey" );
	const std::string CFSecISOTZonePKey::S_VALUE( "value" );
	const std::string CFSecISOTZonePKey::S_VALUE_LENGTH( "value.length()" );

	CFSecISOTZonePKey::CFSecISOTZonePKey() {
		requiredISOTZoneId = cfsec::CFSecISOTZoneBuff::ISOTZONEID_INIT_VALUE;
	}

	CFSecISOTZonePKey::CFSecISOTZonePKey( const CFSecISOTZonePKey& src ) {
		requiredISOTZoneId = cfsec::CFSecISOTZoneBuff::ISOTZONEID_INIT_VALUE;
		setRequiredISOTZoneId( src.getRequiredISOTZoneId() );
	}

	CFSecISOTZonePKey::~CFSecISOTZonePKey() {
	}

	const int16_t CFSecISOTZonePKey::getRequiredISOTZoneId() const {
		return( requiredISOTZoneId );
	}

	const int16_t* CFSecISOTZonePKey::getRequiredISOTZoneIdReference() const {
		return( &requiredISOTZoneId );
	}

	void CFSecISOTZonePKey::setRequiredISOTZoneId( const int16_t value ) {
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

	bool CFSecISOTZonePKey::operator <( const CFSecISOTZoneHPKey& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZonePKey::operator <( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZonePKey::operator <( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZonePKey::operator <( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZonePKey::operator <=( const CFSecISOTZoneHPKey& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZonePKey::operator <=( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZonePKey::operator <=( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZonePKey::operator <=( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZonePKey::operator ==( const CFSecISOTZoneHPKey& rhs ) {
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZonePKey::operator ==( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZonePKey::operator ==( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZonePKey::operator ==( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZonePKey::operator !=( const CFSecISOTZoneHPKey& rhs ) {
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZonePKey::operator !=( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZonePKey::operator !=( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZonePKey::operator !=( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZonePKey::operator >=( const CFSecISOTZoneHPKey& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZonePKey::operator >=( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZonePKey::operator >=( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZonePKey::operator >=( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZonePKey::operator >( const CFSecISOTZoneHPKey& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZonePKey::operator >( const CFSecISOTZonePKey& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZonePKey::operator >( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZonePKey::operator >( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	CFSecISOTZonePKey CFSecISOTZonePKey::operator =( cfsec::CFSecISOTZonePKey& src ) {
		setRequiredISOTZoneId( src.getRequiredISOTZoneId() );
		return( *this );
	}

	CFSecISOTZonePKey CFSecISOTZonePKey::operator =( cfsec::CFSecISOTZoneHPKey& src ) {
		setRequiredISOTZoneId( src.getRequiredISOTZoneId() );
		return( *this );
	}

	CFSecISOTZonePKey CFSecISOTZonePKey::operator =( cfsec::CFSecISOTZoneBuff& src ) {
		setRequiredISOTZoneId( src.getRequiredISOTZoneId() );
		return( *this );
	}

	CFSecISOTZonePKey CFSecISOTZonePKey::operator =( cfsec::CFSecISOTZoneHBuff& src ) {
		setRequiredISOTZoneId( src.getRequiredISOTZoneId() );
		return( *this );
	}

	size_t CFSecISOTZonePKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOTZoneId();
		return( hashCode );
	}

	std::string CFSecISOTZonePKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOTZonePKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ISOTZoneId( "ISOTZoneId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOTZoneId, getRequiredISOTZoneId() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() != rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHPKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZonePKey& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOTZonePKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredISOTZoneId() < rhs.getRequiredISOTZoneId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOTZoneId() > rhs.getRequiredISOTZoneId() ) {
			return( true );
		}
		return( false );
	}
}

