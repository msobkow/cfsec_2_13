// Description: C++18 implementation for a SecSession by FinishIdx index key object.

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

#include <cfsec/CFSecSecSessionByFinishIdxKey.hpp>
#include <cfsec/CFSecSecSessionBuff.hpp>
#include <cfsec/CFSecSecSessionHBuff.hpp>

namespace cfsec {
	const std::string CFSecSecSessionByFinishIdxKey::CLASS_NAME( "CFSecSecSessionByFinishIdxKey" );
	const std::string CFSecSecSessionByFinishIdxKey::S_VALUE( "value" );
	const std::string CFSecSecSessionByFinishIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecSecSessionByFinishIdxKey::CFSecSecSessionByFinishIdxKey() {
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
		optionalFinish = NULL;
	}

	CFSecSecSessionByFinishIdxKey::CFSecSecSessionByFinishIdxKey( const CFSecSecSessionByFinishIdxKey& src ) {
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
		optionalFinish = NULL;
		setRequiredSecUserId( src.getRequiredSecUserId() );
		if( src.isOptionalFinishNull() ) {
			setOptionalFinishNull();
		}
		else {
			setOptionalFinishValue( src.getOptionalFinishValue() );
		}
	}

	CFSecSecSessionByFinishIdxKey::~CFSecSecSessionByFinishIdxKey() {
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
		if( optionalFinish != NULL ) {
			delete optionalFinish;
			optionalFinish = NULL;
		}
	}

	const uuid_ptr_t CFSecSecSessionByFinishIdxKey::getRequiredSecUserId() const {
		return( requiredSecUserId );
	}

	const uuid_ptr_t CFSecSecSessionByFinishIdxKey::getRequiredSecUserIdReference() const {
		return( requiredSecUserId );
	}

	void CFSecSecSessionByFinishIdxKey::setRequiredSecUserId( const uuid_ptr_t value ) {
		uuid_copy( requiredSecUserId, value );
	}

	void CFSecSecSessionByFinishIdxKey::generateRequiredSecUserId() {
		uuid_generate_random( requiredSecUserId );
	}

	const std::chrono::system_clock::time_point& CFSecSecSessionByFinishIdxKey::getOptionalFinishValue() const {
		return( *optionalFinish );
	}

	const std::chrono::system_clock::time_point* CFSecSecSessionByFinishIdxKey::getOptionalFinishReference() const {
		return( optionalFinish );
	}

	const bool CFSecSecSessionByFinishIdxKey::isOptionalFinishNull() const {
		return( optionalFinish == NULL );
	}

	void CFSecSecSessionByFinishIdxKey::setOptionalFinishNull() {
		if( optionalFinish != NULL ) {
			delete optionalFinish;
			optionalFinish = NULL;
		}
	}

	void CFSecSecSessionByFinishIdxKey::setOptionalFinishValue( const std::chrono::system_clock::time_point& value ) {
		static const std::string S_ProcName( "setOptionalFinishValue" );
		static const std::string S_ColumnName( ".Finish" );
		if( optionalFinish != NULL ) {
			delete optionalFinish;
			optionalFinish = NULL;
		}
		optionalFinish = new std::chrono::system_clock::time_point( value );
	}

	size_t CFSecSecSessionByFinishIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + cflib::CFLib::hash( getRequiredSecUserId() );
		if( ! isOptionalFinishNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalFinishValue() );
		}
		return( hashCode );
	}

	std::string CFSecSecSessionByFinishIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecSessionByFinishIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_SecUserId( "SecUserId" );
		static const std::string S_Finish( "Finish" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, getRequiredSecUserId() ) );
		if( ! isOptionalFinishNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredTimestamp( &S_Space, S_Finish, getOptionalFinishValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecSecSessionByFinishIdxKey::operator <( const CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionByFinishIdxKey::operator <( const CFSecSecSessionHBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionByFinishIdxKey::operator <( const CFSecSecSessionBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionByFinishIdxKey::operator <=( const CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecSessionByFinishIdxKey::operator <=( const CFSecSecSessionHBuff& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecSessionByFinishIdxKey::operator <=( const CFSecSecSessionBuff& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecSecSessionByFinishIdxKey::operator ==( const CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( ! isOptionalFinishNull() ) {
			if( ! rhs.isOptionalFinishNull() ) {
				if( getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionByFinishIdxKey::operator ==( const CFSecSecSessionHBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( ! isOptionalFinishNull() ) {
			if( ! rhs.isOptionalFinishNull() ) {
				if( getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionByFinishIdxKey::operator ==( const CFSecSecSessionBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( ! isOptionalFinishNull() ) {
			if( ! rhs.isOptionalFinishNull() ) {
				if( getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionByFinishIdxKey::operator !=( const CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionByFinishIdxKey::operator !=( const CFSecSecSessionHBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionByFinishIdxKey::operator !=( const CFSecSecSessionBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecSecSessionByFinishIdxKey::operator >=( const CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionByFinishIdxKey::operator >=( const CFSecSecSessionHBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionByFinishIdxKey::operator >=( const CFSecSecSessionBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecSecSessionByFinishIdxKey::operator >( const CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFSecSecSessionByFinishIdxKey::operator >( const CFSecSecSessionHBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFSecSecSessionByFinishIdxKey::operator >( const CFSecSecSessionBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}
	CFSecSecSessionByFinishIdxKey CFSecSecSessionByFinishIdxKey::operator =( cfsec::CFSecSecSessionByFinishIdxKey& src ) {
		setRequiredSecUserId( src.getRequiredSecUserId() );
		if( src.isOptionalFinishNull() ) {
			setOptionalFinishNull();
		}
		else {
			setOptionalFinishValue( src.getOptionalFinishValue() );
		}
		return( *this );
	}

	CFSecSecSessionByFinishIdxKey CFSecSecSessionByFinishIdxKey::operator =( cfsec::CFSecSecSessionBuff& src ) {
		setRequiredSecUserId( src.getRequiredSecUserId() );
		if( src.isOptionalFinishNull() ) {
			setOptionalFinishNull();
		}
		else {
			setOptionalFinishValue( src.getOptionalFinishValue() );
		}
		return( *this );
	}

	CFSecSecSessionByFinishIdxKey CFSecSecSessionByFinishIdxKey::operator =( cfsec::CFSecSecSessionHBuff& src ) {
		setRequiredSecUserId( src.getRequiredSecUserId() );
		if( src.isOptionalFinishNull() ) {
			setOptionalFinishNull();
		}
		else {
			setOptionalFinishValue( src.getOptionalFinishValue() );
		}
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( false );
			}
			if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( ! rhs.isOptionalFinishNull() ) {
				if( lhs.getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
					return( false );
				}
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( ! rhs.isOptionalFinishNull() ) {
				if( lhs.getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
					return( false );
				}
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( ! rhs.isOptionalFinishNull() ) {
				if( lhs.getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
					return( false );
				}
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( lhs.getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( lhs.getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( lhs.getOptionalFinishValue() != rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionByFinishIdxKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionHBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecSessionByFinishIdxKey& lhs, const cfsec::CFSecSecSessionBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( ! lhs.isOptionalFinishNull() ) {
			if( rhs.isOptionalFinishNull() ) {
				return( true );
			}
			if( lhs.getOptionalFinishValue() < rhs.getOptionalFinishValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFinishValue() > rhs.getOptionalFinishValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFinishNull() ) {
				return( false );
			}
		}
		return( false );
	}
}

