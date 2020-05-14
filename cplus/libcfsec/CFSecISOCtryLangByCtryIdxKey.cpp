// Description: C++18 implementation for a ISOCtryLang by CtryIdx index key object.

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

#include <cfsec/CFSecISOCtryLangByCtryIdxKey.hpp>
#include <cfsec/CFSecISOCtryLangBuff.hpp>
#include <cfsec/CFSecISOCtryLangHBuff.hpp>

namespace cfsec {
	const std::string CFSecISOCtryLangByCtryIdxKey::CLASS_NAME( "CFSecISOCtryLangByCtryIdxKey" );
	const std::string CFSecISOCtryLangByCtryIdxKey::S_VALUE( "value" );
	const std::string CFSecISOCtryLangByCtryIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecISOCtryLangByCtryIdxKey::CFSecISOCtryLangByCtryIdxKey() {
		requiredISOCtryId = cfsec::CFSecISOCtryLangBuff::ISOCTRYID_INIT_VALUE;
	}

	CFSecISOCtryLangByCtryIdxKey::CFSecISOCtryLangByCtryIdxKey( const CFSecISOCtryLangByCtryIdxKey& src ) {
		requiredISOCtryId = cfsec::CFSecISOCtryLangBuff::ISOCTRYID_INIT_VALUE;
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
	}

	CFSecISOCtryLangByCtryIdxKey::~CFSecISOCtryLangByCtryIdxKey() {
	}

	const int16_t CFSecISOCtryLangByCtryIdxKey::getRequiredISOCtryId() const {
		return( requiredISOCtryId );
	}

	const int16_t* CFSecISOCtryLangByCtryIdxKey::getRequiredISOCtryIdReference() const {
		return( &requiredISOCtryId );
	}

	void CFSecISOCtryLangByCtryIdxKey::setRequiredISOCtryId( const int16_t value ) {
		static const std::string S_ProcName( "setRequiredISOCtryId" );
		if( value < cfsec::CFSecISOCtryLangBuff::ISOCTRYID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOCtryLangBuff::ISOCTRYID_MIN_VALUE );
		}
		requiredISOCtryId = value;
	}

	size_t CFSecISOCtryLangByCtryIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOCtryId();
		return( hashCode );
	}

	std::string CFSecISOCtryLangByCtryIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOCtryLangByCtryIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ISOCtryId( "ISOCtryId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCtryId, getRequiredISOCtryId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecISOCtryLangByCtryIdxKey::operator <( const CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangByCtryIdxKey::operator <( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangByCtryIdxKey::operator <( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangByCtryIdxKey::operator <=( const CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangByCtryIdxKey::operator <=( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangByCtryIdxKey::operator <=( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangByCtryIdxKey::operator ==( const CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryLangByCtryIdxKey::operator ==( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryLangByCtryIdxKey::operator ==( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryLangByCtryIdxKey::operator !=( const CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangByCtryIdxKey::operator !=( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangByCtryIdxKey::operator !=( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangByCtryIdxKey::operator >=( const CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangByCtryIdxKey::operator >=( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangByCtryIdxKey::operator >=( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangByCtryIdxKey::operator >( const CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangByCtryIdxKey::operator >( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangByCtryIdxKey::operator >( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}
	CFSecISOCtryLangByCtryIdxKey CFSecISOCtryLangByCtryIdxKey::operator =( cfsec::CFSecISOCtryLangByCtryIdxKey& src ) {
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		return( *this );
	}

	CFSecISOCtryLangByCtryIdxKey CFSecISOCtryLangByCtryIdxKey::operator =( cfsec::CFSecISOCtryLangBuff& src ) {
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		return( *this );
	}

	CFSecISOCtryLangByCtryIdxKey CFSecISOCtryLangByCtryIdxKey::operator =( cfsec::CFSecISOCtryLangHBuff& src ) {
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecISOCtryLangByCtryIdxKey& lhs, const cfsec::CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryLangByCtryIdxKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryLangByCtryIdxKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecISOCtryLangByCtryIdxKey& lhs, const cfsec::CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryLangByCtryIdxKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryLangByCtryIdxKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryLangByCtryIdxKey& lhs, const cfsec::CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryLangByCtryIdxKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryLangByCtryIdxKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOCtryLangByCtryIdxKey& lhs, const cfsec::CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryLangByCtryIdxKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryLangByCtryIdxKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOCtryLangByCtryIdxKey& lhs, const cfsec::CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryLangByCtryIdxKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryLangByCtryIdxKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecISOCtryLangByCtryIdxKey& lhs, const cfsec::CFSecISOCtryLangByCtryIdxKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryLangByCtryIdxKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryLangByCtryIdxKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		return( false );
	}
}

