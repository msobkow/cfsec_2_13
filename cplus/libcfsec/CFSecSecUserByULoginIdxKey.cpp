// Description: C++18 implementation for a SecUser by ULoginIdx index key object.

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

#include <cfsec/CFSecSecUserByULoginIdxKey.hpp>
#include <cfsec/CFSecSecUserBuff.hpp>
#include <cfsec/CFSecSecUserHBuff.hpp>

namespace cfsec {
	const std::string CFSecSecUserByULoginIdxKey::CLASS_NAME( "CFSecSecUserByULoginIdxKey" );
	const std::string CFSecSecUserByULoginIdxKey::S_VALUE( "value" );
	const std::string CFSecSecUserByULoginIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecSecUserByULoginIdxKey::CFSecSecUserByULoginIdxKey() {
		requiredLoginId = new std::string( cfsec::CFSecSecUserBuff::LOGINID_INIT_VALUE );
	}

	CFSecSecUserByULoginIdxKey::CFSecSecUserByULoginIdxKey( const CFSecSecUserByULoginIdxKey& src ) {
		requiredLoginId = new std::string( cfsec::CFSecSecUserBuff::LOGINID_INIT_VALUE );
		setRequiredLoginId( src.getRequiredLoginId() );
	}

	CFSecSecUserByULoginIdxKey::~CFSecSecUserByULoginIdxKey() {
		if( requiredLoginId != NULL ) {
			delete requiredLoginId;
			requiredLoginId = NULL;
		}
	}

	const std::string& CFSecSecUserByULoginIdxKey::getRequiredLoginId() const {
		return( *requiredLoginId );
	}

	const std::string* CFSecSecUserByULoginIdxKey::getRequiredLoginIdReference() const {
		return( requiredLoginId );
	}

	void CFSecSecUserByULoginIdxKey::setRequiredLoginId( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredLoginId" );
		if( value.length() > CFSecSecUserBuff::LOGINID_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecSecUserBuff::LOGINID_MAX_LEN );
		}
		if( requiredLoginId != NULL ) {
			delete requiredLoginId;
			requiredLoginId = NULL;
		}
		requiredLoginId = new std::string( value );
	}

	size_t CFSecSecUserByULoginIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + cflib::CFLib::hash( getRequiredLoginId() );
		return( hashCode );
	}

	std::string CFSecSecUserByULoginIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecUserByULoginIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_LoginId( "LoginId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_LoginId, getRequiredLoginId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecSecUserByULoginIdxKey::operator <( const CFSecSecUserByULoginIdxKey& rhs ) {
		if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserByULoginIdxKey::operator <( const CFSecSecUserHBuff& rhs ) {
		if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserByULoginIdxKey::operator <( const CFSecSecUserBuff& rhs ) {
		if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserByULoginIdxKey::operator <=( const CFSecSecUserByULoginIdxKey& rhs ) {
		if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecUserByULoginIdxKey::operator <=( const CFSecSecUserHBuff& rhs ) {
		if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecUserByULoginIdxKey::operator <=( const CFSecSecUserBuff& rhs ) {
		if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecUserByULoginIdxKey::operator ==( const CFSecSecUserByULoginIdxKey& rhs ) {
		if( getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecUserByULoginIdxKey::operator ==( const CFSecSecUserHBuff& rhs ) {
		if( getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecUserByULoginIdxKey::operator ==( const CFSecSecUserBuff& rhs ) {
		if( getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecUserByULoginIdxKey::operator !=( const CFSecSecUserByULoginIdxKey& rhs ) {
		if( getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserByULoginIdxKey::operator !=( const CFSecSecUserHBuff& rhs ) {
		if( getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserByULoginIdxKey::operator !=( const CFSecSecUserBuff& rhs ) {
		if( getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserByULoginIdxKey::operator >=( const CFSecSecUserByULoginIdxKey& rhs ) {
		if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecUserByULoginIdxKey::operator >=( const CFSecSecUserHBuff& rhs ) {
		if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecUserByULoginIdxKey::operator >=( const CFSecSecUserBuff& rhs ) {
		if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecUserByULoginIdxKey::operator >( const CFSecSecUserByULoginIdxKey& rhs ) {
		if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserByULoginIdxKey::operator >( const CFSecSecUserHBuff& rhs ) {
		if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecUserByULoginIdxKey::operator >( const CFSecSecUserBuff& rhs ) {
		if( getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}
	CFSecSecUserByULoginIdxKey CFSecSecUserByULoginIdxKey::operator =( cfsec::CFSecSecUserByULoginIdxKey& src ) {
		setRequiredLoginId( src.getRequiredLoginId() );
		return( *this );
	}

	CFSecSecUserByULoginIdxKey CFSecSecUserByULoginIdxKey::operator =( cfsec::CFSecSecUserBuff& src ) {
		setRequiredLoginId( src.getRequiredLoginId() );
		return( *this );
	}

	CFSecSecUserByULoginIdxKey CFSecSecUserByULoginIdxKey::operator =( cfsec::CFSecSecUserHBuff& src ) {
		setRequiredLoginId( src.getRequiredLoginId() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs ) {
		if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
		if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs ) {
		if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
		if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs ) {
		if( lhs.getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
		if( lhs.getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( lhs.getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs ) {
		if( lhs.getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
		if( lhs.getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( lhs.getRequiredLoginId() != rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs ) {
		if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
		if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserByULoginIdxKey& rhs ) {
		if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserHBuff& rhs ) {
		if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecUserByULoginIdxKey& lhs, const cfsec::CFSecSecUserBuff& rhs ) {
		if( lhs.getRequiredLoginId() < rhs.getRequiredLoginId() ) {
			return( false );
		}
		else if( lhs.getRequiredLoginId() > rhs.getRequiredLoginId() ) {
			return( true );
		}
		return( false );
	}
}

