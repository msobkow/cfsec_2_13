// Description: C++18 implementation for a SecForm by UJEEServletIdx index key object.

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

#include <cfsec/CFSecSecFormByUJEEServletIdxKey.hpp>
#include <cfsec/CFSecSecFormBuff.hpp>
#include <cfsec/CFSecSecFormHBuff.hpp>

namespace cfsec {
	const std::string CFSecSecFormByUJEEServletIdxKey::CLASS_NAME( "CFSecSecFormByUJEEServletIdxKey" );
	const std::string CFSecSecFormByUJEEServletIdxKey::S_VALUE( "value" );
	const std::string CFSecSecFormByUJEEServletIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecSecFormByUJEEServletIdxKey::CFSecSecFormByUJEEServletIdxKey() {
		requiredClusterId = cfsec::CFSecSecFormBuff::CLUSTERID_INIT_VALUE;
		requiredSecAppId = cfsec::CFSecSecFormBuff::SECAPPID_INIT_VALUE;
		requiredJEEServletMapName = new std::string( cfsec::CFSecSecFormBuff::JEESERVLETMAPNAME_INIT_VALUE );
	}

	CFSecSecFormByUJEEServletIdxKey::CFSecSecFormByUJEEServletIdxKey( const CFSecSecFormByUJEEServletIdxKey& src ) {
		requiredClusterId = cfsec::CFSecSecFormBuff::CLUSTERID_INIT_VALUE;
		requiredSecAppId = cfsec::CFSecSecFormBuff::SECAPPID_INIT_VALUE;
		requiredJEEServletMapName = new std::string( cfsec::CFSecSecFormBuff::JEESERVLETMAPNAME_INIT_VALUE );
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecAppId( src.getRequiredSecAppId() );
		setRequiredJEEServletMapName( src.getRequiredJEEServletMapName() );
	}

	CFSecSecFormByUJEEServletIdxKey::~CFSecSecFormByUJEEServletIdxKey() {
		if( requiredJEEServletMapName != NULL ) {
			delete requiredJEEServletMapName;
			requiredJEEServletMapName = NULL;
		}
	}

	const int64_t CFSecSecFormByUJEEServletIdxKey::getRequiredClusterId() const {
		return( requiredClusterId );
	}

	const int64_t* CFSecSecFormByUJEEServletIdxKey::getRequiredClusterIdReference() const {
		return( &requiredClusterId );
	}

	void CFSecSecFormByUJEEServletIdxKey::setRequiredClusterId( const int64_t value ) {
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

	const int32_t CFSecSecFormByUJEEServletIdxKey::getRequiredSecAppId() const {
		return( requiredSecAppId );
	}

	const int32_t* CFSecSecFormByUJEEServletIdxKey::getRequiredSecAppIdReference() const {
		return( &requiredSecAppId );
	}

	void CFSecSecFormByUJEEServletIdxKey::setRequiredSecAppId( const int32_t value ) {
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

	const std::string& CFSecSecFormByUJEEServletIdxKey::getRequiredJEEServletMapName() const {
		return( *requiredJEEServletMapName );
	}

	const std::string* CFSecSecFormByUJEEServletIdxKey::getRequiredJEEServletMapNameReference() const {
		return( requiredJEEServletMapName );
	}

	void CFSecSecFormByUJEEServletIdxKey::setRequiredJEEServletMapName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredJEEServletMapName" );
		if( value.length() > CFSecSecFormBuff::JEESERVLETMAPNAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecSecFormBuff::JEESERVLETMAPNAME_MAX_LEN );
		}
		if( requiredJEEServletMapName != NULL ) {
			delete requiredJEEServletMapName;
			requiredJEEServletMapName = NULL;
		}
		requiredJEEServletMapName = new std::string( value );
	}

	size_t CFSecSecFormByUJEEServletIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredClusterId() );
		hashCode = hashCode + getRequiredSecAppId();
		hashCode = hashCode + cflib::CFLib::hash( getRequiredJEEServletMapName() );
		return( hashCode );
	}

	std::string CFSecSecFormByUJEEServletIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecFormByUJEEServletIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecAppId( "SecAppId" );
		static const std::string S_JEEServletMapName( "JEEServletMapName" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecAppId, getRequiredSecAppId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_JEEServletMapName, getRequiredJEEServletMapName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecSecFormByUJEEServletIdxKey::operator <( const CFSecSecFormByUJEEServletIdxKey& rhs ) {
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
		if( getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecFormByUJEEServletIdxKey::operator <( const CFSecSecFormHBuff& rhs ) {
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
		if( getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecFormByUJEEServletIdxKey::operator <( const CFSecSecFormBuff& rhs ) {
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
		if( getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecFormByUJEEServletIdxKey::operator <=( const CFSecSecFormByUJEEServletIdxKey& rhs ) {
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
		if( getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecFormByUJEEServletIdxKey::operator <=( const CFSecSecFormHBuff& rhs ) {
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
		if( getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecFormByUJEEServletIdxKey::operator <=( const CFSecSecFormBuff& rhs ) {
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
		if( getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecFormByUJEEServletIdxKey::operator ==( const CFSecSecFormByUJEEServletIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		if( getRequiredJEEServletMapName() != rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecFormByUJEEServletIdxKey::operator ==( const CFSecSecFormHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		if( getRequiredJEEServletMapName() != rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecFormByUJEEServletIdxKey::operator ==( const CFSecSecFormBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		if( getRequiredJEEServletMapName() != rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecFormByUJEEServletIdxKey::operator !=( const CFSecSecFormByUJEEServletIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( getRequiredJEEServletMapName() != rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecFormByUJEEServletIdxKey::operator !=( const CFSecSecFormHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( getRequiredJEEServletMapName() != rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecFormByUJEEServletIdxKey::operator !=( const CFSecSecFormBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( getRequiredJEEServletMapName() != rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecFormByUJEEServletIdxKey::operator >=( const CFSecSecFormByUJEEServletIdxKey& rhs ) {
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
		if( getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecFormByUJEEServletIdxKey::operator >=( const CFSecSecFormHBuff& rhs ) {
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
		if( getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecFormByUJEEServletIdxKey::operator >=( const CFSecSecFormBuff& rhs ) {
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
		if( getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecFormByUJEEServletIdxKey::operator >( const CFSecSecFormByUJEEServletIdxKey& rhs ) {
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
		if( getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecFormByUJEEServletIdxKey::operator >( const CFSecSecFormHBuff& rhs ) {
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
		if( getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecFormByUJEEServletIdxKey::operator >( const CFSecSecFormBuff& rhs ) {
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
		if( getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( false );
	}
	CFSecSecFormByUJEEServletIdxKey CFSecSecFormByUJEEServletIdxKey::operator =( cfsec::CFSecSecFormByUJEEServletIdxKey& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecAppId( src.getRequiredSecAppId() );
		setRequiredJEEServletMapName( src.getRequiredJEEServletMapName() );
		return( *this );
	}

	CFSecSecFormByUJEEServletIdxKey CFSecSecFormByUJEEServletIdxKey::operator =( cfsec::CFSecSecFormBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecAppId( src.getRequiredSecAppId() );
		setRequiredJEEServletMapName( src.getRequiredJEEServletMapName() );
		return( *this );
	}

	CFSecSecFormByUJEEServletIdxKey CFSecSecFormByUJEEServletIdxKey::operator =( cfsec::CFSecSecFormHBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecAppId( src.getRequiredSecAppId() );
		setRequiredJEEServletMapName( src.getRequiredJEEServletMapName() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecSecFormByUJEEServletIdxKey& lhs, const cfsec::CFSecSecFormByUJEEServletIdxKey& rhs ) {
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
		if( lhs.getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecFormByUJEEServletIdxKey& lhs, const cfsec::CFSecSecFormHBuff& rhs ) {
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
		if( lhs.getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecFormByUJEEServletIdxKey& lhs, const cfsec::CFSecSecFormBuff& rhs ) {
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
		if( lhs.getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSecFormByUJEEServletIdxKey& lhs, const cfsec::CFSecSecFormByUJEEServletIdxKey& rhs ) {
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
		if( lhs.getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecFormByUJEEServletIdxKey& lhs, const cfsec::CFSecSecFormHBuff& rhs ) {
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
		if( lhs.getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecFormByUJEEServletIdxKey& lhs, const cfsec::CFSecSecFormBuff& rhs ) {
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
		if( lhs.getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecFormByUJEEServletIdxKey& lhs, const cfsec::CFSecSecFormByUJEEServletIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		if( lhs.getRequiredJEEServletMapName() != rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecFormByUJEEServletIdxKey& lhs, const cfsec::CFSecSecFormHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		if( lhs.getRequiredJEEServletMapName() != rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecFormByUJEEServletIdxKey& lhs, const cfsec::CFSecSecFormBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( false );
		}
		if( lhs.getRequiredJEEServletMapName() != rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSecFormByUJEEServletIdxKey& lhs, const cfsec::CFSecSecFormByUJEEServletIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEServletMapName() != rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecFormByUJEEServletIdxKey& lhs, const cfsec::CFSecSecFormHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEServletMapName() != rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecFormByUJEEServletIdxKey& lhs, const cfsec::CFSecSecFormBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecAppId() != rhs.getRequiredSecAppId() ) {
			return( true );
		}
		if( lhs.getRequiredJEEServletMapName() != rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSecFormByUJEEServletIdxKey& lhs, const cfsec::CFSecSecFormByUJEEServletIdxKey& rhs ) {
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
		if( lhs.getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecFormByUJEEServletIdxKey& lhs, const cfsec::CFSecSecFormHBuff& rhs ) {
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
		if( lhs.getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecFormByUJEEServletIdxKey& lhs, const cfsec::CFSecSecFormBuff& rhs ) {
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
		if( lhs.getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSecFormByUJEEServletIdxKey& lhs, const cfsec::CFSecSecFormByUJEEServletIdxKey& rhs ) {
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
		if( lhs.getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecFormByUJEEServletIdxKey& lhs, const cfsec::CFSecSecFormHBuff& rhs ) {
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
		if( lhs.getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecFormByUJEEServletIdxKey& lhs, const cfsec::CFSecSecFormBuff& rhs ) {
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
		if( lhs.getRequiredJEEServletMapName() < rhs.getRequiredJEEServletMapName() ) {
			return( false );
		}
		else if( lhs.getRequiredJEEServletMapName() > rhs.getRequiredJEEServletMapName() ) {
			return( true );
		}
		return( false );
	}
}

