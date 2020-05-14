// Description: C++18 implementation of a ISOCtryCcy primary key object.

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

#include <cfsec/CFSecISOCtryCcyPKey.hpp>
#include <cfsec/CFSecISOCtryCcyBuff.hpp>
#include <cfsec/CFSecISOCtryCcyHPKey.hpp>
#include <cfsec/CFSecISOCtryCcyHBuff.hpp>

namespace cfsec {

	const std::string CFSecISOCtryCcyPKey::CLASS_NAME( "CFSecISOCtryCcyPKey" );
	const std::string CFSecISOCtryCcyPKey::S_VALUE( "value" );
	const std::string CFSecISOCtryCcyPKey::S_VALUE_LENGTH( "value.length()" );

	CFSecISOCtryCcyPKey::CFSecISOCtryCcyPKey() {
		requiredISOCtryId = cfsec::CFSecISOCtryCcyBuff::ISOCTRYID_INIT_VALUE;
		requiredISOCcyId = cfsec::CFSecISOCtryCcyBuff::ISOCCYID_INIT_VALUE;
	}

	CFSecISOCtryCcyPKey::CFSecISOCtryCcyPKey( const CFSecISOCtryCcyPKey& src ) {
		requiredISOCtryId = cfsec::CFSecISOCtryCcyBuff::ISOCTRYID_INIT_VALUE;
		requiredISOCcyId = cfsec::CFSecISOCtryCcyBuff::ISOCCYID_INIT_VALUE;
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setRequiredISOCcyId( src.getRequiredISOCcyId() );
	}

	CFSecISOCtryCcyPKey::~CFSecISOCtryCcyPKey() {
	}

	const int16_t CFSecISOCtryCcyPKey::getRequiredISOCtryId() const {
		return( requiredISOCtryId );
	}

	const int16_t* CFSecISOCtryCcyPKey::getRequiredISOCtryIdReference() const {
		return( &requiredISOCtryId );
	}

	void CFSecISOCtryCcyPKey::setRequiredISOCtryId( const int16_t value ) {
		static const std::string S_ProcName( "setRequiredISOCtryId" );
		if( value < cfsec::CFSecISOCtryCcyBuff::ISOCTRYID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecISOCtryCcyBuff::ISOCTRYID_MIN_VALUE );
		}
		requiredISOCtryId = value;
	}

	const int16_t CFSecISOCtryCcyPKey::getRequiredISOCcyId() const {
		return( requiredISOCcyId );
	}

	const int16_t* CFSecISOCtryCcyPKey::getRequiredISOCcyIdReference() const {
		return( &requiredISOCcyId );
	}

	void CFSecISOCtryCcyPKey::setRequiredISOCcyId( const int16_t value ) {
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

	bool CFSecISOCtryCcyPKey::operator <( const CFSecISOCtryCcyHPKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyPKey::operator <( const CFSecISOCtryCcyPKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyPKey::operator <( const CFSecISOCtryCcyHBuff& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyPKey::operator <( const CFSecISOCtryCcyBuff& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyPKey::operator <=( const CFSecISOCtryCcyHPKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyPKey::operator <=( const CFSecISOCtryCcyPKey& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyPKey::operator <=( const CFSecISOCtryCcyHBuff& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyPKey::operator <=( const CFSecISOCtryCcyBuff& rhs ) {
		if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyPKey::operator ==( const CFSecISOCtryCcyHPKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryCcyPKey::operator ==( const CFSecISOCtryCcyPKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryCcyPKey::operator ==( const CFSecISOCtryCcyHBuff& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryCcyPKey::operator ==( const CFSecISOCtryCcyBuff& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool CFSecISOCtryCcyPKey::operator !=( const CFSecISOCtryCcyHPKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyPKey::operator !=( const CFSecISOCtryCcyPKey& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyPKey::operator !=( const CFSecISOCtryCcyHBuff& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyPKey::operator !=( const CFSecISOCtryCcyBuff& rhs ) {
		if( getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyPKey::operator >=( const CFSecISOCtryCcyHPKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyPKey::operator >=( const CFSecISOCtryCcyPKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyPKey::operator >=( const CFSecISOCtryCcyHBuff& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyPKey::operator >=( const CFSecISOCtryCcyBuff& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool CFSecISOCtryCcyPKey::operator >( const CFSecISOCtryCcyHPKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyPKey::operator >( const CFSecISOCtryCcyPKey& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyPKey::operator >( const CFSecISOCtryCcyHBuff& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool CFSecISOCtryCcyPKey::operator >( const CFSecISOCtryCcyBuff& rhs ) {
		if( getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	CFSecISOCtryCcyPKey CFSecISOCtryCcyPKey::operator =( cfsec::CFSecISOCtryCcyPKey& src ) {
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setRequiredISOCcyId( src.getRequiredISOCcyId() );
		return( *this );
	}

	CFSecISOCtryCcyPKey CFSecISOCtryCcyPKey::operator =( cfsec::CFSecISOCtryCcyHPKey& src ) {
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setRequiredISOCcyId( src.getRequiredISOCcyId() );
		return( *this );
	}

	CFSecISOCtryCcyPKey CFSecISOCtryCcyPKey::operator =( cfsec::CFSecISOCtryCcyBuff& src ) {
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setRequiredISOCcyId( src.getRequiredISOCcyId() );
		return( *this );
	}

	CFSecISOCtryCcyPKey CFSecISOCtryCcyPKey::operator =( cfsec::CFSecISOCtryCcyHBuff& src ) {
		setRequiredISOCtryId( src.getRequiredISOCtryId() );
		setRequiredISOCcyId( src.getRequiredISOCcyId() );
		return( *this );
	}

	size_t CFSecISOCtryCcyPKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOCtryId();
		hashCode = ( hashCode * 0x10000 ) + getRequiredISOCcyId();
		return( hashCode );
	}

	std::string CFSecISOCtryCcyPKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOCtryCcyPKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_ISOCtryId( "ISOCtryId" );
		static const std::string S_ISOCcyId( "ISOCcyId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCtryId, getRequiredISOCtryId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCcyId, getRequiredISOCcyId() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() != rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() != rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyHPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyPKey& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyHBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfsec::CFSecISOCtryCcyPKey& lhs, const cfsec::CFSecISOCtryCcyBuff& rhs ) {
		if( lhs.getRequiredISOCtryId() < rhs.getRequiredISOCtryId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCtryId() > rhs.getRequiredISOCtryId() ) {
			return( true );
		}
		if( lhs.getRequiredISOCcyId() < rhs.getRequiredISOCcyId() ) {
			return( false );
		}
		else if( lhs.getRequiredISOCcyId() > rhs.getRequiredISOCcyId() ) {
			return( true );
		}
		return( false );
	}
}

