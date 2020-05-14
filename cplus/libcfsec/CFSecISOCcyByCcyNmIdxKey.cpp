// Description: C++18 implementation for a ISOCcy by CcyNmIdx index key object.

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

#include <cfsec/CFSecISOCcyByCcyNmIdxKey.hpp>
#include <cfsec/CFSecISOCcyBuff.hpp>
#include <cfsec/CFSecISOCcyHBuff.hpp>

namespace cfsec {
	const std::string CFSecISOCcyByCcyNmIdxKey::CLASS_NAME( "CFSecISOCcyByCcyNmIdxKey" );
	const std::string CFSecISOCcyByCcyNmIdxKey::S_VALUE( "value" );
	const std::string CFSecISOCcyByCcyNmIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecISOCcyByCcyNmIdxKey::CFSecISOCcyByCcyNmIdxKey() {
		requiredName = new std::string( cfsec::CFSecISOCcyBuff::NAME_INIT_VALUE );
	}

	CFSecISOCcyByCcyNmIdxKey::CFSecISOCcyByCcyNmIdxKey( const CFSecISOCcyByCcyNmIdxKey& src ) {
		requiredName = new std::string( cfsec::CFSecISOCcyBuff::NAME_INIT_VALUE );
		setRequiredName( src.getRequiredName() );
	}

	CFSecISOCcyByCcyNmIdxKey::~CFSecISOCcyByCcyNmIdxKey() {
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
	}

	const std::string& CFSecISOCcyByCcyNmIdxKey::getRequiredName() const {
		return( *requiredName );
	}

	const std::string* CFSecISOCcyByCcyNmIdxKey::getRequiredNameReference() const {
		return( requiredName );
	}

	void CFSecISOCcyByCcyNmIdxKey::setRequiredName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredName" );
		if( value.length() > CFSecISOCcyBuff::NAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecISOCcyBuff::NAME_MAX_LEN );
		}
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
		requiredName = new std::string( value );
	}

	size_t CFSecISOCcyByCcyNmIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + cflib::CFLib::hash( getRequiredName() );
		return( hashCode );
	}

	std::string CFSecISOCcyByCcyNmIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOCcyByCcyNmIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Name( "Name" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, getRequiredName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecISOCcyByCcyNmIdxKey::operator <( const CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyByCcyNmIdxKey::operator <( const CFSecISOCcyHBuff& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyByCcyNmIdxKey::operator <( const CFSecISOCcyBuff& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyByCcyNmIdxKey::operator <=( const CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyByCcyNmIdxKey::operator <=( const CFSecISOCcyHBuff& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyByCcyNmIdxKey::operator <=( const CFSecISOCcyBuff& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyByCcyNmIdxKey::operator ==( const CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCcyByCcyNmIdxKey::operator ==( const CFSecISOCcyHBuff& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCcyByCcyNmIdxKey::operator ==( const CFSecISOCcyBuff& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCcyByCcyNmIdxKey::operator !=( const CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyByCcyNmIdxKey::operator !=( const CFSecISOCcyHBuff& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyByCcyNmIdxKey::operator !=( const CFSecISOCcyBuff& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyByCcyNmIdxKey::operator >=( const CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyByCcyNmIdxKey::operator >=( const CFSecISOCcyHBuff& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyByCcyNmIdxKey::operator >=( const CFSecISOCcyBuff& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyByCcyNmIdxKey::operator >( const CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyByCcyNmIdxKey::operator >( const CFSecISOCcyHBuff& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyByCcyNmIdxKey::operator >( const CFSecISOCcyBuff& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}
	CFSecISOCcyByCcyNmIdxKey CFSecISOCcyByCcyNmIdxKey::operator =( cfsec::CFSecISOCcyByCcyNmIdxKey& src ) {
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

	CFSecISOCcyByCcyNmIdxKey CFSecISOCcyByCcyNmIdxKey::operator =( cfsec::CFSecISOCcyBuff& src ) {
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

	CFSecISOCcyByCcyNmIdxKey CFSecISOCcyByCcyNmIdxKey::operator =( cfsec::CFSecISOCcyHBuff& src ) {
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyByCcyNmIdxKey& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCcyByCcyNmIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}
}

