// Description: C++18 implementation for a ISOCtry by ISOCodeIdx index key object.

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

#include <cfsec/CFSecISOCtryByISOCodeIdxKey.hpp>
#include <cfsec/CFSecISOCtryBuff.hpp>
#include <cfsec/CFSecISOCtryHBuff.hpp>

namespace cfsec {
	const std::string CFSecISOCtryByISOCodeIdxKey::CLASS_NAME( "CFSecISOCtryByISOCodeIdxKey" );
	const std::string CFSecISOCtryByISOCodeIdxKey::S_VALUE( "value" );
	const std::string CFSecISOCtryByISOCodeIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecISOCtryByISOCodeIdxKey::CFSecISOCtryByISOCodeIdxKey() {
		requiredISOCode = new std::string( cfsec::CFSecISOCtryBuff::ISOCODE_INIT_VALUE );
	}

	CFSecISOCtryByISOCodeIdxKey::CFSecISOCtryByISOCodeIdxKey( const CFSecISOCtryByISOCodeIdxKey& src ) {
		requiredISOCode = new std::string( cfsec::CFSecISOCtryBuff::ISOCODE_INIT_VALUE );
		setRequiredISOCode( src.getRequiredISOCode() );
	}

	CFSecISOCtryByISOCodeIdxKey::~CFSecISOCtryByISOCodeIdxKey() {
		if( requiredISOCode != NULL ) {
			delete requiredISOCode;
			requiredISOCode = NULL;
		}
	}

	const std::string& CFSecISOCtryByISOCodeIdxKey::getRequiredISOCode() const {
		return( *requiredISOCode );
	}

	const std::string* CFSecISOCtryByISOCodeIdxKey::getRequiredISOCodeReference() const {
		return( requiredISOCode );
	}

	void CFSecISOCtryByISOCodeIdxKey::setRequiredISOCode( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredISOCode" );
		if( value.length() > CFSecISOCtryBuff::ISOCODE_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecISOCtryBuff::ISOCODE_MAX_LEN );
		}
		if( requiredISOCode != NULL ) {
			delete requiredISOCode;
			requiredISOCode = NULL;
		}
		requiredISOCode = new std::string( value );
	}

	size_t CFSecISOCtryByISOCodeIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + cflib::CFLib::hash( getRequiredISOCode() );
		return( hashCode );
	}

	std::string CFSecISOCtryByISOCodeIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOCtryByISOCodeIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ISOCode( "ISOCode" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_ISOCode, getRequiredISOCode() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecISOCtryByISOCodeIdxKey::operator <( const CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryByISOCodeIdxKey::operator <( const CFSecISOCtryHBuff& rhs ) {
		if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryByISOCodeIdxKey::operator <( const CFSecISOCtryBuff& rhs ) {
		if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryByISOCodeIdxKey::operator <=( const CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryByISOCodeIdxKey::operator <=( const CFSecISOCtryHBuff& rhs ) {
		if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryByISOCodeIdxKey::operator <=( const CFSecISOCtryBuff& rhs ) {
		if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryByISOCodeIdxKey::operator ==( const CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryByISOCodeIdxKey::operator ==( const CFSecISOCtryHBuff& rhs ) {
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryByISOCodeIdxKey::operator ==( const CFSecISOCtryBuff& rhs ) {
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryByISOCodeIdxKey::operator !=( const CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryByISOCodeIdxKey::operator !=( const CFSecISOCtryHBuff& rhs ) {
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryByISOCodeIdxKey::operator !=( const CFSecISOCtryBuff& rhs ) {
		if( getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryByISOCodeIdxKey::operator >=( const CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryByISOCodeIdxKey::operator >=( const CFSecISOCtryHBuff& rhs ) {
		if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryByISOCodeIdxKey::operator >=( const CFSecISOCtryBuff& rhs ) {
		if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryByISOCodeIdxKey::operator >( const CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryByISOCodeIdxKey::operator >( const CFSecISOCtryHBuff& rhs ) {
		if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryByISOCodeIdxKey::operator >( const CFSecISOCtryBuff& rhs ) {
		if( getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}
	CFSecISOCtryByISOCodeIdxKey CFSecISOCtryByISOCodeIdxKey::operator =( cfsec::CFSecISOCtryByISOCodeIdxKey& src ) {
		setRequiredISOCode( src.getRequiredISOCode() );
		return( *this );
	}

	CFSecISOCtryByISOCodeIdxKey CFSecISOCtryByISOCodeIdxKey::operator =( cfsec::CFSecISOCtryBuff& src ) {
		setRequiredISOCode( src.getRequiredISOCode() );
		return( *this );
	}

	CFSecISOCtryByISOCodeIdxKey CFSecISOCtryByISOCodeIdxKey::operator =( cfsec::CFSecISOCtryHBuff& src ) {
		setRequiredISOCode( src.getRequiredISOCode() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecISOCtryByISOCodeIdxKey& lhs, const cfsec::CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryByISOCodeIdxKey& lhs, const cfsec::CFSecISOCtryHBuff& rhs ) {
		if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryByISOCodeIdxKey& lhs, const cfsec::CFSecISOCtryBuff& rhs ) {
		if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecISOCtryByISOCodeIdxKey& lhs, const cfsec::CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryByISOCodeIdxKey& lhs, const cfsec::CFSecISOCtryHBuff& rhs ) {
		if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryByISOCodeIdxKey& lhs, const cfsec::CFSecISOCtryBuff& rhs ) {
		if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryByISOCodeIdxKey& lhs, const cfsec::CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryByISOCodeIdxKey& lhs, const cfsec::CFSecISOCtryHBuff& rhs ) {
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryByISOCodeIdxKey& lhs, const cfsec::CFSecISOCtryBuff& rhs ) {
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOCtryByISOCodeIdxKey& lhs, const cfsec::CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryByISOCodeIdxKey& lhs, const cfsec::CFSecISOCtryHBuff& rhs ) {
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryByISOCodeIdxKey& lhs, const cfsec::CFSecISOCtryBuff& rhs ) {
		if( lhs.getRequiredISOCode() != rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOCtryByISOCodeIdxKey& lhs, const cfsec::CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryByISOCodeIdxKey& lhs, const cfsec::CFSecISOCtryHBuff& rhs ) {
		if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryByISOCodeIdxKey& lhs, const cfsec::CFSecISOCtryBuff& rhs ) {
		if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecISOCtryByISOCodeIdxKey& lhs, const cfsec::CFSecISOCtryByISOCodeIdxKey& rhs ) {
		if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryByISOCodeIdxKey& lhs, const cfsec::CFSecISOCtryHBuff& rhs ) {
		if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryByISOCodeIdxKey& lhs, const cfsec::CFSecISOCtryBuff& rhs ) {
		if( lhs.getRequiredISOCode() < rhs.getRequiredISOCode() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCode() > rhs.getRequiredISOCode() ) {
			return( true );
		}
		return( false );
	}
}

