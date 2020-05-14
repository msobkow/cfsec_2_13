// Description: C++18 implementation for a ISOTZone by UTZNameIdx index key object.

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

#include <cfsec/CFSecISOTZoneByUTZNameIdxKey.hpp>
#include <cfsec/CFSecISOTZoneBuff.hpp>
#include <cfsec/CFSecISOTZoneHBuff.hpp>

namespace cfsec {
	const std::string CFSecISOTZoneByUTZNameIdxKey::CLASS_NAME( "CFSecISOTZoneByUTZNameIdxKey" );
	const std::string CFSecISOTZoneByUTZNameIdxKey::S_VALUE( "value" );
	const std::string CFSecISOTZoneByUTZNameIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecISOTZoneByUTZNameIdxKey::CFSecISOTZoneByUTZNameIdxKey() {
		requiredTZName = new std::string( cfsec::CFSecISOTZoneBuff::TZNAME_INIT_VALUE );
	}

	CFSecISOTZoneByUTZNameIdxKey::CFSecISOTZoneByUTZNameIdxKey( const CFSecISOTZoneByUTZNameIdxKey& src ) {
		requiredTZName = new std::string( cfsec::CFSecISOTZoneBuff::TZNAME_INIT_VALUE );
		setRequiredTZName( src.getRequiredTZName() );
	}

	CFSecISOTZoneByUTZNameIdxKey::~CFSecISOTZoneByUTZNameIdxKey() {
		if( requiredTZName != NULL ) {
			delete requiredTZName;
			requiredTZName = NULL;
		}
	}

	const std::string& CFSecISOTZoneByUTZNameIdxKey::getRequiredTZName() const {
		return( *requiredTZName );
	}

	const std::string* CFSecISOTZoneByUTZNameIdxKey::getRequiredTZNameReference() const {
		return( requiredTZName );
	}

	void CFSecISOTZoneByUTZNameIdxKey::setRequiredTZName( const std::string& value ) {
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

	size_t CFSecISOTZoneByUTZNameIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + cflib::CFLib::hash( getRequiredTZName() );
		return( hashCode );
	}

	std::string CFSecISOTZoneByUTZNameIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOTZoneByUTZNameIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_TZName( "TZName" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_TZName, getRequiredTZName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecISOTZoneByUTZNameIdxKey::operator <( const CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneByUTZNameIdxKey::operator <( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneByUTZNameIdxKey::operator <( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneByUTZNameIdxKey::operator <=( const CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneByUTZNameIdxKey::operator <=( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneByUTZNameIdxKey::operator <=( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneByUTZNameIdxKey::operator ==( const CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZoneByUTZNameIdxKey::operator ==( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZoneByUTZNameIdxKey::operator ==( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOTZoneByUTZNameIdxKey::operator !=( const CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneByUTZNameIdxKey::operator !=( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneByUTZNameIdxKey::operator !=( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneByUTZNameIdxKey::operator >=( const CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneByUTZNameIdxKey::operator >=( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneByUTZNameIdxKey::operator >=( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOTZoneByUTZNameIdxKey::operator >( const CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneByUTZNameIdxKey::operator >( const CFSecISOTZoneHBuff& rhs ) {
		if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOTZoneByUTZNameIdxKey::operator >( const CFSecISOTZoneBuff& rhs ) {
		if( getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}
	CFSecISOTZoneByUTZNameIdxKey CFSecISOTZoneByUTZNameIdxKey::operator =( cfsec::CFSecISOTZoneByUTZNameIdxKey& src ) {
		setRequiredTZName( src.getRequiredTZName() );
		return( *this );
	}

	CFSecISOTZoneByUTZNameIdxKey CFSecISOTZoneByUTZNameIdxKey::operator =( cfsec::CFSecISOTZoneBuff& src ) {
		setRequiredTZName( src.getRequiredTZName() );
		return( *this );
	}

	CFSecISOTZoneByUTZNameIdxKey CFSecISOTZoneByUTZNameIdxKey::operator =( cfsec::CFSecISOTZoneHBuff& src ) {
		setRequiredTZName( src.getRequiredTZName() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( lhs.getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( lhs.getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredTZName() != rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneByUTZNameIdxKey& rhs ) {
		if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneHBuff& rhs ) {
		if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOTZoneByUTZNameIdxKey& lhs, const cfsec::CFSecISOTZoneBuff& rhs ) {
		if( lhs.getRequiredTZName() < rhs.getRequiredTZName() ) {
			return( false );
		}
		else if( lhs.getRequiredTZName() > rhs.getRequiredTZName() ) {
			return( true );
		}
		return( false );
	}
}

