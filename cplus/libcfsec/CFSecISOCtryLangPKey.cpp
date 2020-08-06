// Description: C++18 implementation of a ISOCtryLang primary key object.

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

#include <cfsec/CFSecISOCtryLangPKey.hpp>
#include <cfsec/CFSecISOCtryLangBuff.hpp>
#include <cfsec/CFSecISOCtryLangHPKey.hpp>
#include <cfsec/CFSecISOCtryLangHBuff.hpp>

namespace cfsec {

	const std::string CFSecISOCtryLangPKey::CLASS_NAME( "CFSecISOCtryLangPKey" );
	const std::string CFSecISOCtryLangPKey::S_VALUE( "value" );
	const std::string CFSecISOCtryLangPKey::S_VALUE_LENGTH( "value.length()" );

	CFSecISOCtryLangPKey::CFSecISOCtryLangPKey() {
		requiredISOCtryId = cfsec::CFSecISOCtryLangBuff::ISOCTRYID_INIT_VALUE;
		requiredISOLangId = cfsec::CFSecISOCtryLangBuff::ISOLANGID_INIT_VALUE;
	}

	CFSecISOCtryLangPKey::CFSecISOCtryLangPKey( const CFSecISOCtryLangPKey& src ) {
		requiredISOCtryId = cfsec::CFSecISOCtryLangBuff::ISOCTRYID_INIT_VALUE;
		requiredISOLangId = cfsec::CFSecISOCtryLangBuff::ISOLANGID_INIT_VALUE;
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setRequiredISOLangId( src.getRequiredISOLangId() );
	}

	CFSecISOCtryLangPKey::~CFSecISOCtryLangPKey() {
	}

	const int16_t CFSecISOCtryLangPKey::getRequiredISOCtryId() const {
		return( requiredISOCtryId );
	}

	const int16_t* CFSecISOCtryLangPKey::getRequiredISOCtryIdReference() const {
		return( &requiredISOCtryId );
	}

	void CFSecISOCtryLangPKey::setRequiredISOCtryId( const int16_t value ) {
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

	const int16_t CFSecISOCtryLangPKey::getRequiredISOLangId() const {
		return( requiredISOLangId );
	}

	const int16_t* CFSecISOCtryLangPKey::getRequiredISOLangIdReference() const {
		return( &requiredISOLangId );
	}

	void CFSecISOCtryLangPKey::setRequiredISOLangId( const int16_t value ) {
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

	bool CFSecISOCtryLangPKey::operator <( const CFSecISOCtryLangHPKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangPKey::operator <( const CFSecISOCtryLangPKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangPKey::operator <( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangPKey::operator <( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangPKey::operator <=( const CFSecISOCtryLangHPKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangPKey::operator <=( const CFSecISOCtryLangPKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangPKey::operator <=( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangPKey::operator <=( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangPKey::operator ==( const CFSecISOCtryLangHPKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryLangPKey::operator ==( const CFSecISOCtryLangPKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryLangPKey::operator ==( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryLangPKey::operator ==( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryLangPKey::operator !=( const CFSecISOCtryLangHPKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangPKey::operator !=( const CFSecISOCtryLangPKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangPKey::operator !=( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangPKey::operator !=( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangPKey::operator >=( const CFSecISOCtryLangHPKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangPKey::operator >=( const CFSecISOCtryLangPKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangPKey::operator >=( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangPKey::operator >=( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryLangPKey::operator >( const CFSecISOCtryLangHPKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangPKey::operator >( const CFSecISOCtryLangPKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangPKey::operator >( const CFSecISOCtryLangHBuff& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryLangPKey::operator >( const CFSecISOCtryLangBuff& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	CFSecISOCtryLangPKey CFSecISOCtryLangPKey::operator =( cfsec::CFSecISOCtryLangPKey& src ) {
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setRequiredISOLangId( src.getRequiredISOLangId() );
		return( *this );
	}

	CFSecISOCtryLangPKey CFSecISOCtryLangPKey::operator =( cfsec::CFSecISOCtryLangHPKey& src ) {
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setRequiredISOLangId( src.getRequiredISOLangId() );
		return( *this );
	}

	CFSecISOCtryLangPKey CFSecISOCtryLangPKey::operator =( cfsec::CFSecISOCtryLangBuff& src ) {
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setRequiredISOLangId( src.getRequiredISOLangId() );
		return( *this );
	}

	CFSecISOCtryLangPKey CFSecISOCtryLangPKey::operator =( cfsec::CFSecISOCtryLangHBuff& src ) {
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setRequiredISOLangId( src.getRequiredISOLangId() );
		return( *this );
	}

	size_t CFSecISOCtryLangPKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOCtryId();
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOLangId();
		return( hashCode );
	}

	std::string CFSecISOCtryLangPKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOCtryLangPKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ISOCtryId( "ISOCtryId" );
		static const std::string S_ISOLangId( "ISOLangId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCtryId, getRequiredISOCtryId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOLangId, getRequiredISOLangId() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() != rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryLangPKey& lhs, const cfsec::CFSecISOCtryLangBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOLangId() < rhs.getRequiredISOLangId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOLangId() > rhs.getRequiredISOLangId() ) {
			return( true );
		}
		return( false );
	}
}

