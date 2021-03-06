// Description: C++18 implementation of a ISOLang primary key object.

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

#include <cfsec/CFSecISOLangPKey.hpp>
#include <cfsec/CFSecISOLangBuff.hpp>
#include <cfsec/CFSecISOLangHPKey.hpp>
#include <cfsec/CFSecISOLangHBuff.hpp>

namespace cfsec {

	const std::string CFSecISOLangPKey::CLASS_NAME( "CFSecISOLangPKey" );
	const std::string CFSecISOLangPKey::S_VALUE( "value" );
	const std::string CFSecISOLangPKey::S_VALUE_LENGTH( "value.length()" );

	CFSecISOLangPKey::CFSecISOLangPKey() {
		requiredISOLangId = cfsec::CFSecISOLangBuff::ISOLANGID_INIT_VALUE;
	}

	CFSecISOLangPKey::CFSecISOLangPKey( const CFSecISOLangPKey& src ) {
		requiredISOLangId = cfsec::CFSecISOLangBuff::ISOLANGID_INIT_VALUE;
		setRequiredISOLangId( src.getRequiredISOLangId() );
	}

	CFSecISOLangPKey::~CFSecISOLangPKey() {
	}

	const int16_t CFSecISOLangPKey::getRequiredISOLangId() const {
		return( requiredISOLangId );
	}

	const int16_t* CFSecISOLangPKey::getRequiredISOLangIdReference() const {
		return( &requiredISOLangId );
	}

	void CFSecISOLangPKey::setRequiredISOLangId( const int16_t value ) {
		static const std::string S_ProcName( "setRequiredISOLangId" );
		if( value < cfsec::CFSecISOLangBuff::ISOLANGID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOLangBuff::ISOLANGID_MIN_VALUE );
		}
		requiredISOLangId = value;
	}

	bool CFSecISOLangPKey::operator <( const CFSecISOLangHPKey& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangPKey::operator <( const CFSecISOLangPKey& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangPKey::operator <( const CFSecISOLangHBuff& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangPKey::operator <( const CFSecISOLangBuff& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangPKey::operator <=( const CFSecISOLangHPKey& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangPKey::operator <=( const CFSecISOLangPKey& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangPKey::operator <=( const CFSecISOLangHBuff& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangPKey::operator <=( const CFSecISOLangBuff& rhs ) {
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangPKey::operator ==( const CFSecISOLangHPKey& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOLangPKey::operator ==( const CFSecISOLangPKey& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOLangPKey::operator ==( const CFSecISOLangHBuff& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOLangPKey::operator ==( const CFSecISOLangBuff& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOLangPKey::operator !=( const CFSecISOLangHPKey& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangPKey::operator !=( const CFSecISOLangPKey& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangPKey::operator !=( const CFSecISOLangHBuff& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangPKey::operator !=( const CFSecISOLangBuff& rhs ) {
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangPKey::operator >=( const CFSecISOLangHPKey& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangPKey::operator >=( const CFSecISOLangPKey& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangPKey::operator >=( const CFSecISOLangHBuff& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangPKey::operator >=( const CFSecISOLangBuff& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOLangPKey::operator >( const CFSecISOLangHPKey& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangPKey::operator >( const CFSecISOLangPKey& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangPKey::operator >( const CFSecISOLangHBuff& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOLangPKey::operator >( const CFSecISOLangBuff& rhs ) {
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	CFSecISOLangPKey CFSecISOLangPKey::operator =( cfsec::CFSecISOLangPKey& src ) {
		setRequiredISOLangId( src.getRequiredISOLangId() );
		return( *this );
	}

	CFSecISOLangPKey CFSecISOLangPKey::operator =( cfsec::CFSecISOLangHPKey& src ) {
		setRequiredISOLangId( src.getRequiredISOLangId() );
		return( *this );
	}

	CFSecISOLangPKey CFSecISOLangPKey::operator =( cfsec::CFSecISOLangBuff& src ) {
		setRequiredISOLangId( src.getRequiredISOLangId() );
		return( *this );
	}

	CFSecISOLangPKey CFSecISOLangPKey::operator =( cfsec::CFSecISOLangHBuff& src ) {
		setRequiredISOLangId( src.getRequiredISOLangId() );
		return( *this );
	}

	size_t CFSecISOLangPKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOLangId();
		return( hashCode );
	}

	std::string CFSecISOLangPKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOLangPKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ISOLangId( "ISOLangId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOLangId, getRequiredISOLangId() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHPKey& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangPKey& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHPKey& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangPKey& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHPKey& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangPKey& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHPKey& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangPKey& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHPKey& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangPKey& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHPKey& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangPKey& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangHBuff& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOLangPKey& lhs, const cfsec::CFSecISOLangBuff& rhs ) {
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}
}

