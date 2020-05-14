// Description: C++18 base object instance implementation for CFSec ISOLang.

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
#include <cfsecobj/CFSecISOLangObj.hpp>

namespace cfsec {

	const std::string CFSecISOLangObj::CLASS_NAME( "CFSecISOLangObj" );
	const classcode_t CFSecISOLangObj::CLASS_CODE = 0xa007L;

	int32_t CFSecISOLangObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int16_t CFSecISOLangObj::getRequiredISOLangId() {
		return( getPKey()->getRequiredISOLangId() );
	}

	const int16_t* CFSecISOLangObj::getRequiredISOLangIdReference() {
		return( getPKey()->getRequiredISOLangIdReference() );
	}

	const std::string& CFSecISOLangObj::getRequiredISO6392Code() {
		return( getISOLangBuff()->getRequiredISO6392Code() );
	}

	const std::string* CFSecISOLangObj::getRequiredISO6392CodeReference() {
		return( getISOLangBuff()->getRequiredISO6392CodeReference() );
	}

	bool CFSecISOLangObj::isOptionalISO6391CodeNull() {
		return( getISOLangBuff()->isOptionalISO6391CodeNull() );
	}

	const std::string& CFSecISOLangObj::getOptionalISO6391CodeValue() {
		return( getISOLangBuff()->getOptionalISO6391CodeValue() );
	}

	const std::string* CFSecISOLangObj::getOptionalISO6391CodeReference() {
		return( getISOLangBuff()->getOptionalISO6391CodeReference() );
	}

	const std::string& CFSecISOLangObj::getRequiredEnglishName() {
		return( getISOLangBuff()->getRequiredEnglishName() );
	}

	const std::string* CFSecISOLangObj::getRequiredEnglishNameReference() {
		return( getISOLangBuff()->getRequiredEnglishNameReference() );
	}


	std::vector<cfsec::ICFSecISOCtryLangObj*> CFSecISOLangObj::getOptionalChildrenCtry( bool forceRead ) {
		std::vector<cfsec::ICFSecISOCtryLangObj*> retval;
		retval = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOCtryLangTableObj()->readISOCtryLangByLangIdx( getPKey()->getRequiredISOLangId(),
			forceRead );
		return( retval );
	}

	CFSecISOLangObj::CFSecISOLangObj()
	: ICFSecISOLangObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecISOLangObj::CFSecISOLangObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFSecISOLangObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecISOLangObj::~CFSecISOLangObj() {
		schema = NULL;
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}
		if( pKey != NULL ) {
			delete pKey;
			pKey = NULL;
		}

	}

	cfsec::CFSecISOLangBuff* CFSecISOLangObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecISOLangBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOLang()->readDerivedByIdIdx( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredISOLangId() );
			}
		}
		return( buff );
	}

	void CFSecISOLangObj::setBuff( cfsec::CFSecISOLangBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFSecISOLangObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecISOLangObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecISOLangObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecISOLangBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecISOLangObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOLangObj" );
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
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecISOLangObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecISOLangObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecISOLangObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecISOLangObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecISOLangObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOLangId, CFSecISOLangObj::getRequiredISOLangId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_ISO6392Code, CFSecISOLangObj::getRequiredISO6392Code() ) );
		if( ! CFSecISOLangObj::isOptionalISO6391CodeNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_ISO6391Code, CFSecISOLangObj::getOptionalISO6391CodeValue() ) );
		}
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_EnglishName, CFSecISOLangObj::getRequiredEnglishName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFSecISOLangObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredISO6392Code() );
		return( objName );
	}

	const std::string CFSecISOLangObj::getGenDefName() {
		return( cfsec::CFSecISOLangBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecISOLangObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFSecISOLangObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFSecISOLangObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecISOLangObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecISOLangObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecISOLangObj::getObjQualifiedName() {
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

	std::string CFSecISOLangObj::getObjFullName() {
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

	cfsec::ICFSecISOLangObj* CFSecISOLangObj::realize() {
		cfsec::ICFSecISOLangObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOLangTableObj()->realizeISOLang(
			(cfsec::ICFSecISOLangObj*)this );
		return( dynamic_cast<cfsec::ICFSecISOLangObj*>( retobj ) );
	}

	cfsec::ICFSecISOLangObj* CFSecISOLangObj::read( bool forceRead ) {
		cfsec::ICFSecISOLangObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOLangTableObj()->readISOLangByIdIdx( getISOLangBuff()->getRequiredISOLangId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecISOLangObj*>( retobj ) );
	}

	cfsec::ICFSecISOLangTableObj* CFSecISOLangObj::getISOLangTable() {
		return( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOLangTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFSecISOLangObj::getSchema() {
		return( schema );
	}

	void CFSecISOLangObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecISOLangPKey* CFSecISOLangObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecISOLangPKey();
		}
		return( pKey );
	}

	void CFSecISOLangObj::setPKey( cfsec::CFSecISOLangPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecISOLangPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFSecISOLangObj::getIsNew() {
		return( isNew );
	}

	void CFSecISOLangObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecISOLangEditObj* CFSecISOLangObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecISOLangObj* lockobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOLangTableObj()->lockISOLang( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOLangTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecISOLangEditObj*>( edit ) );
	}

	void CFSecISOLangObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecISOLangEditObj* CFSecISOLangObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecISOLangEditObj* CFSecISOLangObj::getISOLangEdit() {
		return( dynamic_cast<cfsec::ICFSecISOLangEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFSecISOLangObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOLangBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecISOLangObj::getCreatedAt() {
		return( getISOLangBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecISOLangObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOLangBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecISOLangObj::getUpdatedAt() {
		return( getISOLangBuff()->getUpdatedAt() );
	}

	void CFSecISOLangObj::copyPKeyToBuff() {
		cfsec::CFSecISOLangPKey* tablePKey = getPKey();
		cfsec::CFSecISOLangBuff* tableBuff = getISOLangEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredISOLangId( tablePKey->getRequiredISOLangId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFSecISOLangObj::copyBuffToPKey() {
		cfsec::CFSecISOLangPKey* tablePKey = getPKey();
		cfsec::CFSecISOLangBuff* tableBuff = getISOLangBuff();
		tablePKey->setRequiredISOLangId( tableBuff->getRequiredISOLangId() );
	}

}
