// Description: C++18 implementation for a SecGroupForm by UFormIdx index key object.

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

#include <cfsec/CFSecSecGroupFormByUFormIdxKey.hpp>
#include <cfsec/CFSecSecGroupFormBuff.hpp>
#include <cfsec/CFSecSecGroupFormHBuff.hpp>

namespace cfsec {
	const std::string CFSecSecGroupFormByUFormIdxKey::CLASS_NAME( "CFSecSecGroupFormByUFormIdxKey" );
	const std::string CFSecSecGroupFormByUFormIdxKey::S_VALUE( "value" );
	const std::string CFSecSecGroupFormByUFormIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecSecGroupFormByUFormIdxKey::CFSecSecGroupFormByUFormIdxKey() {
		requiredClusterId = cfsec::CFSecSecGroupFormBuff::CLUSTERID_INIT_VALUE;
		requiredSecGroupId = cfsec::CFSecSecGroupFormBuff::SECGROUPID_INIT_VALUE;
		requiredSecFormId = cfsec::CFSecSecGroupFormBuff::SECFORMID_INIT_VALUE;
	}

	CFSecSecGroupFormByUFormIdxKey::CFSecSecGroupFormByUFormIdxKey( const CFSecSecGroupFormByUFormIdxKey& src ) {
		requiredClusterId = cfsec::CFSecSecGroupFormBuff::CLUSTERID_INIT_VALUE;
		requiredSecGroupId = cfsec::CFSecSecGroupFormBuff::SECGROUPID_INIT_VALUE;
		requiredSecFormId = cfsec::CFSecSecGroupFormBuff::SECFORMID_INIT_VALUE;
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecGroupId( src.getRequiredSecGroupId() );
		setRequiredSecFormId( src.getRequiredSecFormId() );
	}

	CFSecSecGroupFormByUFormIdxKey::~CFSecSecGroupFormByUFormIdxKey() {
	}

	const int64_t CFSecSecGroupFormByUFormIdxKey::getRequiredClusterId() const {
		return( requiredClusterId );
	}

	const int64_t* CFSecSecGroupFormByUFormIdxKey::getRequiredClusterIdReference() const {
		return( &requiredClusterId );
	}

	void CFSecSecGroupFormByUFormIdxKey::setRequiredClusterId( const int64_t value ) {
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

	const int32_t CFSecSecGroupFormByUFormIdxKey::getRequiredSecGroupId() const {
		return( requiredSecGroupId );
	}

	const int32_t* CFSecSecGroupFormByUFormIdxKey::getRequiredSecGroupIdReference() const {
		return( &requiredSecGroupId );
	}

	void CFSecSecGroupFormByUFormIdxKey::setRequiredSecGroupId( const int32_t value ) {
		static const std::string S_ProcName( "setRequiredSecGroupId" );
		if( value < cfsec::CFSecSecGroupFormBuff::SECGROUPID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecSecGroupFormBuff::SECGROUPID_MIN_VALUE );
		}
		requiredSecGroupId = value;
	}

	const int32_t CFSecSecGroupFormByUFormIdxKey::getRequiredSecFormId() const {
		return( requiredSecFormId );
	}

	const int32_t* CFSecSecGroupFormByUFormIdxKey::getRequiredSecFormIdReference() const {
		return( &requiredSecFormId );
	}

	void CFSecSecGroupFormByUFormIdxKey::setRequiredSecFormId( const int32_t value ) {
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

	size_t CFSecSecGroupFormByUFormIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredClusterId() );
		hashCode = hashCode + getRequiredSecGroupId();
		hashCode = hashCode + getRequiredSecFormId();
		return( hashCode );
	}

	std::string CFSecSecGroupFormByUFormIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecGroupFormByUFormIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecGroupId( "SecGroupId" );
		static const std::string S_SecFormId( "SecFormId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecGroupId, getRequiredSecGroupId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecFormId, getRequiredSecFormId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecSecGroupFormByUFormIdxKey::operator <( const CFSecSecGroupFormByUFormIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
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

	bool CFSecSecGroupFormByUFormIdxKey::operator <( const CFSecSecGroupFormHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
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

	bool CFSecSecGroupFormByUFormIdxKey::operator <( const CFSecSecGroupFormBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
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

	bool CFSecSecGroupFormByUFormIdxKey::operator <=( const CFSecSecGroupFormByUFormIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
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

	bool CFSecSecGroupFormByUFormIdxKey::operator <=( const CFSecSecGroupFormHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
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

	bool CFSecSecGroupFormByUFormIdxKey::operator <=( const CFSecSecGroupFormBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
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

	bool CFSecSecGroupFormByUFormIdxKey::operator ==( const CFSecSecGroupFormByUFormIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		if( getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGroupFormByUFormIdxKey::operator ==( const CFSecSecGroupFormHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		if( getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGroupFormByUFormIdxKey::operator ==( const CFSecSecGroupFormBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		if( getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSecGroupFormByUFormIdxKey::operator !=( const CFSecSecGroupFormByUFormIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGroupFormByUFormIdxKey::operator !=( const CFSecSecGroupFormHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGroupFormByUFormIdxKey::operator !=( const CFSecSecGroupFormBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSecGroupFormByUFormIdxKey::operator >=( const CFSecSecGroupFormByUFormIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
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

	bool CFSecSecGroupFormByUFormIdxKey::operator >=( const CFSecSecGroupFormHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
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

	bool CFSecSecGroupFormByUFormIdxKey::operator >=( const CFSecSecGroupFormBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
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

	bool CFSecSecGroupFormByUFormIdxKey::operator >( const CFSecSecGroupFormByUFormIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
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

	bool CFSecSecGroupFormByUFormIdxKey::operator >( const CFSecSecGroupFormHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
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

	bool CFSecSecGroupFormByUFormIdxKey::operator >( const CFSecSecGroupFormBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
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
	CFSecSecGroupFormByUFormIdxKey CFSecSecGroupFormByUFormIdxKey::operator =( cfsec::CFSecSecGroupFormByUFormIdxKey& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecGroupId( src.getRequiredSecGroupId() );
		setRequiredSecFormId( src.getRequiredSecFormId() );
		return( *this );
	}

	CFSecSecGroupFormByUFormIdxKey CFSecSecGroupFormByUFormIdxKey::operator =( cfsec::CFSecSecGroupFormBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecGroupId( src.getRequiredSecGroupId() );
		setRequiredSecFormId( src.getRequiredSecFormId() );
		return( *this );
	}

	CFSecSecGroupFormByUFormIdxKey CFSecSecGroupFormByUFormIdxKey::operator =( cfsec::CFSecSecGroupFormHBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		setRequiredSecGroupId( src.getRequiredSecGroupId() );
		setRequiredSecFormId( src.getRequiredSecFormId() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecSecGroupFormByUFormIdxKey& lhs, const cfsec::CFSecSecGroupFormByUFormIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
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

	bool operator <(const  cfsec::CFSecSecGroupFormByUFormIdxKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
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

	bool operator <(const  cfsec::CFSecSecGroupFormByUFormIdxKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
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

	bool operator <=(const  cfsec::CFSecSecGroupFormByUFormIdxKey& lhs, const cfsec::CFSecSecGroupFormByUFormIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
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

	bool operator <=(const  cfsec::CFSecSecGroupFormByUFormIdxKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
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

	bool operator <=(const  cfsec::CFSecSecGroupFormByUFormIdxKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
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

	bool operator ==(const  cfsec::CFSecSecGroupFormByUFormIdxKey& lhs, const cfsec::CFSecSecGroupFormByUFormIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		if( lhs.getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGroupFormByUFormIdxKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		if( lhs.getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSecGroupFormByUFormIdxKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		if( lhs.getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		if( lhs.getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSecGroupFormByUFormIdxKey& lhs, const cfsec::CFSecSecGroupFormByUFormIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( lhs.getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecGroupFormByUFormIdxKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( lhs.getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSecGroupFormByUFormIdxKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() != rhs.getRequiredSecGroupId() ) {
			return( true );
		}
		if( lhs.getRequiredSecFormId() != rhs.getRequiredSecFormId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSecGroupFormByUFormIdxKey& lhs, const cfsec::CFSecSecGroupFormByUFormIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
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

	bool operator >=(const  cfsec::CFSecSecGroupFormByUFormIdxKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
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

	bool operator >=(const  cfsec::CFSecSecGroupFormByUFormIdxKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
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

	bool operator >(const  cfsec::CFSecSecGroupFormByUFormIdxKey& lhs, const cfsec::CFSecSecGroupFormByUFormIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
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

	bool operator >(const  cfsec::CFSecSecGroupFormByUFormIdxKey& lhs, const cfsec::CFSecSecGroupFormHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
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

	bool operator >(const  cfsec::CFSecSecGroupFormByUFormIdxKey& lhs, const cfsec::CFSecSecGroupFormBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		if( lhs.getRequiredSecGroupId() < rhs.getRequiredSecGroupId() ) {
			return( false );
		}
		else if( lhs.getRequiredSecGroupId() > rhs.getRequiredSecGroupId() ) {
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

