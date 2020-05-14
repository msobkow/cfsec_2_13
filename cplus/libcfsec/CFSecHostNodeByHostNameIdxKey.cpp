// Description: C++18 implementation for a HostNode by HostNameIdx index key object.

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

#include <cfsec/CFSecHostNodeByHostNameIdxKey.hpp>
#include <cfsec/CFSecHostNodeBuff.hpp>
#include <cfsec/CFSecHostNodeHBuff.hpp>

namespace cfsec {
	const std::string CFSecHostNodeByHostNameIdxKey::CLASS_NAME( "CFSecHostNodeByHostNameIdxKey" );
	const std::string CFSecHostNodeByHostNameIdxKey::S_VALUE( "value" );
	const std::string CFSecHostNodeByHostNameIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecHostNodeByHostNameIdxKey::CFSecHostNodeByHostNameIdxKey() {
		requiredClusterId = cfsec::CFSecHostNodeBuff::CLUSTERID_INIT_VALUE;
		requiredHostName = new std::string( cfsec::CFSecHostNodeBuff::HOSTNAME_INIT_VALUE );
	}

	CFSecHostNodeByHostNameIdxKey::CFSecHostNodeByHostNameIdxKey( const CFSecHostNodeByHostNameIdxKey& src ) {
		requiredClusterId = cfsec::CFSecHostNodeBuff::CLUSTERID_INIT_VALUE;
		requiredHostName = new std::string( cfsec::CFSecHostNodeBuff::HOSTNAME_INIT_VALUE );
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredHostName( src.getRequiredHostName() );
	}

	CFSecHostNodeByHostNameIdxKey::~CFSecHostNodeByHostNameIdxKey() {
		if( requiredHostName != NULL ) {
			delete requiredHostName;
			requiredHostName = NULL;
		}
	}

	const int64_t CFSecHostNodeByHostNameIdxKey::getRequiredClusterId() const {
		return( requiredClusterId );
	}

	const int64_t* CFSecHostNodeByHostNameIdxKey::getRequiredClusterIdReference() const {
		return( &requiredClusterId );
	}

	void CFSecHostNodeByHostNameIdxKey::setRequiredClusterId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredClusterId" );
		if( value < cfsec::CFSecHostNodeBuff::CLUSTERID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecHostNodeBuff::CLUSTERID_MIN_VALUE );
		}
		requiredClusterId = value;
	}

	const std::string& CFSecHostNodeByHostNameIdxKey::getRequiredHostName() const {
		return( *requiredHostName );
	}

	const std::string* CFSecHostNodeByHostNameIdxKey::getRequiredHostNameReference() const {
		return( requiredHostName );
	}

	void CFSecHostNodeByHostNameIdxKey::setRequiredHostName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredHostName" );
		if( value.length() > CFSecHostNodeBuff::HOSTNAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecHostNodeBuff::HOSTNAME_MAX_LEN );
		}
		if( requiredHostName != NULL ) {
			delete requiredHostName;
			requiredHostName = NULL;
		}
		requiredHostName = new std::string( value );
	}

	size_t CFSecHostNodeByHostNameIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredClusterId() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredHostName() );
		return( hashCode );
	}

	std::string CFSecHostNodeByHostNameIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecHostNodeByHostNameIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_HostName( "HostName" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_HostName, getRequiredHostName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecHostNodeByHostNameIdxKey::operator <( const CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeByHostNameIdxKey::operator <( const CFSecHostNodeHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeByHostNameIdxKey::operator <( const CFSecHostNodeBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeByHostNameIdxKey::operator <=( const CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecHostNodeByHostNameIdxKey::operator <=( const CFSecHostNodeHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecHostNodeByHostNameIdxKey::operator <=( const CFSecHostNodeBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecHostNodeByHostNameIdxKey::operator ==( const CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecHostNodeByHostNameIdxKey::operator ==( const CFSecHostNodeHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecHostNodeByHostNameIdxKey::operator ==( const CFSecHostNodeBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecHostNodeByHostNameIdxKey::operator !=( const CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeByHostNameIdxKey::operator !=( const CFSecHostNodeHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeByHostNameIdxKey::operator !=( const CFSecHostNodeBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeByHostNameIdxKey::operator >=( const CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecHostNodeByHostNameIdxKey::operator >=( const CFSecHostNodeHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecHostNodeByHostNameIdxKey::operator >=( const CFSecHostNodeBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecHostNodeByHostNameIdxKey::operator >( const CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeByHostNameIdxKey::operator >( const CFSecHostNodeHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecHostNodeByHostNameIdxKey::operator >( const CFSecHostNodeBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}
	CFSecHostNodeByHostNameIdxKey CFSecHostNodeByHostNameIdxKey::operator =( cfsec::CFSecHostNodeByHostNameIdxKey& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredHostName( src.getRequiredHostName() );
		return( *this );
	}

	CFSecHostNodeByHostNameIdxKey CFSecHostNodeByHostNameIdxKey::operator =( cfsec::CFSecHostNodeBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredHostName( src.getRequiredHostName() );
		return( *this );
	}

	CFSecHostNodeByHostNameIdxKey CFSecHostNodeByHostNameIdxKey::operator =( cfsec::CFSecHostNodeHBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredHostName( src.getRequiredHostName() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() != rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeByHostNameIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecHostNodeByHostNameIdxKey& lhs, const cfsec::CFSecHostNodeBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostName() < rhs.getRequiredHostName() ) {
			return( false );
		}
		else if( lhs.getRequiredHostName() > rhs.getRequiredHostName() ) {
			return( true );
		}
		return( false );
	}
}

