// Description: C++18 implementation for a SecApp by UJEEMountIdx index key object.

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

#include <cfsec/CFSecSecAppByUJEEMountIdxKey.hpp>
#include <cfsec/CFSecSecAppBuff.hpp>
#include <cfsec/CFSecSecAppHBuff.hpp>

namespace cfsec {
	const std::string CFSecSecAppByUJEEMountIdxKey::CLASS_NAME( "CFSecSecAppByUJEEMountIdxKey" );
	const std::string CFSecSecAppByUJEEMountIdxKey::S_VALUE( "value" );
	const std::string CFSecSecAppByUJEEMountIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecSecAppByUJEEMountIdxKey::CFSecSecAppByUJEEMountIdxKey() {
		requiredClusterId = cfsec::CFSecSecAppBuff::CLUSTERID_INIT_VALUE;
		requiredJEEMountName = new std::string( cfsec::CFSecSecAppBuff::JEEMOUNTNAME_INIT_VALUE );
	}

	CFSecSecAppByUJEEMountIdxKey::CFSecSecAppByUJEEMountIdxKey( const CFSecSecAppByUJEEMountIdxKey& src ) {
		requiredClusterId = cfsec::CFSecSecAppBuff::CLUSTERID_INIT_VALUE;
		requiredJEEMountName = new std::string( cfsec::CFSecSecAppBuff::JEEMOUNTNAME_INIT_VALUE );
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredJEEMountName( src.getRequiredJEEMountName() );
	}

	CFSecSecAppByUJEEMountIdxKey::~CFSecSecAppByUJEEMountIdxKey() {
		if( requiredJEEMountName != NULL ) {
			delete requiredJEEMountName;
			requiredJEEMountName = NULL;
		}
	}

	const int64_t CFSecSecAppByUJEEMountIdxKey::getRequiredClusterId() const {
		return( requiredClusterId );
	}

	const int64_t* CFSecSecAppByUJEEMountIdxKey::getRequiredClusterIdReference() const {
		return( &requiredClusterId );
	}

	void CFSecSecAppByUJEEMountIdxKey::setRequiredClusterId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredClusterId" );
		if( value < cfsec::CFSecSecAppBuff::CLUSTERID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecSecAppBuff::CLUSTERID_MIN_VALUE );
		}
		requiredClusterId = value;
	}

	const std::string& CFSecSecAppByUJEEMountIdxKey::getRequiredJEEMountName() const {
		return( *requiredJEEMountName );
	}

	const std::string* CFSecSecAppByUJEEMountIdxKey::getRequiredJEEMountNameReference() const {
		return( requiredJEEMountName );
	}

	void CFSecSecAppByUJEEMountIdxKey::setRequiredJEEMountName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredJEEMountName" );
		if( value.length() > CFSecSecAppBuff::JEEMOUNTNAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecSecAppBuff::JEEMOUNTNAME_MAX_LEN );
		}
		if( requiredJEEMountName != NULL ) {
			delete requiredJEEMountName;
			requiredJEEMountName = NULL;
		}
		requiredJEEMountName = new std::string( value );
	}

	size_t CFSecSecAppByUJEEMountIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredClusterId() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredJEEMountName() );
		return( hashCode );
	}

	std::string CFSecSecAppByUJEEMountIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecAppByUJEEMountIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_JEEMountName( "JEEMountName" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_JEEMountName, getRequiredJEEMountName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecSecAppByUJEEMountIdxKey::operator <( const CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppByUJEEMountIdxKey::operator <( const CFSecSecAppHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppByUJEEMountIdxKey::operator <( const CFSecSecAppBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppByUJEEMountIdxKey::operator <=( const CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppByUJEEMountIdxKey::operator <=( const CFSecSecAppHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppByUJEEMountIdxKey::operator <=( const CFSecSecAppBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppByUJEEMountIdxKey::operator ==( const CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecAppByUJEEMountIdxKey::operator ==( const CFSecSecAppHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecAppByUJEEMountIdxKey::operator ==( const CFSecSecAppBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecAppByUJEEMountIdxKey::operator !=( const CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppByUJEEMountIdxKey::operator !=( const CFSecSecAppHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppByUJEEMountIdxKey::operator !=( const CFSecSecAppBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppByUJEEMountIdxKey::operator >=( const CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppByUJEEMountIdxKey::operator >=( const CFSecSecAppHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppByUJEEMountIdxKey::operator >=( const CFSecSecAppBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppByUJEEMountIdxKey::operator >( const CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppByUJEEMountIdxKey::operator >( const CFSecSecAppHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppByUJEEMountIdxKey::operator >( const CFSecSecAppBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}
	CFSecSecAppByUJEEMountIdxKey CFSecSecAppByUJEEMountIdxKey::operator =( cfsec::CFSecSecAppByUJEEMountIdxKey& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredJEEMountName( src.getRequiredJEEMountName() );
		return( *this );
	}

	CFSecSecAppByUJEEMountIdxKey CFSecSecAppByUJEEMountIdxKey::operator =( cfsec::CFSecSecAppBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredJEEMountName( src.getRequiredJEEMountName() );
		return( *this );
	}

	CFSecSecAppByUJEEMountIdxKey CFSecSecAppByUJEEMountIdxKey::operator =( cfsec::CFSecSecAppHBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredJEEMountName( src.getRequiredJEEMountName() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() != rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppByUJEEMountIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecAppByUJEEMountIdxKey& lhs, const cfsec::CFSecSecAppBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEMountName() < rhs.getRequiredJEEMountName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEMountName() > rhs.getRequiredJEEMountName() ) {
			return( true );
		}
		return( false );
	}
}

