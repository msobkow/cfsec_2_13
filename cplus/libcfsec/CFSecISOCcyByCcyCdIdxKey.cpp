// Description: C++18 implementation for a ISOCcy by CcyCdIdx index key object.

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

#include <cfsec/CFSecISOCcyByCcyCdIdxKey.hpp>
#include <cfsec/CFSecISOCcyBuff.hpp>
#include <cfsec/CFSecISOCcyHBuff.hpp>

namespace cfsec {
	const std::string CFSecISOCcyByCcyCdIdxKey::CLASS_NAME( "CFSecISOCcyByCcyCdIdxKey" );
	const std::string CFSecISOCcyByCcyCdIdxKey::S_VALUE( "value" );
	const std::string CFSecISOCcyByCcyCdIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecISOCcyByCcyCdIdxKey::CFSecISOCcyByCcyCdIdxKey() {
		requiredISOCode = new std::string( cfsec::CFSecISOCcyBuff::ISOCODE_INIT_VALUE );
	}

	CFSecISOCcyByCcyCdIdxKey::CFSecISOCcyByCcyCdIdxKey( const CFSecISOCcyByCcyCdIdxKey& src ) {
		requiredISOCode = new std::string( cfsec::CFSecISOCcyBuff::ISOCODE_INIT_VALUE );
		setRequiredISOCode( src.getRequiredISOCode() );
	}

	CFSecISOCcyByCcyCdIdxKey::~CFSecISOCcyByCcyCdIdxKey() {
		if( requiredISOCode != NULL ) {
			delete requiredISOCode;
			requiredISOCode = NULL;
		}
	}

	const std::string& CFSecISOCcyByCcyCdIdxKey::getRequiredISOCode() const {
		return( *requiredISOCode );
	}

	const std::string* CFSecISOCcyByCcyCdIdxKey::getRequiredISOCodeReference() const {
		return( requiredISOCode );
	}

	void CFSecISOCcyByCcyCdIdxKey::setRequiredISOCode( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredISOCode" );
		if( value.length() > CFSecISOCcyBuff::ISOCODE_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecISOCcyBuff::ISOCODE_MAX_LEN );
		}
		if( requiredISOCode != NULL ) {
			delete requiredISOCode;
			requiredISOCode = NULL;
		}
		requiredISOCode = new std::string( value );
	}

	size_t CFSecISOCcyByCcyCdIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + cflib::CFLib::hash( getRequiredISOCode() );
		return( hashCode );
	}

	std::string CFSecISOCcyByCcyCdIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOCcyByCcyCdIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ISOCode( "ISOCode" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_ISOCode, getRequiredISOCode() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecISOCcyByCcyCdIdxKey::operator <( const CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyByCcyCdIdxKey::operator <( const CFSecISOCcyHBuff& rhs ) {
		if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyByCcyCdIdxKey::operator <( const CFSecISOCcyBuff& rhs ) {
		if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyByCcyCdIdxKey::operator <=( const CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyByCcyCdIdxKey::operator <=( const CFSecISOCcyHBuff& rhs ) {
		if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyByCcyCdIdxKey::operator <=( const CFSecISOCcyBuff& rhs ) {
		if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyByCcyCdIdxKey::operator ==( const CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCcyByCcyCdIdxKey::operator ==( const CFSecISOCcyHBuff& rhs ) {
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCcyByCcyCdIdxKey::operator ==( const CFSecISOCcyBuff& rhs ) {
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCcyByCcyCdIdxKey::operator !=( const CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyByCcyCdIdxKey::operator !=( const CFSecISOCcyHBuff& rhs ) {
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyByCcyCdIdxKey::operator !=( const CFSecISOCcyBuff& rhs ) {
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyByCcyCdIdxKey::operator >=( const CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyByCcyCdIdxKey::operator >=( const CFSecISOCcyHBuff& rhs ) {
		if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyByCcyCdIdxKey::operator >=( const CFSecISOCcyBuff& rhs ) {
		if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCcyByCcyCdIdxKey::operator >( const CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyByCcyCdIdxKey::operator >( const CFSecISOCcyHBuff& rhs ) {
		if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCcyByCcyCdIdxKey::operator >( const CFSecISOCcyBuff& rhs ) {
		if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}
	CFSecISOCcyByCcyCdIdxKey CFSecISOCcyByCcyCdIdxKey::operator =( cfsec::CFSecISOCcyByCcyCdIdxKey& src ) {
		setRequiredISOCode( src.getRequiredISOCode() );
		return( *this );
	}

	CFSecISOCcyByCcyCdIdxKey CFSecISOCcyByCcyCdIdxKey::operator =( cfsec::CFSecISOCcyBuff& src ) {
		setRequiredISOCode( src.getRequiredISOCode() );
		return( *this );
	}

	CFSecISOCcyByCcyCdIdxKey CFSecISOCcyByCcyCdIdxKey::operator =( cfsec::CFSecISOCcyHBuff& src ) {
		setRequiredISOCode( src.getRequiredISOCode() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
		if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
		if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
		if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
		if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
		if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
		if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyByCcyCdIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyHBuff& rhs ) {
		if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCcyByCcyCdIdxKey& lhs, const cfsec::CFSecISOCcyBuff& rhs ) {
		if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}
}

