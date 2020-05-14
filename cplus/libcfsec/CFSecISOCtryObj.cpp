// Description: C++18 base object instance implementation for CFSec ISOCtry.

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

namespace cfsec {

	const std::string CFSecISOCtryObj::CLASS_NAME( "CFSecISOCtryObj" );
	const classcode_t CFSecISOCtryObj::CLASS_CODE = 0xa004L;

	int32_t CFSecISOCtryObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int16_t CFSecISOCtryObj::getRequiredISOCtryId() {
		return( getPKey()->getRequiredISOCtryId() );
	}

	const int16_t* CFSecISOCtryObj::getRequiredISOCtryIdReference() {
		return( getPKey()->getRequiredISOCtryIdReference() );
	}

	const std::string& CFSecISOCtryObj::getRequiredISOCode() {
		return( getISOCtryBuff()->getRequiredISOCode() );
	}

	const std::string* CFSecISOCtryObj::getRequiredISOCodeReference() {
		return( getISOCtryBuff()->getRequiredISOCodeReference() );
	}

	const std::string& CFSecISOCtryObj::getRequiredName() {
		return( getISOCtryBuff()->getRequiredName() );
	}

	const std::string* CFSecISOCtryObj::getRequiredNameReference() {
		return( getISOCtryBuff()->getRequiredNameReference() );
	}


	std::vector<cfsec::ICFSecISOCtryCcyObj*> CFSecISOCtryObj::getOptionalComponentsCcy( bool forceRead ) {
		std::vector<cfsec::ICFSecISOCtryCcyObj*> retval;
		retval = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOCtryCcyTableObj()->readISOCtryCcyByCtryIdx( getPKey()->getRequiredISOCtryId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecISOCtryLangObj*> CFSecISOCtryObj::getOptionalComponentsLang( bool forceRead ) {
		std::vector<cfsec::ICFSecISOCtryLangObj*> retval;
		retval = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOCtryLangTableObj()->readISOCtryLangByCtryIdx( getPKey()->getRequiredISOCtryId(),
			forceRead );
		return( retval );
	}

	CFSecISOCtryObj::CFSecISOCtryObj()
	: ICFSecISOCtryObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecISOCtryObj::CFSecISOCtryObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFSecISOCtryObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecISOCtryObj::~CFSecISOCtryObj() {
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

	cfsec::CFSecISOCtryBuff* CFSecISOCtryObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecISOCtryBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtry()->readDerivedByIdIdx( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredISOCtryId() );
			}
		}
		return( buff );
	}

	void CFSecISOCtryObj::setBuff( cfsec::CFSecISOCtryBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFSecISOCtryObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecISOCtryObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecISOCtryObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecISOCtryBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecISOCtryObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOCtryObj" );
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
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecISOCtryObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecISOCtryObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecISOCtryObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecISOCtryObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecISOCtryObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCtryId, CFSecISOCtryObj::getRequiredISOCtryId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_ISOCode, CFSecISOCtryObj::getRequiredISOCode() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFSecISOCtryObj::getRequiredName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFSecISOCtryObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredISOCode() );
		return( objName );
	}

	const std::string CFSecISOCtryObj::getGenDefName() {
		return( cfsec::CFSecISOCtryBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecISOCtryObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFSecISOCtryObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFSecISOCtryObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecISOCtryObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecISOCtryObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecISOCtryObj::getObjQualifiedName() {
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

	std::string CFSecISOCtryObj::getObjFullName() {
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

	cfsec::ICFSecISOCtryObj* CFSecISOCtryObj::realize() {
		cfsec::ICFSecISOCtryObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOCtryTableObj()->realizeISOCtry(
			(cfsec::ICFSecISOCtryObj*)this );
		return( dynamic_cast<cfsec::ICFSecISOCtryObj*>( retobj ) );
	}

	cfsec::ICFSecISOCtryObj* CFSecISOCtryObj::read( bool forceRead ) {
		cfsec::ICFSecISOCtryObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOCtryTableObj()->readISOCtryByIdIdx( getISOCtryBuff()->getRequiredISOCtryId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecISOCtryObj*>( retobj ) );
	}

	cfsec::ICFSecISOCtryTableObj* CFSecISOCtryObj::getISOCtryTable() {
		return( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOCtryTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFSecISOCtryObj::getSchema() {
		return( schema );
	}

	void CFSecISOCtryObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecISOCtryPKey* CFSecISOCtryObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecISOCtryPKey();
		}
		return( pKey );
	}

	void CFSecISOCtryObj::setPKey( cfsec::CFSecISOCtryPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecISOCtryPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFSecISOCtryObj::getIsNew() {
		return( isNew );
	}

	void CFSecISOCtryObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecISOCtryEditObj* CFSecISOCtryObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecISOCtryObj* lockobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOCtryTableObj()->lockISOCtry( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOCtryTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecISOCtryEditObj*>( edit ) );
	}

	void CFSecISOCtryObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecISOCtryEditObj* CFSecISOCtryObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecISOCtryEditObj* CFSecISOCtryObj::getISOCtryEdit() {
		return( dynamic_cast<cfsec::ICFSecISOCtryEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFSecISOCtryObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCtryBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecISOCtryObj::getCreatedAt() {
		return( getISOCtryBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecISOCtryObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCtryBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecISOCtryObj::getUpdatedAt() {
		return( getISOCtryBuff()->getUpdatedAt() );
	}

	void CFSecISOCtryObj::copyPKeyToBuff() {
		cfsec::CFSecISOCtryPKey* tablePKey = getPKey();
		cfsec::CFSecISOCtryBuff* tableBuff = getISOCtryEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredISOCtryId( tablePKey->getRequiredISOCtryId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFSecISOCtryObj::copyBuffToPKey() {
		cfsec::CFSecISOCtryPKey* tablePKey = getPKey();
		cfsec::CFSecISOCtryBuff* tableBuff = getISOCtryBuff();
		tablePKey->setRequiredISOCtryId( tableBuff->getRequiredISOCtryId() );
	}

}
