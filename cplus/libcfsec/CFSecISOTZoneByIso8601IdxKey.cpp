// Description: C++18 implementation for a ISOTZone by Iso8601Idx index key object.

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

#include <cfsec/CFSecISOTZoneByIso8601IdxKey.hpp>
#include <cfsec/CFSecISOTZoneBuff.hpp>
#include <cfsec/CFSecISOTZoneHBuff.hpp>

namespace cfsec {
	const std::string CFSecISOTZoneByIso8601IdxKey::CLASS_NAME( "CFSecISOTZoneByIso8601IdxKey" );
	const std::string CFSecISOTZoneByIso8601IdxKey::S_VALUE( "value" );
	const std::string CFSecISOTZoneByIso8601IdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecISOTZoneByIso8601IdxKey::CFSecISOTZoneByIso8601IdxKey() {
		requiredIso8601 = new std::string( cfsec::CFSecISOTZoneBuff::ISO8601_INIT_VALUE );
	}

	CFSecISOTZoneByIso8601IdxKey::CFSecISOTZoneByIso8601IdxKey( const CFSecISOTZoneByIso8601IdxKey& src ) {
		requiredIso8601 = new std::string( cfsec::CFSecISOTZoneBuff::ISO8601_INIT_VALUE );
		setRequiredIso8601( src.getRequiredIso8601() );
	}

	CFSecISOTZoneByIso8601IdxKey::~CFSecISOTZoneByIso8601IdxKey() {
		if( requiredIso8601 != NULL ) {
			delete requiredIso8601;
			requiredIso8601 = NULL;
		}
	}

	const std::string& CFSecISOTZoneByIso8601IdxKey::getRequiredIso8601() const {
		return( *requiredIso8601 );
	}

	const std::string* CFSecISOTZoneByIso8601IdxKey::getRequiredIso8601Reference() const {
		return( requiredIso8601 );
	}

	void CFSecISOTZoneByIso8601IdxKey::setRequiredIso8601( const std::string& value ) {
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

	size_t CFSecISOTZoneByIso8601IdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + cflib::CFLib::hash( getRequiredIso8601() );
		return( hashCode );
	}

	std::string CFSecISOTZoneByIso8601IdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOTZoneByIso8601IdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Iso8601( "Iso8601" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Iso8601, getRequiredIso8601() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecISOTZoneByIso8601IdxKey::operator <( const CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneByIso8601IdxKey::operator <( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneByIso8601IdxKey::operator <( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneByIso8601IdxKey::operator <=( const CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneByIso8601IdxKey::operator <=( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneByIso8601IdxKey::operator <=( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneByIso8601IdxKey::operator ==( const CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZoneByIso8601IdxKey::operator ==( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZoneByIso8601IdxKey::operator ==( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZoneByIso8601IdxKey::operator !=( const CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneByIso8601IdxKey::operator !=( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneByIso8601IdxKey::operator !=( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneByIso8601IdxKey::operator >=( const CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneByIso8601IdxKey::operator >=( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneByIso8601IdxKey::operator >=( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneByIso8601IdxKey::operator >( const CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneByIso8601IdxKey::operator >( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneByIso8601IdxKey::operator >( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}
	CFSecISOTZoneByIso8601IdxKey CFSecISOTZoneByIso8601IdxKey::operator =( cfsec::CFSecISOTZoneByIso8601IdxKey& src ) {
		setRequiredIso8601( src.getRequiredIso8601() );
		return( *this );
	}

	CFSecISOTZoneByIso8601IdxKey CFSecISOTZoneByIso8601IdxKey::operator =( cfsec::CFSecISOTZoneBuff& src ) {
		setRequiredIso8601( src.getRequiredIso8601() );
		return( *this );
	}

	CFSecISOTZoneByIso8601IdxKey CFSecISOTZoneByIso8601IdxKey::operator =( cfsec::CFSecISOTZoneHBuff& src ) {
		setRequiredIso8601( src.getRequiredIso8601() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( lhs.getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( lhs.getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredIso8601() != rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneByIso8601IdxKey& rhs ) {
		if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOTZoneByIso8601IdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredIso8601() < rhs.getRequiredIso8601() ) {
			return( false );
		}
		else if( lhs.getRequiredIso8601() > rhs.getRequiredIso8601() ) {
			return( true );
		}
		return( false );
	}
}

