// Description: C++18 edit object instance implementation for CFSec ISOCtryLang.

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

#include <cfsec/ICFSecPublic.hpp>
#include <cfsecobj/ICFSecObjPublic.hpp>
#include <cfsecobj/CFSecISOCtryLangObj.hpp>
#include <cfsecobj/CFSecISOCtryLangEditObj.hpp>


namespace cfsec {

	const std::string CFSecISOCtryLangEditObj::CLASS_NAME( "CFSecISOCtryLangEditObj" );

	CFSecISOCtryLangEditObj::CFSecISOCtryLangEditObj( cfsec::ICFSecISOCtryLangObj* argOrig )
	: ICFSecISOCtryLangEditObj()
	{
		static const std::string S_ProcName( "CFSecISOCtryLangEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecISOCtryLangBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( origBuff->clone() );
	}

	CFSecISOCtryLangEditObj::~CFSecISOCtryLangEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFSecISOCtryLangEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFSecISOCtryLangEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCtryLangBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecISOCtryLangEditObj::getCreatedAt() {
		return( getISOCtryLangBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecISOCtryLangEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCtryLangBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecISOCtryLangEditObj::getUpdatedAt() {
		return( getISOCtryLangBuff()->getUpdatedAt() );
	}

	void CFSecISOCtryLangEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getISOCtryLangEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecISOCtryLangEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getISOCtryLangEditBuff()->setCreatedAt( value );
	}

	void CFSecISOCtryLangEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getISOCtryLangEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecISOCtryLangEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getISOCtryLangEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFSecISOCtryLangEditObj::getClassCode() const {
		return( cfsec::CFSecISOCtryLangBuff::CLASS_CODE );
	}

	bool CFSecISOCtryLangEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecISOCtryLangBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecISOCtryLangEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOCtryLangEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ISOCtryId( "ISOCtryId" );
		static const std::string S_ISOLangId( "ISOLangId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecISOCtryLangEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecISOCtryLangEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecISOCtryLangEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecISOCtryLangEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecISOCtryLangEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCtryId, CFSecISOCtryLangEditObj::getRequiredISOCtryId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOLangId, CFSecISOCtryLangEditObj::getRequiredISOLangId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFSecISOCtryLangEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFSecISOCtryLangEditObj::setRequiredRevision( int32_t value ) {
		getISOCtryLangEditBuff()->setRequiredRevision( value );
	}

	std::string CFSecISOCtryLangEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		int16_t val = getRequiredISOLangId();
		objName = cflib::CFLibXmlUtil::formatInt16( val );
		return( objName );
	}

	const std::string CFSecISOCtryLangEditObj::getGenDefName() {
		return( cfsec::CFSecISOCtryLangBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecISOCtryLangEditObj::getScope() {
		cfsec::ICFSecISOCtryObj* scope = getRequiredContainerCtry();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecISOCtryLangEditObj::getObjScope() {
		cfsec::ICFSecISOCtryObj* scope = getRequiredContainerCtry();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecISOCtryLangEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
		cflib::ICFLibAnyObj* container = this;
		if( qualifyingClass != NULL ) {
			while( container != NULL ) {
				if( container->getClassCode() == cfsec::CFSecClusterBuff::CLASS_CODE ) {
					break;
				}
				else if( container->getClassCode() == cfsec::CFSecTenantBuff::CLASS_CODE ) {
					break;
				}
				else if( container->implementsClassCode( *qualifyingClass ) ) {
					break;
				}
				container = container->getObjScope();
			}
		}
		else {
			while( container != NULL ) {
				if( container->getClassCode() == cfsec::CFSecClusterBuff::CLASS_CODE ) {
					break;
				}
				else if( container->getClassCode() == cfsec::CFSecTenantBuff::CLASS_CODE ) {
					break;
				}
				container = container->getObjScope();
			}
		}
		return( container );
	}

	cflib::ICFLibAnyObj* CFSecISOCtryLangEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecISOCtryLangEditObj::getNamedObject( const std::string& objName ) {
		std::string nextName;
		std::string remainingName;
		cflib::ICFLibAnyObj* subObj = NULL;
		cflib::ICFLibAnyObj* retObj;
		int32_t nextDot = objName.find( '.' );
		if( nextDot >= 0 ) {
			nextName = objName.substr( 0, nextDot );
			remainingName = objName.substr( nextDot + 1 );
		}
		else {
			nextName.clear();
			nextName.append( objName );
			remainingName.clear();
		}
		if( remainingName.length() <= 0 ) {
			retObj = subObj;
		}
		else if( subObj == NULL ) {
			retObj = NULL;
		}
		else {
			retObj = subObj->getNamedObject( remainingName );
		}
		return( retObj );
	}

	std::string CFSecISOCtryLangEditObj::getObjQualifiedName() {
		const static std::string S_Dot( "." );
		std::string qualName( getObjName() );
		cflib::ICFLibAnyObj* container = getObjScope();
		std::string containerName;
		std::string buildName;
		while( container != NULL ) {
			if( container->getClassCode() == cfsec::CFSecClusterBuff::CLASS_CODE ) {
				container = NULL;
			}
			else if( container->getClassCode() == cfsec::CFSecTenantBuff::CLASS_CODE ) {
				container = NULL;
			}
			else {
				containerName = container->getObjName();
				buildName.clear();
				buildName.append( containerName );
				buildName.append( S_Dot );
				buildName.append( qualName );
				qualName.clear();
				qualName.append( buildName );
				container = container->getObjScope();
			}
		}
		return( qualName );
	}

	std::string CFSecISOCtryLangEditObj::getObjFullName() {
		const static std::string S_Dot( "." );
		std::string fullName = getObjName();
		cflib::ICFLibAnyObj* container = getObjScope();
		std::string containerName;
		std::string buildName;
		while( container != NULL ) {
			if( container->getClassCode() == cfsec::CFSecClusterBuff::CLASS_CODE ) {
				container = NULL;
			}
			else if( container->getClassCode() == cfsec::CFSecTenantBuff::CLASS_CODE ) {
				container = NULL;
			}
			else {
				containerName = container->getObjName();
				buildName.clear();
				buildName.append( containerName );
				buildName.append( S_Dot );
				buildName.append( fullName );
				fullName.clear();
				fullName.append( buildName );
				container = container->getObjScope();
			}
		}
		return( fullName );
	}

	cfsec::ICFSecISOCtryLangObj* CFSecISOCtryLangEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecISOCtryLangObj* retobj = getSchema()->getISOCtryLangTableObj()->realizeISOCtryLang( dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecISOCtryLangObj* CFSecISOCtryLangEditObj::read( bool forceRead ) {
		cfsec::ICFSecISOCtryLangObj* retval = getOrigAsISOCtryLang()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecISOCtryLangObj* CFSecISOCtryLangEditObj::create() {
		cfsec::ICFSecISOCtryLangObj* retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsISOCtryLang()->getSchema() )->getISOCtryLangTableObj()->createISOCtryLang( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecISOCtryLangEditObj* CFSecISOCtryLangEditObj::update() {
		getSchema()->getISOCtryLangTableObj()->updateISOCtryLang( this );
		return( NULL );
	}

	cfsec::ICFSecISOCtryLangEditObj* CFSecISOCtryLangEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getISOCtryLangTableObj()->deleteISOCtryLang( this );
		return( NULL );
	}

	cfsec::ICFSecISOCtryLangTableObj* CFSecISOCtryLangEditObj::getISOCtryLangTable() {
		return( orig->getSchema()->getISOCtryLangTableObj() );
	}

	cfsec::ICFSecISOCtryLangEditObj* CFSecISOCtryLangEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecISOCtryLangEditObj* CFSecISOCtryLangEditObj::getISOCtryLangEdit() {
		return( (cfsec::ICFSecISOCtryLangEditObj*)this );
	}

	cfsec::ICFSecISOCtryLangEditObj* CFSecISOCtryLangEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFSecISOCtryLangEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecISOCtryLangObj* CFSecISOCtryLangEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecISOCtryLangObj* CFSecISOCtryLangEditObj::getOrigAsISOCtryLang() {
		return( dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFSecISOCtryLangEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecISOCtryLangBuff* CFSecISOCtryLangEditObj::getBuff() {
		return( buff );
	}

	void CFSecISOCtryLangEditObj::setBuff( cfsec::CFSecISOCtryLangBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecISOCtryLangPKey* CFSecISOCtryLangEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFSecISOCtryLangEditObj::setPKey( cfsec::CFSecISOCtryLangPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFSecISOCtryLangEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFSecISOCtryLangEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int16_t CFSecISOCtryLangEditObj::getRequiredISOCtryId() {
		return( getPKey()->getRequiredISOCtryId() );
	}

	const int16_t* CFSecISOCtryLangEditObj::getRequiredISOCtryIdReference() {
		return( getPKey()->getRequiredISOCtryIdReference() );
	}

	const int16_t CFSecISOCtryLangEditObj::getRequiredISOLangId() {
		return( getPKey()->getRequiredISOLangId() );
	}

	const int16_t* CFSecISOCtryLangEditObj::getRequiredISOLangIdReference() {
		return( getPKey()->getRequiredISOLangIdReference() );
	}

	cfsec::ICFSecISOCtryObj* CFSecISOCtryLangEditObj::getRequiredContainerCtry( bool forceRead ) {
		cfsec::ICFSecISOCtryObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsISOCtryLang()->getSchema() )->getISOCtryTableObj()->readISOCtryByIdIdx( getPKey()->getRequiredISOCtryId() );
		}
		return( retobj );
	}

	void CFSecISOCtryLangEditObj::setRequiredContainerCtry( cfsec::ICFSecISOCtryObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredISOCtryId
( value->getRequiredISOCtryId() );
				getISOCtryLangEditBuff()->setRequiredISOCtryId( value->getRequiredISOCtryId() );
			}
		}

	cfsec::ICFSecISOLangObj* CFSecISOCtryLangEditObj::getRequiredParentLang( bool forceRead ) {
		cfsec::ICFSecISOLangObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsISOCtryLang()->getSchema() )->getISOLangTableObj()->readISOLangByIdIdx( getPKey()->getRequiredISOLangId() );
		}
		return( retobj );
	}

	void CFSecISOCtryLangEditObj::setRequiredParentLang( cfsec::ICFSecISOLangObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredISOLangId
( value->getRequiredISOLangId() );
				getISOCtryLangEditBuff()->setRequiredISOLangId( value->getRequiredISOLangId() );
			}
			else {
			}
		}

	void CFSecISOCtryLangEditObj::copyPKeyToBuff() {
		cfsec::CFSecISOCtryLangPKey* tablePKey = getPKey();
		cfsec::CFSecISOCtryLangBuff* tableBuff = getISOCtryLangEditBuff();
		tableBuff->setRequiredISOCtryId( tablePKey->getRequiredISOCtryId() );
		tableBuff->setRequiredISOLangId( tablePKey->getRequiredISOLangId() );
	}

	void CFSecISOCtryLangEditObj::copyBuffToPKey() {
		cfsec::CFSecISOCtryLangPKey* tablePKey = getPKey();
		cfsec::CFSecISOCtryLangBuff* tableBuff = getISOCtryLangBuff();
		tablePKey->setRequiredISOCtryId( tableBuff->getRequiredISOCtryId() );
		tablePKey->setRequiredISOLangId( tableBuff->getRequiredISOLangId() );
	}

	void CFSecISOCtryLangEditObj::copyBuffToOrig() {
		cfsec::CFSecISOCtryLangBuff* origBuff = getOrigAsISOCtryLang()->getISOCtryLangEditBuff();
		cfsec::CFSecISOCtryLangBuff* myBuff = getISOCtryLangBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFSecISOCtryLangEditObj::copyOrigToBuff() {
		cfsec::CFSecISOCtryLangBuff* origBuff = getOrigAsISOCtryLang()->getISOCtryLangBuff();
		cfsec::CFSecISOCtryLangBuff* myBuff = getISOCtryLangEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
