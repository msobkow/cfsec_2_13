// Description: C++18 implementation for a SecUser by EMConfIdx index key object.

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

#include <cfsec/CFSecSecUserByEMConfIdxKey.hpp>
#include <cfsec/CFSecSecUserBuff.hpp>
#include <cfsec/CFSecSecUserHBuff.hpp>

namespace cfsec {
	const std::string CFSecSecUserByEMConfIdxKey::CLASS_NAME( "CFSecSecUserByEMConfIdxKey" );
	const std::string CFSecSecUserByEMConfIdxKey::S_VALUE( "value" );
	const std::string CFSecSecUserByEMConfIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecSecUserByEMConfIdxKey::CFSecSecUserByEMConfIdxKey() {
		for( int i = 0; i < 16; i ++ ) {
			optionalEMailConfirmUuid[i] = 0;
		}
	}

	CFSecSecUserByEMConfIdxKey::CFSecSecUserByEMConfIdxKey( const CFSecSecUserByEMConfIdxKey& src ) {
		for( int i = 0; i < 16; i ++ ) {
			optionalEMailConfirmUuid[i] = 0;
		}
		if( src.isOptionalEMailConfirmUuidNull() ) {
			setOptionalEMailConfirmUuidNull();
		}
		else {
			setOptionalEMailConfirmUuidValue( src.getOptionalEMailConfirmUuidValue() );
		}
	}

	CFSecSecUserByEMConfIdxKey::~CFSecSecUserByEMConfIdxKey() {
		for( int i = 0; i < 16; i ++ ) {
			optionalEMailConfirmUuid[i] = 0;
		}
	}

	const uuid_ptr_t CFSecSecUserByEMConfIdxKey::getOptionalEMailConfirmUuidValue() const {
		static const std::string S_ProcName( "getOptionalEMailConfirmUuidValue" );
		if( isOptionalEMailConfirmUuidNull() ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( optionalEMailConfirmUuid );
	}

	const uuid_ptr_t CFSecSecUserByEMConfIdxKey::getOptionalEMailConfirmUuidReference() const {
		if( isOptionalEMailConfirmUuidNull() ) {
			return( NULL );
		}
		else {
			return( optionalEMailConfirmUuid );
		}
	}

	const bool CFSecSecUserByEMConfIdxKey::isOptionalEMailConfirmUuidNull() const {
		for( int i = 0; i < 16; i++ ) {
			if( optionalEMailConfirmUuid[ i ] != 0 ) {
				return( false );
			}
		}
		return( true );
	}

	void CFSecSecUserByEMConfIdxKey::setOptionalEMailConfirmUuidNull() {
		for( int i = 0; i < 16; i ++ ) {
			optionalEMailConfirmUuid[i] = 0;
		}
	}

	void CFSecSecUserByEMConfIdxKey::setOptionalEMailConfirmUuidValue( const uuid_ptr_t value ) {
		uuid_copy( optionalEMailConfirmUuid, value );
	}

	void CFSecSecUserByEMConfIdxKey::generateOptionalEMailConfirmUuid() {
		uuid_generate_random( optionalEMailConfirmUuid );
	}

	size_t CFSecSecUserByEMConfIdxKey::hashCode() const {
		size_t hashCode = 0;
		if( ! isOptionalEMailConfirmUuidNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalEMailConfirmUuidValue() );
		}
		return( hashCode );
	}

	std::string CFSecSecUserByEMConfIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecUserByEMConfIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_EMailConfirmUuid( "EMailConfirmUuid" );
		std::string ret( S_Preamble );
		if( ! isOptionalEMailConfirmUuidNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_EMailConfirmUuid, getOptionalEMailConfirmUuidValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecSecUserByEMConfIdxKey::operator <( const CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecUserByEMConfIdxKey::operator <( const CFSecSecUserHBuff& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecUserByEMConfIdxKey::operator <( const CFSecSecUserBuff& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecUserByEMConfIdxKey::operator <=( const CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecUserByEMConfIdxKey::operator <=( const CFSecSecUserHBuff& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecUserByEMConfIdxKey::operator <=( const CFSecSecUserBuff& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecUserByEMConfIdxKey::operator ==( const CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				if( 0 != uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecUserByEMConfIdxKey::operator ==( const CFSecSecUserHBuff& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				if( 0 != uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecUserByEMConfIdxKey::operator ==( const CFSecSecUserBuff& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				if( 0 != uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecUserByEMConfIdxKey::operator !=( const CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecUserByEMConfIdxKey::operator !=( const CFSecSecUserHBuff& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecUserByEMConfIdxKey::operator !=( const CFSecSecUserBuff& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecUserByEMConfIdxKey::operator >=( const CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecUserByEMConfIdxKey::operator >=( const CFSecSecUserHBuff& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecUserByEMConfIdxKey::operator >=( const CFSecSecUserBuff& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecUserByEMConfIdxKey::operator >( const CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFSecSecUserByEMConfIdxKey::operator >( const CFSecSecUserHBuff& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFSecSecUserByEMConfIdxKey::operator >( const CFSecSecUserBuff& rhs ) {
		if( ! isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}
	CFSecSecUserByEMConfIdxKey CFSecSecUserByEMConfIdxKey::operator =( cfsec::CFSecSecUserByEMConfIdxKey& src ) {
		if( src.isOptionalEMailConfirmUuidNull() ) {
			setOptionalEMailConfirmUuidNull();
		}
		else {
			setOptionalEMailConfirmUuidValue( src.getOptionalEMailConfirmUuidValue() );
		}
		return( *this );
	}

	CFSecSecUserByEMConfIdxKey CFSecSecUserByEMConfIdxKey::operator =( cfsec::CFSecSecUserBuff& src ) {
		if( src.isOptionalEMailConfirmUuidNull() ) {
			setOptionalEMailConfirmUuidNull();
		}
		else {
			setOptionalEMailConfirmUuidValue( src.getOptionalEMailConfirmUuidValue() );
		}
		return( *this );
	}

	CFSecSecUserByEMConfIdxKey CFSecSecUserByEMConfIdxKey::operator =( cfsec::CFSecSecUserHBuff& src ) {
		if( src.isOptionalEMailConfirmUuidNull() ) {
			setOptionalEMailConfirmUuidNull();
		}
		else {
			setOptionalEMailConfirmUuidValue( src.getOptionalEMailConfirmUuidValue() );
		}
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecSecUserByEMConfIdxKey& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecUserByEMConfIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecUserByEMConfIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSecUserByEMConfIdxKey& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecUserByEMConfIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecUserByEMConfIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
			if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecUserByEMConfIdxKey& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				if( 0 != uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecUserByEMConfIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				if( 0 != uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecUserByEMConfIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				if( 0 != uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSecUserByEMConfIdxKey& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecUserByEMConfIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecUserByEMConfIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 != uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSecUserByEMConfIdxKey& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecUserByEMConfIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecUserByEMConfIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSecUserByEMConfIdxKey& lhs, const cfsec::CFSecSecUserByEMConfIdxKey& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecUserByEMConfIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecUserByEMConfIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( ! lhs.isOptionalEMailConfirmUuidNull() ) {
			if( rhs.isOptionalEMailConfirmUuidNull() ) {
				return( true );
			}
			if( 0 > uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( false );
			}
			else if( 0 < uuid_compare( lhs.getOptionalEMailConfirmUuidValue(), rhs.getOptionalEMailConfirmUuidValue() ) ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEMailConfirmUuidNull() ) {
				return( false );
			}
		}
		return( false );
	}
}

