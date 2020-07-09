// Description: C++18 edit object instance implementation for CFSec SecUser.

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
#include <cfsecobj/CFSecSecUserObj.hpp>
#include <cfsecobj/CFSecSecUserEditObj.hpp>


namespace cfsec {

	const std::string CFSecSecUserEditObj::CLASS_NAME( "CFSecSecUserEditObj" );

	CFSecSecUserEditObj::CFSecSecUserEditObj( cfsec::ICFSecSecUserObj* argOrig )
	: ICFSecSecUserEditObj()
	{
		static const std::string S_ProcName( "CFSecSecUserEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecSecUserBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecSecUserBuff*>( origBuff->clone() );
	}

	CFSecSecUserEditObj::~CFSecSecUserEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFSecSecUserEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFSecSecUserEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecUserBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFSecSecUserEditObj::getCreatedAt() {
		return( getSecUserBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFSecSecUserEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfsec::ICFSecSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecUserBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFSecSecUserEditObj::getUpdatedAt() {
		return( getSecUserBuff()->getUpdatedAt() );
	}

	void CFSecSecUserEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getSecUserEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecSecUserEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getSecUserEditBuff()->setCreatedAt( value );
	}

	void CFSecSecUserEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getSecUserEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFSecSecUserEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getSecUserEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFSecSecUserEditObj::getClassCode() const {
		return( cfsec::CFSecSecUserBuff::CLASS_CODE );
	}

	bool CFSecSecUserEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecUserBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFSecSecUserEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFSecSecUserEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_SecUserId( "SecUserId" );
		static const std::string S_LoginId( "LoginId" );
		static const std::string S_EMailAddress( "EMailAddress" );
		static const std::string S_EMailConfirmUuid( "EMailConfirmUuid" );
		static const std::string S_DfltDevUserId( "DfltDevUserId" );
		static const std::string S_DfltDevName( "DfltDevName" );
		static const std::string S_PasswordHash( "PasswordHash" );
		static const std::string S_PasswordResetUuid( "PasswordResetUuid" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFSecSecUserEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFSecSecUserEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFSecSecUserEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFSecSecUserEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFSecSecUserEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, CFSecSecUserEditObj::getRequiredSecUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_LoginId, CFSecSecUserEditObj::getRequiredLoginId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_EMailAddress, CFSecSecUserEditObj::getRequiredEMailAddress() ) );
		if( ! CFSecSecUserEditObj::isOptionalEMailConfirmUuidNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_EMailConfirmUuid, CFSecSecUserEditObj::getOptionalEMailConfirmUuidValue() ) );
		}
		if( ! CFSecSecUserEditObj::isOptionalDfltDevUserIdNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_DfltDevUserId, CFSecSecUserEditObj::getOptionalDfltDevUserIdValue() ) );
		}
		if( ! CFSecSecUserEditObj::isOptionalDfltDevNameNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_DfltDevName, CFSecSecUserEditObj::getOptionalDfltDevNameValue() ) );
		}
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_PasswordHash, CFSecSecUserEditObj::getRequiredPasswordHash() ) );
		if( ! CFSecSecUserEditObj::isOptionalPasswordResetUuidNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_PasswordResetUuid, CFSecSecUserEditObj::getOptionalPasswordResetUuidValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFSecSecUserEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFSecSecUserEditObj::setRequiredRevision( int32_t value ) {
		getSecUserEditBuff()->setRequiredRevision( value );
	}

	std::string CFSecSecUserEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredLoginId() );
		return( objName );
	}

	const std::string CFSecSecUserEditObj::getGenDefName() {
		return( cfsec::CFSecSecUserBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFSecSecUserEditObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFSecSecUserEditObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFSecSecUserEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFSecSecUserEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFSecSecUserEditObj::getNamedObject( const std::string& objName ) {
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
		if( subObj == NULL ) {
			subObj = dynamic_cast<ICFSecSchemaObj*>( getSchema() )->getSecDeviceTableObj()->readSecDeviceByLookupNameIdx( getRequiredSecUserId(),
				nextName,
				false );
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

	std::string CFSecSecUserEditObj::getObjQualifiedName() {
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

	std::string CFSecSecUserEditObj::getObjFullName() {
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

	cfsec::ICFSecSecUserObj* CFSecSecUserEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecSecUserObj* retobj = getSchema()->getSecUserTableObj()->realizeSecUser( dynamic_cast<cfsec::ICFSecSecUserObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecSecUserObj* CFSecSecUserEditObj::read( bool forceRead ) {
		cfsec::ICFSecSecUserObj* retval = getOrigAsSecUser()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecSecUserObj* CFSecSecUserEditObj::create() {
		cfsec::ICFSecSecUserObj* retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsSecUser()->getSchema() )->getSecUserTableObj()->createSecUser( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecSecUserEditObj* CFSecSecUserEditObj::update() {
		getSchema()->getSecUserTableObj()->updateSecUser( this );
		return( NULL );
	}

	cfsec::ICFSecSecUserEditObj* CFSecSecUserEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getSecUserTableObj()->deleteSecUser( this );
		return( NULL );
	}

	cfsec::ICFSecSecUserTableObj* CFSecSecUserEditObj::getSecUserTable() {
		return( orig->getSchema()->getSecUserTableObj() );
	}

	cfsec::ICFSecSecUserEditObj* CFSecSecUserEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecSecUserEditObj* CFSecSecUserEditObj::getSecUserEdit() {
		return( (cfsec::ICFSecSecUserEditObj*)this );
	}

	cfsec::ICFSecSecUserEditObj* CFSecSecUserEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFSecSecUserEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecSecUserObj* CFSecSecUserEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecSecUserObj* CFSecSecUserEditObj::getOrigAsSecUser() {
		return( dynamic_cast<cfsec::ICFSecSecUserObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFSecSecUserEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecSecUserBuff* CFSecSecUserEditObj::getBuff() {
		return( buff );
	}

	void CFSecSecUserEditObj::setBuff( cfsec::CFSecSecUserBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecSecUserPKey* CFSecSecUserEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFSecSecUserEditObj::setPKey( cfsec::CFSecSecUserPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFSecSecUserEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFSecSecUserEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const uuid_ptr_t CFSecSecUserEditObj::getRequiredSecUserId() {
		return( getPKey()->getRequiredSecUserId() );
	}

	const uuid_ptr_t CFSecSecUserEditObj::getRequiredSecUserIdReference() {
		return( getPKey()->getRequiredSecUserIdReference() );
	}

	const std::string& CFSecSecUserEditObj::getRequiredLoginId() {
		return( getSecUserBuff()->getRequiredLoginId() );
	}

	const std::string* CFSecSecUserEditObj::getRequiredLoginIdReference() {
		return( getSecUserBuff()->getRequiredLoginIdReference() );
	}

	void CFSecSecUserEditObj::setRequiredLoginId( const std::string& value ) {
		if( getSecUserBuff()->getRequiredLoginId() != value ) {
			getSecUserEditBuff()->setRequiredLoginId( value );
		}
	}

	const std::string& CFSecSecUserEditObj::getRequiredEMailAddress() {
		return( getSecUserBuff()->getRequiredEMailAddress() );
	}

	const std::string* CFSecSecUserEditObj::getRequiredEMailAddressReference() {
		return( getSecUserBuff()->getRequiredEMailAddressReference() );
	}

	void CFSecSecUserEditObj::setRequiredEMailAddress( const std::string& value ) {
		if( getSecUserBuff()->getRequiredEMailAddress() != value ) {
			getSecUserEditBuff()->setRequiredEMailAddress( value );
		}
	}

	bool CFSecSecUserEditObj::isOptionalEMailConfirmUuidNull() {
		return( getSecUserBuff()->isOptionalEMailConfirmUuidNull() );
	}

	const uuid_ptr_t CFSecSecUserEditObj::getOptionalEMailConfirmUuidValue() {
		return( getSecUserBuff()->getOptionalEMailConfirmUuidValue() );
	}

	const uuid_ptr_t CFSecSecUserEditObj::getOptionalEMailConfirmUuidReference() {
		return( getSecUserBuff()->getOptionalEMailConfirmUuidReference() );
	}

	void CFSecSecUserEditObj::setOptionalEMailConfirmUuidNull() {
		if( ! getSecUserBuff()->isOptionalEMailConfirmUuidNull() ) {
			getSecUserEditBuff()->setOptionalEMailConfirmUuidNull();
		}
	}

	void CFSecSecUserEditObj::setOptionalEMailConfirmUuidValue( const uuid_ptr_t value ) {
		if( getSecUserBuff()->isOptionalEMailConfirmUuidNull() ) {
			getSecUserEditBuff()->setOptionalEMailConfirmUuidValue( value );
		}
		else if( getSecUserBuff()->getOptionalEMailConfirmUuidValue() != value ) {
			getSecUserEditBuff()->setOptionalEMailConfirmUuidValue( value );
		}
	}

	bool CFSecSecUserEditObj::isOptionalDfltDevUserIdNull() {
		return( getSecUserBuff()->isOptionalDfltDevUserIdNull() );
	}

	const uuid_ptr_t CFSecSecUserEditObj::getOptionalDfltDevUserIdValue() {
		return( getSecUserBuff()->getOptionalDfltDevUserIdValue() );
	}

	const uuid_ptr_t CFSecSecUserEditObj::getOptionalDfltDevUserIdReference() {
		return( getSecUserBuff()->getOptionalDfltDevUserIdReference() );
	}

	bool CFSecSecUserEditObj::isOptionalDfltDevNameNull() {
		return( getSecUserBuff()->isOptionalDfltDevNameNull() );
	}

	const std::string& CFSecSecUserEditObj::getOptionalDfltDevNameValue() {
		return( getSecUserBuff()->getOptionalDfltDevNameValue() );
	}

	const std::string* CFSecSecUserEditObj::getOptionalDfltDevNameReference() {
		return( getSecUserBuff()->getOptionalDfltDevNameReference() );
	}

	const std::string& CFSecSecUserEditObj::getRequiredPasswordHash() {
		return( getSecUserBuff()->getRequiredPasswordHash() );
	}

	const std::string* CFSecSecUserEditObj::getRequiredPasswordHashReference() {
		return( getSecUserBuff()->getRequiredPasswordHashReference() );
	}

	void CFSecSecUserEditObj::setRequiredPasswordHash( const std::string& value ) {
		if( getSecUserBuff()->getRequiredPasswordHash() != value ) {
			getSecUserEditBuff()->setRequiredPasswordHash( value );
		}
	}

	bool CFSecSecUserEditObj::isOptionalPasswordResetUuidNull() {
		return( getSecUserBuff()->isOptionalPasswordResetUuidNull() );
	}

	const uuid_ptr_t CFSecSecUserEditObj::getOptionalPasswordResetUuidValue() {
		return( getSecUserBuff()->getOptionalPasswordResetUuidValue() );
	}

	const uuid_ptr_t CFSecSecUserEditObj::getOptionalPasswordResetUuidReference() {
		return( getSecUserBuff()->getOptionalPasswordResetUuidReference() );
	}

	void CFSecSecUserEditObj::setOptionalPasswordResetUuidNull() {
		if( ! getSecUserBuff()->isOptionalPasswordResetUuidNull() ) {
			getSecUserEditBuff()->setOptionalPasswordResetUuidNull();
		}
	}

	void CFSecSecUserEditObj::setOptionalPasswordResetUuidValue( const uuid_ptr_t value ) {
		if( getSecUserBuff()->isOptionalPasswordResetUuidNull() ) {
			getSecUserEditBuff()->setOptionalPasswordResetUuidValue( value );
		}
		else if( getSecUserBuff()->getOptionalPasswordResetUuidValue() != value ) {
			getSecUserEditBuff()->setOptionalPasswordResetUuidValue( value );
		}
	}

	std::vector<cfsec::ICFSecSecDeviceObj*> CFSecSecUserEditObj::getOptionalComponentsSecDev( bool forceRead ) {
		std::vector<cfsec::ICFSecSecDeviceObj*> retval;
		retval = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsSecUser()->getSchema() )->getSecDeviceTableObj()->readSecDeviceByUserIdx( getPKey()->getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	cfsec::ICFSecSecDeviceObj* CFSecSecUserEditObj::getOptionalLookupDefDev( bool forceRead ) {
		cfsec::ICFSecSecDeviceObj* retobj = NULL;
		bool anyMissing = false;

			if( getSecUserBuff()->isOptionalDfltDevUserIdNull() ) {
				anyMissing = true;
			}
			if( getSecUserBuff()->isOptionalDfltDevNameNull() ) {
				anyMissing = true;
			}		if( ! anyMissing ) {
			retobj = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsSecUser()->getSchema() )->getSecDeviceTableObj()->readSecDeviceByIdIdx( getSecUserBuff()->getOptionalDfltDevUserIdValue(),
					getSecUserBuff()->getOptionalDfltDevNameValue() );
		}
		return( retobj );
	}

	void CFSecSecUserEditObj::setOptionalLookupDefDev( cfsec::ICFSecSecDeviceObj* value ) {
			
			if( value != NULL ) {
				getSecUserEditBuff()->setOptionalDfltDevUserIdValue( value->getRequiredSecUserId() );
				getSecUserEditBuff()->setOptionalDfltDevNameValue( value->getRequiredDevName() );
			}
			else {
				getSecUserEditBuff()->setOptionalDfltDevUserIdNull();
				getSecUserEditBuff()->setOptionalDfltDevNameNull();
			}
		}

	std::vector<cfsec::ICFSecSecSessionObj*> CFSecSecUserEditObj::getOptionalComponentsSecSess( bool forceRead ) {
		std::vector<cfsec::ICFSecSecSessionObj*> retval;
		retval = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsSecUser()->getSchema() )->getSecSessionTableObj()->readSecSessionBySecUserIdx( getPKey()->getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSecSessionObj*> CFSecSecUserEditObj::getOptionalChildrenSecProxy( bool forceRead ) {
		std::vector<cfsec::ICFSecSecSessionObj*> retval;
		retval = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsSecUser()->getSchema() )->getSecSessionTableObj()->readSecSessionBySecProxyIdx( getPKey()->getRequiredSecUserIdReference(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSecGrpMembObj*> CFSecSecUserEditObj::getOptionalChildrenSecGrpMemb( bool forceRead ) {
		std::vector<cfsec::ICFSecSecGrpMembObj*> retval;
		retval = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsSecUser()->getSchema() )->getSecGrpMembTableObj()->readSecGrpMembByUserIdx( getPKey()->getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecTSecGrpMembObj*> CFSecSecUserEditObj::getOptionalChildrenTSecGrpMemb( bool forceRead ) {
		std::vector<cfsec::ICFSecTSecGrpMembObj*> retval;
		retval = dynamic_cast<cfsec::ICFSecSchemaObj*>( getOrigAsSecUser()->getSchema() )->getTSecGrpMembTableObj()->readTSecGrpMembByUserIdx( getPKey()->getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	void CFSecSecUserEditObj::copyPKeyToBuff() {
		cfsec::CFSecSecUserPKey* tablePKey = getPKey();
		cfsec::CFSecSecUserBuff* tableBuff = getSecUserEditBuff();
		tableBuff->setRequiredSecUserId( tablePKey->getRequiredSecUserId() );
	}

	void CFSecSecUserEditObj::copyBuffToPKey() {
		cfsec::CFSecSecUserPKey* tablePKey = getPKey();
		cfsec::CFSecSecUserBuff* tableBuff = getSecUserBuff();
		tablePKey->setRequiredSecUserId( tableBuff->getRequiredSecUserId() );
	}

	void CFSecSecUserEditObj::copyBuffToOrig() {
		cfsec::CFSecSecUserBuff* origBuff = getOrigAsSecUser()->getSecUserEditBuff();
		cfsec::CFSecSecUserBuff* myBuff = getSecUserBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFSecSecUserEditObj::copyOrigToBuff() {
		cfsec::CFSecSecUserBuff* origBuff = getOrigAsSecUser()->getSecUserBuff();
		cfsec::CFSecSecUserBuff* myBuff = getSecUserEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
