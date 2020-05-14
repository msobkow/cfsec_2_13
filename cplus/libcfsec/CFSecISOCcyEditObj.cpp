// Description: C++18 edit object instance implementation for CFSec ISOCcy.

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
#include <cfsecobj/CFSecISOCcyObj.hpp>
#include <cfsecobj/CFSecISOCcyEditObj.hpp>


namespace cfsec {

	const std::string CFSecISOCcyEditObj::CLASS_NAME( "CFSecISOCcyEditObj" );

	CFSecISOCcyEditObj::CFSecISOCcyEditObj( cfsec::ICFSecISOCcyObj* argOrig )
	: ICFSecISOCcyEditObj()
	{
		static const std::string S_ProcName( "CFSecISOCcyEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecISOCcyBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( origBuff->clone() );
	}

	CFSecISOCcyEditObj::~CFSecISOCcyEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFSecISOCcyEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFSecISOCcyEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCcyBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecISOCcyEditObj::getCreatedAt() {
		return( getISOCcyBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecISOCcyEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCcyBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecISOCcyEditObj::getUpdatedAt() {
		return( getISOCcyBuff()->getUpdatedAt() );
	}

	void CFSecISOCcyEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getISOCcyEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecISOCcyEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getISOCcyEditBuff()->setCreatedAt( value );
	}

	void CFSecISOCcyEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getISOCcyEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecISOCcyEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getISOCcyEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFSecISOCcyEditObj::getClassCode() const {
		return( cfsec::CFSecISOCcyBuff::CLASS_CODE );
	}

	bool CFSecISOCcyEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecISOCcyEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOCcyEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ISOCcyId( "ISOCcyId" );
		static const std::string S_ISOCode( "ISOCode" );
		static const std::string S_Name( "Name" );
		static const std::string S_UnitSymbol( "UnitSymbol" );
		static const std::string S_Precis( "Precis" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecISOCcyEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecISOCcyEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecISOCcyEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecISOCcyEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecISOCcyEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCcyId, CFSecISOCcyEditObj::getRequiredISOCcyId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_ISOCode, CFSecISOCcyEditObj::getRequiredISOCode() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFSecISOCcyEditObj::getRequiredName() ) );
		if( ! CFSecISOCcyEditObj::isOptionalUnitSymbolNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UnitSymbol, CFSecISOCcyEditObj::getOptionalUnitSymbolValue() ) );
		}
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_Precis, CFSecISOCcyEditObj::getRequiredPrecis() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFSecISOCcyEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFSecISOCcyEditObj::setRequiredRevision( int32_t value ) {
		getISOCcyEditBuff()->setRequiredRevision( value );
	}

	std::string CFSecISOCcyEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredISOCode() );
		return( objName );
	}

	const std::string CFSecISOCcyEditObj::getGenDefName() {
		return( cfsec::CFSecISOCcyBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecISOCcyEditObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFSecISOCcyEditObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFSecISOCcyEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecISOCcyEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecISOCcyEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecISOCcyEditObj::getObjQualifiedName() {
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

	std::string CFSecISOCcyEditObj::getObjFullName() {
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

	cfsec::ICFSecISOCcyObj* CFSecISOCcyEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecISOCcyObj* retobj = getSchema()->getISOCcyTableObj()->realizeISOCcy( dynamic_cast<cfsec::ICFSecISOCcyObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecISOCcyObj* CFSecISOCcyEditObj::read( bool forceRead ) {
		cfsec::ICFSecISOCcyObj* retval = getOrigAsISOCcy()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecISOCcyObj* CFSecISOCcyEditObj::create() {
		cfsec::ICFSecISOCcyObj* retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsISOCcy()->getSchema() )->getISOCcyTableObj()->createISOCcy( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecISOCcyEditObj* CFSecISOCcyEditObj::update() {
		getSchema()->getISOCcyTableObj()->updateISOCcy( this );
		return( NULL );
	}

	cfsec::ICFSecISOCcyEditObj* CFSecISOCcyEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getISOCcyTableObj()->deleteISOCcy( this );
		return( NULL );
	}

	cfsec::ICFSecISOCcyTableObj* CFSecISOCcyEditObj::getISOCcyTable() {
		return( orig->getSchema()->getISOCcyTableObj() );
	}

	cfsec::ICFSecISOCcyEditObj* CFSecISOCcyEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecISOCcyEditObj* CFSecISOCcyEditObj::getISOCcyEdit() {
		return( (cfsec::ICFSecISOCcyEditObj*)this );
	}

	cfsec::ICFSecISOCcyEditObj* CFSecISOCcyEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFSecISOCcyEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecISOCcyObj* CFSecISOCcyEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecISOCcyObj* CFSecISOCcyEditObj::getOrigAsISOCcy() {
		return( dynamic_cast<cfsec::ICFSecISOCcyObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFSecISOCcyEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecISOCcyBuff* CFSecISOCcyEditObj::getBuff() {
		return( buff );
	}

	void CFSecISOCcyEditObj::setBuff( cfsec::CFSecISOCcyBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecISOCcyPKey* CFSecISOCcyEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFSecISOCcyEditObj::setPKey( cfsec::CFSecISOCcyPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFSecISOCcyEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFSecISOCcyEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int16_t CFSecISOCcyEditObj::getRequiredISOCcyId() {
		return( getPKey()->getRequiredISOCcyId() );
	}

	const int16_t* CFSecISOCcyEditObj::getRequiredISOCcyIdReference() {
		return( getPKey()->getRequiredISOCcyIdReference() );
	}

	const std::string& CFSecISOCcyEditObj::getRequiredISOCode() {
		return( getISOCcyBuff()->getRequiredISOCode() );
	}

	const std::string* CFSecISOCcyEditObj::getRequiredISOCodeReference() {
		return( getISOCcyBuff()->getRequiredISOCodeReference() );
	}

	void CFSecISOCcyEditObj::setRequiredISOCode( const std::string& value ) {
		if( getISOCcyBuff()->getRequiredISOCode() != value ) {
			getISOCcyEditBuff()->setRequiredISOCode( value );
		}
	}

	const std::string& CFSecISOCcyEditObj::getRequiredName() {
		return( getISOCcyBuff()->getRequiredName() );
	}

	const std::string* CFSecISOCcyEditObj::getRequiredNameReference() {
		return( getISOCcyBuff()->getRequiredNameReference() );
	}

	void CFSecISOCcyEditObj::setRequiredName( const std::string& value ) {
		if( getISOCcyBuff()->getRequiredName() != value ) {
			getISOCcyEditBuff()->setRequiredName( value );
		}
	}

	bool CFSecISOCcyEditObj::isOptionalUnitSymbolNull() {
		return( getISOCcyBuff()->isOptionalUnitSymbolNull() );
	}

	const std::string& CFSecISOCcyEditObj::getOptionalUnitSymbolValue() {
		return( getISOCcyBuff()->getOptionalUnitSymbolValue() );
	}

	const std::string* CFSecISOCcyEditObj::getOptionalUnitSymbolReference() {
		return( getISOCcyBuff()->getOptionalUnitSymbolReference() );
	}

	void CFSecISOCcyEditObj::setOptionalUnitSymbolNull() {
		if( ! getISOCcyBuff()->isOptionalUnitSymbolNull() ) {
			getISOCcyEditBuff()->setOptionalUnitSymbolNull();
		}
	}

	void CFSecISOCcyEditObj::setOptionalUnitSymbolValue( const std::string& value ) {
		if( getISOCcyBuff()->isOptionalUnitSymbolNull() ) {
			getISOCcyEditBuff()->setOptionalUnitSymbolValue( value );
		}
		else if( getISOCcyBuff()->getOptionalUnitSymbolValue() != value ) {
			getISOCcyEditBuff()->setOptionalUnitSymbolValue( value );
		}
	}

	const int16_t CFSecISOCcyEditObj::getRequiredPrecis() {
		return( getISOCcyBuff()->getRequiredPrecis() );
	}

	const int16_t* CFSecISOCcyEditObj::getRequiredPrecisReference() {
		return( getISOCcyBuff()->getRequiredPrecisReference() );
	}

	void CFSecISOCcyEditObj::setRequiredPrecis( const int16_t value ) {
		if( getISOCcyBuff()->getRequiredPrecis() != value ) {
			getISOCcyEditBuff()->setRequiredPrecis( value );
		}
	}

	std::vector<cfsec::ICFSecISOCtryCcyObj*> CFSecISOCcyEditObj::getOptionalChildrenCtry( bool forceRead ) {
		std::vector<cfsec::ICFSecISOCtryCcyObj*> retval;
		retval = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsISOCcy()->getSchema() )->getISOCtryCcyTableObj()->readISOCtryCcyByCcyIdx( getPKey()->getRequiredISOCcyId(),
			forceRead );
		return( retval );
	}

	void CFSecISOCcyEditObj::copyPKeyToBuff() {
		cfsec::CFSecISOCcyPKey* tablePKey = getPKey();
		cfsec::CFSecISOCcyBuff* tableBuff = getISOCcyEditBuff();
		tableBuff->setRequiredISOCcyId( tablePKey->getRequiredISOCcyId() );
	}

	void CFSecISOCcyEditObj::copyBuffToPKey() {
		cfsec::CFSecISOCcyPKey* tablePKey = getPKey();
		cfsec::CFSecISOCcyBuff* tableBuff = getISOCcyBuff();
		tablePKey->setRequiredISOCcyId( tableBuff->getRequiredISOCcyId() );
	}

	void CFSecISOCcyEditObj::copyBuffToOrig() {
		cfsec::CFSecISOCcyBuff* origBuff = getOrigAsISOCcy()->getISOCcyEditBuff();
		cfsec::CFSecISOCcyBuff* myBuff = getISOCcyBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFSecISOCcyEditObj::copyOrigToBuff() {
		cfsec::CFSecISOCcyBuff* origBuff = getOrigAsISOCcy()->getISOCcyBuff();
		cfsec::CFSecISOCcyBuff* myBuff = getISOCcyEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
