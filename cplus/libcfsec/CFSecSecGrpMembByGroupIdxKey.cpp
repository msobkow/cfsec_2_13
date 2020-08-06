// Description: C++18 implementation for a SecGrpMemb by GroupIdx index key object.

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

#include <cfsec/CFSecSecGrpMembByGroupIdxKey.hpp>
#include <cfsec/CFSecSecGrpMembBuff.hpp>
#include <cfsec/CFSecSecGrpMembHBuff.hpp>

namespace cfsec {
	const std::string CFSecSecGrpMembByGroupIdxKey::CLASS_NAME( "CFSecSecGrpMembByGroupIdxKey" );
	const std::string CFSecSecGrpMembByGroupIdxKey::S_VALUE( "value" );
	const std::string CFSecSecGrpMembByGroupIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecSecGrpMembByGroupIdxKey::CFSecSecGrpMembByGroupIdxKey() {
		requiredClusterId = cfsec::CFSecSecGrpMembBuff::CLUSTERID_INIT_VALUE;
		requiredSecGroupId = cfsec::CFSecSecGrpMembBuff::SECGROUPID_INIT_VALUE;
	}

	CFSecSecGrpMembByGroupIdxKey::CFSecSecGrpMembByGroupIdxKey( const CFSecSecGrpMembByGroupIdxKey& src ) {
		requiredClusterId = cfsec::CFSecSecGrpMembBuff::CLUSTERID_INIT_VALUE;
		requiredSecGroupId = cfsec::CFSecSecGrpMembBuff::SECGROUPID_INIT_VALUE;
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecGroupId( src.getRequiredSecGroupId() );
	}

	CFSecSecGrpMembByGroupIdxKey::~CFSecSecGrpMembByGroupIdxKey() {
	}

	const int64_t CFSecSecGrpMembByGroupIdxKey::getRequiredClusterId() const {
		return( requiredClusterId );
	}

	const int64_t* CFSecSecGrpMembByGroupIdxKey::getRequiredClusterIdReference() const {
		return( &requiredClusterId );
	}

	void CFSecSecGrpMembByGroupIdxKey::setRequiredClusterId( const int64_t value ) {
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

	const int32_t CFSecSecGrpMembByGroupIdxKey::getRequiredSecGroupId() const {
		return( requiredSecGroupId );
	}

	const int32_t* CFSecSecGrpMembByGroupIdxKey::getRequiredSecGroupIdReference() const {
		return( &requiredSecGroupId );
	}

	void CFSecSecGrpMembByGroupIdxKey::setRequiredSecGroupId( const int32_t value ) {
		static const std::string S_ProcName( "setRequiredSecGroupId" );
		if( value < cfsec::CFSecSecGrpMembBuff::SECGROUPID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecSecGrpMembBuff::SECGROUPID_MIN_VALUE );
		}
		requiredSecGroupId = value;
	}

	size_t CFSecSecGrpMembByGroupIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredClusterId() );
		hashCode = hashCode + getRequiredSecGroupId();
		return( hashCode );
	}

	std::string CFSecSecGrpMembByGroupIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecGrpMembByGroupIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecGroupId( "SecGroupId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecGroupId, getRequiredSecGroupId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecSecGrpMembByGroupIdxKey::operator <( const CFSecSecGrpMembByGroupIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpMembByGroupIdxKey::operator <( const CFSecSecGrpMembHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpMembByGroupIdxKey::operator <( const CFSecSecGrpMembBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpMembByGroupIdxKey::operator <=( const CFSecSecGrpMembByGroupIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpMembByGroupIdxKey::operator <=( const CFSecSecGrpMembHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpMembByGroupIdxKey::operator <=( const CFSecSecGrpMembBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpMembByGroupIdxKey::operator ==( const CFSecSecGrpMembByGroupIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGrpMembByGroupIdxKey::operator ==( const CFSecSecGrpMembHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGrpMembByGroupIdxKey::operator ==( const CFSecSecGrpMembBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGrpMembByGroupIdxKey::operator !=( const CFSecSecGrpMembByGroupIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpMembByGroupIdxKey::operator !=( const CFSecSecGrpMembHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpMembByGroupIdxKey::operator !=( const CFSecSecGrpMembBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpMembByGroupIdxKey::operator >=( const CFSecSecGrpMembByGroupIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpMembByGroupIdxKey::operator >=( const CFSecSecGrpMembHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpMembByGroupIdxKey::operator >=( const CFSecSecGrpMembBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGrpMembByGroupIdxKey::operator >( const CFSecSecGrpMembByGroupIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpMembByGroupIdxKey::operator >( const CFSecSecGrpMembHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGrpMembByGroupIdxKey::operator >( const CFSecSecGrpMembBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( false );
	}
	CFSecSecGrpMembByGroupIdxKey CFSecSecGrpMembByGroupIdxKey::operator =( cfsec::CFSecSecGrpMembByGroupIdxKey& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecGroupId( src.getRequiredSecGroupId() );
		return( *this );
	}

	CFSecSecGrpMembByGroupIdxKey CFSecSecGrpMembByGroupIdxKey::operator =( cfsec::CFSecSecGrpMembBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecGroupId( src.getRequiredSecGroupId() );
		return( *this );
	}

	CFSecSecGrpMembByGroupIdxKey CFSecSecGrpMembByGroupIdxKey::operator =( cfsec::CFSecSecGrpMembHBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecGroupId( src.getRequiredSecGroupId() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecSecGrpMembByGroupIdxKey& lhs, const cfsec::CFSecSecGrpMembByGroupIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecGrpMembByGroupIdxKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecGrpMembByGroupIdxKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSecGrpMembByGroupIdxKey& lhs, const cfsec::CFSecSecGrpMembByGroupIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecGrpMembByGroupIdxKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecGrpMembByGroupIdxKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGrpMembByGroupIdxKey& lhs, const cfsec::CFSecSecGrpMembByGroupIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGrpMembByGroupIdxKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGrpMembByGroupIdxKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSecGrpMembByGroupIdxKey& lhs, const cfsec::CFSecSecGrpMembByGroupIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecGrpMembByGroupIdxKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecGrpMembByGroupIdxKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSecGrpMembByGroupIdxKey& lhs, const cfsec::CFSecSecGrpMembByGroupIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecGrpMembByGroupIdxKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecGrpMembByGroupIdxKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSecGrpMembByGroupIdxKey& lhs, const cfsec::CFSecSecGrpMembByGroupIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecGrpMembByGroupIdxKey& lhs, const cfsec::CFSecSecGrpMembHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecGrpMembByGroupIdxKey& lhs, const cfsec::CFSecSecGrpMembBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		return( false );
	}
}

