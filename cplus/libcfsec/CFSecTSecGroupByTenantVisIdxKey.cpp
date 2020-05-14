// Description: C++18 implementation for a TSecGroup by TenantVisIdx index key object.

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

#include <cfsec/CFSecTSecGroupByTenantVisIdxKey.hpp>
#include <cfsec/CFSecTSecGroupBuff.hpp>
#include <cfsec/CFSecTSecGroupHBuff.hpp>

namespace cfsec {
	const std::string CFSecTSecGroupByTenantVisIdxKey::CLASS_NAME( "CFSecTSecGroupByTenantVisIdxKey" );
	const std::string CFSecTSecGroupByTenantVisIdxKey::S_VALUE( "value" );
	const std::string CFSecTSecGroupByTenantVisIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecTSecGroupByTenantVisIdxKey::CFSecTSecGroupByTenantVisIdxKey() {
		requiredTenantId = cfsec::CFSecTSecGroupBuff::TENANTID_INIT_VALUE;
		requiredIsVisible = cfsec::CFSecTSecGroupBuff::ISVISIBLE_INIT_VALUE;
	}

	CFSecTSecGroupByTenantVisIdxKey::CFSecTSecGroupByTenantVisIdxKey( const CFSecTSecGroupByTenantVisIdxKey& src ) {
		requiredTenantId = cfsec::CFSecTSecGroupBuff::TENANTID_INIT_VALUE;
		requiredIsVisible = cfsec::CFSecTSecGroupBuff::ISVISIBLE_INIT_VALUE;
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredIsVisible( src.getRequiredIsVisible() );
	}

	CFSecTSecGroupByTenantVisIdxKey::~CFSecTSecGroupByTenantVisIdxKey() {
	}

	const int64_t CFSecTSecGroupByTenantVisIdxKey::getRequiredTenantId() const {
		return( requiredTenantId );
	}

	const int64_t* CFSecTSecGroupByTenantVisIdxKey::getRequiredTenantIdReference() const {
		return( &requiredTenantId );
	}

	void CFSecTSecGroupByTenantVisIdxKey::setRequiredTenantId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredTenantId" );
		if( value < cfsec::CFSecTSecGroupBuff::TENANTID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecTSecGroupBuff::TENANTID_MIN_VALUE );
		}
		requiredTenantId = value;
	}

	const bool CFSecTSecGroupByTenantVisIdxKey::getRequiredIsVisible() const {
		return( requiredIsVisible );
	}

	const bool* CFSecTSecGroupByTenantVisIdxKey::getRequiredIsVisibleReference() const {
		return( &requiredIsVisible );
	}

	void CFSecTSecGroupByTenantVisIdxKey::setRequiredIsVisible( const bool value ) {
		requiredIsVisible = value;
	}

	size_t CFSecTSecGroupByTenantVisIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredTenantId() );
		if( getRequiredIsVisible() ) {
			hashCode = ( hashCode * 2 ) + 1;
		}
		else {
			hashCode = hashCode * 2;
		}
		return( hashCode );
	}

	std::string CFSecTSecGroupByTenantVisIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecTSecGroupByTenantVisIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_IsVisible( "IsVisible" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredBoolean( &S_Space, S_IsVisible, getRequiredIsVisible() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecTSecGroupByTenantVisIdxKey::operator <( const CFSecTSecGroupByTenantVisIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGroupByTenantVisIdxKey::operator <( const CFSecTSecGroupHBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGroupByTenantVisIdxKey::operator <( const CFSecTSecGroupBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGroupByTenantVisIdxKey::operator <=( const CFSecTSecGroupByTenantVisIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGroupByTenantVisIdxKey::operator <=( const CFSecTSecGroupHBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGroupByTenantVisIdxKey::operator <=( const CFSecTSecGroupBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGroupByTenantVisIdxKey::operator ==( const CFSecTSecGroupByTenantVisIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredIsVisible() != rhs.getRequiredIsVisible() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGroupByTenantVisIdxKey::operator ==( const CFSecTSecGroupHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredIsVisible() != rhs.getRequiredIsVisible() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGroupByTenantVisIdxKey::operator ==( const CFSecTSecGroupBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredIsVisible() != rhs.getRequiredIsVisible() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGroupByTenantVisIdxKey::operator !=( const CFSecTSecGroupByTenantVisIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIsVisible() != rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGroupByTenantVisIdxKey::operator !=( const CFSecTSecGroupHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIsVisible() != rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGroupByTenantVisIdxKey::operator !=( const CFSecTSecGroupBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIsVisible() != rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGroupByTenantVisIdxKey::operator >=( const CFSecTSecGroupByTenantVisIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGroupByTenantVisIdxKey::operator >=( const CFSecTSecGroupHBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGroupByTenantVisIdxKey::operator >=( const CFSecTSecGroupBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGroupByTenantVisIdxKey::operator >( const CFSecTSecGroupByTenantVisIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGroupByTenantVisIdxKey::operator >( const CFSecTSecGroupHBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGroupByTenantVisIdxKey::operator >( const CFSecTSecGroupBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( false );
	}
	CFSecTSecGroupByTenantVisIdxKey CFSecTSecGroupByTenantVisIdxKey::operator =( cfsec::CFSecTSecGroupByTenantVisIdxKey& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredIsVisible( src.getRequiredIsVisible() );
		return( *this );
	}

	CFSecTSecGroupByTenantVisIdxKey CFSecTSecGroupByTenantVisIdxKey::operator =( cfsec::CFSecTSecGroupBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredIsVisible( src.getRequiredIsVisible() );
		return( *this );
	}

	CFSecTSecGroupByTenantVisIdxKey CFSecTSecGroupByTenantVisIdxKey::operator =( cfsec::CFSecTSecGroupHBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredIsVisible( src.getRequiredIsVisible() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupByTenantVisIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupByTenantVisIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupByTenantVisIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredIsVisible() != rhs.getRequiredIsVisible() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredIsVisible() != rhs.getRequiredIsVisible() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredIsVisible() != rhs.getRequiredIsVisible() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupByTenantVisIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIsVisible() != rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIsVisible() != rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIsVisible() != rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupByTenantVisIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupByTenantVisIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupHBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTSecGroupByTenantVisIdxKey& lhs, const cfsec::CFSecTSecGroupBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredIsVisible() < rhs.getRequiredIsVisible() ) {
			return( false );
		}
		else if( lhs.getRequiredIsVisible() > rhs.getRequiredIsVisible() ) {
			return( true );
		}
		return( false );
	}
}

