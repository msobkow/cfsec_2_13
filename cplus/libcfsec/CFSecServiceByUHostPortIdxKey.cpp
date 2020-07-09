// Description: C++18 implementation for a Service by UHostPortIdx index key object.

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

#include <cfsec/CFSecServiceByUHostPortIdxKey.hpp>
#include <cfsec/CFSecServiceBuff.hpp>
#include <cfsec/CFSecServiceHBuff.hpp>

namespace cfsec {
	const std::string CFSecServiceByUHostPortIdxKey::CLASS_NAME( "CFSecServiceByUHostPortIdxKey" );
	const std::string CFSecServiceByUHostPortIdxKey::S_VALUE( "value" );
	const std::string CFSecServiceByUHostPortIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecServiceByUHostPortIdxKey::CFSecServiceByUHostPortIdxKey() {
		requiredClusterId = cfsec::CFSecServiceBuff::CLUSTERID_INIT_VALUE;
		requiredHostNodeId = cfsec::CFSecServiceBuff::HOSTNODEID_INIT_VALUE;
		requiredHostPort = cfsec::CFSecServiceBuff::HOSTPORT_INIT_VALUE;
	}

	CFSecServiceByUHostPortIdxKey::CFSecServiceByUHostPortIdxKey( const CFSecServiceByUHostPortIdxKey& src ) {
		requiredClusterId = cfsec::CFSecServiceBuff::CLUSTERID_INIT_VALUE;
		requiredHostNodeId = cfsec::CFSecServiceBuff::HOSTNODEID_INIT_VALUE;
		requiredHostPort = cfsec::CFSecServiceBuff::HOSTPORT_INIT_VALUE;
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredHostNodeId( src.getRequiredHostNodeId() );
		setRequiredHostPort( src.getRequiredHostPort() );
	}

	CFSecServiceByUHostPortIdxKey::~CFSecServiceByUHostPortIdxKey() {
	}

	const int64_t CFSecServiceByUHostPortIdxKey::getRequiredClusterId() const {
		return( requiredClusterId );
	}

	const int64_t* CFSecServiceByUHostPortIdxKey::getRequiredClusterIdReference() const {
		return( &requiredClusterId );
	}

	void CFSecServiceByUHostPortIdxKey::setRequiredClusterId( const int64_t value ) {
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

	const int64_t CFSecServiceByUHostPortIdxKey::getRequiredHostNodeId() const {
		return( requiredHostNodeId );
	}

	const int64_t* CFSecServiceByUHostPortIdxKey::getRequiredHostNodeIdReference() const {
		return( &requiredHostNodeId );
	}

	void CFSecServiceByUHostPortIdxKey::setRequiredHostNodeId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredHostNodeId" );
		if( value < cfsec::CFSecServiceBuff::HOSTNODEID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecServiceBuff::HOSTNODEID_MIN_VALUE );
		}
		requiredHostNodeId = value;
	}

	const int16_t CFSecServiceByUHostPortIdxKey::getRequiredHostPort() const {
		return( requiredHostPort );
	}

	const int16_t* CFSecServiceByUHostPortIdxKey::getRequiredHostPortReference() const {
		return( &requiredHostPort );
	}

	void CFSecServiceByUHostPortIdxKey::setRequiredHostPort( const int16_t value ) {
		static const std::string S_ProcName( "setRequiredHostPort" );
		if( value < cfsec::CFSecServiceBuff::HOSTPORT_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecServiceBuff::HOSTPORT_MIN_VALUE );
		}
		requiredHostPort = value;
	}

	size_t CFSecServiceByUHostPortIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredClusterId() );
		hashCode = hashCode + (int)( getRequiredHostNodeId() );
		hashCode = ( hashCode * 0x10000 ) + getRequiredHostPort();
		return( hashCode );
	}

	std::string CFSecServiceByUHostPortIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecServiceByUHostPortIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_HostNodeId( "HostNodeId" );
		static const std::string S_HostPort( "HostPort" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_HostNodeId, getRequiredHostNodeId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_HostPort, getRequiredHostPort() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecServiceByUHostPortIdxKey::operator <( const CFSecServiceByUHostPortIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceByUHostPortIdxKey::operator <( const CFSecServiceHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceByUHostPortIdxKey::operator <( const CFSecServiceBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceByUHostPortIdxKey::operator <=( const CFSecServiceByUHostPortIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceByUHostPortIdxKey::operator <=( const CFSecServiceHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceByUHostPortIdxKey::operator <=( const CFSecServiceBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceByUHostPortIdxKey::operator ==( const CFSecServiceByUHostPortIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		if( getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceByUHostPortIdxKey::operator ==( const CFSecServiceHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		if( getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceByUHostPortIdxKey::operator ==( const CFSecServiceBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		if( getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceByUHostPortIdxKey::operator !=( const CFSecServiceByUHostPortIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceByUHostPortIdxKey::operator !=( const CFSecServiceHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceByUHostPortIdxKey::operator !=( const CFSecServiceBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceByUHostPortIdxKey::operator >=( const CFSecServiceByUHostPortIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceByUHostPortIdxKey::operator >=( const CFSecServiceHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceByUHostPortIdxKey::operator >=( const CFSecServiceBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceByUHostPortIdxKey::operator >( const CFSecServiceByUHostPortIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceByUHostPortIdxKey::operator >( const CFSecServiceHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceByUHostPortIdxKey::operator >( const CFSecServiceBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}
	CFSecServiceByUHostPortIdxKey CFSecServiceByUHostPortIdxKey::operator =( cfsec::CFSecServiceByUHostPortIdxKey& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredHostNodeId( src.getRequiredHostNodeId() );
		setRequiredHostPort( src.getRequiredHostPort() );
		return( *this );
	}

	CFSecServiceByUHostPortIdxKey CFSecServiceByUHostPortIdxKey::operator =( cfsec::CFSecServiceBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredHostNodeId( src.getRequiredHostNodeId() );
		setRequiredHostPort( src.getRequiredHostPort() );
		return( *this );
	}

	CFSecServiceByUHostPortIdxKey CFSecServiceByUHostPortIdxKey::operator =( cfsec::CFSecServiceHBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredHostNodeId( src.getRequiredHostNodeId() );
		setRequiredHostPort( src.getRequiredHostPort() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		if( lhs.getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		if( lhs.getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		if( lhs.getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() != rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() != rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceByUHostPortIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecServiceByUHostPortIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredHostNodeId() < rhs.getRequiredHostNodeId() ) {
			return( false );
		}
		else if( lhs.getRequiredHostNodeId() > rhs.getRequiredHostNodeId() ) {
			return( true );
		}
		if( lhs.getRequiredHostPort() < rhs.getRequiredHostPort() ) {
			return( false );
		}
		else if( lhs.getRequiredHostPort() > rhs.getRequiredHostPort() ) {
			return( true );
		}
		return( false );
	}
}

