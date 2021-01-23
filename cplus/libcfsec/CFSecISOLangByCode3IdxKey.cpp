// Description: C++18 implementation for a ISOLang by Code3Idx index key object.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at mark.sobkow@gmail.com for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <cflib/ICFLibPublic.hpp>

using namespace std;

#include <cfsec/CFSecISOLangByCode3IdxKey.hpp>
#include <cfsec/CFSecISOLangBuff.hpp>
#include <cfsec/CFSecISOLangHBuff.hpp>

namespace cfsec {
	const std::string CFSecISOLangByCode3IdxKey::CLASS_NAME( "CFSecISOLangByCode3IdxKey" );
	const std::string CFSecISOLangByCode3IdxKey::S_VALUE( "value" );
	const std::string CFSecISOLangByCode3IdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecISOLangByCode3IdxKey::CFSecISOLangByCode3IdxKey() {
		requiredISO6392Code = new std::string( cfsec::CFSecISOLangBuff::ISO6392CODE_INIT_VALUE );
	}

	CFSecISOLangByCode3IdxKey::CFSecISOLangByCode3IdxKey( const CFSecISOLangByCode3IdxKey& src ) {
		requiredISO6392Code = new std::string( cfsec::CFSecISOLangBuff::ISO6392CODE_INIT_VALUE );
		setRequiredISO6392Code( src.getRequiredISO6392Code() );
	}

	CFSecISOLangByCode3IdxKey::~CFSecISOLangByCode3IdxKey() {
		if( requiredISO6392Code != NULL ) {
			delete requiredISO6392Code;
			requiredISO6392Code = NULL;
		}
	}

	const std::string& CFSecISOLangByCode3IdxKey::getRequiredISO6392Code() const {
		return( *requiredISO6392Code );
	}

	const std::string* CFSecISOLangByCode3IdxKey::getRequiredISO6392CodeReference() const {
		return( requiredISO6392Code );
	}

	void CFSecISOLangByCode3IdxKey::setRequiredISO6392Code( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredISO6392Code" );
		if( value.length() > CFSecISOLangBuff::ISO6392CODE_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecISOLangBuff::ISO6392CODE_MAX_LEN );
		}
		if( requiredISO6392Code != NULL ) {
			delete requiredISO6392Code;
			requiredISO6392Code = NULL;
		}
		requiredISO6392Code = new std::string( value );
	}

	size_t CFSecISOLangByCode3IdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + cflib::CFLib::hash( getRequiredISO6392Code() );
		return( hashCode );
	}

	std::string CFSecISOLangByCode3IdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOLangByCode3IdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ISO6392Code( "ISO6392Code" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_ISO6392Code, getRequiredISO6392Code() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecISOLangByCode3IdxKey::operator <( const CFSecISOLangByCode3IdxKey& rhs ) {
		if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangByCode3IdxKey::operator <( const CFSecISOLangHBuff& rhs ) {
		if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangByCode3IdxKey::operator <( const CFSecISOLangBuff& rhs ) {
		if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangByCode3IdxKey::operator <=( const CFSecISOLangByCode3IdxKey& rhs ) {
		if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangByCode3IdxKey::operator <=( const CFSecISOLangHBuff& rhs ) {
		if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangByCode3IdxKey::operator <=( const CFSecISOLangBuff& rhs ) {
		if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangByCode3IdxKey::operator ==( const CFSecISOLangByCode3IdxKey& rhs ) {
		if( getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOLangByCode3IdxKey::operator ==( const CFSecISOLangHBuff& rhs ) {
		if( getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOLangByCode3IdxKey::operator ==( const CFSecISOLangBuff& rhs ) {
		if( getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOLangByCode3IdxKey::operator !=( const CFSecISOLangByCode3IdxKey& rhs ) {
		if( getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangByCode3IdxKey::operator !=( const CFSecISOLangHBuff& rhs ) {
		if( getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangByCode3IdxKey::operator !=( const CFSecISOLangBuff& rhs ) {
		if( getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangByCode3IdxKey::operator >=( const CFSecISOLangByCode3IdxKey& rhs ) {
		if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangByCode3IdxKey::operator >=( const CFSecISOLangHBuff& rhs ) {
		if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangByCode3IdxKey::operator >=( const CFSecISOLangBuff& rhs ) {
		if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangByCode3IdxKey::operator >( const CFSecISOLangByCode3IdxKey& rhs ) {
		if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangByCode3IdxKey::operator >( const CFSecISOLangHBuff& rhs ) {
		if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangByCode3IdxKey::operator >( const CFSecISOLangBuff& rhs ) {
		if( getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}
	CFSecISOLangByCode3IdxKey CFSecISOLangByCode3IdxKey::operator =( cfsec::CFSecISOLangByCode3IdxKey& src ) {
		setRequiredISO6392Code( src.getRequiredISO6392Code() );
		return( *this );
	}

	CFSecISOLangByCode3IdxKey CFSecISOLangByCode3IdxKey::operator =( cfsec::CFSecISOLangBuff& src ) {
		setRequiredISO6392Code( src.getRequiredISO6392Code() );
		return( *this );
	}

	CFSecISOLangByCode3IdxKey CFSecISOLangByCode3IdxKey::operator =( cfsec::CFSecISOLangHBuff& src ) {
		setRequiredISO6392Code( src.getRequiredISO6392Code() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs ) {
		if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs ) {
		if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs ) {
		if( lhs.getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( lhs.getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs ) {
		if( lhs.getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( lhs.getRequiredISO6392Code() != rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs ) {
		if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangByCode3IdxKey& rhs ) {
		if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOLangByCode3IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( lhs.getRequiredISO6392Code() < rhs.getRequiredISO6392Code() ) {
			return( false );
		}
		else if( lhs.getRequiredISO6392Code() > rhs.getRequiredISO6392Code() ) {
			return( true );
		}
		return( false );
	}
}

