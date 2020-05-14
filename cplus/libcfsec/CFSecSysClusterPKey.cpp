// Description: C++18 implementation of a SysCluster primary key object.

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

#include <cfsec/CFSecSysClusterPKey.hpp>
#include <cfsec/CFSecSysClusterBuff.hpp>
#include <cfsec/CFSecSysClusterHPKey.hpp>
#include <cfsec/CFSecSysClusterHBuff.hpp>

namespace cfsec {

	const std::string CFSecSysClusterPKey::CLASS_NAME( "CFSecSysClusterPKey" );
	const std::string CFSecSysClusterPKey::S_VALUE( "value" );
	const std::string CFSecSysClusterPKey::S_VALUE_LENGTH( "value.length()" );

	CFSecSysClusterPKey::CFSecSysClusterPKey() {
		requiredSingletonId = cfsec::CFSecSysClusterBuff::SINGLETONID_INIT_VALUE;
	}

	CFSecSysClusterPKey::CFSecSysClusterPKey( const CFSecSysClusterPKey& src ) {
		requiredSingletonId = cfsec::CFSecSysClusterBuff::SINGLETONID_INIT_VALUE;
		setRequiredSingletonId( src.getRequiredSingletonId() );
	}

	CFSecSysClusterPKey::~CFSecSysClusterPKey() {
	}

	const int32_t CFSecSysClusterPKey::getRequiredSingletonId() const {
		return( requiredSingletonId );
	}

	const int32_t* CFSecSysClusterPKey::getRequiredSingletonIdReference() const {
		return( &requiredSingletonId );
	}

	void CFSecSysClusterPKey::setRequiredSingletonId( const int32_t value ) {
		static const std::string S_ProcName( "setRequiredSingletonId" );
		if( value < cfsec::CFSecSysClusterBuff::SINGLETONID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecSysClusterBuff::SINGLETONID_MIN_VALUE );
		}
		if( value > cfsec::CFSecSysClusterBuff::SINGLETONID_MAX_VALUE ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecSysClusterBuff::SINGLETONID_MAX_VALUE );
		}
		requiredSingletonId = value;
	}

	bool CFSecSysClusterPKey::operator <( const CFSecSysClusterHPKey& rhs ) {
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterPKey::operator <( const CFSecSysClusterPKey& rhs ) {
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterPKey::operator <( const CFSecSysClusterHBuff& rhs ) {
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterPKey::operator <( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterPKey::operator <=( const CFSecSysClusterHPKey& rhs ) {
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterPKey::operator <=( const CFSecSysClusterPKey& rhs ) {
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterPKey::operator <=( const CFSecSysClusterHBuff& rhs ) {
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterPKey::operator <=( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterPKey::operator ==( const CFSecSysClusterHPKey& rhs ) {
		if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSysClusterPKey::operator ==( const CFSecSysClusterPKey& rhs ) {
		if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSysClusterPKey::operator ==( const CFSecSysClusterHBuff& rhs ) {
		if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSysClusterPKey::operator ==( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSysClusterPKey::operator !=( const CFSecSysClusterHPKey& rhs ) {
		if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterPKey::operator !=( const CFSecSysClusterPKey& rhs ) {
		if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterPKey::operator !=( const CFSecSysClusterHBuff& rhs ) {
		if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterPKey::operator !=( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterPKey::operator >=( const CFSecSysClusterHPKey& rhs ) {
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterPKey::operator >=( const CFSecSysClusterPKey& rhs ) {
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterPKey::operator >=( const CFSecSysClusterHBuff& rhs ) {
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterPKey::operator >=( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterPKey::operator >( const CFSecSysClusterHPKey& rhs ) {
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterPKey::operator >( const CFSecSysClusterPKey& rhs ) {
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterPKey::operator >( const CFSecSysClusterHBuff& rhs ) {
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterPKey::operator >( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	CFSecSysClusterPKey CFSecSysClusterPKey::operator =( cfsec::CFSecSysClusterPKey& src ) {
		setRequiredSingletonId( src.getRequiredSingletonId() );
		return( *this );
	}

	CFSecSysClusterPKey CFSecSysClusterPKey::operator =( cfsec::CFSecSysClusterHPKey& src ) {
		setRequiredSingletonId( src.getRequiredSingletonId() );
		return( *this );
	}

	CFSecSysClusterPKey CFSecSysClusterPKey::operator =( cfsec::CFSecSysClusterBuff& src ) {
		setRequiredSingletonId( src.getRequiredSingletonId() );
		return( *this );
	}

	CFSecSysClusterPKey CFSecSysClusterPKey::operator =( cfsec::CFSecSysClusterHBuff& src ) {
		setRequiredSingletonId( src.getRequiredSingletonId() );
		return( *this );
	}

	size_t CFSecSysClusterPKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + getRequiredSingletonId();
		return( hashCode );
	}

	std::string CFSecSysClusterPKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSysClusterPKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_SingletonId( "SingletonId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SingletonId, getRequiredSingletonId() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHPKey& rhs ) {
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterPKey& rhs ) {
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHPKey& rhs ) {
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterPKey& rhs ) {
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHPKey& rhs ) {
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterPKey& rhs ) {
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHPKey& rhs ) {
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterPKey& rhs ) {
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHPKey& rhs ) {
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterPKey& rhs ) {
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHPKey& rhs ) {
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterPKey& rhs ) {
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSysClusterPKey& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}
}

