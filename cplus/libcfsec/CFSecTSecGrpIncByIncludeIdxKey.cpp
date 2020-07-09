// Description: C++18 implementation for a TSecGrpInc by IncludeIdx index key object.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	This file is part of MSS Code Factory.
 *	
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *	    http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <cflib/ICFLibPublic.hpp>

using namespace std;

#include <cfsec/CFSecTSecGrpIncByIncludeIdxKey.hpp>
#include <cfsec/CFSecTSecGrpIncBuff.hpp>
#include <cfsec/CFSecTSecGrpIncHBuff.hpp>

namespace cfsec {
	const std::string CFSecTSecGrpIncByIncludeIdxKey::CLASS_NAME( "CFSecTSecGrpIncByIncludeIdxKey" );
	const std::string CFSecTSecGrpIncByIncludeIdxKey::S_VALUE( "value" );
	const std::string CFSecTSecGrpIncByIncludeIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecTSecGrpIncByIncludeIdxKey::CFSecTSecGrpIncByIncludeIdxKey() {
		requiredTenantId = cfsec::CFSecTSecGrpIncBuff::TENANTID_INIT_VALUE;
		requiredIncludeGroupId = cfsec::CFSecTSecGrpIncBuff::INCLUDEGROUPID_INIT_VALUE;
	}

	CFSecTSecGrpIncByIncludeIdxKey::CFSecTSecGrpIncByIncludeIdxKey( const CFSecTSecGrpIncByIncludeIdxKey& src ) {
		requiredTenantId = cfsec::CFSecTSecGrpIncBuff::TENANTID_INIT_VALUE;
		requiredIncludeGroupId = cfsec::CFSecTSecGrpIncBuff::INCLUDEGROUPID_INIT_VALUE;
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredIncludeGroupId( src.getRequiredIncludeGroupId() );
	}

	CFSecTSecGrpIncByIncludeIdxKey::~CFSecTSecGrpIncByIncludeIdxKey() {
	}

	const int64_t CFSecTSecGrpIncByIncludeIdxKey::getRequiredTenantId() const {
		return( requiredTenantId );
	}

	const int64_t* CFSecTSecGrpIncByIncludeIdxKey::getRequiredTenantIdReference() const {
		return( &requiredTenantId );
	}

	void CFSecTSecGrpIncByIncludeIdxKey::setRequiredTenantId( const int64_t value ) {
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

	const int32_t CFSecTSecGrpIncByIncludeIdxKey::getRequiredIncludeGroupId() const {
		return( requiredIncludeGroupId );
	}

	const int32_t* CFSecTSecGrpIncByIncludeIdxKey::getRequiredIncludeGroupIdReference() const {
		return( &requiredIncludeGroupId );
	}

	void CFSecTSecGrpIncByIncludeIdxKey::setRequiredIncludeGroupId( const int32_t value ) {
		static const std::string S_ProcName( "setRequiredIncludeGroupId" );
		if( value < cfsec::CFSecTSecGrpIncBuff::INCLUDEGROUPID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecTSecGrpIncBuff::INCLUDEGROUPID_MIN_VALUE );
		}
		requiredIncludeGroupId = value;
	}

	size_t CFSecTSecGrpIncByIncludeIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredTenantId() );
		hashCode = hashCode + getRequiredIncludeGroupId();
		return( hashCode );
	}

	std::string CFSecTSecGrpIncByIncludeIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecTSecGrpIncByIncludeIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_IncludeGroupId( "IncludeGroupId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_IncludeGroupId, getRequiredIncludeGroupId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecTSecGrpIncByIncludeIdxKey::operator <( const CFSecTSecGrpIncByIncludeIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncByIncludeIdxKey::operator <( const CFSecTSecGrpIncHBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncByIncludeIdxKey::operator <( const CFSecTSecGrpIncBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncByIncludeIdxKey::operator <=( const CFSecTSecGrpIncByIncludeIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpIncByIncludeIdxKey::operator <=( const CFSecTSecGrpIncHBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpIncByIncludeIdxKey::operator <=( const CFSecTSecGrpIncBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpIncByIncludeIdxKey::operator ==( const CFSecTSecGrpIncByIncludeIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpIncByIncludeIdxKey::operator ==( const CFSecTSecGrpIncHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpIncByIncludeIdxKey::operator ==( const CFSecTSecGrpIncBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpIncByIncludeIdxKey::operator !=( const CFSecTSecGrpIncByIncludeIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncByIncludeIdxKey::operator !=( const CFSecTSecGrpIncHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncByIncludeIdxKey::operator !=( const CFSecTSecGrpIncBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncByIncludeIdxKey::operator >=( const CFSecTSecGrpIncByIncludeIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpIncByIncludeIdxKey::operator >=( const CFSecTSecGrpIncHBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpIncByIncludeIdxKey::operator >=( const CFSecTSecGrpIncBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpIncByIncludeIdxKey::operator >( const CFSecTSecGrpIncByIncludeIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncByIncludeIdxKey::operator >( const CFSecTSecGrpIncHBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncByIncludeIdxKey::operator >( const CFSecTSecGrpIncBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}
	CFSecTSecGrpIncByIncludeIdxKey CFSecTSecGrpIncByIncludeIdxKey::operator =( cfsec::CFSecTSecGrpIncByIncludeIdxKey& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredIncludeGroupId( src.getRequiredIncludeGroupId() );
		return( *this );
	}

	CFSecTSecGrpIncByIncludeIdxKey CFSecTSecGrpIncByIncludeIdxKey::operator =( cfsec::CFSecTSecGrpIncBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredIncludeGroupId( src.getRequiredIncludeGroupId() );
		return( *this );
	}

	CFSecTSecGrpIncByIncludeIdxKey CFSecTSecGrpIncByIncludeIdxKey::operator =( cfsec::CFSecTSecGrpIncHBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredIncludeGroupId( src.getRequiredIncludeGroupId() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncByIncludeIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncByIncludeIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncByIncludeIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncByIncludeIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() != rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncByIncludeIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncByIncludeIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTSecGrpIncByIncludeIdxKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIncludeGroupId() < rhs.getRequiredIncludeGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredIncludeGroupId() > rhs.getRequiredIncludeGroupId() ) {
			return( true );
		}
		return( false );
	}
}

