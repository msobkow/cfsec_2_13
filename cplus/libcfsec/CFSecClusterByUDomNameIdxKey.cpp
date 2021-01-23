// Description: C++18 implementation for a Cluster by UDomNameIdx index key object.

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

#include <cfsec/CFSecClusterByUDomNameIdxKey.hpp>
#include <cfsec/CFSecClusterBuff.hpp>
#include <cfsec/CFSecClusterHBuff.hpp>

namespace cfsec {
	const std::string CFSecClusterByUDomNameIdxKey::CLASS_NAME( "CFSecClusterByUDomNameIdxKey" );
	const std::string CFSecClusterByUDomNameIdxKey::S_VALUE( "value" );
	const std::string CFSecClusterByUDomNameIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecClusterByUDomNameIdxKey::CFSecClusterByUDomNameIdxKey() {
		requiredFullDomName = new std::string( cfsec::CFSecClusterBuff::FULLDOMNAME_INIT_VALUE );
	}

	CFSecClusterByUDomNameIdxKey::CFSecClusterByUDomNameIdxKey( const CFSecClusterByUDomNameIdxKey& src ) {
		requiredFullDomName = new std::string( cfsec::CFSecClusterBuff::FULLDOMNAME_INIT_VALUE );
		setRequiredFullDomName( src.getRequiredFullDomName() );
	}

	CFSecClusterByUDomNameIdxKey::~CFSecClusterByUDomNameIdxKey() {
		if( requiredFullDomName != NULL ) {
			delete requiredFullDomName;
			requiredFullDomName = NULL;
		}
	}

	const std::string& CFSecClusterByUDomNameIdxKey::getRequiredFullDomName() const {
		return( *requiredFullDomName );
	}

	const std::string* CFSecClusterByUDomNameIdxKey::getRequiredFullDomNameReference() const {
		return( requiredFullDomName );
	}

	void CFSecClusterByUDomNameIdxKey::setRequiredFullDomName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredFullDomName" );
		if( value.length() > CFSecClusterBuff::FULLDOMNAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecClusterBuff::FULLDOMNAME_MAX_LEN );
		}
		if( requiredFullDomName != NULL ) {
			delete requiredFullDomName;
			requiredFullDomName = NULL;
		}
		requiredFullDomName = new std::string( value );
	}

	size_t CFSecClusterByUDomNameIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + cflib::CFLib::hash( getRequiredFullDomName() );
		return( hashCode );
	}

	std::string CFSecClusterByUDomNameIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecClusterByUDomNameIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_FullDomName( "FullDomName" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_FullDomName, getRequiredFullDomName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecClusterByUDomNameIdxKey::operator <( const CFSecClusterByUDomNameIdxKey& rhs ) {
		if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDomNameIdxKey::operator <( const CFSecClusterHBuff& rhs ) {
		if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDomNameIdxKey::operator <( const CFSecClusterBuff& rhs ) {
		if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDomNameIdxKey::operator <=( const CFSecClusterByUDomNameIdxKey& rhs ) {
		if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecClusterByUDomNameIdxKey::operator <=( const CFSecClusterHBuff& rhs ) {
		if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecClusterByUDomNameIdxKey::operator <=( const CFSecClusterBuff& rhs ) {
		if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecClusterByUDomNameIdxKey::operator ==( const CFSecClusterByUDomNameIdxKey& rhs ) {
		if( getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecClusterByUDomNameIdxKey::operator ==( const CFSecClusterHBuff& rhs ) {
		if( getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecClusterByUDomNameIdxKey::operator ==( const CFSecClusterBuff& rhs ) {
		if( getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecClusterByUDomNameIdxKey::operator !=( const CFSecClusterByUDomNameIdxKey& rhs ) {
		if( getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDomNameIdxKey::operator !=( const CFSecClusterHBuff& rhs ) {
		if( getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDomNameIdxKey::operator !=( const CFSecClusterBuff& rhs ) {
		if( getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDomNameIdxKey::operator >=( const CFSecClusterByUDomNameIdxKey& rhs ) {
		if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecClusterByUDomNameIdxKey::operator >=( const CFSecClusterHBuff& rhs ) {
		if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecClusterByUDomNameIdxKey::operator >=( const CFSecClusterBuff& rhs ) {
		if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecClusterByUDomNameIdxKey::operator >( const CFSecClusterByUDomNameIdxKey& rhs ) {
		if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDomNameIdxKey::operator >( const CFSecClusterHBuff& rhs ) {
		if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDomNameIdxKey::operator >( const CFSecClusterBuff& rhs ) {
		if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}
	CFSecClusterByUDomNameIdxKey CFSecClusterByUDomNameIdxKey::operator =( cfsec::CFSecClusterByUDomNameIdxKey& src ) {
		setRequiredFullDomName( src.getRequiredFullDomName() );
		return( *this );
	}

	CFSecClusterByUDomNameIdxKey CFSecClusterByUDomNameIdxKey::operator =( cfsec::CFSecClusterBuff& src ) {
		setRequiredFullDomName( src.getRequiredFullDomName() );
		return( *this );
	}

	CFSecClusterByUDomNameIdxKey CFSecClusterByUDomNameIdxKey::operator =( cfsec::CFSecClusterHBuff& src ) {
		setRequiredFullDomName( src.getRequiredFullDomName() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs ) {
		if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs ) {
		if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs ) {
		if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs ) {
		if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs ) {
		if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs ) {
		if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs ) {
		if( lhs.getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs ) {
		if( lhs.getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs ) {
		if( lhs.getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs ) {
		if( lhs.getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs ) {
		if( lhs.getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs ) {
		if( lhs.getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs ) {
		if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs ) {
		if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs ) {
		if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs ) {
		if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs ) {
		if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs ) {
		if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}
}

