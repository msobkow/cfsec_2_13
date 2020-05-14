// Description: C++18 base object instance implementation for CFSec SecDevice.

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
#include <cfsecobj/CFSecSecDeviceObj.hpp>

namespace cfsec {

	const std::string CFSecSecDeviceObj::CLASS_NAME( "CFSecSecDeviceObj" );
	const classcode_t CFSecSecDeviceObj::CLASS_CODE = 0xa00aL;

	int32_t CFSecSecDeviceObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const uuid_ptr_t CFSecSecDeviceObj::getRequiredSecUserId() {
		return( getPKey()->getRequiredSecUserId() );
	}

	const uuid_ptr_t CFSecSecDeviceObj::getRequiredSecUserIdReference() {
		return( getPKey()->getRequiredSecUserIdReference() );
	}

	const std::string& CFSecSecDeviceObj::getRequiredDevName() {
		return( getPKey()->getRequiredDevName() );
	}

	const std::string* CFSecSecDeviceObj::getRequiredDevNameReference() {
		return( getPKey()->getRequiredDevNameReference() );
	}

	bool CFSecSecDeviceObj::isOptionalPubKeyNull() {
		return( getSecDeviceBuff()->isOptionalPubKeyNull() );
	}

	const std::string& CFSecSecDeviceObj::getOptionalPubKeyValue() {
		return( getSecDeviceBuff()->getOptionalPubKeyValue() );
	}

	const std::string* CFSecSecDeviceObj::getOptionalPubKeyReference() {
		return( getSecDeviceBuff()->getOptionalPubKeyReference() );
	}


	cfsec::ICFSecSecUserObj* CFSecSecDeviceObj::getRequiredContainerSecUser( bool forceRead ) {
		cfsec::ICFSecSecUserObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getPKey()->getRequiredSecUserId(), forceRead );
		}
		return( retobj );
	}

	CFSecSecDeviceObj::CFSecSecDeviceObj()
	: ICFSecSecDeviceObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecSecDeviceObj::CFSecSecDeviceObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFSecSecDeviceObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFSecSecDeviceObj::~CFSecSecDeviceObj() {
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

	cfsec::CFSecSecDeviceBuff* CFSecSecDeviceObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecSecDeviceBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFSecSchema*>( schema->getBackingStore() )->getTableSecDevice()->readDerivedByIdIdx( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredSecUserId(),
						getPKey()->getRequiredDevName() );
			}
		}
		return( buff );
	}

	void CFSecSecDeviceObj::setBuff( cfsec::CFSecSecDeviceBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFSecSecDeviceObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFSecSecDeviceObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFSecSecDeviceObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecDeviceBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecSecDeviceObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecDeviceObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_SecUserId( "SecUserId" );
		static const std::string S_DevName( "DevName" );
		static const std::string S_PubKey( "PubKey" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecSecDeviceObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecSecDeviceObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecSecDeviceObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecSecDeviceObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecSecDeviceObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, CFSecSecDeviceObj::getRequiredSecUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_DevName, CFSecSecDeviceObj::getRequiredDevName() ) );
		if( ! CFSecSecDeviceObj::isOptionalPubKeyNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_PubKey, CFSecSecDeviceObj::getOptionalPubKeyValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFSecSecDeviceObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredDevName() );
		return( objName );
	}

	const std::string CFSecSecDeviceObj::getGenDefName() {
		return( cfsec::CFSecSecDeviceBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecSecDeviceObj::getScope() {
		cfsec::ICFSecSecUserObj* scope = getRequiredContainerSecUser();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecSecDeviceObj::getObjScope() {
		cfsec::ICFSecSecUserObj* scope = getRequiredContainerSecUser();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecSecDeviceObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecSecDeviceObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecSecDeviceObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecSecDeviceObj::getObjQualifiedName() {
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

	std::string CFSecSecDeviceObj::getObjFullName() {
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

	cfsec::ICFSecSecDeviceObj* CFSecSecDeviceObj::realize() {
		cfsec::ICFSecSecDeviceObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecDeviceTableObj()->realizeSecDevice(
			(cfsec::ICFSecSecDeviceObj*)this );
		return( dynamic_cast<cfsec::ICFSecSecDeviceObj*>( retobj ) );
	}

	cfsec::ICFSecSecDeviceObj* CFSecSecDeviceObj::read( bool forceRead ) {
		cfsec::ICFSecSecDeviceObj* retobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecDeviceTableObj()->readSecDeviceByIdIdx( getSecDeviceBuff()->getRequiredSecUserId(),
		getSecDeviceBuff()->getRequiredDevName(), forceRead );
		return( dynamic_cast<cfsec::ICFSecSecDeviceObj*>( retobj ) );
	}

	cfsec::ICFSecSecDeviceTableObj* CFSecSecDeviceObj::getSecDeviceTable() {
		return( dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecDeviceTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFSecSecDeviceObj::getSchema() {
		return( schema );
	}

	void CFSecSecDeviceObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecSecDevicePKey* CFSecSecDeviceObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecSecDevicePKey();
		}
		return( pKey );
	}

	void CFSecSecDeviceObj::setPKey( cfsec::CFSecSecDevicePKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecSecDevicePKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFSecSecDeviceObj::getIsNew() {
		return( isNew );
	}

	void CFSecSecDeviceObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecSecDeviceEditObj* CFSecSecDeviceObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecSecDeviceObj* lockobj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecDeviceTableObj()->lockSecDevice( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecDeviceTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecSecDeviceEditObj*>( edit ) );
	}

	void CFSecSecDeviceObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecSecDeviceEditObj* CFSecSecDeviceObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecSecDeviceEditObj* CFSecSecDeviceObj::getSecDeviceEdit() {
		return( dynamic_cast<cfsec::ICFSecSecDeviceEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFSecSecDeviceObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecDeviceBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecSecDeviceObj::getCreatedAt() {
		return( getSecDeviceBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecSecDeviceObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecDeviceBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecSecDeviceObj::getUpdatedAt() {
		return( getSecDeviceBuff()->getUpdatedAt() );
	}

	void CFSecSecDeviceObj::copyPKeyToBuff() {
		cfsec::CFSecSecDevicePKey* tablePKey = getPKey();
		cfsec::CFSecSecDeviceBuff* tableBuff = getSecDeviceEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredSecUserId( tablePKey->getRequiredSecUserId() );
			tableBuff->setRequiredDevName( tablePKey->getRequiredDevName() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFSecSecDeviceObj::copyBuffToPKey() {
		cfsec::CFSecSecDevicePKey* tablePKey = getPKey();
		cfsec::CFSecSecDeviceBuff* tableBuff = getSecDeviceBuff();
		tablePKey->setRequiredSecUserId( tableBuff->getRequiredSecUserId() );
		tablePKey->setRequiredDevName( tableBuff->getRequiredDevName() );
	}

}
