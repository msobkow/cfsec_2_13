// Description: C++18 implementation for a SecSession by SecDevIdx index key object.

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

#include <cfsec/CFSecSecSessionBySecDevIdxKey.hpp>
#include <cfsec/CFSecSecSessionBuff.hpp>
#include <cfsec/CFSecSecSessionHBuff.hpp>

namespace cfsec {
	const std::string CFSecSecSessionBySecDevIdxKey::CLASS_NAME( "CFSecSecSessionBySecDevIdxKey" );
	const std::string CFSecSecSessionBySecDevIdxKey::S_VALUE( "value" );
	const std::string CFSecSecSessionBySecDevIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecSecSessionBySecDevIdxKey::CFSecSecSessionBySecDevIdxKey() {
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
		optionalSecDevName = NULL;
	}

	CFSecSecSessionBySecDevIdxKey::CFSecSecSessionBySecDevIdxKey( const CFSecSecSessionBySecDevIdxKey& src ) {
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
		optionalSecDevName = NULL;
		setRequiredSecUserId( src.getRequiredSecUserId() );
		if( src.isOptionalSecDevNameNull() ) {
			setOptionalSecDevNameNull();
		}
		else {
			setOptionalSecDevNameValue( src.getOptionalSecDevNameValue() );
		}
	}

	CFSecSecSessionBySecDevIdxKey::~CFSecSecSessionBySecDevIdxKey() {
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
		if( optionalSecDevName != NULL ) {
			delete optionalSecDevName;
			optionalSecDevName = NULL;
		}
	}

	const uuid_ptr_t CFSecSecSessionBySecDevIdxKey::getRequiredSecUserId() const {
		return( requiredSecUserId );
	}

	const uuid_ptr_t CFSecSecSessionBySecDevIdxKey::getRequiredSecUserIdReference() const {
		return( requiredSecUserId );
	}

	void CFSecSecSessionBySecDevIdxKey::setRequiredSecUserId( const uuid_ptr_t value ) {
		uuid_copy( requiredSecUserId, value );
	}

	void CFSecSecSessionBySecDevIdxKey::generateRequiredSecUserId() {
		uuid_generate_random( requiredSecUserId );
	}

	const std::string& CFSecSecSessionBySecDevIdxKey::getOptionalSecDevNameValue() const {
		static const std::string S_ProcName( "getOptionalSecDevNameValue" );
		if( optionalSecDevName == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( *optionalSecDevName );
	}

	const std::string* CFSecSecSessionBySecDevIdxKey::getOptionalSecDevNameReference() const {
		return( optionalSecDevName );
	}

	const bool CFSecSecSessionBySecDevIdxKey::isOptionalSecDevNameNull() const {
		return( optionalSecDevName == NULL );
	}

	void CFSecSecSessionBySecDevIdxKey::setOptionalSecDevNameNull() {
		if( optionalSecDevName != NULL ) {
			delete optionalSecDevName;
			optionalSecDevName = NULL;
		}
	}

	void CFSecSecSessionBySecDevIdxKey::setOptionalSecDevNameValue( const std::string& value ) {
		static const std::string S_ProcName( "setOptionalSecDevNameValue" );
		if( value.length() > CFSecSecSessionBuff::SECDEVNAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecSecSessionBuff::SECDEVNAME_MAX_LEN );
		}
		if( optionalSecDevName != NULL ) {
			delete optionalSecDevName;
			optionalSecDevName = NULL;
		}
		optionalSecDevName = new std::string( value );
	}

	size_t CFSecSecSessionBySecDevIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + cflib::CFLib::hash( getRequiredSecUserId() );
		if( ! isOptionalSecDevNameNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalSecDevNameValue() );
		}
		return( hashCode );
	}

	std::string CFSecSecSessionBySecDevIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecSessionBySecDevIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_SecUserId( "SecUserId" );
		static const std::string S_SecDevName( "SecDevName" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, getRequiredSecUserId() ) );
		if( ! isOptionalSecDevNameNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_SecDevName, getOptionalSecDevNameValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecSecSessionBySecDevIdxKey::operator <( const CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionBySecDevIdxKey::operator <( const CFSecSecSessionHBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionBySecDevIdxKey::operator <( const CFSecSecSessionBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionBySecDevIdxKey::operator <=( const CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBySecDevIdxKey::operator <=( const CFSecSecSessionHBuff& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBySecDevIdxKey::operator <=( const CFSecSecSessionBuff& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBySecDevIdxKey::operator ==( const CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				if( getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBySecDevIdxKey::operator ==( const CFSecSecSessionHBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				if( getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBySecDevIdxKey::operator ==( const CFSecSecSessionBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				if( getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBySecDevIdxKey::operator !=( const CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionBySecDevIdxKey::operator !=( const CFSecSecSessionHBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionBySecDevIdxKey::operator !=( const CFSecSecSessionBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionBySecDevIdxKey::operator >=( const CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBySecDevIdxKey::operator >=( const CFSecSecSessionHBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBySecDevIdxKey::operator >=( const CFSecSecSessionBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionBySecDevIdxKey::operator >( const CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFSecSecSessionBySecDevIdxKey::operator >( const CFSecSecSessionHBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFSecSecSessionBySecDevIdxKey::operator >( const CFSecSecSessionBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}
	CFSecSecSessionBySecDevIdxKey CFSecSecSessionBySecDevIdxKey::operator =( cfsec::CFSecSecSessionBySecDevIdxKey& src ) {
		setRequiredSecUserId( src.getRequiredSecUserId() );
		if( src.isOptionalSecDevNameNull() ) {
			setOptionalSecDevNameNull();
		}
		else {
			setOptionalSecDevNameValue( src.getOptionalSecDevNameValue() );
		}
		return( *this );
	}

	CFSecSecSessionBySecDevIdxKey CFSecSecSessionBySecDevIdxKey::operator =( cfsec::CFSecSecSessionBuff& src ) {
		setRequiredSecUserId( src.getRequiredSecUserId() );
		if( src.isOptionalSecDevNameNull() ) {
			setOptionalSecDevNameNull();
		}
		else {
			setOptionalSecDevNameValue( src.getOptionalSecDevNameValue() );
		}
		return( *this );
	}

	CFSecSecSessionBySecDevIdxKey CFSecSecSessionBySecDevIdxKey::operator =( cfsec::CFSecSecSessionHBuff& src ) {
		setRequiredSecUserId( src.getRequiredSecUserId() );
		if( src.isOptionalSecDevNameNull() ) {
			setOptionalSecDevNameNull();
		}
		else {
			setOptionalSecDevNameValue( src.getOptionalSecDevNameValue() );
		}
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecSecSessionBySecDevIdxKey& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecSessionBySecDevIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecSessionBySecDevIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSecSessionBySecDevIdxKey& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecSessionBySecDevIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecSessionBySecDevIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
			if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionBySecDevIdxKey& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				if( lhs.getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionBySecDevIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				if( lhs.getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionBySecDevIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				if( lhs.getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSecSessionBySecDevIdxKey& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecSessionBySecDevIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecSessionBySecDevIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalSecDevNameValue() != rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSecSessionBySecDevIdxKey& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecSessionBySecDevIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecSessionBySecDevIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSecSessionBySecDevIdxKey& lhs, const cfsec::CFSecSecSessionBySecDevIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecSessionBySecDevIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecSessionBySecDevIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalSecDevNameNull() ) {
			if( rhs.isOptionalSecDevNameNull() ) {
				return( true );
			}
			if( lhs.getOptionalSecDevNameValue() < rhs.getOptionalSecDevNameValue() ) {
				return( false );
			}
			else if( lhs.getOptionalSecDevNameValue() > rhs.getOptionalSecDevNameValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalSecDevNameNull() ) {
				return( false );
			}
		}
		return( false );
	}
}

