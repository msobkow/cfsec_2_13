// Description: C++18 implementation for a ServiceType by UDescrIdx index key object.

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

#include <cfsec/CFSecServiceTypeByUDescrIdxKey.hpp>
#include <cfsec/CFSecServiceTypeBuff.hpp>
#include <cfsec/CFSecServiceTypeHBuff.hpp>

namespace cfsec {
	const std::string CFSecServiceTypeByUDescrIdxKey::CLASS_NAME( "CFSecServiceTypeByUDescrIdxKey" );
	const std::string CFSecServiceTypeByUDescrIdxKey::S_VALUE( "value" );
	const std::string CFSecServiceTypeByUDescrIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecServiceTypeByUDescrIdxKey::CFSecServiceTypeByUDescrIdxKey() {
		requiredDescription = new std::string( cfsec::CFSecServiceTypeBuff::DESCRIPTION_INIT_VALUE );
	}

	CFSecServiceTypeByUDescrIdxKey::CFSecServiceTypeByUDescrIdxKey( const CFSecServiceTypeByUDescrIdxKey& src ) {
		requiredDescription = new std::string( cfsec::CFSecServiceTypeBuff::DESCRIPTION_INIT_VALUE );
		setRequiredDescription( src.getRequiredDescription() );
	}

	CFSecServiceTypeByUDescrIdxKey::~CFSecServiceTypeByUDescrIdxKey() {
		if( requiredDescription != NULL ) {
			delete requiredDescription;
			requiredDescription = NULL;
		}
	}

	const std::string& CFSecServiceTypeByUDescrIdxKey::getRequiredDescription() const {
		return( *requiredDescription );
	}

	const std::string* CFSecServiceTypeByUDescrIdxKey::getRequiredDescriptionReference() const {
		return( requiredDescription );
	}

	void CFSecServiceTypeByUDescrIdxKey::setRequiredDescription( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredDescription" );
		if( value.length() > CFSecServiceTypeBuff::DESCRIPTION_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecServiceTypeBuff::DESCRIPTION_MAX_LEN );
		}
		if( requiredDescription != NULL ) {
			delete requiredDescription;
			requiredDescription = NULL;
		}
		requiredDescription = new std::string( value );
	}

	size_t CFSecServiceTypeByUDescrIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + cflib::CFLib::hash( getRequiredDescription() );
		return( hashCode );
	}

	std::string CFSecServiceTypeByUDescrIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecServiceTypeByUDescrIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Description( "Description" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, getRequiredDescription() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecServiceTypeByUDescrIdxKey::operator <( const CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypeByUDescrIdxKey::operator <( const CFSecServiceTypeHBuff& rhs ) {
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypeByUDescrIdxKey::operator <( const CFSecServiceTypeBuff& rhs ) {
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypeByUDescrIdxKey::operator <=( const CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceTypeByUDescrIdxKey::operator <=( const CFSecServiceTypeHBuff& rhs ) {
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceTypeByUDescrIdxKey::operator <=( const CFSecServiceTypeBuff& rhs ) {
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceTypeByUDescrIdxKey::operator ==( const CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceTypeByUDescrIdxKey::operator ==( const CFSecServiceTypeHBuff& rhs ) {
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceTypeByUDescrIdxKey::operator ==( const CFSecServiceTypeBuff& rhs ) {
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceTypeByUDescrIdxKey::operator !=( const CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypeByUDescrIdxKey::operator !=( const CFSecServiceTypeHBuff& rhs ) {
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypeByUDescrIdxKey::operator !=( const CFSecServiceTypeBuff& rhs ) {
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypeByUDescrIdxKey::operator >=( const CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceTypeByUDescrIdxKey::operator >=( const CFSecServiceTypeHBuff& rhs ) {
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceTypeByUDescrIdxKey::operator >=( const CFSecServiceTypeBuff& rhs ) {
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceTypeByUDescrIdxKey::operator >( const CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypeByUDescrIdxKey::operator >( const CFSecServiceTypeHBuff& rhs ) {
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceTypeByUDescrIdxKey::operator >( const CFSecServiceTypeBuff& rhs ) {
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}
	CFSecServiceTypeByUDescrIdxKey CFSecServiceTypeByUDescrIdxKey::operator =( cfsec::CFSecServiceTypeByUDescrIdxKey& src ) {
		setRequiredDescription( src.getRequiredDescription() );
		return( *this );
	}

	CFSecServiceTypeByUDescrIdxKey CFSecServiceTypeByUDescrIdxKey::operator =( cfsec::CFSecServiceTypeBuff& src ) {
		setRequiredDescription( src.getRequiredDescription() );
		return( *this );
	}

	CFSecServiceTypeByUDescrIdxKey CFSecServiceTypeByUDescrIdxKey::operator =( cfsec::CFSecServiceTypeHBuff& src ) {
		setRequiredDescription( src.getRequiredDescription() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs ) {
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs ) {
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs ) {
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs ) {
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs ) {
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs ) {
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs ) {
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs ) {
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs ) {
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs ) {
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeHBuff& rhs ) {
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecServiceTypeByUDescrIdxKey& lhs, const cfsec::CFSecServiceTypeBuff& rhs ) {
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}
}

