// Description: C++18 implementation of a Service primary key object.

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

#include <cfsec/CFSecServicePKey.hpp>
#include <cfsec/CFSecServiceBuff.hpp>
#include <cfsec/CFSecServiceHPKey.hpp>
#include <cfsec/CFSecServiceHBuff.hpp>

namespace cfsec {

	const std::string CFSecServicePKey::CLASS_NAME( "CFSecServicePKey" );
	const std::string CFSecServicePKey::S_VALUE( "value" );
	const std::string CFSecServicePKey::S_VALUE_LENGTH( "value.length()" );

	CFSecServicePKey::CFSecServicePKey() {
		requiredClusterId = cfsec::CFSecServiceBuff::CLUSTERID_INIT_VALUE;
		requiredServiceId = cfsec::CFSecServiceBuff::SERVICEID_INIT_VALUE;
	}

	CFSecServicePKey::CFSecServicePKey( const CFSecServicePKey& src ) {
		requiredClusterId = cfsec::CFSecServiceBuff::CLUSTERID_INIT_VALUE;
		requiredServiceId = cfsec::CFSecServiceBuff::SERVICEID_INIT_VALUE;
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredServiceId( src.getRequiredServiceId() );
	}

	CFSecServicePKey::~CFSecServicePKey() {
	}

	const int64_t CFSecServicePKey::getRequiredClusterId() const {
		return( requiredClusterId );
	}

	const int64_t* CFSecServicePKey::getRequiredClusterIdReference() const {
		return( &requiredClusterId );
	}

	void CFSecServicePKey::setRequiredClusterId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredClusterId" );
		if( value < cfsec::CFSecServiceBuff::CLUSTERID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecServiceBuff::CLUSTERID_MIN_VALUE );
		}
		requiredClusterId = value;
	}

	const int64_t CFSecServicePKey::getRequiredServiceId() const {
		return( requiredServiceId );
	}

	const int64_t* CFSecServicePKey::getRequiredServiceIdReference() const {
		return( &requiredServiceId );
	}

	void CFSecServicePKey::setRequiredServiceId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredServiceId" );
		if( value < cfsec::CFSecServiceBuff::SERVICEID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecServiceBuff::SERVICEID_MIN_VALUE );
		}
		requiredServiceId = value;
	}

	bool CFSecServicePKey::operator <( const CFSecServiceHPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServicePKey::operator <( const CFSecServicePKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServicePKey::operator <( const CFSecServiceHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServicePKey::operator <( const CFSecServiceBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServicePKey::operator <=( const CFSecServiceHPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServicePKey::operator <=( const CFSecServicePKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServicePKey::operator <=( const CFSecServiceHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServicePKey::operator <=( const CFSecServiceBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServicePKey::operator ==( const CFSecServiceHPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServicePKey::operator ==( const CFSecServicePKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServicePKey::operator ==( const CFSecServiceHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServicePKey::operator ==( const CFSecServiceBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServicePKey::operator !=( const CFSecServiceHPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServicePKey::operator !=( const CFSecServicePKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServicePKey::operator !=( const CFSecServiceHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServicePKey::operator !=( const CFSecServiceBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServicePKey::operator >=( const CFSecServiceHPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServicePKey::operator >=( const CFSecServicePKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServicePKey::operator >=( const CFSecServiceHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServicePKey::operator >=( const CFSecServiceBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServicePKey::operator >( const CFSecServiceHPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServicePKey::operator >( const CFSecServicePKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServicePKey::operator >( const CFSecServiceHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServicePKey::operator >( const CFSecServiceBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	CFSecServicePKey CFSecServicePKey::operator =( cfsec::CFSecServicePKey& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredServiceId( src.getRequiredServiceId() );
		return( *this );
	}

	CFSecServicePKey CFSecServicePKey::operator =( cfsec::CFSecServiceHPKey& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredServiceId( src.getRequiredServiceId() );
		return( *this );
	}

	CFSecServicePKey CFSecServicePKey::operator =( cfsec::CFSecServiceBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredServiceId( src.getRequiredServiceId() );
		return( *this );
	}

	CFSecServicePKey CFSecServicePKey::operator =( cfsec::CFSecServiceHBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredServiceId( src.getRequiredServiceId() );
		return( *this );
	}

	size_t CFSecServicePKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredClusterId() );
		hashCode = hashCode + (int)( getRequiredServiceId() );
		return( hashCode );
	}

	std::string CFSecServicePKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecServicePKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_ServiceId( "ServiceId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ServiceId, getRequiredServiceId() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServiceHPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServicePKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServiceHPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServicePKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServiceHPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServicePKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServiceHPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServicePKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() != rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServiceHPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServicePKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServiceHPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServicePKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecServicePKey& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredServiceId() < rhs.getRequiredServiceId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceId() > rhs.getRequiredServiceId() ) {
			return( true );
		}
		return( false );
	}
}

