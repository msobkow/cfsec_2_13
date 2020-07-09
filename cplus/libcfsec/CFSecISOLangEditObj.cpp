// Description: C++18 edit object instance implementation for CFSec ISOLang.

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

#include <cfsec/ICFSecPublic.hpp>
#include <cfsecobj/ICFSecObjPublic.hpp>
#include <cfsecobj/CFSecISOLangObj.hpp>
#include <cfsecobj/CFSecISOLangEditObj.hpp>


namespace cfsec {

	const std::string CFSecISOLangEditObj::CLASS_NAME( "CFSecISOLangEditObj" );

	CFSecISOLangEditObj::CFSecISOLangEditObj( cfsec::ICFSecISOLangObj* argOrig )
	: ICFSecISOLangEditObj()
	{
		static const std::string S_ProcName( "CFSecISOLangEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecISOLangBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecISOLangBuff*>( origBuff->clone() );
	}

	CFSecISOLangEditObj::~CFSecISOLangEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFSecISOLangEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFSecISOLangEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOLangBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecISOLangEditObj::getCreatedAt() {
		return( getISOLangBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecISOLangEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOLangBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecISOLangEditObj::getUpdatedAt() {
		return( getISOLangBuff()->getUpdatedAt() );
	}

	void CFSecISOLangEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getISOLangEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecISOLangEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getISOLangEditBuff()->setCreatedAt( value );
	}

	void CFSecISOLangEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getISOLangEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecISOLangEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getISOLangEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFSecISOLangEditObj::getClassCode() const {
		return( cfsec::CFSecISOLangBuff::CLASS_CODE );
	}

	bool CFSecISOLangEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecISOLangBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecISOLangEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOLangEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ISOLangId( "ISOLangId" );
		static const std::string S_ISO6392Code( "ISO6392Code" );
		static const std::string S_ISO6391Code( "ISO6391Code" );
		static const std::string S_EnglishName( "EnglishName" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecISOLangEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecISOLangEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecISOLangEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecISOLangEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecISOLangEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOLangId, CFSecISOLangEditObj::getRequiredISOLangId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_ISO6392Code, CFSecISOLangEditObj::getRequiredISO6392Code() ) );
		if( ! CFSecISOLangEditObj::isOptionalISO6391CodeNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_ISO6391Code, CFSecISOLangEditObj::getOptionalISO6391CodeValue() ) );
		}
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_EnglishName, CFSecISOLangEditObj::getRequiredEnglishName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFSecISOLangEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFSecISOLangEditObj::setRequiredRevision( int32_t value ) {
		getISOLangEditBuff()->setRequiredRevision( value );
	}

	std::string CFSecISOLangEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredISO6392Code() );
		return( objName );
	}

	const std::string CFSecISOLangEditObj::getGenDefName() {
		return( cfsec::CFSecISOLangBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecISOLangEditObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFSecISOLangEditObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFSecISOLangEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecISOLangEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecISOLangEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecISOLangEditObj::getObjQualifiedName() {
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

	std::string CFSecISOLangEditObj::getObjFullName() {
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

	cfsec::ICFSecISOLangObj* CFSecISOLangEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecISOLangObj* retobj = getSchema()->getISOLangTableObj()->realizeISOLang( dynamic_cast<cfsec::ICFSecISOLangObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecISOLangObj* CFSecISOLangEditObj::read( bool forceRead ) {
		cfsec::ICFSecISOLangObj* retval = getOrigAsISOLang()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecISOLangObj* CFSecISOLangEditObj::create() {
		cfsec::ICFSecISOLangObj* retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsISOLang()->getSchema() )->getISOLangTableObj()->createISOLang( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecISOLangEditObj* CFSecISOLangEditObj::update() {
		getSchema()->getISOLangTableObj()->updateISOLang( this );
		return( NULL );
	}

	cfsec::ICFSecISOLangEditObj* CFSecISOLangEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getISOLangTableObj()->deleteISOLang( this );
		return( NULL );
	}

	cfsec::ICFSecISOLangTableObj* CFSecISOLangEditObj::getISOLangTable() {
		return( orig->getSchema()->getISOLangTableObj() );
	}

	cfsec::ICFSecISOLangEditObj* CFSecISOLangEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecISOLangEditObj* CFSecISOLangEditObj::getISOLangEdit() {
		return( (cfsec::ICFSecISOLangEditObj*)this );
	}

	cfsec::ICFSecISOLangEditObj* CFSecISOLangEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFSecISOLangEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecISOLangObj* CFSecISOLangEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecISOLangObj* CFSecISOLangEditObj::getOrigAsISOLang() {
		return( dynamic_cast<cfsec::ICFSecISOLangObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFSecISOLangEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecISOLangBuff* CFSecISOLangEditObj::getBuff() {
		return( buff );
	}

	void CFSecISOLangEditObj::setBuff( cfsec::CFSecISOLangBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecISOLangPKey* CFSecISOLangEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFSecISOLangEditObj::setPKey( cfsec::CFSecISOLangPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFSecISOLangEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFSecISOLangEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int16_t CFSecISOLangEditObj::getRequiredISOLangId() {
		return( getPKey()->getRequiredISOLangId() );
	}

	const int16_t* CFSecISOLangEditObj::getRequiredISOLangIdReference() {
		return( getPKey()->getRequiredISOLangIdReference() );
	}

	const std::string& CFSecISOLangEditObj::getRequiredISO6392Code() {
		return( getISOLangBuff()->getRequiredISO6392Code() );
	}

	const std::string* CFSecISOLangEditObj::getRequiredISO6392CodeReference() {
		return( getISOLangBuff()->getRequiredISO6392CodeReference() );
	}

	void CFSecISOLangEditObj::setRequiredISO6392Code( const std::string& value ) {
		if( getISOLangBuff()->getRequiredISO6392Code() != value ) {
			getISOLangEditBuff()->setRequiredISO6392Code( value );
		}
	}

	bool CFSecISOLangEditObj::isOptionalISO6391CodeNull() {
		return( getISOLangBuff()->isOptionalISO6391CodeNull() );
	}

	const std::string& CFSecISOLangEditObj::getOptionalISO6391CodeValue() {
		return( getISOLangBuff()->getOptionalISO6391CodeValue() );
	}

	const std::string* CFSecISOLangEditObj::getOptionalISO6391CodeReference() {
		return( getISOLangBuff()->getOptionalISO6391CodeReference() );
	}

	void CFSecISOLangEditObj::setOptionalISO6391CodeNull() {
		if( ! getISOLangBuff()->isOptionalISO6391CodeNull() ) {
			getISOLangEditBuff()->setOptionalISO6391CodeNull();
		}
	}

	void CFSecISOLangEditObj::setOptionalISO6391CodeValue( const std::string& value ) {
		if( getISOLangBuff()->isOptionalISO6391CodeNull() ) {
			getISOLangEditBuff()->setOptionalISO6391CodeValue( value );
		}
		else if( getISOLangBuff()->getOptionalISO6391CodeValue() != value ) {
			getISOLangEditBuff()->setOptionalISO6391CodeValue( value );
		}
	}

	const std::string& CFSecISOLangEditObj::getRequiredEnglishName() {
		return( getISOLangBuff()->getRequiredEnglishName() );
	}

	const std::string* CFSecISOLangEditObj::getRequiredEnglishNameReference() {
		return( getISOLangBuff()->getRequiredEnglishNameReference() );
	}

	void CFSecISOLangEditObj::setRequiredEnglishName( const std::string& value ) {
		if( getISOLangBuff()->getRequiredEnglishName() != value ) {
			getISOLangEditBuff()->setRequiredEnglishName( value );
		}
	}

	std::vector<cfsec::ICFSecISOCtryLangObj*> CFSecISOLangEditObj::getOptionalChildrenCtry( bool forceRead ) {
		std::vector<cfsec::ICFSecISOCtryLangObj*> retval;
		retval = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsISOLang()->getSchema() )->getISOCtryLangTableObj()->readISOCtryLangByLangIdx( getPKey()->getRequiredISOLangId(),
			forceRead );
		return( retval );
	}

	void CFSecISOLangEditObj::copyPKeyToBuff() {
		cfsec::CFSecISOLangPKey* tablePKey = getPKey();
		cfsec::CFSecISOLangBuff* tableBuff = getISOLangEditBuff();
		tableBuff->setRequiredISOLangId( tablePKey->getRequiredISOLangId() );
	}

	void CFSecISOLangEditObj::copyBuffToPKey() {
		cfsec::CFSecISOLangPKey* tablePKey = getPKey();
		cfsec::CFSecISOLangBuff* tableBuff = getISOLangBuff();
		tablePKey->setRequiredISOLangId( tableBuff->getRequiredISOLangId() );
	}

	void CFSecISOLangEditObj::copyBuffToOrig() {
		cfsec::CFSecISOLangBuff* origBuff = getOrigAsISOLang()->getISOLangEditBuff();
		cfsec::CFSecISOLangBuff* myBuff = getISOLangBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFSecISOLangEditObj::copyOrigToBuff() {
		cfsec::CFSecISOLangBuff* origBuff = getOrigAsISOLang()->getISOLangBuff();
		cfsec::CFSecISOLangBuff* myBuff = getISOLangEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
