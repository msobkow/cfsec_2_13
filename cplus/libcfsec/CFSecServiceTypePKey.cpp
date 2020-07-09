// Description: C++18 implementation of a ServiceType primary key object.

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

#include <cfsec/CFSecServiceTypePKey.hpp>
#include <cfsec/CFSecServiceTypeBuff.hpp>
#include <cfsec/CFSecServiceTypeHPKey.hpp>
#include <cfsec/CFSecServiceTypeHBuff.hpp>

namespace cfsec {

	const std::string CFSecServiceTypePKey::CLASS_NAME( "CFSecServiceTypePKey" );
	const std::string CFSecServiceTypePKey::S_VALUE( "value" );
	const std::string CFSecServiceTypePKey::S_VALUE_LENGTH( "value.length()" );

	CFSecServiceTypePKey::CFSecServiceTypePKey() {
		requiredServiceTypeId = cfsec::CFSecServiceTypeBuff::SERVICETYPEID_INIT_VALUE;
	}

	CFSecServiceTypePKey::CFSecServiceTypePKey( const CFSecServiceTypePKey& src ) {
		requiredServiceTypeId = cfsec::CFSecServiceTypeBuff::SERVICETYPEID_INIT_VALUE;
		setRequiredServiceTypeId( src.getRequiredServiceTypeId() );
	}

	CFSecServiceTypePKey::~CFSecServiceTypePKey() {
	}

	const int32_t CFSecServiceTypePKey::getRequiredServiceTypeId() const {
		return( requiredServiceTypeId );
	}

	const int32_t* CFSecServiceTypePKey::getRequiredServiceTypeIdReference() const {
		return( &requiredServiceTypeId );
	}

	void CFSecServiceTypePKey::setRequiredServiceTypeId( const int32_t value ) {
		static const std::string S_ProcName( "setRequiredServiceTypeId" );
		if( value < cfsec::CFSecServiceTypeBuff::SERVICETYPEID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecServiceTypeBuff::SERVICETYPEID_MIN_VALUE );
		}
		requiredServiceTypeId = value;
	}

	bool CFSecServiceTypePKey::operator <( const CFSecServiceTypeHPKey& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypePKey::operator <( const CFSecServiceTypePKey& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypePKey::operator <( const CFSecServiceTypeHBuff& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypePKey::operator <( const CFSecServiceTypeBuff& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypePKey::operator <=( const CFSecServiceTypeHPKey& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceTypePKey::operator <=( const CFSecServiceTypePKey& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceTypePKey::operator <=( const CFSecServiceTypeHBuff& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceTypePKey::operator <=( const CFSecServiceTypeBuff& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceTypePKey::operator ==( const CFSecServiceTypeHPKey& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceTypePKey::operator ==( const CFSecServiceTypePKey& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceTypePKey::operator ==( const CFSecServiceTypeHBuff& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceTypePKey::operator ==( const CFSecServiceTypeBuff& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceTypePKey::operator !=( const CFSecServiceTypeHPKey& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypePKey::operator !=( const CFSecServiceTypePKey& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypePKey::operator !=( const CFSecServiceTypeHBuff& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypePKey::operator !=( const CFSecServiceTypeBuff& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypePKey::operator >=( const CFSecServiceTypeHPKey& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceTypePKey::operator >=( const CFSecServiceTypePKey& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceTypePKey::operator >=( const CFSecServiceTypeHBuff& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceTypePKey::operator >=( const CFSecServiceTypeBuff& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceTypePKey::operator >( const CFSecServiceTypeHPKey& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypePKey::operator >( const CFSecServiceTypePKey& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypePKey::operator >( const CFSecServiceTypeHBuff& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypePKey::operator >( const CFSecServiceTypeBuff& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	CFSecServiceTypePKey CFSecServiceTypePKey::operator =( cfsec::CFSecServiceTypePKey& src ) {
		setRequiredServiceTypeId( src.getRequiredServiceTypeId() );
		return( *this );
	}

	CFSecServiceTypePKey CFSecServiceTypePKey::operator =( cfsec::CFSecServiceTypeHPKey& src ) {
		setRequiredServiceTypeId( src.getRequiredServiceTypeId() );
		return( *this );
	}

	CFSecServiceTypePKey CFSecServiceTypePKey::operator =( cfsec::CFSecServiceTypeBuff& src ) {
		setRequiredServiceTypeId( src.getRequiredServiceTypeId() );
		return( *this );
	}

	CFSecServiceTypePKey CFSecServiceTypePKey::operator =( cfsec::CFSecServiceTypeHBuff& src ) {
		setRequiredServiceTypeId( src.getRequiredServiceTypeId() );
		return( *this );
	}

	size_t CFSecServiceTypePKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + getRequiredServiceTypeId();
		return( hashCode );
	}

	std::string CFSecServiceTypePKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecServiceTypePKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ServiceTypeId( "ServiceTypeId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_ServiceTypeId, getRequiredServiceTypeId() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHPKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypePKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHPKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypePKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHPKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypePKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHPKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypePKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHPKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypePKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHPKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypePKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecServiceTypePKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}
}

