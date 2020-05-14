// Description: C++18 implementation for a Tenant by UNameIdx index key object.

/*
 *	com.github.msobkow.CFSec
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

#include <cfsec/CFSecTenantByUNameIdxKey.hpp>
#include <cfsec/CFSecTenantBuff.hpp>
#include <cfsec/CFSecTenantHBuff.hpp>

namespace cfsec {
	const std::string CFSecTenantByUNameIdxKey::CLASS_NAME( "CFSecTenantByUNameIdxKey" );
	const std::string CFSecTenantByUNameIdxKey::S_VALUE( "value" );
	const std::string CFSecTenantByUNameIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecTenantByUNameIdxKey::CFSecTenantByUNameIdxKey() {
		requiredClusterId = cfsec::CFSecTenantBuff::CLUSTERID_INIT_VALUE;
		requiredTenantName = new std::string( cfsec::CFSecTenantBuff::TENANTNAME_INIT_VALUE );
	}

	CFSecTenantByUNameIdxKey::CFSecTenantByUNameIdxKey( const CFSecTenantByUNameIdxKey& src ) {
		requiredClusterId = cfsec::CFSecTenantBuff::CLUSTERID_INIT_VALUE;
		requiredTenantName = new std::string( cfsec::CFSecTenantBuff::TENANTNAME_INIT_VALUE );
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredTenantName( src.getRequiredTenantName() );
	}

	CFSecTenantByUNameIdxKey::~CFSecTenantByUNameIdxKey() {
		if( requiredTenantName != NULL ) {
			delete requiredTenantName;
			requiredTenantName = NULL;
		}
	}

	const int64_t CFSecTenantByUNameIdxKey::getRequiredClusterId() const {
		return( requiredClusterId );
	}

	const int64_t* CFSecTenantByUNameIdxKey::getRequiredClusterIdReference() const {
		return( &requiredClusterId );
	}

	void CFSecTenantByUNameIdxKey::setRequiredClusterId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredClusterId" );
		if( value < cfsec::CFSecTenantBuff::CLUSTERID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecTenantBuff::CLUSTERID_MIN_VALUE );
		}
		requiredClusterId = value;
	}

	const std::string& CFSecTenantByUNameIdxKey::getRequiredTenantName() const {
		return( *requiredTenantName );
	}

	const std::string* CFSecTenantByUNameIdxKey::getRequiredTenantNameReference() const {
		return( requiredTenantName );
	}

	void CFSecTenantByUNameIdxKey::setRequiredTenantName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredTenantName" );
		if( value.length() > CFSecTenantBuff::TENANTNAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecTenantBuff::TENANTNAME_MAX_LEN );
		}
		if( requiredTenantName != NULL ) {
			delete requiredTenantName;
			requiredTenantName = NULL;
		}
		requiredTenantName = new std::string( value );
	}

	size_t CFSecTenantByUNameIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredClusterId() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredTenantName() );
		return( hashCode );
	}

	std::string CFSecTenantByUNameIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecTenantByUNameIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_TenantName( "TenantName" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_TenantName, getRequiredTenantName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecTenantByUNameIdxKey::operator <( const CFSecTenantByUNameIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantByUNameIdxKey::operator <( const CFSecTenantHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantByUNameIdxKey::operator <( const CFSecTenantBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantByUNameIdxKey::operator <=( const CFSecTenantByUNameIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTenantByUNameIdxKey::operator <=( const CFSecTenantHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTenantByUNameIdxKey::operator <=( const CFSecTenantBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTenantByUNameIdxKey::operator ==( const CFSecTenantByUNameIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTenantByUNameIdxKey::operator ==( const CFSecTenantHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTenantByUNameIdxKey::operator ==( const CFSecTenantBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTenantByUNameIdxKey::operator !=( const CFSecTenantByUNameIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantByUNameIdxKey::operator !=( const CFSecTenantHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantByUNameIdxKey::operator !=( const CFSecTenantBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantByUNameIdxKey::operator >=( const CFSecTenantByUNameIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTenantByUNameIdxKey::operator >=( const CFSecTenantHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTenantByUNameIdxKey::operator >=( const CFSecTenantBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTenantByUNameIdxKey::operator >( const CFSecTenantByUNameIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantByUNameIdxKey::operator >( const CFSecTenantHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTenantByUNameIdxKey::operator >( const CFSecTenantBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}
	CFSecTenantByUNameIdxKey CFSecTenantByUNameIdxKey::operator =( cfsec::CFSecTenantByUNameIdxKey& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredTenantName( src.getRequiredTenantName() );
		return( *this );
	}

	CFSecTenantByUNameIdxKey CFSecTenantByUNameIdxKey::operator =( cfsec::CFSecTenantBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredTenantName( src.getRequiredTenantName() );
		return( *this );
	}

	CFSecTenantByUNameIdxKey CFSecTenantByUNameIdxKey::operator =( cfsec::CFSecTenantHBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredTenantName( src.getRequiredTenantName() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() != rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantByUNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTenantByUNameIdxKey& lhs, const cfsec::CFSecTenantBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredTenantName() < rhs.getRequiredTenantName() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantName() > rhs.getRequiredTenantName() ) {
			return( true );
		}
		return( false );
	}
}

