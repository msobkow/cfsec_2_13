// Description: C++18 implementation for a SysCluster by ClusterIdx index key object.

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

#include <cfsec/CFSecSysClusterByClusterIdxKey.hpp>
#include <cfsec/CFSecSysClusterBuff.hpp>
#include <cfsec/CFSecSysClusterHBuff.hpp>

namespace cfsec {
	const std::string CFSecSysClusterByClusterIdxKey::CLASS_NAME( "CFSecSysClusterByClusterIdxKey" );
	const std::string CFSecSysClusterByClusterIdxKey::S_VALUE( "value" );
	const std::string CFSecSysClusterByClusterIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFSecSysClusterByClusterIdxKey::CFSecSysClusterByClusterIdxKey() {
		requiredClusterId = cfsec::CFSecSysClusterBuff::CLUSTERID_INIT_VALUE;
	}

	CFSecSysClusterByClusterIdxKey::CFSecSysClusterByClusterIdxKey( const CFSecSysClusterByClusterIdxKey& src ) {
		requiredClusterId = cfsec::CFSecSysClusterBuff::CLUSTERID_INIT_VALUE;
		setRequiredClusterId( src.getRequiredClusterId() );
	}

	CFSecSysClusterByClusterIdxKey::~CFSecSysClusterByClusterIdxKey() {
	}

	const int64_t CFSecSysClusterByClusterIdxKey::getRequiredClusterId() const {
		return( requiredClusterId );
	}

	const int64_t* CFSecSysClusterByClusterIdxKey::getRequiredClusterIdReference() const {
		return( &requiredClusterId );
	}

	void CFSecSysClusterByClusterIdxKey::setRequiredClusterId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredClusterId" );
		if( value < cfsec::CFSecSysClusterBuff::CLUSTERID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecSysClusterBuff::CLUSTERID_MIN_VALUE );
		}
		requiredClusterId = value;
	}

	size_t CFSecSysClusterByClusterIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredClusterId() );
		return( hashCode );
	}

	std::string CFSecSysClusterByClusterIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSysClusterByClusterIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ClusterId( "ClusterId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, getRequiredClusterId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFSecSysClusterByClusterIdxKey::operator <( const CFSecSysClusterByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterByClusterIdxKey::operator <( const CFSecSysClusterHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterByClusterIdxKey::operator <( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterByClusterIdxKey::operator <=( const CFSecSysClusterByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterByClusterIdxKey::operator <=( const CFSecSysClusterHBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterByClusterIdxKey::operator <=( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterByClusterIdxKey::operator ==( const CFSecSysClusterByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSysClusterByClusterIdxKey::operator ==( const CFSecSysClusterHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSysClusterByClusterIdxKey::operator ==( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSysClusterByClusterIdxKey::operator !=( const CFSecSysClusterByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterByClusterIdxKey::operator !=( const CFSecSysClusterHBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterByClusterIdxKey::operator !=( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterByClusterIdxKey::operator >=( const CFSecSysClusterByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterByClusterIdxKey::operator >=( const CFSecSysClusterHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterByClusterIdxKey::operator >=( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterByClusterIdxKey::operator >( const CFSecSysClusterByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterByClusterIdxKey::operator >( const CFSecSysClusterHBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterByClusterIdxKey::operator >( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}
	CFSecSysClusterByClusterIdxKey CFSecSysClusterByClusterIdxKey::operator =( cfsec::CFSecSysClusterByClusterIdxKey& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		return( *this );
	}

	CFSecSysClusterByClusterIdxKey CFSecSysClusterByClusterIdxKey::operator =( cfsec::CFSecSysClusterBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		return( *this );
	}

	CFSecSysClusterByClusterIdxKey CFSecSysClusterByClusterIdxKey::operator =( cfsec::CFSecSysClusterHBuff& src ) {
		setRequiredClusterId( src.getRequiredClusterId() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSysClusterByClusterIdxKey& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}
}

