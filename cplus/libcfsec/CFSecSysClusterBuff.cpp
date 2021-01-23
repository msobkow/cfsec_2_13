// Description: C++18 implementation for a SysCluster buffer object.

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

#include <cfsec/ICFSecPublic.hpp>

#include <cfsec/CFSecSysClusterByClusterIdxKey.hpp>
#include <cfsec/CFSecSchema.hpp>

namespace cfsec {

	const std::string CFSecSysClusterBuff::S_VALUE( "value" );
	const std::string CFSecSysClusterBuff::S_VALUE_LENGTH( "value.length()" );

	const std::string CFSecSysClusterBuff::GENDEFNAME( "SysCluster" );
	const classcode_t CFSecSysClusterBuff::CLASS_CODE = 0xa014L;
	const std::string CFSecSysClusterBuff::CLASS_NAME( "CFSecSysClusterBuff" );
		const std::string CFSecSysClusterBuff::COLNAME_SINGLETONID( "SingletonId" );
		const std::string CFSecSysClusterBuff::COLNAME_CLUSTERID( "ClusterId" );
	const int CFSecSysClusterBuff::SINGLETONID_INIT_VALUE = 1L;
	const int64_t CFSecSysClusterBuff::CLUSTERID_INIT_VALUE = 0LL;
	const int CFSecSysClusterBuff::SINGLETONID_MIN_VALUE = 1L;
	const int64_t CFSecSysClusterBuff::CLUSTERID_MIN_VALUE = 0LL;
	const int CFSecSysClusterBuff::SINGLETONID_MAX_VALUE = 1L;

	CFSecSysClusterBuff::CFSecSysClusterBuff()
	: cflib::ICFLibCloneableObj()
	{
		requiredRevision = 1;
		requiredSingletonId = cfsec::CFSecSysClusterBuff::SINGLETONID_INIT_VALUE;
		requiredClusterId = cfsec::CFSecSysClusterBuff::CLUSTERID_INIT_VALUE;
	}

	CFSecSysClusterBuff::CFSecSysClusterBuff( const CFSecSysClusterBuff& src )
	: cflib::ICFLibCloneableObj()
	{
		requiredRevision = 1;
		requiredSingletonId = cfsec::CFSecSysClusterBuff::SINGLETONID_INIT_VALUE;
		requiredClusterId = cfsec::CFSecSysClusterBuff::CLUSTERID_INIT_VALUE;
		setRequiredSingletonId( src.getRequiredSingletonId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredClusterId( src.getRequiredClusterId() );
	}

	CFSecSysClusterBuff::~CFSecSysClusterBuff() {
	}

	cflib::ICFLibCloneableObj* CFSecSysClusterBuff::clone() {
		CFSecSysClusterBuff* copy = new CFSecSysClusterBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const std::string& CFSecSysClusterBuff::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecSysClusterBuff::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecSysClusterBuff::implementsClassCode( const classcode_t argClassCode ) {
		if( argClassCode == CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	const int32_t CFSecSysClusterBuff::getRequiredSingletonId() const {
		return( requiredSingletonId );
	}

	const int32_t* CFSecSysClusterBuff::getRequiredSingletonIdReference() const {
		return( &requiredSingletonId );
	}

	void CFSecSysClusterBuff::setRequiredSingletonId( const int32_t value ) {
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

	const int64_t CFSecSysClusterBuff::getRequiredClusterId() const {
		return( requiredClusterId );
	}

	const int64_t* CFSecSysClusterBuff::getRequiredClusterIdReference() const {
		return( &requiredClusterId );
	}

	void CFSecSysClusterBuff::setRequiredClusterId( const int64_t value ) {
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

	int32_t CFSecSysClusterBuff::getRequiredRevision() const {
		return( requiredRevision );
	}

	void CFSecSysClusterBuff::setRequiredRevision( int32_t value ) {
		requiredRevision = value;
	}

	size_t CFSecSysClusterBuff::hashCode() const {
		size_t hashCode = 0L;
		hashCode = hashCode + getRequiredSingletonId();
		hashCode = hashCode + (int)( getRequiredClusterId() );
		return( hashCode );
	}

	CFSecSysClusterBuff CFSecSysClusterBuff::operator =( cfsec::CFSecSysClusterBuff& src ) {
		setRequiredSingletonId( src.getRequiredSingletonId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredClusterId( src.getRequiredClusterId() );
		return( *this );
	}

	CFSecSysClusterBuff CFSecSysClusterBuff::operator =( cfsec::CFSecSysClusterHBuff& src ) {
		setRequiredSingletonId( src.getRequiredSingletonId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredClusterId( src.getRequiredClusterId() );
		return( *this );
	}

	bool CFSecSysClusterBuff::operator <( const CFSecSysClusterByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterBuff::operator <( const CFSecSysClusterPKey& rhs ) {
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterBuff::operator <( const CFSecSysClusterHPKey& rhs ) {
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterBuff::operator <( const CFSecSysClusterHBuff& rhs ) {
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterBuff::operator <( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterBuff::operator <=( const CFSecSysClusterByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterBuff::operator <=( const CFSecSysClusterPKey& rhs ) {
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterBuff::operator <=( const CFSecSysClusterHPKey& rhs ) {
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterBuff::operator <=( const CFSecSysClusterHBuff& rhs ) {
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterBuff::operator <=( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterBuff::operator ==( const CFSecSysClusterByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSysClusterBuff::operator ==( const CFSecSysClusterPKey& rhs ) {
		if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSysClusterBuff::operator ==( const CFSecSysClusterHPKey& rhs ) {
		if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSysClusterBuff::operator ==( const CFSecSysClusterHBuff& rhs ) {
		if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( false );
		}
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSysClusterBuff::operator ==( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( false );
		}
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecSysClusterBuff::operator !=( const CFSecSysClusterByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterBuff::operator !=( const CFSecSysClusterPKey& rhs ) {
		if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterBuff::operator !=( const CFSecSysClusterHPKey& rhs ) {
		if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterBuff::operator !=( const CFSecSysClusterHBuff& rhs ) {
		if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterBuff::operator !=( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		if( getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterBuff::operator >=( const CFSecSysClusterByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterBuff::operator >=( const CFSecSysClusterPKey& rhs ) {
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterBuff::operator >=( const CFSecSysClusterHPKey& rhs ) {
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterBuff::operator >=( const CFSecSysClusterHBuff& rhs ) {
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterBuff::operator >=( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecSysClusterBuff::operator >( const CFSecSysClusterByClusterIdxKey& rhs ) {
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterBuff::operator >( const CFSecSysClusterPKey& rhs ) {
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterBuff::operator >( const CFSecSysClusterHPKey& rhs ) {
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterBuff::operator >( const CFSecSysClusterHBuff& rhs ) {
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecSysClusterBuff::operator >( const CFSecSysClusterBuff& rhs ) {
		if( getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		if( getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	std::string CFSecSysClusterBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSysClusterBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_SingletonId( "SingletonId" );
		static const std::string S_ClusterId( "ClusterId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SingletonId, getRequiredSingletonId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, getRequiredClusterId() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterPKey& rhs ) {
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHPKey& rhs ) {
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterPKey& rhs ) {
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHPKey& rhs ) {
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( true );
		}
		if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterPKey& rhs ) {
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHPKey& rhs ) {
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( false );
		}
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( false );
		}
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterPKey& rhs ) {
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHPKey& rhs ) {
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredSingletonId() != rhs.getRequiredSingletonId() ) {
			return( true );
		}
		if( lhs.getRequiredClusterId() != rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterPKey& rhs ) {
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHPKey& rhs ) {
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterByClusterIdxKey& rhs ) {
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterPKey& rhs ) {
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHPKey& rhs ) {
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterHBuff& rhs ) {
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecSysClusterBuff& lhs, const cfsec::CFSecSysClusterBuff& rhs ) {
		if( lhs.getRequiredSingletonId() < rhs.getRequiredSingletonId() ) {
			return( false );
		}
		else if( lhs.getRequiredSingletonId() > rhs.getRequiredSingletonId() ) {
			return( true );
		}
		if( lhs.getRequiredClusterId() < rhs.getRequiredClusterId() ) {
			return( false );
		}
		else if( lhs.getRequiredClusterId() > rhs.getRequiredClusterId() ) {
			return( true );
		}
		return( false );
	}
}

