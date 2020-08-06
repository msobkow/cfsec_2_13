// Description: C++18 implementation for a TSecGrpInc by GroupIdx index key object.

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

#include <cfsec/CFSecTSecGrpIncByGroupIdxKey.hpp>
#include <cfsec/CFSecTSecGrpIncBuff.hpp>
#include <cfsec/CFSecTSecGrpIncHBuff.hpp>

namespace cfsec {
	const std::string CFSecTSecGrpIncByGroupIdxKey::CLASS_NAME( "CFSecTSecGrpIncByGroupIdxKey" );
	const std::string CFSecTSecGrpIncByGroupIdxKey::S_VALUE( "value" );
	const std::string CFSecTSecGrpIncByGroupIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecTSecGrpIncByGroupIdxKey::CFSecTSecGrpIncByGroupIdxKey() {
		requiredTenantId = cfsec::CFSecTSecGrpIncBuff::TENANTID_INIT_VALUE;
		requiredTSecGroupId = cfsec::CFSecTSecGrpIncBuff::TSECGROUPID_INIT_VALUE;
	}

	CFSecTSecGrpIncByGroupIdxKey::CFSecTSecGrpIncByGroupIdxKey( const CFSecTSecGrpIncByGroupIdxKey& src ) {
		requiredTenantId = cfsec::CFSecTSecGrpIncBuff::TENANTID_INIT_VALUE;
		requiredTSecGroupId = cfsec::CFSecTSecGrpIncBuff::TSECGROUPID_INIT_VALUE;
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTSecGroupId( src.getRequiredTSecGroupId() );
	}

	CFSecTSecGrpIncByGroupIdxKey::~CFSecTSecGrpIncByGroupIdxKey() {
	}

	const int64_t CFSecTSecGrpIncByGroupIdxKey::getRequiredTenantId() const {
		return( requiredTenantId );
	}

	const int64_t* CFSecTSecGrpIncByGroupIdxKey::getRequiredTenantIdReference() const {
		return( &requiredTenantId );
	}

	void CFSecTSecGrpIncByGroupIdxKey::setRequiredTenantId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredTenantId" );
		if( value < cfsec::CFSecTSecGrpIncBuff::TENANTID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecTSecGrpIncBuff::TENANTID_MIN_VALUE );
		}
		requiredTenantId = value;
	}

	const int32_t CFSecTSecGrpIncByGroupIdxKey::getRequiredTSecGroupId() const {
		return( requiredTSecGroupId );
	}

	const int32_t* CFSecTSecGrpIncByGroupIdxKey::getRequiredTSecGroupIdReference() const {
		return( &requiredTSecGroupId );
	}

	void CFSecTSecGrpIncByGroupIdxKey::setRequiredTSecGroupId( const int32_t value ) {
		static const std::string S_ProcName( "setRequiredTSecGroupId" );
		if( value < cfsec::CFSecTSecGrpIncBuff::TSECGROUPID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecTSecGrpIncBuff::TSECGROUPID_MIN_VALUE );
		}
		requiredTSecGroupId = value;
	}

	size_t CFSecTSecGrpIncByGroupIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredTenantId() );
		hashCode = hashCode + getRequiredTSecGroupId();
		return( hashCode );
	}

	std::string CFSecTSecGrpIncByGroupIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecTSecGrpIncByGroupIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_TSecGroupId( "TSecGroupId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_TSecGroupId, getRequiredTSecGroupId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecTSecGrpIncByGroupIdxKey::operator <( const CFSecTSecGrpIncByGroupIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncByGroupIdxKey::operator <( const CFSecTSecGrpIncHBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncByGroupIdxKey::operator <( const CFSecTSecGrpIncBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncByGroupIdxKey::operator <=( const CFSecTSecGrpIncByGroupIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpIncByGroupIdxKey::operator <=( const CFSecTSecGrpIncHBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpIncByGroupIdxKey::operator <=( const CFSecTSecGrpIncBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpIncByGroupIdxKey::operator ==( const CFSecTSecGrpIncByGroupIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpIncByGroupIdxKey::operator ==( const CFSecTSecGrpIncHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpIncByGroupIdxKey::operator ==( const CFSecTSecGrpIncBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpIncByGroupIdxKey::operator !=( const CFSecTSecGrpIncByGroupIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncByGroupIdxKey::operator !=( const CFSecTSecGrpIncHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncByGroupIdxKey::operator !=( const CFSecTSecGrpIncBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncByGroupIdxKey::operator >=( const CFSecTSecGrpIncByGroupIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpIncByGroupIdxKey::operator >=( const CFSecTSecGrpIncHBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpIncByGroupIdxKey::operator >=( const CFSecTSecGrpIncBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpIncByGroupIdxKey::operator >( const CFSecTSecGrpIncByGroupIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncByGroupIdxKey::operator >( const CFSecTSecGrpIncHBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncByGroupIdxKey::operator >( const CFSecTSecGrpIncBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( false );
	}
	CFSecTSecGrpIncByGroupIdxKey CFSecTSecGrpIncByGroupIdxKey::operator =( cfsec::CFSecTSecGrpIncByGroupIdxKey& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTSecGroupId( src.getRequiredTSecGroupId() );
		return( *this );
	}

	CFSecTSecGrpIncByGroupIdxKey CFSecTSecGrpIncByGroupIdxKey::operator =( cfsec::CFSecTSecGrpIncBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTSecGroupId( src.getRequiredTSecGroupId() );
		return( *this );
	}

	CFSecTSecGrpIncByGroupIdxKey CFSecTSecGrpIncByGroupIdxKey::operator =( cfsec::CFSecTSecGrpIncHBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTSecGroupId( src.getRequiredTSecGroupId() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecTSecGrpIncByGroupIdxKey& lhs, const cfsec::CFSecTSecGrpIncByGroupIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecTSecGrpIncByGroupIdxKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecTSecGrpIncByGroupIdxKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpIncByGroupIdxKey& lhs, const cfsec::CFSecTSecGrpIncByGroupIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpIncByGroupIdxKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpIncByGroupIdxKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpIncByGroupIdxKey& lhs, const cfsec::CFSecTSecGrpIncByGroupIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpIncByGroupIdxKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpIncByGroupIdxKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpIncByGroupIdxKey& lhs, const cfsec::CFSecTSecGrpIncByGroupIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpIncByGroupIdxKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpIncByGroupIdxKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() != rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpIncByGroupIdxKey& lhs, const cfsec::CFSecTSecGrpIncByGroupIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpIncByGroupIdxKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpIncByGroupIdxKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecTSecGrpIncByGroupIdxKey& lhs, const cfsec::CFSecTSecGrpIncByGroupIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTSecGrpIncByGroupIdxKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTSecGrpIncByGroupIdxKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGroupId() < rhs.getRequiredTSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGroupId() > rhs.getRequiredTSecGroupId() ) {
			return( true );
		}
		return( false );
	}
}

