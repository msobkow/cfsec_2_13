// Description: C++18 implementation for a SecSession by StartIdx index key object.

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

#include <cfsec/CFSecSecSessionByStartIdxKey.hpp>
#include <cfsec/CFSecSecSessionBuff.hpp>
#include <cfsec/CFSecSecSessionHBuff.hpp>

namespace cfsec {
	const std::string CFSecSecSessionByStartIdxKey::CLASS_NAME( "CFSecSecSessionByStartIdxKey" );
	const std::string CFSecSecSessionByStartIdxKey::S_VALUE( "value" );
	const std::string CFSecSecSessionByStartIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecSecSessionByStartIdxKey::CFSecSecSessionByStartIdxKey() {
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
		requiredStart = cflib::CFLib::getUTCGregorianCalendarInstance( 2020, 0, 1, 0, 0, 0 );
	}

	CFSecSecSessionByStartIdxKey::CFSecSecSessionByStartIdxKey( const CFSecSecSessionByStartIdxKey& src ) {
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
		requiredStart = cflib::CFLib::getUTCGregorianCalendarInstance( 2020, 0, 1, 0, 0, 0 );
		setRequiredSecUserId( src.getRequiredSecUserId() );
		setRequiredStart( src.getRequiredStart() );
	}

	CFSecSecSessionByStartIdxKey::~CFSecSecSessionByStartIdxKey() {
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
	}

	const uuid_ptr_t CFSecSecSessionByStartIdxKey::getRequiredSecUserId() const {
		return( requiredSecUserId );
	}

	const uuid_ptr_t CFSecSecSessionByStartIdxKey::getRequiredSecUserIdReference() const {
		return( requiredSecUserId );
	}

	void CFSecSecSessionByStartIdxKey::setRequiredSecUserId( const uuid_ptr_t value ) {
		uuid_copy( requiredSecUserId, value );
	}

	void CFSecSecSessionByStartIdxKey::generateRequiredSecUserId() {
		uuid_generate_random( requiredSecUserId );
	}

	const std::chrono::system_clock::time_point& CFSecSecSessionByStartIdxKey::getRequiredStart() const {
		return( requiredStart );
	}

	const std::chrono::system_clock::time_point* CFSecSecSessionByStartIdxKey::getRequiredStartReference() const {
		return( &requiredStart );
	}

	void CFSecSecSessionByStartIdxKey::setRequiredStart( const std::chrono::system_clock::time_point& value ) {
		static const std::string S_ProcName( "setRequiredStart" );
		requiredStart = value;
	}

	size_t CFSecSecSessionByStartIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + cflib::CFLib::hash( getRequiredSecUserId() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredStart() );
		return( hashCode );
	}

	std::string CFSecSecSessionByStartIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecSessionByStartIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_SecUserId( "SecUserId" );
		static const std::string S_Start( "Start" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, getRequiredSecUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTimestamp( &S_Space, S_Start, getRequiredStart() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecSecSessionByStartIdxKey::operator <( const CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionByStartIdxKey::operator <( const CFSecSecSessionHBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionByStartIdxKey::operator <( const CFSecSecSessionBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionByStartIdxKey::operator <=( const CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionByStartIdxKey::operator <=( const CFSecSecSessionHBuff& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionByStartIdxKey::operator <=( const CFSecSecSessionBuff& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionByStartIdxKey::operator ==( const CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( getRequiredStart() != rhs.getRequiredStart() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecSessionByStartIdxKey::operator ==( const CFSecSecSessionHBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( getRequiredStart() != rhs.getRequiredStart() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecSessionByStartIdxKey::operator ==( const CFSecSecSessionBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( getRequiredStart() != rhs.getRequiredStart() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecSessionByStartIdxKey::operator !=( const CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredStart() != rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionByStartIdxKey::operator !=( const CFSecSecSessionHBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredStart() != rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionByStartIdxKey::operator !=( const CFSecSecSessionBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredStart() != rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionByStartIdxKey::operator >=( const CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionByStartIdxKey::operator >=( const CFSecSecSessionHBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionByStartIdxKey::operator >=( const CFSecSecSessionBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecSessionByStartIdxKey::operator >( const CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionByStartIdxKey::operator >( const CFSecSecSessionHBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecSessionByStartIdxKey::operator >( const CFSecSecSessionBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}
	CFSecSecSessionByStartIdxKey CFSecSecSessionByStartIdxKey::operator =( cfsec::CFSecSecSessionByStartIdxKey& src ) {
		setRequiredSecUserId( src.getRequiredSecUserId() );
		setRequiredStart( src.getRequiredStart() );
		return( *this );
	}

	CFSecSecSessionByStartIdxKey CFSecSecSessionByStartIdxKey::operator =( cfsec::CFSecSecSessionBuff& src ) {
		setRequiredSecUserId( src.getRequiredSecUserId() );
		setRequiredStart( src.getRequiredStart() );
		return( *this );
	}

	CFSecSecSessionByStartIdxKey CFSecSecSessionByStartIdxKey::operator =( cfsec::CFSecSecSessionHBuff& src ) {
		setRequiredSecUserId( src.getRequiredSecUserId() );
		setRequiredStart( src.getRequiredStart() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecSecSessionByStartIdxKey& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecSessionByStartIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecSessionByStartIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSecSessionByStartIdxKey& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecSessionByStartIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecSessionByStartIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionByStartIdxKey& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( lhs.getRequiredStart() != rhs.getRequiredStart() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionByStartIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( lhs.getRequiredStart() != rhs.getRequiredStart() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionByStartIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( lhs.getRequiredStart() != rhs.getRequiredStart() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSecSessionByStartIdxKey& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredStart() != rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecSessionByStartIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredStart() != rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecSessionByStartIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredStart() != rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSecSessionByStartIdxKey& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecSessionByStartIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecSessionByStartIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSecSessionByStartIdxKey& lhs, const cfsec::CFSecSecSessionByStartIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecSessionByStartIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecSessionByStartIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredStart() < rhs.getRequiredStart() ) {
			return( false );
		}
		else if( lhs.getRequiredStart() > rhs.getRequiredStart() ) {
			return( true );
		}
		return( false );
	}
}

