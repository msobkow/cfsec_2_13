// Description: C++18 implementation of a SecApp primary key object.

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

#include <cfsec/CFSecSecAppPKey.hpp>
#include <cfsec/CFSecSecAppBuff.hpp>
#include <cfsec/CFSecSecAppHPKey.hpp>
#include <cfsec/CFSecSecAppHBuff.hpp>

namespace cfsec {

	const std::string CFSecSecAppPKey::CLASS_NAME( "CFSecSecAppPKey" );
	const std::string CFSecSecAppPKey::S_VALUE( "value" );
	const std::string CFSecSecAppPKey::S_VALUE_LENGTH( "value.length()" );

	CFSecSecAppPKey::CFSecSecAppPKey() {
		requiredClusterId = cfsec::CFSecSecAppBuff::CLUSTERID_INIT_VALUE;
		requiredSecAppId = cfsec::CFSecSecAppBuff::SECAPPID_INIT_VALUE;
	}

	CFSecSecAppPKey::CFSecSecAppPKey( const CFSecSecAppPKey& src ) {
		requiredClusterId = cfsec::CFSecSecAppBuff::CLUSTERID_INIT_VALUE;
		requiredSecAppId = cfsec::CFSecSecAppBuff::SECAPPID_INIT_VALUE;
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecAppId( src.getRequiredSecAppId() );
	}

	CFSecSecAppPKey::~CFSecSecAppPKey() {
	}

	const int64_t CFSecSecAppPKey::getRequiredClusterId() const {
		return( requiredClusterId );
	}

	const int64_t* CFSecSecAppPKey::getRequiredClusterIdReference() const {
		return( &requiredClusterId );
	}

	void CFSecSecAppPKey::setRequiredClusterId( const int64_t value ) {
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

	const int32_t CFSecSecAppPKey::getRequiredSecAppId() const {
		return( requiredSecAppId );
	}

	const int32_t* CFSecSecAppPKey::getRequiredSecAppIdReference() const {
		return( &requiredSecAppId );
	}

	void CFSecSecAppPKey::setRequiredSecAppId( const int32_t value ) {
		static const std::string S_ProcName( "setRequiredSecAppId" );
		if( value < cfsec::CFSecSecAppBuff::SECAPPID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecSecAppBuff::SECAPPID_MIN_VALUE );
		}
		requiredSecAppId = value;
	}

	bool CFSecSecAppPKey::operator <( const CFSecSecAppHPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppPKey::operator <( const CFSecSecAppPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppPKey::operator <( const CFSecSecAppHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppPKey::operator <( const CFSecSecAppBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppPKey::operator <=( const CFSecSecAppHPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppPKey::operator <=( const CFSecSecAppPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppPKey::operator <=( const CFSecSecAppHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppPKey::operator <=( const CFSecSecAppBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppPKey::operator ==( const CFSecSecAppHPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecAppPKey::operator ==( const CFSecSecAppPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecAppPKey::operator ==( const CFSecSecAppHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecAppPKey::operator ==( const CFSecSecAppBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecAppPKey::operator !=( const CFSecSecAppHPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppPKey::operator !=( const CFSecSecAppPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppPKey::operator !=( const CFSecSecAppHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppPKey::operator !=( const CFSecSecAppBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppPKey::operator >=( const CFSecSecAppHPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppPKey::operator >=( const CFSecSecAppPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppPKey::operator >=( const CFSecSecAppHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppPKey::operator >=( const CFSecSecAppBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecAppPKey::operator >( const CFSecSecAppHPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppPKey::operator >( const CFSecSecAppPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppPKey::operator >( const CFSecSecAppHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecAppPKey::operator >( const CFSecSecAppBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	CFSecSecAppPKey CFSecSecAppPKey::operator =( cfsec::CFSecSecAppPKey& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecAppId( src.getRequiredSecAppId() );
		return( *this );
	}

	CFSecSecAppPKey CFSecSecAppPKey::operator =( cfsec::CFSecSecAppHPKey& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecAppId( src.getRequiredSecAppId() );
		return( *this );
	}

	CFSecSecAppPKey CFSecSecAppPKey::operator =( cfsec::CFSecSecAppBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecAppId( src.getRequiredSecAppId() );
		return( *this );
	}

	CFSecSecAppPKey CFSecSecAppPKey::operator =( cfsec::CFSecSecAppHBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecAppId( src.getRequiredSecAppId() );
		return( *this );
	}

	size_t CFSecSecAppPKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredClusterId() );
		hashCode = hashCode + getRequiredSecAppId();
		return( hashCode );
	}

	std::string CFSecSecAppPKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecAppPKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecAppId( "SecAppId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecAppId, getRequiredSecAppId() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppHPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppHPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppHPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppHPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppHPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppHPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecAppPKey& lhs, const cfsec::CFSecSecAppBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() < rhs.getRequiredSecAppId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecAppId() > rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}
}

