// Description: C++18 implementation for a Cluster by UDomNameIdx index key object.

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

#include <cfsec/CFSecClusterByUDomNameIdxKey.hpp>
#include <cfsec/CFSecClusterBuff.hpp>
#include <cfsec/CFSecClusterHBuff.hpp>

namespace cfsec {
	const std::string CFSecClusterByUDomNameIdxKey::CLASS_NAME( "CFSecClusterByUDomNameIdxKey" );
	const std::string CFSecClusterByUDomNameIdxKey::S_VALUE( "value" );
	const std::string CFSecClusterByUDomNameIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecClusterByUDomNameIdxKey::CFSecClusterByUDomNameIdxKey() {
		requiredFullDomName = new std::string( cfsec::CFSecClusterBuff::FULLDOMNAME_INIT_VALUE );
	}

	CFSecClusterByUDomNameIdxKey::CFSecClusterByUDomNameIdxKey( const CFSecClusterByUDomNameIdxKey& src ) {
		requiredFullDomName = new std::string( cfsec::CFSecClusterBuff::FULLDOMNAME_INIT_VALUE );
		setRequiredFullDomName( src.getRequiredFullDomName() );
	}

	CFSecClusterByUDomNameIdxKey::~CFSecClusterByUDomNameIdxKey() {
		if( requiredFullDomName != NULL ) {
			delete requiredFullDomName;
			requiredFullDomName = NULL;
		}
	}

	const std::string& CFSecClusterByUDomNameIdxKey::getRequiredFullDomName() const {
		return( *requiredFullDomName );
	}

	const std::string* CFSecClusterByUDomNameIdxKey::getRequiredFullDomNameReference() const {
		return( requiredFullDomName );
	}

	void CFSecClusterByUDomNameIdxKey::setRequiredFullDomName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredFullDomName" );
		if( value.length() > CFSecClusterBuff::FULLDOMNAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecClusterBuff::FULLDOMNAME_MAX_LEN );
		}
		if( requiredFullDomName != NULL ) {
			delete requiredFullDomName;
			requiredFullDomName = NULL;
		}
		requiredFullDomName = new std::string( value );
	}

	size_t CFSecClusterByUDomNameIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + cflib::CFLib::hash( getRequiredFullDomName() );
		return( hashCode );
	}

	std::string CFSecClusterByUDomNameIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecClusterByUDomNameIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_FullDomName( "FullDomName" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_FullDomName, getRequiredFullDomName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecClusterByUDomNameIdxKey::operator <( const CFSecClusterByUDomNameIdxKey& rhs ) {
		if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDomNameIdxKey::operator <( const CFSecClusterHBuff& rhs ) {
		if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDomNameIdxKey::operator <( const CFSecClusterBuff& rhs ) {
		if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDomNameIdxKey::operator <=( const CFSecClusterByUDomNameIdxKey& rhs ) {
		if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecClusterByUDomNameIdxKey::operator <=( const CFSecClusterHBuff& rhs ) {
		if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecClusterByUDomNameIdxKey::operator <=( const CFSecClusterBuff& rhs ) {
		if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecClusterByUDomNameIdxKey::operator ==( const CFSecClusterByUDomNameIdxKey& rhs ) {
		if( getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecClusterByUDomNameIdxKey::operator ==( const CFSecClusterHBuff& rhs ) {
		if( getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecClusterByUDomNameIdxKey::operator ==( const CFSecClusterBuff& rhs ) {
		if( getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecClusterByUDomNameIdxKey::operator !=( const CFSecClusterByUDomNameIdxKey& rhs ) {
		if( getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDomNameIdxKey::operator !=( const CFSecClusterHBuff& rhs ) {
		if( getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDomNameIdxKey::operator !=( const CFSecClusterBuff& rhs ) {
		if( getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDomNameIdxKey::operator >=( const CFSecClusterByUDomNameIdxKey& rhs ) {
		if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecClusterByUDomNameIdxKey::operator >=( const CFSecClusterHBuff& rhs ) {
		if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecClusterByUDomNameIdxKey::operator >=( const CFSecClusterBuff& rhs ) {
		if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecClusterByUDomNameIdxKey::operator >( const CFSecClusterByUDomNameIdxKey& rhs ) {
		if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDomNameIdxKey::operator >( const CFSecClusterHBuff& rhs ) {
		if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDomNameIdxKey::operator >( const CFSecClusterBuff& rhs ) {
		if( getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}
	CFSecClusterByUDomNameIdxKey CFSecClusterByUDomNameIdxKey::operator =( cfsec::CFSecClusterByUDomNameIdxKey& src ) {
		setRequiredFullDomName( src.getRequiredFullDomName() );
		return( *this );
	}

	CFSecClusterByUDomNameIdxKey CFSecClusterByUDomNameIdxKey::operator =( cfsec::CFSecClusterBuff& src ) {
		setRequiredFullDomName( src.getRequiredFullDomName() );
		return( *this );
	}

	CFSecClusterByUDomNameIdxKey CFSecClusterByUDomNameIdxKey::operator =( cfsec::CFSecClusterHBuff& src ) {
		setRequiredFullDomName( src.getRequiredFullDomName() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs ) {
		if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs ) {
		if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs ) {
		if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs ) {
		if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs ) {
		if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs ) {
		if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs ) {
		if( lhs.getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs ) {
		if( lhs.getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs ) {
		if( lhs.getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs ) {
		if( lhs.getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs ) {
		if( lhs.getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs ) {
		if( lhs.getRequiredFullDomName() != rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs ) {
		if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs ) {
		if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs ) {
		if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterByUDomNameIdxKey& rhs ) {
		if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs ) {
		if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecClusterByUDomNameIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs ) {
		if( lhs.getRequiredFullDomName() < rhs.getRequiredFullDomName() ) {
			return( false );
		}
		else if( lhs.getRequiredFullDomName() > rhs.getRequiredFullDomName() ) {
			return( true );
		}
		return( false );
	}
}

