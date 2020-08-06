// Description: C++18 implementation of a TSecGrpMemb primary key object.

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

#include <cfsec/CFSecTSecGrpMembPKey.hpp>
#include <cfsec/CFSecTSecGrpMembBuff.hpp>
#include <cfsec/CFSecTSecGrpMembHPKey.hpp>
#include <cfsec/CFSecTSecGrpMembHBuff.hpp>

namespace cfsec {

	const std::string CFSecTSecGrpMembPKey::CLASS_NAME( "CFSecTSecGrpMembPKey" );
	const std::string CFSecTSecGrpMembPKey::S_VALUE( "value" );
	const std::string CFSecTSecGrpMembPKey::S_VALUE_LENGTH( "value.length()" );

	CFSecTSecGrpMembPKey::CFSecTSecGrpMembPKey() {
		requiredTenantId = cfsec::CFSecTSecGrpMembBuff::TENANTID_INIT_VALUE;
		requiredTSecGrpMembId = cfsec::CFSecTSecGrpMembBuff::TSECGRPMEMBID_INIT_VALUE;
	}

	CFSecTSecGrpMembPKey::CFSecTSecGrpMembPKey( const CFSecTSecGrpMembPKey& src ) {
		requiredTenantId = cfsec::CFSecTSecGrpMembBuff::TENANTID_INIT_VALUE;
		requiredTSecGrpMembId = cfsec::CFSecTSecGrpMembBuff::TSECGRPMEMBID_INIT_VALUE;
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTSecGrpMembId( src.getRequiredTSecGrpMembId() );
	}

	CFSecTSecGrpMembPKey::~CFSecTSecGrpMembPKey() {
	}

	const int64_t CFSecTSecGrpMembPKey::getRequiredTenantId() const {
		return( requiredTenantId );
	}

	const int64_t* CFSecTSecGrpMembPKey::getRequiredTenantIdReference() const {
		return( &requiredTenantId );
	}

	void CFSecTSecGrpMembPKey::setRequiredTenantId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredTenantId" );
		if( value < cfsec::CFSecTSecGrpMembBuff::TENANTID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecTSecGrpMembBuff::TENANTID_MIN_VALUE );
		}
		requiredTenantId = value;
	}

	const int64_t CFSecTSecGrpMembPKey::getRequiredTSecGrpMembId() const {
		return( requiredTSecGrpMembId );
	}

	const int64_t* CFSecTSecGrpMembPKey::getRequiredTSecGrpMembIdReference() const {
		return( &requiredTSecGrpMembId );
	}

	void CFSecTSecGrpMembPKey::setRequiredTSecGrpMembId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredTSecGrpMembId" );
		if( value < cfsec::CFSecTSecGrpMembBuff::TSECGRPMEMBID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecTSecGrpMembBuff::TSECGRPMEMBID_MIN_VALUE );
		}
		requiredTSecGrpMembId = value;
	}

	bool CFSecTSecGrpMembPKey::operator <( const CFSecTSecGrpMembHPKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembPKey::operator <( const CFSecTSecGrpMembPKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembPKey::operator <( const CFSecTSecGrpMembHBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembPKey::operator <( const CFSecTSecGrpMembBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembPKey::operator <=( const CFSecTSecGrpMembHPKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembPKey::operator <=( const CFSecTSecGrpMembPKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembPKey::operator <=( const CFSecTSecGrpMembHBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembPKey::operator <=( const CFSecTSecGrpMembBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembPKey::operator ==( const CFSecTSecGrpMembHPKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpMembPKey::operator ==( const CFSecTSecGrpMembPKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpMembPKey::operator ==( const CFSecTSecGrpMembHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpMembPKey::operator ==( const CFSecTSecGrpMembBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpMembPKey::operator !=( const CFSecTSecGrpMembHPKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembPKey::operator !=( const CFSecTSecGrpMembPKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembPKey::operator !=( const CFSecTSecGrpMembHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembPKey::operator !=( const CFSecTSecGrpMembBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembPKey::operator >=( const CFSecTSecGrpMembHPKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembPKey::operator >=( const CFSecTSecGrpMembPKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembPKey::operator >=( const CFSecTSecGrpMembHBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembPKey::operator >=( const CFSecTSecGrpMembBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpMembPKey::operator >( const CFSecTSecGrpMembHPKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembPKey::operator >( const CFSecTSecGrpMembPKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembPKey::operator >( const CFSecTSecGrpMembHBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpMembPKey::operator >( const CFSecTSecGrpMembBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	CFSecTSecGrpMembPKey CFSecTSecGrpMembPKey::operator =( cfsec::CFSecTSecGrpMembPKey& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTSecGrpMembId( src.getRequiredTSecGrpMembId() );
		return( *this );
	}

	CFSecTSecGrpMembPKey CFSecTSecGrpMembPKey::operator =( cfsec::CFSecTSecGrpMembHPKey& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTSecGrpMembId( src.getRequiredTSecGrpMembId() );
		return( *this );
	}

	CFSecTSecGrpMembPKey CFSecTSecGrpMembPKey::operator =( cfsec::CFSecTSecGrpMembBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTSecGrpMembId( src.getRequiredTSecGrpMembId() );
		return( *this );
	}

	CFSecTSecGrpMembPKey CFSecTSecGrpMembPKey::operator =( cfsec::CFSecTSecGrpMembHBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTSecGrpMembId( src.getRequiredTSecGrpMembId() );
		return( *this );
	}

	size_t CFSecTSecGrpMembPKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredTenantId() );
		hashCode = hashCode + (int)( getRequiredTSecGrpMembId() );
		return( hashCode );
	}

	std::string CFSecTSecGrpMembPKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecTSecGrpMembPKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_TSecGrpMembId( "TSecGrpMembId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TSecGrpMembId, getRequiredTSecGrpMembId() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() != rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembHPKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembPKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTSecGrpMembPKey& lhs, const cfsec::CFSecTSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpMembId() < rhs.getRequiredTSecGrpMembId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpMembId() > rhs.getRequiredTSecGrpMembId() ) {
			return( true );
		}
		return( false );
	}
}

