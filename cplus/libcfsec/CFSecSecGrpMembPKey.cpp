// Description: C++18 implementation of a SecGrpMemb primary key object.

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

#include <cfsec/CFSecSecGrpMembPKey.hpp>
#include <cfsec/CFSecSecGrpMembBuff.hpp>
#include <cfsec/CFSecSecGrpMembHPKey.hpp>
#include <cfsec/CFSecSecGrpMembHBuff.hpp>

namespace cfsec {

	const std::string CFSecSecGrpMembPKey::CLASS_NAME( "CFSecSecGrpMembPKey" );
	const std::string CFSecSecGrpMembPKey::S_VALUE( "value" );
	const std::string CFSecSecGrpMembPKey::S_VALUE_LENGTH( "value.length()" );

	CFSecSecGrpMembPKey::CFSecSecGrpMembPKey() {
		requiredClusterId = cfsec::CFSecSecGrpMembBuff::CLUSTERID_INIT_VALUE;
		requiredSecGrpMembId = cfsec::CFSecSecGrpMembBuff::SECGRPMEMBID_INIT_VALUE;
	}

	CFSecSecGrpMembPKey::CFSecSecGrpMembPKey( const CFSecSecGrpMembPKey& src ) {
		requiredClusterId = cfsec::CFSecSecGrpMembBuff::CLUSTERID_INIT_VALUE;
		requiredSecGrpMembId = cfsec::CFSecSecGrpMembBuff::SECGRPMEMBID_INIT_VALUE;
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecGrpMembId( src.getRequiredSecGrpMembId() );
	}

	CFSecSecGrpMembPKey::~CFSecSecGrpMembPKey() {
	}

	const int64_t CFSecSecGrpMembPKey::getRequiredClusterId() const {
		return( requiredClusterId );
	}

	const int64_t* CFSecSecGrpMembPKey::getRequiredClusterIdReference() const {
		return( &requiredClusterId );
	}

	void CFSecSecGrpMembPKey::setRequiredClusterId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredClusterId" );
		if( value < cfsec::CFSecSecGrpMembBuff::CLUSTERID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecSecGrpMembBuff::CLUSTERID_MIN_VALUE );
		}
		requiredClusterId = value;
	}

	const int64_t CFSecSecGrpMembPKey::getRequiredSecGrpMembId() const {
		return( requiredSecGrpMembId );
	}

	const int64_t* CFSecSecGrpMembPKey::getRequiredSecGrpMembIdReference() const {
		return( &requiredSecGrpMembId );
	}

	void CFSecSecGrpMembPKey::setRequiredSecGrpMembId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredSecGrpMembId" );
		if( value < cfsec::CFSecSecGrpMembBuff::SECGRPMEMBID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecSecGrpMembBuff::SECGRPMEMBID_MIN_VALUE );
		}
		requiredSecGrpMembId = value;
	}

	bool CFSecSecGrpMembPKey::operator <( const CFSecSecGrpMembHPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpMembPKey::operator <( const CFSecSecGrpMembPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpMembPKey::operator <( const CFSecSecGrpMembHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpMembPKey::operator <( const CFSecSecGrpMembBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpMembPKey::operator <=( const CFSecSecGrpMembHPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpMembPKey::operator <=( const CFSecSecGrpMembPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpMembPKey::operator <=( const CFSecSecGrpMembHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpMembPKey::operator <=( const CFSecSecGrpMembBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpMembPKey::operator ==( const CFSecSecGrpMembHPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecGrpMembId() != rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGrpMembPKey::operator ==( const CFSecSecGrpMembPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecGrpMembId() != rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGrpMembPKey::operator ==( const CFSecSecGrpMembHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecGrpMembId() != rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGrpMembPKey::operator ==( const CFSecSecGrpMembBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecGrpMembId() != rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGrpMembPKey::operator !=( const CFSecSecGrpMembHPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpMembId() != rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpMembPKey::operator !=( const CFSecSecGrpMembPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpMembId() != rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpMembPKey::operator !=( const CFSecSecGrpMembHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpMembId() != rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpMembPKey::operator !=( const CFSecSecGrpMembBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpMembId() != rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpMembPKey::operator >=( const CFSecSecGrpMembHPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpMembPKey::operator >=( const CFSecSecGrpMembPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpMembPKey::operator >=( const CFSecSecGrpMembHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpMembPKey::operator >=( const CFSecSecGrpMembBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpMembPKey::operator >( const CFSecSecGrpMembHPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpMembPKey::operator >( const CFSecSecGrpMembPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpMembPKey::operator >( const CFSecSecGrpMembHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpMembPKey::operator >( const CFSecSecGrpMembBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	CFSecSecGrpMembPKey CFSecSecGrpMembPKey::operator =( cfsec::CFSecSecGrpMembPKey& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecGrpMembId( src.getRequiredSecGrpMembId() );
		return( *this );
	}

	CFSecSecGrpMembPKey CFSecSecGrpMembPKey::operator =( cfsec::CFSecSecGrpMembHPKey& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecGrpMembId( src.getRequiredSecGrpMembId() );
		return( *this );
	}

	CFSecSecGrpMembPKey CFSecSecGrpMembPKey::operator =( cfsec::CFSecSecGrpMembBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecGrpMembId( src.getRequiredSecGrpMembId() );
		return( *this );
	}

	CFSecSecGrpMembPKey CFSecSecGrpMembPKey::operator =( cfsec::CFSecSecGrpMembHBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecGrpMembId( src.getRequiredSecGrpMembId() );
		return( *this );
	}

	size_t CFSecSecGrpMembPKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredClusterId() );
		hashCode = hashCode + (int)( getRequiredSecGrpMembId() );
		return( hashCode );
	}

	std::string CFSecSecGrpMembPKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecGrpMembPKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecGrpMembId( "SecGrpMembId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_SecGrpMembId, getRequiredSecGrpMembId() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecGrpMembId() != rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecGrpMembId() != rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecGrpMembId() != rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecGrpMembId() != rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpMembId() != rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpMembId() != rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpMembId() != rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpMembId() != rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecGrpMembPKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGrpMembId() < rhs.getRequiredSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGrpMembId() > rhs.getRequiredSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}
}

