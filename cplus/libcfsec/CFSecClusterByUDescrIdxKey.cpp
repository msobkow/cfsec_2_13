// Description: C++18 implementation for a Cluster by UDescrIdx index key object.

/*
 *	org.msscf.msscf.CFSec
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <cflib/ICFLibPublic.hpp>

using namespace std;

#include <cfsec/CFSecClusterByUDescrIdxKey.hpp>
#include <cfsec/CFSecClusterBuff.hpp>
#include <cfsec/CFSecClusterHBuff.hpp>

namespace cfsec {
	const std::string CFSecClusterByUDescrIdxKey::CLASS_NAME( "CFSecClusterByUDescrIdxKey" );
	const std::string CFSecClusterByUDescrIdxKey::S_VALUE( "value" );
	const std::string CFSecClusterByUDescrIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecClusterByUDescrIdxKey::CFSecClusterByUDescrIdxKey() {
		requiredDescription = new std::string( cfsec::CFSecClusterBuff::DESCRIPTION_INIT_VALUE );
	}

	CFSecClusterByUDescrIdxKey::CFSecClusterByUDescrIdxKey( const CFSecClusterByUDescrIdxKey& src ) {
		requiredDescription = new std::string( cfsec::CFSecClusterBuff::DESCRIPTION_INIT_VALUE );
		setRequiredDescription( src.getRequiredDescription() );
	}

	CFSecClusterByUDescrIdxKey::~CFSecClusterByUDescrIdxKey() {
		if( requiredDescription != NULL ) {
			delete requiredDescription;
			requiredDescription = NULL;
		}
	}

	const std::string& CFSecClusterByUDescrIdxKey::getRequiredDescription() const {
		return( *requiredDescription );
	}

	const std::string* CFSecClusterByUDescrIdxKey::getRequiredDescriptionReference() const {
		return( requiredDescription );
	}

	void CFSecClusterByUDescrIdxKey::setRequiredDescription( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredDescription" );
		if( value.length() > CFSecClusterBuff::DESCRIPTION_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFSecClusterBuff::DESCRIPTION_MAX_LEN );
		}
		if( requiredDescription != NULL ) {
			delete requiredDescription;
			requiredDescription = NULL;
		}
		requiredDescription = new std::string( value );
	}

	size_t CFSecClusterByUDescrIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + cflib::CFLib::hash( getRequiredDescription() );
		return( hashCode );
	}

	std::string CFSecClusterByUDescrIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecClusterByUDescrIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Description( "Description" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, getRequiredDescription() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecClusterByUDescrIdxKey::operator <( const CFSecClusterByUDescrIdxKey& rhs ) {
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDescrIdxKey::operator <( const CFSecClusterHBuff& rhs ) {
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDescrIdxKey::operator <( const CFSecClusterBuff& rhs ) {
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDescrIdxKey::operator <=( const CFSecClusterByUDescrIdxKey& rhs ) {
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecClusterByUDescrIdxKey::operator <=( const CFSecClusterHBuff& rhs ) {
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecClusterByUDescrIdxKey::operator <=( const CFSecClusterBuff& rhs ) {
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecClusterByUDescrIdxKey::operator ==( const CFSecClusterByUDescrIdxKey& rhs ) {
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecClusterByUDescrIdxKey::operator ==( const CFSecClusterHBuff& rhs ) {
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecClusterByUDescrIdxKey::operator ==( const CFSecClusterBuff& rhs ) {
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecClusterByUDescrIdxKey::operator !=( const CFSecClusterByUDescrIdxKey& rhs ) {
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDescrIdxKey::operator !=( const CFSecClusterHBuff& rhs ) {
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDescrIdxKey::operator !=( const CFSecClusterBuff& rhs ) {
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDescrIdxKey::operator >=( const CFSecClusterByUDescrIdxKey& rhs ) {
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecClusterByUDescrIdxKey::operator >=( const CFSecClusterHBuff& rhs ) {
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecClusterByUDescrIdxKey::operator >=( const CFSecClusterBuff& rhs ) {
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecClusterByUDescrIdxKey::operator >( const CFSecClusterByUDescrIdxKey& rhs ) {
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDescrIdxKey::operator >( const CFSecClusterHBuff& rhs ) {
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecClusterByUDescrIdxKey::operator >( const CFSecClusterBuff& rhs ) {
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}
	CFSecClusterByUDescrIdxKey CFSecClusterByUDescrIdxKey::operator =( cfsec::CFSecClusterByUDescrIdxKey& src ) {
		setRequiredDescription( src.getRequiredDescription() );
		return( *this );
	}

	CFSecClusterByUDescrIdxKey CFSecClusterByUDescrIdxKey::operator =( cfsec::CFSecClusterBuff& src ) {
		setRequiredDescription( src.getRequiredDescription() );
		return( *this );
	}

	CFSecClusterByUDescrIdxKey CFSecClusterByUDescrIdxKey::operator =( cfsec::CFSecClusterHBuff& src ) {
		setRequiredDescription( src.getRequiredDescription() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs ) {
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs ) {
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs ) {
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs ) {
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs ) {
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs ) {
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs ) {
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs ) {
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs ) {
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs ) {
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterByUDescrIdxKey& rhs ) {
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterHBuff& rhs ) {
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecClusterByUDescrIdxKey& lhs, const cfsec::CFSecClusterBuff& rhs ) {
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		return( false );
	}
}

