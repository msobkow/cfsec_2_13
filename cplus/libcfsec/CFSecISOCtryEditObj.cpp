// Description: C++18 edit object instance implementation for CFSec ISOCtry.

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

#include <cfsec/ICFSecPublic.hpp>
#include <cfsecobj/ICFSecObjPublic.hpp>
#include <cfsecobj/CFSecISOCtryObj.hpp>
#include <cfsecobj/CFSecISOCtryEditObj.hpp>


namespace cfsec {

	const std::string CFSecISOCtryEditObj::CLASS_NAME( "CFSecISOCtryEditObj" );

	CFSecISOCtryEditObj::CFSecISOCtryEditObj( cfsec::ICFSecISOCtryObj* argOrig )
	: ICFSecISOCtryEditObj()
	{
		static const std::string S_ProcName( "CFSecISOCtryEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecISOCtryBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecISOCtryBuff*>( origBuff->clone() );
	}

	CFSecISOCtryEditObj::~CFSecISOCtryEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFSecISOCtryEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFSecISOCtryEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCtryBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecISOCtryEditObj::getCreatedAt() {
		return( getISOCtryBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecISOCtryEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCtryBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecISOCtryEditObj::getUpdatedAt() {
		return( getISOCtryBuff()->getUpdatedAt() );
	}

	void CFSecISOCtryEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getISOCtryEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecISOCtryEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getISOCtryEditBuff()->setCreatedAt( value );
	}

	void CFSecISOCtryEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getISOCtryEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecISOCtryEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getISOCtryEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFSecISOCtryEditObj::getClassCode() const {
		return( cfsec::CFSecISOCtryBuff::CLASS_CODE );
	}

	bool CFSecISOCtryEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecISOCtryBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecISOCtryEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOCtryEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ISOCtryId( "ISOCtryId" );
		static const std::string S_ISOCode( "ISOCode" );
		static const std::string S_Name( "Name" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecISOCtryEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecISOCtryEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecISOCtryEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecISOCtryEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecISOCtryEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCtryId, CFSecISOCtryEditObj::getRequiredISOCtryId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_ISOCode, CFSecISOCtryEditObj::getRequiredISOCode() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFSecISOCtryEditObj::getRequiredName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFSecISOCtryEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFSecISOCtryEditObj::setRequiredRevision( int32_t value ) {
		getISOCtryEditBuff()->setRequiredRevision( value );
	}

	std::string CFSecISOCtryEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredISOCode() );
		return( objName );
	}

	const std::string CFSecISOCtryEditObj::getGenDefName() {
		return( cfsec::CFSecISOCtryBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecISOCtryEditObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFSecISOCtryEditObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFSecISOCtryEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecISOCtryEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecISOCtryEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecISOCtryEditObj::getObjQualifiedName() {
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

	std::string CFSecISOCtryEditObj::getObjFullName() {
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

	cfsec::ICFSecISOCtryObj* CFSecISOCtryEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecISOCtryObj* retobj = getSchema()->getISOCtryTableObj()->realizeISOCtry( dynamic_cast<cfsec::ICFSecISOCtryObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecISOCtryObj* CFSecISOCtryEditObj::read( bool forceRead ) {
		cfsec::ICFSecISOCtryObj* retval = getOrigAsISOCtry()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecISOCtryObj* CFSecISOCtryEditObj::create() {
		cfsec::ICFSecISOCtryObj* retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsISOCtry()->getSchema() )->getISOCtryTableObj()->createISOCtry( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecISOCtryEditObj* CFSecISOCtryEditObj::update() {
		getSchema()->getISOCtryTableObj()->updateISOCtry( this );
		return( NULL );
	}

	cfsec::ICFSecISOCtryEditObj* CFSecISOCtryEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getISOCtryTableObj()->deleteISOCtry( this );
		return( NULL );
	}

	cfsec::ICFSecISOCtryTableObj* CFSecISOCtryEditObj::getISOCtryTable() {
		return( orig->getSchema()->getISOCtryTableObj() );
	}

	cfsec::ICFSecISOCtryEditObj* CFSecISOCtryEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecISOCtryEditObj* CFSecISOCtryEditObj::getISOCtryEdit() {
		return( (cfsec::ICFSecISOCtryEditObj*)this );
	}

	cfsec::ICFSecISOCtryEditObj* CFSecISOCtryEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFSecISOCtryEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecISOCtryObj* CFSecISOCtryEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecISOCtryObj* CFSecISOCtryEditObj::getOrigAsISOCtry() {
		return( dynamic_cast<cfsec::ICFSecISOCtryObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFSecISOCtryEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecISOCtryBuff* CFSecISOCtryEditObj::getBuff() {
		return( buff );
	}

	void CFSecISOCtryEditObj::setBuff( cfsec::CFSecISOCtryBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecISOCtryPKey* CFSecISOCtryEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFSecISOCtryEditObj::setPKey( cfsec::CFSecISOCtryPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFSecISOCtryEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFSecISOCtryEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int16_t CFSecISOCtryEditObj::getRequiredISOCtryId() {
		return( getPKey()->getRequiredISOCtryId() );
	}

	const int16_t* CFSecISOCtryEditObj::getRequiredISOCtryIdReference() {
		return( getPKey()->getRequiredISOCtryIdReference() );
	}

	const std::string& CFSecISOCtryEditObj::getRequiredISOCode() {
		return( getISOCtryBuff()->getRequiredISOCode() );
	}

	const std::string* CFSecISOCtryEditObj::getRequiredISOCodeReference() {
		return( getISOCtryBuff()->getRequiredISOCodeReference() );
	}

	void CFSecISOCtryEditObj::setRequiredISOCode( const std::string& value ) {
		if( getISOCtryBuff()->getRequiredISOCode() != value ) {
			getISOCtryEditBuff()->setRequiredISOCode( value );
		}
	}

	const std::string& CFSecISOCtryEditObj::getRequiredName() {
		return( getISOCtryBuff()->getRequiredName() );
	}

	const std::string* CFSecISOCtryEditObj::getRequiredNameReference() {
		return( getISOCtryBuff()->getRequiredNameReference() );
	}

	void CFSecISOCtryEditObj::setRequiredName( const std::string& value ) {
		if( getISOCtryBuff()->getRequiredName() != value ) {
			getISOCtryEditBuff()->setRequiredName( value );
		}
	}

	std::vector<cfsec::ICFSecISOCtryCcyObj*> CFSecISOCtryEditObj::getOptionalComponentsCcy( bool forceRead ) {
		std::vector<cfsec::ICFSecISOCtryCcyObj*> retval;
		retval = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsISOCtry()->getSchema() )->getISOCtryCcyTableObj()->readISOCtryCcyByCtryIdx( getPKey()->getRequiredISOCtryId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecISOCtryLangObj*> CFSecISOCtryEditObj::getOptionalComponentsLang( bool forceRead ) {
		std::vector<cfsec::ICFSecISOCtryLangObj*> retval;
		retval = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsISOCtry()->getSchema() )->getISOCtryLangTableObj()->readISOCtryLangByCtryIdx( getPKey()->getRequiredISOCtryId(),
			forceRead );
		return( retval );
	}

	void CFSecISOCtryEditObj::copyPKeyToBuff() {
		cfsec::CFSecISOCtryPKey* tablePKey = getPKey();
		cfsec::CFSecISOCtryBuff* tableBuff = getISOCtryEditBuff();
		tableBuff->setRequiredISOCtryId( tablePKey->getRequiredISOCtryId() );
	}

	void CFSecISOCtryEditObj::copyBuffToPKey() {
		cfsec::CFSecISOCtryPKey* tablePKey = getPKey();
		cfsec::CFSecISOCtryBuff* tableBuff = getISOCtryBuff();
		tablePKey->setRequiredISOCtryId( tableBuff->getRequiredISOCtryId() );
	}

	void CFSecISOCtryEditObj::copyBuffToOrig() {
		cfsec::CFSecISOCtryBuff* origBuff = getOrigAsISOCtry()->getISOCtryEditBuff();
		cfsec::CFSecISOCtryBuff* myBuff = getISOCtryBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFSecISOCtryEditObj::copyOrigToBuff() {
		cfsec::CFSecISOCtryBuff* origBuff = getOrigAsISOCtry()->getISOCtryBuff();
		cfsec::CFSecISOCtryBuff* myBuff = getISOCtryEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
