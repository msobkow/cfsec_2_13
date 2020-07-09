// Description: C++18 edit object instance implementation for CFSec SecDevice.

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
#include <cfsecobj/CFSecSecDeviceObj.hpp>
#include <cfsecobj/CFSecSecDeviceEditObj.hpp>


namespace cfsec {

	const std::string CFSecSecDeviceEditObj::CLASS_NAME( "CFSecSecDeviceEditObj" );

	CFSecSecDeviceEditObj::CFSecSecDeviceEditObj( cfsec::ICFSecSecDeviceObj* argOrig )
	: ICFSecSecDeviceEditObj()
	{
		static const std::string S_ProcName( "CFSecSecDeviceEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecSecDeviceBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecSecDeviceBuff*>( origBuff->clone() );
	}

	CFSecSecDeviceEditObj::~CFSecSecDeviceEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFSecSecDeviceEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFSecSecDeviceEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecDeviceBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecSecDeviceEditObj::getCreatedAt() {
		return( getSecDeviceBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecSecDeviceEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecDeviceBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecSecDeviceEditObj::getUpdatedAt() {
		return( getSecDeviceBuff()->getUpdatedAt() );
	}

	void CFSecSecDeviceEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getSecDeviceEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecSecDeviceEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getSecDeviceEditBuff()->setCreatedAt( value );
	}

	void CFSecSecDeviceEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getSecDeviceEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecSecDeviceEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getSecDeviceEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFSecSecDeviceEditObj::getClassCode() const {
		return( cfsec::CFSecSecDeviceBuff::CLASS_CODE );
	}

	bool CFSecSecDeviceEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecDeviceBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecSecDeviceEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecDeviceEditObj" );
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
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecSecDeviceEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecSecDeviceEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecSecDeviceEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecSecDeviceEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecSecDeviceEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, CFSecSecDeviceEditObj::getRequiredSecUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_DevName, CFSecSecDeviceEditObj::getRequiredDevName() ) );
		if( ! CFSecSecDeviceEditObj::isOptionalPubKeyNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_PubKey, CFSecSecDeviceEditObj::getOptionalPubKeyValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFSecSecDeviceEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFSecSecDeviceEditObj::setRequiredRevision( int32_t value ) {
		getSecDeviceEditBuff()->setRequiredRevision( value );
	}

	std::string CFSecSecDeviceEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredDevName() );
		return( objName );
	}

	const std::string CFSecSecDeviceEditObj::getGenDefName() {
		return( cfsec::CFSecSecDeviceBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecSecDeviceEditObj::getScope() {
		cfsec::ICFSecSecUserObj* scope = getRequiredContainerSecUser();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecSecDeviceEditObj::getObjScope() {
		cfsec::ICFSecSecUserObj* scope = getRequiredContainerSecUser();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFSecSecDeviceEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecSecDeviceEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecSecDeviceEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFSecSecDeviceEditObj::getObjQualifiedName() {
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

	std::string CFSecSecDeviceEditObj::getObjFullName() {
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

	cfsec::ICFSecSecDeviceObj* CFSecSecDeviceEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecSecDeviceObj* retobj = getSchema()->getSecDeviceTableObj()->realizeSecDevice( dynamic_cast<cfsec::ICFSecSecDeviceObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecSecDeviceObj* CFSecSecDeviceEditObj::read( bool forceRead ) {
		cfsec::ICFSecSecDeviceObj* retval = getOrigAsSecDevice()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecSecDeviceObj* CFSecSecDeviceEditObj::create() {
		cfsec::ICFSecSecDeviceObj* retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsSecDevice()->getSchema() )->getSecDeviceTableObj()->createSecDevice( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecSecDeviceEditObj* CFSecSecDeviceEditObj::update() {
		getSchema()->getSecDeviceTableObj()->updateSecDevice( this );
		return( NULL );
	}

	cfsec::ICFSecSecDeviceEditObj* CFSecSecDeviceEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getSecDeviceTableObj()->deleteSecDevice( this );
		return( NULL );
	}

	cfsec::ICFSecSecDeviceTableObj* CFSecSecDeviceEditObj::getSecDeviceTable() {
		return( orig->getSchema()->getSecDeviceTableObj() );
	}

	cfsec::ICFSecSecDeviceEditObj* CFSecSecDeviceEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecSecDeviceEditObj* CFSecSecDeviceEditObj::getSecDeviceEdit() {
		return( (cfsec::ICFSecSecDeviceEditObj*)this );
	}

	cfsec::ICFSecSecDeviceEditObj* CFSecSecDeviceEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFSecSecDeviceEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecSecDeviceObj* CFSecSecDeviceEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecSecDeviceObj* CFSecSecDeviceEditObj::getOrigAsSecDevice() {
		return( dynamic_cast<cfsec::ICFSecSecDeviceObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFSecSecDeviceEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecSecDeviceBuff* CFSecSecDeviceEditObj::getBuff() {
		return( buff );
	}

	void CFSecSecDeviceEditObj::setBuff( cfsec::CFSecSecDeviceBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecSecDevicePKey* CFSecSecDeviceEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFSecSecDeviceEditObj::setPKey( cfsec::CFSecSecDevicePKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFSecSecDeviceEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFSecSecDeviceEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const uuid_ptr_t CFSecSecDeviceEditObj::getRequiredSecUserId() {
		return( getPKey()->getRequiredSecUserId() );
	}

	const uuid_ptr_t CFSecSecDeviceEditObj::getRequiredSecUserIdReference() {
		return( getPKey()->getRequiredSecUserIdReference() );
	}

	const std::string& CFSecSecDeviceEditObj::getRequiredDevName() {
		return( getPKey()->getRequiredDevName() );
	}

	const std::string* CFSecSecDeviceEditObj::getRequiredDevNameReference() {
		return( getPKey()->getRequiredDevNameReference() );
	}

	void CFSecSecDeviceEditObj::setRequiredDevName( const std::string& value ) {
		if( getPKey()->getRequiredDevName() != value ) {
			getPKey()->setRequiredDevName( value );
		}
		if( getSecDeviceBuff()->getRequiredDevName() != value ) {
			getSecDeviceEditBuff()->setRequiredDevName( value );
		}
	}

	bool CFSecSecDeviceEditObj::isOptionalPubKeyNull() {
		return( getSecDeviceBuff()->isOptionalPubKeyNull() );
	}

	const std::string& CFSecSecDeviceEditObj::getOptionalPubKeyValue() {
		return( getSecDeviceBuff()->getOptionalPubKeyValue() );
	}

	const std::string* CFSecSecDeviceEditObj::getOptionalPubKeyReference() {
		return( getSecDeviceBuff()->getOptionalPubKeyReference() );
	}

	void CFSecSecDeviceEditObj::setOptionalPubKeyNull() {
		if( ! getSecDeviceBuff()->isOptionalPubKeyNull() ) {
			getSecDeviceEditBuff()->setOptionalPubKeyNull();
		}
	}

	void CFSecSecDeviceEditObj::setOptionalPubKeyValue( const std::string& value ) {
		if( getSecDeviceBuff()->isOptionalPubKeyNull() ) {
			getSecDeviceEditBuff()->setOptionalPubKeyValue( value );
		}
		else if( getSecDeviceBuff()->getOptionalPubKeyValue() != value ) {
			getSecDeviceEditBuff()->setOptionalPubKeyValue( value );
		}
	}

	cfsec::ICFSecSecUserObj* CFSecSecDeviceEditObj::getRequiredContainerSecUser( bool forceRead ) {
		cfsec::ICFSecSecUserObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsSecDevice()->getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getPKey()->getRequiredSecUserId() );
		}
		return( retobj );
	}

	void CFSecSecDeviceEditObj::setRequiredContainerSecUser( cfsec::ICFSecSecUserObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredSecUserId
( value->getRequiredSecUserId() );
				getSecDeviceEditBuff()->setRequiredSecUserId( value->getRequiredSecUserId() );
			}
		}

	void CFSecSecDeviceEditObj::copyPKeyToBuff() {
		cfsec::CFSecSecDevicePKey* tablePKey = getPKey();
		cfsec::CFSecSecDeviceBuff* tableBuff = getSecDeviceEditBuff();
		tableBuff->setRequiredSecUserId( tablePKey->getRequiredSecUserId() );
		tableBuff->setRequiredDevName( tablePKey->getRequiredDevName() );
	}

	void CFSecSecDeviceEditObj::copyBuffToPKey() {
		cfsec::CFSecSecDevicePKey* tablePKey = getPKey();
		cfsec::CFSecSecDeviceBuff* tableBuff = getSecDeviceBuff();
		tablePKey->setRequiredSecUserId( tableBuff->getRequiredSecUserId() );
		tablePKey->setRequiredDevName( tableBuff->getRequiredDevName() );
	}

	void CFSecSecDeviceEditObj::copyBuffToOrig() {
		cfsec::CFSecSecDeviceBuff* origBuff = getOrigAsSecDevice()->getSecDeviceEditBuff();
		cfsec::CFSecSecDeviceBuff* myBuff = getSecDeviceBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFSecSecDeviceEditObj::copyOrigToBuff() {
		cfsec::CFSecSecDeviceBuff* origBuff = getOrigAsSecDevice()->getSecDeviceBuff();
		cfsec::CFSecSecDeviceBuff* myBuff = getSecDeviceEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
