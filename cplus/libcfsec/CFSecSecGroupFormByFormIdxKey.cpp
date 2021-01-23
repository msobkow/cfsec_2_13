// Description: C++18 implementation for a SecGroupForm by FormIdx index key object.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow
 *	
 *		This file is part of MSS Code Factory.
 *	
 *		MSS Code Factory is available under dual commercial license from Mark Stephen
 *		Sobkow, or under the terms of the GNU General Public License, Version 3
 *		or later.
 *	
 *	    MSS Code Factory is free software: you can redistribute it and/or modify
 *	    it under the terms of the GNU General Public License as published by
 *	    the Free Software Foundation, either version 3 of the License, or
 *	    (at your option) any later version.
 *	
 *	    MSS Code Factory is distributed in the hope that it will be useful,
 *	    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	    GNU General Public License for more details.
 *	
 *	    You should have received a copy of the GNU General Public License
 *	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
 *	
 *	Please contact Mark Stephen Sobkow at mark.sobkow@gmail.com for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <cflib/ICFLibPublic.hpp>

using namespace std;

#include <cfsec/CFSecSecGroupFormByFormIdxKey.hpp>
#include <cfsec/CFSecSecGroupFormBuff.hpp>
#include <cfsec/CFSecSecGroupFormHBuff.hpp>

namespace cfsec {
	const std::string CFSecSecGroupFormByFormIdxKey::CLASS_NAME( "CFSecSecGroupFormByFormIdxKey" );
	const std::string CFSecSecGroupFormByFormIdxKey::S_VALUE( "value" );
	const std::string CFSecSecGroupFormByFormIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecSecGroupFormByFormIdxKey::CFSecSecGroupFormByFormIdxKey() {
		requiredClusterId = cfsec::CFSecSecGroupFormBuff::CLUSTERID_INIT_VALUE;
		requiredSecFormId = cfsec::CFSecSecGroupFormBuff::SECFORMID_INIT_VALUE;
	}

	CFSecSecGroupFormByFormIdxKey::CFSecSecGroupFormByFormIdxKey( const CFSecSecGroupFormByFormIdxKey& src ) {
		requiredClusterId = cfsec::CFSecSecGroupFormBuff::CLUSTERID_INIT_VALUE;
		requiredSecFormId = cfsec::CFSecSecGroupFormBuff::SECFORMID_INIT_VALUE;
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecFormId( src.getRequiredSecFormId() );
	}

	CFSecSecGroupFormByFormIdxKey::~CFSecSecGroupFormByFormIdxKey() {
	}

	const int64_t CFSecSecGroupFormByFormIdxKey::getRequiredClusterId() const {
		return( requiredClusterId );
	}

	const int64_t* CFSecSecGroupFormByFormIdxKey::getRequiredClusterIdReference() const {
		return( &requiredClusterId );
	}

	void CFSecSecGroupFormByFormIdxKey::setRequiredClusterId( const int64_t value ) {
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

	const int32_t CFSecSecGroupFormByFormIdxKey::getRequiredSecFormId() const {
		return( requiredSecFormId );
	}

	const int32_t* CFSecSecGroupFormByFormIdxKey::getRequiredSecFormIdReference() const {
		return( &requiredSecFormId );
	}

	void CFSecSecGroupFormByFormIdxKey::setRequiredSecFormId( const int32_t value ) {
		static const std::string S_ProcName( "setRequiredSecFormId" );
		if( value < cfsec::CFSecSecGroupFormBuff::SECFORMID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecSecGroupFormBuff::SECFORMID_MIN_VALUE );
		}
		requiredSecFormId = value;
	}

	size_t CFSecSecGroupFormByFormIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredClusterId() );
		hashCode = hashCode + getRequiredSecFormId();
		return( hashCode );
	}

	std::string CFSecSecGroupFormByFormIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecGroupFormByFormIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecFormId( "SecFormId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecFormId, getRequiredSecFormId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecSecGroupFormByFormIdxKey::operator <( const CFSecSecGroupFormByFormIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGroupFormByFormIdxKey::operator <( const CFSecSecGroupFormHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGroupFormByFormIdxKey::operator <( const CFSecSecGroupFormBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGroupFormByFormIdxKey::operator <=( const CFSecSecGroupFormByFormIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGroupFormByFormIdxKey::operator <=( const CFSecSecGroupFormHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGroupFormByFormIdxKey::operator <=( const CFSecSecGroupFormBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGroupFormByFormIdxKey::operator ==( const CFSecSecGroupFormByFormIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGroupFormByFormIdxKey::operator ==( const CFSecSecGroupFormHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGroupFormByFormIdxKey::operator ==( const CFSecSecGroupFormBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGroupFormByFormIdxKey::operator !=( const CFSecSecGroupFormByFormIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGroupFormByFormIdxKey::operator !=( const CFSecSecGroupFormHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGroupFormByFormIdxKey::operator !=( const CFSecSecGroupFormBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGroupFormByFormIdxKey::operator >=( const CFSecSecGroupFormByFormIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGroupFormByFormIdxKey::operator >=( const CFSecSecGroupFormHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGroupFormByFormIdxKey::operator >=( const CFSecSecGroupFormBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSecGroupFormByFormIdxKey::operator >( const CFSecSecGroupFormByFormIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGroupFormByFormIdxKey::operator >( const CFSecSecGroupFormHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGroupFormByFormIdxKey::operator >( const CFSecSecGroupFormBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}
	CFSecSecGroupFormByFormIdxKey CFSecSecGroupFormByFormIdxKey::operator =( cfsec::CFSecSecGroupFormByFormIdxKey& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecFormId( src.getRequiredSecFormId() );
		return( *this );
	}

	CFSecSecGroupFormByFormIdxKey CFSecSecGroupFormByFormIdxKey::operator =( cfsec::CFSecSecGroupFormBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecFormId( src.getRequiredSecFormId() );
		return( *this );
	}

	CFSecSecGroupFormByFormIdxKey CFSecSecGroupFormByFormIdxKey::operator =( cfsec::CFSecSecGroupFormHBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecFormId( src.getRequiredSecFormId() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecSecGroupFormByFormIdxKey& lhs, const cfsec::CFSecSecGroupFormByFormIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecGroupFormByFormIdxKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSecGroupFormByFormIdxKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSecGroupFormByFormIdxKey& lhs, const cfsec::CFSecSecGroupFormByFormIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecGroupFormByFormIdxKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSecGroupFormByFormIdxKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGroupFormByFormIdxKey& lhs, const cfsec::CFSecSecGroupFormByFormIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGroupFormByFormIdxKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGroupFormByFormIdxKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSecGroupFormByFormIdxKey& lhs, const cfsec::CFSecSecGroupFormByFormIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecGroupFormByFormIdxKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecGroupFormByFormIdxKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSecGroupFormByFormIdxKey& lhs, const cfsec::CFSecSecGroupFormByFormIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecGroupFormByFormIdxKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSecGroupFormByFormIdxKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSecGroupFormByFormIdxKey& lhs, const cfsec::CFSecSecGroupFormByFormIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecGroupFormByFormIdxKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSecGroupFormByFormIdxKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecFormId() < rhs.getRequiredSecFormId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecFormId() > rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}
}

