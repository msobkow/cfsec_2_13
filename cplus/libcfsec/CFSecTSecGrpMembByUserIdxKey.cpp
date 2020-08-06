// Description: C++18 implementation for a TSecGrpMemb by UserIdx index key object.

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

#include <cfsec/CFSecTSecGrpMembByUserIdxKey.hpp>
#include <cfsec/CFSecTSecGrpMembBuff.hpp>
#include <cfsec/CFSecTSecGrpMembHBuff.hpp>

namespace cfsec {
	const std::string CFSecTSecGrpMembByUserIdxKey::CLASS_NAME( "CFSecTSecGrpMembByUserIdxKey" );
	const std::string CFSecTSecGrpMembByUserIdxKey::S_VALUE( "value" );
	const std::string CFSecTSecGrpMembByUserIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecTSecGrpMembByUserIdxKey::CFSecTSecGrpMembByUserIdxKey() {
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
	}

	CFSecTSecGrpMembByUserIdxKey::CFSecTSecGrpMembByUserIdxKey( const CFSecTSecGrpMembByUserIdxKey& src ) {
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
		setRequiredSecUserId( src.getRequiredSecUserId() );
	}

	CFSecTSecGrpMembByUserIdxKey::~CFSecTSecGrpMembByUserIdxKey() {
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
	}

	const uuid_ptr_t CFSecTSecGrpMembByUserIdxKey::getRequiredSecUserId() const {
		return( requiredSecUserId );
	}

	const uuid_ptr_t CFSecTSecGrpMembByUserIdxKey::getRequiredSecUserIdReference() const {
		return( requiredSecUserId );
	}

	void CFSecTSecGrpMembByUserIdxKey::setRequiredSecUserId( const uuid_ptr_t value ) {
		uuid_copy( requiredSecUserId, value );
	}

	void CFSecTSecGrpMembByUserIdxKey::generateRequiredSecUserId() {
		uuid_generate_random( requiredSecUserId );
	}

	size_t CFSecTSecGrpMembByUserIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + cflib::CFLib::hash( getRequiredSecUserId() );
		return( hashCode );
	}

	std::string CFSecTSecGrpMembByUserIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecTSecGrpMembByUserIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_SecUserId( "SecUserId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, getRequiredSecUserId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecTSecGrpMembByUserIdxKey::operator <( const CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembByUserIdxKey::operator <( const CFSecTSecGrpMembHBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembByUserIdxKey::operator <( const CFSecTSecGrpMembBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembByUserIdxKey::operator <=( const CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembByUserIdxKey::operator <=( const CFSecTSecGrpMembHBuff& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembByUserIdxKey::operator <=( const CFSecTSecGrpMembBuff& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembByUserIdxKey::operator ==( const CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpMembByUserIdxKey::operator ==( const CFSecTSecGrpMembHBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpMembByUserIdxKey::operator ==( const CFSecTSecGrpMembBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpMembByUserIdxKey::operator !=( const CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembByUserIdxKey::operator !=( const CFSecTSecGrpMembHBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembByUserIdxKey::operator !=( const CFSecTSecGrpMembBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembByUserIdxKey::operator >=( const CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembByUserIdxKey::operator >=( const CFSecTSecGrpMembHBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembByUserIdxKey::operator >=( const CFSecTSecGrpMembBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembByUserIdxKey::operator >( const CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembByUserIdxKey::operator >( const CFSecTSecGrpMembHBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembByUserIdxKey::operator >( const CFSecTSecGrpMembBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}
	CFSecTSecGrpMembByUserIdxKey CFSecTSecGrpMembByUserIdxKey::operator =( cfsec::CFSecTSecGrpMembByUserIdxKey& src ) {
		setRequiredSecUserId( src.getRequiredSecUserId() );
		return( *this );
	}

	CFSecTSecGrpMembByUserIdxKey CFSecTSecGrpMembByUserIdxKey::operator =( cfsec::CFSecTSecGrpMembBuff& src ) {
		setRequiredSecUserId( src.getRequiredSecUserId() );
		return( *this );
	}

	CFSecTSecGrpMembByUserIdxKey CFSecTSecGrpMembByUserIdxKey::operator =( cfsec::CFSecTSecGrpMembHBuff& src ) {
		setRequiredSecUserId( src.getRequiredSecUserId() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembByUserIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTSecGrpMembByUserIdxKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		return( false );
	}
}

