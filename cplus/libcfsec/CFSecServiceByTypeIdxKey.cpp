// Description: C++18 implementation for a Service by TypeIdx index key object.

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

#include <cfsec/CFSecServiceByTypeIdxKey.hpp>
#include <cfsec/CFSecServiceBuff.hpp>
#include <cfsec/CFSecServiceHBuff.hpp>

namespace cfsec {
	const std::string CFSecServiceByTypeIdxKey::CLASS_NAME( "CFSecServiceByTypeIdxKey" );
	const std::string CFSecServiceByTypeIdxKey::S_VALUE( "value" );
	const std::string CFSecServiceByTypeIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecServiceByTypeIdxKey::CFSecServiceByTypeIdxKey() {
		requiredServiceTypeId = cfsec::CFSecServiceBuff::SERVICETYPEID_INIT_VALUE;
	}

	CFSecServiceByTypeIdxKey::CFSecServiceByTypeIdxKey( const CFSecServiceByTypeIdxKey& src ) {
		requiredServiceTypeId = cfsec::CFSecServiceBuff::SERVICETYPEID_INIT_VALUE;
		setRequiredServiceTypeId( src.getRequiredServiceTypeId() );
	}

	CFSecServiceByTypeIdxKey::~CFSecServiceByTypeIdxKey() {
	}

	const int32_t CFSecServiceByTypeIdxKey::getRequiredServiceTypeId() const {
		return( requiredServiceTypeId );
	}

	const int32_t* CFSecServiceByTypeIdxKey::getRequiredServiceTypeIdReference() const {
		return( &requiredServiceTypeId );
	}

	void CFSecServiceByTypeIdxKey::setRequiredServiceTypeId( const int32_t value ) {
		static const std::string S_ProcName( "setRequiredServiceTypeId" );
		if( value < cfsec::CFSecServiceBuff::SERVICETYPEID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecServiceBuff::SERVICETYPEID_MIN_VALUE );
		}
		requiredServiceTypeId = value;
	}

	size_t CFSecServiceByTypeIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + getRequiredServiceTypeId();
		return( hashCode );
	}

	std::string CFSecServiceByTypeIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecServiceByTypeIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ServiceTypeId( "ServiceTypeId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_ServiceTypeId, getRequiredServiceTypeId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecServiceByTypeIdxKey::operator <( const CFSecServiceByTypeIdxKey& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceByTypeIdxKey::operator <( const CFSecServiceHBuff& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceByTypeIdxKey::operator <( const CFSecServiceBuff& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceByTypeIdxKey::operator <=( const CFSecServiceByTypeIdxKey& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceByTypeIdxKey::operator <=( const CFSecServiceHBuff& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceByTypeIdxKey::operator <=( const CFSecServiceBuff& rhs ) {
		if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceByTypeIdxKey::operator ==( const CFSecServiceByTypeIdxKey& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceByTypeIdxKey::operator ==( const CFSecServiceHBuff& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceByTypeIdxKey::operator ==( const CFSecServiceBuff& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecServiceByTypeIdxKey::operator !=( const CFSecServiceByTypeIdxKey& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceByTypeIdxKey::operator !=( const CFSecServiceHBuff& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceByTypeIdxKey::operator !=( const CFSecServiceBuff& rhs ) {
		if( getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceByTypeIdxKey::operator >=( const CFSecServiceByTypeIdxKey& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceByTypeIdxKey::operator >=( const CFSecServiceHBuff& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceByTypeIdxKey::operator >=( const CFSecServiceBuff& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecServiceByTypeIdxKey::operator >( const CFSecServiceByTypeIdxKey& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceByTypeIdxKey::operator >( const CFSecServiceHBuff& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecServiceByTypeIdxKey::operator >( const CFSecServiceBuff& rhs ) {
		if( getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}
	CFSecServiceByTypeIdxKey CFSecServiceByTypeIdxKey::operator =( cfsec::CFSecServiceByTypeIdxKey& src ) {
		setRequiredServiceTypeId( src.getRequiredServiceTypeId() );
		return( *this );
	}

	CFSecServiceByTypeIdxKey CFSecServiceByTypeIdxKey::operator =( cfsec::CFSecServiceBuff& src ) {
		setRequiredServiceTypeId( src.getRequiredServiceTypeId() );
		return( *this );
	}

	CFSecServiceByTypeIdxKey CFSecServiceByTypeIdxKey::operator =( cfsec::CFSecServiceHBuff& src ) {
		setRequiredServiceTypeId( src.getRequiredServiceTypeId() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() != rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceByTypeIdxKey& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceHBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecServiceByTypeIdxKey& lhs, const cfsec::CFSecServiceBuff& rhs ) {
		if( lhs.getRequiredServiceTypeId() < rhs.getRequiredServiceTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredServiceTypeId() > rhs.getRequiredServiceTypeId() ) {
			return( true );
		}
		return( false );
	}
}

