// Description: C++18 implementation for a SecForm by SecAppIdx index key object.

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

#include <cfsec/CFSecSecFormBySecAppIdxKey.hpp>
#include <cfsec/CFSecSecFormBuff.hpp>
#include <cfsec/CFSecSecFormHBuff.hpp>

namespace cfsec {
	const std::string CFSecSecFormBySecAppIdxKey::CLASS_NAME( "CFSecSecFormBySecAppIdxKey" );
	const std::string CFSecSecFormBySecAppIdxKey::S_VALUE( "value" );
	const std::string CFSecSecFormBySecAppIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecSecFormBySecAppIdxKey::CFSecSecFormBySecAppIdxKey() {
		requiredClusterId = cfsec::CFSecSecFormBuff::CLUSTERID_INIT_VALUE;
		requiredSecAppId = cfsec::CFSecSecFormBuff::SECAPPID_INIT_VALUE;
	}

	CFSecSecFormBySecAppIdxKey::CFSecSecFormBySecAppIdxKey( const CFSecSecFormBySecAppIdxKey& src ) {
		requiredClusterId = cfsec::CFSecSecFormBuff::CLUSTERID_INIT_VALUE;
		requiredSecAppId = cfsec::CFSecSecFormBuff::SECAPPID_INIT_VALUE;
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecAppId( src.getRequiredSecAppId() );
	}

	CFSecSecFormBySecAppIdxKey::~CFSecSecFormBySecAppIdxKey() {
	}

	const int64_t CFSecSecFormBySecAppIdxKey::getRequiredClusterId() const {
		return( requiredClusterId );
	}

	const int64_t* CFSecSecFormBySecAppIdxKey::getRequiredClusterIdReference() const {
		return( &requiredClusterId );
	}

	void CFSecSecFormBySecAppIdxKey::setRequiredClusterId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredClusterId" );
		if( value < cfsec::CFSecSecFormBuff::CLUSTERID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecSecFormBuff::CLUSTERID_MIN_VALUE );
		}
		requiredClusterId = value;
	}

	const int32_t CFSecSecFormBySecAppIdxKey::getRequiredSecAppId() const {
		return( requiredSecAppId );
	}

	const int32_t* CFSecSecFormBySecAppIdxKey::getRequiredSecAppIdReference() const {
		return( &requiredSecAppId );
	}

	void CFSecSecFormBySecAppIdxKey::setRequiredSecAppId( const int32_t value ) {
		static const std::string S_ProcName( "setRequiredSecAppId" );
		if( value < cfsec::CFSecSecFormBuff::SECAPPID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecSecFormBuff::SECAPPID_MIN_VALUE );
		}
		requiredSecAppId = value;
	}

	size_t CFSecSecFormBySecAppIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredClusterId() );
		hashCode = hashCode + getRequiredSecAppId();
		return( hashCode );
	}

	std::string CFSecSecFormBySecAppIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecFormBySecAppIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecAppId( "SecAppId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecAppId, getRequiredSecAppId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecSecFormBySecAppIdxKey::operator <( const CFSecSecFormBySecAppIdxKey& rhs ) {
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

	bool CFSecSecFormBySecAppIdxKey::operator <( const CFSecSecFormHBuff& rhs ) {
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

	bool CFSecSecFormBySecAppIdxKey::operator <( const CFSecSecFormBuff& rhs ) {
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

	bool CFSecSecFormBySecAppIdxKey::operator <=( const CFSecSecFormBySecAppIdxKey& rhs ) {
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

	bool CFSecSecFormBySecAppIdxKey::operator <=( const CFSecSecFormHBuff& rhs ) {
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

	bool CFSecSecFormBySecAppIdxKey::operator <=( const CFSecSecFormBuff& rhs ) {
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

	bool CFSecSecFormBySecAppIdxKey::operator ==( const CFSecSecFormBySecAppIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecFormBySecAppIdxKey::operator ==( const CFSecSecFormHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecFormBySecAppIdxKey::operator ==( const CFSecSecFormBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecFormBySecAppIdxKey::operator !=( const CFSecSecFormBySecAppIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecFormBySecAppIdxKey::operator !=( const CFSecSecFormHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecFormBySecAppIdxKey::operator !=( const CFSecSecFormBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecFormBySecAppIdxKey::operator >=( const CFSecSecFormBySecAppIdxKey& rhs ) {
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

	bool CFSecSecFormBySecAppIdxKey::operator >=( const CFSecSecFormHBuff& rhs ) {
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

	bool CFSecSecFormBySecAppIdxKey::operator >=( const CFSecSecFormBuff& rhs ) {
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

	bool CFSecSecFormBySecAppIdxKey::operator >( const CFSecSecFormBySecAppIdxKey& rhs ) {
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

	bool CFSecSecFormBySecAppIdxKey::operator >( const CFSecSecFormHBuff& rhs ) {
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

	bool CFSecSecFormBySecAppIdxKey::operator >( const CFSecSecFormBuff& rhs ) {
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
	CFSecSecFormBySecAppIdxKey CFSecSecFormBySecAppIdxKey::operator =( cfsec::CFSecSecFormBySecAppIdxKey& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecAppId( src.getRequiredSecAppId() );
		return( *this );
	}

	CFSecSecFormBySecAppIdxKey CFSecSecFormBySecAppIdxKey::operator =( cfsec::CFSecSecFormBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecAppId( src.getRequiredSecAppId() );
		return( *this );
	}

	CFSecSecFormBySecAppIdxKey CFSecSecFormBySecAppIdxKey::operator =( cfsec::CFSecSecFormHBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecAppId( src.getRequiredSecAppId() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBySecAppIdxKey& rhs ) {
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

	bool operator <(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormHBuff& rhs ) {
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

	bool operator <(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBuff& rhs ) {
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

	bool operator <=(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBySecAppIdxKey& rhs ) {
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

	bool operator <=(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormHBuff& rhs ) {
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

	bool operator <=(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBuff& rhs ) {
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

	bool operator ==(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBySecAppIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBySecAppIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBySecAppIdxKey& rhs ) {
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

	bool operator >=(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormHBuff& rhs ) {
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

	bool operator >=(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBuff& rhs ) {
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

	bool operator >(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBySecAppIdxKey& rhs ) {
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

	bool operator >(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormHBuff& rhs ) {
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

	bool operator >(const  cfsec::CFSecSecFormBySecAppIdxKey& lhs, const cfsec::CFSecSecFormBuff& rhs ) {
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
