// Description: C++18 implementation for a SecUser by PwdResetIdx index key object.

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

#include <cfsec/CFSecSecUserByPwdResetIdxKey.hpp>
#include <cfsec/CFSecSecUserBuff.hpp>
#include <cfsec/CFSecSecUserHBuff.hpp>

namespace cfsec {
	const std::string CFSecSecUserByPwdResetIdxKey::CLASS_NAME( "CFSecSecUserByPwdResetIdxKey" );
	const std::string CFSecSecUserByPwdResetIdxKey::S_VALUE( "value" );
	const std::string CFSecSecUserByPwdResetIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecSecUserByPwdResetIdxKey::CFSecSecUserByPwdResetIdxKey() {
		for( int i = 0; i < 16; i ++ ) {
			optionalPasswordResetUuid[i] = 0;
		}
	}

	CFSecSecUserByPwdResetIdxKey::CFSecSecUserByPwdResetIdxKey( const CFSecSecUserByPwdResetIdxKey& src ) {
		for( int i = 0; i < 16; i ++ ) {
			optionalPasswordResetUuid[i] = 0;
		}
		if( src.isOptionalPasswordResetUuidNull() ) {
			setOptionalPasswordResetUuidNull();
		}
		else {
			setOptionalPasswordResetUuidValue( src.getOptionalPasswordResetUuidValue() );
		}
	}

	CFSecSecUserByPwdResetIdxKey::~CFSecSecUserByPwdResetIdxKey() {
		for( int i = 0; i < 16; i ++ ) {
			optionalPasswordResetUuid[i] = 0;
		}
	}

	const uuid_ptr_t CFSecSecUserByPwdResetIdxKey::getOptionalPasswordResetUuidValue() const {
		static const std::string S_ProcName( "getOptionalPasswordResetUuidValue" );
		if( isOptionalPasswordResetUuidNull() ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( optionalPasswordResetUuid );
	}

	const uuid_ptr_t CFSecSecUserByPwdResetIdxKey::getOptionalPasswordResetUuidReference() const {
		if( isOptionalPasswordResetUuidNull() ) {
			return( NULL );
		}
		else {
			return( optionalPasswordResetUuid );
		}
	}

	const bool CFSecSecUserByPwdResetIdxKey::isOptionalPasswordResetUuidNull() const {
		for( int i = 0; i < 16; i++ ) {
			if( optionalPasswordResetUuid[ i ] != 0 ) {
				return( false );
			}
		}
		return( true );
	}

	void CFSecSecUserByPwdResetIdxKey::setOptionalPasswordResetUuidNull() {
		for( int i = 0; i < 16; i ++ ) {
			optionalPasswordResetUuid[i] = 0;
		}
	}

	void CFSecSecUserByPwdResetIdxKey::setOptionalPasswordResetUuidValue( const uuid_ptr_t value ) {
		uuid_copy( optionalPasswordResetUuid, value );
	}

	void CFSecSecUserByPwdResetIdxKey::generateOptionalPasswordResetUuid() {
		uuid_generate_random( optionalPasswordResetUuid );
	}

	size_t CFSecSecUserByPwdResetIdxKey::hashCode() const {
		size_t hashCode = 0;
		if( ! isOptionalPasswordResetUuidNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalPasswordResetUuidValue() );
		}
		return( hashCode );
	}

	std::string CFSecSecUserByPwdResetIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecUserByPwdResetIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_PasswordResetUuid( "PasswordResetUuid" );
		std::string ret( S_Preamble );
		if( ! isOptionalPasswordResetUuidNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_PasswordResetUuid, getOptionalPasswordResetUuidValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecSecUserByPwdResetIdxKey::operator <( const CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecUserByPwdResetIdxKey::operator <( const CFSecSecUserHBuff& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecUserByPwdResetIdxKey::operator <( const CFSecSecUserBuff& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecUserByPwdResetIdxKey::operator <=( const CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecUserByPwdResetIdxKey::operator <=( const CFSecSecUserHBuff& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecUserByPwdResetIdxKey::operator <=( const CFSecSecUserBuff& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecUserByPwdResetIdxKey::operator ==( const CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				if( 0 != uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecUserByPwdResetIdxKey::operator ==( const CFSecSecUserHBuff& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				if( 0 != uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecUserByPwdResetIdxKey::operator ==( const CFSecSecUserBuff& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				if( 0 != uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecUserByPwdResetIdxKey::operator !=( const CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecUserByPwdResetIdxKey::operator !=( const CFSecSecUserHBuff& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecUserByPwdResetIdxKey::operator !=( const CFSecSecUserBuff& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecUserByPwdResetIdxKey::operator >=( const CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecUserByPwdResetIdxKey::operator >=( const CFSecSecUserHBuff& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecUserByPwdResetIdxKey::operator >=( const CFSecSecUserBuff& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecUserByPwdResetIdxKey::operator >( const CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFSecSecUserByPwdResetIdxKey::operator >( const CFSecSecUserHBuff& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFSecSecUserByPwdResetIdxKey::operator >( const CFSecSecUserBuff& rhs ) {
		if( ! isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}
	CFSecSecUserByPwdResetIdxKey CFSecSecUserByPwdResetIdxKey::operator =( cfsec::CFSecSecUserByPwdResetIdxKey& src ) {
		if( src.isOptionalPasswordResetUuidNull() ) {
			setOptionalPasswordResetUuidNull();
		}
		else {
			setOptionalPasswordResetUuidValue( src.getOptionalPasswordResetUuidValue() );
		}
		return( *this );
	}

	CFSecSecUserByPwdResetIdxKey CFSecSecUserByPwdResetIdxKey::operator =( cfsec::CFSecSecUserBuff& src ) {
		if( src.isOptionalPasswordResetUuidNull() ) {
			setOptionalPasswordResetUuidNull();
		}
		else {
			setOptionalPasswordResetUuidValue( src.getOptionalPasswordResetUuidValue() );
		}
		return( *this );
	}

	CFSecSecUserByPwdResetIdxKey CFSecSecUserByPwdResetIdxKey::operator =( cfsec::CFSecSecUserHBuff& src ) {
		if( src.isOptionalPasswordResetUuidNull() ) {
			setOptionalPasswordResetUuidNull();
		}
		else {
			setOptionalPasswordResetUuidValue( src.getOptionalPasswordResetUuidValue() );
		}
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecSecUserByPwdResetIdxKey& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecUserByPwdResetIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecUserByPwdResetIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSecUserByPwdResetIdxKey& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecUserByPwdResetIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecUserByPwdResetIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecUserByPwdResetIdxKey& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				if( 0 != uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecUserByPwdResetIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				if( 0 != uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecUserByPwdResetIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				if( 0 != uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSecUserByPwdResetIdxKey& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecUserByPwdResetIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecUserByPwdResetIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSecUserByPwdResetIdxKey& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecUserByPwdResetIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecUserByPwdResetIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSecUserByPwdResetIdxKey& lhs, const cfsec::CFSecSecUserByPwdResetIdxKey& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecUserByPwdResetIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecUserByPwdResetIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( ! lhs.isOptionalPasswordResetUuidNull() ) {
			if( rhs.isOptionalPasswordResetUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalPasswordResetUuidValue(), rhs.getOptionalPasswordResetUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalPasswordResetUuidNull() ) {
				return( false );
			}
		}
		return( false );
	}
}

