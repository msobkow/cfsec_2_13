// Description: C++18 implementation for a ISOLang by Code2Idx index key object.

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

#include <cfsec/CFSecISOLangByCode2IdxKey.hpp>
#include <cfsec/CFSecISOLangBuff.hpp>
#include <cfsec/CFSecISOLangHBuff.hpp>

namespace cfsec {
	const std::string CFSecISOLangByCode2IdxKey::CLASS_NAME( "CFSecISOLangByCode2IdxKey" );
	const std::string CFSecISOLangByCode2IdxKey::S_VALUE( "value" );
	const std::string CFSecISOLangByCode2IdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecISOLangByCode2IdxKey::CFSecISOLangByCode2IdxKey() {
		optionalISO6391Code = NULL;
	}

	CFSecISOLangByCode2IdxKey::CFSecISOLangByCode2IdxKey( const CFSecISOLangByCode2IdxKey& src ) {
		optionalISO6391Code = NULL;
		if( src.isOptionalISO6391CodeNull() ) {
			setOptionalISO6391CodeNull();
		}
		else {
			setOptionalISO6391CodeValue( src.getOptionalISO6391CodeValue() );
		}
	}

	CFSecISOLangByCode2IdxKey::~CFSecISOLangByCode2IdxKey() {
		if( optionalISO6391Code != NULL ) {
			delete optionalISO6391Code;
			optionalISO6391Code = NULL;
		}
	}

	const std::string& CFSecISOLangByCode2IdxKey::getOptionalISO6391CodeValue() const {
		static const std::string S_ProcName( "getOptionalISO6391CodeValue" );
		if( optionalISO6391Code == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( *optionalISO6391Code );
	}

	const std::string* CFSecISOLangByCode2IdxKey::getOptionalISO6391CodeReference() const {
		return( optionalISO6391Code );
	}

	const bool CFSecISOLangByCode2IdxKey::isOptionalISO6391CodeNull() const {
		return( optionalISO6391Code == NULL );
	}

	void CFSecISOLangByCode2IdxKey::setOptionalISO6391CodeNull() {
		if( optionalISO6391Code != NULL ) {
			delete optionalISO6391Code;
			optionalISO6391Code = NULL;
		}
	}

	void CFSecISOLangByCode2IdxKey::setOptionalISO6391CodeValue( const std::string& value ) {
		static const std::string S_ProcName( "setOptionalISO6391CodeValue" );
		if( value.length() > CFSecISOLangBuff::ISO6391CODE_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecISOLangBuff::ISO6391CODE_MAX_LEN );
		}
		if( optionalISO6391Code != NULL ) {
			delete optionalISO6391Code;
			optionalISO6391Code = NULL;
		}
		optionalISO6391Code = new std::string( value );
	}

	size_t CFSecISOLangByCode2IdxKey::hashCode() const {
		size_t hashCode = 0;
		if( ! isOptionalISO6391CodeNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalISO6391CodeValue() );
		}
		return( hashCode );
	}

	std::string CFSecISOLangByCode2IdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOLangByCode2IdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ISO6391Code( "ISO6391Code" );
		std::string ret( S_Preamble );
		if( ! isOptionalISO6391CodeNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_ISO6391Code, getOptionalISO6391CodeValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecISOLangByCode2IdxKey::operator <( const CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecISOLangByCode2IdxKey::operator <( const CFSecISOLangHBuff& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecISOLangByCode2IdxKey::operator <( const CFSecISOLangBuff& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecISOLangByCode2IdxKey::operator <=( const CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecISOLangByCode2IdxKey::operator <=( const CFSecISOLangHBuff& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecISOLangByCode2IdxKey::operator <=( const CFSecISOLangBuff& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFSecISOLangByCode2IdxKey::operator ==( const CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				if( getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecISOLangByCode2IdxKey::operator ==( const CFSecISOLangHBuff& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				if( getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecISOLangByCode2IdxKey::operator ==( const CFSecISOLangBuff& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				if( getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecISOLangByCode2IdxKey::operator !=( const CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecISOLangByCode2IdxKey::operator !=( const CFSecISOLangHBuff& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecISOLangByCode2IdxKey::operator !=( const CFSecISOLangBuff& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFSecISOLangByCode2IdxKey::operator >=( const CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecISOLangByCode2IdxKey::operator >=( const CFSecISOLangHBuff& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecISOLangByCode2IdxKey::operator >=( const CFSecISOLangBuff& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFSecISOLangByCode2IdxKey::operator >( const CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFSecISOLangByCode2IdxKey::operator >( const CFSecISOLangHBuff& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFSecISOLangByCode2IdxKey::operator >( const CFSecISOLangBuff& rhs ) {
		if( ! isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}
	CFSecISOLangByCode2IdxKey CFSecISOLangByCode2IdxKey::operator =( cfsec::CFSecISOLangByCode2IdxKey& src ) {
		if( src.isOptionalISO6391CodeNull() ) {
			setOptionalISO6391CodeNull();
		}
		else {
			setOptionalISO6391CodeValue( src.getOptionalISO6391CodeValue() );
		}
		return( *this );
	}

	CFSecISOLangByCode2IdxKey CFSecISOLangByCode2IdxKey::operator =( cfsec::CFSecISOLangBuff& src ) {
		if( src.isOptionalISO6391CodeNull() ) {
			setOptionalISO6391CodeNull();
		}
		else {
			setOptionalISO6391CodeValue( src.getOptionalISO6391CodeValue() );
		}
		return( *this );
	}

	CFSecISOLangByCode2IdxKey CFSecISOLangByCode2IdxKey::operator =( cfsec::CFSecISOLangHBuff& src ) {
		if( src.isOptionalISO6391CodeNull() ) {
			setOptionalISO6391CodeNull();
		}
		else {
			setOptionalISO6391CodeValue( src.getOptionalISO6391CodeValue() );
		}
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
			if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				if( lhs.getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				if( lhs.getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				if( lhs.getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( lhs.getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( lhs.getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( lhs.getOptionalISO6391CodeValue() != rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangByCode2IdxKey& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOLangByCode2IdxKey& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( ! lhs.isOptionalISO6391CodeNull() ) {
			if( rhs.isOptionalISO6391CodeNull() ) {
				return( true );
			}
			if( lhs.getOptionalISO6391CodeValue() < rhs.getOptionalISO6391CodeValue() ) {
				return( false );
			}
			else if( lhs.getOptionalISO6391CodeValue() > rhs.getOptionalISO6391CodeValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalISO6391CodeNull() ) {
				return( false );
			}
		}
		return( false );
	}
}

