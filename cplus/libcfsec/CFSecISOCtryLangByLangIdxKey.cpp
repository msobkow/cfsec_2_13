// Description: C++18 implementation for a ISOCtryLang by LangIdx index key object.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <cflib/ICFLibPublic.hpp>

using namespace std;

#include <cfsec/CFSecISOCtryLangByLangIdxKey.hpp>
#include <cfsec/CFSecISOCtryLangBuff.hpp>
#include <cfsec/CFSecISOCtryLangHBuff.hpp>

namespace cfsec {
	const std::string CFSecISOCtryLangByLangIdxKey::CLASS_NAME( "CFSecISOCtryLangByLangIdxKey" );
	const std::string CFSecISOCtryLangByLangIdxKey::S_VALUE( "value" );
	const std::string CFSecISOCtryLangByLangIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecISOCtryLangByLangIdxKey::CFSecISOCtryLangByLangIdxKey() {
		requiredISOLangId = cfsec::CFSecISOCtryLangBuff::ISOLANGID_INIT_VALUE;
	}

	CFSecISOCtryLangByLangIdxKey::CFSecISOCtryLangByLangIdxKey( const CFSecISOCtryLangByLangIdxKey& src ) {
		requiredISOLangId = cfsec::CFSecISOCtryLangBuff::ISOLANGID_INIT_VALUE;
		setRequiredISOLangId( src.getRequiredISOLangId() );
	}

	CFSecISOCtryLangByLangIdxKey::~CFSecISOCtryLangByLangIdxKey() {
	}

	const int16_t CFSecISOCtryLangByLangIdxKey::getRequiredISOLangId() const {
		return( requiredISOLangId );
	}

	const int16_t* CFSecISOCtryLangByLangIdxKey::getRequiredISOLangIdReference() const {
		return( &requiredISOLangId );
	}

	void CFSecISOCtryLangByLangIdxKey::setRequiredISOLangId( const int16_t value ) {
		static const std::string S_ProcName( "setRequiredISOLangId" );
		if( value < cfsec::CFSecISOCtryLangBuff::ISOLANGID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOCtryLangBuff::ISOLANGID_MIN_VALUE );
		}
		requiredISOLangId = value;
	}

	size_t CFSecISOCtryLangByLangIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOLangId();
		return( hashCode );
	}

	std::string CFSecISOCtryLangByLangIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOCtryLangByLangIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ISOLangId( "ISOLangId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOLangId, getRequiredISOLangId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecISOCtryLangByLangIdxKey::operator <( const CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangByLangIdxKey::operator <( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangByLangIdxKey::operator <( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangByLangIdxKey::operator <=( const CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangByLangIdxKey::operator <=( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangByLangIdxKey::operator <=( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangByLangIdxKey::operator ==( const CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryLangByLangIdxKey::operator ==( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryLangByLangIdxKey::operator ==( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryLangByLangIdxKey::operator !=( const CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangByLangIdxKey::operator !=( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangByLangIdxKey::operator !=( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangByLangIdxKey::operator >=( const CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangByLangIdxKey::operator >=( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangByLangIdxKey::operator >=( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangByLangIdxKey::operator >( const CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangByLangIdxKey::operator >( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangByLangIdxKey::operator >( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}
	CFSecISOCtryLangByLangIdxKey CFSecISOCtryLangByLangIdxKey::operator =( cfsec::CFSecISOCtryLangByLangIdxKey& src ) {
		setRequiredISOLangId( src.getRequiredISOLangId() );
		return( *this );
	}

	CFSecISOCtryLangByLangIdxKey CFSecISOCtryLangByLangIdxKey::operator =( cfsec::CFSecISOCtryLangBuff& src ) {
		setRequiredISOLangId( src.getRequiredISOLangId() );
		return( *this );
	}

	CFSecISOCtryLangByLangIdxKey CFSecISOCtryLangByLangIdxKey::operator =( cfsec::CFSecISOCtryLangHBuff& src ) {
		setRequiredISOLangId( src.getRequiredISOLangId() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecISOCtryLangByLangIdxKey& lhs, const cfsec::CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryLangByLangIdxKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryLangByLangIdxKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecISOCtryLangByLangIdxKey& lhs, const cfsec::CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryLangByLangIdxKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryLangByLangIdxKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryLangByLangIdxKey& lhs, const cfsec::CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryLangByLangIdxKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryLangByLangIdxKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOCtryLangByLangIdxKey& lhs, const cfsec::CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryLangByLangIdxKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryLangByLangIdxKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOCtryLangByLangIdxKey& lhs, const cfsec::CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryLangByLangIdxKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryLangByLangIdxKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecISOCtryLangByLangIdxKey& lhs, const cfsec::CFSecISOCtryLangByLangIdxKey& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryLangByLangIdxKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryLangByLangIdxKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}
}

