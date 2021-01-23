// Description: C++18 implementation for a ISOCtryCcy by CcyIdx index key object.

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

#include <cfsec/CFSecISOCtryCcyByCcyIdxKey.hpp>
#include <cfsec/CFSecISOCtryCcyBuff.hpp>
#include <cfsec/CFSecISOCtryCcyHBuff.hpp>

namespace cfsec {
	const std::string CFSecISOCtryCcyByCcyIdxKey::CLASS_NAME( "CFSecISOCtryCcyByCcyIdxKey" );
	const std::string CFSecISOCtryCcyByCcyIdxKey::S_VALUE( "value" );
	const std::string CFSecISOCtryCcyByCcyIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecISOCtryCcyByCcyIdxKey::CFSecISOCtryCcyByCcyIdxKey() {
		requiredISOCcyId = cfsec::CFSecISOCtryCcyBuff::ISOCCYID_INIT_VALUE;
	}

	CFSecISOCtryCcyByCcyIdxKey::CFSecISOCtryCcyByCcyIdxKey( const CFSecISOCtryCcyByCcyIdxKey& src ) {
		requiredISOCcyId = cfsec::CFSecISOCtryCcyBuff::ISOCCYID_INIT_VALUE;
		setRequiredISOCcyId( src.getRequiredISOCcyId() );
	}

	CFSecISOCtryCcyByCcyIdxKey::~CFSecISOCtryCcyByCcyIdxKey() {
	}

	const int16_t CFSecISOCtryCcyByCcyIdxKey::getRequiredISOCcyId() const {
		return( requiredISOCcyId );
	}

	const int16_t* CFSecISOCtryCcyByCcyIdxKey::getRequiredISOCcyIdReference() const {
		return( &requiredISOCcyId );
	}

	void CFSecISOCtryCcyByCcyIdxKey::setRequiredISOCcyId( const int16_t value ) {
		static const std::string S_ProcName( "setRequiredISOCcyId" );
		if( value < cfsec::CFSecISOCtryCcyBuff::ISOCCYID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOCtryCcyBuff::ISOCCYID_MIN_VALUE );
		}
		requiredISOCcyId = value;
	}

	size_t CFSecISOCtryCcyByCcyIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOCcyId();
		return( hashCode );
	}

	std::string CFSecISOCtryCcyByCcyIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOCtryCcyByCcyIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ISOCcyId( "ISOCcyId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCcyId, getRequiredISOCcyId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecISOCtryCcyByCcyIdxKey::operator <( const CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyByCcyIdxKey::operator <( const CFSecISOCtryCcyHBuff& rhs ) {
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyByCcyIdxKey::operator <( const CFSecISOCtryCcyBuff& rhs ) {
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyByCcyIdxKey::operator <=( const CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyByCcyIdxKey::operator <=( const CFSecISOCtryCcyHBuff& rhs ) {
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyByCcyIdxKey::operator <=( const CFSecISOCtryCcyBuff& rhs ) {
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyByCcyIdxKey::operator ==( const CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryCcyByCcyIdxKey::operator ==( const CFSecISOCtryCcyHBuff& rhs ) {
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryCcyByCcyIdxKey::operator ==( const CFSecISOCtryCcyBuff& rhs ) {
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryCcyByCcyIdxKey::operator !=( const CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyByCcyIdxKey::operator !=( const CFSecISOCtryCcyHBuff& rhs ) {
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyByCcyIdxKey::operator !=( const CFSecISOCtryCcyBuff& rhs ) {
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyByCcyIdxKey::operator >=( const CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyByCcyIdxKey::operator >=( const CFSecISOCtryCcyHBuff& rhs ) {
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyByCcyIdxKey::operator >=( const CFSecISOCtryCcyBuff& rhs ) {
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyByCcyIdxKey::operator >( const CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyByCcyIdxKey::operator >( const CFSecISOCtryCcyHBuff& rhs ) {
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyByCcyIdxKey::operator >( const CFSecISOCtryCcyBuff& rhs ) {
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}
	CFSecISOCtryCcyByCcyIdxKey CFSecISOCtryCcyByCcyIdxKey::operator =( cfsec::CFSecISOCtryCcyByCcyIdxKey& src ) {
		setRequiredISOCcyId( src.getRequiredISOCcyId() );
		return( *this );
	}

	CFSecISOCtryCcyByCcyIdxKey CFSecISOCtryCcyByCcyIdxKey::operator =( cfsec::CFSecISOCtryCcyBuff& src ) {
		setRequiredISOCcyId( src.getRequiredISOCcyId() );
		return( *this );
	}

	CFSecISOCtryCcyByCcyIdxKey CFSecISOCtryCcyByCcyIdxKey::operator =( cfsec::CFSecISOCtryCcyHBuff& src ) {
		setRequiredISOCcyId( src.getRequiredISOCcyId() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyByCcyIdxKey& rhs ) {
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryCcyByCcyIdxKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}
}

