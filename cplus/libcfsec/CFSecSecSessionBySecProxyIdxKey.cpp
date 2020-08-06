// Description: C++18 implementation for a SecSession by SecProxyIdx index key object.

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

#include <cfsec/CFSecSecSessionBySecProxyIdxKey.hpp>
#include <cfsec/CFSecSecSessionBuff.hpp>
#include <cfsec/CFSecSecSessionHBuff.hpp>

namespace cfsec {
	const std::string CFSecSecSessionBySecProxyIdxKey::CLASS_NAME( "CFSecSecSessionBySecProxyIdxKey" );
	const std::string CFSecSecSessionBySecProxyIdxKey::S_VALUE( "value" );
	const std::string CFSecSecSessionBySecProxyIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecSecSessionBySecProxyIdxKey::CFSecSecSessionBySecProxyIdxKey() {
		for( int i = 0; i < 16; i ++ ) {
			optionalSecProxyId[i] = 0;
		}
	}

	CFSecSecSessionBySecProxyIdxKey::CFSecSecSessionBySecProxyIdxKey( const CFSecSecSessionBySecProxyIdxKey& src ) {
		for( int i = 0; i < 16; i ++ ) {
			optionalSecProxyId[i] = 0;
		}
		if( src.isOptionalSecProxyIdNull() ) {
			setOptionalSecProxyIdNull();
		}
		else {
			setOptionalSecProxyIdValue( src.getOptionalSecProxyIdValue() );
		}
	}

	CFSecSecSessionBySecProxyIdxKey::~CFSecSecSessionBySecProxyIdxKey() {
		for( int i = 0; i < 16; i ++ ) {
			optionalSecProxyId[i] = 0;
		}
	}

	const uuid_ptr_t CFSecSecSessionBySecProxyIdxKey::getOptionalSecProxyIdValue() const {
		static const std::string S_ProcName( "getOptionalSecProxyIdValue" );
		if( isOptionalSecProxyIdNull() ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( optionalSecProxyId );
	}

	const uuid_ptr_t CFSecSecSessionBySecProxyIdxKey::getOptionalSecProxyIdReference() const {
		if( isOptionalSecProxyIdNull() ) {
			return( NULL );
		}
		else {
			return( optionalSecProxyId );
		}
	}

	const bool CFSecSecSessionBySecProxyIdxKey::isOptionalSecProxyIdNull() const {
		for( int i = 0; i < 16; i++ ) {
			if( optionalSecProxyId[ i ] != 0 ) {
				return( false );
			}
		}
		return( true );
	}

	void CFSecSecSessionBySecProxyIdxKey::setOptionalSecProxyIdNull() {
		for( int i = 0; i < 16; i ++ ) {
			optionalSecProxyId[i] = 0;
		}
	}

	void CFSecSecSessionBySecProxyIdxKey::setOptionalSecProxyIdValue( const uuid_ptr_t value ) {
		uuid_copy( optionalSecProxyId, value );
	}

	void CFSecSecSessionBySecProxyIdxKey::generateOptionalSecProxyId() {
		uuid_generate_random( optionalSecProxyId );
	}

	size_t CFSecSecSessionBySecProxyIdxKey::hashCode() const {
		size_t hashCode = 0;
		if( ! isOptionalSecProxyIdNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalSecProxyIdValue() );
		}
		return( hashCode );
	}

	std::string CFSecSecSessionBySecProxyIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecSessionBySecProxyIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_SecProxyId( "SecProxyId" );
		std::string ret( S_Preamble );
		if( ! isOptionalSecProxyIdNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecProxyId, getOptionalSecProxyIdValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecSecSessionBySecProxyIdxKey::operator <( const CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionBySecProxyIdxKey::operator <( const CFSecSecSessionHBuff& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionBySecProxyIdxKey::operator <( const CFSecSecSessionBuff& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionBySecProxyIdxKey::operator <=( const CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBySecProxyIdxKey::operator <=( const CFSecSecSessionHBuff& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBySecProxyIdxKey::operator <=( const CFSecSecSessionBuff& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBySecProxyIdxKey::operator ==( const CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				if( 0 != uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBySecProxyIdxKey::operator ==( const CFSecSecSessionHBuff& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				if( 0 != uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBySecProxyIdxKey::operator ==( const CFSecSecSessionBuff& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				if( 0 != uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBySecProxyIdxKey::operator !=( const CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionBySecProxyIdxKey::operator !=( const CFSecSecSessionHBuff& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionBySecProxyIdxKey::operator !=( const CFSecSecSessionBuff& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionBySecProxyIdxKey::operator >=( const CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBySecProxyIdxKey::operator >=( const CFSecSecSessionHBuff& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBySecProxyIdxKey::operator >=( const CFSecSecSessionBuff& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBySecProxyIdxKey::operator >( const CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFSecSecSessionBySecProxyIdxKey::operator >( const CFSecSecSessionHBuff& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFSecSecSessionBySecProxyIdxKey::operator >( const CFSecSecSessionBuff& rhs ) {
		if( ! isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}
	CFSecSecSessionBySecProxyIdxKey CFSecSecSessionBySecProxyIdxKey::operator =( cfsec::CFSecSecSessionBySecProxyIdxKey& src ) {
		if( src.isOptionalSecProxyIdNull() ) {
			setOptionalSecProxyIdNull();
		}
		else {
			setOptionalSecProxyIdValue( src.getOptionalSecProxyIdValue() );
		}
		return( *this );
	}

	CFSecSecSessionBySecProxyIdxKey CFSecSecSessionBySecProxyIdxKey::operator =( cfsec::CFSecSecSessionBuff& src ) {
		if( src.isOptionalSecProxyIdNull() ) {
			setOptionalSecProxyIdNull();
		}
		else {
			setOptionalSecProxyIdValue( src.getOptionalSecProxyIdValue() );
		}
		return( *this );
	}

	CFSecSecSessionBySecProxyIdxKey CFSecSecSessionBySecProxyIdxKey::operator =( cfsec::CFSecSecSessionHBuff& src ) {
		if( src.isOptionalSecProxyIdNull() ) {
			setOptionalSecProxyIdNull();
		}
		else {
			setOptionalSecProxyIdValue( src.getOptionalSecProxyIdValue() );
		}
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				if( 0 != uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				if( 0 != uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				if( 0 != uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBySecProxyIdxKey& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecSessionBySecProxyIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( ! lhs.isOptionalSecProxyIdNull() ) {
			if( rhs.isOptionalSecProxyIdNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalSecProxyIdValue(), rhs.getOptionalSecProxyIdValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecProxyIdNull() ) {
				return( false );
			}
		}
		return( false );
	}
}

