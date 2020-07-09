// Description: C++18 base object instance implementation for CFSec ISOTZone.

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
#include <cfsecobj/CFSecISOTZoneObj.hpp>

namespace cfsec {

	const std::string CFSecISOTZoneObj::CLASS_NAME( "CFSecISOTZoneObj" );
	const classcode_t CFSecISOTZoneObj::CLASS_CODE = 0xa008L;

	int32_t CFSecISOTZoneObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int16_t CFSecISOTZoneObj::getRequiredISOTZoneId() {
		return( getPKey()->getRequiredISOTZoneId() );
	}

	const int16_t* CFSecISOTZoneObj::getRequiredISOTZoneIdReference() {
		return( getPKey()->getRequiredISOTZoneIdReference() );
	}

	const std::string& CFSecISOTZoneObj::getRequiredIso8601() {
		return( getISOTZoneBuff()->getRequiredIso8601() );
	}

	const std::string* CFSecISOTZoneObj::getRequiredIso8601Reference() {
		return( getISOTZoneBuff()->getRequiredIso8601Reference() );
	}

	const std::string& CFSecISOTZoneObj::getRequiredTZName() {
		return( getISOTZoneBuff()->getRequiredTZName() );
	}

	const std::string* CFSecISOTZoneObj::getRequiredTZNameReference() {
		return( getISOTZoneBuff()->getRequiredTZNameReference() );
	}

	const int16_t CFSecISOTZoneObj::getRequiredTZHourOffset() {
		return( getISOTZoneBuff()->getRequiredTZHourOffset() );
	}

	const int16_t* CFSecISOTZoneObj::getRequiredTZHourOffsetReference() {
		return( getISOTZoneBuff()->getRequiredTZHourOffsetReference() );
	}

	const int16_t CFSecISOTZoneObj::getRequiredTZMinOffset() {
		return( getISOTZoneBuff()->getRequiredTZMinOffset() );
	}

	const int16_t* CFSecISOTZoneObj::getRequiredTZMinOffsetReference() {
		return( getISOTZoneBuff()->getRequiredTZMinOffsetReference() );
	}

	const std::string& CFSecISOTZoneObj::getRequiredDescription() {
		return( getISOTZoneBuff()->getRequiredDescription() );
	}

	const std::string* CFSecISOTZoneObj::getRequiredDescriptionReference() {
		return( getISOTZoneBuff()->getRequiredDescriptionReference() );
	}

	const bool CFSecISOTZoneObj::getRequiredVisible() {
		return( getISOTZoneBuff()->getRequiredVisible() );
	}

	const bool* CFSecISOTZoneObj::getRequiredVisibleReference() {
		return( getISOTZoneBuff()->getRequiredVisibleReference() );
	}


	CFSecISOTZoneObj::CFSecISOTZoneObj()
	: ICFSecISOTZoneObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecISOTZoneObj::CFSecISOTZoneObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFSecISOTZoneObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecISOTZoneObj::~CFSecISOTZoneObj() {
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

	cfsec::CFSecISOTZoneBuff* CFSecISOTZoneObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecISOTZoneBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableISOTZone()->readDerivedByIdIdx( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredISOTZoneId() );
			}
		}
		return( buff );
	}

	void CFSecISOTZoneObj::setBuff( cfsec::CFSecISOTZoneBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFSecISOTZoneObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecISOTZoneObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecISOTZoneObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecISOTZoneBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecISOTZoneObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecISOTZoneObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ISOTZoneId( "ISOTZoneId" );
		static const std::string S_Iso8601( "Iso8601" );
		static const std::string S_TZName( "TZName" );
		static const std::string S_TZHourOffset( "TZHourOffset" );
		static const std::string S_TZMinOffset( "TZMinOffset" );
		static const std::string S_Description( "Description" );
		static const std::string S_Visible( "Visible" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecISOTZoneObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecISOTZoneObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecISOTZoneObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecISOTZoneObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecISOTZoneObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOTZoneId, CFSecISOTZoneObj::getRequiredISOTZoneId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Iso8601, CFSecISOTZoneObj::getRequiredIso8601() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_TZName, CFSecISOTZoneObj::getRequiredTZName() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_TZHourOffset, CFSecISOTZoneObj::getRequiredTZHourOffset() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_TZMinOffset, CFSecISOTZoneObj::getRequiredTZMinOffset() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFSecISOTZoneObj::getRequiredDescription() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredBoolean( &S_Space, S_Visible, CFSecISOTZoneObj::getRequiredVisible() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFSecISOTZoneObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredTZName() );
		return( objName );
	}

	const std::string CFSecISOTZoneObj::getGenDefName() {
		return( cfsec::CFSecISOTZoneBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecISOTZoneObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFSecISOTZoneObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFSecISOTZoneObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecISOTZoneObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecISOTZoneObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecISOTZoneObj::getObjQualifiedName() {
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

	std::string CFSecISOTZoneObj::getObjFullName() {
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

	cfsec::ICFSecISOTZoneObj* CFSecISOTZoneObj::realize() {
		cfsec::ICFSecISOTZoneObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOTZoneTableObj()->realizeISOTZone(
			(cfsec::ICFSecISOTZoneObj*)this );
		return( dynamic_cast<cfsec::ICFSecISOTZoneObj*>( retobj ) );
	}

	cfsec::ICFSecISOTZoneObj* CFSecISOTZoneObj::read( bool forceRead ) {
		cfsec::ICFSecISOTZoneObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOTZoneTableObj()->readISOTZoneByIdIdx( getISOTZoneBuff()->getRequiredISOTZoneId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecISOTZoneObj*>( retobj ) );
	}

	cfsec::ICFSecISOTZoneTableObj* CFSecISOTZoneObj::getISOTZoneTable() {
		return( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOTZoneTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFSecISOTZoneObj::getSchema() {
		return( schema );
	}

	void CFSecISOTZoneObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecISOTZonePKey* CFSecISOTZoneObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecISOTZonePKey();
		}
		return( pKey );
	}

	void CFSecISOTZoneObj::setPKey( cfsec::CFSecISOTZonePKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecISOTZonePKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFSecISOTZoneObj::getIsNew() {
		return( isNew );
	}

	void CFSecISOTZoneObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecISOTZoneEditObj* CFSecISOTZoneObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecISOTZoneObj* lockobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOTZoneTableObj()->lockISOTZone( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getISOTZoneTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecISOTZoneEditObj*>( edit ) );
	}

	void CFSecISOTZoneObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecISOTZoneEditObj* CFSecISOTZoneObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecISOTZoneEditObj* CFSecISOTZoneObj::getISOTZoneEdit() {
		return( dynamic_cast<cfsec::ICFSecISOTZoneEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFSecISOTZoneObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOTZoneBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecISOTZoneObj::getCreatedAt() {
		return( getISOTZoneBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecISOTZoneObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOTZoneBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecISOTZoneObj::getUpdatedAt() {
		return( getISOTZoneBuff()->getUpdatedAt() );
	}

	void CFSecISOTZoneObj::copyPKeyToBuff() {
		cfsec::CFSecISOTZonePKey* tablePKey = getPKey();
		cfsec::CFSecISOTZoneBuff* tableBuff = getISOTZoneEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredISOTZoneId( tablePKey->getRequiredISOTZoneId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFSecISOTZoneObj::copyBuffToPKey() {
		cfsec::CFSecISOTZonePKey* tablePKey = getPKey();
		cfsec::CFSecISOTZoneBuff* tableBuff = getISOTZoneBuff();
		tablePKey->setRequiredISOTZoneId( tableBuff->getRequiredISOTZoneId() );
	}

}
