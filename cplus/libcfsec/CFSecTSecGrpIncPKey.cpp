// Description: C++18 implementation of a TSecGrpInc primary key object.

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

#include <cfsec/CFSecTSecGrpIncPKey.hpp>
#include <cfsec/CFSecTSecGrpIncBuff.hpp>
#include <cfsec/CFSecTSecGrpIncHPKey.hpp>
#include <cfsec/CFSecTSecGrpIncHBuff.hpp>

namespace cfsec {

	const std::string CFSecTSecGrpIncPKey::CLASS_NAME( "CFSecTSecGrpIncPKey" );
	const std::string CFSecTSecGrpIncPKey::S_VALUE( "value" );
	const std::string CFSecTSecGrpIncPKey::S_VALUE_LENGTH( "value.length()" );

	CFSecTSecGrpIncPKey::CFSecTSecGrpIncPKey() {
		requiredTenantId = cfsec::CFSecTSecGrpIncBuff::TENANTID_INIT_VALUE;
		requiredTSecGrpIncId = cfsec::CFSecTSecGrpIncBuff::TSECGRPINCID_INIT_VALUE;
	}

	CFSecTSecGrpIncPKey::CFSecTSecGrpIncPKey( const CFSecTSecGrpIncPKey& src ) {
		requiredTenantId = cfsec::CFSecTSecGrpIncBuff::TENANTID_INIT_VALUE;
		requiredTSecGrpIncId = cfsec::CFSecTSecGrpIncBuff::TSECGRPINCID_INIT_VALUE;
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTSecGrpIncId( src.getRequiredTSecGrpIncId() );
	}

	CFSecTSecGrpIncPKey::~CFSecTSecGrpIncPKey() {
	}

	const int64_t CFSecTSecGrpIncPKey::getRequiredTenantId() const {
		return( requiredTenantId );
	}

	const int64_t* CFSecTSecGrpIncPKey::getRequiredTenantIdReference() const {
		return( &requiredTenantId );
	}

	void CFSecTSecGrpIncPKey::setRequiredTenantId( const int64_t value ) {
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

	const int64_t CFSecTSecGrpIncPKey::getRequiredTSecGrpIncId() const {
		return( requiredTSecGrpIncId );
	}

	const int64_t* CFSecTSecGrpIncPKey::getRequiredTSecGrpIncIdReference() const {
		return( &requiredTSecGrpIncId );
	}

	void CFSecTSecGrpIncPKey::setRequiredTSecGrpIncId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredTSecGrpIncId" );
		if( value < cfsec::CFSecTSecGrpIncBuff::TSECGRPINCID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecTSecGrpIncBuff::TSECGRPINCID_MIN_VALUE );
		}
		requiredTSecGrpIncId = value;
	}

	bool CFSecTSecGrpIncPKey::operator <( const CFSecTSecGrpIncHPKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncPKey::operator <( const CFSecTSecGrpIncPKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncPKey::operator <( const CFSecTSecGrpIncHBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncPKey::operator <( const CFSecTSecGrpIncBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncPKey::operator <=( const CFSecTSecGrpIncHPKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpIncPKey::operator <=( const CFSecTSecGrpIncPKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpIncPKey::operator <=( const CFSecTSecGrpIncHBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpIncPKey::operator <=( const CFSecTSecGrpIncBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpIncPKey::operator ==( const CFSecTSecGrpIncHPKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTSecGrpIncId() != rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpIncPKey::operator ==( const CFSecTSecGrpIncPKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTSecGrpIncId() != rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpIncPKey::operator ==( const CFSecTSecGrpIncHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTSecGrpIncId() != rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpIncPKey::operator ==( const CFSecTSecGrpIncBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTSecGrpIncId() != rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecTSecGrpIncPKey::operator !=( const CFSecTSecGrpIncHPKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpIncId() != rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncPKey::operator !=( const CFSecTSecGrpIncPKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpIncId() != rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncPKey::operator !=( const CFSecTSecGrpIncHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpIncId() != rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncPKey::operator !=( const CFSecTSecGrpIncBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpIncId() != rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncPKey::operator >=( const CFSecTSecGrpIncHPKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpIncPKey::operator >=( const CFSecTSecGrpIncPKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpIncPKey::operator >=( const CFSecTSecGrpIncHBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpIncPKey::operator >=( const CFSecTSecGrpIncBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecTSecGrpIncPKey::operator >( const CFSecTSecGrpIncHPKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncPKey::operator >( const CFSecTSecGrpIncPKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncPKey::operator >( const CFSecTSecGrpIncHBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecTSecGrpIncPKey::operator >( const CFSecTSecGrpIncBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	CFSecTSecGrpIncPKey CFSecTSecGrpIncPKey::operator =( cfsec::CFSecTSecGrpIncPKey& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTSecGrpIncId( src.getRequiredTSecGrpIncId() );
		return( *this );
	}

	CFSecTSecGrpIncPKey CFSecTSecGrpIncPKey::operator =( cfsec::CFSecTSecGrpIncHPKey& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTSecGrpIncId( src.getRequiredTSecGrpIncId() );
		return( *this );
	}

	CFSecTSecGrpIncPKey CFSecTSecGrpIncPKey::operator =( cfsec::CFSecTSecGrpIncBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTSecGrpIncId( src.getRequiredTSecGrpIncId() );
		return( *this );
	}

	CFSecTSecGrpIncPKey CFSecTSecGrpIncPKey::operator =( cfsec::CFSecTSecGrpIncHBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTSecGrpIncId( src.getRequiredTSecGrpIncId() );
		return( *this );
	}

	size_t CFSecTSecGrpIncPKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredTenantId() );
		hashCode = hashCode + (int)( getRequiredTSecGrpIncId() );
		return( hashCode );
	}

	std::string CFSecTSecGrpIncPKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecTSecGrpIncPKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_TSecGrpIncId( "TSecGrpIncId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TSecGrpIncId, getRequiredTSecGrpIncId() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTSecGrpIncId() != rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTSecGrpIncId() != rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTSecGrpIncId() != rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTSecGrpIncId() != rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpIncId() != rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpIncId() != rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpIncId() != rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpIncId() != rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHPKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncPKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncHBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecTSecGrpIncPKey& lhs, const cfsec::CFSecTSecGrpIncBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTSecGrpIncId() < rhs.getRequiredTSecGrpIncId() ) {
			return( false );
		}
		else if( lhs.getRequiredTSecGrpIncId() > rhs.getRequiredTSecGrpIncId() ) {
			return( true );
		}
		return( false );
	}
}

