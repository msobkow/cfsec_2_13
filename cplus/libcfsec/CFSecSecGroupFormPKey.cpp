// Description: C++18 implementation of a SecGroupForm primary key object.

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

#include <cfsec/CFSecSecGroupFormPKey.hpp>
#include <cfsec/CFSecSecGroupFormBuff.hpp>
#include <cfsec/CFSecSecGroupFormHPKey.hpp>
#include <cfsec/CFSecSecGroupFormHBuff.hpp>

namespace cfsec {

	const std::string CFSecSecGroupFormPKey::CLASS_NAME( "CFSecSecGroupFormPKey" );
	const std::string CFSecSecGroupFormPKey::S_VALUE( "value" );
	const std::string CFSecSecGroupFormPKey::S_VALUE_LENGTH( "value.length()" );

	CFSecSecGroupFormPKey::CFSecSecGroupFormPKey() {
		requiredClusterId = cfsec::CFSecSecGroupFormBuff::CLUSTERID_INIT_VALUE;
		requiredSecGroupFormId = cfsec::CFSecSecGroupFormBuff::SECGROUPFORMID_INIT_VALUE;
	}

	CFSecSecGroupFormPKey::CFSecSecGroupFormPKey( const CFSecSecGroupFormPKey& src ) {
		requiredClusterId = cfsec::CFSecSecGroupFormBuff::CLUSTERID_INIT_VALUE;
		requiredSecGroupFormId = cfsec::CFSecSecGroupFormBuff::SECGROUPFORMID_INIT_VALUE;
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecGroupFormId( src.getRequiredSecGroupFormId() );
	}

	CFSecSecGroupFormPKey::~CFSecSecGroupFormPKey() {
	}

	const int64_t CFSecSecGroupFormPKey::getRequiredClusterId() const {
		return( requiredClusterId );
	}

	const int64_t* CFSecSecGroupFormPKey::getRequiredClusterIdReference() const {
		return( &requiredClusterId );
	}

	void CFSecSecGroupFormPKey::setRequiredClusterId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredClusterId" );
		if( value < cfsec::CFSecSecGroupFormBuff::CLUSTERID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecSecGroupFormBuff::CLUSTERID_MIN_VALUE );
		}
		requiredClusterId = value;
	}

	const int64_t CFSecSecGroupFormPKey::getRequiredSecGroupFormId() const {
		return( requiredSecGroupFormId );
	}

	const int64_t* CFSecSecGroupFormPKey::getRequiredSecGroupFormIdReference() const {
		return( &requiredSecGroupFormId );
	}

	void CFSecSecGroupFormPKey::setRequiredSecGroupFormId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredSecGroupFormId" );
		if( value < cfsec::CFSecSecGroupFormBuff::SECGROUPFORMID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecSecGroupFormBuff::SECGROUPFORMID_MIN_VALUE );
		}
		requiredSecGroupFormId = value;
	}

	bool CFSecSecGroupFormPKey::operator <( const CFSecSecGroupFormHPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGroupFormPKey::operator <( const CFSecSecGroupFormPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGroupFormPKey::operator <( const CFSecSecGroupFormHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGroupFormPKey::operator <( const CFSecSecGroupFormBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGroupFormPKey::operator <=( const CFSecSecGroupFormHPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGroupFormPKey::operator <=( const CFSecSecGroupFormPKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGroupFormPKey::operator <=( const CFSecSecGroupFormHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGroupFormPKey::operator <=( const CFSecSecGroupFormBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGroupFormPKey::operator ==( const CFSecSecGroupFormHPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecGroupFormId() != rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGroupFormPKey::operator ==( const CFSecSecGroupFormPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecGroupFormId() != rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGroupFormPKey::operator ==( const CFSecSecGroupFormHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecGroupFormId() != rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGroupFormPKey::operator ==( const CFSecSecGroupFormBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecGroupFormId() != rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGroupFormPKey::operator !=( const CFSecSecGroupFormHPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupFormId() != rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGroupFormPKey::operator !=( const CFSecSecGroupFormPKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupFormId() != rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGroupFormPKey::operator !=( const CFSecSecGroupFormHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupFormId() != rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGroupFormPKey::operator !=( const CFSecSecGroupFormBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupFormId() != rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGroupFormPKey::operator >=( const CFSecSecGroupFormHPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGroupFormPKey::operator >=( const CFSecSecGroupFormPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGroupFormPKey::operator >=( const CFSecSecGroupFormHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGroupFormPKey::operator >=( const CFSecSecGroupFormBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGroupFormPKey::operator >( const CFSecSecGroupFormHPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGroupFormPKey::operator >( const CFSecSecGroupFormPKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGroupFormPKey::operator >( const CFSecSecGroupFormHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGroupFormPKey::operator >( const CFSecSecGroupFormBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}

	CFSecSecGroupFormPKey CFSecSecGroupFormPKey::operator =( cfsec::CFSecSecGroupFormPKey& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecGroupFormId( src.getRequiredSecGroupFormId() );
		return( *this );
	}

	CFSecSecGroupFormPKey CFSecSecGroupFormPKey::operator =( cfsec::CFSecSecGroupFormHPKey& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecGroupFormId( src.getRequiredSecGroupFormId() );
		return( *this );
	}

	CFSecSecGroupFormPKey CFSecSecGroupFormPKey::operator =( cfsec::CFSecSecGroupFormBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecGroupFormId( src.getRequiredSecGroupFormId() );
		return( *this );
	}

	CFSecSecGroupFormPKey CFSecSecGroupFormPKey::operator =( cfsec::CFSecSecGroupFormHBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecGroupFormId( src.getRequiredSecGroupFormId() );
		return( *this );
	}

	size_t CFSecSecGroupFormPKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredClusterId() );
		hashCode = hashCode + (int)( getRequiredSecGroupFormId() );
		return( hashCode );
	}

	std::string CFSecSecGroupFormPKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecGroupFormPKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecGroupFormId( "SecGroupFormId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_SecGroupFormId, getRequiredSecGroupFormId() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormHPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormHPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormPKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormHPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecGroupFormId() != rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecGroupFormId() != rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecGroupFormId() != rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecGroupFormId() != rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormHPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupFormId() != rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormPKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupFormId() != rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupFormId() != rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupFormId() != rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormHPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormHPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormPKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecGroupFormPKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupFormId() < rhs.getRequiredSecGroupFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupFormId() > rhs.getRequiredSecGroupFormId() ) {
			return( true );
		}
		return( false );
	}
}

