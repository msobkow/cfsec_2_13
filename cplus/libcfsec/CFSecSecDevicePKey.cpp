// Description: C++18 implementation of a SecDevice primary key object.

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

#include <cfsec/CFSecSecDevicePKey.hpp>
#include <cfsec/CFSecSecDeviceBuff.hpp>
#include <cfsec/CFSecSecDeviceHPKey.hpp>
#include <cfsec/CFSecSecDeviceHBuff.hpp>

namespace cfsec {

	const std::string CFSecSecDevicePKey::CLASS_NAME( "CFSecSecDevicePKey" );
	const std::string CFSecSecDevicePKey::S_VALUE( "value" );
	const std::string CFSecSecDevicePKey::S_VALUE_LENGTH( "value.length()" );

	CFSecSecDevicePKey::CFSecSecDevicePKey() {
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
		requiredDevName = new std::string( cfsec::CFSecSecDeviceBuff::DEVNAME_INIT_VALUE );
	}

	CFSecSecDevicePKey::CFSecSecDevicePKey( const CFSecSecDevicePKey& src ) {
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
		requiredDevName = new std::string( cfsec::CFSecSecDeviceBuff::DEVNAME_INIT_VALUE );
		setRequiredSecUserId( src.getRequiredSecUserId() );
		setRequiredDevName( src.getRequiredDevName() );
	}

	CFSecSecDevicePKey::~CFSecSecDevicePKey() {
		for( int i = 0; i < 16; i ++ ) {
			requiredSecUserId[i] = 0;
		}
		if( requiredDevName != NULL ) {
			delete requiredDevName;
			requiredDevName = NULL;
		}
	}

	const uuid_ptr_t CFSecSecDevicePKey::getRequiredSecUserId() const {
		return( requiredSecUserId );
	}

	const uuid_ptr_t CFSecSecDevicePKey::getRequiredSecUserIdReference() const {
		return( requiredSecUserId );
	}

	void CFSecSecDevicePKey::setRequiredSecUserId( const uuid_ptr_t value ) {
		uuid_copy( requiredSecUserId, value );
	}

	void CFSecSecDevicePKey::generateRequiredSecUserId() {
		uuid_generate_random( requiredSecUserId );
	}

	const std::string& CFSecSecDevicePKey::getRequiredDevName() const {
		return( *requiredDevName );
	}

	const std::string* CFSecSecDevicePKey::getRequiredDevNameReference() const {
		return( requiredDevName );
	}

	void CFSecSecDevicePKey::setRequiredDevName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredDevName" );
		if( value.length() > CFSecSecDeviceBuff::DEVNAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecSecDeviceBuff::DEVNAME_MAX_LEN );
		}
		if( requiredDevName != NULL ) {
			delete requiredDevName;
			requiredDevName = NULL;
		}
		requiredDevName = new std::string( value );
	}

	bool CFSecSecDevicePKey::operator <( const CFSecSecDeviceHPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecDevicePKey::operator <( const CFSecSecDevicePKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecDevicePKey::operator <( const CFSecSecDeviceHBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecDevicePKey::operator <( const CFSecSecDeviceBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecDevicePKey::operator <=( const CFSecSecDeviceHPKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecDevicePKey::operator <=( const CFSecSecDevicePKey& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecDevicePKey::operator <=( const CFSecSecDeviceHBuff& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecDevicePKey::operator <=( const CFSecSecDeviceBuff& rhs ) {
		if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecDevicePKey::operator ==( const CFSecSecDeviceHPKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecDevicePKey::operator ==( const CFSecSecDevicePKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecDevicePKey::operator ==( const CFSecSecDeviceHBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecDevicePKey::operator ==( const CFSecSecDeviceBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecDevicePKey::operator !=( const CFSecSecDeviceHPKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecDevicePKey::operator !=( const CFSecSecDevicePKey& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecDevicePKey::operator !=( const CFSecSecDeviceHBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecDevicePKey::operator !=( const CFSecSecDeviceBuff& rhs ) {
		if( 0 != uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecDevicePKey::operator >=( const CFSecSecDeviceHPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecDevicePKey::operator >=( const CFSecSecDevicePKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecDevicePKey::operator >=( const CFSecSecDeviceHBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecDevicePKey::operator >=( const CFSecSecDeviceBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecDevicePKey::operator >( const CFSecSecDeviceHPKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecDevicePKey::operator >( const CFSecSecDevicePKey& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecDevicePKey::operator >( const CFSecSecDeviceHBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecDevicePKey::operator >( const CFSecSecDeviceBuff& rhs ) {
		if( 0 > uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	CFSecSecDevicePKey CFSecSecDevicePKey::operator =( cfsec::CFSecSecDevicePKey& src ) {
		setRequiredSecUserId( src.getRequiredSecUserId() );
		setRequiredDevName( src.getRequiredDevName() );
		return( *this );
	}

	CFSecSecDevicePKey CFSecSecDevicePKey::operator =( cfsec::CFSecSecDeviceHPKey& src ) {
		setRequiredSecUserId( src.getRequiredSecUserId() );
		setRequiredDevName( src.getRequiredDevName() );
		return( *this );
	}

	CFSecSecDevicePKey CFSecSecDevicePKey::operator =( cfsec::CFSecSecDeviceBuff& src ) {
		setRequiredSecUserId( src.getRequiredSecUserId() );
		setRequiredDevName( src.getRequiredDevName() );
		return( *this );
	}

	CFSecSecDevicePKey CFSecSecDevicePKey::operator =( cfsec::CFSecSecDeviceHBuff& src ) {
		setRequiredSecUserId( src.getRequiredSecUserId() );
		setRequiredDevName( src.getRequiredDevName() );
		return( *this );
	}

	size_t CFSecSecDevicePKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + cflib::CFLib::hash( getRequiredSecUserId() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredDevName() );
		return( hashCode );
	}

	std::string CFSecSecDevicePKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecDevicePKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_SecUserId( "SecUserId" );
		static const std::string S_DevName( "DevName" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, getRequiredSecUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_DevName, getRequiredDevName() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDeviceHPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDevicePKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDeviceHBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDeviceBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDeviceHPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDevicePKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDeviceHBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDeviceBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDeviceHPKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( lhs.getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDevicePKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( lhs.getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDeviceHBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( lhs.getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDeviceBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		if( lhs.getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDeviceHPKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDevicePKey& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDeviceHBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDeviceBuff& rhs ) {
		if( 0 != uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() != rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDeviceHPKey& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDevicePKey& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDeviceHBuff& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDeviceBuff& rhs ) {
		if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDeviceHPKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDevicePKey& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDeviceHBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecDevicePKey& lhs, const cfsec::CFSecSecDeviceBuff& rhs ) {
		if( 0 < uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( false );
		}
		else if( 0 > uuid_compare( lhs.getRequiredSecUserId(), rhs.getRequiredSecUserId() ) ) {
			return( true );
		}
		if( lhs.getRequiredDevName() < rhs.getRequiredDevName() ) {
			return( false );
		}
		else if( lhs.getRequiredDevName() > rhs.getRequiredDevName() ) {
			return( true );
		}
		return( false );
	}
}

